#include "gray_scale_fabric.h"
#include "../exceptions.h"
#include "../filters/gray_scale.h"

std::shared_ptr<BaseFilter> GrayScaleFabric::Create(const std::vector<std::string>& input_params) {
    if (!input_params.empty()) {
        throw FilterException("'GrayScale' expects no parameters.");
    }

    return std::make_shared<GrayScale>();
}
