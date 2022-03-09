#include <SFML/Graphics.hpp>

#define PI 3.14159265359

enum class Unit
{
  radians,
  degrees,
};

enum class Origin
{
  global,
  local,
};

class Transformation
{
  public:
  template<Unit from, Unit to, typename type>
  static void transform(type*);

  template<Origin from, Origin to, typename type>
  static type transform(type*, float*);
};

template<>
void Transformation::transform<Unit::radians, Unit::degrees>(float* angle)
{
  *angle = (*angle / PI) * 180;
}

template<>
void Transformation::transform<Unit::degrees, Unit::radians>(float* angle)
{
  *angle = (*angle / 180.0) * PI;
}
