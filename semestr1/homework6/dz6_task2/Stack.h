#pragma once

struct Stack;

//������ ������� � ����
void push(Stack *stack, int value);

//������� ������� �� ����� � ���������� �������� ������� ��������
int pop(Stack *stack);

//������� ����� ����
Stack *createStack();

//���������� �������� �������� �������� �����
int returnHeadValue(Stack *stack);

//���������� ���������� ��������� � �����
int returnAmountElements(Stack *stack);

//������ ����
void deleteStack(Stack *stack);