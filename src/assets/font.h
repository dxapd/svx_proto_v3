#ifndef ASSETS_FONT_H
#define ASSETS_FONT_H

#include <vector>
#include <string>

#include "raylib.h"

namespace Assets {
namespace Fonts {

// TODO: Uncouple this from raylib
struct LoadedFont {
    Font font;
};

using FontHandle = size_t;

class FontAssets {
    std::vector<LoadedFont> fonts;
public:
    FontHandle LoadFontFromPath(std::string path);
    LoadedFont& GetFont(FontHandle fontHandle);
};

} // namespace Font
} // namespace Assets

#endif // ASSETS_FONT_H