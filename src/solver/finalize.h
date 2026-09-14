#ifndef SOLVER_FINALIZE_H
#define SOLVER_FINALIZE_H

#include "solver/final_tree.h"
#include "solver/final_box.h"
#include "layout/tree.h"

namespace Solver {

Solver::FinalBox SolveViewportBox(Layout::Tree &layoutTree, Layout::BoxHandle viewportBoxHandle);
void FinalizeTree(Layout::Tree &layoutTree, Solver::FinalTree &finalTree);

} // namespace Solver

#endif // SOLVER_FINALIZE_H