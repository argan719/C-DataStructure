
/*
// 1��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int getcount(TreeNode *ptrNode) 
{// �ΰ��� ��� (sum������ ����ϵ簡, ���ϵ簡)

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
	n11 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 1;    // ù ��° ��Ʈ�� �����Ѵ�.
	n1->left = n2;
	n1->right = n7;
	n2->data = 2;    // �� ��° ��带 �����Ѵ�.
	n2->left = n3;
	n2->right = n6;
	n3->data = 3;    // �� ��° ��带 �����Ѵ�.
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
	// �� ��� 11��
	// �� �ܸ���� 6��

	// Ʈ�� ��ȸ
	TreeNode *Head;
	Head = n1;

	printf("�� ��� ���� : %d \n", getcount(Head));
}
*/


/*
// 2��
// �ڽĳ�尡 ���� ����Ʈ�� �ܸ� ��� ���� ī��Ʈ
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
	n11 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 1;    // ù ��° ��Ʈ�� �����Ѵ�.
	n1->left = n2;
	n1->right = n7;
	n2->data = 2;    // �� ��° ��带 �����Ѵ�.
	n2->left = n3;
	n2->right = n6;
	n3->data = 3;    // �� ��° ��带 �����Ѵ�.
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


	// Ʈ�� ��ȸ
	TreeNode *Head;
	Head = n1;

	printf("�ܸ� ��� ���� : %d \n", getcount(Head));
}
*/



/*
// 3��  - Ʈ���� ���� ���ϱ�
// 3������ �ذ��ϰ� 
// ����� ���Ի��� �ǳʶٰ� 16������ ����Ǯ�� 4�� �� �ؿ���

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
	n11 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 1;    // ù ��° ��Ʈ�� �����Ѵ�.
	n1->left = n2;
	n1->right = n7;
	n2->data = 2;    // �� ��° ��带 �����Ѵ�.
	n2->left = n3;
	n2->right = n6;
	n3->data = 3;    // �� ��° ��带 �����Ѵ�.
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


	// Ʈ�� ��ȸ
	TreeNode *Head;
	Head = n1;

	printf("Ʈ���� ���� : %d \n", get_height(Head));
}
*/






/*
// ����Ǯ�� 16������
// 1��
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
	printf("����� ���� = %d \n", getcount(Head));
}
*/


/*
// 2��
// �ڽ��� �ϳ��� �ִ� ����� ����

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
	printf("�ڽ��� �ϳ��� ����� ���� = %d \n", getcount(Head));     // ������ 1
}
*/


/*
// 3�� 
// �ڽ��� ���� ����� ����

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
	printf("�ڽ��� ���� ����� ���� = %d \n", getcount(Head));     // ������  4
}
*/



/*
// 4��
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
	printf("ū�� = %d   ������ = %d  \n", max, min);
}
*/






