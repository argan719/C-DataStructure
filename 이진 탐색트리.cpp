#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "CircularQueue.h"

TreeNode *Head;
QueueType q;


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



void Traverse(TreeNode *ptr)
{
	if (ptr != NULL)
	{
		Traverse(ptr->Left);
		Traverse(ptr->Right);
		printf("%d\n", ptr->Data);
	}
}


int Search_Traverse(TreeNode *ptr, int item)
{
	if (ptr != NULL)
	{
		Traverse(ptr->Left);
		Traverse(ptr->Right);
		return(ptr->Data);
	}
	return NULL;
	
}

void Search()
{
	int item;

	printf("ã�� ���� �Է��Ͻÿ� : ");
	scanf("%d", &item);
	int data = Search_Traverse(Head);

	

}

void main()
{
	int n;
	init(&q);
	initNode();

	for (;;)
	{
		printf("*******************\n");
		printf("1. �Է�\n");
		printf("2. ����\n");
		printf("3. Ž��\n");
		printf("4. ���\n");
		printf("5. ����\n");
		printf("*******************\n");
		scanf("=> %d", &n);

		if (n == 5) break;

		if (n == 1) input();
		if (n == 2)
		if (n == 3) Search();
		if (n == 4) Traverse(Head);

	}
}