#pragma once

#include <vector>

struct Resolution
{
  uint32_t width;
  uint32_t height;

  std::array<uint32_t, 2> resolutionVec()
  {
    return std::array<uint32_t, 2>{ width, height };
  }
};

class WindowConfig
{
  public:
  WindowConfig() : resolution_(Resolution{ 800, 600 }), initialized_(false){};
  WindowConfig(const Resolution& resolution)
      : resolution_(resolution), initialized_(true){};

  bool setResolution(const Resolution& resolution)
  {
    if (initialized_ == false)
    {
      resolution_ = resolution;
      initialized_ = true;
      return true;
    }

    return false;
  }

  const Resolution& getResolution()
  {
    return resolution_;
  }

  private:
  Resolution resolution_{};
  bool initialized_{ false };
};