#ifndef RENDERER_FRONTEND_H
#define RENDERER_FRONTEND_H

#include <vector>
#include "solver/finalize.h"
#include "renderer/backend.h"

namespace Renderer {
namespace Frontend {

void EmitDrawList(Solver::FinalTree &finalizeTree, std::vector<Renderer::DrawCmd> &drawList);

} // namespace Frontend
} // namespace Renderer

#endif // RENDERER_FRONTEND_H