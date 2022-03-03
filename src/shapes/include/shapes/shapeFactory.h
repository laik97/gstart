#pragma once
#include <SFML/Graphics.hpp>

#define PI 3.141592

class ShapeFactory
{
  public:
  ShapeFactory(const sf::VertexArray& points) : points_(points){};
  virtual ~ShapeFactory(){};
  virtual float area();

  public:
  sf::VertexArray points_{};
};
