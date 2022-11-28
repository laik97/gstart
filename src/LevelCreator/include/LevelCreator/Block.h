#pragma once
#include <jsoncpp/json/json.h>

#include <SFML/Graphics.hpp>
#include <type_traits>

namespace LevelCreator {

  /***********************
   ************************/
  struct Block
  {
    Block(const sf::Vector2f& origin) : origin_{ origin } { }
    Block(const Block&) = default;
    virtual ~Block() = default;

    sf::Vector2f origin_;
    virtual sf::RectangleShape makeBlock() const = 0;
  };

  /***********************
  ************************/
  struct RectangleBlock : Block
  {
    float width_;
    float height_;

    sf::RectangleShape makeBlock() const override {
      return makeBlock(width_, height_, origin_);
    }

    static sf::RectangleShape makeBlock(const float width,
                                        const float height,
                                        const sf::Vector2f& origin) {
      auto rectangle = sf::RectangleShape{ sf::Vector2f(width, height) };
      rectangle.setOrigin(origin);
      rectangle.setFillColor(sf::Color::White);
      return rectangle;
    }
  };

  /***********************
   ************************/
  struct SquareBlock : public Block
  {
    SquareBlock(float size, sf::Vector2f origin) : Block{ origin }, size_{ size } { }

    float size_;

    sf::RectangleShape makeBlock() const override {
      auto square = sf::RectangleShape{ sf::Vector2f(size_, size_) };
      square.setOrigin(origin_);
      square.setFillColor(sf::Color::White);
      return square;
    }

    static sf::RectangleShape makeBlock(const float size,
                                        const sf::Vector2f& origin) {
      const SquareBlock b{ size, origin };
      return b.makeBlock();
    }
  };

  /***********************
  ************************/
  template<typename BlockType>
  inline Json::Value dumpBlock2Json(const BlockType& block) {
    Json::Value blockDeclBranch;

    blockDeclBranch["origin"]["x"] = block.origin_.x;
    blockDeclBranch["origin"]["y"] = block.origin_.y;

    if constexpr (std::is_same_v<BlockType, SquareBlock>)
    {
      blockDeclBranch["type"] = "square_block";
      blockDeclBranch["size"] = block.size_;
    }

    if constexpr (std::is_same_v<BlockType, RectangleBlock>)
    {
      blockDeclBranch["type"] = "rectangle_block";
      blockDeclBranch["width"] = block.width_;
      blockDeclBranch["height"] = block.height_;
    }

    return blockDeclBranch;
  }

  inline std::shared_ptr<Block> loadBlockFromJson(
      const Json::Value& blockDeclBranch) {
    if (blockDeclBranch["type"].asString() == "square_block")
    {
      return std::make_shared<SquareBlock>(
          SquareBlock{ blockDeclBranch["size"].asFloat(),
                       sf::Vector2f{ blockDeclBranch["origin"]["x"].asFloat(),
                                     blockDeclBranch["origin"]["y"].asFloat() } });
    }

    return nullptr;
  }

  /***********************
  ************************/
  template<typename T>
  T specializeBlock(std::shared_ptr<Block> block) {
    if (auto spec = std::dynamic_pointer_cast<T>(block))
    { return *spec; }
    else
    { throw("convert2spec impossible convertion"); }
  }

}  // namespace LevelCreator