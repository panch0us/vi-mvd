/*
�������� ��������� � ������ SPISOK, ���������� ��������� ����:
�	������� (�� ����� 20 ��������);
�	��� (�� ����� 15 ��������);
�	�������� (�� ����� 20 ��������);
�	����� ��������;
�	����������� ������ (�� ����� 10 ��������);;
�	���� ��������;
�	����� ��������;
�	��� ���������.
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

	int employes_count = 0;
	cout << "������� ���������� ����������� ��� ����� � ����: ";
	cin >> employes_count;

	SPISOK *sotrudniki = new SPISOK [employes_count];
	
	for (int i = 0; i != employes_count; i++)
	{	
		cout << "�������: ";
		cin >> sotrudniki[i].fam;
		cout << "���: ";
		cin >> sotrudniki[i].imya;
		cout << "��������: ";
		cin >> sotrudniki[i].otch;
		cout << "����� ��������: ";
		cin >> sotrudniki[i].phone_num;
		cout << "���� ��������: " << endl;
		cout << "\t����: ";
		cin >> sotrudniki[i].d_rojd;
		cout << "\t�����: ";
		cin >> sotrudniki[i].m_rojd;
		cout << "\t���: ";
		cin >> sotrudniki[i].y_rojd;
	}

	for (int i = 0; i != employes_count; i++)
	{	
		cout << endl << "---------------------------------------" << endl;
		cout << "��������� � " << i + 1 << ": " << endl;

		cout << "�������: " << sotrudniki[i].fam << endl;
		cout << "���: " << sotrudniki[i].imya << endl;
		cout << "��������: " << sotrudniki[i].otch << endl;
		cout << "����� ��������: " << sotrudniki[i].phone_num << endl;
		cout << "���� ��������: " << sotrudniki[i].d_rojd << "."
			<< sotrudniki[i].m_rojd << "." << sotrudniki[i].y_rojd << endl;
	}
	


	return 0;
}