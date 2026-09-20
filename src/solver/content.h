#ifndef SOLVER_CONTENT_H
#define SOLVER_CONTENT_H

#include "solver/text.h"

namespace Solver {

using FinalContent = std::variant<std::monostate, FinalTextArea>;

} // namespace Solver

#endif // SOLVER_CONTENT_H