#include <iostream>
using namespace std;

int main() {
	float massive[100];
	float summ = 0;
	int count;

	cout << "vvedite kolichestvo iteraciy: ";
	cin >> count;

	for (int i = 0; i < count; i++) {
		cout << "massive[" << i << "] = ";
		cin >> *(massive + i);
		summ += *(massive + i);
	}
	
	cout << "Summa = " << summ << endl;

	return 0;
}