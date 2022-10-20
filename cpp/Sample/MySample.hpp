#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>


namespace vgb
{
    class MySample
    {
    public:
      using  SPtr = std::shared_ptr<MySample>;
      using  UPtr = std::unique_ptr<MySample>;
    
      using  Ptr = SPtr;
      template<class... Args >
      static Ptr make( Args&&... args ) { return std::make_shared<MySample>(args ...); }
    
      using  Vector = std::vector<MySample::Ptr>;
    public:
      MySample(/* args */);
    
       friend std::ostream& operator<<(std::ostream& out, const MySample& obj);
    private:
      int64_t _val{0};
    };
    

} // end namespace vgb

