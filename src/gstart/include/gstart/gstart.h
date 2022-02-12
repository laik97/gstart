#include <math.h>

#include <iostream>

#include "ConsoleLog.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

sf::VertexArray createSimpleShape()
{
  sf::VertexArray lineShape(sf::Lines, 2);
  lineShape[0].position = sf::Vector2f(30, 30);
  lineShape[1].position = sf::Vector2f(60, 30);

  return lineShape;
}

void translateLinearPoint(sf::Vector2f& point)
{
  constexpr float moveFactor = 0.001;
  point.x += moveFactor;
  point.y += moveFactor;
}

float translateCircularPoint(sf::Vector2f& point, float nextStep = 0)
{
  constexpr float radius = 20.0;
  constexpr float angleFactor = (0.000001 / 360.0) * 3.1415;

  float radiusStep = 0.1 + nextStep;

  point.x += radius * std::sin(radiusStep * angleFactor);
  point.y += radius * std::cos(radiusStep * angleFactor);

  return radiusStep;
}

void shapeMove(sf::VertexArray& shape)
{
  // translateLinearPoint(shape[0].position);
  // translateLinearPoint(shape[1].position);

  static float radiusStepMemoryPoint_0 = 0;
  static float radiusStepMemoryPoint_1 = 0;

  // ConsoleLog::print(radiusStepMemoryPoint_0);
  // ConsoleLog::print(radiusStepMemoryPoint_1);

  radiusStepMemoryPoint_0 = translateCircularPoint(shape[0].position, radiusStepMemoryPoint_0);
  radiusStepMemoryPoint_1 = translateCircularPoint(shape[1].position, radiusStepMemoryPoint_1);
}

int runGstart()
{
  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

  auto lineShape = createSimpleShape();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code)
        {
          case sf::Keyboard::Escape: window.close(); break;
          case sf::Keyboard::Left: break;
          default: break;
        }
      }

      if (event.type == sf::Event::Closed)
        window.close();
    }

    shapeMove(lineShape);

    window.clear();
    window.draw(lineShape);
    window.display();
    sf::sleep(sf::seconds(1));
  }

  return 0;
}