#pragma once

#include "exceptions.h"
#include <fstream>

class BinaryReader {
private:
    std::ifstream in_;

public:
    explicit BinaryReader(const std::string& input_file) {
        in_.open(input_file, std::ios::binary);
        if (!in_.is_open()) {
            throw IOException("Failed to open input file: [" + input_file + "]");
        }
    }

    template <std::integral T>
    BinaryReader& operator>>(T& value) {
        const int shift = 8;
        using U = typename std::make_unsigned<T>::type;
        U bits = 0;
        unsigned char buffer[sizeof(T)];
        in_.read(reinterpret_cast<char*>(buffer), sizeof(T));

        if (in_.gcount() < static_cast<std::streamsize>(sizeof(T))) {
            throw IOException("Not enough data in the input file.");
        }

        for (size_t i = 0; i < sizeof(T); ++i) {
            bits = (bits << U{shift}) | buffer[sizeof(T) - i - 1];
        }

        value = static_cast<T>(bits);
        return *this;
    }
};

class BinaryWriter {
private:
    std::ofstream out_;

public:
    explicit BinaryWriter(const std::string& output_file) {
        out_.open(output_file, std::ios::binary);
        if (!out_.is_open()) {
            throw IOException("Failed to open output file: " + output_file);
        }
    }

    template <std::integral T>
    BinaryWriter& operator<<(T value) {
        using U = typename std::make_unsigned<T>::type;
        const int shift = 8;
        const int byte_mask = 0xFF;
        U bits = static_cast<U>(value);
        unsigned char buffer[sizeof(T)];

        if (sizeof(T) == 1) {
            buffer[0] = static_cast<unsigned char>(bits);
        } else {
            for (unsigned char& byte : buffer) {
                byte = bits & U{byte_mask};
                bits >>= U{shift};
            }
        }

        out_.write(reinterpret_cast<char*>(buffer), sizeof(buffer));
        return *this;
    }
};
