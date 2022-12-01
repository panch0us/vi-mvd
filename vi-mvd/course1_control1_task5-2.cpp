#include <iostream>
using namespace std;

int main() {
	int rows;
	int cols;

	cout << "vvedite kolichestvo strok: ";
	cin >> rows;
	cout << "vvedite kolichestvo stolbcov: ";
	cin >> cols;

	int  **array = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new int [cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	
	/////////////////////////////
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	
	delete[] array;

	return 0;
}