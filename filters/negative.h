#pragma once

#include "base_filter.h"

#include <cstdint>

class Negative : public BaseFilter {
public:
    Negative() = default;
    void Apply(Image& image) override;
};
