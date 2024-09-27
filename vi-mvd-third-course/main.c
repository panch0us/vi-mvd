#include <stdio.h>
#include "sqlite3.h"

#define MENU \
    "АИПС \"Опознание\"\n" \
    "Меню:\n" \
    "Введите нужное число для выбора действия:\n" \
    "1. Ввод лица\n" \
    "2. Поиск лица\n" \
    "3. Редактирование лица\n" \
    "4. Инструкция\n" \
    "5. О программе\n"


/* Определяем константы */
enum { max_name_len = 64 };


/* Определяем струкрутру лица для опознания*/
struct person {
    char surname[max_name_len];             // Фамилия
    char name[max_name_len];                // Имя
    char middle_name[max_name_len];         // Отчество
    char sex[3];                            // М или Ж
};


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
    
#ifdef DEBUG
    printf("Таблица создана успешно!\n");
    printf("Дата: %s, Время: %s\n", __DATE__, __TIME__);
#endif
    puts(MENU);

    int select_menu;
    int scanf_result;    // Какой пункт меню выбрал пользователь
    struct person prsn;
    
    // Анализируем выбор пункта меню пользователя 
    while((select_menu = getchar()) != EOF) {
        if(select_menu == '1') {
            getchar(); // Разобраться, почему лишний символ \n 
            
            printf("Вы выбрали ввод лица!\nВведите фамилию: ");
            scanf_result = scanf("%63[^'\n']", prsn.surname);
            if(scanf_result != 1){
                printf("Error: wrong input.\n");
                return 1;
            }
            getchar();
            
            printf("Введите имя: ");
            scanf_result = scanf("%63[^'\n']", prsn.name);
            if(scanf_result != 1){
                printf("Error: wrong input.\n");
                return 1;
            }
            getchar();
            
            printf("Введите отчество: ");
            scanf_result = scanf("%63[^'\n']", prsn.middle_name);
            if(scanf_result != 1){
                printf("Error: wrong input.\n");
                return 1;
            }
            getchar();

            printf("Введите пол: ");
            scanf_result = scanf("%2[^'\n']", prsn.sex);
            if(scanf_result != 1){
                printf("Error: wrong input.\n");
                return 1;
            }
            getchar();
            
            char *for_sql = "INSERT INTO person (surname, name, middle_name, sex) VALUES (";
            char sql[512];

            sprintf(sql, "%s'%s', '%s', '%s', '%s');", for_sql, prsn.surname, prsn.name, prsn.middle_name, prsn.sex);
#ifdef DEBUG
            printf("%s\n", sql);
#endif
            result = sqlite3_exec(db, sql, 0, 0, &err_msg);

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
