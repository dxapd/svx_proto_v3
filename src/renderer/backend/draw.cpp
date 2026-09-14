#include <vector>

#include "raylib.h"
#include "renderer/backend.h"
#include "renderer/draw_command.h"

namespace Renderer {
namespace Backend {

void RenderFrameAndWait(std::vector<DrawCmd>& drawCommands) {
    BeginDrawing();
    ClearBackground(BLACK);
    for (const DrawCmd& cmd : drawCommands) {
        DrawRectangleLines(cmd.x, cmd.y, cmd.width, cmd.height, WHITE);
    }
    EndDrawing();
}

}  // namespace Backend
}  // namespace Renderer