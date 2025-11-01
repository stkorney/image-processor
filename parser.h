#pragma once

#include "exceptions.h"
#include <string>
#include <vector>

struct InputFilter {
    std::string filter_name;
    std::vector<std::string> filter_params;
};

struct ParserResults {
    std::string input_file;
    std::string output_file;
    std::vector<InputFilter> input_filters;
};

ParserResults Parse(int argc, char** argv);
