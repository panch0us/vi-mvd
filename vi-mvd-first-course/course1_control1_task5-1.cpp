#include <iostream>
#include <Windows.h> // ����������� ��� SetConsoleCP() � SetConsoleOutputCP()

// 1 ����, ����������� � 1, ������� � 5.1
float response() {
	// ������� ���������� ����� � ��������� ������
	float response;
	bool finish = false;

	while (finish == false) {
		std::cout << "������� ����� ��� ������� � ������� (��������: 2 ��� 2.2): ";
		std::cin >> response;

		if (std::cin.good()) {
			finish = true;
			return response;
		}
		else {
			std::cout << "������� �������� ��������! ���������� ������ ����� (��������: 2 ��� 2.2) !" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

void my_f(float x) {
	float degree = 2 * (x + 2);
	float e = 2.71828;

	float result = (pow(e, degree) / -(2 * x + 3)) - (3 * pow(x, 4) + x);
	std::cout << "�����: " << result;
}

int main() {
	// ������� ��� ������ � �������� �������� � �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// �������� ����� �� ������������ 
	float result = response();
	my_f(result);
	return 0;
}