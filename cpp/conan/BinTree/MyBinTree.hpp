#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>


namespace vbg
{
    class MyBinTree
    {
    public:
      using  SPtr = std::shared_ptr<MyBinTree>;
      using  UPtr = std::unique_ptr<MyBinTree>;
    
      using  Ptr = SPtr;
      template<class... Args >
      static Ptr make( Args&&... args ) { return std::make_shared<MyBinTree>(args ...); }
    
      using  Vector = std::vector<MyBinTree::Ptr>;
    public:
      MyBinTree(/* args */);
    
       friend std::ostream& operator<<(std::ostream& out, const MyBinTree& obj);
    private:
      int64_t _val{0};
    };
    

} // end namespace vbg

