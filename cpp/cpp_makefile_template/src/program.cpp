#include <module1/mod1c1.hpp>
#include <module1/mod1c2.hpp>
#include <module2/mod2c1.hpp>
#include <module2/mod2c2.hpp>
#include <program.hpp>

#include<vector>

int main(int argc, char const *argv[])
{
   if (argc > 1)
   {
      for (int i = 0; i < argc; i++)
      {
         printf("argv[%d]=%s %d\n",i,argv[i], argc);
      }
      
   }
   else
   {
      printf("argv[0]=%s %d\n",argv[0], argc);
   }


   std::vector<int> v;
   v.push_back(12);
   v.push_back(120);
   v.push_back(102);

   mod1c1 m1c1;
   mod1c2 m1c2;
   mod2c1 m2c1;
   mod2c2 m2c2;

   m1c1.foo(5);
   m1c2.foo();
   m2c1.foo();
   m2c2.foo();

   program::foo();

   return 0;
}
