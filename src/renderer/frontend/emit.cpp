#include <vector>
#include <ranges>

#include "renderer/frontend.h"
#include "solver/final_box.h"

namespace Renderer {
namespace Frontend {

void EmitDrawList(Solver::FinalTree &finalTree, std::vector<Renderer::DrawCmd> &drawList) {
    std::vector<Solver::FinalBoxHandle> stack;
    stack.emplace_back(finalTree.GetRootBox());

    while (!stack.empty()) {
        Solver::FinalBoxHandle curr = std::move(stack.back());
        stack.pop_back();
        Solver::FinalBox currBox = finalTree.GetBox(curr);

        Renderer::DrawCmd command = {
            currBox.x,
            currBox.y,
            currBox.width,
            currBox.height
        };

        drawList.push_back(command);

        for (auto &child : currBox.children) {
            stack.push_back(child);
        }
    }
}

} // namespace Frontend
} // namespace Renderer