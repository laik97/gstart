#include "shapeFactory.h"

class WorkerShape : public ShapeFactory
{
  WorkerShape(sf::Vector2f startPosition, double startOrientation)
      : ShapeFactory(sf::VertexArray(sf::Triangles, 3)),
        color_(130, 222, 255){};

 private:
  sf::Color color_{};
  sf::Vector2f position_{};
  double orientation{ 0 };
};