#ifndef LAYOUT_KINDS_FLEX_H
#define LAYOUT_KINDS_FLEX_H

#include <vector>

#include "layout/child.h"

namespace Layout {
namespace Kinds {

struct Flex;
struct FlexParams {
    using Method = Flex;
    float weight;
};
enum class Axis {
    Horizontal = 0, // x axis
    Vertical = 1, // y axis
};
struct Flex {
    Axis axis;
    std::vector<Layout::Child<FlexParams>> children;
};

} // namespace Kinds
} // namespace Layout

#endif // LAYOUT_KINDS_FLEX_H