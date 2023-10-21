


/*

//레벨 순회

// 1페이지 1번
// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"


QueueType level;
TreeNode *Head;

// 내가 만든 직접 입력해서 입력한 값 트리에 넣는 알고리즘  - > initNode input 함수 같이 두 개 가져다 쓸 것 ("Circular.h" include 하기)
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
	printf("트리에 넣을 값을 입력하시오 : ");
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
		printf("1. 입력 2. 출력 3. 종료\n");
		scanf("%d", &num);
		if (num == 1) input();
		if (num == 2) output(Head);
		if (num == 3) break;
	
	}
}

*/


 


/*
// 6페이지 
// <디렉토리 용량 계산>

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
	n1.Data = { "정지영상",200 };
	n1.Left = NULL;
	n1.Right = NULL;

	TreeNode n2;
	n2.Data = { "동영상",500 };
	n2.Left = NULL;
	n2.Right = NULL;

	TreeNode n3;
	n3.Data = { "음악",500 };
	n3.Left = NULL;
	n3.Right = NULL;

	TreeNode n4;
	n4.Data = { "그림",100 };
	n4.Left = &n1;
	n4.Right = &n2;

	TreeNode n5;
	n5.Data = { "나의문서",NULL };
	n5.Left = &n3;
	n5.Right = &n4;


	printf("후위순회로 출력한 디렉토리\n\n");
	Recursive_Traverse(&n5);

	printf("\n나의문서의 용량(총 디렉토리 용량) : %d\n", tot(&n5));
	total = 0;
	printf("\n그림문서의 용량 : %d\n", tot(&n4));


}

*/







/*
// 9페이지
// 트리의 높이 구하기

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
	printf("트리에 넣을 값을 입력하시오 : ");
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
		printf("1. 입력  2. 트리 높이  3. 종료\n");
		scanf("%d", &n);
		if (n == 3) break;

		if (n == 1) input();
		if (n == 2) {
			int cnt_left = Recursive_LEFT_Traverse(Head);
			int cnt_right = Recursive_RIGHT_Traverse(Head);

			if (cnt_left <= cnt_right) cnt = cnt_right;
			else cnt = cnt_left;
			printf("현재 트리의 높이 : %d\n", cnt);
	
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














			// 트리 높이 구하는 거 완성해오기(완성함) + 스레드 이진 트리 보면서 키보드로 입력해보고 이해. 확인하기 + 13페이지 1번해오기