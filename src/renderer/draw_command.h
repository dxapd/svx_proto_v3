#ifndef RENDERER_DRAW_COMMAND_H
#define RENDERER_DRAW_COMMAND_H

#include <variant>

#include "assets/glyph.h"

namespace Renderer {

struct DrawRect {
    int x;
    int y;

    int width;
    int height;
};

struct DrawGlyphs {
    int x;
    int y;
    Assets::Fonts::GlyphRun glyphs;
};

using DrawCmd = std::variant<DrawRect, DrawGlyphs>;

} // namespace Renderer

#endif // RENDERER_DRAW_COMMAND_H