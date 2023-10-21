
/*
// 6������ 6��
// ���� Ʈ���� ��ũ�� ����Ʈ�� ����

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
		printf("���� Ʈ���� ���� ���� ���ʴ�� �Է��Ͻÿ� : ");
		scanf("%d", &data);

		Tree[i] = data;
	}

	for (int i = 0; i < 10; i++)
		printf("%d  %d\n", i, Tree[i]);
}
*/







/*
// 10������ 4��
// ���� Ʈ�� Ž�� _ ������ȸ



// ==== main.cpp

#include "node.h"

// ���� �Լ� ����
void InitializeTree(void);
void MakeTree(void);
void Traverse(TreeNode *);
void Visit(TreeNode *);


// ���� ���� ����
TreeNode *Parent, *LeftChild, *RightChild;
TreeNode *HeadNode, *EndNode;


// Ʈ���� �ʱ�ȭ
void InitializeTree(void)
{
	HeadNode = (TreeNode *)malloc(sizeof(TreeNode));
	EndNode = (TreeNode *)malloc(sizeof(TreeNode));
	
	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}


// Ʈ���� �ʱ� ����
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
	InitStack();				// ������ �ʱ�ȭ
	InitializeTree();				// Ʈ���� �ʱ�ȭ
	MakeTree();					// Ʈ���� ����
	Traverse(HeadNode->Left);			// Ʈ���� ��ȯ
}
*/






/*
// 27������ 4��

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

// �Է¹޴� ��� Ʈ�� �߰�(�����) (����ڰ� Ű����� �Է��ϴ� ���� ��� �߰�) initialize�� TreeAdd �Լ� ---> ��� �̰� ������ ����ϱ�
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
	printf("�߰��� ���� �Է��Ͻÿ� : ");
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
		printf("1. Ʈ���߰�\t2. Ʈ�� ��ȸ(������ȸ)\t3. ����\n");
		scanf("%d", &n);

		if (n == 3) break;
		if (n == 1) TreeAdd();
		if (n == 2) Traverse(Head);
	}
}

*/










/*

// 27������ 7��


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

void TreeAdd()			// ���� ���� ���� �Է��ؼ� ��忡 �� ����ִ� �˰���
{
	TreeNode *parent;
	TreeNode *new_node;
	int data;
	printf("�߰��� ���� �Է��Ͻÿ� : ");
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
		printf("1. Ʈ���߰�\n2. Ʈ�� ��ȸ(������ȸ)\n3. ��尳�� ���\n4. �ڽ��� �ϳ��� �ִ� ����� ���� ���\n5. �ڽ��� ���� ����� ���� ���\n6. ����\n");
		scanf("%d", &n);

		if (n == 6) break;

		if (n == 1) TreeAdd();
		if (n == 2) Traverse(Head);
		if (n == 3) printf("��� ���� : %d\n",TreeTotal_Num(Head));
		if (n == 4) printf("�ڽ��� �ϳ��� �ִ� ��� ���� : %d\n",TreeOne_Num(Head));
		if (n == 5) printf("�ڽ� ���� ��� ���� : %d\n",TreeTwo_Num(Head));
	}
}

*/







/*
// 14������ 5�� 
// ���� Ʈ��_������ȸ
// Traverse - ����Լ� �̿�


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
	printf("�߰��� ���� �Է��Ͻÿ� : ");
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
		printf("1. Ʈ���߰�\t2. Ʈ����ȸ(������ȸ)- ��͸� �̿���\t3. ����\n");
		scanf("%d", &n);

		if (n == 3) break;

		if (n == 1) TreeAdd();
		if (n == 2) Recursive_Traverse(Head);

	}
}
*/





/*

// 17������ 6��
// ����Ʈ��_������ȸ

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
	printf("�߰��� ���� �Է��Ͻÿ� : ");
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
		printf("1. Ʈ���߰�\t2. Ʈ����ȸ(������ȸ)- ��͸� �̿���\t3. ����\n");
		scanf("%d", &n);

		if (n == 3) break;

		if (n == 1) TreeAdd();
		if (n == 2) Recursive_Traverse(Head);

	}
}

*/



