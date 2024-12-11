/* создание таблицы для авторизации*/
int create_table_auth(PGconn *conn){
    PGresult *res = NULL;
    res = PQexec(conn, "create table if not exists auth(\
                            id                      SERIAL PRIMARY KEY,\
                            login                   VARCHAR(50),\
                            pass                    VARCHAR(250),\
                            role                    VARCHAR(50)\
                            );");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        cout << "Таблица авторизации не создана: " << PQresultErrorMessage(res) << endl;
        PQclear(res);
        return 1;
    }
    PQclear(res);
    return 0;
}

/* создание основной таблицы */
void create_table_opoz(PGconn *conn){
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
        cout << "Таблица опознания не создана: " << PQresultErrorMessage(res) << endl;
        PQclear(res);
    }
    PQclear(res);
}

// создание админа
void create_admin(PGconn *conn){
    // понятно, что нужно использовать хэш от пользовательского ввода пароля... пока тест
    string insert = "insert into auth (login, pass, role) values ('admin', '12345', 'admin');";

    PGresult *res = NULL;
    res = PQexec(conn, insert.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cout << "Ошибка создание администратора: " << PQresultErrorMessage(res) << std::endl;
    }
    PQclear(res);
    printf("Создана роль администратора!\n");
}

// вставка в таблицу
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
        shoes_size,\
        area_loss,\
        date_loss_start,\
        date_loss_end\
        ) values";

    insert += "('" +\
        pm.getSurname()                   + "', '" +\
        pm.getName()                      + "', '" +\
        pm.getMiddleName()                + "', '" +\
        pm.getSex()                       + "', '" +\
        to_string(pm.getBirthYear())      + '-'    + to_string(pm.getBirthMonth()) + '-' + to_string(pm.getBirthDay()) + "', '" +\
        pm.getBirthPlace()                + "', '" +\
        pm.getResidentPlaceLast()         + "', '" +\
        pm.getAppearance()                + "', '" +\
        pm.getTeeth()                     + "', '" +\
        pm.getVoice()                     + "', '" +\
        pm.getBloodGroup()                + "', '" +\
        pm.getClothes()                   + "', '" +\
        pm.getHeaddressSize()             + "', '" +\
        pm.getShoesSize()                 + "', '" +\
        pm.getAreaLoss()                  + "', '" +\
        to_string(pm.getDayLossStart())   + '-'    + to_string(pm.getMonthLossStart()) + '-' + to_string(pm.getYearLossStart()) + "', '" +\
        to_string(pm.getDayLossEnd())     + '-'    + to_string(pm.getMonthLossEnd())   + '-' + to_string(pm.getYearLossEnd()) +\
        "');";

    //printf("%s\n", insert.c_str());

    PGresult *res = NULL;
    res = PQexec(conn, insert.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        std::cout << "Ошибка ввода в базу данных: " << PQresultErrorMessage(res) << std::endl;
    }
    PQclear(res);
}

// поиск в таблице
void select_table(PGconn *conn){
    string surname, name, middle_name; 
    unsigned short int dayb, monthb, yearb;

    cout << "Введите фамилию: ";
    getline(cin, surname);
    cout << "Введите имя: ";
    getline(cin, name);
    cout << "Введите отчество: ";
    getline(cin, middle_name);
    cout << "Введите день рождения: ";
    cin >> dayb;
    cout << "Введите месяц рождения: ";
    cin >> monthb;
    cout << "Введите год рождения: ";
    cin >> yearb;
    fflush(stdin);

    string query = "select * from opoz_pers_mis where surname LIKE ";
    query += "'%" + surname + "%';";
    
    PGresult *res = NULL;
    
    res = PQexec(conn, query.c_str());
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
    } else {
        /*
        cout << "Get " << PQntuples(res) << "tuples, each tuple has " << PQnfields(res) << "fields" << endl;
        // print column name
        for (int i = 0; i < PQnfields(res); i++){
            cout << PQfname(res, i) << "       ";
        }
        cout << endl;
        */
        // print column values
        for (int i = 0; i < PQntuples(res); i++){ // i = 1, т.к пропускаем поле id
            for (int j = 0; j < PQnfields(res); j++){
                cout << PQgetvalue(res, i, j) << "\n";
            }
            cout << endl;
        }
    }
    PQclear(res);
}

