#ifndef RENDERER_BACKEND_H
#define RENDERER_BACKEND_H

#include <vector>
#include "renderer/draw_command.h"

namespace Renderer {
namespace Backend {

void Initialize();
void Cleanup();
bool Done();
void RenderFrameAndWait(std::vector<DrawCmd>& drawCommands);

} // namespace Backend
} // namespace Renderer

#endif // RENDERER_BACKEND_H