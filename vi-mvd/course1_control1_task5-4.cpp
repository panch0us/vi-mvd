/*
«Описать структуру с именем SPISOK, содержащую следующие поля:
•	Фамилия (не более 20 символов);
•	Имя (не более 15 символов);
•	Отчество (не более 20 символов);
•	Номер телефона;
•	Специальное звание (не более 10 символов);;
•	День рождения;
•	Месяц рождения;
•	Год рождения».
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
	cout << "Введите количество сотрудников для ввода в базу: ";
	cin >> employes_count;

	SPISOK *sotrudniki = new SPISOK [employes_count];
	
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
	cout << "Список всех сотрудников в базе: ";

	for (int i = 0; i != employes_count; i++)
	{	
		cout << endl << "---------------------------------------" << endl;
		cout << "Сотрудник № " << i + 1 << ": " << endl;
		cout << "ФИО: " << sotrudniki[i].fam << " ";
		cout << sotrudniki[i].imya << " ";
		cout << sotrudniki[i].otch << endl;
		cout << "Номер телефона: " << sotrudniki[i].phone_num << endl;
		cout << "Звание: " << sotrudniki[i].zvan << endl;
		cout << "Дата рождения: " << sotrudniki[i].d_rojd << "."
			<< sotrudniki[i].m_rojd << "." 
			<< sotrudniki[i].y_rojd << endl;
	}

	return 0;
}