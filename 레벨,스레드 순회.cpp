

/*

// 1��
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "CircularQueue.h"

static QueueType q;

void level_order(TreeNode *ptrNode) {
	enqueue(&q, ptrNode);
	while (!is_empty(&q)) {
		ptrNode = dequeue(&q);
		printf("%c -> ", ptrNode->Data);
		if (ptrNode->Left != NULL) {
			enqueue(&q,ptrNode->Left);
		}
		if (ptrNode->Right != NULL) {
			enqueue(&q, ptrNode->Right);
		}
	}

}

int main()
{
	init(&q);

	TreeNode n1 = { '1', NULL, NULL };
	TreeNode n2 = { '4', NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { '6', NULL, NULL };
	TreeNode n5 = { '5', NULL, NULL };
	TreeNode n6 = { '+', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 };  // ��Ʈ
	TreeNode *exp = &n7;
	level_order(exp);
}


*/



/*
// ������ ����Ʈ��
#include<stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread;   // ������ �� ����(0/1)
}TreeNode;

//             G
//     C               F
//  A     B         D      E

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode *exp = &n7;

TreeNode *find_thread_successor(TreeNode *p)
{
	TreeNode *q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;
	while (q->left != NULL) q = q->left;
	return q;
}
void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	q = t;
	while (q->left) q = q->left;
	do
	{
		printf("%c ", q->data);
		q = find_thread_successor(q);
	} while (q);
}

void main()
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	thread_inorder(exp);
}
*/


/*
// ���� Ʈ�� ��ȸ�� ����
// 5������ 1��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;
//           +
//     *          +
//   1   4      16  25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode *exp = &n7;

//���� ��� �Լ�
int evaluate(TreeNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}
void main()
{
	TreeNode *root;
	printf("%d", evaluate(exp));
}
*/


/*
// 7������ 2�� - ���丮 �뷮 ���
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int calc_direc_size(TreeNode *root)
{
	int left_size, right_size;
	if (root) {
		left_size = calc_direc_size(root->left);
		right_size = calc_direc_size(root->right);
		return (root->data + left_size + right_size);
	}
	else return 0;
}
//  <���� ����>
//       0
//    /     |
//   50     100
//          /  |
//        500  200

void main()
{
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("���丮�� ũ�� = %d\n", calc_direc_size(&n1));
	// ������   ���丮�� ũ�� = 850
}
*/



/*
// ����Ǯ�� 10������
// 1��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
}TreeNode;
//           -
//     *          /
//   A   B      C  D
TreeNode n1 = { 'A', NULL, NULL };
TreeNode n2 = { 'B', NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 'C', NULL, NULL };
TreeNode n5 = { 'D', NULL, NULL };
TreeNode n6 = { '/', &n4, &n5 };
TreeNode n7 = { '-', &n3, &n6 };
TreeNode *exp = &n7;

void preorder(TreeNode *ptrNode)
{
	if (ptrNode) {
		printf("%c", ptrNode->data);
		preorder(ptrNode->left);
		preorder(ptrNode->right);
	}
}

void inorder(TreeNode *ptrNode)
{
	if (ptrNode) {
		inorder(ptrNode->left);
		printf("%c", ptrNode->data);
		inorder(ptrNode->right);
	}
}

void postorder(TreeNode *ptrNode)
{
	if (ptrNode) {
		postorder(ptrNode->left);
		postorder(ptrNode->right);
		printf("%c", ptrNode->data);
	}
}

void main()
{
	printf("preorder : ");
	preorder(exp);

	printf("\ninorder : ");
	inorder(exp);

	printf("\npostorder : ");
	postorder(exp);

	printf("\n\n");
}
*/


/*
// 2��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	char data;
	struct TreeNode *left, *right;
	int thread;
}TreeNode;
//           -
//     *          /
//   A   B      C  D
TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL , 1};
TreeNode n3 = { '*', &n1, &n2, 0 };
TreeNode n4 = { 'C', NULL, NULL, 1 };
TreeNode n5 = { 'D', NULL, NULL, 0 };
TreeNode n6 = { '/', &n4, &n5, 0 };
TreeNode n7 = { '-', &n3, &n6, 0 };
TreeNode *exp = &n7;

TreeNode *find_thread_successor(TreeNode *p)
{
	TreeNode *q = p->right;
	if (q == NULL || p->thread == 1)
		return q;
	while (q->left != NULL) q = q->left;
	return q;
}
void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	q = t;
	while (q->left) q = q->left;
	do
	{
		printf("%c ", q->data);
		q = find_thread_successor(q);
	} while (q);
}

void main()
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	
	printf("������ ���� Ʈ���� ���� ��ȸ : ");
	thread_inorder(exp);
	printf("\n\n");
}
*/


