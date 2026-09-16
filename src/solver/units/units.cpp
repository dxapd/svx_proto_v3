#include "solver/units.h"

#include <stdexcept>

#include "util/overloads.h"

namespace Solver {

int ResolvePos(const Layout::Units::LayoutPos& pos,
               int parentExtent) {
    return std::visit(
        Util::Overloads{[&](Layout::Units::Pixels px) { return px.value; },
                        [&](Layout::Units::Percent pc) {
                            return (int)(parentExtent * pc.value / 100.0f);
                        }},
        pos);
}

int ResolveSize(const Layout::Units::LayoutSize& size,
                int parentExtent) {
    return std::visit(Util::Overloads{
                          [&](Layout::Units::Pixels px) { return px.value; },
                          [&](Layout::Units::Percent pc) {
                              return (int)(parentExtent * pc.value / 100.0f);
                          },
                          [&](Layout::Units::Auto a) {
                              throw std::runtime_error("Unimplemented");
                              return 0;
                          },
                      },
                      size);
}

}  // namespace Solver
