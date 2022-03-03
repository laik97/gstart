#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

template<typename InternalType = int>
struct Resolution
{
  InternalType width;
  InternalType height;

  // template<typename T>
  // void resolutionVec();

  template<>
  std::vector<InternalType> resolutionVec<std::vector<InternalType>>()
  {
    return std::vector{ width, height };
  }

  template<>
  std::array<InternalType, 2> resolutionVec<std::array<InternalType, 2>>()
  {
    return std::array<InternalType, 2>{ width, height };
  }

  template<>
  sf::Vector2f resolutionVec<sf::Vector2f>()
  {
    return sf::Vector2f{ width, height };
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
    return Resolution<>{ resolution_.width / 2, resolution_.height / 2 };
  }

  private:
  Resolution<> resolution_{};
  bool initialized_{ false };
};