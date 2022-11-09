
#include <iostream>
#include "MyDebugPid.hpp"


int main()
{
  std::cout << "This is main" << std::endl;
  vbg::MyDebugPid debugPid;
  std::cout << "debugPid=" << debugPid << "\n";
  

  return 0;
}
