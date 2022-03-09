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

  static Gstart* getInstance(const Resolution<uint>& resolution);

  void run();

  private:
  ~Gstart(){};
  Gstart(const Resolution<uint> resolution)
      : globalConfig_(resolution),
        window_(sf::VideoMode(resolution.width_, resolution.height_), "GSTART"){};

  void mainLoop();

  GlobalConfig globalConfig_{};
  sf::RenderWindow window_{};
};