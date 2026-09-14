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
    Horizontal,
    Vertical,
};
struct Flex {
    Axis axis;
    std::vector<Layout::Child<FlexParams>> children;
};

} // namespace Kinds
} // namespace Layout

#endif // LAYOUT_KINDS_FLEX_H