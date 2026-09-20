#ifndef CONTENT_TEXT_H
#define CONTENT_TEXT_H

#include <vector>
#include <variant>
#include <string>

#include "assets/font.h"
#include "content/content.h"

namespace Content {

struct TextSpan {
    bool bold = false;
    bool italic = false;
    int size = 12;
    Assets::Fonts::FontHandle font;
    std::string text;
};
using TextItem =
    std::variant<TextSpan, Geometry, Model, Sprite>;

struct TextArea {
    std::vector<TextItem> textItems;
};

TextArea ConstructTextArea(int size, Assets::Fonts::FontHandle fontHandle, std::string text);

} // namespace Content

#endif // CONTENT_TEXT_H