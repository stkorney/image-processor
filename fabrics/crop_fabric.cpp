#include "crop_fabric.h"
#include "../exceptions.h"
#include "../filters/crop.h"

#include <string>

std::shared_ptr<BaseFilter> CropFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 2) {
        throw FilterException("'Crop' expects 2 parameters.");
    }

    size_t width = 0;

    try {
        width = static_cast<size_t>(std::stoul(input_params[0]));
    } catch (...) {
        throw FilterException("Invalid width argument.");
    }

    size_t height = 0;

    try {
        height = static_cast<size_t>(std::stoul(input_params[1]));
    } catch (...) {
        throw FilterException("Invalid height argument for 'Crop'.");
    }

    if (width < 0 || height < 0) {
        throw FilterException("Width and height arguments for 'Crop' must be at least 0.");
    }

    return std::make_shared<Crop>(width, height);
}
