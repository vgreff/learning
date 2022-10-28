
#include <iostream>
#include <memory>

#include "MyIntervalMap.hpp"

namespace vbg
{



template <typename T>
class ImKey
{
public:
  using  SPtr = std::shared_ptr<ImKey<T>>;
  using  UPtr = std::unique_ptr<ImKey<T>>;

  using  Ptr = SPtr;
  template<class... Args >
  static Ptr make( Args&&... args ) { return std::make_shared<ImKey<T>>(args ...); }

  using  Vector = std::vector<ImKey<T>::Ptr>;
public:
  ImKey(T startVal, T endVal);

   friend std::ostream& operator<< <T>(std::ostream& out, const ImKey<T>& obj);
private:
  T startVal_{0};
  T endVal_{0};
};

template <typename T>
ImKey<T>::ImKey(T startVal, T endVal)
: startVal_(startVal), endVal_(endVal)
{
}



template <typename Key, typename T>
class IntervalMap
{
public:
  using  SPtr = std::shared_ptr<IntervalMap<Key, T>>;
  using  UPtr = std::unique_ptr<IntervalMap<Key, T>>;

  using  Ptr = SPtr;
  template<class... Args >
  static Ptr make( Args&&... args ) { return std::make_shared<IntervalMap<Key, T>>(args ...); }

  using  Vector = std::vector<IntervalMap<Key, T>::Ptr>;
public:
  IntervalMap(T notFoundVal);

   friend std::ostream& operator<< <Key, T>(std::ostream& out, const IntervalMap<Key, T>& obj);
private:
  T notFoundVal_;
};

template <typename Key, typename T>
IntervalMap<Key, T>::IntervalMap(T notFoundVal)
: notFoundVal_(notFoundVal)
{
}

template <typename Key, typename T>
std::ostream& operator<<(std::ostream& out, const IntervalMap<Key, T>& obj)
{
     out << "IntervalMap<Key, T>:{ ";

     out << "}";
     return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const ImKey<T>& obj)
{
  out << "ImKey:{ ";
  out << "startVal=" << obj.startVal_ << ", "
      << "endVal=" << obj.endVal_ << " ";

  out << "}";
  return out;
}
} // namespace vbg

int main()
{
  using namespace vbg;

  std::cout << "This is main" << std::endl;
  vbg::MyIntervalMap intervalMap;
  std::cout << "MyIntervalMap=" << intervalMap << "\n";

  ImKey<int> key(10,20);
  std::cout << "key=" << key << "\n";
  

  IntervalMap<int, char> im('A');
  std::cout << "intervalMap=" << im << "\n";

  return 0;
}
