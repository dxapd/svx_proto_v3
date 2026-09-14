#include "solver/units.h"

#include <stdexcept>

#include "util/overloads.h"

namespace Solver {

int ResolvePos(const Layout::LayoutPos& pos,
               int parentExtent) {
    return std::visit(
        Util::Overloads{[&](Layout::Pixels px) { return px.value; },
                        [&](Layout::Percent pc) {
                            return (int)(parentExtent * pc.value / 100.0f);
                        }},
        pos);
}

int ResolveSize(const Layout::LayoutSize& size,
                int parentExtent) {
    return std::visit(Util::Overloads{
                          [&](Layout::Pixels px) { return px.value; },
                          [&](Layout::Percent pc) {
                              return (int)(parentExtent * pc.value / 100.0f);
                          },
                          [&](Layout::Auto a) {
                              throw std::runtime_error("Unimplemented");
                              return 0;
                          },
                      },
                      size);
}

}  // namespace Solver
