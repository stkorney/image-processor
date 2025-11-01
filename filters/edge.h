#pragma once

#include "base_filter.h"

class Edge : public BaseFilterWithMatrix {
public:
    Edge(double threshold);
    void Apply(Image& image) override;
private:
    double threshold_;
};
