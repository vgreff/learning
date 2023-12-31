#include "MySample.hpp"


namespace vbg
{
    MySample::MySample(/* args */)
    {
    }
    
    std::ostream& operator<<(std::ostream& out, const MySample& obj)
    {
         out << "MySample:{ ";
    
         out << "}";
         return out;
    }
    
} // namespace vbg
