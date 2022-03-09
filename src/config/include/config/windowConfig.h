#pragma once

#include <vector>

template<typename InternalType = uint>
struct Resolution
{
  InternalType width_;
  InternalType height_;

  template<typename T = Resolution, typename CastType = InternalType>
  auto get() const
  {
    return { static_cast<CastType>(width_), static_cast<CastType>(height_) };
  }

  template<typename T = Resolution, typename CastType = InternalType>
  auto getMiddle() const
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
  Resolution<> resolution_{};
};