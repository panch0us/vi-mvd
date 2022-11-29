#include <iostream>
#include <typeinfo>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()

// 1 курс, контрольная № 1, задание № 10
float response() {
	// Функция возвращает число с плавающей точкой
	float response;
	std::cout << "Введите число для расчета в функции (например: 2 или 2.2): ";
	if (std::cin >> response, std::cin.good()) {
		std::cout << response << std::endl;
		return response;
	}
	else {
		std::cout << "Введено неверное значение! Необходимо ввести цифру (например: 2 или 2.2) !" << std::endl;
		std::cin.clear();		
	}
}

void my_f(float x) {
	float degree = 2 * (x + 2);
	float e = 2.71828;
	
	float result = (pow(e, degree) / -(2 * x + 3)) - (3 * pow(x, 4) + x);
	std::cout << "Ответ: " << result;
}

int main() {
	// Функции для работы с русскими симолами в консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Получаем ответ от пользователя 
	float result = response();
	my_f(result);
	return 0;
}