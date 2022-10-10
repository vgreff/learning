#include <iostream>
#include <sqlite3.h>
#include <vector>

int main() 
{
  sqlite3 *db;
  int rc = sqlite3_open("test.db", &db);
  int vg= rc+10;
  std::vector<int> vect{1,2,3,4,5,6,10};

  if (SQLITE_OK == rc) 
  {
    std::cout << "Opened SQLite database successfully! VG1\n";
    sqlite3_close(db);
  } else 
  {
    std::cout << "Can't open the SQLite database: " << sqlite3_errmsg(db) << "\n";
  }
  return 0;
}

