
#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <unordered_set>
#include <unordered_map>

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

  inline friend bool operator==(const ImKey<T>& lhs, const ImKey<T>& rhs)
  {
      // compares startVal_ to rhs.startVal_,
      // then endVal_.endVal_     // then d to rhs.d
      return std::tie(lhs.startVal_, lhs.endVal_) == std::tie(rhs.startVal_, rhs.endVal_);
  }

   std::size_t hash() const
    {
        std::size_t h1 = std::hash<T>{}(startVal_);
        std::size_t h2 = std::hash<T>{}(endVal_);
        return h1 ^ (h2 << 8); // or use boost::hash_combine
    }

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

  void add(const Key& keyStart, const Key& keyEnd, const T& val)
  {
    ImKey<Key> myKey(keyStart, keyEnd);
    directHit_.insert_or_assign(myKey, val);
  }

  friend std::ostream& operator<< <>(std::ostream& out, const IntervalMap<Key, T>& obj);
private:
  T notFoundVal_;
  std::unordered_map<ImKey<Key>, T > directHit_;
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

template <typename T>
struct std::hash<vbg::ImKey<T>>
{
    std::size_t operator()(const vbg::ImKey<T>& s) const noexcept
    {
      return s.hash();
    }
};

template <typename T>
struct std::equal_to<vbg::ImKey<T>>
{
    std::size_t operator()(const vbg::ImKey<T>& lhs, const vbg::ImKey<T>& rhs) const noexcept
    {
      return lhs == rhs;
    }
};


int main()
{
  using namespace vbg;

  std::cout << "This is main" << std::endl;
  vbg::MyIntervalMap intervalMap;
  std::cout << "MyIntervalMap=" << intervalMap << "\n";

  ImKey<int> key(10,20);
  std::cout << "key=" << key << "\n";
  

  IntervalMap<int64_t, char> im('A');
  im.add(5,10,'B');

  std::cout << "intervalMap=" << im << "\n";

  return 0;
}
