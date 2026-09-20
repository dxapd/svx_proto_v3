#include "layout/child.h"
#include "layout/tree.h"
#include "solver/algorithms.h"
#include "solver/units.h"

namespace Solver {

void SolveLayout(const Layout::Kinds::Free& layout,
                 const Solver::FinalBox& parent,
                 Layout::Tree& layoutTree,
                 std::vector<Solver::FinalBox>& finalBoxes) {
    for (const Layout::Child<Layout::Kinds::FreeParams>& child :
         layout.children) {
        const Layout::Box& curr = layoutTree.GetBox(child.box);
        Solver::FinalBox finalBox = {
            {parent.position[0] +
                 Solver::ResolvePos(child.params.x, parent.extent[0]),
             parent.position[1] +
                 Solver::ResolvePos(child.params.y, parent.extent[1])},
            {Solver::ResolveSize(curr.size[0], parent.extent[0]),
             Solver::ResolveSize(curr.size[1], parent.extent[1])},
            child.box};

        finalBoxes.push_back(finalBox);
    }
}

}  // namespace Solver