/*
��������� ���������, ��� ������ ������� ������������, 
���� �� � ������� ��������, �������� ������� ���������.
*/

#include <iostream>
#include <Windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int elements = 0;
	int random = 0;

	cout << "������� ���������� ��������� �������: ";
	cin >> elements;
	cout << "������� �������� ��� ��������� ��������� �����: ";
	cin >> random;

	int *array = new int [elements];

	for (int i = 0; i < elements; i++)
	{
		array[i] = rand() % random;
	}

	cout << endl << "���������� ������ �����: ";
	for (int i = 0; i < elements; i++)
	{
		cout << array[i] << ", ";
	}

	cout << endl << "������� �������������� ��������: " << endl;
	for (int i = 0; i < elements - 1; i++)
	{
		for (int j = (i + 1); j < elements - 1; j++)
		{
			if (array[i] == array[j]) {
				cout << "������� � " << i << "(" << array[i] << ")" 
					<< " == �������� � " << j << "(" << array[j] << ");" << endl;
			}
		}
	}
	return 0;
}