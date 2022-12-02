/*
«Дана целочисленная матрица A размером mxn 
упорядочить (переставить) столбцы матрицы по 
неубыванию (каждый слежующий элемент не меньше 
предыдущего) значений первых элементов столбцов.
Разрешается использовать дополнительный массив».
*/


#include <iostream>
#include <Windows.h>
using namespace std;

int** arr_f(int &rows, int &cols, int &random) {

	
	cout << "Введите количество строк матрицы: "; cin >> rows;
	cout << "Введите количество столбцов матрицы: "; cin >> cols;
	cout << "Введите диапазон для случайных чисел: "; cin >> random;

	int** arr = new int *[rows];

	for (int i = 0; i < rows; i++)
	{	
		*(arr + i) = new int [cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(arr + i) + j) = rand() % random;
		}
	}

	return arr;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int rows = 0, cols = 0, buffer_1 = 0, buffer_2 = 0, count = 0, random = 0;

	int **array = arr_f(rows, cols, random);

	cout << endl << "Матрица " << rows << "x" 
		<< cols << ", состоящая из случайных чисел в диапазоне от 0 до " 
		<< random << ": " << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(array + i) + j) << '\t';
		}
		cout << endl;
	}

	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols - 1; j++)
			{
				if (array[i][j] > array[i][j + 1]) {
					buffer_1 = array[i][j];
					buffer_2 = array[i][j + 1];
					array[i][j] = buffer_2;
					array[i][j + 1] = buffer_1;
				}
			}
		}
	}
		
	
	cout << endl << "Матрица с сортировкой по неубыванию:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(array + i) + j) << '\t';
		}
		cout << endl;
	}

	// освобождаем память
	for (int i = 0; i < cols; i++)
	{
		delete[] array[i];
	}

	delete[] array;

	return 0;
}