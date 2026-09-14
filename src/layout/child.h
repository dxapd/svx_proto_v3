#ifndef LAYOUT_CHILD_H
#define LAYOUT_CHILD_H

#include "layout/handle.h"

namespace Layout {

template <typename Params>
struct Child {
    Layout::BoxHandle box;
    Params params;
};

} // namespace Layout

#endif // LAYOUT_CHILD_H