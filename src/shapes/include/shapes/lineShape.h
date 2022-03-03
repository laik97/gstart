#include "SFML/Graphics.hpp"
#include "shapeFactory.h"

class LineShape : public ShapeFactory
{
  public:
  LineShape(const sf::VertexArray& points);

  float area();
  float length();
  sf::Vector2f center();

  void linearTranslate(const sf::Vector2f& translVec);
  void rotate(const float radiusAngle);

  float xAxisAngle();
  float yAxisAngle();
};
