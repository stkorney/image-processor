#include "edge.h"
#include <string>
#include <iomanip>

Edge::Edge(double threshold) {
    threshold_ = threshold;
    matrix_ = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
}

void Edge::Apply(Image& image) {
    const size_t width = image.pixels[0].size();
    const size_t height = image.pixels.size();

    GrayScale::Apply(image);
    BaseFilterWithMatrix::Apply(image);

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (image.pixels[i][j].blue > threshold_) {
                image.pixels[i][j] = Pixel(1, 1, 1);
            } else {
                image.pixels[i][j] = Pixel(0, 0, 0);
            }
        }
    }
}
