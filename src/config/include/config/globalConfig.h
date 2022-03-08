#pragma once

#include "SFML/Graphics.hpp"
#include "windowConfig.h"

class GlobalConfig : public WindowConfig
{
  public:
  GlobalConfig(){};
  GlobalConfig(const Resolution<>& resolution) : WindowConfig(resolution){};
};
