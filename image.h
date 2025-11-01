#pragma once

#include <vector>

struct Pixel {
    double red;
    double green;
    double blue;

    Pixel(double red, double green, double blue) : red(red), green(green), blue(blue) {
    }

    Pixel() = default;
};

struct Image {
    std::vector<std::vector<Pixel>> pixels;

    Image(size_t height, size_t width) {
        pixels.resize(height, std::vector<Pixel>(width, Pixel(0.0, 0.0, 0.0)));
    }

    Image() = default;
};
