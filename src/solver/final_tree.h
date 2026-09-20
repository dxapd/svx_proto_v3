#ifndef SOLVER_FINAL_TREE_H
#define SOLVER_FINAL_TREE_H

#include "solver/final_box.h"

namespace Solver {

class FinalTree {
    Solver::FinalBoxHandle rootBoxHandle;
    std::vector<Solver::FinalBox> finalBoxes;
public:
    FinalTree();
    void Reset();
    Solver::FinalBoxHandle InitRoot(Solver::FinalBox finalBox);
    Solver::FinalBoxHandle AddBox(Solver::FinalBox finalBox, Solver::FinalBoxHandle parentHandle);
    Solver::FinalBox& GetBox(Solver::FinalBoxHandle finalBoxHandle);
    Solver::FinalBoxHandle GetRootBox();
    size_t Count() const;
};

} // namespace Solver

#endif // SOLVER_FINAL_TREE_H