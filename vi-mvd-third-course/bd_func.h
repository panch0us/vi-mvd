// проверка, создана ли таблица
int check_exist_tables(PGconn *conn, string &name_table){
    int exist = 0; // если 0 - то таблица не существует
    string query = "SELECT COUNT(table_name) FROM information_schema.tables WHERE table_schema LIKE 'public' AND table_type LIKE 'BASE TABLE' AND table_name = ";
    query += "'" + name_table + "';";
    
    PGresult *res = NULL;
    res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        std::cout << "Ошибка выборки админа: " << PQresultErrorMessage(res) << std::endl;
        return 2;
    }

    for (int i = 0; i < PQntuples(res); i++){
            for (int j = 0; j < PQnfields(res); j++){
                exist = atoi(PQgetvalue(res, i, j));
            }
        }
    
    PQclear(res);
    return exist;
}

/* создание таблицы для авторизации*/
int create_table_auth(PGconn *conn){
    PGresult *res = NULL;
    res = PQexec(conn, "create table if not exists auth(\
                            id                      SERIAL PRIMARY KEY,\
                            login                   VARCHAR(50) UNIQUE NOT NULL,\
                            pass                    VARCHAR(250) NOT NULL,\
                            role                    VARCHAR(50) NOT NULL\
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
int create_table_opoz(PGconn *conn){
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
                            date_loss_start         DATE NOT NULL,\
                            date_loss_end           DATE NOT NULL\
                            );");
    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        cout << "Таблица опознания не создана: " << PQresultErrorMessage(res) << endl;
        PQclear(res);
        return 1;
    }
    PQclear(res);
    return 0;
}

int dont_exist_admin(PGconn *conn){
    int exist_admin; // если 1 - то существует, если 0 - нет, другое число - ошибка.

    string query = "select login from auth where login = 'admin'";
    PGresult *res = NULL;
    res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        std::cout << "Ошибка выборки админа: " << PQresultErrorMessage(res) << std::endl;
        return 2;
    }
    
    exist_admin = PQntuples(res);
    PQclear(res);
    return exist_admin;
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

// авторизация
int auth_adm(PGconn *conn){
    string login, pass;
    int auth_adm_ok = 0;

    fflush(stdin);
    cout << "Введите логин: ";
    getline(cin, login);
    cout << "Введите пароль: ";
    getline(cin, pass);

    string query = "select login, pass from auth where login = ";
    query += "'" + login + "' AND pass = '" + pass + "';";

    PGresult *res = NULL;
    
    res = PQexec(conn, query.c_str());
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
        std::cout << "Ошибка авторизации " << PQresultErrorMessage(res) << std::endl;
    else
        auth_adm_ok = PQntuples(res);
    PQclear(res);

    return auth_adm_ok;
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

    cout << "Введите фамилию: ";
    getline(cin, surname);
    cout << "Введите имя: ";
    getline(cin, name);
    cout << "Введите отчество: ";
    getline(cin, middle_name);

    string query = "select * from opoz_pers_mis where surname LIKE ";
    query += "'%" + surname + "%' AND name LIKE '%" + name + "%' AND middle_name LIKE '%" + middle_name + "%'";
    
    PGresult *res = NULL;
    
    res = PQexec(conn, query.c_str());
    
    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
    } else {
        /*
        // print column name
        for (int i = 0; i < PQnfields(res); i++)
            cout << PQfname(res, i) << "       ";
        cout << endl;
        */
        for (int i = 0; i < PQntuples(res); i++){
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
        out.open("отчет_1.csv", ios::trunc);
        if (out.is_open()){
            for (int i = 0; i < PQntuples(res); i++){
                for (int j = 0; j < PQnfields(res); j++)
                    out << PQgetvalue(res, i, j) << ";";
                out << endl;
            }
        out.close();
        printf("Формирование отчета № 1 завершено!\n");
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
        out.open("отчет_2.csv", ios::trunc);
        if (out.is_open()){
            for (int i = 0; i < PQntuples(res); i++){
                for (int j = 0; j < PQnfields(res); j++)
                    out << PQgetvalue(res, i, j) << ";";
                out << endl;
            }
        out.close();
        printf("Формирование отчета № 2 завершено!\n");
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
        out.open("отчет_3.csv", ios::trunc);
        if (out.is_open()){
            for (int i = 0; i < PQntuples(res); i++){
                for (int j = 0; j < PQnfields(res); j++)
                    out << PQgetvalue(res, i, j) << ";";
                out << endl;
            }
        out.close();
        printf("Формирование отчета № 3 завершено!\n");
        }
        PQclear(res);
    }
}