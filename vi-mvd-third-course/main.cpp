/*
g++ -Wall -g main.cpp -o main -I "C:\Program Files\PostgreSQL\16\include" -L "C:\Program Files\PostgreSQL\16\lib" -lpq
*/

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main(int argc, char **argv)
{
    const char my_con[] = "host=localhost dbname=postgres user=postgres password=12345678"; // тестовый вариант
    PGconn *conn = PQconnectdb(my_con);
    printf("HELLO!!!1\n");
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    PQfinish(conn);
    printf("HELLO!!!0\n");
    return 0;
}