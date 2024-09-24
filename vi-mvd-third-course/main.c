#include <stdio.h>
#include "sqlite3.h"


/* Определяем константы */
enum {
    max_name_len = 64,
};


/* Определяем струкрутру лица для опознания*/
struct person {
    char surname[64];          /* Фамилия     */
    char name[max_name_len];             /* Имя         */
    char middle_name[max_name_len];      /* Отчество    */
    char sex[5];                            /* М или Ж     */
};


void menu(){ 
    char *menu = "\tАИПС \"Опознание\"\n \
                 \tМеню:\n \
                 Введите нужное число для выбора действия:\n \
                 1. Ввод лица\n \
                 2. Поиск лица\n \
                 3. Редактирование лица\n \
                 4. Инструкция\n \
                 5. О программе\n";
    
    printf("%s", menu);
}

int main()
{
    sqlite3 *db;                                        /* Создаем указатель на базу данных */
    int result = sqlite3_open("idetification.db", &db); /* Открываем подключение в БД */
    
    if(result != SQLITE_OK){
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    char *sql = "CREATE TABLE IF NOT EXISTS person(\
                 id INTEGER PRIMARY KEY AUTOINCREMENT,\
                 surname TEXT,\
                 name TEXT,\
                 middle_name TEXT,\
                 sex TEXT\
                 )";

    char *err_msg = 0;
    result = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if(result != SQLITE_OK){
        printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    printf("Таблица создана успешно!\n\n");
    
    menu();

    int select_menu; /* Какой пункт меню выбрал пользователь */
    struct person prsn;
    
    // добавить анализ для scanf на возвращаемое значение (стр 117 столяров)
    while((select_menu = getchar()) != EOF) {
        if(select_menu == '1') {
            getchar(); // Разобраться, почему лишний символ \n 
            printf("Вы выбрали ввод лица!\nВведите фамилию: ");
            scanf("%63[^'\n']", prsn.surname);
            getchar();
            printf("Введите имя: ");
            scanf("%63[^'\n']", prsn.name);
            getchar();
            printf("Введите отчество: ");
            scanf("%63[^'\n']", prsn.middle_name);
            printf("Введите пол: ");
            scanf("%4s[^'\n']", prsn.sex);
            getchar();
            
            // попробовать snprintf или spirintf
            char *sql = "INSERT INTO person (surname, name, middle_name, sex) VALUE (";
            char *sql2;
            
            char sql_res[500];
            scanf(sql2, "%s, %s, %s, %s", prsn.surname, prsn.name, prsn.middle_name, prsn.sex);
            snprintf(sql_res, sizeof sql_res, "%s%s", sql, sql2);
            printf("%s\n", sql_res);
            result = sqlite3_exec(db, sql_res, 0, 0, &err_msg);

            if(result != SQLITE_OK){
                printf("SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
                sqlite3_close(db);
                return 1;
            }

            break;
        }
        if(select_menu == '2') {
            printf("Вы выбрали Поиск лица!\n");
            break;
        }
        if(select_menu == '3') {
            printf("Вы выбрали редактирование лица!\n");
            break;
        }
    }

    sqlite3_close(db); /* Закрываем подключение к БД */
    return 0;
}
