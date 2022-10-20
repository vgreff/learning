#include "MySample.hpp"


namespace vgb
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
    
} // namespace vgb
