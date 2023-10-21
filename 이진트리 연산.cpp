
/*
// 1번
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int getcount(TreeNode *ptrNode) 
{// 두가지 방법 (sum변수를 사용하든가, 안하든가)

	// 1)
	//if (ptrNode == NULL) return 0;
	//return 1 + getcount(ptrNode->left) + getcount(ptrNode->right);

	// 2)
	int sum = 0;
	if (ptrNode) {
		sum = 1 + getcount(ptrNode->left) + getcount(ptrNode->right);
	}
	return sum;
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
	n11 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 1;    // 첫 번째 노트를 설정한다.
	n1->left = n2;
	n1->right = n7;
	n2->data = 2;    // 두 번째 노드를 설정한다.
	n2->left = n3;
	n2->right = n6;
	n3->data = 3;    // 세 번째 노드를 설정한다.
	n3->left = n4;
	n3->right = n5;
	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;
	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	n7->data = 7;
	n7->left = n8;
	n7->right = n9;
	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;
	n9->data = 9;
	n9->left = n10;
	n9->right = n11;
	n10->data = 10;
	n10->left = NULL;
	n10->right = NULL;
	n11->data = 11;
	n11->left = NULL;
	n11->right = NULL;
	// 총 노드 11개
	// 총 단말노드 6개

	// 트리 순회
	TreeNode *Head;
	Head = n1;

	printf("총 노드 개수 : %d \n", getcount(Head));
}
*/


/*
// 2번
// 자식노드가 없는 이진트리 단말 노드 개수 카운트
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int getcount(TreeNode * ptrNode) 
{
	int sum = 0;
	if (ptrNode) {
		if (ptrNode->left == NULL && ptrNode->right == NULL) return 1;
		else
			sum = getcount(ptrNode->left) + getcount(ptrNode->right);
	}
	return sum;
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
	n11 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 1;    // 첫 번째 노트를 설정한다.
	n1->left = n2;
	n1->right = n7;
	n2->data = 2;    // 두 번째 노드를 설정한다.
	n2->left = n3;
	n2->right = n6;
	n3->data = 3;    // 세 번째 노드를 설정한다.
	n3->left = n4;
	n3->right = n5;
	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;
	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	n7->data = 7;
	n7->left = n8;
	n7->right = n9;
	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;
	n9->data = 9;
	n9->left = n10;
	n9->right = n11;
	n10->data = 10;
	n10->left = NULL;
	n10->right = NULL;
	n11->data = 11;
	n11->left = NULL;
	n11->right = NULL;


	// 트리 순회
	TreeNode *Head;
	Head = n1;

	printf("단말 노드 개수 : %d \n", getcount(Head));
}
*/



/*
// 3번  - 트리의 높이 구하기
// 3번까지 해결하고 
// 노드의 삽입삭제 건너뛰고 16페이지 문제풀이 4개 다 해오기

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int high(int n1, int n2) {
	return (n1 > n2) ? n1: n2;
}

int get_height(TreeNode *ptrNode)
{
	int height = 0;
	if (ptrNode) {
		height = 1 + high(get_height(ptrNode->left), get_height(ptrNode->right));
	}
	return height;
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
	n11 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 1;    // 첫 번째 노트를 설정한다.
	n1->left = n2;
	n1->right = n7;
	n2->data = 2;    // 두 번째 노드를 설정한다.
	n2->left = n3;
	n2->right = n6;
	n3->data = 3;    // 세 번째 노드를 설정한다.
	n3->left = n4;
	n3->right = n5;
	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;
	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	n7->data = 7;
	n7->left = n8;
	n7->right = n9;
	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;
	n9->data = 9;
	n9->left = n10;
	n9->right = n11;
	n10->data = 10;
	n10->left = NULL;
	n10->right = NULL;
	n11->data = 11;
	n11->left = NULL;
	n11->right = NULL;


	// 트리 순회
	TreeNode *Head;
	Head = n1;

	printf("트리의 높이 : %d \n", get_height(Head));
}
*/






