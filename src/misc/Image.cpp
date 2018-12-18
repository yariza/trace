#include "Image.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

using namespace trace;

Image::Image(uint height, uint width)
    : m_height(height)
    , m_width(width)
    , m_data(new uint8_t[width * height * NUM_CHANNELS])
{
}

Image::Image(Image& other)
{
    m_height = other.m_height;
    m_width = other.m_width;
    m_data = new uint8_t[m_width * m_height * NUM_CHANNELS];
    memcpy(m_data, other.m_data, m_width * m_height * NUM_CHANNELS);
}

Image::~Image()
{
    delete[] m_data;
}

void Image::setPixelColor(uint row, uint col, byte3 color)
{
    uint index = (row * m_width + col) * NUM_CHANNELS;
    m_data[index + 0] = color.x;
    m_data[index + 1] = color.y;
    m_data[index + 2] = color.z;
}

byte3 Image::getPixelColor(uint row, uint col)
{
    uint index = (row * m_width + col) * NUM_CHANNELS;
    byte3 color;
    color.x = m_data[index + 0];
    color.y = m_data[index + 1];
    color.z = m_data[index + 2];
    return color;
}

void Image::writeToFilePNG(const char* path)
{
    FILE* file = fopen(path, "w");
    stbi_write_png_to_func(write_file, file, m_width, m_height, 3, m_data, m_width * NUM_CHANNELS * sizeof(uint8_t));
    fclose(file);
}

void Image::write_file(void *context, void *data, int size)
{
    FILE* file = (FILE*)context;
    fwrite(data, 1, size, file);
}
