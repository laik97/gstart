#include <SFML/Window.hpp>

#include "config/globalConfig.h"
#include "gstart/gstart.h"

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

      if (event.type == sf::Event::Closed)
        window_.close();
    }

    window_.clear();
    window_.display();
  }
}