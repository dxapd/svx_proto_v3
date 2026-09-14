#include "layout/child.h"
#include "layout/tree.h"
#include "solver/algorithms.h"
#include "solver/units.h"

namespace Solver {

Solver::FinalBox ResolveBox(
    const Layout::Child<Layout::Kinds::FreeParams>& child,
    const Layout::Kinds::Free& layout,
    const Solver::FinalBox& parent,
    Layout::Tree& layoutTree) {
    Layout::Box curr = layoutTree.GetBox(child.box);
    Solver::FinalBox finalBox = {
        parent.x + Solver::ResolvePos(child.params.x, parent.width),
        parent.y + Solver::ResolvePos(child.params.y, parent.height),
        Solver::ResolveSize(curr.width, parent.width),
        Solver::ResolveSize(curr.height, parent.height), child.box};

    return finalBox;
}

}  // namespace Solver