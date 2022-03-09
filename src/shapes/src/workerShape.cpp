
#include "shapes/transformations.h"
#include "shapes/workerShape.h"

WorkerShape::WorkerShape(const sf::Vector2f& startPosition,
                         const double startOrientation)
{
  createShape();
  setInitialPosition(startPosition, startOrientation);
}

void WorkerShape::createShape()
{
  shape_.setPointCount(3);
  shape_.setRotation(0);
  shape_.setPoint(0, WorkerBaseShape::getFrontBasePoint());
  shape_.setPoint(1, WorkerBaseShape::getBackUpBasePoint());
  shape_.setPoint(2, WorkerBaseShape::getBackDownBasePoint());
  shape_.setOrigin(WorkerBaseShape::getOrigin());
  shape_.setFillColor(color_);
  shape_.setOutlineColor(color_);
  shape_.setOutlineThickness(2);
}

void WorkerShape::setInitialPosition(const sf::Vector2f& position,
                                     const double orientation)
{
  shape_.setPosition(position);
  shape_.setRotation(orientation);
}

void WorkerShape::move(const Directions& dir)
{
  moveLeft(dir);
  moveRight(dir);
  moveForeward(dir);
  // currently, backward movement is not needed
}

void WorkerShape::moveLeft(const Directions& dir)
{
  if (dir.left_)
    shape_.rotate(-2.0);
}

void WorkerShape::moveRight(const Directions& dir)
{
  if (dir.right_)
    shape_.rotate(2.0);
}

void WorkerShape::moveForeward(const Directions& dir)
{
  sf::Vector2f moveVec(1.0, 0.0);
  sf::Transform transform;
  transform.rotate(shape_.getRotation());
  const auto m = transform.transformPoint(moveVec);

  if (dir.forward_)
    shape_.move(m);
  else
    shape_.move(sf::Vector2f(0.0, 0.0));
}

void WorkerShape::moveBackward(const Directions& dir)
{
  sf::Vector2f moveVec(-1.0, 0.0);
  sf::Transform transform;
  transform.rotate(shape_.getRotation());
  const auto m = transform.transformPoint(moveVec);

  if (dir.backward_)
    shape_.move(m);
  else
    shape_.move(sf::Vector2f(0.0, 0.0));
}

void WorkerShape::draw(sf::RenderWindow& window)
{
  window.draw(shape_);
}
