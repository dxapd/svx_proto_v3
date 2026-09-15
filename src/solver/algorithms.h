#ifndef SOLVER_ALGORITHMS_H
#define SOLVER_ALGORITHMS_H

#include "layout/tree.h"
#include "layout/kinds.h"
#include "solver/final_box.h"

namespace Solver {

Solver::FinalBox SolveBox(const Layout::Child<Layout::Kinds::FreeParams>& child, 
                            const Layout::Kinds::Free& layout,
                            const Solver::FinalBox& parent,
                            Layout::Tree& layoutTree);

Solver::FinalBox SolveBox(const Layout::Child<Layout::Kinds::FlexParams>& child, 
                            const Layout::Kinds::Flex& layout,
                            const Solver::FinalBox& parent,
                            Layout::Tree& layoutTree);

} // namespace Solver

#endif // SOLVER_ALGORITHMS_H