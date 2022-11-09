#include "MyDebugPid.hpp"


namespace vbg
{
    MyDebugPid::MyDebugPid(/* args */)
    {
    }
    
    std::ostream& operator<<(std::ostream& out, const MyDebugPid& obj)
    {
         out << "MyDebugPid:{ ";
    
         out << "}";
         return out;
    }
    
} // namespace vbg