/*
// 문제풀이 16페이지
// 1번
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode n6 = { 6, NULL, NULL };
TreeNode n7 = { 9, NULL, NULL };
TreeNode n8 = { 1, NULL, NULL };
TreeNode n9 = { 8, NULL, NULL };
TreeNode n10 = { 10, NULL, NULL };
TreeNode n4 = { 2, &n8,  &n9 };
TreeNode n5 = { 4, &n10, NULL };
TreeNode n2 = { 3, &n4, &n5 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n1 = { 5, &n2, &n3 };
TreeNode *Head = &n1;

int getcount(TreeNode *node) {
	if (node == NULL) return 0;
	return 1 + getcount(node->left) + getcount(node->right);
}

void main()
{
	printf("노드의 개수 = %d \n", getcount(Head));
}
*/


/*
// 2번
// 자식이 하나만 있는 노드의 개수

#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode n6 = { 6, NULL, NULL };
TreeNode n7 = { 9, NULL, NULL };
TreeNode n8 = { 1, NULL, NULL };
TreeNode n9 = { 8, NULL, NULL };
TreeNode n10 = { 10, NULL, NULL };
TreeNode n4 = { 2, &n8,  &n9 };
TreeNode n5 = { 4, &n10, NULL };
TreeNode n2 = { 3, &n4, &n5 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n1 = { 5, &n2, &n3 };
TreeNode *Head = &n1;
//                5
//            /       |
//          3          7
//       /     |      /   |
//      2      4     6     9
//    /  |    /     
//   1   8   10


int getcount(TreeNode *node) {
	int sum = 0;
	if (node) {
		if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) return 1;
		else
			sum = getcount(node->left) + getcount(node->right);
	}
	return sum;
}

void main()
{
	printf("자식이 하나인 노드의 개수 = %d \n", getcount(Head));     // 실행결과 1
}
*/


/*
// 3번 
// 자식이 둘인 노드의 개수

#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode n6 = { 6, NULL, NULL };
TreeNode n7 = { 9, NULL, NULL };
TreeNode n8 = { 1, NULL, NULL };
TreeNode n9 = { 8, NULL, NULL };
TreeNode n10 = { 10, NULL, NULL };
TreeNode n4 = { 2, &n8,  &n9 };
TreeNode n5 = { 4, &n10, NULL };
TreeNode n2 = { 3, &n4, &n5 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n1 = { 5, &n2, &n3 };
TreeNode *Head = &n1;

int getcount(TreeNode *node) {
	int sum = 0;
	if (node) {
		sum = getcount(node->left) + getcount(node->right);
		if (node->left != NULL && node->right != NULL) return sum + 1;
	}
	return sum;
}


void main()
{
	printf("자식이 둘인 노드의 개수 = %d \n", getcount(Head));     // 실행결과  4
}
*/



/*
// 4번
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode n6 = { 6, NULL, NULL };
TreeNode n7 = { 9, NULL, NULL };
TreeNode n8 = { 1, NULL, NULL };
TreeNode n9 = { 8, NULL, NULL };
TreeNode n10 = { 10, NULL, NULL };
TreeNode n4 = { 2, &n8,  &n9 };
TreeNode n5 = { 4, &n10, NULL };
TreeNode n2 = { 3, &n4, &n5 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n1 = { 5, &n2, &n3 };
TreeNode *Head = &n1;

void traverese(TreeNode *node, int &max, int &min) {
	if (node) {
		if (node->data > max) max = node->data;
		else if (node->data < min) min = node->data;
		traverese(node->left, max, min);
		traverese(node->right, max, min);
	}
}

void main()
{
	int max = Head->data, min = Head->data;
	traverese(Head, max, min);
	printf("큰값 = %d   작은값 = %d  \n", max, min);
}
*/






