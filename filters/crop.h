#pragma once

#include "base_filter.h"

class Crop : public BaseFilter {
public:
    Crop(size_t width, size_t height) : width_(width), height_(height) {
    }
    void Apply(Image& image) override;

private:
    size_t width_;
    size_t height_;
};
