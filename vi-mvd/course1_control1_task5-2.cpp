#include <iostream>

using namespace std;


int main() {
	double massive[10];
	double *pd = &massive[0];

	for (int i = 0; i < 10; i++) {
		cout << "massive[" << i << "] = ";
		cin >> *pd++;
	}

	for (double x : massive) {
		cout << x << endl;
	}

	return 0;
}