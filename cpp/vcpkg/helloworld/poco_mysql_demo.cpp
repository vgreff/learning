#include <Poco/Data/Session.h>
#include <Poco/Data/MySQL/Connector.h>
#include <vector>
#include <iostream>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

struct Person
{
    std::string name;
    std::string address;
    int         age;
};

int main(int argc, char** argv)
{
    // register MySQL connector
    Poco::Data::MySQL::Connector::registerConnector();

    // create a session
    Session session("mysql", "host=127.0.0.1;port=3306;db=nation;user=user1;password=password1");

    // drop sample table, if it exists
    session << "DROP TABLE IF EXISTS Person", now;

    // (re)create table
    session << "CREATE TABLE Person (Name VARCHAR(30) primary key, Address VARCHAR(50), Age INTEGER(3))", now;

    // insert some rows
    Person person =
    {
        "Bart Simpson",
        "Springfield",
        12
    };

    Statement insert(session);
    insert << "INSERT INTO Person VALUES(?, ?, ?)",
        use(person.name),
        use(person.address),
        use(person.age);

    insert.execute();

    person.name    = "Lisa Simpson";
    person.address = "Springfield";
    person.age     = 10;

    insert.execute();

    // a simple query
    Statement select(session);
    select << "SELECT Name, Address, Age FROM Person",
        into(person.name),
        into(person.address),
        into(person.age),
        range(0, 1); //  iterate over result set one row at a time

    while (!select.done())
    {
        select.execute();
        std::cout << person.name << " " << person.address << " " << person.age << std::endl;
    }

    return 0;
}