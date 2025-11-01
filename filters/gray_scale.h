#pragma once

#include "base_filter.h"

#include <cstdint>

class GrayScale : public BaseFilter {
public:
    GrayScale() = default;
    void Apply(Image& image) override;
};
