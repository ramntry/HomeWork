#pragma once

struct List;
struct ListElement;

// ������� ����� ������
List *createList();

// ��������� ������� � ����� ������
void addToEnd(List *list, char *name, char *phoneNumber);

// ������ ������
void deleteList(List * list);

// ���������� ���������� ��������� � ������
int returnAmountEl(List *list);

// ������ ������� �� ��������� ������� ������
ListElement *nextElement(List *list, ListElement *position);

// ������ �������� �� ��������� ������� ������
ListElement *endElement(List*list);

// ������ �������� �� ������ ������� ������
ListElement *firstElement(List *list);

// ���������� �������� �������� � ������ ���������
void returnValuePosition(List *list, char *&name, char *&phoneNumber, ListElement *position);

// ������� ������� ������� ������
void delHead(List *list);

// ���������� �������� �������� �������� ������
void returnHeadValue(List *list, char *&name, char *&phoneNumber);
