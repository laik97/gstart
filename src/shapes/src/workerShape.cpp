#include <eigen3/Eigen/Geometry>

#include "math.h"
#include "shapes/transformations.h"
#include "shapes/workerShape.h"

WorkerShape::WorkerShape(const sf::Vector2f& startPosition,
                         const double startOrientation)
    : color_(255, 191, 41), position_(startPosition), orientation_(startOrientation)
{
  createShape();
  setInitialPosition();
}

void WorkerShape::createShape()
{
  const sf::Vector2f frontCorner(8.0, 2.5);
  const sf::Vector2f backUpCorner(0.0, 0.0);
  const sf::Vector2f backDownCorner(0.0, 5.0);

  shape_.front.position = frontCorner;
  shape_.backUp.position = backUpCorner;
  shape_.backDown.position = backDownCorner;

  shape_.front.color = color_;
  shape_.backUp.color = color_;
  shape_.backDown.color = color_;
}

void WorkerShape::setInitialPosition()
{
  translate(position_);
}

void WorkerShape::translate(const sf::Vector2f& moveVector)
{
  for (const auto& point : shape_.getAsVector())
  {
    point->position.x = point->position.x + moveVector.x;
    point->position.y = point->position.y + moveVector.y;
  }
}

void WorkerShape::rotate(const float orientation)
{
  Transformation::transform<Transformations::degrees, Transformations::radians>(
      &orientation);
  Eigen::Rotation2D rotation(orientation);
}

void WorkerShape::move(const double distance)
{
}

void WorkerShape::move(const sf::Vector2i& dstPoint)
{
  sf::Vector2f moveVec(dstPoint.x - position_.x, dstPoint.y - position_.y);
  position_ = sf::Vector2f(dstPoint.x, dstPoint.y);
  translate(moveVec);
}

void WorkerShape::move(const sf::Vector2f& dstPoint)
{
  sf::Vector2f moveVec(dstPoint.x - position_.x, dstPoint.y - position_.y);
  position_ = dstPoint;
  translate(moveVec);
}

void WorkerShape::move(const Directions& dir)
{
  // rotate

  // translate
}

sf::VertexArray WorkerShape::getDrawable()
{
  return shape_.getAsVertexArray();
}
