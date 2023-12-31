#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>


namespace vbg
{
    class MyDebugPid
    {
    public:
      using  SPtr = std::shared_ptr<MyDebugPid>;
      using  UPtr = std::unique_ptr<MyDebugPid>;
    
      using  Ptr = SPtr;
      template<class... Args >
      static Ptr make( Args&&... args ) { return std::make_shared<MyDebugPid>(args ...); }
    
      using  Vector = std::vector<MyDebugPid::Ptr>;
    public:
      MyDebugPid(/* args */);
    
       friend std::ostream& operator<<(std::ostream& out, const MyDebugPid& obj);
    private:
      int64_t _val{0};
    };
    

} // end namespace vbg

