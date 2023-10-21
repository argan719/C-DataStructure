


/*

//���� ��ȸ

// 1������ 1��
// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"


QueueType level;
TreeNode *Head;

// ���� ���� ���� �Է��ؼ� �Է��� �� Ʈ���� �ִ� �˰���  - > initNode input �Լ� ���� �� �� ������ �� �� ("Circular.h" include �ϱ�)
{

void initNode()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	Head->Data = NULL;
	Head->Left = NULL;
	Head->Right = NULL;
}

void input()							
	TreeNode *parent;
	TreeNode *new_node = NULL;
	int data;
	printf("Ʈ���� ���� ���� �Է��Ͻÿ� : ");
	scanf("%d", &data);

	parent = Head;

	if (Head->Data == NULL)
	{
		parent = Head;
		parent->Data = data;
	}
	else {

		new_node = (TreeNode *)malloc(sizeof(TreeNode));
		new_node->Left = NULL;
		new_node->Right = NULL;
		new_node->Data = data;

		if (data <= parent->Data) {

			while (data <= parent->Data)
			{
				if (parent->Left == NULL) {
					parent->Left = new_node; break;
				}
				else parent = parent->Left;

				if (parent->Data < data) {
					while (parent->Data < data) {
						if (parent->Right == NULL) {
							parent->Right = new_node; break;
						}
						else parent = parent->Right;
					}
				}
			}


		}

		else {

			while (parent->Data < data)
			{
				if (parent->Right == NULL) {
					parent->Right = new_node; break;
				}
				else parent = parent->Right;

				if (data <= parent->Data) {
					while (data <= parent->Data) {
						if (parent->Left == NULL) {
							parent->Left = new_node; break;
						}
						else parent = parent->Left;
					}
				}
			}

		}
	}
}


void output(TreeNode *ptr)
{
	enqueue(&level, ptr);

	while (!is_empty(&level))
	{
		ptr= dequeue(&level);
		printf("%d ", ptr->Data);

		if (ptr->Left != NULL)
			enqueue(&level, ptr->Left);
		if (ptr->Right != NULL)
			enqueue(&level, ptr->Right);
	}
	printf("\n");
}



void main()
{
	init(&level);
	initNode();
	int num;
	for (;;)
	{
		printf("1. �Է� 2. ��� 3. ����\n");
		scanf("%d", &num);
		if (num == 1) input();
		if (num == 2) output(Head);
		if (num == 3) break;
	
	}
}

*/


 


/*
// 6������ 
// <���丮 �뷮 ���>

#include<stdio.h>
#include<stdlib.h>

typedef struct f {
	char name[20];
	int size;
}file;

int total = 0;


typedef struct TreeNode {
	file Data;
	struct TreeNode *Left, *Right;
}TreeNode;


void Recursive_Traverse(TreeNode *ptr)
{
	if (ptr != NULL)
	{
		Recursive_Traverse(ptr->Left);
		Recursive_Traverse(ptr->Right);
		printf("%s %d\n", ptr->Data.name, ptr->Data.size);
	}
}


int tot(TreeNode *ptr)
{
	if (ptr != NULL)
	{
		tot(ptr->Left);
		tot(ptr->Right);
		total += ptr->Data.size;
	}
	return total;
}


void main()
{
	TreeNode n1;
	n1.Data = { "��������",200 };
	n1.Left = NULL;
	n1.Right = NULL;

	TreeNode n2;
	n2.Data = { "������",500 };
	n2.Left = NULL;
	n2.Right = NULL;

	TreeNode n3;
	n3.Data = { "����",500 };
	n3.Left = NULL;
	n3.Right = NULL;

	TreeNode n4;
	n4.Data = { "�׸�",100 };
	n4.Left = &n1;
	n4.Right = &n2;

	TreeNode n5;
	n5.Data = { "���ǹ���",NULL };
	n5.Left = &n3;
	n5.Right = &n4;


	printf("������ȸ�� ����� ���丮\n\n");
	Recursive_Traverse(&n5);

	printf("\n���ǹ����� �뷮(�� ���丮 �뷮) : %d\n", tot(&n5));
	total = 0;
	printf("\n�׸������� �뷮 : %d\n", tot(&n4));


}

*/







/*
// 9������
// Ʈ���� ���� ���ϱ�

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct tree{
	int Data;
	struct tree *Left, *Right;
}TreeNode;


TreeNode *Head;

void initNode()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	Head->Data = NULL;
	Head->Left = NULL;
	Head->Right = NULL;
}

void input()
{
	TreeNode *parent;
	TreeNode *new_node = NULL;
	int data;
	printf("Ʈ���� ���� ���� �Է��Ͻÿ� : ");
	scanf("%d", &data);

	parent = Head;

	if (Head->Data == NULL)
	{
		parent = Head;
		parent->Data = data;
	}
	else {

		new_node = (TreeNode *)malloc(sizeof(TreeNode));
		new_node->Left = NULL;
		new_node->Right = NULL;
		new_node->Data = data;

		if (data <= parent->Data) {

			while (data <= parent->Data)
			{
				if (parent->Left == NULL) {
					parent->Left = new_node; break;
				}
				else parent = parent->Left;

				if (parent->Data < data) {
					while (parent->Data < data) {
						if (parent->Right == NULL) {
							parent->Right = new_node; break;
						}
						else parent = parent->Right;
					}
				}
			}


		}

		else {

			while (parent->Data < data)
			{
				if (parent->Right == NULL) {
					parent->Right = new_node; break;
				}
				else parent = parent->Right;

				if (data <= parent->Data) {
					while (data <= parent->Data) {
						if (parent->Left == NULL) {
							parent->Left = new_node; break;
						}
						else parent = parent->Left;
					}
				}
			}

		}
	}
}



int Recursive_LEFT_Traverse(TreeNode *ptr)
{
	if (ptr->Left == NULL) return(1);
	else return(Recursive_LEFT_Traverse(ptr->Left) + 1);
}


int Recursive_RIGHT_Traverse(TreeNode *ptr)
{
	if (ptr->Right == NULL) return(1);
	else return(Recursive_RIGHT_Traverse(ptr->Right) + 1);
}


void main()
{
	initNode();
	int n;
	int cnt;
	for (;;)
	{
		printf("1. �Է�  2. Ʈ�� ����  3. ����\n");
		scanf("%d", &n);
		if (n == 3) break;

		if (n == 1) input();
		if (n == 2) {
			int cnt_left = Recursive_LEFT_Traverse(Head);
			int cnt_right = Recursive_RIGHT_Traverse(Head);

			if (cnt_left <= cnt_right) cnt = cnt_right;
			else cnt = cnt_left;
			printf("���� Ʈ���� ���� : %d\n", cnt);
	
		}

	}
}
*/





/*
#include<stdio.h>
#include<string.h>


int Recursive(int n)
{
	if(10<=n) return (0);
	else return ( Recursive(n+2) + 1);
}


void main()
{
	int sum = Recursive(1);
	printf("cnt = %d", sum);
}

*/














			// Ʈ�� ���� ���ϴ� �� �ϼ��ؿ���(�ϼ���) + ������ ���� Ʈ�� ���鼭 Ű����� �Է��غ��� ����. Ȯ���ϱ� + 13������ 1���ؿ���