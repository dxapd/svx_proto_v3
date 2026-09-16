#ifndef LAYOUT_UNITS_H
#define LAYOUT_UNITS_H

#include <variant>

namespace Layout {
namespace Units {

struct Pixels {
    int value;
};
struct Percent {
    float value;
};
struct Auto {};

using LayoutSize = std::variant<Pixels, Percent, Auto>;
using LayoutPos = std::variant<Pixels, Percent>;

} // namespace Units
} // namespace Layout

#endif // LAYOUT_UNITS_H