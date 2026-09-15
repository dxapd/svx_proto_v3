#include "layout/child.h"
#include "layout/tree.h"
#include "solver/algorithms.h"

namespace Solver {

Solver::FinalBox SolveBox(
    const Layout::Child<Layout::Kinds::FlexParams>& child,
    const Layout::Kinds::Flex& layout,
    const Solver::FinalBox& parent,
    Layout::Tree& layoutTree) {
    return {};
}

}  // namespace Solver