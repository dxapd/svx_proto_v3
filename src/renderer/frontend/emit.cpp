#include <ranges>
#include <vector>

#include "renderer/frontend.h"
#include "solver/final_box.h"
#include "solver/text.h"
#include "util/overloads.h"

namespace Renderer {
namespace Frontend {

void EmitDrawList(Solver::FinalTree& finalTree,
                  std::vector<Renderer::DrawCmd>& drawList) {
    std::vector<Solver::FinalBoxHandle> stack;
    stack.emplace_back(finalTree.GetRootBox());

    while (!stack.empty()) {
        Solver::FinalBoxHandle curr = std::move(stack.back());
        stack.pop_back();
        // TODO: figure out how to not run into const vs. non-const pitfall
        const Solver::FinalBox& currBox = finalTree.GetBox(curr);

        std::visit(
            Util::Overloads{
                [&](const Solver::FinalTextArea& textCmd) {
                    for (Solver::Line line : textCmd.lines) {
                        Renderer::DrawCmd command;
                        for (Solver::FinalItem item : line.finalItems) {
                            command = Renderer::DrawGlyphs{
                                currBox.position[0] + item.x,
                                currBox.position[1] + item.y,
                                std::get<Assets::Fonts::GlyphRun>(item.item)};
                            drawList.push_back(command);
                        }
                    }
                },
                [&](const auto&) {
                    Renderer::DrawCmd command;
                    command = Renderer::DrawRect{
                        currBox.position[0], currBox.position[1],
                        currBox.extent[0], currBox.extent[1]};

                    drawList.push_back(command);
                }},
            currBox.content);

        for (auto& child : currBox.children) {
            stack.push_back(child);
        }
    }
}

}  // namespace Frontend
}  // namespace Renderer