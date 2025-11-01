#include "sharpening.h"

Sharpening::Sharpening() {
    matrix_ = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
}

void Sharpening::Apply(Image& image) {
    BaseFilterWithMatrix::Apply(image);
}
