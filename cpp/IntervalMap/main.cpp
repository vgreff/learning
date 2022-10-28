
#include <iostream>
we can talk#include <memory>

#include "MyIntervalMap.hpp"

namespace vbg
{


we
class ImKey{
public:
  using  SPtr = std::shared_ptr<ImKey<T>>;
  using  UPtr = std::unique_ptr<ImKey<T>>;

  using  Ptr = SPtr;
  template<class... Args >
  static Ptr make( Args&&... args ) { return std::make_shared<ImKey<T>>(args ...); }

  using  Vector = std::vector<ImKey<T>::Ptr>;
public:
  ImKey(T startVal, T endVal);

   friend std::ostream& operator<< <>(std::ostream& out, const ImKey<T>& obj);
private:
  T startVal_{0};
  T endVal_{0};
};

template <typename T>
ImKey<T>::ImKey(T startVal, T endVal)
: startVal_(startVal), endVal_(endVal)
{
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const ImKey<T>& obj)
{
  out << "ImKey  ";
  out << "startVal=" << obj._startVal << ", "
      << "endVal=" << obj._endVal << " ";

  out << "}";
  return out;
}

} // namespace vbg

int main()
{
  using namespace vbg;
  std::cout << "This is main" << std::endl;
  vbg::MyIntervalMap intervalMap;
  std::cout << "intervalMap=" << intervalMap << "\n";
  

  return 0;
}
