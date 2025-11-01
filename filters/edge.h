#pragma once

#include "base_filter.h"
#include "gray_scale.h"

class Edge : public BaseFilterWithMatrix, public GrayScale {
public:
    explicit Edge(double threshold);
    void Apply(Image& image) override;

private:
    double threshold_;
};
