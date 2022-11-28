#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Resolution final
{
  Resolution(const uint width_, const uint height_)
      : width{ width_ }, height{ height_ } { }
  ~Resolution() = default;

  uint width;
  uint height;

  template<typename T = Resolution, typename CastType = uint>
  T get() const {
    return { static_cast<CastType>(width), static_cast<CastType>(height) };
  }

  template<typename T = Resolution, typename CastType = uint>
  T getMiddle() const {
    return { static_cast<CastType>(width / 2), static_cast<CastType>(height / 2) };
  }
};
