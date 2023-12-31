#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>


namespace vbg
{
    class MyIntervalMap
    {
    public:
      using  SPtr = std::shared_ptr<MyIntervalMap>;
      using  UPtr = std::unique_ptr<MyIntervalMap>;
    
      using  Ptr = SPtr;
      template<class... Args >
      static Ptr make( Args&&... args ) { return std::make_shared<MyIntervalMap>(args ...); }
    
      using  Vector = std::vector<MyIntervalMap::Ptr>;
    public:
      MyIntervalMap(/* args */);
    
       friend std::ostream& operator<<(std::ostream& out, const MyIntervalMap& obj);
    private:
      int64_t _val{0};
    };
    

} // end namespace vbg

