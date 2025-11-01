#include "controller.h"
#include "parser.h"
#include "bmp.h"
#include "exceptions.h"
#include <iostream>

int main(int argc, char** argv) {
    try {
        ParserResults parsed = Parse(argc, argv);
        BMPFile input_file = BMPRead(parsed.input_file);
        std::vector<std::shared_ptr<BaseFilter>> filters = CreateFilters(parsed.input_filters);
        ApplyFilters(filters, input_file.image_);
        BMPWrite(input_file, parsed.output_file);
    } catch(const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
    return 0;
}
