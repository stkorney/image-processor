#pragma once

#include "../filters/base_filter.h"

#include <memory>

struct BaseFabric {
    virtual std::shared_ptr<BaseFilter> Create(const std::vector<std::string>& input_params) = 0;
    virtual ~BaseFabric() = default;
};
