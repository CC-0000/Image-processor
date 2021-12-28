#ifndef IMAGEPROCESSINGPROGRAM_IMAGE_H
#define IMAGEPROCESSINGPROGRAM_IMAGE_H

#include "Header.h"
#include <vector>

struct Image
{
    Header imageHeader;
    std::vector<unsigned char> imageData;// stores the individual pixel data of the image
};

#endif