#include "edge_fabric.h"
#include "../exceptions.h"
#include "../filters/edge.h"

std::shared_ptr<BaseFilter> EdgeFabric::Create(const std::vector<std::string>& input_params) {
    if (input_params.size() != 1) {
        throw FilterException("'Edge' expects 1 parameter.");
    }

    double threshold = 0;

    try {
        threshold = static_cast<double>(std::stod(input_params[0]));
    } catch (...) {
        throw FilterException("Invalid threshold argument.");
    }

    return std::make_shared<Edge>(threshold);
}
