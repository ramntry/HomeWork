#pragma once

struct Stack;

// ������ ������� � ����
void push(Stack *stack, char value);

// ������� ������� �� ����� � ���������� �������� ������� ��������
int pop(Stack *stack);

// ������� ����� ����
Stack *createStack();

// ���������� �������� �������� �������� �����
int returnHeadValue(Stack *stack);

// ���������� ���������� ��������� � �����
int returnAmountElements(Stack *stack);

// ������ ����
void deleteStack(Stack *stack);