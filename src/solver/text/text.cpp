#include "solver/text.h"

#include <ranges>

namespace Solver {

// TODO: handle non-text
Solver::FinalTextArea SolveTextContent(Content::TextArea textArea,
                                       int maxWidth) {
    Solver::FinalTextArea finalTextArea{};
    Solver::Line line{};

    std::vector<Assets::Fonts::GlyphRun> brokenRuns;
    for (Content::TextItem& textItem : textArea.textItems) {
        // unneeded variant smell
        Content::TextSpan span = std::get<Content::TextSpan>(textItem);
        Assets::Fonts::GlyphRun run =
            Assets::Fonts::ShapeText(span.text, span.font, span.size);

        // chunk run into runs that are < maxWidth
        int glyphIndex = 0;
        float runningWidth = 0.0;
        Assets::Fonts::GlyphRun brokenRun = run;
        brokenRun.glyphs.clear();
        brokenRun.width = 0;

        struct BreakCandidate {
            int resumeIndex;  // the start of the next line to resume from
            float runningWidth;
        };
        BreakCandidate lastBreakCandidate = {-1, 0.0};
        int runStart = 0;
        while (glyphIndex < run.glyphs.size()) {
            Assets::Fonts::ShapedGlyph& glyph = run.glyphs[glyphIndex];

            if (glyph.advance + runningWidth <= maxWidth) {
                brokenRun.glyphs.push_back(glyph);
                runningWidth += glyph.advance;
                glyphIndex++;
                if (glyph.codepoint == ' ') {
                    lastBreakCandidate = {glyphIndex, runningWidth};
                }
            } else {
                BreakCandidate breakCandidate{};
                if (lastBreakCandidate.resumeIndex != -1) {
                    breakCandidate = lastBreakCandidate;
                } else {
                    if (brokenRun.glyphs.empty()) {
                        brokenRun.glyphs.push_back(glyph);
                        runningWidth += glyph.advance;
                        glyphIndex++;
                    }
                    breakCandidate = {glyphIndex, runningWidth};
                }
                brokenRun.glyphs.resize(breakCandidate.resumeIndex - runStart);
                brokenRun.width = breakCandidate.runningWidth;
                glyphIndex = breakCandidate.resumeIndex;
                brokenRuns.push_back(brokenRun);
                runningWidth = 0;
                lastBreakCandidate.resumeIndex = -1;
                brokenRun.glyphs.clear();
                brokenRun.width = 0;
                runStart = glyphIndex;
            }
        }

        if (!brokenRun.glyphs.empty()) {
            brokenRun.width = runningWidth;
            brokenRuns.push_back(brokenRun);
        }
    }

    int y = 0;
    for (Assets::Fonts::GlyphRun run : brokenRuns) {
        Solver::Line line;
        Solver::FinalItem finalItem;

        finalItem.x = 0;
        finalItem.y = y;
        finalItem.width = (int)run.width;
        finalItem.height = run.size;
        finalItem.item = run;
        line.finalItems.push_back(finalItem);
        finalTextArea.lines.push_back(line);
        y += run.size;
    }

    return finalTextArea;
}

}  // namespace Solver