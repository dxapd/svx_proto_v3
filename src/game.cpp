#include "game.h"

#include <vector>

#include "layout/box.h"
#include "layout/kinds.h"
#include "layout/tree.h"
#include "renderer/backend.h"
#include "renderer/frontend.h"

static constexpr int WIDTH = 800;
static constexpr int HEIGHT = 600;

void ConstructTree(Layout::Tree& layoutTree) {
    Layout::BoxHandle viewportBox = layoutTree.GetViewportBox();

    Layout::BoxHandle contentArea = layoutTree.AddChild(
        viewportBox,
        Layout::Kinds::FreeParams{Layout::Units::Pixels{0}, Layout::Units::Pixels{0}},
        Layout::Box{Layout::Kinds::Flex{Layout::Kinds::Axis::Vertical}, std::monostate{}, Content::Fit::Fill,
                    {Layout::Units::Pixels{800}, Layout::Units::Pixels{600}}});

    Layout::BoxHandle contentSpacer = layoutTree.AddChild(
        contentArea,
        Layout::Kinds::FlexParams{2.0},
        Layout::Box{Layout::Kinds::Free{}, std::monostate{}, Content::Fit::Fill,
                    {Layout::Units::Auto{}, Layout::Units::Auto{}}});

    Layout::BoxHandle dialogueArea = layoutTree.AddChild(
        contentArea,
        Layout::Kinds::FlexParams{1.0},
        Layout::Box{Layout::Kinds::Flex{}, std::monostate{}, Content::Fit::Fill,
                    {Layout::Units::Auto{}, Layout::Units::Auto{}}});

    Layout::BoxHandle portraitBox = layoutTree.AddChild(
        dialogueArea,
        Layout::Kinds::FlexParams{1.0},
        Layout::Box{Layout::Kinds::Free{}, std::monostate{}, Content::Fit::Fill,
                    {Layout::Units::Pixels{200}, Layout::Units::Auto{}}});

    Layout::BoxHandle textBox = layoutTree.AddChild(
        dialogueArea,
        Layout::Kinds::FlexParams{2.0},
        Layout::Box{Layout::Kinds::Free{}, std::monostate{}, Content::Fit::Fill,
                    {Layout::Units::Auto{}, Layout::Units::Auto{}}});

    Layout::BoxHandle highlightBox = layoutTree.AddChild(
        dialogueArea,
        Layout::Kinds::FlexParams{1.0},
        Layout::Box{Layout::Kinds::Free{}, std::monostate{}, Content::Fit::Fill,
                    {Layout::Units::Pixels{200}, Layout::Units::Auto{}}});
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