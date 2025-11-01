#include "sharpening_fabric.h"
#include "../exceptions.h"
#include "../filters/sharpening.h"

std::shared_ptr<BaseFilter> SharpeningFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 0)  {
        throw FilterException("'Sharpening' expects no parameters.");
    }

    return std::make_shared<Sharpening>();
}
