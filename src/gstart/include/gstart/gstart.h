#include "SFML/Graphics.hpp"
#include "config/globalConfig.h"
#include "config/windowConfig.h"

class Gstart
{
  public:
  Gstart() = delete;
  Gstart(const Gstart&) = delete;
  Gstart(const Gstart&&) = delete;
  Gstart& operator=(const Gstart&) = delete;

  static Gstart* getInstance(const Resolution& resolution);

  void run();

  private:
  ~Gstart(){};
  Gstart(const Resolution resolution)
      : globalConfig_(resolution),
        window_(sf::VideoMode(resolution.width, resolution.height), "GSTART"){};

  void mainLoop();

  GlobalConfig globalConfig_{};
  sf::RenderWindow window_{};
};