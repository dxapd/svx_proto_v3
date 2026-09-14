#include <ranges>

#include "solver/finalize.h"
#include "solver/final_box.h"
#include "solver/final_tree.h"
#include "solver/algorithms.h"

namespace Solver {

Solver::FinalBox SolveViewportBox(Layout::Tree &layoutTree, Layout::BoxHandle viewportBoxHandle) {
    return {
        0,
        0,
        std::get<Layout::Pixels>(layoutTree.GetBox(viewportBoxHandle).width).value,
        std::get<Layout::Pixels>(layoutTree.GetBox(viewportBoxHandle).height).value,
        viewportBoxHandle,
        0,
        {}
    };
}

void FinalizeTree(Layout::Tree &layoutTree, Solver::FinalTree &finalTree) {
    std::vector<Solver::FinalBox> stack;
    Solver::FinalBox finalViewportBox = Solver::SolveViewportBox(layoutTree, layoutTree.GetViewportBox());
    finalTree.InitRoot(finalViewportBox);
    stack.push_back(finalViewportBox);

    while(!stack.empty()) {
        Solver::FinalBox currParent = std::move(stack.back());
        stack.pop_back();

        // solve this parent's layout!
        // we do that by applying its algorithm across all of its children.
        std::visit([&](const auto& layout) {
            // iterate in reverse order to maintain the original order
            for (auto &child : layout.children | std::views::reverse) {
                // this dispatches to the right algorithm via overload.
                Solver::FinalBox finalBox = ResolveBox(child, layout, currParent, layoutTree);

                finalBox.handle = finalTree.AddBox(finalBox, currParent.handle);
                stack.push_back(finalBox);
            }
        }, layoutTree.GetBox(currParent.originalBoxHandle).layout);
    }
}

} // namespace Solver