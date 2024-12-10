/* создание таблицы */
void create_table(PGconn *conn){
    PGresult *res = NULL;
    res = PQexec(conn, "create table if not exists opoz_pers_mis(\
                            id                      SERIAL PRIMARY KEY,\
                            surname                 VARCHAR(50),\
                            name                    VARCHAR(50),\
                            middle_name             VARCHAR(50),\
                            sex                     VARCHAR(2));");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cout << "Create table failed: " << PQresultErrorMessage(res) << std::endl;
        PQclear(res);
    }
    PQclear(res);
}


/* вставка в таблицу */
void insert_table(PGconn *conn, PersonMissing &pm){

    string insert = "insert into opoz_pers_mis (surname, name, middle_name, sex) values";

    insert += "('" +\
        pm.getSurname()           + "', '" +\
        pm.getName()              + "', '" +\
        pm.getMiddleName()        + "', '" +\
        pm.getSex()               +\
        "');";

    printf("%s\n", insert.c_str());

    PGresult *res = NULL;
    res = PQexec(conn, insert.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cout << "Insert into table failed: " << PQresultErrorMessage(res) << std::endl;
    }
    PQclear(res);
}

