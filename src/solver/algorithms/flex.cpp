#include "layout/child.h"
#include "layout/tree.h"
#include "solver/algorithms.h"
#include "solver/units.h"

namespace Solver {

// TODO: There's a bunch of truncation nonsense that's probably
//       happening in here, I need to look at what the floats
//       are doing more carefully.
// TODO: There's a lot of confusion in variable names between
//       boxes, final boxes, box handles, and final box handles.
void SolveLayout(const Layout::Kinds::Flex& layout,
                 const Solver::FinalBox& parent,
                 Layout::Tree& layoutTree,
                 std::vector<Solver::FinalBox>& finalBoxes) {
    int mainAxis = (int)layout.axis;
    int crossAxis = 1 - mainAxis;

    int parentMainExtent = parent.extent[mainAxis];
    int parentCrossExtent = parent.extent[crossAxis];
    int leftoverExtent = parentMainExtent;
    float autoWeights = 0.0;

    // calculate the flex weights and leftover extent to distribute
    for (const Layout::Child<Layout::Kinds::FlexParams>& child :
         layout.children) {
        const Layout::Box& childBox = layoutTree.GetBox(child.box);
        if (std::holds_alternative<Layout::Units::Auto>(
                childBox.size[mainAxis])) {
            autoWeights += child.params.weight;
        } else {
            leftoverExtent -=
                Solver::ResolveSize(childBox.size[mainAxis], parentMainExtent);
        }
    }

    // distribute the leftover extent
    int currOffset = parent.position[mainAxis];
    for (const Layout::Child<Layout::Kinds::FlexParams>& child :
         layout.children) {
        Solver::FinalBox finalChild = {};
        const Layout::Box& childBox = layoutTree.GetBox(child.box);

        // calculate this child's main axis extent
        int childExtent = 0;
        if (std::holds_alternative<Layout::Units::Auto>(
                childBox.size[mainAxis])) {
            // this is probably doing some truncation
            childExtent =
                (int)((child.params.weight / autoWeights) * leftoverExtent);
        } else {
            childExtent =
                Solver::ResolveSize(childBox.size[mainAxis], parentMainExtent);
        }

        // construct this child's finalized box
        finalChild.position[mainAxis] = currOffset;
        // TODO: Cross axis policy (centering etc.)
        finalChild.position[crossAxis] = parent.position[crossAxis];
        finalChild.extent[mainAxis] = childExtent;
        if (std::holds_alternative<Layout::Units::Auto>(
                childBox.size[crossAxis])) {
            finalChild.extent[crossAxis] = parent.extent[crossAxis];
        } else {
            finalChild.extent[crossAxis] = Solver::ResolveSize(
                childBox.size[crossAxis], parentCrossExtent);
        }
        finalChild.originalBoxHandle = child.box;

        currOffset += childExtent;
        finalBoxes.push_back(finalChild);
    }
}

}  // namespace Solver