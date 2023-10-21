

// 2022 / 04 / 29
// C++ ������ �ڷᱸ�� �ٽ� ����
// Ʈ�� ó������ ���� (Ʈ�� ������ ó�� ���� ��ó�� Ʈ������ �ڷᱸ�� ����)








/*
// 6��
// ���� Ʈ���� ��ũ�� ǥ���Ͽ� ���ô�.
// ����, ����, ������ȸ �������� ����

#include<stdlib.h>
#include<memory.h>
#include"node.h"
#define MAX 100
#define TRUE 1
#define FALSE 0
// stack(Ʈ��).cpp 

void Visit(TreeNode * ptrNode);
void Recursive_Traverse(TreeNode *ptrNode);


TreeNode *Stack[MAX];
int Top;


void InitStack(void)
{
	Top = 0;
}

void Push(TreeNode *ptrNode)
{
	Stack[Top] = ptrNode;
	Top = (Top++) % MAX;
}

TreeNode *Pop(void)
{
	TreeNode *ptrNode;
	if (!IsStackEmpty()) {
		ptrNode = Stack[--Top];
		return ptrNode;
	}
	else
		printf("Stack is Empty!\n");
	return NULL;
}

int IsStackEmpty(void)
{
	if (Top == 0)
		return TRUE;
	else
		return FALSE;
}



void main()
{
	// Ʈ�� ��� ����
	TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10, *n11;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	n4 = (TreeNode *)malloc(sizeof(TreeNode));
	n5 = (TreeNode *)malloc(sizeof(TreeNode));
	n6 = (TreeNode *)malloc(sizeof(TreeNode));
	n7 = (TreeNode *)malloc(sizeof(TreeNode));
	n8 = (TreeNode *)malloc(sizeof(TreeNode));
	n9 = (TreeNode *)malloc(sizeof(TreeNode));
	n10 = (TreeNode *)malloc(sizeof(TreeNode));
	n11= (TreeNode *)malloc(sizeof(TreeNode));

	n1->Data = 1;    // ù ��° ��Ʈ�� �����Ѵ�.
	n1->Left = n2; 
	n1->Right = n7;
	n2->Data = 2;    // �� ��° ��带 �����Ѵ�.
	n2->Left = n3;
	n2->Right = n6;
	n3->Data = 3;    // �� ��° ��带 �����Ѵ�.
	n3->Left = n4;
	n3->Right = n5;
	n4->Data = 4;
	n4->Left = NULL;
	n4->Right = NULL;
	n5->Data = 5;
	n5->Left = NULL;
	n5->Right = NULL;
	n6->Data = 6;
	n6->Left = NULL;
	n6->Right = NULL;
	n7->Data = 7;
	n7->Left = n8;
	n7->Right = n9;
	n8->Data = 8;
	n8->Left = NULL;
	n8->Right = NULL;
	n9->Data = 9;
	n9->Left = n10;
	n9->Right = n11;
	n10->Data = 10;
	n10->Left = NULL;
	n10->Right = NULL;
	n11->Data = 11;
	n11->Left = NULL;
	n11->Right = NULL;


	// Ʈ�� ��ȸ
	TreeNode *Head;

	// ������ȸ
	InitStack();
	Head = n1;
	printf("������ȸ\n");
	Push(Head);
	while(!IsStackEmpty()) {
		printf("%d ", *Head);
		if (Head->Right != NULL)
			Push(Head->Right);
		if (Head->Left != NULL)
			Head = Head->Left;
		else if (Head->Left == NULL && Head->Right == NULL) {
			Head = Pop();
		}
	}
	

	//������ȸ
	InitStack();
	Head = n1;

	printf("\n\n������ȸ\n");
	int Finish = 0;
	do {
		while (Head != NULL) {
			Push(Head);
			Head = Head->Left;
		}

		if (!IsStackEmpty()) {
			Head = Pop();
			printf("%d ", Head->Data);
			Head = Head->Right;
		}
		else
			Finish = 1;

	} while (!Finish);




	//������ȸ     // while���� ũ�� �ϳ��� �ƴ϶� 2���ε� ��������?
	InitStack();
	TreeNode *Root = n1;
	TreeNode *Head2;
	Head = n1;

	printf("\n\n������ȸ\n");
	// 4 5 3 6 2 7 1 ��
	do {
		Push(Head);
		if (Head->Right != NULL)
			Push(Head->Right);
		Head = Head->Left;

	} while (Head!=NULL);


	while (!IsStackEmpty()) {
		Head = Pop();
		printf("%d ", Head->Data);
		// pop�ϴ� �����߿� 2�� (root�� left)������ 
		if (Head == Root->Left) {
			Head2 = Root->Right; 
			while (Head2->Left!=NULL) {
				printf("%d ", Head2->Left->Data);
				Head2 = Head2->Right;
				if(Head2!=NULL) Push(Head2);
			}
			while (!IsStackEmpty()) {
				Head = Pop();
				printf("%d ", Head->Data);
			}
		}
		
	}

	Head = n1;
	printf("\n\n��ͷ� ������ȸ\n");
	Recursive_Traverse(Head);

}

void Visit(TreeNode * ptrNode)
{
	printf("%2d -> ", ptrNode->Data);
}

// ������ȸ
void Recursive_Traverse(TreeNode *ptrNode)
{
	if (ptrNode != NULL) {
		Recursive_Traverse(ptrNode->Left);
		Visit(ptrNode);
		Recursive_Traverse(ptrNode->Right);

	}
}
*/

