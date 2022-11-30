#include <iostream>

using namespace std;


int main() {
	int x;

	metka:	cout << "vvedite znchenie x: ";
			cin >> x;

			if (x) {
				cout << 10 / x;
			}
			else {
				cout << "GOTO!";
				goto metka;
			}
				
	return 0;
}