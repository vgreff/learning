
#include <iostream>
#include "MyPlayWithCpp.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
 
void tokenize(const std::string &s, const char delim,
            std::vector<std::string> &out)
{
    std::string::size_type beg = 0;
    for (auto end = 0; (end = s.find(delim, end)) != std::string::npos; ++end)
    {
        out.push_back(s.substr(beg, end - beg));
        beg = end + 1;
    }
 
    out.push_back(s.substr(beg));
}

int main()
{
   const char delim = ' ';

   std::vector<std::string> out1;
   std::fstream newfile;
   newfile.open("../../data.txt",std::ios::in); //open a file to perform read operation using file object
   if (newfile.is_open())
   {   //checking whether the file is open
      std::string tp;
      while(getline(newfile, tp))
      {
         tokenize(tp, delim, out1);
         std::cout << tp << std::endl;
      }
      newfile.close();   //close the file object.
   }
   for (auto &&s : out1)
   {
      std::cout << "s=" << s << "\n";
      
   }
   
}


int main1()
{
  std::cout << "This is main" << std::endl;
  vgb::MyPlayWithCpp playWithCpp;
  std::cout << "playWithCpp=" << playWithCpp << "\n";
  

  return 0;
}
