#include "assets/glyph.h"
#include "assets/store.h"
#include "raylib.h"

namespace Assets {
namespace Fonts {

Assets::Fonts::GlyphRun ShapeText(std::string text,
                                  FontHandle fontHandle,
                                  int fontSize) {
    const char* ptr = text.c_str();
    std::vector<Assets::Fonts::ShapedGlyph> shapedGlyphs;
    Font font = Assets::Store::Get().fontAssets.GetFont(fontHandle).font;
    float scale = fontSize / (float)font.baseSize;
    float curr = 0;

    while (*ptr != '\0') {
        int codepointSize = 0;
        int codepoint = GetCodepointNext(ptr, &codepointSize);
        int glyphIndex = GetGlyphIndex(font, codepoint);
        float advance = 0;

        if (font.glyphs[glyphIndex].advanceX != 0) {
            advance = (float)font.glyphs[glyphIndex].advanceX;
        } else {
            advance = font.recs[glyphIndex].width;
        }

        advance *= scale;
        ShapedGlyph glyph{codepoint, advance, 0, 0};
        shapedGlyphs.push_back(glyph);

        curr += advance;
        ptr += codepointSize;
    }

    Assets::Fonts::GlyphRun glyphRun{fontSize, curr, fontHandle, shapedGlyphs};
    return glyphRun;
}

}  // namespace Fonts
}  // namespace Assets