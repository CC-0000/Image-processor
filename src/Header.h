#ifndef IMAGEPROCESSINGPROGRAM_HEADER_H
#define IMAGEPROCESSINGPROGRAM_HEADER_H

struct Header
{
    // tga image header data
    char  idLength;
    char  colorMapType;
    char  dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char  colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char  bitsPerPixel;
    char  imageDescriptor;
};

#endif