// формирует отчет в файл по всем лицам
void generate_report_1(PGconn *conn){
    PGresult *res = NULL;
    res = PQexec(conn, "select * from opoz_pers_mis;");
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        cout << "Ошибка Select: " << PQresultErrorMessage(res) << std::endl;
    } else {
        ofstream out; // поток для записи в файл для формирования отчета
        out.open("отчет_1.csv", ios::app);
        if (out.is_open()){
            for (int i = 0; i < PQntuples(res); i++){
                for (int j = 0; j < PQnfields(res); j++){
                    out << PQgetvalue(res, i, j) << ";";
                }
                out << endl;
                out.close();
                printf("Формирование отчета № 1 завершено!\n");
            }
        }
    }
    PQclear(res);
}

// формирует отчет в файл по всем лицам по промежутку времени пропажи
void generate_report_2(PGconn *conn){
    unsigned short int day_loss_start, month_loss_start, year_loss_start;
    unsigned short int day_loss_end, month_loss_end, year_loss_end;
    cout << "Выберите промежток времени для поиска:\n";

    cout << "Введите день начала пропажи: ";
    cin >> day_loss_start;
    cout << "Введите месяц начала пропажи: ";
    cin >> month_loss_start;
    cout << "Введите год начала пропажи: ";
    cin >> year_loss_start;
    cout << "Введите день конца пропажи: ";
    cin >> day_loss_end;
    cout << "Введите месяц конца пропажи: ";
    cin >> month_loss_end;
    cout << "Введите год конца пропажи: ";
    cin >> year_loss_end;
    fflush(stdin); 

    string date_start = to_string(year_loss_start) + '-' + to_string(month_loss_start) + '-' + to_string(day_loss_start);
    string date_end   = to_string(year_loss_end)   + '-' + to_string(month_loss_end)   + '-' + to_string(day_loss_end);
    string query      = "select * from opoz_pers_mis where date_loss_start >= ";
    query += "'" + date_start + "' AND date_loss_end <= '" + date_end + "';";
    
    PGresult *res = NULL;
    res = PQexec(conn, query.c_str());
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        cout << "Ошибка Select: " << PQresultErrorMessage(res) << std::endl;
    } else {
        ofstream out; // поток для записи в файл для формирования отчета
        out.open("отчет_2.csv", ios::app);
        if (out.is_open()){
            for (int i = 0; i < PQntuples(res); i++){
                for (int j = 0; j < PQnfields(res); j++){
                    out << PQgetvalue(res, i, j) << ";";
                }
                out << endl;
                out.close();
                printf("Формирование отчета № 2 завершено!\n");
            }
        }
    }
    PQclear(res);
}

// формирует отчет в файл по всем лицам, пропавшим в определенном районе
void generate_report_3(PGconn *conn){
    string area;
    cout << "Введите район для формирования отчета: ";
    getline(cin, area);

    string query = "SELECT * FROM opoz_pers_mis WHERE area_loss LIKE ";
    query += "'%" + area + "%';";
    
    PGresult *res = NULL;
    res = PQexec(conn, query.c_str());
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
    } else {
        ofstream out; // поток для записи в файл для формирования отчета
        out.open("отчет_3.csv", ios::app);
        if (out.is_open()){
            for (int i = 0; i < PQntuples(res); i++){
                for (int j = 0; j < PQnfields(res); j++){
                    out << PQgetvalue(res, i, j) << ";";
                }
                out << endl;
                out.close();
                printf("Формирование отчета № 3 завершено!\n");
            }
        }
        PQclear(res);
    }
}