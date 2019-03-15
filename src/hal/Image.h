//
// Created by max on 11/23/18.
//

#ifndef DUCKBURG_IMAGE_H
#define DUCKBURG_IMAGE_H

#include <iostream>


class Image {
public:
    char cam;
    uint8_t ** rgb;
    uint8_t * getPixel(int x,int y);

    Image(char cam, uint8_t ** rgb, int width, int height);

    virtual ~Image();

private:
    int width;
    int height;
};


#endif //DUCKBURG_IMAGE_H
