#ifndef SOLVER_FINAL_BOX_H
#define SOLVER_FINAL_BOX_H

#include <vector>

#include "layout/box.h"

namespace Solver {

using FinalBoxHandle = size_t;

struct FinalBox {
    // absolute position vector, indexed by axis
    // [x, y]
    int position[2];
    // calculated box size vector, indexed by axis
    // [x, y]
    int extent[2];

    Layout::BoxHandle originalBoxHandle;
    Solver::FinalBoxHandle handle;
    std::vector<Solver::FinalBoxHandle> children;
};

} // namespace Solver

#endif // SOLVER_FINAL_BOX_H