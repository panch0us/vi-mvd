/* создание таблицы */
void create_table(PGconn *conn){
    PGresult *res = NULL;
    res = PQexec(conn, "create table if not exists opoz_pers_mis(\
                            id                      SERIAL PRIMARY KEY,\
                            surname                 VARCHAR(50),\
                            name                    VARCHAR(50),\
                            middle_name             VARCHAR(50),\
                            sex                     VARCHAR(2),\
                            birth_date              DATE,\
                            birth_place             VARCHAR(50),\
                            residence_place_last    VARCHAR(250),\
                            appearance              VARCHAR(250),\
                            teeth                   VARCHAR(100),\
                            voice                   VARCHAR(100),\
                            blood_group             VARCHAR(30),\
                            clothes                 VARCHAR(500),\
                            headdress_size          VARCHAR(15),\
                            shoes_size              VARCHAR(15),\
                            area_loss               VARCHAR(30),\
                            date_loss_start         DATE,\
                            date_loss_end           DATE\
                            );");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cout << "Create table failed: " << PQresultErrorMessage(res) << std::endl;
        PQclear(res);
    }
    PQclear(res);
}


/* вставка в таблицу */
void insert_table(PGconn *conn, PersonMissing &pm){

    string insert = "insert into opoz_pers_mis (\
        surname,\
        name,\
        middle_name,\
        sex,\
        birth_date,\
        birth_place,\
        residence_place_last,\
        appearance,\
        teeth,\
        voice,\
        blood_group,\
        clothes,\
        headdress_size,\
        shoes_size\
        ) values";

    printf("GETYEAR: %d\n", pm.getBirthYear());
    insert += "('" +\
        pm.getSurname()               + "', '" +\
        pm.getName()                  + "', '" +\
        pm.getMiddleName()            + "', '" +\
        pm.getSex()                   + "', '" +\
        to_string(pm.getBirthYear())  + '-' + to_string(pm.getBirthMonth()) + '-' + to_string(pm.getBirthDay()) + "', '" +\
        pm.getBirthPlace()            + "', '" +\
        pm.getResidentPlaceLast()     + "', '" +\
        pm.getAppearance()            + "', '" +\
        pm.getTeeth()                 + "', '" +\
        pm.getVoice()                 + "', '" +\
        pm.getBloodGroup()            + "', '" +\
        pm.getClothes()               + "', '" +\
        pm.getHeaddressSize()         + "', '" +\
        pm.getShoesSize()             +\
        "');";

    printf("%s\n", insert.c_str());

    PGresult *res = NULL;
    res = PQexec(conn, insert.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cout << "Insert into table failed: " << PQresultErrorMessage(res) << std::endl;
    }
    PQclear(res);
}