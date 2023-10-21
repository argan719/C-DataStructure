
/*
// 6페이지 6번
// 이진 트리를 링크드 리스트로 구현

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;


void main()
{
	TreeNode *n1, *n2, *n3;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;

}
*/



/*
#include<stdio.h>
#include<stdlib.h>


void main()
{
	int Tree[10] = { 0, };
	int data;
	for (int i = 1; i <8; i++)
	{
		printf("이진 트리에 넣을 값을 차례대로 입력하시오 : ");
		scanf("%d", &data);

		Tree[i] = data;
	}

	for (int i = 0; i < 10; i++)
		printf("%d  %d\n", i, Tree[i]);
}
*/







/*
// 10페이지 4번
// 이진 트리 탐색 _ 전위순회



// ==== main.cpp

#include "node.h"

// 내부 함수 정의
void InitializeTree(void);
void MakeTree(void);
void Traverse(TreeNode *);
void Visit(TreeNode *);


// 전역 변수 정의
TreeNode *Parent, *LeftChild, *RightChild;
TreeNode *HeadNode, *EndNode;


// 트리의 초기화
void InitializeTree(void)
{
	HeadNode = (TreeNode *)malloc(sizeof(TreeNode));
	EndNode = (TreeNode *)malloc(sizeof(TreeNode));
	
	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}


// 트리의 초기 구성
void MakeTree()
{
	Parent = (TreeNode *)malloc(sizeof(TreeNode));
	Parent->Data = 'A';

	LeftChild = (TreeNode *)malloc(sizeof(TreeNode));
	LeftChild->Data = 'B';

	RightChild = (TreeNode *)malloc(sizeof(TreeNode));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (TreeNode *)malloc(sizeof(TreeNode));
	LeftChild->Data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (TreeNode *)malloc(sizeof(TreeNode));
	RightChild->Data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
	Parent = HeadNode->Right->Right;

	LeftChild = (TreeNode *)malloc(sizeof(TreeNode));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (TreeNode *)malloc(sizeof(TreeNode));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

}

void Traverse(TreeNode *ptrNode)
{
	Push(ptrNode);

	while (!IsStackEmpty()) {
		ptrNode = Pop();
		Visit(ptrNode);

		if (ptrNode->Right != EndNode)
			Push(ptrNode->Right);

		if (ptrNode->Left != EndNode)
			Push(ptrNode->Left);
	}
}


void Visit(TreeNode *ptrNode)
{
	printf("%2c -> ", ptrNode->Data);
}


void main()
{
	InitStack();				// 스택의 초기화
	InitializeTree();				// 트리의 초기화
	MakeTree();					// 트리의 구성
	Traverse(HeadNode->Left);			// 트리의 순환
}
*/






