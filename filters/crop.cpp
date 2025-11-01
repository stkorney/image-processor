#include "crop.h"

#include <cstddef>

void Crop::Apply(Image& image) {
    size_t crop_height = std::min(image.pixels.size(), height_);
    size_t crop_width = std::min(image.pixels[0].size(), width_);
    std::vector<std::vector<Pixel>> croped_image;

    for (size_t i = 0; i < crop_height; ++i) {
        std::vector<Pixel> row(image.pixels[i].begin(),
                               image.pixels[i].begin() + static_cast<std::ptrdiff_t>(crop_width));
        croped_image.push_back(row);
    }
    image.pixels = croped_image;
}
