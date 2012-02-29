/*�����:
1)
������� ��������� � ��������� �����
(1+1)*2
������ ��������� � ����������� ����� ����� ���
11+2*
2)
������� ��������� � ��������� �����
(1+1
�������� ������!
3)
������� ��������� � ��������� �����
2*3+(1+7*8+9)*(6-5)
������ ��������� � ����������� ����� ����� ���
23*178*+9+65-*+
4)
������� ��������� � ��������� �����
1+2+3
������ ��������� � ����������� ����� ����� ���
12+3+
5)
������� ��������� � ��������� �����
4/2+(5-3)*(2+4)
������ ��������� � ����������� ����� ����� ���
42/53-24+*+

��������� �����: 1 ���
����������� �����: 1 ��� 35 �����
*/

#include <iostream>
#include <clocale>
#include "Stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Stack *stack = createStack();
	cout << "������� ��������� � ��������� �����\n";
	char string[256];
	cin >> string;
	char stringResult[256];
	int count = 0;
	int size = strlen(string);
	bool successfulyOperation = true;
	
	for (int i = 0; i < size; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			stringResult[count] = string[i];
			count++;
		}

		if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/')
		{
			if (string[i] == '*' || string[i] == '/')
			{
				char symbol = returnHeadValue(stack);

				while (symbol == '*' || symbol == '/')
				{
					symbol = pop(stack);
					stringResult[count] = symbol;
					count++;
					symbol = returnHeadValue(stack);
				}
			}

			if (string[i] == '+' || string[i] == '-')
			{
				char symbol = returnHeadValue(stack);
				
				while (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
				{
					symbol = pop(stack);
					stringResult[count] = symbol;
					count++;
					symbol = returnHeadValue(stack);
				}
			}

			push(stack, string[i]);
		}

		if (string[i] == '(')
			push(stack, string[i]);

		if (string[i] == ')')
		{
			while (returnHeadValue(stack) != '(')
			{
				char symbol = pop(stack);
				
				if (symbol == ' ')
				{
					successfulyOperation = false;
					break;
				}
				else
				{
					stringResult[count] = symbol;
					count++;
				}
			}
			
			pop(stack);
		}
	}

	if (!successfulyOperation)
		cout << "�������� ������!\n";
	else
	{
		while (returnAmountElements(stack) > 0)
		{
			char symbol = pop(stack);
			if (symbol == '(')
			{
				successfulyOperation = false;
				break;
			}
			else
			{
				stringResult[count] = symbol;
				count++;
			}
		}
		
		if (!successfulyOperation)
			cout << "�������� ������!\n";
		else
		{
			cout << "������ ��������� � ����������� ����� ����� ���\n";
			for (int i = 0; i < count; i++)
				cout << stringResult[i];
			cout << endl;
		}
	}
	
	deleteStack(stack);
	return 0;
}