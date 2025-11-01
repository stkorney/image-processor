#include "bmp.h"
#include "io.h"
#include "image.h"
#include "exceptions.h"
#include <vector>

BMPFile BMPRead(const std::string& in_path) {
    const int type = 0x4D42;
    const int bit_count = 24;
    const double max_colour_value = 255.0;
    BMPHeader header;
    ImageHeader image_header;
    BinaryReader read(in_path);

    read >> header.bf_type;
    read >> header.bf_size;
    read >> header.bf_reserved1;
    read >> header.bf_reserved2;
    read >> header.bf_offbits;

    read >> image_header.bi_size;
    read >> image_header.bi_width;
    read >> image_header.bi_height;
    read >> image_header.bi_planes;
    read >> image_header.bi_bit_count;
    read >> image_header.bi_compression;
    read >> image_header.bi_size_image;
    read >> image_header.bi_xpels_per_meter;
    read >> image_header.bi_ypels_per_meter;
    read >> image_header.bi_clr_used;
    read >> image_header.bi_clr_important;

    if (header.bf_type != type) {
        throw BMPReadingException("File format must be BMP.");
    }
    if (image_header.bi_compression != 0) {
        throw BMPReadingException("Compressed images are not allowed.");
    }
    if (image_header.bi_bit_count != bit_count) {
        throw BMPReadingException("Image must be 24-bit.");
    }
    if (image_header.bi_planes != 1) {
        throw BMPReadingException("Number of image planes must be 1.");
    }

    uint32_t width = image_header.bi_width;
    uint32_t height = image_header.bi_height;
    Image image(height, width);

    for (int64_t i = height - 1; i >= 0; --i) {
        for (int64_t j = 0; j < width; ++j) {
            uint8_t blue = 0;
            uint8_t green = 0;
            uint8_t red = 0;
            read >> blue >> green >> red;
            double actual_blue = blue / max_colour_value;
            double actual_green = green / max_colour_value;
            double actual_red = red / max_colour_value;
            image.pixels[i][j] = Pixel(actual_red, actual_green, actual_blue);
        }

        uint32_t byte_width = width * 3;
        uint32_t nulls = (4 - (byte_width % 4)) % 4;
        for (uint32_t index = 0; index < nulls; ++index) {
            uint8_t additional_null = 0;
            read >> additional_null;
        }
    }
    return BMPFile(header, image_header, image);
}

void BMPWrite(const BMPFile& file, const std::string& out_path) {
    const double max_colour_value = 255;
    BinaryWriter write(out_path);
    BMPHeader header = file.header_;
    ImageHeader image_header = file.image_header_;
    Image image = file.image_;

    uint32_t width = static_cast<int32_t>(image.pixels[0].size());
    uint32_t height = static_cast<int32_t>(image.pixels.size());
    uint32_t byte_width = width * 3;
    uint32_t nulls = (4 - (byte_width % 4)) % 4;

    uint32_t image_size = (byte_width + nulls) * height;
    header.bf_size = sizeof(BMPHeader) + sizeof(ImageHeader) + image_size;

    image_header.bi_size = sizeof(ImageHeader);
    image_header.bi_width = width;
    image_header.bi_height = height;
    image_header.bi_size_image = image_size;
    image_header.bi_clr_used = 0;
    image_header.bi_clr_important = 0;

    write << header.bf_type;
    write << header.bf_size;
    write << header.bf_reserved1;
    write << header.bf_reserved2;
    write << header.bf_offbits;

    write << image_header.bi_size;
    write << image_header.bi_width;
    write << image_header.bi_height;
    write << image_header.bi_planes;
    write << image_header.bi_bit_count;
    write << image_header.bi_compression;
    write << image_header.bi_size_image;
    write << image_header.bi_xpels_per_meter;
    write << image_header.bi_ypels_per_meter;
    write << image_header.bi_clr_used;
    write << image_header.bi_clr_important;

    for (int64_t i = height - 1; i >= 0; --i) {
        for (int64_t j = 0; j < width; ++j) {
            uint8_t red = static_cast<uint8_t>(image.pixels[i][j].red * max_colour_value);
            uint8_t green = static_cast<uint8_t>(image.pixels[i][j].green * max_colour_value);
            uint8_t blue = static_cast<uint8_t>(image.pixels[i][j].blue * max_colour_value);

            write << blue << green << red;
        }

        for (uint32_t index = 0; index < nulls; ++index) {
            write << static_cast<uint8_t>(0);
        }
    }
}