/*
// 7��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;
//         15
//		  /   |
//	    4      20
//	   /       / |
//	  1       16  25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

// ������ȸ
void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);  // ���ʼ���Ʈ�� ��ȸ
		printf("%4d", root->data);   // ��� �湮
		inorder(root->right); // �����ʼ���Ʈ�� ��ȸ
	}
}

// ������ȸ
void preorder(TreeNode *root) {
	if (root) {
		printf("%4d", root->data);   // ��� �湮
		preorder(root->left);   // ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);  // �����ʼ���Ʈ�� ��ȸ
	}
}


// ������ȸ
void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);   // ���ʼ���Ʈ�� ��ȸ
		postorder(root->right);  // �����ʼ���Ʈ�� ��ȸ
		printf("%4d", root->data);   // ��� �湮
	}
}

void main()
{
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}
*/


/*
// 8��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _bTreeNode {
	int data;
	char name[20];
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

void InitNode(BTreeNode **ap) {
	*ap = (BTreeNode*)malloc(sizeof(BTreeNode));
}

void SetData(BTreeNode *ap, int data, char *name) {
	ap->data = data;
	strcpy(ap->name, name);
	ap->left = ap->right = NULL;
}

void MakeTree(BTreeNode **ap, int data, char *name) {
	BTreeNode *p, *t, *n;
	t = *ap;
	p = NULL;

	while (t != NULL) {
		if (data == t->data) return;   // �� �ߺ��� �� ����.
		p = t;
		if (data < t->data) t = t->left; 
		else t = t->right;   
	}  // ��带 ������ ������ ��ġ Ž��(t�� �Űܰ��鼭 ��尡 ���Ե� �� �ִ� null��ġ ã��. p�� ���� ������ ����� �θ��尡 �Ǵ°���)
	InitNode(&n);
	SetData(n, data, name);

	if (p != NULL) {
		if (data < p->data)
			p->left = n;    // ���λ����� ���� (p��-�θ���)���� ������ ���� �ڽ� ���� ����
		else
			p->right = n;   // ���λ����� ���� ũ�� ������ �ڽ� ���� ����
	}
	else
		*ap = n;
}


int GetData(BTreeNode * ap) {
	return ap->data;
}

// ������ȸ�� Ʈ�� ��ȸ�ϸ� ���
void disp(BTreeNode *p) {
	if (p != NULL) {
		disp(p->left);
		printf("%d %s \n", p->data, p->name);
		disp(p->right);
	}
}


char *search(BTreeNode *ap, int data) {
	BTreeNode *p = ap;
	while (p != NULL) {
		if (data == p->data) return p->name;
		if (data < p->data) p = p->left;
		else
			p = p->right;
	}
}

int main()
{
	int data, cho;
	char name[20];
	BTreeNode *ap = NULL;

	while (1) {
		printf("1. �Է�  2. ����Ʈ  3. �˻�  4. ����");
		scanf("%d", &cho);
		if (cho == 1) {
			printf("��ȣ:");
			scanf("%d", &data);
			printf("�̸�:");
			scanf("%s", &name);
			MakeTree(&ap, data, name);
		}
		if (cho == 2) {
			disp(ap);
		}
		if (cho == 3) {
			printf("�˻���ȣ: ");
			scanf("%d", &data);
			printf("==>%s\n", search(ap, data));
		}
		if (cho == 4) {
			break;
		}
	}
	return 0;
}
*/



