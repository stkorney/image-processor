#include "parser.h"

ParserResults Parse(int argc, char** argv) { // обязательно покрыть юнит тестами

    if (argc < 3) {
        throw ParserException("Input file path and output file path must be present.");
    }
    
    ParserResults parser_result;
    parser_result.input_file = argv[1];
    parser_result.output_file = argv[2];

    for (int index = 3; index < argc; ++index) {
        if (argv[index][0] != '-') {
            throw ParserException("Use '-' to call a filter.");
        }
        
        InputFilter new_filter;
        new_filter.filter_name = std::string(argv[index] + 1);
        
        ++index;
        while (index < argc && argv[index][0] != '-') {
            new_filter.filter_params.push_back(argv[index]);
            ++index;
        }
        --index;
        
        parser_result.input_filters.push_back(new_filter);
    }

    return parser_result;
};
