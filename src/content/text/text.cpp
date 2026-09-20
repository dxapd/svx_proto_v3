#include "content/text.h"

#include "assets/font.h"

namespace Content {

TextArea ConstructTextArea(int size,
                           Assets::Fonts::FontHandle fontHandle,
                           std::string text) {
    TextArea textArea{};
    TextSpan textSpan{false, false, size, fontHandle, text};

    // TODO: parse the text and construct this properly
    // doesn't matter right now because bold, italic, and inline items are not
    // supported yet
    textArea.textItems.push_back(textSpan);
    return textArea;
}

}  // namespace Content