// ����Ǯ�� 26������

/*
// 2��
// Ʈ���� �迭�� ���� 
#include<stdio.h>
struct tree {
	int index;
	int data;
};

void main()
{
	tree arr[20] = { NULL, };
	arr[1] = { 1,6 };
	arr[2] = { 2,4 };
	arr[3] = { 3,9 };
	arr[4] = { 4,2 };
	arr[5] = { 5,5 };
	arr[6] = { 6,7 };
	arr[7] = { 7,10 };
	arr[8] = { 8,1 };
	arr[9] = { 9,3 };
	arr[10] = { 10,8 };
	arr[11] = { 11,11 };

	int a;
	int level, dir;
	for (;;) {
		printf("\n1. ���˻�  2. ����\n");
		scanf("%d", &a);
		if (a == 1) {
			printf("�θ��� �ε��� : ");
			scanf("%d", &level);
			printf("���� �ڽ�/ ������ �ڽ� (0/1) : ");
			scanf("%d", &dir);
			if (dir == 0) printf("%d�� ���� �ڽ��� %d�Դϴ�\n", arr[level].data, arr[level * 2].data);
			else printf("%d�� ������ �ڽ��� %d�Դϴ�\n", arr[level].data, arr[level * 2 + 1].data);
			
		}
		else {
			printf("����Ǿ����ϴ�\n");
			break;
		}
	}


}
*/


/*
// 4��
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>

typedef struct TreeNode {
	int Data;
	struct TreeNode *Left, *Right;
}TreeNode;

void preorder(TreeNode *ptrNode);

void main()
{
	// Ʈ�� ��� ����
	TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	n4 = (TreeNode *)malloc(sizeof(TreeNode));
	n5 = (TreeNode *)malloc(sizeof(TreeNode));
	n6 = (TreeNode *)malloc(sizeof(TreeNode));
	n7 = (TreeNode *)malloc(sizeof(TreeNode));
	n8 = (TreeNode *)malloc(sizeof(TreeNode));
	n9 = (TreeNode *)malloc(sizeof(TreeNode));
	n10 = (TreeNode *)malloc(sizeof(TreeNode));

	n5->Data = 5;  // ��Ʈ��� node5
	n5->Left = n3;
	n5->Right = n7;
	n3->Data = 3;  // node3
	n3->Left = n2;
	n3->Right = n4;
	n2->Data = 2;   // node2
	n2->Left = n1;
	n2->Right = n8;
	n1->Data = 1;   // node1
	n1->Left = NULL;
	n1->Right = NULL;
	n8->Data = 8;    // node8
	n8->Left = NULL;
	n8->Right = NULL;
	n4->Data = 4;   // node4
	n4->Left = n10;
	n4->Right = NULL;
	n10->Data = 10;   // node10
	n10->Left = NULL;
	n10->Right = NULL;
	n7->Data = 7;    // node7
	n7->Left = n6;
	n7->Right = n9;
	n6->Data = 6;    // node6
	n6->Left = NULL;
	n6->Right = NULL;
	n9->Data = 9;    // node9
	n9->Left = NULL;
	n9->Right = NULL;


	// Ʈ�� ��ȸ
	TreeNode *Head;
	Head = n5;

	printf("������ȸ\n");
	preorder(Head);

}

// ������ȸ - ��ͻ��
void preorder(TreeNode *ptrNode) {
	if (ptrNode) {
		printf("%d -> ", ptrNode->Data);
		preorder(ptrNode->Left);
		preorder(ptrNode->Right);
	}
}
*/