/*
// 27페이지 4번

#include<stdio.h>
#include<stdlib.h>
#include "node.h"

TreeNode *Head, *EndNode;

void InitializeTree()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	EndNode = (TreeNode *)malloc(sizeof(TreeNode));

	Head->Left = EndNode;
	Head->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;

}

void MakeTree()
{
	TreeNode *Left, *Right, *parent;

	parent= (TreeNode *)malloc(sizeof(TreeNode));
	parent->Left = EndNode;
	parent->Right = EndNode;
	parent->Data = 5;

	
	Left = (TreeNode *)malloc(sizeof(TreeNode));
	Left->Left = EndNode;
	Left->Right = EndNode;
	Left->Data = 3;

	Right = (TreeNode *)malloc(sizeof(TreeNode));
	Right->Left = EndNode;
	Right->Right = EndNode;
	Right->Data = 7;

	parent->Left = Left;
	parent->Right = Right;

	Head->Left = parent;
	Head->Right = parent;

	parent = parent->Left;

	Left = (TreeNode *)malloc(sizeof(TreeNode));
	Left->Left = EndNode;
	Left->Right = EndNode;
	Left->Data = 2;

	Right = (TreeNode *)malloc(sizeof(TreeNode));
	Right->Left = EndNode;
	Right->Right = EndNode;
	Right->Data = 4;

	parent->Left = Left;
	parent->Right = Right;

	Left = (TreeNode *)malloc(sizeof(TreeNode));
	Left->Left = EndNode;
	Left->Right = EndNode;
	Left->Data = 1;

	Right = (TreeNode *)malloc(sizeof(TreeNode));
	Right->Left = EndNode;
	Right->Right = EndNode;
	Right->Data = 8;

	parent->Left->Left = Left;
	parent->Left->Right = Right;


	Left = (TreeNode *)malloc(sizeof(TreeNode));
	Left->Left = EndNode;
	Left->Right = EndNode;
	Left->Data = 1;

	parent->Right->Left = Left;

	parent = Head->Left->Right;

	Left = (TreeNode *)malloc(sizeof(TreeNode));
	Left->Left = EndNode;
	Left->Right = EndNode;
	Left->Data = 6;

	Right = (TreeNode *)malloc(sizeof(TreeNode));
	Right->Left = EndNode;
	Right->Right = EndNode;
	Right->Data = 9;

	parent->Left = Left;
	parent->Right = Right;
}

void Visit(TreeNode *ptr)
{
	printf("%d -> ", ptr->Data);
}

void Traverse(TreeNode *ptr)
{
	Push(ptr);

	while (!IsStackEmpty()) {
		ptr = Pop();
		Visit(ptr);

		if (ptr->Right != EndNode)
			Push(ptr->Right);
		
		if (ptr->Left != EndNode)
			Push(ptr->Left);
	}
}



void main()
{
	InitStack();
	InitializeTree();
	MakeTree();
	Traverse(Head->Left);
}

*/









/*

// 입력받는 대로 트리 추가(만들기) (사용자가 키보드로 입력하는 값을 계속 추가) initialize랑 TreeAdd 함수 ---> 계속 이거 가져다 사용하기
// ===main.cpp

#include<stdio.h>
#include<stdlib.h>
#include "node.h"

TreeNode *Head;


void initialize()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	Head->Data = NULL;
	Head->Left = NULL;
	Head->Right = NULL;

}

void TreeAdd()
{
	TreeNode *parent;
	TreeNode *new_node;
	int data;
	printf("추가할 값을 입력하시오 : ");
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

void Visit(TreeNode *ptr)
{
	printf("%d -> ", ptr->Data);
}

void Traverse(TreeNode *ptr)
{
	Push(ptr);

	while (!IsStackEmpty()) {
		ptr = Pop();
		Visit(ptr);

		if (ptr->Right != NULL) {
			Push(ptr->Right);
		}

		if (ptr->Left != NULL) {
			Push(ptr->Left);
		}
	}
	printf("\n");

}

void main()
{
	int n;
	initialize();
	for (;;)
	{
		printf("1. 트리추가\t2. 트리 순회(전위순회)\t3. 종료\n");
		scanf("%d", &n);

		if (n == 3) break;
		if (n == 1) TreeAdd();
		if (n == 2) Traverse(Head);
	}
}

*/










