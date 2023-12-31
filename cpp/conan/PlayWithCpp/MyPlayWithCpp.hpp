#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>


namespace vgb
{
    class MyPlayWithCpp
    {
    public:
      using  SPtr = std::shared_ptr<MyPlayWithCpp>;
      using  UPtr = std::unique_ptr<MyPlayWithCpp>;
    
      using  Ptr = SPtr;
      template<class... Args >
      static Ptr make( Args&&... args ) { return std::make_shared<MyPlayWithCpp>(args ...); }
    
      using  Vector = std::vector<MyPlayWithCpp::Ptr>;
    public:
      MyPlayWithCpp(/* args */);
    
       friend std::ostream& operator<<(std::ostream& out, const MyPlayWithCpp& obj);
    private:
      int64_t _val{0};
    };
    

} // end namespace vgb

