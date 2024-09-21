#include <stdio.h>
#include "sqlite3.h"


/* Определяем константы */
enum {
    max_name_len = 64,
};


/* Определяем струкрутру лица для опознания*/
struct person {
    char surname[max_name_len];          /* Фамилия     */
    char name[max_name_len];             /* Имя         */
    char middle_name[max_name_len];      /* Отчество    */
    char sex;                            /* М или Ж     */
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

    printf("table created\n");

    char *hello = "Программа \"Опознание\"";
    char *menu = "\tМеню:\nВведите нужное число для выбора действия:\n \
    1. Ввод лица\n \
    2. Поиск лица\n \
    3. Редактирование лица\n";
    
    printf("%s\n%s\n", hello, menu);

    int select_menu;
    struct person prsn;

    while((select_menu = getchar()) != EOF) {
        if(select_menu == '1') {
            printf("Вы выбрали ввод лица!\n");
            printf("Введите фамилию: ");
            scanf("%s", prsn.surname);
            printf("Вы ввели фамилию: %s\n", prsn.surname);
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
