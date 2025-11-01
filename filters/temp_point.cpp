#include "temp_point.h"

#include <cmath>

/* Фильтр превращает цвета изображения в "степень теплоты"
   и похож в этом на CITemperatureAndTint.
   Однако, чем ближе пиксель к заданной отношением по высоте и ширине
   точке изображения, тем теплее он будет. */

void TempPoint::Apply(Image& image) {
    const size_t width = image.pixels[0].size();
    const size_t height = image.pixels.size();
    const double point_x = static_cast<double>(width) * x_part_;
    const double point_y = static_cast<double>(height) * y_part_;
    const double x_distance = std::max(static_cast<double>(width) - point_x, point_x);
    const double y_distance = std::max(static_cast<double>(height) - point_y, point_y);
    const double max_distance = sqrt(x_distance * x_distance + y_distance * y_distance);
    const double red_coef = 1.2;
    const double green_coef = 0.6;
    const double blue_coef = 0.1;

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            double dx = static_cast<double>(j) - point_x;
            double dy = static_cast<double>(i) - point_y;
            double distance = sqrt(dx * dx + dy * dy);
            double intensity = 1.0 - (distance / max_distance);

            double new_red = image.pixels[i][j].red * (1 - intensity) + red_coef * intensity;
            double new_green = image.pixels[i][j].green * (1 - intensity) + green_coef * intensity;
            double new_blue = image.pixels[i][j].blue * (1 - intensity) + blue_coef * intensity;

            double final_red = std::min(1.0, std::max(0.0, new_red));
            double final_green = std::min(1.0, std::max(0.0, new_green));
            double final_blue = std::min(1.0, std::max(0.0, new_blue));
            image.pixels[i][j] = Pixel(final_red, final_green, final_blue);
        }
    }
}
