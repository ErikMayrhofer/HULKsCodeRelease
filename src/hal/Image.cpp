//
// Created by max on 11/23/18.
//

#include "Image.h"

uint8_t *Image::getPixel(int x, int y) {
    int pos = (y*width+x);
    return rgb[pos];
}

Image::Image(char cam,uint8_t ** rgb, int width, int height) : cam(cam), rgb(rgb),width(width), height(height) {
}

Image::~Image() {
    free(rgb);
}
