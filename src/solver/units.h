#ifndef SOLVER_UNITS_H
#define SOLVER_UNITS_H

#include "layout/units.h"

namespace Solver {

int ResolvePos(const Layout::LayoutPos& pos, int parentExtent);
int ResolveSize(const Layout::LayoutSize& size, int parentExtent);

}

#endif // SOLVER_UNITS_H