/*

// 27페이지 7번


#include<stdio.h>
#include<stdlib.h>
#include "node.h"

TreeNode *Head;

void initialize()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	Head->Data = NULL;
	Head->Left = NULL;
	Head->Right = NULL;

}

void TreeAdd()			// 내가 만든 직접 입력해서 노드에 값 집어넣는 알고리즘
{
	TreeNode *parent;
	TreeNode *new_node;
	int data;
	printf("추가할 값을 입력하시오 : ");
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

void Visit(TreeNode *ptr)
{
	printf("%d -> ", ptr->Data);
}

void Traverse(TreeNode *ptr)
{
	Push(ptr);

	while (!IsStackEmpty()) {
		ptr = Pop();
		Visit(ptr);

		if (ptr->Right != NULL) {
			Push(ptr->Right);
		}

		if (ptr->Left != NULL) {
			Push(ptr->Left);
		}
	}
	printf("\n");

}

int TreeTotal_Num(TreeNode *ptr)
{
	int sum = 0;
	Push(ptr);
	sum++;

	while (!IsStackEmpty()) {
		ptr = Pop();

		if (ptr->Right != NULL) {
			Push(ptr->Right);
			sum++;
		}

		if (ptr->Left != NULL) {
			Push(ptr->Left);
			sum++;
		}
	}

	return sum;
}


int TreeOne_Num(TreeNode *ptr)
{
	int flag;
	int sum = 0;
	Push(ptr);


	while (!IsStackEmpty()) {
		ptr = Pop();
		flag = 0;

		if (ptr->Right != NULL) {
			Push(ptr->Right);
			flag++;
		}

		if (ptr->Left != NULL) {
			Push(ptr->Left);
			flag++;
		}

		if (flag == 1) sum++;
	}

	return sum;
}

int TreeTwo_Num(TreeNode *ptr)
{
	int flag;
	int sum = 0;
	Push(ptr);


	while (!IsStackEmpty()) {
		ptr = Pop();
		flag = 0;

		if (ptr->Right != NULL) {
			Push(ptr->Right);
			flag++;
		}

		if (ptr->Left != NULL) {
			Push(ptr->Left);
			flag++;
		}

		if (flag == 2) sum++;
	}

	return sum;
}


void main()
{
	int n;
	initialize();
	for (;;)
	{
		printf("1. 트리추가\n2. 트리 순회(전위순회)\n3. 노드개수 출력\n4. 자식이 하나만 있는 노드의 개수 출력\n5. 자식이 둘인 노드의 개수 출력\n6. 종료\n");
		scanf("%d", &n);

		if (n == 6) break;

		if (n == 1) TreeAdd();
		if (n == 2) Traverse(Head);
		if (n == 3) printf("노드 개수 : %d\n",TreeTotal_Num(Head));
		if (n == 4) printf("자식이 하나만 있는 노드 개수 : %d\n",TreeOne_Num(Head));
		if (n == 5) printf("자식 둘인 노드 개수 : %d\n",TreeTwo_Num(Head));
	}
}

*/







/*
// 14페이지 5번 
// 이진 트리_중위순회
// Traverse - 재귀함수 이용


#include<stdio.h>
#include<stdlib.h>
#include "node.h"


TreeNode *Head;


void initialize()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	Head->Data = NULL;
	Head->Left = NULL;
	Head->Right = NULL;

}

void TreeAdd()
{
	TreeNode *parent;
	TreeNode *new_node;
	int data;
	printf("추가할 값을 입력하시오 : ");
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

void Visit(TreeNode *ptr)
{
	printf("%d -> ", ptr->Data);
}



void Recursive_Traverse(TreeNode *ptr)
{
	if (ptr != NULL)
	{
		Recursive_Traverse(ptr->Left);
		Visit(ptr);
		Recursive_Traverse(ptr->Right);
	}
}


void main()
{
	initialize();
	int n;

	for (;;)
	{
		printf("1. 트리추가\t2. 트리순회(중위순회)- 재귀를 이용한\t3. 종료\n");
		scanf("%d", &n);

		if (n == 3) break;

		if (n == 1) TreeAdd();
		if (n == 2) Recursive_Traverse(Head);

	}
}
*/





/*

// 17페이지 6번
// 이진트리_후위순회

#include<stdio.h>
#include<stdlib.h>
#include "node.h"


TreeNode *Head;


void initialize()
{
	Head = (TreeNode *)malloc(sizeof(TreeNode));
	Head->Data = NULL;
	Head->Left = NULL;
	Head->Right = NULL;

}

void TreeAdd()
{
	TreeNode *parent;
	TreeNode *new_node;
	int data;
	printf("추가할 값을 입력하시오 : ");
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

void Visit(TreeNode *ptr)
{
	printf("%d -> ", ptr->Data);
}



void Recursive_Traverse(TreeNode *ptr)
{
	if (ptr != NULL)
	{
		Recursive_Traverse(ptr->Left);
		Recursive_Traverse(ptr->Right);
		Visit(ptr);
	}
}


void main()
{
	initialize();
	int n;

	for (;;)
	{
		printf("1. 트리추가\t2. 트리순회(후위순회)- 재귀를 이용한\t3. 종료\n");
		scanf("%d", &n);

		if (n == 3) break;

		if (n == 1) TreeAdd();
		if (n == 2) Recursive_Traverse(Head);

	}
}

*/



