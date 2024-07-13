
find_package(Poco  REQUIRED COMPONENTS DataSQLite DataMySQL)

find_package(unofficial-libmariadb CONFIG REQUIRED)


add_executable(poco_sqlite_demo poco_sqlite_demo.cpp)
target_link_libraries(poco_sqlite_demo PRIVATE Poco::DataSQLite )

add_executable(poco_mysql_demo poco_mysql_demo.cpp)
target_link_libraries(poco_mysql_demo PRIVATE Poco::DataMySQL )

add_executable(maria_c_conn_demo maria_c_conn_demo.cpp)
target_link_libraries(maria_c_conn_demo PRIVATE unofficial::libmariadb )

# add_executable(db_cpp_demo db_cpp_demo.cpp)
# target_link_libraries(db_cpp_demo PRIVATE myunofficial::mysql-connector-cpp::connectorsqlcppconn)
