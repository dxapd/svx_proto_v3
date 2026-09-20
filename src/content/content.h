#ifndef CONTENT_H
#define CONTENT_H

#include <variant>
#include <string>

namespace Content {

struct Geometry {};
struct Model {};
struct Sprite {};
struct SceneWindow {};

enum class Fit { Fill };

} // namespace Content

#endif // CONTENT_H