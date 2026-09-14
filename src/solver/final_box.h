#ifndef SOLVER_FINAL_BOX_H
#define SOLVER_FINAL_BOX_H

#include <vector>

#include "layout/box.h"

namespace Solver {

using FinalBoxHandle = size_t;

struct FinalBox {
    int x;
    int y;
    int width;
    int height;

    Layout::BoxHandle originalBoxHandle;
    Solver::FinalBoxHandle handle;
    std::vector<Solver::FinalBoxHandle> children;
};

} // namespace Solver

#endif // SOLVER_FINAL_BOX_H