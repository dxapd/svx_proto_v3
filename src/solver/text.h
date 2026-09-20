#ifndef SOLVER_TEXT_H
#define SOLVER_TEXT_H

#include <vector>
#include <variant>

#include "assets/glyph.h"
#include "content/text.h"

namespace Solver {

// TODO: Re-evaluate whether or not there's too much indirection here
using TextAreaItem = std::variant<std::monostate, Assets::Fonts::GlyphRun>;

struct FinalItem {
    int x;
    int y;
    int width;
    int height;
    TextAreaItem item;
};

struct Line {
    std::vector<FinalItem> finalItems;
};

struct FinalTextArea {
    std::vector<Line> lines;
};

Solver::FinalTextArea SolveTextContent(Content::TextArea textArea, int maxWidth);

} // namespace Solver

#endif // SOLVER_TEXT_H