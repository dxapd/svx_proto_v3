#ifndef RENDERER_DRAW_COMMAND_H
#define RENDERER_DRAW_COMMAND_H

namespace Renderer {

struct DrawCmd {
    int x;
    int y;

    int width;
    int height;
};

} // namespace Renderer

#endif // RENDERER_DRAW_COMMAND_H