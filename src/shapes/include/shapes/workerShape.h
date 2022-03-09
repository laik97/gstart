#pragma once

#include "SFML/Graphics.hpp"

struct Directions
{
  bool forward_ = false;
  bool backward_ = false;
  bool left_ = false;
  bool right_ = false;

  void left(bool arg = true)
  {
    left_ = arg;
  }
  void right(bool arg = true)
  {
    right_ = arg;
  }
  void forward(bool arg = true)
  {
    forward_ = arg;
  }
  void backward(bool arg = true)
  {
    backward_ = arg;
  }

  void clear()
  {
    forward_ = false;
    backward_ = false;
    left_ = false;
    right_ = false;
  }
};

struct WorkerBaseShape
{
  /*
  // backUp
  // | \
  // |   \
  // |     \
  // |       \
  // |       / front
  // |     /
  // |   /
  // | /
  // backDown
  */

  static constexpr std::array<float, 2> frontBasePoint{ 8.0, 2.5 };
  static constexpr std::array<float, 2> backUpBasePoint{ 0.0, 0.0 };
  static constexpr std::array<float, 2> backDownBasePoint{ 0.0, 5.0 };

  static sf::Vector2f getFrontBasePoint()
  {
    return { 8.0, 2.5 };
  };

  static sf::Vector2f getBackUpBasePoint()
  {
    return { 0.0, 0.0 };
  };

  static sf::Vector2f getBackDownBasePoint()
  {
    return { 0.0, 5.0 };
  };

  static sf::Vector2f getOrigin()
  {
    return { 4.0, 2.5 };
  }
};

class WorkerShape
{
  public:
  WorkerShape(const sf::Vector2f& startPosition, const double startOrientation);

  void draw(sf::RenderWindow& window);

  void move(const Directions& dir);

  private:
  sf::ConvexShape shape_{};
  sf::Vector2f speedVector_{ 1.0, 0.0 };
  const sf::Color color_{ 255, 191, 41 };
  void setInitialPosition(const sf::Vector2f& position, const double orientation);
  void createShape();
  void moveLeft(const Directions& dir);
  void moveRight(const Directions& dir);
  void moveForeward(const Directions& dir);
  void moveBackward(const Directions& dir);
};

struct Worker
{
  WorkerShape worker;
  Directions directions;

  void draw(sf::RenderWindow& window)
  {
    worker.draw(window);
  }

  void move()
  {
    worker.move(directions);
  }

  void setDirections(sf::Keyboard::Key code)
  {
    switch (code)
    {
      case sf::Keyboard::Left: directions.left(); break;
      case sf::Keyboard::Right: directions.right(); break;
      case sf::Keyboard::Up: directions.forward(); break;
      case sf::Keyboard::Down: directions.backward(); break;
      default: break;
    }
  }

  void resetDirections(sf::Keyboard::Key code)
  {
    switch (code)
    {
      case sf::Keyboard::Left: directions.left(false); break;
      case sf::Keyboard::Right: directions.right(false); break;
      case sf::Keyboard::Up: directions.forward(false); break;
      case sf::Keyboard::Down: directions.backward(false); break;
      default: break;
    }
  }
};