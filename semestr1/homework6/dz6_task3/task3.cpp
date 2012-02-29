/*�����
1) ({)} 
��� ������� ������
2) ({})
������ ������ ��������
3) ({[]})
������ ������ ��������
4) ([{}](
��� ������� ������
5) (
��� ������� ������
6) )
��� ������� ������

���������: 40 �����
�����������: 50 �����
*/
#include <iostream>
#include <clocale>
#include <string.h>
#include "Stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Stack *stack = createStack();
	cout << "������� ������������������ ������ ���� {}, [], ()\n";
	char string[256];
	cin >> string;
	int size = strlen(string);
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		if (string[i] == '{' || string[i] == '[' || string[i] == '(')
			push(stack, string[i]);
		else
		{
			char symbol = returnHeadValue(stack);

			if (symbol == ' ')
			{
				flag = false;
				break;
			}

			if (string[i] == '}')
				if (symbol == '{')
					pop(stack);
				else
					break;
			if (string[i] == ']')
				if (symbol == '[')
					pop(stack);
				else
					break;
			if (string[i] == ')')
				if (symbol == '(')
					pop(stack);
				else
					break;
		}
	}

	if (!flag)
		cout << "��� ������� ������\n";
	else
	{
		if (returnHeadValue(stack) == ' ')
			cout << "������ ������ ��������\n";
		else
			cout << "��� ������� ������\n";
	}

	deleteStack(stack);
	return 0;
}