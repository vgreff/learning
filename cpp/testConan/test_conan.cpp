#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <tuple>
#include <memory>

  std::string _symbol;
  double      _price{0.0};
  int32_t     _quantity{0};


class VgClass
{
private:
public:
  std::string _symbol;
  double      _price{0.0};
  int32_t     _quantity{0};
public:
  using  SPtr = std::shared_ptr<VgClass>;
  using  UPtr = std::unique_ptr<VgClass>;

  using  Ptr = SPtr;
  template<class... Args >
  static Ptr make( Args&&... args ) { return std::make_shared<VgClass>(args ...); }
public:
  VgClass(const std::string symbol, double p) : _symbol(symbol), _price(p) {}
  VgClass();
   friend std::ostream& operator<<(std::ostream& out, const VgClass& obj);
};

VgClass::VgClass()
{
}
std::ostream& operator<<(std::ostream& out, const VgClass& obj)
{
    out 
    << "symbol=" << '"' << obj._symbol << '"' << ", "
    << "price=" << obj._price << ", "
    << "quantity=" << obj._quantity << "\n"
    
    << std::endl;
  
    return out;
}

struct C
{
  // constructors needed (until C++20)
  C(int i) : i(i) {}
  C(int i, float f) : i(i), f(f) {}
  int i;
  float f{};

  inline friend bool operator<(const C &lhs, const C &rhs)
  {
    // compares i to rhs.i,
    // then f to rhs.f,
    return std::tie(lhs.i, lhs.f) < std::tie(rhs.i, rhs.f);
  }
  inline friend bool operator==(const C &lhs, const C &rhs)
  {
    // compares i to rhs.i,
    // then f to rhs.f,
    return std::tie(lhs.i, lhs.f) == std::tie(rhs.i, rhs.f);
  }
  inline friend bool operator>(const C &lhs, const C &rhs) { return rhs < lhs; }
  inline friend bool operator<=(const C &lhs, const C &rhs) { return !(lhs > rhs); }
  inline friend bool operator>=(const C &lhs, const C &rhs) { return !(lhs < rhs); }
  inline friend bool operator!=(const C &lhs, const C &rhs) { return !(lhs == rhs); }
};

int main()
{
  auto vg1 = VgClass::make("abc", 123.45);
  auto vg2 = std::make_shared<VgClass>("abc", 123.45);
  std::cout  << "vg1=" << *vg1 << ""
  << std::endl;
  
  
  sqlite3 *db;
  int rc = sqlite3_open("test.db", &db);
  int vg = rc + 10;
  std::vector<int> vect{1, 2, 3, 4, 5, 6, 10};

  if (SQLITE_OK == rc)
  {
    std::cout << "Opened SQLite database successfully! VG1\n";
    sqlite3_close(db);
  }
  else
  {
    std::cout << "Can't open the SQLite database: " << sqlite3_errmsg(db) << "\n";
  }

  return 0;
}
