#include "negative_fabric.h"
#include "../exceptions.h"
#include "../filters/negative.h"

std::shared_ptr<BaseFilter> NegativeFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 0)  {
        throw FilterException("'Negative' expects no parameters.");
    }

    return std::make_shared<Negative>();
}
