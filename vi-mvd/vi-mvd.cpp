// vi-mvd.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void cp_fnc() {
    int massive[5] = { 0,1,2,3,4 };
    int cp_massive[5];

    for (int x : massive)
        std::cout << x << '\n';
}

int main()
{
    cp_fnc();
}

