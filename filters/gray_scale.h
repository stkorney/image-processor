#pragma once

#include "base_filter.h"

#include <cstdint>

class GrayScale : virtual public BaseFilter {
public:
    GrayScale() = default;
    void Apply(Image& image) override;
};
