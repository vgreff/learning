#include <iostream>

#include <module1/mod1c1.hpp>

// namespace module1
// {
   int mod1c1::foo(int i)
   {
      std::cout << "mod1c1" << i << "\n";
      return i + 3;
   }
// };
