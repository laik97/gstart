#include "SFML/Graphics.hpp"
#include "shapeFactory.h"

namespace shape
{
  class LineShape : public ShapeFactory
  {
   public:
    LineShape(const sf::VertexArray& points) : ShapeFactory(points){};

    float area();
    float length();
    sf::Vector2f center();

    void linearTranslate(const sf::Vector2f& translVec);
    void rotate(const float radiusAngle);

    float xAxisAngle();
    float yAxisAngle();
  };

}  // namespace shape