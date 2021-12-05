#pragma once

#include <Positron/Core.h>
#include <format>

namespace Positron {
  struct POSITRON_API Point2D {
    float x, y;

    Point2D(float x, float y) : x(x), y(y) {}

    public:
    inline std::string ToString() const GET(F("({},{})", x, y));
  };

  struct POSITRON_API Point3D : Point2D {
    float z;

    Point3D(float x, float y, float z) : Point2D(x, y), z(z) {}

    public:
    inline std::string ToString() const GET(F("({},{},{})", x, y, z));
  };

  using Vector2D = Point2D;
  using Vector3D = Point3D;
}