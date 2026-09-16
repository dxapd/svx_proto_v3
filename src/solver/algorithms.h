#ifndef SOLVER_ALGORITHMS_H
#define SOLVER_ALGORITHMS_H

#include "layout/tree.h"
#include "layout/kinds.h"
#include "solver/final_box.h"

namespace Solver {

void SolveLayout(const Layout::Kinds::Free& layout,
                            const Solver::FinalBox& parent,
                            Layout::Tree& layoutTree,
                            std::vector<Solver::FinalBox>& finalBoxes);

void SolveLayout(const Layout::Kinds::Flex& layout,
                            const Solver::FinalBox& parent,
                            Layout::Tree& layoutTree,
                            std::vector<Solver::FinalBox>& finalBoxes);

} // namespace Solver

#endif // SOLVER_ALGORITHMS_H