/*
// 이진탐색트리 구현
// 이진트리 삽입, 삭제 연산


#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 2. 순회 (전위순회로 출력)
void Traverse(TreeNode *node) {
	if (node) {
		printf("%d -> ", node->data);
		Traverse(node->left);
		Traverse(node->right);
	}
}


// 1. 입력 - 삽입
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// 왼쪽으로 이동
		if (node->data > newNode->data) {
			if(node->left != NULL) node = node->left;
			else {  node->left = newNode;  break; }
		} // 오른쪽으로 이동
		else if (node->data < newNode->data) {
			if(node->right!=NULL) node = node->right;
			else { node->right = newNode; break; }
		}
		else break;
	}
}
// 1. 입력
void insert() {
	TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));
	tmp->left = NULL;
	tmp->right = NULL;
	printf("삽입할 노드의 정수값 입력 : ");
	scanf("%d", &tmp->data);
	if (Head == NULL) {
		Head = tmp;
	}
	else traverse_for_insert(Head, tmp);
}


// 3. 삭제 - 삭제할 노드 찾기
void traverse_for_delete(TreeNode *node, int key, TreeNode **search) {
	if (node) {
		if (node->data == key) *search = node;
		traverse_for_delete(node->left, key, search);
		traverse_for_delete(node->right, key, search);
	}
	
}

// 3. 삭제 연산진행 - 1. 자식노드가 없는 경우  - 부모노드 찾기
void find_parent_no_child(TreeNode *node, TreeNode *key) {  // Head, 삭제할노드
	if (node) {
		if (Head == key) {       // 삭제할 노드가 루트노드인 경우
			Head = NULL;
			printf("%d (root)노드 삭제완료.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) { 
			if(node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("%d 노드 삭제완료.\n", key->data);
			return;
		}
		find_parent_no_child(node->left, key);
		find_parent_no_child(node->right, key);
	}
}
// 3. 삭제 연산진행 -  2. 자식노드가 하나인 경우 - 부모노드 찾기
void find_parent_one_child(TreeNode *node, TreeNode *key, TreeNode *child) {  // Head, 삭제할노드, 삭제할노드의 자식노드
	if (node) {
		if (Head == key) {       // 삭제할 노드가 루트노드인 경우
			Head = child;
			printf("%d (root)노드 삭제완료.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("%d 노드 삭제완료.\n", key->data);
			return;
		}
		find_parent_one_child(node->left, key, child);
		find_parent_one_child(node->right, key, child);
	}
}
// 3. 삭제 연산진행 -  3. 자식노드가 둘인 경우 - 부모노드 찾기
void find_parent_two_child(TreeNode *node, TreeNode *key) {  // Head, 삭제할노드
	TreeNode *tmp, *before;
	int flag = 0;
	if (node) {
		if (Head == key) {        // 삭제할 노드가 루트노드인 경우
			tmp = key->right;  // right 한번 이동
			before = tmp;
			while (tmp->left != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->left;   // left로 끝까지 이동
			}
			if (flag == 1) {
				before->left = tmp->right;
				tmp->right = Head->right;
			}
			tmp->left = Head->left;
			Head = tmp;

			printf("%d (root)노드 삭제완료.\n", key->data);
			return;
		}

		if (node->left == key || node->right == key) {
			tmp = key->right;  // right 한번 이동
			before = tmp;
			while (tmp->left != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->left;   // left로 끝까지 이동
			}
			if (node->left == key) { node->left = tmp; tmp->left = key->left; }
			else { node->right = tmp;  tmp->left = key->left; }

			if (flag == 1) {
				before->left = tmp->right;
				tmp->right = key->right;  
			}
			printf("%d 노드 삭제완료.\n", key->data);
			return;
		}
		find_parent_two_child(node->left, key);
		find_parent_two_child(node->right, key);
	}
}


// 3. 삭제
void remove() {
	int val; // 삭제할값
	TreeNode *key = NULL;  // 삭제할 노드 
	printf("삭제할 키값을 입력하시오 : ");
	scanf("%d", &val);
	traverse_for_delete(Head, val, &key);
	if (key == NULL) printf("입력하신 키값이 존재하지 않습니다.\n");
	else {
		//printf("찾았습니다!  %d", key->data);
		// 1. 자식노드가 없는 경우(단말노드인 경우)
		if (key->left == NULL && key->right == NULL) {
			find_parent_no_child(Head, key);
		}
		// 2. 자식노드가 하나인 경우
		else if ((key->left != NULL && key->right == NULL) || (key->left == NULL && key->right != NULL)) {
			if (key->left != NULL ) // 왼쪽 자식인 경우
				find_parent_one_child(Head, key, key->left);
			else  // 오른쪽 자식인 경우
				find_parent_one_child(Head, key, key->right);
		}
		// 3. 자식노드가 둘인 경우
		else if (key->left != NULL && key->right != NULL) {
			find_parent_two_child(Head, key);
		}
	}
}

void main()
{
	int n;

	for (;;) {
		printf("\n=== 메뉴 ===\n");
		printf("1. 삽입\n");
		printf("2. 순회\n");
		printf("3. 삭제\n");
		printf("4. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			Traverse(Head);
		}
		else if (n == 3) {
			remove();
		}
		else { printf("종료되었습니다.\n"); break; }
	}

}


*/
