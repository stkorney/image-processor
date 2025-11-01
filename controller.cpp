#include "controller.h"
#include "exceptions.h"

extern const std::unordered_map<std::string, std::shared_ptr<BaseFabric>> FABRICS = {
    {"crop", std::make_shared<CropFabric>()},    {"sharp", std::make_shared<SharpeningFabric>()},
    {"gs", std::make_shared<GrayScaleFabric>()}, {"neg", std::make_shared<NegativeFabric>()},
    {"edge", std::make_shared<EdgeFabric>()},    {"tempp", std::make_shared<TempPointFabric>()}};

std::vector<std::shared_ptr<BaseFilter>> CreateFilters(const std::vector<InputFilter>& input_filters) {
    std::vector<std::shared_ptr<BaseFilter>> filters;

    for (const auto& input_filter : input_filters) {
        auto fabric = FABRICS.find(input_filter.filter_name);
        if (fabric == FABRICS.end()) {
            throw ControllerException(input_filter.filter_name + "is not a filter.");
        }
        filters.push_back(fabric->second->Create(input_filter.filter_params));
    }

    return filters;
}

void ApplyFilters(const std::vector<std::shared_ptr<BaseFilter>>& filters, Image& image) {
    for (const auto& filter : filters) {
        filter->Apply(image);
    }
}
