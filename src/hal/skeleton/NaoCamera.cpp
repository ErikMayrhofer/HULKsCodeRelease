//
// Created by max on 11/22/18.
//

#include "NaoCamera.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/videodev2.h>

skeleton::NaoCamera::NaoCamera(int pos) : camFile() {
    camFile = "/dev/video"+std::to_string(pos);
}

void skeleton::NaoCamera::init() {
    if((fd= open(camFile.c_str(), O_RDWR))<0){
        perror("open");
        exit(1);
    }
    //set possible format for camera images
    struct v4l2_capability cap;
    if(ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0){
        perror("VIDIOC_QUERYCAP");
        exit(1);
    }
    if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)){
        fprintf(stderr, "The device does not handle single-planar video capture.\n");
        exit(1);
    }
    format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    format.fmt.pix.width = 1280;
    format.fmt.pix.height = 720;
    if(ioctl(fd, VIDIOC_S_FMT, &format) < 0){
        perror("VIDIOC_S_FMT");
        exit(1);
    }


    //request buffers
    struct v4l2_requestbuffers bufrequest;
    bufrequest.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    bufrequest.memory = V4L2_MEMORY_MMAP;
    bufrequest.count = 1;

    if(ioctl(fd, VIDIOC_REQBUFS, &bufrequest) < 0){
        perror("VIDIOC_REQBUFS");
        exit(1);
    }
    struct v4l2_buffer buffer;
    memset(&buffer, 0, sizeof(buffer));

    buffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buffer.memory = V4L2_MEMORY_MMAP;
    buffer.index = 0;

    if(ioctl(fd, VIDIOC_QUERYBUF, &buffer) < 0){
        perror("VIDIOC_QUERYBUF");
        exit(1);
    }
    uint8_t * buffer_start = static_cast<uint8_t *>(mmap(
            NULL,
            buffer.length,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            fd,
            buffer.m.offset
    ));
    if(buffer_start == MAP_FAILED){
        perror("mmap");
        exit(1);
    }
}
void skeleton::NaoCamera::start() {
    type = buffer.type;
    if(ioctl(fd, VIDIOC_STREAMON, &type) < 0){
        perror("VIDIOC_STREAMON");
        exit(1);
    }
}
Image* skeleton::NaoCamera::takePicture() {
    uint8_t * rgb = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3 * buffer.length / 2));
    memset(buffer_map, 0, buffer.length);
    if (ioctl(fd, VIDIOC_QBUF, &buffer) < 0) {
        perror("VIDIOC_QBUF");
        exit(1);
    }

    //flush image to bufferp
    if (ioctl(fd, VIDIOC_DQBUF, &buffer) < 0) {
        perror("VIDIOC_DQBUF");
        exit(1);
    }
    int rgbc = 0;
    for(int i=0;i<buffer.length;i+=4){
        int u=buffer_map[i];
        int y1 = buffer_map[i+1];
        int v  = buffer_map[i+2];
        int y2 = buffer_map[i+3];
        yuv2rgb(rgb,rgbc,y1, u, v);
        yuv2rgb(rgb,rgbc,y2, u, v);
        rgbc+=3;
    }
    //insert into image object;
    Image *image = new Image(camFile.at(camFile.size()-1),rgb,format.fmt.pix.width,format.fmt.pix.height);
    return image;
}
skeleton::NaoCamera::~NaoCamera() {
    if (ioctl(fd, VIDIOC_STREAMOFF, &type) < 0) {
        perror("VIDIOC_STREAMOFF");
        exit(1);
    }
    close(fd);
}

void skeleton::NaoCamera::yuv2rgb(uint8_t (*array), int rgbc,int y,int u,int v){
    array[rgbc+0]=(uint8_t)(y + 1.140*v);
    array[rgbc+1]=(uint8_t)(y - 0.395*u - 0.581*v);
    array[rgbc+2]=(uint8_t)(y + 2.032*u);
}