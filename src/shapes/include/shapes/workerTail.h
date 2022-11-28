#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <random>

#include "SFML/Graphics.hpp"

namespace {
  template<typename T>
  auto randomGenerateNumberInRange(int low, int high) {
    static std::random_device randDev;
    static std::mt19937 generator(randDev());
    std::uniform_int_distribution<> distr(low, high);
    return static_cast<T>(distr(generator));
  }
}  // namespace

class WorkerTail
{
  public:
  WorkerTail() = default;
  virtual ~WorkerTail() = default;

  virtual void operator()(const sf::Vector2f& position) {
    if (segments_.size())
    {
      if (segments_.back().getGlobalBounds().contains(position))
      { return; }
    }

    constexpr auto tailSize = 12;
    constexpr auto tailLength = 12;

    segments_.emplace_back(sf::RectangleShape{ sf::Vector2f{ tailSize, tailSize } });
    segments_.back().setOrigin({ tailSize / 2.0, tailSize / 2.0 });
    segments_.back().setPosition(position);
    segments_.back().setFillColor(sf::Color(255, 255, 255, 100));

    if (segments_.size() > tailLength)
      segments_.pop_front();

    std::for_each(
        segments_.begin(), segments_.end(), [&](sf::RectangleShape& segment) {
          const auto tmpSize = segment.getSize();
          segment.setSize({ tmpSize.x - (tailSize / tailLength),
                            tmpSize.y - (tailSize / tailLength) });
          segment.setOrigin({ (tmpSize.x - (tailSize / tailLength)) / 2.0f,
                              (tmpSize.y - (tailSize / tailLength)) / 2.0f });
          segment.setRotation(randomGenerateNumberInRange<float>(5, 85));
        });
  }

  virtual void draw(sf::RenderWindow& window) {
    for (const auto& segment : segments_)
    { window.draw(segment); }
  }

  private:
  std::deque<sf::RectangleShape> segments_;
};