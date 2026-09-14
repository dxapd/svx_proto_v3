#include "content/content.h"
#include "layout/tree.h"

Layout::Tree::Tree(int viewportWidth, int viewportHeight)
    : boxes() {
    Layout::Box viewportBox =
        Layout::Box{Layout::Kinds::Free{}, 
                    std::monostate{},
                    Content::Fit::Fill,
                    Pixels{viewportWidth},
                    Pixels{viewportHeight}
                };

    boxes.emplace_back(viewportBox);
    viewportBoxHandle = 0;
}

Layout::BoxHandle& Layout::Tree::GetViewportBox() {
    return viewportBoxHandle;
}

// box references are not stable.
Layout::Box& Layout::Tree::GetBox(Layout::BoxHandle handle) {
    return boxes[handle];
}

size_t Layout::Tree::Count() const { 
    return boxes.size();
}