#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mysql.h>

int main(int argc, char *argv[])
{

    // Initialize Connection
    MYSQL *conn;
    if (!(conn = mysql_init(0)))
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        exit(1);
    }

    // Connect to the database
    if (!mysql_real_connect(
            conn,         // Connection
            "localhost4", // Host
            "user1",      // User account
            "password1",  // User password
            "nation",     // Default database
            3306,         // Port number
            NULL,         // Path to socket file
            0             // Additional options
            ))
    {
        // Report the failed-connection error & close the handle
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // Use the Connection
    MYSQL_STMT *stmt;
    const char *query;

    stmt = mysql_stmt_init(conn);

    if (stmt)
    {
        puts("Statement init OK!");
    }
    else
    {
        printf("Statement init failed: %s\n", mysql_error(conn));
    }

    if (stmt)
    {
        query = "SELECT VERSION(), USER()";

        if (mysql_stmt_prepare(stmt, query, strlen(query)))
        {
            printf("Statement prepare failed: %s\n", mysql_stmt_error(stmt));
        }
        else
        {
            puts("Statement prepare OK!");
        }

        if (mysql_stmt_execute(stmt))
        {
            printf("Statement execute failed: %s\n", mysql_stmt_error(stmt));
        }
        else
        {
            puts("Statement execute OK!");
        }

        mysql_stmt_free_result(stmt);
        mysql_stmt_close(stmt);
    }

    {
        if (mysql_query(conn, "SELECT User, Password FROM mysql.user"))
        {
            printf("Query failed: %s\n", mysql_error(conn));
        }
        else
        {
            MYSQL_RES *result = mysql_store_result(conn);

            if (!result)
            {
                printf("Couldn't get results set: %s\n", mysql_error(conn));
            }
            else
            {
                MYSQL_ROW row;
                int i;
                unsigned int num_fields = mysql_num_fields(result);

                while ((row = mysql_fetch_row(result)))
                {
                    for (i = 0; i < num_fields; i++)
                    {
                        printf("%s, ", row[i]);
                    }
                    putchar('\n');
                }

                mysql_free_result(result);
            }
        }
    }

    // Close the Connection
    mysql_close(conn);

    return 0;
}
