#pragma once

#include "base_filter.h"

class Sharpening : public BaseFilterWithMatrix {
public:
    Sharpening();
    void Apply(Image& image) override;
};
