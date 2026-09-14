#ifndef LAYOUT_KINDS_H
#define LAYOUT_KINDS_H

#include <variant>

#include "layout/kinds/free.h"
#include "layout/kinds/flex.h"

namespace Layout {
namespace Kinds {

using Any = std::variant<Layout::Kinds::Free, Layout::Kinds::Flex>;

} // namespace Kinds
} // namespace Layout

#endif // LAYOUT_KINDS_H