#pragma once
#include <fmt/format.h>
#include <jsoncpp/json/json.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "Block.h"
#include "Resolution.h"

namespace LevelCreator {

  struct CreatorArguments
  {
    Resolution resolution{ 800, 600 };
    std::string savePath{ "" };
    std::string loadPath{ "" };
  };

  class LevelSaver;
  class LevelLoader;

  /***********************
  ************************/
  class LevelCreator
  {
    friend class LevelSaver;
    friend class LevelLoader;

    public:
    LevelCreator() = default;

    template<typename T>
    explicit LevelCreator(const T& block)
        : templateBlock_{ std::make_unique<T>(block) } { }

    void addBlock(const sf::Vector2f& position) {
      if (isPositionAvailible(position))
      {
        buildingBlocks_.push_back(templateBlock_->makeBlock());
        buildingBlocks_.back().setPosition(position);
      }
    }

    void removeBlock(const sf::Vector2f& position) {
      buildingBlocks_.erase(
          std::remove_if(buildingBlocks_.begin(),
                         buildingBlocks_.end(),
                         [&position](const sf::RectangleShape& block) {
                           return block.getGlobalBounds().contains(position);
                         }));
    }

    void removeAllBlocks() {
      buildingBlocks_.clear();
    }

    void draw(sf::RenderWindow& window) {
      for (const auto block : buildingBlocks_)
      { window.draw(block); }
    }

    const std::vector<sf::RectangleShape>& getBuildingBlocks() const {
      return buildingBlocks_;
    }

    private:
    bool isPositionAvailible(const sf::Vector2f& /*coor*/) {
      /*
        Should this even be used ?
      */
      return true;
    }

    void fillBuildingBlock(const std::vector<std::pair<int, int>>& positions) {
      for (const auto& [x, y] : positions)
      {
        buildingBlocks_.push_back(templateBlock_->makeBlock());
        buildingBlocks_.back().setPosition(
            sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
      }
    }

    private:
    std::vector<sf::RectangleShape> buildingBlocks_;
    std::shared_ptr<Block> templateBlock_;
  };

  /***********************
   ************************/
  struct WindowConfig
  {
    Resolution resolution{ 800, 600 };
    LevelCreator level;

    explicit operator bool() const noexcept {
      return resolution.width != 0 && resolution.height != 0;
    }
  };

  /***********************
   ************************/
  void mainLoop(const CreatorArguments& arguments);

  /***********************
   ************************/
  class LevelSaver
  {
    public:
    static void save(const WindowConfig& windowConfig, const std::string& savePath) {
      fmt::print("[LevelSaver] Saving level info to : {}\n", savePath);

      Json::Value root;

      root["window_config"]["width"] = windowConfig.resolution.width;
      root["window_config"]["height"] = windowConfig.resolution.height;

      if (const auto concreteBlock = std::dynamic_pointer_cast<SquareBlock>(
              windowConfig.level.templateBlock_))
      { root["block_declaration"] = dumpBlock2Json(*concreteBlock); }

      if (const auto concreteBlock = std::dynamic_pointer_cast<RectangleBlock>(
              windowConfig.level.templateBlock_))
      { root["block_declaration"] = dumpBlock2Json(*concreteBlock); }

      for (const auto& b : windowConfig.level.getBuildingBlocks())
      {
        Json::Value block;
        block["x"] = b.getPosition().x;
        block["y"] = b.getPosition().y;
        root["blocks"].append(block);
      }

      std::ofstream levelInfoFile;

      levelInfoFile.open(savePath);

      levelInfoFile << root;
      levelInfoFile << std::endl;

      levelInfoFile.close();
    }
  };

  class LevelLoader
  {
    public:
    static WindowConfig load(const std::string& loadPath) {
      fmt::print("[LevelLoader] Loading level from : {}\n", loadPath);

      std::ifstream levelInfoFile;

      levelInfoFile.open(loadPath);

      if (levelInfoFile.is_open())
      {
        Json::Value root;
        levelInfoFile >> root;

        auto blockTemplate = loadBlockFromJson(root["block_declaration"]);
        const auto blockType = root["block_declaration"]["type"].asString();

        WindowConfig windowConfig;
        if (blockType == "square_block")
        {
          windowConfig = WindowConfig{
            Resolution{ root["window_config"]["width"].asUInt(),
                        root["window_config"]["height"].asUInt() },
            LevelCreator{ specializeBlock<SquareBlock>(blockTemplate) }
          };
        }

        fmt::print("Loaded window : width={} height={}",
                   windowConfig.resolution.width,
                   windowConfig.resolution.height);

        std::vector<std::pair<int, int>> positions;
        for (const auto& node : root["blocks"])
        { positions.push_back({ node["x"].asInt(), node["y"].asInt() }); }

        windowConfig.level.fillBuildingBlock(positions);

        return windowConfig;
      }

      return {};
    }
  };

}  // namespace LevelCreator
