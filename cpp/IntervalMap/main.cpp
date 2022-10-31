
#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include "MyIntervalMap.hpp"

namespace vbg
{



template <typename T, typename DATA>
class ImData
{
public:
  using  SPtr = std::shared_ptr<ImData<T, DATA>>;
  using  UPtr = std::unique_ptr<ImData<T, DATA>>;

  using  Ptr = SPtr;
  template<class... Args >
  static Ptr make( Args&&... args ) { return std::make_shared<ImData<T, DATA>>(args ...); }

  using  Vector = std::vector<ImData<T, DATA>::Ptr>;
public:
  ImData(T startVal, T endVal, DATA data);

  inline friend bool operator==(const ImData<T, DATA>& lhs, const ImData<T, DATA>& rhs)
  {
      // compares startVal_ to rhs.startVal_,
      // then endVal_.endVal_     // then d to rhs.d
      return std::tie(lhs.startVal_, lhs.endVal_) == std::tie(rhs.startVal_, rhs.endVal_);
  }
  inline bool equalStart(const ImData<T, DATA>& rhs) const
  {
      return startVal_ == rhs.startVal_;
  }

  inline bool isInBetween(const T& val) const
  {
      return (val >= startVal_) && val <= endVal_;
  }

  std::size_t hash() const
  {
      std::size_t h1 = std::hash<T>{}(startVal_);
      std::size_t h2 = std::hash<T>{}(endVal_);
      return h1 ^ (h2 << 8); // or use boost::hash_combine
  }
  std::size_t hashStart() const
  {
      std::size_t h1 = std::hash<T>{}(startVal_);
      return h1;
  }

   friend std::ostream& operator<< <>(std::ostream& out, const ImData<T, DATA>& obj);
private:
  T startVal_;
  T endVal_;
  DATA data_;
};
template <typename T, typename DATA>
ImData<T, DATA>::ImData(T startVal, T endVal, DATA data)
: startVal_(startVal), endVal_(endVal), data_(data)
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
    ImData<Key, T> myKey(keyStart, keyEnd, val);
    fakeTotest_.insert_or_assign(myKey, val);
    directHit_.insert_or_assign(keyStart, val);
  }

  friend std::ostream& operator<< <>(std::ostream& out, const IntervalMap<Key, T>& obj);
private:
  T notFoundVal_;
  std::unordered_map<Key, T > directHit_;
  std::unordered_map<ImData<Key, T>, T > fakeTotest_;
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
template <typename T, typename DATA>
std::ostream& operator<<(std::ostream& out, const ImData<T, DATA>& obj)
{
  out << "ImData:{ ";
  out << "startVal=" << obj.startVal_ << ", "
      << "endVal=" << obj.endVal_ << " ";
  out << "}";
  return out;
}
} // namespace vbg
template <typename T, typename DATA>
struct std::hash<vbg::ImData<T, DATA>>
{
    std::size_t operator()(const vbg::ImData<T, DATA>& s) const noexcept
    {
      return s.hashStart();
    }
};
template <typename T, typename DATA>
struct std::equal_to<vbg::ImData<T, DATA>>
{
    std::size_t operator()(const vbg::ImData<T, DATA>& lhs, const vbg::ImData<T, DATA>& rhs) const noexcept
    {
      return lhs.equalStart(rhs);
    }
};


int main()
{
  using namespace vbg;

  std::cout << "This is main" << std::endl;
  vbg::MyIntervalMap intervalMap;
  std::cout << "MyIntervalMap=" << intervalMap << "\n";

  ImData<int, char> key(10,20, 'D');
  std::cout << "key=" << key << "\n";
  

  IntervalMap<int64_t, char> im('A');
  im.add(5,10,'B');

  std::cout << "intervalMap=" << im << "\n";

  return 0;
}
