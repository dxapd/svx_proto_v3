#ifndef ASSETS_GLYPH_H
#define ASSETS_GLYPH_H

#include <vector>
#include <string>

#include "assets/font.h"

namespace Assets {
namespace Fonts {

struct ShapedGlyph {
    int codepoint;
    float advance;
    int dx;
    int dy;
};

struct GlyphRun {
    int size;
    float width;
    FontHandle fontHandle;
    std::vector<Assets::Fonts::ShapedGlyph> glyphs;
};

Assets::Fonts::GlyphRun ShapeText(std::string text, FontHandle font, int fontSize);

} // namespace Font
} // namespace Assets

#endif // ASSETS_GLYPH_H