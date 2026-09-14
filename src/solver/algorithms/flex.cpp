#include "solver/algorithms.h"
#include "layout/child.h"
#include "layout/tree.h"

namespace Solver {

Solver::FinalBox ResolveBox(const Layout::Child<Layout::Kinds::FlexParams>& child, 
                const Layout::Kinds::Flex& layout,
                const Solver::FinalBox& parent,
                Layout::Tree& layoutTree) {
    return {};
}

} // namespace Solver