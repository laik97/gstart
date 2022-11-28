#pragma once

#include "SFML/Graphics.hpp"

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

  template<Origin from, Origin to, typename type>
  static type transform(type&&, type&&);
};

template<>
inline void Transformation::transform<Unit::radians, Unit::degrees>(float* angle) {
  *angle = (*angle / PI) * 180;
}

template<>
inline float Transformation::transform<Unit::radians, Unit::degrees>(float&& angle) {
  return (angle / PI) * 180;
}

template<>
inline void Transformation::transform<Unit::degrees, Unit::radians>(float* angle) {
  *angle = (*angle / 180.0) * PI;
}

template<>
inline float Transformation::transform<Unit::degrees, Unit::radians>(float&& angle) {
  return (angle / 180.0) * PI;
}

template<>
inline sf::Vector2f Transformation::transform<Origin::local, Origin::global>(
    sf::Vector2f&& local,
    sf::Vector2f&& ref) {
  return { local.x + ref.x, local.y + ref.y };
}