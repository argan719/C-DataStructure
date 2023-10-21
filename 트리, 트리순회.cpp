

// 2022 / 04 / 29
// C++ 끝내고 자료구조 다시 시작
// 트리 처음부터 시작 (트리 완전히 처음 배우는 것처럼 트리부터 자료구조 시작)








/*
// 6번
// 이진 트리를 링크로 표현하여 봅시다.
// 전위, 중위, 후위순회 스택으로 구현

#include<stdlib.h>
#include<memory.h>
#include"node.h"
#define MAX 100
#define TRUE 1
#define FALSE 0
// stack(트리).cpp 

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
	// 트리 노드 생성
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

	n1->Data = 1;    // 첫 번째 노트를 설정한다.
	n1->Left = n2; 
	n1->Right = n7;
	n2->Data = 2;    // 두 번째 노드를 설정한다.
	n2->Left = n3;
	n2->Right = n6;
	n3->Data = 3;    // 세 번째 노드를 설정한다.
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


	// 트리 순회
	TreeNode *Head;

	// 전위순회
	InitStack();
	Head = n1;
	printf("전위순회\n");
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
	

	//중위순회
	InitStack();
	Head = n1;

	printf("\n\n중위순회\n");
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




	//후위순회     // while문이 크게 하나가 아니라 2개인데 괜찮은지?
	InitStack();
	TreeNode *Root = n1;
	TreeNode *Head2;
	Head = n1;

	printf("\n\n후위순회\n");
	// 4 5 3 6 2 7 1 들어감
	do {
		Push(Head);
		if (Head->Right != NULL)
			Push(Head->Right);
		Head = Head->Left;

	} while (Head!=NULL);


	while (!IsStackEmpty()) {
		Head = Pop();
		printf("%d ", Head->Data);
		// pop하는 과정중에 2를 (root의 left)만나면 
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
	printf("\n\n재귀로 전위순회\n");
	Recursive_Traverse(Head);

}

void Visit(TreeNode * ptrNode)
{
	printf("%2d -> ", ptrNode->Data);
}

// 중위순회
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
// 7번
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

// 중위순회
void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);  // 왼쪽서브트리 순회
		printf("%4d", root->data);   // 노드 방문
		inorder(root->right); // 오른쪽서브트리 순회
	}
}

// 전위순회
void preorder(TreeNode *root) {
	if (root) {
		printf("%4d", root->data);   // 노드 방문
		preorder(root->left);   // 왼쪽서브트리 순회
		preorder(root->right);  // 오른쪽서브트리 순회
	}
}


// 후위순회
void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);   // 왼쪽서브트리 순회
		postorder(root->right);  // 오른쪽서브트리 순회
		printf("%4d", root->data);   // 노드 방문
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
// 8번
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
		if (data == t->data) return;   // 값 중복될 수 없음.
		p = t;
		if (data < t->data) t = t->left; 
		else t = t->right;   
	}  // 노드를 삽입할 적당한 위치 탐색(t를 옮겨가면서 노드가 삽입될 수 있는 null위치 찾음. p는 새로 삽입할 노드의 부모노드가 되는거임)
	InitNode(&n);
	SetData(n, data, name);

	if (p != NULL) {
		if (data < p->data)
			p->left = n;    // 새로삽입한 값이 (p값-부모노드)보다 작으면 왼쪽 자식 노드로 삽입
		else
			p->right = n;   // 새로삽입한 값이 크면 오른쪽 자식 노드로 삽입
	}
	else
		*ap = n;
}


int GetData(BTreeNode * ap) {
	return ap->data;
}

// 중위순회로 트리 순회하며 출력
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
		printf("1. 입력  2. 리스트  3. 검색  4. 종료");
		scanf("%d", &cho);
		if (cho == 1) {
			printf("번호:");
			scanf("%d", &data);
			printf("이름:");
			scanf("%s", &name);
			MakeTree(&ap, data, name);
		}
		if (cho == 2) {
			disp(ap);
		}
		if (cho == 3) {
			printf("검색번호: ");
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



// 문제풀이 26페이지

/*
// 2번
// 트리를 배열로 구현 
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
		printf("\n1. 값검색  2. 종료\n");
		scanf("%d", &a);
		if (a == 1) {
			printf("부모노드 인덱스 : ");
			scanf("%d", &level);
			printf("왼쪽 자식/ 오른쪽 자식 (0/1) : ");
			scanf("%d", &dir);
			if (dir == 0) printf("%d의 왼쪽 자식은 %d입니다\n", arr[level].data, arr[level * 2].data);
			else printf("%d의 오른쪽 자식은 %d입니다\n", arr[level].data, arr[level * 2 + 1].data);
			
		}
		else {
			printf("종료되었습니다\n");
			break;
		}
	}


}
*/


/*
// 4번
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
	// 트리 노드 생성
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

	n5->Data = 5;  // 루트노드 node5
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


	// 트리 순회
	TreeNode *Head;
	Head = n5;

	printf("전위순회\n");
	preorder(Head);

}

// 전위순회 - 재귀사용
void preorder(TreeNode *ptrNode) {
	if (ptrNode) {
		printf("%d -> ", ptrNode->Data);
		preorder(ptrNode->Left);
		preorder(ptrNode->Right);
	}
}
*/



/*
// 5번
#include<stdlib.h>
#include<memory.h>
#include "node.h"

void main()
{
	// 트리 노드 생성
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

	n5->Data = 5;  // 루트노드 node5
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


	// 트리 순회
	TreeNode *Head;

	// 중위순회 - 스택사용 (6번꺼 갖다씀)
	InitStack();
	Head = n5; // 루트노드

	printf("중위순회\n");
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
// 6번
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
	// 트리 노드 생성
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

	n5->Data = 5;  // 루트노드 node5
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


	// 트리 순회
	TreeNode *Head;
	Head = n5;

	printf("후위순회\n");
	postorder(Head);

}

// 후위순회 - 재귀사용
void postorder(TreeNode *ptrNode) {
	if (ptrNode) {
		postorder(ptrNode->Left);
		postorder(ptrNode->Right);
		printf("%d -> ", ptrNode->Data);
	}
}
*/

