#include "temp_point_fabric.h"
#include "../exceptions.h"
#include "../filters/temp_point.h"

#include <string>

std::shared_ptr<BaseFilter> TempPointFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 2) {
        throw FilterException("'Temperature point' expects 2 parameters.");
    }

    double x_part = 0;

    try {
        x_part = static_cast<double>(std::stod(input_params[0]));
    } catch (...) {
        throw FilterException("Invalid x_part argument.");
    }

    double y_part = 0;

    try {
        y_part = static_cast<double>(std::stod(input_params[1]));
    } catch (...) {
        throw FilterException("Invalid y_part argument.");
    }
    if (x_part < 0 || y_part < 0 || x_part > 1 || y_part > 1) {
        throw FilterException("Width and height arguments for 'Temperature point' must be between 0 and 1.");
    }

    return std::make_shared<TempPoint>(x_part, y_part);
}
