#ifndef ASSETS_STORE_H
#define ASSETS_STORE_H

#include <vector>
#include <optional>
#include "assets/font.h"

namespace Assets {

struct Store {
    static void Init() { s.emplace(); }
    static void Cleanup() { s.reset(); }
    static Store& Get() { return *s; }

    Assets::Fonts::FontAssets fontAssets;
private:
    static std::optional<Store> s;
};

inline std::optional<Store> Store::s;

} // namespace Assets

#endif // ASSETS_STORE_H