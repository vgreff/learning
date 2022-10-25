#include "MyPlayWithCpp.hpp"


namespace vgb
{
    MyPlayWithCpp::MyPlayWithCpp(/* args */)
    {
    }
    
    std::ostream& operator<<(std::ostream& out, const MyPlayWithCpp& obj)
    {
         out << "MyPlayWithCpp:{ ";
    
         out << "}";
         return out;
    }
    
} // namespace vgb
