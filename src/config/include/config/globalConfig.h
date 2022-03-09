#pragma once

#include "windowConfig.h"

class GlobalConfig
{
  public:
  GlobalConfig(){};
  GlobalConfig(const Resolution<uint>& resolution) : window_(resolution){};

  WindowConfig window_;
};
