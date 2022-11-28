#include <cstdlib>

#include "LevelCreator/LevelCreator.h"

namespace LevelCreator {
  /***********************
   ************************/
  void levelCreatorBlockEvents(const sf::RenderWindow& window,
                               LevelCreator& levelCreator) {
    static bool wasButtonPressed = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) &&
        (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasButtonPressed))
    {
      /*
        c + LFT Button = remove single block
      */
      const auto& pos = sf::Mouse::getPosition(window);
      levelCreator.removeBlock(
          sf::Vector2f(static_cast<float>(pos.x), static_cast<float>(pos.y)));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) &&
             sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      /*
        c + a = remove all blocks
      */
      levelCreator.removeAllBlocks();
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasButtonPressed)
    {
      /*
        LFT Button = add new block
      */
      const auto& pos = sf::Mouse::getPosition(window);
      levelCreator.addBlock(
          sf::Vector2f(static_cast<float>(pos.x), static_cast<float>(pos.y)));
    }

    wasButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
  }

  /***********************
   ************************/
  void printInfo() {
    fmt::print("Key bindings :\n\tSave level : a + s\n\tRemove all blocks : c + a");
    fmt::print("\nMouse : \n\tAdd block : LMB\n\tRemove block : c + LMB\n\n");
  }

  /***********************
   ************************/
  void mainLoop(const CreatorArguments& arguments) {
    printInfo();

    WindowConfig windowConfig;

    if (!arguments.loadPath.empty())
    {
      fmt::print("[LevelCreator] Level load path is empty\n");
      if (auto w_conf_ = LevelLoader::load(arguments.loadPath))
      { windowConfig = std::move(w_conf_); }
    }
    else
    {
      const auto blockTempl = SquareBlock{ 50, { 0.0, 0.0 } };
      windowConfig.level = LevelCreator{ blockTempl };
    }

    sf::RenderWindow window{ sf::VideoMode{ windowConfig.resolution.width,
                                            windowConfig.resolution.height },
                             "LevelCreator" };

    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(30);

    if (arguments.savePath.empty())
    { std::cerr << "No save path provided : projectMainPath is null !\n"; }

    while (window.isOpen())
    {
      levelCreatorBlockEvents(window, windowConfig.level);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
          sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      { LevelSaver::save(windowConfig, arguments.savePath); }

      windowConfig.level.draw(window);

      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::KeyPressed)
        {
          if (event.key.code == sf::Keyboard::Escape)
            window.close();
        }

        if (event.type == sf::Event::Closed)
          window.close();
      }

      window.display();
      window.clear();
    }
  }

}  // namespace LevelCreator