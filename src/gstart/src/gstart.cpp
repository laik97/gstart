#include <SFML/Window.hpp>
#include <vector>

#include "config/globalConfig.h"
#include "gstart/ConsoleLog.h"
#include "gstart/gstart.h"
#include "shapes/workerShape.h"

Gstart* Gstart::getInstance(const Resolution& resolution)
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
  auto res = globalConfig_.getResolution();
  std::vector<WorkerShape> workers;
  const auto a = res.resolutionVec<sf::Vector2f>();
  workers.reserve(20);
  for (int i = 0; i < 20; i++)
  {
    workers.emplace_back(WorkerShape{
        globalConfig_.getWindowMiddlePoint().resolutionVec<sf::Vector2f>(), 0 });
  }

  while (window_.isOpen())
  {
    sf::Event event;
    while (window_.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code)
        {
          case sf::Keyboard::Escape: window_.close(); break;
          case sf::Keyboard::Left: break;
          default: break;
        }
      }

      if (event.type == sf::Event::MouseMoved)
      {
        for (auto& worker : workers)
        {
          worker.move(sf::Mouse::getPosition(window_));
        }
      }

      if (event.type == sf::Event::Closed)
        window_.close();
    }

    for (auto& worker : workers)
    {
      window_.draw(worker.getDrawable());
    }
    window_.display();
    window_.clear();
    window_.setFramerateLimit(120);
  }
}