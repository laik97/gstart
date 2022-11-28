#pragma once

#include "SFML/Graphics.hpp"
#include "workerTail.h"

class Worker;

enum class Direction
{
  forward,
  backward,
  left,
  right,
  stop
};

struct WorkerBaseShape
{
  WorkerBaseShape() = default;
  WorkerBaseShape(const float width, const float length)
      : width_{ width }, length_{ length } { }

  WorkerBaseShape(const float scale)
      : width_{ 5.0f * scale }, length_{ 8.0f * scale } { }

  ~WorkerBaseShape() = default;

  /*
  origin length
        |
        |
        |
      backUp
        | \
        |   \
        |     \
        |       \
        |       / front ----- origin width
        |     /
        |   /
        | /
      backDown
  */

  sf::Vector2f getFrontBasePoint() {
    return { length_, 0.0 };
  };

  sf::Vector2f getBackUpBasePoint() {
    return { 0.0f, -width_ / 2.0f };
  };

  sf::Vector2f getBackDownBasePoint() {
    return { 0.0f, width_ / 2.0f };
  };

  sf::Vector2f getOrigin() {
    return { 0.0f, 0.0f };
  }

  private:
  float width_{ 5.0f };
  float length_{ 8.0f };
};

class WorkerShape
{
  friend class Worker;

  public:
  WorkerShape() = default;
  WorkerShape(const sf::Vector2f& startPosition, const double startOrientation);

  protected:
  void draw(sf::RenderWindow& window);
  void move(const Direction dir);

  const sf::Vector2f& getCurrentPosition() const {
    return shape_.getPosition();
  }

  float getCurrentOrientation() const {
    return shape_.getRotation();
  }

  private:
  sf::Vector2f getShapePointGlobalPosition(const size_t pointIndex);
  sf::Vector2f transformPointFromLocalToGlobal(sf::Vector2f&& point);

  sf::ConvexShape shape_;
  sf::Vector2f speedVector_{ 1.0, 0.0 };
  sf::Color color_{ 255, 191, 41 };
  WorkerTail tail;

  void setInitialPosition(const sf::Vector2f& position, const double orientation);
  void createShape();

  // shape movement
  void moveLeft();
  void moveRight();
  void moveForward();
  void moveBackward();
  void stop();
};

struct Worker
{
  Worker() = default;
  Worker(const WorkerShape& worker) : worker_{ worker } { }
  ~Worker() = default;

  WorkerShape worker_;

  void draw(sf::RenderWindow& window) {
    worker_.draw(window);
  }

  void move(const Direction dir) {
    worker_.move(dir);
  }
};
