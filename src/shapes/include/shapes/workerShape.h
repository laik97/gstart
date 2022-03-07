#pragma once
#include "SFML/Graphics.hpp"

struct Directions
{
  int forward : 1;
  int backward : 1;
  int left : 1;
  int right : 1;
};

struct WorkerBaseShape
{
  // backUp
  // |\
  // | \
  // |  \ front
  // |  /
  // | /
  // |/
  // backDown

  sf::Vertex front;
  sf::Vertex backUp;
  sf::Vertex backDown;

  static constexpr std::array<float, 2> fronBasePoint{ 8.0, 2.5 };
  static constexpr std::array<float, 2> backUpBasePoint{ 0.0, 0.0 };
  static constexpr std::array<float, 2> backDownBasePoint{ 0.0, 5.0 };

  std::vector<sf::Vertex*> getAsVector()
  {
    return std::vector<sf::Vertex*>{ &front, &backUp, &backDown };
  }

  sf::VertexArray getAsVertexArray()
  {
    auto array = sf::VertexArray(sf::Triangles, 3);
    array[0] = front;
    array[1] = backUp;
    array[2] = backDown;
    return array;
  }

  static constexpr std::array<std::array<float, 2>, 3> getBasePoints()
  {
    return { fronBasePoint, backUpBasePoint, backDownBasePoint };
  };

  static constexpr std::array<float, 2> getFrontPoint()
  {
    return { 8.0, 2.5 };
  };

  static constexpr std::array<float, 2> getBackUpPoint()
  {
    return { 0.0, 0.0 };
  };

  static constexpr std::array<float, 2> getBackDownPoint()
  {
    return { 0.0, 5.0 };
  };
};

class WorkerShape
{
  public:
  WorkerShape(const sf::Vector2f& startPosition, const double startOrientation);

  void move(const sf::Vector2i& dstPoint);
  void move(const sf::Vector2f& dstPoint);
  void move(const double distance);
  void move(const Directions& dir);

  sf::VertexArray getDrawable();

  private:
  WorkerBaseShape shape_;
  sf::Color color_;
  sf::Vector2f position_{ 0, 0 };
  float orientation_;
  void createShape();
  void setInitialPosition();
  void translate(const sf::Vector2f& moveVector);
  void rotate(const float angle);
};