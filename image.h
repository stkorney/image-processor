#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

struct Pixel {
    double red;
    double green;
    double blue;

    Pixel(double _red, double _green, double _blue)
        : red(_red), green(_green), blue(_blue)
    {}

    Pixel() = default;
};

struct Image {
    std::vector<std::vector<Pixel>> pixels;

    Image(size_t height, size_t width) {
        pixels.resize(height, std::vector<Pixel>(width, Pixel(0.0, 0.0, 0.0)));
    }

    void PrintPixelsTable() const {
        for (const auto& row : pixels) {
            for (const auto& pixel : row) {
                // Форматируем вывод: (R, G, B) с точностью до 2 знаков
                std::cout << "(" 
                          << std::fixed << std::setprecision(2)
                          << pixel.blue << ", "
                          << pixel.green << ", "
                          << pixel.red << ") ";
            }
            std::cout << "\n"; // Переход на новую строку после каждой строки пикселей
        }
    }

    Image();
};
