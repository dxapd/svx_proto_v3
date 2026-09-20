#include <vector>

#include "assets/store.h"
#include "raylib.h"
#include "renderer/backend.h"
#include "renderer/draw_command.h"
#include "util/overloads.h"

namespace Renderer {
namespace Backend {

void RenderFrameAndWait(std::vector<DrawCmd>& drawCommands) {
    BeginDrawing();
    ClearBackground(BLACK);
    for (const DrawCmd& cmd : drawCommands) {
        std::visit(
            Util::Overloads{[&](const DrawGlyphs& glyphCmd) {
                                Assets::Fonts::FontHandle fontHandle =
                                    glyphCmd.glyphs.fontHandle;
                                // probably no way around how ugly this line is
                                // for now?
                                Font font = Assets::Store::Get()
                                                .fontAssets.GetFont(fontHandle)
                                                .font;
                                float fontSize = glyphCmd.glyphs.size;

                                float penX = (float)glyphCmd.x;
                                for (const Assets::Fonts::ShapedGlyph& glyph :
                                     glyphCmd.glyphs.glyphs) {
                                    Vector2 pos{penX + glyph.dx,
                                                (float)glyphCmd.y + glyph.dy};
                                    DrawTextCodepoint(font, glyph.codepoint,
                                                      pos, fontSize, WHITE);
                                    penX += glyph.advance;
                                }
                            },
                            [&](const DrawRect& rectCmd) {
                                DrawRectangleLines(rectCmd.x, rectCmd.y,
                                                   rectCmd.width,
                                                   rectCmd.height, WHITE);
                            }},
            cmd);
    }
    EndDrawing();
}

}  // namespace Backend
}  // namespace Renderer