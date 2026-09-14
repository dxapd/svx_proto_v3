#include "game.h"

#include <vector>

#include "layout/tree.h"
#include "layout/kinds.h"
#include "layout/box.h"
#include "renderer/frontend.h"
#include "renderer/backend.h"

static constexpr int WIDTH = 800;
static constexpr int HEIGHT = 600;

void ConstructTree(Layout::Tree& layoutTree) {
    Layout::BoxHandle viewportBox = layoutTree.GetViewportBox();

    Layout::BoxHandle box_1 = 
        layoutTree.AddChild(viewportBox, 
            Layout::Kinds::FreeParams{
                Layout::Pixels{100}, 
                Layout::Pixels{100}
            },
            Layout::Box{
                Layout::Kinds::Free{}, 
                std::monostate{}, 
                Content::Fit::Fill, 
                Layout::Pixels{400}, 
                Layout::Pixels{400}
            }
        );

    Layout::BoxHandle box_2 = 
        layoutTree.AddChild(box_1, 
            Layout::Kinds::FreeParams{
                Layout::Pixels{60}, 
                Layout::Pixels{60}
            },
            Layout::Box{
                Layout::Kinds::Free{}, 
                std::monostate{}, 
                Content::Fit::Fill, 
                Layout::Pixels{100}, 
                Layout::Pixels{100}
            }
        );
}

void UpdateTree(Layout::Tree& layoutTree) {
    // do something every frame.
    // options:
    // 1. step the Lua coroutine to dispatch all of
    // the desired mutations to the tree
    // 2. process a list of mutation commands created
    // by a separate thread that Lua is running on
    // 3. hardcoded logic for prototype (e.g. do something)
    // on mouse click
}

void RunGame() {
    Layout::Tree layoutTree(WIDTH, HEIGHT);
    Solver::FinalTree finalTree;
    std::vector<Renderer::DrawCmd> drawList;

    Renderer::Backend::Initialize();
    ConstructTree(layoutTree);

    while (!Renderer::Backend::Done()) {
        UpdateTree(layoutTree);

        Solver::FinalizeTree(layoutTree, finalTree);
        Renderer::Frontend::EmitDrawList(finalTree, drawList);
        Renderer::Backend::RenderFrameAndWait(drawList);

        drawList.clear();
    }

    Renderer::Backend::Cleanup();
}