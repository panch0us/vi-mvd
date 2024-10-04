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


/* Определяем константы */
enum {  max_name_len = 64 };


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
        switch(select_menu)  
        {
            case '1':
                getchar(); 
            
                // Блок ввода фамилии
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

            // Блок ввода пола
            printf("Введите пол: ");
            scanf_result = scanf("%2[^'\n']", prsn.sex);
            if(scanf_result != 1){
                printf("Error: wrong input.\n");
                return 1;
            }
            getchar();
            
            printf("-------------------------------------------------\n \
                \rВнимание! Проверьте введенные данные!\n \
                \rВы ввели следующие данные:\n \
                \rФамилия: %s\n \
                \rИмя: %s\n \
                \rОтчество: %s\n \
                \rПол: %s\n \
                \r--------------------------------------------------- \n \
                \r           1. Верно\n \
                \r           2. Ввести заново\n \
                \r---------------------------------------------------\n\n",
                prsn.surname, prsn.name, prsn.middle_name, prsn.sex); 
            
            while((select_menu = getchar()) != EOF) {
                switch(select_menu){
                    case '1':
                       getchar();
                       printf("aaaa\n");
                       break;

                    default:
                       getchar();
                       printf("default\n");
                       break;
                }
                break;
            }

            char *for_sql = "INSERT INTO person (surname, name, middle_name, sex) VALUES (";
            char sql[512];

            sprintf(sql, "%s'%s', '%s', '%s', '%s');", for_sql, prsn.surname, prsn.name, prsn.middle_name, prsn.sex);
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

            break;

        case '2':
            getchar();
            printf("Вы выбрали Поиск лица!\n");
            break;

        case '3':
            getchar();
            printf("Вы выбрали редактирование лица!\n");
            break;
        
        default:
            getchar();
            printf("Введен неверный символ для меню, выберит между 1-6\n");
            break;
        }
        
        puts(MENU);
    }

    sqlite3_close(db); /* Закрываем подключение к БД */
    return 0;
}

// добавить к новым функциям static
