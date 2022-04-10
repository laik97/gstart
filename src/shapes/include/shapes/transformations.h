#pragma once

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

  template<Unit from, Unit to, typename type>
  static type transform(type&&);
};

template<>
inline void Transformation::transform<Unit::radians, Unit::degrees>(float* angle)
{
  *angle = (*angle / PI) * 180;
}

template<>
inline float Transformation::transform<Unit::radians, Unit::degrees>(float&& angle)
{
  return (angle / PI) * 180;
}

template<>
inline void Transformation::transform<Unit::degrees, Unit::radians>(float* angle)
{
  *angle = (*angle / 180.0) * PI;
}

template<>
inline float Transformation::transform<Unit::degrees, Unit::radians>(float&& angle)
{
  return (angle / 180.0) * PI;
}
