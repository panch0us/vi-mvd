/*
g++ -Wall -g main.cpp -o main -I "C:\Program Files\PostgreSQL\16\include" -L "C:\Program Files\PostgreSQL\16\lib" -lpq
*/
using namespace std;

#include <Windows.h> // для кодировка CP1251
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <libpq-fe.h>

#include "person.h"
#include "menu_func.h"
#include "bd_func.h"


// названия заголовков
static const char *msg[] = {
    "Добро пожаловать в АИПС \"Опознание\"!",
    "Введите нужную команду (от 1 до 4):",
    "1. Ввод лица",
    "2. Поиск лица",
    "3. Сформировать отчет",
    "4. Выход"
};


int main(int argc, char **argv)
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    const char my_con[] = "host=localhost dbname=postgres user=postgres password=12345678"; // тестовый вариант
    PGconn *conn = PQconnectdb(my_con);
    if (PQstatus(conn) != CONNECTION_OK){
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    // создаем таблицу в БД
    create_table(conn);

    // Подготовка к загрузке главного меню
    int select_menu;       // выбор пользователя по разделам меню
    PersonMissing persmis; // создаем объект для опознания
    string power = "on";   // если "on" - значит главный цикл работает


    // вывод главного меню на экран
    while(power == "on"){
        for(int i = 0; i < 6; i++)
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
                        select_table(conn, surname, name, middle_name, dayb, monthb, yearb);
                    break;
                }
            case 3:
                {
                    cout << "Выбрано формирование отчета.\nВыберите вид отчета:\
                    1.Полный отчет\n2.Отчет за период времени\n3.Отчет по району";
                    cin >> select_menu;
                    
                    if(select_menu == 1)
                        generate_report_1();
                    else if(select_menu == 2)
                        generate_report_2();
                    else if(select_menu == 3)
                        generate_report_3();
                    else
                        printf("Неверный выбор отчета\n");
                    break;
                }
            case 4:
                {
                    cout << "Выход!\n";
                    PQfinish(conn); // Завершаем работу с БД
                    exit(0);
                }
            default:
                {
                    cout << "Неверный ввод!\n";
                    break;
                }
        }
        
        
    }

    PQfinish(conn); // Завершаем работу с БД
}