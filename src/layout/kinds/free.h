#ifndef LAYOUT_KINDS_FREE_H
#define LAYOUT_KINDS_FREE_H

#include <vector>

#include "layout/child.h"
#include "layout/units.h"

namespace Layout {
namespace Kinds {

struct Free;
struct FreeParams {
    using Method = Free;
    LayoutPos x;
    LayoutPos y;
};

struct Free {
    std::vector<Layout::Child<FreeParams>> children;
};

} // namespace Kinds
} // namespace Layout

#endif // LAYOUT_KINDS_FREE_H