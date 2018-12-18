#define once

#include "Common.h"
#include "../math/TypeDefs.h"

namespace trace {

class Image {
public:
    Image(uint width, uint height);
    Image(Image& other);
    ~Image();

    // xyz is rgb
    void setPixelColor(uint row, uint col, byte3 color);
    byte3 getPixelColor(uint row, uint col);

    void writeToFilePNG(const char* path);

private:
    static void write_file(void *context, void *data, int size);
    uint m_height;
    uint m_width;
    uint8_t* m_data;

    static const uint NUM_CHANNELS = 3;
};

}
