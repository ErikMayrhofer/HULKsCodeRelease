//
// Created by max on 11/22/18.
//

#ifndef DUCKBURG_NAOCAMERA_H
#define DUCKBURG_NAOCAMERA_H

#include <cstring>
#include <iostream>
#include <linux/videodev2.h>
#include "Image.h"

class NaoCamera {
public:
    NaoCamera(int pos) : camFile() {
        camFile = "/dev/video"+std::to_string(pos);
    }
    void init();
    void start();
    Image* takePicture();
    virtual ~NaoCamera();
private:
    void yuv2rgb(uint8_t (*array), int rgbc, int y, int u, int v);

    std::string camFile;
    struct v4l2_requestbuffers buffrequest;
    struct v4l2_format format;
    uint8_t  * buffer_map;
    struct v4l2_buffer buffer;
    int fd;
    int type;
};


#endif //DUCKBURG_NAOCAMERA_H
