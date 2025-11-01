#pragma once

#include "base_filter.h"

class TempPoint : public BaseFilter {
public:
    TempPoint(double x_part, double y_part) : x_part_(x_part), y_part_(y_part) {
    }
    void Apply(Image& image) override;

private:
    double x_part_;
    double y_part_;
};
