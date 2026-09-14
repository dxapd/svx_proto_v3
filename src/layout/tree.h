#ifndef LAYOUT_TREE_H
#define LAYOUT_TREE_H

#include <vector>

#include "layout/box.h"

namespace Layout {

class Tree {
    std::vector<Layout::Box> boxes;
    Layout::BoxHandle viewportBoxHandle;

   public:
    Tree(int viewportWidth,
               int viewportHeight);

    // it's annoying that i have to put this here
    // and more annoying that my only other option is
    // arcane template declarations in the .cpp
    template <typename Params>
    Layout::BoxHandle AddChild(Layout::BoxHandle parent,
                                     Params p,
                                     Layout::Box box) {
        using Method = typename Params::Method;
        boxes.emplace_back(box);

        Layout::Child<Params> child;
        child.box = boxes.size() - 1;
        child.params = p;

        auto& layout = std::get<Method>(boxes[parent].layout);
        layout.children.push_back(child);

        return boxes.size() - 1;
    }
    Layout::BoxHandle& GetViewportBox();
    Layout::Box& GetBox(Layout::BoxHandle handle);
    size_t Count() const;
};

} // namespace Layout

#endif // LAYOUT_TREE_H