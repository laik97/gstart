#include <SFML/Window.hpp>
#include <vector>

#include "gstart/gstart.h"
#include "shapes/workerShape.h"

void Gstart::run(std::vector<Worker> workers,
                 std::vector<sf::RectangleShape> worldItems) {
  worldItems_ = std::move(worldItems);
  runningWorkers_ = std::move(workers);
  mainLoop();
}

void Gstart::mainLoop() {
  window_.create(sf::VideoMode(resolution_.width, resolution_.height), "GSTART");
  window_.setFramerateLimit(160);

  while (window_.isOpen())
  {
    eventLoop();

    for (auto& worker : runningWorkers_)
    { worker.draw(window_); }

    for (auto& worldItem : worldItems_)
    { window_.draw(worldItem); }

    window_.display();
    window_.clear();
  }

  window_.close();
}

void Gstart::eventLoop() {
  Direction faceDirection = Direction::stop;
  Direction sideDirection = Direction::stop;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  { faceDirection = Direction::forward; }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  { faceDirection = Direction::backward; }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  { sideDirection = Direction::left; }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  { sideDirection = Direction::right; }

  for (auto& worker : runningWorkers_)
  {
    worker.move(faceDirection);
    worker.move(sideDirection);
  }

  sf::Event event;
  while (window_.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window_.close();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    window_.close();
}
