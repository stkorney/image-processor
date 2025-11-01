#pragma once

#include "image.h"
#include <cstdint>
#include <string>

struct BMPHeader {
    uint16_t bf_type;
    uint32_t bf_size;
    uint16_t bf_reserved1;
    uint16_t bf_reserved2;
    uint32_t bf_offbits;
};

struct ImageHeader {
    uint32_t bi_size;
    uint32_t bi_width;
    uint32_t bi_height;
    uint16_t bi_planes;
    uint16_t bi_bit_count;
    uint32_t bi_compression;
    uint32_t bi_size_image;
    uint32_t bi_xpels_per_meter;
    uint32_t bi_ypels_per_meter;
    uint32_t bi_clr_used;
    uint32_t bi_clr_important;
};

struct BMPFile {
    BMPHeader header_;
    ImageHeader image_header_;
    Image image_;

    BMPFile (BMPHeader header, ImageHeader image_header, Image image)
        : header_(header), image_header_(image_header), image_(image)
    {}
};

BMPFile BMPRead(const std::string& in_path);

void BMPWrite(const BMPFile& file, const std::string& out_path);
