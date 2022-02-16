#include <SFML/Graphics.hpp>

namespace shape
{
#define PI 3.141592

  class ShapeFactory
  {
   public:
    ShapeFactory(const sf::VertexArray& points) : points_(points){};
    virtual float area();
    sf::VertexArray points_;
  };

}  // namespace shape
