#ifndef LAYOUT_UNITS_H
#define LAYOUT_UNITS_H

#include <variant>

namespace Layout {

struct Pixels {
    int value;
};
struct Percent {
    float value;
};
struct Auto {};

using LayoutSize = std::variant<Pixels, Percent, Auto>;
using LayoutPos = std::variant<Pixels, Percent>;

} // namespace Layout

#endif // LAYOUT_UNITS_H