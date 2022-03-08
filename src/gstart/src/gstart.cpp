#include <SFML/Window.hpp>
#include <vector>

#include "config/globalConfig.h"
#include "gstart/ConsoleLog.h"
#include "gstart/gstart.h"
#include "shapes/workerShape.h"

Gstart* Gstart::getInstance(const Resolution<>& resolution)
{
  static Gstart instance{ resolution };
  return &instance;
}

void Gstart::run()
{
  mainLoop();
}

void Gstart::mainLoop()
{
  WorkerShape worker(
      globalConfig_.getResolution().resolutionMiddle<sf::Vector2f, float>(), 0.0f);

  while (window_.isOpen())
  {
    sf::Event event;
    while (window_.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
      {
        Directions directions;

        switch (event.key.code)
        {
          case sf::Keyboard::Escape: window_.close(); break;
          case sf::Keyboard::Left:; break;
          default: break;
        }
      }

      if (event.type == sf::Event::Closed)
        window_.close();
    }

    window_.display();
    window_.clear();
    window_.setFramerateLimit(120);
  }
}