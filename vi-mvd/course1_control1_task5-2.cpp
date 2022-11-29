#include <iostream>
#include <iomanip>


int main() {
	int a = 0;
	float b = 5;

	double i = 12345.1234567;
	std::cout << std::fixed << std::setprecision(5) << i << std::endl;
	std::cout << std::setw(20) << std::showpoint << std::setprecision(2) << b << "QWE";
}