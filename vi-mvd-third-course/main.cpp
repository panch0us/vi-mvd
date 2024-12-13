/*
g++ -Wall -g main.cpp -o main -I "C:\Program Files\PostgreSQL\16\include" -L "C:\Program Files\PostgreSQL\16\lib" -lpq
*/
using namespace std;

#include <Windows.h> // для кодировка CP1251
#include <stdio.h>
#include <fstream>   // для записи в файл
#include <stdlib.h>
#include <iostream>
#include <libpq-fe.h>

#include "person.h"
#include "menu_func.h"
#include "bd_func.h"


// названия заголовков
static const char *msg[] = {
    "_________________________________________",
    "| Добро пожаловать в АИПС 'Опознание'!  |",
    "| Введите нужную команду (от 1 до 4):   |",
    "| 1. Ввод лица                          |",
    "| 2. Поиск лица                         |",
    "| 3. Сформировать отчет                 |",
    "| 4. Выход                              |",
    "|_______________________________________|"
};


int main(int argc, char **argv)
{
    int auth_status = 0; // если 0 - значит ни кто не авторизовался, если 1 - авторизовался.
    
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    const char my_con[] = "host=localhost dbname=postgres user=postgres password=12345678"; // тестовый вариант
    PGconn *conn = PQconnectdb(my_con);
    if (PQstatus(conn) != CONNECTION_OK){
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    int exist_table = 0;
    string name_table; // для передачи параметра в функцию check_exist_tables

    name_table = "auth";
    exist_table = check_exist_tables(conn, name_table);
    if(exist_table == 0)
        create_table_auth(conn); // создаем таблицу для авторизации

    name_table = "opoz_pers_mis";
    exist_table = check_exist_tables(conn, name_table);
    if(exist_table == 0)
        create_table_opoz(conn); // создаем таблицу для опознания (если не создана)
    
    int select_menu;       // выбор пользователя по разделам меню
    PersonMissing persmis; // создаем объект для опознания
    string power = "on";

    // вывод главного меню на экран
    while(power == "on"){
        int exist_admin = 0; // админ не существует.
        exist_admin = dont_exist_admin(conn);
        if(exist_admin == 0)
            create_admin(conn);
        else if((exist_admin > 1) || (exist_admin < 0)){
            PQfinish(conn);
            return 1;
        }

        int auth_adm_ok = 0; // если 0 - значит администратор не авторизовался
        
        while(auth_adm_ok == 0 && auth_status == 0){
            auth_adm_ok = auth_adm(conn); // аутентификация админа
            if(auth_adm_ok == 1){
                printf("Добро пожаловать!\n");
                auth_status = 1;
            }
            else if(auth_adm_ok == 0)
                printf("Неверный логин или пароль! Попробуйте заново!\n");
            else{
                printf("Неизвестная ошибка авторизации!\n");
                PQfinish(conn);
                return 1;
            }
        }
        for(int i = 0; i < 9; i++)
            printf("%s\n", msg[i]);
    
        cin >> select_menu; // пользователь вводин номер меню
        fflush(stdin); // очищаем стандартный поток ввода от символа \n, оставшегося после cin

        // выбираем действия в зависимости от выбора пользователя
        switch (select_menu)
        {
            case 1:
                {
                    cout << "Выбран ввод лица.\n";
                    int correct_input = 0;
                    
                    while(correct_input != 1)
                    {
                        input_person(persmis);
                        cout << "Данные введены верно? (1 - да / 0 - нет).";
                        cin >> correct_input;
                        fflush(stdin);
                    }
                    insert_table(conn, persmis);
                    break;
                }
            case 2:
                {
                    cout << "Выбран поиск лица\n";
                    select_table(conn);
                    break;
                }
            case 3:
                {
                    cout << "Выбрано формирование отчета.\nВыберите вид отчета:\n1.Полный отчет\n2.Отчет за период времени\n3.Отчет по району";
                    cin >> select_menu;
                    fflush(stdin);
                    if(select_menu == 1)
                        generate_report_1(conn);
                    else if(select_menu == 2)
                        generate_report_2(conn);
                    else if(select_menu == 3)
                        generate_report_3(conn);
                    else
                        printf("Неверный выбор отчета\n");
                    break;
                }
            case 4:
                {
                    cout << "Выход!\n";
                    PQfinish(conn); // Завершаем работу с БД
                    return 0;
                }
            default:
                {
                    cout << "Неверный ввод!\n";
                    break;
                }
        }     
    }
    PQfinish(conn);
    return 1;
}