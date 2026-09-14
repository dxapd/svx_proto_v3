#ifndef CONTENT_H
#define CONTENT_H

#include <variant>

namespace Content {

struct Geometry {};
struct Model {};
struct Sprite {};
struct TextArea {};
struct SceneWindow {};

using Any = std::variant<std::monostate,
                                   Geometry,
                                   Sprite,
                                   TextArea,
                                   SceneWindow,
                                   Model>;

struct TextSpan {};
using TextItem =
    std::variant<TextSpan, Geometry, Model, Sprite>;

enum class Fit { Fill };

} // namespace Content

#endif // CONTENT_H