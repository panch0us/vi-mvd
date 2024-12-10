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

// константы
enum {
    spacing     = 5,       // промежутки
    button_w    = 300,     // ширина кнопки
    button_h    = 40,      // высота кнопки
    font_size   = 20       // размер шрифта
};

// названия заголовков
static const char *msg[] = {
    "Добро пожаловать в АИПС \"Опознание\"!",
    "Выберите нужную команду (от 1 до 4):",
    "1. Ввод лица",
    "2. Редактирование лица",
    "3. Поиск лица",
    "4. Выход"
};


int main(int argc, char **argv)
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    const char my_con[] = "host=localhost dbname=postgres user=postgres password=12345678"; // тестовый вариант
    PGconn *conn = PQconnectdb(my_con);
    printf("HELLO!!!1\n");
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }

    PQfinish(conn);

    int select_menu;
    PersonMissing persmis;
    string power = "on";

    printf("HELLO!!!0\n");

    // вывод главного меню на экран
    while(power == "on"){
        for(int i = 0; i < 6; i++)
            printf("%s\n", msg[i]);
    
        // пользователь вводин номер меню
        cin >> select_menu;

        // выбираем действия в зависимости от выбора пользователя
        switch (select_menu)
        {
        case 1:
            {
                cout << "Выбран ввод лица.\n";
            int correct_input = 0;
            
            while(correct_input != 1){
                input_person(persmis);
                cout << "Данные введены верно? (1 - да / 0 - нет).";
                cin >> correct_input;
            }
            break;
            }
        case 2:
            cout << "Выбрано редактирование лица.\n";
            break;
        
        default:
            cout << "Неверный ввод!\n";
            break;
        }
        
        //power = "off";
    }
}