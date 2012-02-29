/* �����: 
1)
��������� ������
olga
777
vanya
341
petr
123
tom
541234

������� 1, ���� ������ ������������� ������ �� �����
������� 2, ���� ������ ������������� ������ �� ������ ��������
1
��������������� ������:
olga
777
petr
123
tom
541234
vanya
341
2)
��������� ������
olga
777
vanya
341
petr
123
tom
541234

������� 1, ���� ������ ������������� ������ �� �����
������� 2, ���� ������ ������������� ������ �� ������ ��������
2
��������������� ������:
petr
123
vanya
341
tom
541234
olga
777

��������� �����: 1,5 ����
�����������: 2 ���� 40 �����
*/
#include <iostream>
#include <fstream>
#include <clocale>
#include "List.h"
#include "MergeSort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	List *list = createList();
	ifstream in("List.txt");
	cout << "��������� ������\n";

	if (in)
	{
		while (!in.eof())
		{
			char name[256];
			in >> name;
			char phoneNumber[256];
			in >> phoneNumber;
			if (name[0] != 0 && phoneNumber[0] != 0)
			{
				addToEnd(list, name, phoneNumber);
				cout << name << endl;
				cout << phoneNumber << endl;
			}
		}
	}
	in.close();
	cout << "\n������� 1, ���� ������ ������������� ������ �� �����\n";
	cout << "������� 2, ���� ������ ������������� ������ �� ������ ��������\n";
	int number = 0;
	cin >> number;
	char *string = {0};
	
	if (number == 1)
		string = "name";
	if (number == 2)
		string = "phoneNumber";

	list = mergeSort(list, string);
	int size = returnAmountEl(list);
	char *name = {0};
	char *phoneNumber = {0};
	ListElement *position = firstElement(list);
	cout << "��������������� ������:\n";

	for (int i = 0; i < size; i++)
	{
		returnValuePosition(list, name, phoneNumber, position);
		cout << name << endl;
		cout << phoneNumber << endl;
		position = nextElement(list, position);
	}

	deleteList(list);
	return 0;
}