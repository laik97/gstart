#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

template<typename InternalType = uint>
struct Resolution
{
  InternalType width_;
  InternalType height_;

  template<typename T = Resolution, typename CastType = InternalType>
  const auto resolutionVec()
  {
    return { static_cast<CastType>(width_), static_cast<CastType>(height_) };
  }

  template<typename T = Resolution, typename CastType = InternalType>
  const auto resolutionMiddle()
  {
    return { static_cast<CastType>(width_ / 2), static_cast<CastType>(height_ / 2) };
  }
};

class WindowConfig
{
  public:
  WindowConfig() : resolution_(Resolution<>{ 800, 600 }), initialized_(false){};
  WindowConfig(const Resolution<>& resolution)
      : resolution_(resolution), initialized_(true){};

  bool setResolution(const Resolution<>& resolution)
  {
    if (initialized_ == false)
    {
      resolution_ = resolution;
      initialized_ = true;
      return true;
    }

    return false;
  }

  Resolution<>& getResolution()
  {
    return resolution_;
  }

  private:
  Resolution<> resolution_{};
  bool initialized_{ false };
};