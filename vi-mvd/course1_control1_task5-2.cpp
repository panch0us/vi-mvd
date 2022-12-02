#include <iostream>
using namespace std;

int** arr_f(int &rows, int &cols) {

	cout << "count rows: "; cin >> rows;
	cout << "count cols: "; cin >> cols;

	int** arr = new int *[rows];

	for (int i = 0; i < rows; i++)
	{	
		*(arr + i) = new int [cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(arr + i) + j) = rand() % 10;
		}
	}

	return arr;
}

int main() {
	int rows = 0, cols = 0, summ = 0, count = 0, average = 0;

	int **array = arr_f(rows, cols);

	cout << "ARRAY: " << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(array + i) + j) << '\t';
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ( !(*(*(array + i) + j) % 2) ) {
				summ += *(*(array + i) + j);
				count += 1;
			}
		}
	}

	if (count) {
		average = summ / count;
	}

	cout << "summ = " << summ << endl << "count = " << count << endl << "average = " << average << endl;


	for (int i = 0; i < cols; i++)
	{
		delete[] array[i];
	}

	delete[] array;

	return 0;
}