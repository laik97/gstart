#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

template<typename InternalType = uint>
struct Resolution
{
  InternalType width_;
  InternalType height_;

  template<typename T = Resolution>
  auto resolutionVec()
  {
    if constexpr (std::is_same<T, std::vector<InternalType>>::value)
      return std::vector<InternalType>{ width_, height_ };
    else if constexpr (std::is_same<T, std::array<InternalType, 2>>::value)
      return std::array<InternalType, 2>{ width_, height_ };
    else if constexpr (std::is_same<T, sf::Vector2f>::value)
      return sf::Vector2f{ static_cast<float>(height_), static_cast<float>(width_) };
    else
      return Resolution{ width_, height_ };
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

  const Resolution<>& getResolution()
  {
    return resolution_;
  }

  Resolution<> getWindowMiddlePoint()
  {
    return Resolution<>{ resolution_.width_ / 2, resolution_.height_ / 2 };
  }

  private:
  Resolution<> resolution_{};
  bool initialized_{ false };
};