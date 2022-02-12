#include <iostream>

class ConsoleLog
{
 public:
  template<typename T>
  static void print(const T& arg)
  {
    std::cout << arg << "\n";
  };
};