/*
// 5��
#include<stdlib.h>
#include<memory.h>
#include "node.h"

void main()
{
	// Ʈ�� ��� ����
	TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	n4 = (TreeNode *)malloc(sizeof(TreeNode));
	n5 = (TreeNode *)malloc(sizeof(TreeNode));
	n6 = (TreeNode *)malloc(sizeof(TreeNode));
	n7 = (TreeNode *)malloc(sizeof(TreeNode));
	n8 = (TreeNode *)malloc(sizeof(TreeNode));
	n9 = (TreeNode *)malloc(sizeof(TreeNode));
	n10 = (TreeNode *)malloc(sizeof(TreeNode));

	n5->Data = 5;  // ��Ʈ��� node5
	n5->Left = n3;
	n5->Right = n7;
	n3->Data = 3;  // node3
	n3->Left = n2;
	n3->Right = n4;
	n2->Data = 2;   // node2
	n2->Left = n1;
	n2->Right = n8;
	n1->Data = 1;   // node1
	n1->Left = NULL;
	n1->Right = NULL;
	n8->Data = 8;    // node8
	n8->Left = NULL;
	n8->Right = NULL;
	n4->Data = 4;   // node4
	n4->Left = n10;
	n4->Right = NULL;
	n10->Data = 10;   // node10
	n10->Left = NULL;
	n10->Right = NULL;
	n7->Data = 7;    // node7
	n7->Left = n6;
	n7->Right = n9;
	n6->Data = 6;    // node6
	n6->Left = NULL;
	n6->Right = NULL;
	n9->Data = 9;    // node9
	n9->Left = NULL;
	n9->Right = NULL;


	// Ʈ�� ��ȸ
	TreeNode *Head;

	// ������ȸ - ���û�� (6���� ���پ�)
	InitStack();
	Head = n5; // ��Ʈ���

	printf("������ȸ\n");
	int Finish = 0;
	do {
		while (Head != NULL) {
			Push(Head);
			Head = Head->Left;
		}

		if (!IsStackEmpty()) {
			Head = Pop();
			printf("%d ", Head->Data);
			Head = Head->Right;
		}
		else
			Finish = 1;

	} while (!Finish);
}
*/


/*
// 6��
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>

typedef struct TreeNode {
	int Data;
	struct TreeNode *Left, *Right;
}TreeNode;

void postorder(TreeNode *ptrNode);

void main()
{
	// Ʈ�� ��� ����
	TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	n4 = (TreeNode *)malloc(sizeof(TreeNode));
	n5 = (TreeNode *)malloc(sizeof(TreeNode));
	n6 = (TreeNode *)malloc(sizeof(TreeNode));
	n7 = (TreeNode *)malloc(sizeof(TreeNode));
	n8 = (TreeNode *)malloc(sizeof(TreeNode));
	n9 = (TreeNode *)malloc(sizeof(TreeNode));
	n10 = (TreeNode *)malloc(sizeof(TreeNode));

	n5->Data = 5;  // ��Ʈ��� node5
	n5->Left = n3;
	n5->Right = n7;
	n3->Data = 3;  // node3
	n3->Left = n2;
	n3->Right = n4;
	n2->Data = 2;   // node2
	n2->Left = n1;
	n2->Right = n8;
	n1->Data = 1;   // node1
	n1->Left = NULL;
	n1->Right = NULL;
	n8->Data = 8;    // node8
	n8->Left = NULL;
	n8->Right = NULL;
	n4->Data = 4;   // node4
	n4->Left = n10;
	n4->Right = NULL;
	n10->Data = 10;   // node10
	n10->Left = NULL;
	n10->Right = NULL;
	n7->Data = 7;    // node7
	n7->Left = n6;
	n7->Right = n9;
	n6->Data = 6;    // node6
	n6->Left = NULL;
	n6->Right = NULL;
	n9->Data = 9;    // node9
	n9->Left = NULL;
	n9->Right = NULL;


	// Ʈ�� ��ȸ
	TreeNode *Head;
	Head = n5;

	printf("������ȸ\n");
	postorder(Head);

}

// ������ȸ - ��ͻ��
void postorder(TreeNode *ptrNode) {
	if (ptrNode) {
		postorder(ptrNode->Left);
		postorder(ptrNode->Right);
		printf("%d -> ", ptrNode->Data);
	}
}
*/

