#pragma once
#include <memory>
#include <vector>

#include "LevelCreator/LevelCreator.h"
#include "SFML/Graphics.hpp"
#include "shapes/workerShape.h"

struct GstartArguments
{
  std::string levelLoadPath{};
};

class Gstart
{
  public:
  Gstart() = delete;
  Gstart(const Gstart&) = delete;
  Gstart(const Gstart&&) = delete;
  ~Gstart() = default;
  Gstart& operator=(const Gstart&) = delete;

  friend std::unique_ptr<Gstart> std::make_unique<Gstart>(const Resolution&);

  protected:
  explicit Gstart(const Resolution resolution) : resolution_{ resolution } {};

  public:
  static std::unique_ptr<Gstart> makeGstart(const Resolution& resolution) {
    return std::make_unique<Gstart>(resolution);
  }

  static std::unique_ptr<Gstart> makeGstart(const GstartArguments& args) {
    LevelCreator::WindowConfig windowConfig;

    if (!args.levelLoadPath.empty())
    { windowConfig = LevelCreator::LevelLoader::load(args.levelLoadPath); }

    auto game = makeGstart(
        Resolution{ windowConfig.resolution.width, windowConfig.resolution.height });

    game->worldItems_ = { windowConfig.level.getBuildingBlocks().begin(),
                          windowConfig.level.getBuildingBlocks().end() };

    return game;
  }

  void run(std::vector<Worker> workers, std::vector<sf::RectangleShape> worldItems);

  private:
  void mainLoop();
  void eventLoop();

  private:
  Resolution resolution_;
  sf::RenderWindow window_{};
  std::vector<Worker> runningWorkers_;
  std::vector<sf::RectangleShape> worldItems_;
};