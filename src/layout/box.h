#ifndef LAYOUT_BOX_H
#define LAYOUT_BOX_H

#include <variant>

#include "content/content.h"
#include "layout/kinds.h"
#include "layout/units.h"

namespace Layout {

struct Box {
    // This box' children and how to arrange them
    Layout::Kinds::Any layout;
    // The content that will go into this box
    Content::Any content;
    // How this box should fit its content to its space
    Content::Fit contentFit;

    // size vector, indexed by axis
    // [x, y]
    Layout::Units::LayoutSize size[2];
};

} // namespace Layout

#endif // LAYOUT_BOX_H