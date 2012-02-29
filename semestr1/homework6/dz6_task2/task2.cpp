/*�����:
1)
������� ������������������ ���� � �������� +, -, *, /
96-12+*
���������: 9
2)
������� ������������������ ���� � �������� +, -, *, /
11+
���������: 2
3)
������� ������������������ ���� � �������� +, -, *, /
12
������! �������� ������� ������!
4)
������� ������������������ ���� � �������� +, -, *, /
57+34-*
���������: -12
5)
������� ������������������ ���� � �������� +, -, *, /
70/
������! �������� ������� ������!
6)
������� ������������������ ���� � �������� +, -, *, /
10+30++
���������: 4
7)
������� ������������������ ���� � �������� +, -, *, /
22-
���������: 0
8)
������� ������������������ ���� � �������� +, -, *, /
123+
������! �������� ������� ������!

��������� �����: 40 �����
�����������: �� ���� ����, � � � ���������� �����,
��-����� ���� ������ �������� 
*/

#include <iostream>
#include <clocale>
#include <string.h>
#include "Stack.h"

using namespace std;

bool operation(char symbolOperation, Stack *stack)
{
	int result = 0;
	
	if (returnAmountElements(stack) == 0)
		return false;
	int valueFirst = pop(stack);

	if (returnAmountElements(stack) == 0)
		return false;
	int valueSecond = pop(stack);

	if (symbolOperation == '+')
		result = valueSecond + valueFirst;

	if (symbolOperation == '-')
		result = valueSecond - valueFirst;

	if (symbolOperation == '*')
		result = valueSecond * valueFirst;

	if (symbolOperation == '/')
	{
		if (valueFirst == 0)
			return false;
		else
			result = valueSecond / valueFirst;
	}

	push(stack, result);
	return true;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Stack *stack = createStack();
	cout << "������� ������������������ ���� � �������� +, -, *, /\n";
	char string[256];
	cin >> string;
	int size = strlen(string);
	bool successfulyOperation = true;

	for (int i = 0; i < size; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
			push(stack, string[i] - '0');
		
		if (string[i] == '+' || string[i] == '-' || string[i] == '*'  || string[i] == '/' )
		{
			successfulyOperation = operation(string[i], stack);	
			
			if (!successfulyOperation)
				break;
		}
	}
	
	if (!successfulyOperation)
		cout << "������! �������� ������� ������!\n";
	else
	{
		int result = pop(stack);
		
		if (returnAmountElements(stack) == 0)
			cout << "���������: " << result << endl;
		else
			cout << "������! �������� ������� ������!\n";
	}

	deleteStack(stack);
	return 0;
}