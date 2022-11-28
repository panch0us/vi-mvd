// vi-mvd.cpp

#include <iostream>

void cp_for() {
	int massive[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (int& el : massive)
		//std::cout << el;
		++el;
}

int main() {

}