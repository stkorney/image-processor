#include "sharpening.h"

Sharpening::Sharpening() {
    const double five = 5.0;
    matrix_ = {{0, -1, 0}, {-1, five, -1}, {0, -1, 0}};
}

void Sharpening::Apply(Image& image) {
    BaseFilterWithMatrix::Apply(image);
}
