/*
������ ���������� � ����������, ����� �������� �������� ����� � ����������. 
���� ������ ���, ������� ��������������� ���������.
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

	int employes_count = 0; // ���������� ����������� ��� ����� � ��
	unsigned long long int phone_number = 0; // ������� ���������� ��� ������ � ��
	cout << "������� ���������� ����������� ��� ����� � ����: ";
	cin >> employes_count;

	SPISOK* sotrudniki = new SPISOK[employes_count];

	for (int i = 0; i != employes_count; i++)
	{
		cout << endl << "---------------------------------------" << endl;
		cout << "������� ������ � ���������� � " << i + 1 << ": " << endl;
		cout << "�������: ";
		cin >> sotrudniki[i].fam;
		cout << "���: ";
		cin >> sotrudniki[i].imya;
		cout << "��������: ";
		cin >> sotrudniki[i].otch;
		cout << "����� ��������: ";
		cin >> sotrudniki[i].phone_num;
		cout << "������: ";
		cin >> sotrudniki[i].zvan;
		cout << "���� ��������: " << endl;
		cout << "\t����: ";
		cin >> sotrudniki[i].d_rojd;
		cout << "\t�����: ";
		cin >> sotrudniki[i].m_rojd;
		cout << "\t���: ";
		cin >> sotrudniki[i].y_rojd;
	}

	cout << endl << "---------------------------------------" << endl;
	cout << "������� ����� �������� ��� ������ �� ���� �����������: ";
	cin >> phone_number;

	for (int i = 0; i != employes_count; i++)
	{
		if (phone_number == sotrudniki[i].phone_num) {
			cout << endl << "---------------------------------------" << endl;
			cout << "��������� ���������� ����� ���������� ��������� � " 
				<< i + 1 << ": " << endl;
			cout << "���: " << sotrudniki[i].fam << " ";
			cout << sotrudniki[i].imya << " ";
			cout << sotrudniki[i].otch << endl;
			cout << "����� ��������: " << sotrudniki[i].phone_num << endl;
			cout << "������: " << sotrudniki[i].zvan << endl;
			cout << "���� ��������: " << sotrudniki[i].d_rojd << "."
				<< sotrudniki[i].m_rojd << "."
				<< sotrudniki[i].y_rojd << endl;
			cout << endl << "������������ ����� �� ���������� �����������..." 
				<< endl;
		}
		else {
			cout << "����� ��������! ���������� ����� " << phone_number 
				<< " � �� ����������!" << endl;
		}
	}

	return 0;
}