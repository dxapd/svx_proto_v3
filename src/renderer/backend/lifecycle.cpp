#include "raylib.h"
#include "renderer/backend.h"

namespace Renderer {
namespace Backend {

void Initialize() {
    const int W = 800;
    const int H = 600;

    InitWindow(W, H, "SVX prototype 3");
    SetTargetFPS(60);
}

void Cleanup() { CloseWindow(); }

bool Done() { return WindowShouldClose(); }

}  // namespace Backend
}  // namespace Renderer