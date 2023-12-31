
#include <iostream>
#include "MyDebugPid.hpp"


int main()
{
  std::cout << "This is main" << std::endl;
  vbg::MyDebugPid debugPid;
  std::cout << "debugPid=" << debugPid << "\n";
  int64_t counter(0);
  while (1)
  {
    if (counter % 1000000000 == 0)
    {
      std::cout << "counter=" << counter << "\n";
    }
    ++counter;
  }
  

  return 0;
}
