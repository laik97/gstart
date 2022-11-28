
#include "shapes/transformations.h"
#include "shapes/workerShape.h"

WorkerShape::WorkerShape(const sf::Vector2f& startPosition,
                         const double startOrientation) {
  createShape();
  setInitialPosition(startPosition, startOrientation);
}

void WorkerShape::createShape() {
  WorkerBaseShape shape{ 2.5 };

  shape_.setPointCount(3);
  shape_.setRotation(0);
  shape_.setPoint(0, shape.getBackUpBasePoint());
  shape_.setPoint(1, shape.getFrontBasePoint());
  shape_.setPoint(2, shape.getBackDownBasePoint());
  shape_.setOrigin(shape.getOrigin());
  shape_.setFillColor(color_);
  shape_.setOutlineColor(color_);
  shape_.setOutlineThickness(2);
}

void WorkerShape::setInitialPosition(const sf::Vector2f& position,
                                     const double orientation) {
  shape_.setPosition(position);
  shape_.setRotation(orientation);
}

void WorkerShape::move(const Direction dir) {
  const auto tailBasePoint = transformPointFromLocalToGlobal({ 0.0, 0.0 });
  tail(tailBasePoint);

  switch (dir)
  {
    case Direction::forward: moveForward(); break;
    case Direction::left: moveLeft(); break;
    case Direction::right: moveRight(); break;
    // currently, backward movement is not needed
    // case Direction::backward: moveBackward(); break;
    case Direction::stop: stop(); break;
    default: stop();
  }
}

void WorkerShape::moveLeft() {
  shape_.rotate(-2.0);
}

void WorkerShape::moveRight() {
  shape_.rotate(2.0);
}

void WorkerShape::moveForward() {
  sf::Vector2f moveVec(1.0, 0.0);
  sf::Transform transform;
  transform.rotate(shape_.getRotation());
  const auto m = transform.transformPoint(moveVec);

  shape_.move(m);
}

void WorkerShape::moveBackward() {
  sf::Vector2f moveVec(-1.0, 0.0);
  sf::Transform transform;
  transform.rotate(shape_.getRotation());
  const auto m = transform.transformPoint(moveVec);

  shape_.move(m);
}

void WorkerShape::stop() {
  shape_.move(sf::Vector2f(0.0, 0.0));
}

void WorkerShape::draw(sf::RenderWindow& window) {
  // tail must be rendered first so it does does not occlude shape
  tail.draw(window);
  window.draw(shape_);
}

sf::Vector2f WorkerShape::transformPointFromLocalToGlobal(sf::Vector2f&& point) {
  sf::Transform transform;
  transform.rotate(shape_.getRotation());
  const auto transformed = transform.transformPoint(point);
  const auto position = shape_.getPosition();
  return position - transformed;
}