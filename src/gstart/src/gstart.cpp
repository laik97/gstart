#include <SFML/Window.hpp>
#include <vector>

#include "config/globalConfig.h"
#include "gstart/ConsoleLog.h"
#include "gstart/gstart.h"
#include "shapes/workerShape.h"

Gstart* Gstart::getInstance(const Resolution<uint>& resolution)
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
  const auto window = globalConfig_.window_;
  const auto resolution = window.resolution();
  runningWorkers_.push_back(
      { WorkerShape{ resolution.getMiddle<sf::Vector2f, float>(), 0.0 },
        Directions() });

  while (window_.isOpen())
  {
    eventLoop();

    for (auto& worker : runningWorkers_)
    {
      worker.move();
      worker.draw(window_);
    }

    window_.display();
    window_.clear();
    window_.setFramerateLimit(120);
  }
}

inline void Gstart::eventLoop()
{
  sf::Event event;
  Directions directions;

  while (window_.pollEvent(event))
  {
    for (auto& worker : runningWorkers_)
    {
      if (event.type == sf::Event::KeyPressed)
      {
        worker.setDirections(event.key.code);
      }

      if (event.type == sf::Event::KeyReleased)
      {
        worker.resetDirections(event.key.code);
      }
    }

    if (event.type == sf::Event::KeyPressed)
    {
      if (event.key.code == sf::Keyboard::Escape)
        window_.close();
    }

    if (event.type == sf::Event::Closed)
      window_.close();
  }
}
