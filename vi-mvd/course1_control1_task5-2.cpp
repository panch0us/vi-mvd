#include <iostream>

using namespace std;

void f1(int a, int *b, int &c) {
	a += 10;
	(*b) += 10;
	c += 10;
}

int main() {
	int x = 10;
	int y = 20;
	int z = 30;

	f1(x, &y, z);

	cout << x << " " << y << " " << z << endl;

	return 0;
}