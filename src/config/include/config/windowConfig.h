#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

template<typename InternalType = uint>
struct Resolution
{
  InternalType width_;
  InternalType height_;

  template<typename T = Resolution, typename CastType = InternalType>
  T get() const
  {
    return { static_cast<CastType>(width_), static_cast<CastType>(height_) };
  }

  template<typename T = Resolution, typename CastType = InternalType>
  T getMiddle() const
  {
    return { static_cast<CastType>(width_ / 2), static_cast<CastType>(height_ / 2) };
  }
};

class WindowConfig
{
  public:
  WindowConfig() : resolution_(Resolution<uint>{ 800, 600 }){};

  explicit WindowConfig(const Resolution<uint>& resolution)
      : resolution_(resolution){};

  const Resolution<uint>& resolution() const
  {
    return resolution_;
  }

  private:
  Resolution<uint> resolution_{};
};