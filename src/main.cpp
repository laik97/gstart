#include <string>

#include "gstart/gstart.h"

int main()
{
  Gstart* game = Gstart::getInstance(Resolution<>{ 800, 600 });
  game->run();
}