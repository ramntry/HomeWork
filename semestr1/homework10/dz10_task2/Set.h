#pragma once

struct Set;

// ������� ����� ���������
Set *createSet();

// ��������� ������� � ���������
void addToSet(Set *set, int value);

// ���������, ���� �� ������� � ���������
bool exists(Set *set, int value);

// ���������� ���������� ��������� � ���������
int amountSet(Set *set);

// ������� ���������
void deleteSet(Set *set);