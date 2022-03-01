#include "shapes/lineShape.h"

#include "math.h"

float LineShape::area()
{
  return 0;
}

float LineShape::length()
{
  return std::sqrt(
      std::pow(this->points_[0].position.x - this->points_[1].position.x, 2) +
      std::pow(this->points_[0].position.y - this->points_[1].position.y, 2));
}

sf::Vector2f LineShape::center()
{
  return sf::Vector2f(
      this->points_[0].position.x + this->points_[1].position.x, this->points_[0].position.y + this->points_[1].position.y);
}

void LineShape::linearTranslate(const sf::Vector2f& translVec)
{
  this->points_[0].position += translVec;
  this->points_[1].position += translVec;
}

float LineShape::xAxisAngle()
{
  float xDiff = this->points_[0].position.x - this->points_[1].position.x;
  float yDiff = this->points_[0].position.y - this->points_[1].position.y;
  return static_cast<float>(std::atan2(yDiff, xDiff));
}

float LineShape::yAxisAngle()
{
  float xDiff = this->points_[0].position.x - this->points_[1].position.x;
  float yDiff = this->points_[0].position.y - this->points_[1].position.y;
  return static_cast<float>(std::atan2(xDiff, yDiff));
}
