#include "gray_scale.h"
#include "../image.h"

#include <vector>

void GrayScale::Apply(Image& image) {
    const double red_multipier = 0.299;
    const double green_multipier = 0.587;
    const double blue_multipier = 0.114;
    const size_t width = image.pixels[0].size();
    const size_t height = image.pixels.size();

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            Pixel new_pixel;
            new_pixel.red = image.pixels[i][j].red * red_multipier + image.pixels[i][j].green * green_multipier +
                            image.pixels[i][j].blue * blue_multipier;
            new_pixel.green = image.pixels[i][j].red * red_multipier + image.pixels[i][j].green * green_multipier +
                              image.pixels[i][j].blue * blue_multipier;
            new_pixel.blue = image.pixels[i][j].red * red_multipier + image.pixels[i][j].green * green_multipier +
                             image.pixels[i][j].blue * blue_multipier;
            image.pixels[i][j] = new_pixel;
        }
    }
}