/*
// ����Ž��Ʈ�� ����
// ����Ʈ�� ����, ���� ����


#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 2. ��ȸ (������ȸ�� ���)
void Traverse(TreeNode *node) {
	if (node) {
		printf("%d -> ", node->data);
		Traverse(node->left);
		Traverse(node->right);
	}
}


// 1. �Է� - ����
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// �������� �̵�
		if (node->data > newNode->data) {
			if(node->left != NULL) node = node->left;
			else {  node->left = newNode;  break; }
		} // ���������� �̵�
		else if (node->data < newNode->data) {
			if(node->right!=NULL) node = node->right;
			else { node->right = newNode; break; }
		}
		else break;
	}
}
// 1. �Է�
void insert() {
	TreeNode *tmp = (TreeNode *)malloc(sizeof(TreeNode));
	tmp->left = NULL;
	tmp->right = NULL;
	printf("������ ����� ������ �Է� : ");
	scanf("%d", &tmp->data);
	if (Head == NULL) {
		Head = tmp;
	}
	else traverse_for_insert(Head, tmp);
}


// 3. ���� - ������ ��� ã��
void traverse_for_delete(TreeNode *node, int key, TreeNode **search) {
	if (node) {
		if (node->data == key) *search = node;
		traverse_for_delete(node->left, key, search);
		traverse_for_delete(node->right, key, search);
	}
	
}

// 3. ���� �������� - 1. �ڽĳ�尡 ���� ���  - �θ��� ã��
void find_parent_no_child(TreeNode *node, TreeNode *key) {  // Head, �����ҳ��
	if (node) {
		if (Head == key) {       // ������ ��尡 ��Ʈ����� ���
			Head = NULL;
			printf("%d (root)��� �����Ϸ�.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) { 
			if(node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("%d ��� �����Ϸ�.\n", key->data);
			return;
		}
		find_parent_no_child(node->left, key);
		find_parent_no_child(node->right, key);
	}
}
// 3. ���� �������� -  2. �ڽĳ�尡 �ϳ��� ��� - �θ��� ã��
void find_parent_one_child(TreeNode *node, TreeNode *key, TreeNode *child) {  // Head, �����ҳ��, �����ҳ���� �ڽĳ��
	if (node) {
		if (Head == key) {       // ������ ��尡 ��Ʈ����� ���
			Head = child;
			printf("%d (root)��� �����Ϸ�.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("%d ��� �����Ϸ�.\n", key->data);
			return;
		}
		find_parent_one_child(node->left, key, child);
		find_parent_one_child(node->right, key, child);
	}
}
// 3. ���� �������� -  3. �ڽĳ�尡 ���� ��� - �θ��� ã��
void find_parent_two_child(TreeNode *node, TreeNode *key) {  // Head, �����ҳ��
	TreeNode *tmp, *before;
	int flag = 0;
	if (node) {
		if (Head == key) {        // ������ ��尡 ��Ʈ����� ���
			tmp = key->right;  // right �ѹ� �̵�
			before = tmp;
			while (tmp->left != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->left;   // left�� ������ �̵�
			}
			if (flag == 1) {
				before->left = tmp->right;
				tmp->right = Head->right;
			}
			tmp->left = Head->left;
			Head = tmp;

			printf("%d (root)��� �����Ϸ�.\n", key->data);
			return;
		}

		if (node->left == key || node->right == key) {
			tmp = key->right;  // right �ѹ� �̵�
			before = tmp;
			while (tmp->left != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->left;   // left�� ������ �̵�
			}
			if (node->left == key) { node->left = tmp; tmp->left = key->left; }
			else { node->right = tmp;  tmp->left = key->left; }

			if (flag == 1) {
				before->left = tmp->right;
				tmp->right = key->right;  
			}
			printf("%d ��� �����Ϸ�.\n", key->data);
			return;
		}
		find_parent_two_child(node->left, key);
		find_parent_two_child(node->right, key);
	}
}


// 3. ����
void remove() {
	int val; // �����Ұ�
	TreeNode *key = NULL;  // ������ ��� 
	printf("������ Ű���� �Է��Ͻÿ� : ");
	scanf("%d", &val);
	traverse_for_delete(Head, val, &key);
	if (key == NULL) printf("�Է��Ͻ� Ű���� �������� �ʽ��ϴ�.\n");
	else {
		//printf("ã�ҽ��ϴ�!  %d", key->data);
		// 1. �ڽĳ�尡 ���� ���(�ܸ������ ���)
		if (key->left == NULL && key->right == NULL) {
			find_parent_no_child(Head, key);
		}
		// 2. �ڽĳ�尡 �ϳ��� ���
		else if ((key->left != NULL && key->right == NULL) || (key->left == NULL && key->right != NULL)) {
			if (key->left != NULL ) // ���� �ڽ��� ���
				find_parent_one_child(Head, key, key->left);
			else  // ������ �ڽ��� ���
				find_parent_one_child(Head, key, key->right);
		}
		// 3. �ڽĳ�尡 ���� ���
		else if (key->left != NULL && key->right != NULL) {
			find_parent_two_child(Head, key);
		}
	}
}

void main()
{
	int n;

	for (;;) {
		printf("\n=== �޴� ===\n");
		printf("1. ����\n");
		printf("2. ��ȸ\n");
		printf("3. ����\n");
		printf("4. ����\n");
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
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}

}


*/
