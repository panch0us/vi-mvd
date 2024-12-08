#include <stdio.h>
#include "sqlite3.h"

#define MENU \
    "===============================================================\n" \
    "|                       АИПС Опознание                        |\n" \
    "|                            Меню:                            |\n" \
    "| Введите нужное число для выбора действия:                   |\n" \
    "| 1. Ввод лица                                                |\n" \
    "| 2. Поиск лица                                               |\n" \
    "| 3. Редактирование лица                                      |\n" \
    "| 4. Инструкция                                               |\n" \
    "| 5. О программе                                              |\n" \
    "| 6. Выход                                                    |\n" \
    "| Для завершения программы нажмите ctrl+d или введите цифру 6 |\n" \
    "===============================================================\n"


/* Create constans */
enum {  MAX_NAME_LEN = 64 };


/* Create struct for insert/select in database. 
Person.sex = 3 char, because russian char = 2 byte + 1 byte for \0
*/
struct person {
    char surname[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    char middle_name[MAX_NAME_LEN];
    char sex[3];                        /* М or Ж */
};

/* callback-function for database requests */
int callback(void*, int, char**, char**);

int main()
{
    /* Create pointer on  database */
    sqlite3 *db;
    int result = sqlite3_open("idetification.db", &db);
    
    if(result != SQLITE_OK){
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    /* Attempt create table */
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
        switch(select_menu)  
        {
            /* create person */
            case '1':
                getchar(); 
            
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
                if(scanf_result == '\n'){
                    getchar();
                    scanf_result = (int)32; // Если отчества нет - символ пробела ASCII
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

                printf("---------------------------------------------------\n \
                    \rВнимание! Проверьте введенные данные выше!\n \
                    \r--------------------------------------------------- \n \
                    \r           1. Верно, продолжить\n \
                    \r           2. Неверно, вернуться в меню\n \
                    \r---------------------------------------------------\n\n"); 
                
                int select_menu_after_input;

                while((select_menu_after_input = getchar()) != EOF) {
                    switch(select_menu_after_input){
                        case '1':
                            getchar();
                            printf("Выбарно: Данные введены верно ");
                            break;
                        
                        case '2':
                            getchar();
                            printf("Выбарно: Данные введены неверно. Запись в базу не проводилась\n");
                            break;

                        case '\n':
                            getchar();
                            printf("удален лишний символ новой строки\n");
                            continue;

                        default:
                            getchar();
                            printf("Неверно введен символ при выборе, попробуйте снова\n");
                            continue;
                    }
                    break;
                }

                if(select_menu_after_input == '2'){
                    puts(MENU);
                    continue;
                }

                char *for_sql = "INSERT INTO person (surname, name, middle_name, sex) VALUES (";
                char sql[512];

                sprintf(sql, "%s'%s', '%s', '%s', '%s');", 
                    for_sql, prsn.surname, prsn.name, prsn.middle_name, prsn.sex);
#ifdef DEBUG
                printf("DEBUG: %s\n", sql);
#endif
                result = sqlite3_exec(db, sql, 0, 0, &err_msg);

                if(result != SQLITE_OK){
                    printf("SQL error: %s\n", err_msg);
                    sqlite3_free(err_msg);
                    sqlite3_close(db);
                    return 1;
                }
                printf("и записаны в базу.\n");
                break;

            /* Search person */
            case '2':
                getchar();
                printf("Вы выбрали Поиск лица!\nВыберите поиск по:\n \
                    \r1. Фамилии\n \
                    \r2. Имени\n \
                    \r3. Отчеству\n");
                
                int select_menu_for_search;
                char surname_for_search[MAX_NAME_LEN];
                
                while((select_menu_for_search = getchar()) != EOF) {
                    switch(select_menu_for_search){
                        /* Search surname */
                        case '1':
                            getchar();
                            printf("Выбарно: Поиск по фамилии.\nВведите фамилию: ");

                            scanf_result = scanf("%63[^'\n']", surname_for_search);
                            if(scanf_result != 1){
                                printf("Error: wrong input.\n");
                                return 1;
                            }
                            getchar();

                            char *for_sql = "SELECT * FROM person WHERE surname LIKE";
                            char sql[512];

                            sprintf(sql, "%s '%s';", for_sql, surname_for_search);

                            result = sqlite3_exec(db, sql, callback, 0, &err_msg);
                            if (result != SQLITE_OK ){
                                printf("SQL error: %s\n", err_msg);
                                sqlite3_free(err_msg);
                                sqlite3_close(db);
                                return 1;
                            }
#ifdef DEBUG
                            printf("DEBUG: %s\n", sql);
#endif                      
                            break;
                        
                        case '2':
                            getchar();
                            printf("Выбарно: Поиск по имени\n");
                            break;

                        case '3':
                            getchar();
                            printf("Выбарно: Поиск по отчеству\n");
                            break;

                        case '\n':
                            getchar();
                            printf("Удален лишний символ новой строки\n");
                            continue;

                        default:
                            getchar();
                            printf("Неверно введен символ при выборе, попробуйте снова\n");
                            continue;
                    }

                    break;
                }
            break;

            /* Edit person */    
            case '3':
                getchar();
                printf("Вы выбрали редактирование лица!\n");
                break;
            
            default:
                getchar();
                printf("Введен неверный символ для меню, выберит между 1-6\n");
                continue;
            }
            
        puts(MENU);
    }

    /* Close database */
    sqlite3_close(db);
    return 0;
}

/* For search person */
int callback(void *notUsed, int colCount, char **columns, char **colNames)
{
    for (int i = 0; i < colCount; i++)
    {
        printf("%s = %s\n", colNames[i], columns[i] ? columns[i] : "NULL");
    }
    printf("\n");
    return 0;
}
