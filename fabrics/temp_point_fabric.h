#pragma once

#include "base_fabric.h"

struct TempPointFabric : public BaseFabric {
    std::shared_ptr<BaseFilter> Create(const std::vector<std::string>& input_params) override;
};
