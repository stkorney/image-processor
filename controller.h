#pragma once

#include "fabrics/base_fabric.h"
#include "fabrics/crop_fabric.h"
#include "fabrics/sharpening_fabric.h"
#include "fabrics/gray_scale_fabric.h"
#include "fabrics/negative_fabric.h"
#include "fabrics/edge_fabric.h"
#include "filters/base_filter.h"
#include "parser.h"
#include "image.h"

#include <memory>
#include <unordered_map>
#include <vector>

extern const std::unordered_map<std::string, std::shared_ptr<BaseFabric>> fabrics;

std::vector<std::shared_ptr<BaseFilter>> CreateFilters(const std::vector<InputFilter>& input_filters);

void ApplyFilters(const std::vector<std::shared_ptr<BaseFilter>>& filters, Image& image);
