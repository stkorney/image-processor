#include "negative.h"
#include "../image.h"

#include <vector>

void Negative::Apply(Image& image) {
    const size_t width = image.pixels[0].size();
    const size_t height = image.pixels.size();

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            Pixel new_pixel;
            new_pixel.red = 1.0 - image.pixels[i][j].red;
            new_pixel.green = 1.0 - image.pixels[i][j].green;
            new_pixel.blue = 1.0 - image.pixels[i][j].blue;
            image.pixels[i][j] = new_pixel;
        }
    }
}
