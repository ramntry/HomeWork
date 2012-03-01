#pragma once

struct BinaryTree;
struct BinaryTreeElement;

// ������� �������� ������ ������
BinaryTree *createBinaryTree();

// ��������� ������� � �������� ������ ������
void insert(BinaryTree *tree, int value);

// ������� ������� � �������� ���������
bool deleteElement(BinaryTree *tree, int value);

/* ���� ������� � �������� ���������, ���������� true, ���� ���� �������,
false, ���� ������ �������� ��� � ������ */
bool search(BinaryTree *tree, int value);

// ������ ������� �� ������
BinaryTreeElement *returnRootPosition(BinaryTree *tree);

// ������� ������
void deleteTree(BinaryTree *tree);

// ���������� �������� �������� ��������
int returnValuePosition(BinaryTree *tree, BinaryTreeElement *position);

// ���������� ������� ������ ������ ���� ������� ��������
BinaryTreeElement *leftMostChild(BinaryTree *tree, BinaryTreeElement *temp);

// ���������� ������� ������ ����
BinaryTreeElement *returnLeftPosition(BinaryTree *tree, BinaryTreeElement *position);

// ���������� ������� ������� ����
BinaryTreeElement *returnRigthPosition(BinaryTree *tree, BinaryTreeElement *position);

// ���������� ������� ��������
BinaryTreeElement *returnParentPosition(BinaryTree *tree, BinaryTreeElement *position);

