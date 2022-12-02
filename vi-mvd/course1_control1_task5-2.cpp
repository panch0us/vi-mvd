#include <iostream>
using namespace std;

int main() {
	
	int **array = new int *[3];

	for (int i = 0; i < 3; i++)
	{
		*(array+i) = new int [5];
	}

	cout << "array = " << array << ", *(array) = " << *(array) << endl;


	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			*(*(array + i)+ j) = rand() % 20;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << ((array + i) + j) << " -> ";
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete [] *(array + i);
	}

	delete [] array;

	return 0;
}