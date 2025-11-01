#pragma once

#include "exceptions.h"
#include <fstream>

class BinaryReader {
private:
    std::ifstream in_;
public:
    BinaryReader(const std::string& input_file) {
        in_.open(input_file, std::ios::binary);
        if (!in_.is_open()) {
            throw IOException("Failed to open input file: [" + input_file + "]");
        }
    }

    template <std::integral T>
    BinaryReader& operator>>(T& value) {
        using U = typename std::make_unsigned<T>::type;
        U bits = 0;
        unsigned char buffer[sizeof(T)];
        in_.read(reinterpret_cast<char*>(buffer), sizeof(T));

        if (in_.gcount() < static_cast<std::streamsize>(sizeof(T))) {
            throw IOException("Not enough data in the input file.");
        }

        for (size_t i = 0; i < sizeof(T); ++i) {
            bits = (bits << U{8}) | buffer[sizeof(T) - i - 1];
        }
    
        value = static_cast<T>(bits);
        return *this;
    }
};

class BinaryWriter {
private:
    std::ofstream out_;
public:
    BinaryWriter(const std::string& output_file) {
        out_.open(output_file, std::ios::binary);
        if (!out_.is_open()) {
            throw IOException("Failed to open output file: " + output_file);
        }
    }

    template <std::integral T>
    BinaryWriter& operator<<(T value) {
        using U = typename std::make_unsigned<T>::type;
        U bits = static_cast<U>(value);
        unsigned char buffer[sizeof(T)];

        for (unsigned char& byte : buffer) {
            byte = bits & U{0xFF};
            bits >>= U{8};
        }

        out_.write(reinterpret_cast<char*>(buffer), sizeof(buffer));
        return *this;
    }
};
