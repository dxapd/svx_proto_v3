#ifndef CONTENT_ANY_H
#define CONTENT_ANY_H

#include <vector>
#include <variant>
#include <string>

#include "content/content.h"
#include "content/text.h"

namespace Content {

using Any = std::variant<std::monostate,
                                   Geometry,
                                   Sprite,
                                   TextArea,
                                   SceneWindow,
                                   Model>;

} // namespace Content

#endif // CONTENT_ANY_H