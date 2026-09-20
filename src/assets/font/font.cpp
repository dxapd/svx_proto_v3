#include "assets/font.h"

#include "raylib.h"

namespace Assets {
namespace Fonts {

// TODO: Uncouple this from raylib
Assets::Fonts::FontHandle Assets::Fonts::FontAssets::LoadFontFromPath(
    std::string path) {
    Font font = LoadFontEx(path.c_str(), 120, nullptr, 0);
    LoadedFont loadedFont{font};
    fonts.push_back(loadedFont);
    return fonts.size() - 1;
}

Assets::Fonts::LoadedFont& Assets::Fonts::FontAssets::GetFont(
    FontHandle fontHandle) {
    return fonts[fontHandle];
}

}  // namespace Fonts
}  // namespace Assets