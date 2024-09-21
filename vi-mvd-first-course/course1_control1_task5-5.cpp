/*
«Вывод информации о сотруднике, номер телефона которого введён с клавиатуры. 
Если такого нет, вывести соответствующие сообщение».
*/

#include <iostream>
#include <Windows.h>
using namespace std;

struct SPISOK {
	char fam[21];
	char imya[16];
	char otch[21];
	unsigned long long int phone_num;
	char zvan[11];
	int d_rojd;
	int m_rojd;
	int y_rojd;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int employes_count = 0; // Количество сотрудников для ввода в БД
	unsigned long long int phone_number = 0; // Телефон сотруднкиа для поиска в БД
	cout << "Введите количество сотрудников для ввода в базу: ";
	cin >> employes_count;

	SPISOK* sotrudniki = new SPISOK[employes_count];

	for (int i = 0; i != employes_count; i++)
	{
		cout << endl << "---------------------------------------" << endl;
		cout << "Введите данные о сотруднике № " << i + 1 << ": " << endl;
		cout << "Фамилия: ";
		cin >> sotrudniki[i].fam;
		cout << "Имя: ";
		cin >> sotrudniki[i].imya;
		cout << "Отчество: ";
		cin >> sotrudniki[i].otch;
		cout << "Номер телефона: ";
		cin >> sotrudniki[i].phone_num;
		cout << "Звание: ";
		cin >> sotrudniki[i].zvan;
		cout << "Дата рождения: " << endl;
		cout << "\tДень: ";
		cin >> sotrudniki[i].d_rojd;
		cout << "\tМесяц: ";
		cin >> sotrudniki[i].m_rojd;
		cout << "\tГод: ";
		cin >> sotrudniki[i].y_rojd;
	}

	cout << endl << "---------------------------------------" << endl;
	cout << "Введите номер телефона для поиска по базе сотрудников: ";
	cin >> phone_number;

	for (int i = 0; i != employes_count; i++)
	{
		if (phone_number == sotrudniki[i].phone_num) {
			cout << endl << "---------------------------------------" << endl;
			cout << "Указанный телефонный номер использует сотрудник № " 
				<< i + 1 << ": " << endl;
			cout << "ФИО: " << sotrudniki[i].fam << " ";
			cout << sotrudniki[i].imya << " ";
			cout << sotrudniki[i].otch << endl;
			cout << "Номер телефона: " << sotrudniki[i].phone_num << endl;
			cout << "Звание: " << sotrudniki[i].zvan << endl;
			cout << "Дата рождения: " << sotrudniki[i].d_rojd << "."
				<< sotrudniki[i].m_rojd << "."
				<< sotrudniki[i].y_rojd << endl;
			cout << endl << "Продолжается поиск по оставшимся сотрудникам..." 
				<< endl;
		}
		else {
			cout << "Поиск завершен! Телефонный номер " << phone_number 
				<< " в БД отсутсвует!" << endl;
		}
	}

	return 0;
}