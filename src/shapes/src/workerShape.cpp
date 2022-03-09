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
  Eigen::Translation<float, 2> translationVec(0.001, 0.0);
  Eigen::Rotation2D currentOrientation(orientation_);
  const auto directedTranslationVec =
      translationVec * currentOrientation.toRotationMatrix();

  for (auto& base : shape_.getAsVector())
  {
    Eigen::Vector2f point(base->position.x, base->position.y);
    const auto newPos = directedTranslationVec * point;
    base->position.x = newPos(0);
    base->position.y = newPos(1);
  }
}

void WorkerShape::rotate(const float orientation)
{
  orientation_ += orientation;
  Transformation::transform<Transformations::degrees, Transformations::radians>(
      &orientation);
  Eigen::Rotation2D rotation(orientation);
  for (auto& base : shape_.getAsVector())
  {
    Eigen::Vector2f point(base->position.x, base->position.y);
    const auto newPoint = rotation.toRotationMatrix() * point;
    base->position.x = newPoint(0);
    base->position.y = newPoint(1);
  }
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
  if (dir.left)
    rotate(1.0f);
  if (dir.right)
    rotate(-1.0f);
  // translate
  if (dir.forward)
    move(sf::Vector2f(1.0, 0.0));
  if (dir.backward)
    move(sf::Vector2f(-1.0, 0.0));
}

sf::VertexArray WorkerShape::getDrawable()
{
  return shape_.getAsVector();
}
