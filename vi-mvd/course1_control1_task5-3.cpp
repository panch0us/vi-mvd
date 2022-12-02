/*
«Напишите программу, при работе которой определяется, 
есть ли в массиве элементы, значения которых совпадают».
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int elements = 0;
	int random = 0;

	cout << "Введите количество элементов массива: ";
	cin >> elements;
	cout << "Введите значения для диапазона случайных чисел: ";
	cin >> random;

	int *array = new int [elements];

	for (int i = 0; i < elements; i++)
	{
		array[i] = rand() % random;
	}

	cout << endl << "Полученный массив чисел: ";
	for (int i = 0; i < elements; i++)
	{
		cout << array[i] << ", ";
	}

	cout << endl << "Находим повторяющиейся значения: " << endl;
	for (int i = 0; i < elements - 1; i++)
	{
		for (int j = (i + 1); j < elements - 1; j++)
		{
			if (array[i] == array[j]) {
				cout << "Элемент № " << i << "(" << array[i] << ")" 
					<< " == Элементу № " << j << "(" << array[j] << ");" << endl;
			}
		}
	}
	return 0;
}