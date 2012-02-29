#pragma once

struct Stack;

// ������ ������� � ����
void push(Stack *stack, char value);

// ������� ������� �� ����� � ���������� �������� ������� ��������
char pop(Stack *stack);

// ������� ����� ����
Stack *createStack();

// ���������� �������� �������� �������� �����
char returnHeadValue(Stack *stack);

// ������ ����
void deleteStack(Stack *stack);