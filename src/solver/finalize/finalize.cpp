#include "solver/finalize.h"

#include <ranges>

#include "solver/algorithms.h"
#include "solver/final_box.h"
#include "solver/final_tree.h"

namespace Solver {

Solver::FinalBox SolveViewportBox(Layout::Tree& layoutTree,
                                  Layout::BoxHandle viewportBoxHandle) {
    return {
        0,
        0,
        std::get<Layout::Units::Pixels>(layoutTree.GetBox(viewportBoxHandle).size[0])
            .value,
        std::get<Layout::Units::Pixels>(layoutTree.GetBox(viewportBoxHandle).size[1])
            .value,
        viewportBoxHandle,
        0,
        {}};
}

void FinalizeTree(Layout::Tree& layoutTree,
                  Solver::FinalTree& finalTree) {
    std::vector<Solver::FinalBox> stack;
    std::vector<Solver::FinalBox> finalBoxes;

    Solver::FinalBox finalViewportBox =
        Solver::SolveViewportBox(layoutTree, layoutTree.GetViewportBox());
    finalTree.InitRoot(finalViewportBox);
    stack.push_back(finalViewportBox);

    while (!stack.empty()) {
        finalBoxes.clear();

        Solver::FinalBox currParent = std::move(stack.back());
        stack.pop_back();

        // solve this parent's layout!
        // we do that by applying its algorithm across all of its children.
        std::visit(
            [&](const auto& layout) {
                SolveLayout(layout, currParent, layoutTree, finalBoxes);
            },
            layoutTree.GetBox(currParent.originalBoxHandle).layout);

            // iterate in reverse order to maintain the original order
            for (Solver::FinalBox& box : finalBoxes | std::views::reverse) {
                box.handle =
                    finalTree.AddBox(box, currParent.handle);
                stack.push_back(box);
            }
    }
}

}  // namespace Solver