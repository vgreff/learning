#include <iostream>
#include <sqlite3.h>


int main()
{
  sqlite3 *db;
  int rc = sqlite3_open("test.db", &db);
  int vg = rc + 10;

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
