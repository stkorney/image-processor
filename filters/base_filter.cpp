#include "base_filter.h"
#include "../exceptions.h"
#include <algorithm>

void BaseFilterWithMatrix::Apply(Image& image) {

    if (matrix_.empty() || matrix_[0].empty()) {
        throw FilterException("Matrix is not initialized!");
    }

    Image filtered_image = image;
    const long long y_size = image.pixels.size();
    const long long x_size = image.pixels[0].size(); 

    for (long long i = 0; i < y_size; ++i) {
        for (long long j = 0; j < x_size; ++j) {
            Pixel new_pixel(0.0, 0.0, 0.0);
            for (long long shift_i = -1; shift_i <= 1; ++shift_i) {
                for (long long shift_j = -1; shift_j <= 1; ++shift_j) {
                    long long actual_used_pixel_i = shift_i + i;
                    long long actual_used_pixel_j = shift_j + j;

                    if (0 > actual_used_pixel_j) {
                        actual_used_pixel_j = 0;
                    }
                    if (actual_used_pixel_j >= x_size) {
                        actual_used_pixel_j = x_size - 1;
                    }

                    if (0 > actual_used_pixel_i) {
                        actual_used_pixel_i = 0;
                    }
                    if (actual_used_pixel_i >= y_size) {
                        actual_used_pixel_i = y_size - 1;
                    }

                    new_pixel.red += image.pixels[actual_used_pixel_i][actual_used_pixel_j].red * matrix_[1 + shift_i][1 + shift_j] ;
                    new_pixel.green += image.pixels[actual_used_pixel_i][actual_used_pixel_j].green * matrix_[1 + shift_i][1 + shift_j];
                    new_pixel.blue += image.pixels[actual_used_pixel_i][actual_used_pixel_j].blue * matrix_[1 + shift_i][1 + shift_j];
                }
            }

            new_pixel.red = std::min(1.0, std::max(0.0, new_pixel.red));
            new_pixel.green = std::min(1.0, std::max(0.0, new_pixel.green));
            new_pixel.blue = std::min(1.0, std::max(0.0, new_pixel.blue));
            filtered_image.pixels[i][j] = new_pixel;
        }
    }

    image = filtered_image;
}
