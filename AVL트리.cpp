


// 11������ 1��

/*
// AVLƮ���� ���Կ����� �����Ͽ� ���ô�

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	int height;   // ���̸� �����ؾ� �ð� ���⵵�� ������ �� ����
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


// �ִ밪ã�� �Լ�
int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

// ���� ���ϴ� �Լ�
int getHeight(Node *node) {
	if (node == NULL) return 0;
	return node -> height;
}

// ��� ���� ȸ���� ������ ���Ŀ� ���� ����
void setHeight(Node *node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

// ���� �μ� ��� �Լ�
int getDifference(Node *node) {
	if (node == NULL) return 0;
	return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// LL ȸ��
Node* rotateLL(Node * node) {
	puts("LL");
	Node *tmp = node->leftChild;
	node->leftChild = tmp->rightChild;
	tmp->rightChild = node;
	setHeight(node);  // ȸ�� ���� ���� �ٽ� ���
	return tmp;
}

// RR ȸ��
Node* rotateRR(Node *node) {
	puts("RR");
	Node *tmp = node->rightChild;
	node->rightChild = tmp->leftChild;
	tmp->leftChild = node;
	setHeight(node);  // ȸ�� ���� ���� �ٽ� ���
	return tmp;
}

// LR ȸ��
Node* rotateLR(Node *node) {
	puts("LR");
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

// RL ȸ��
Node* rotateRL(Node *node) {
	puts("RL");
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}


// ���� ���
Node *balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		// LL, LR ���� �Ǻ� �� ���� ���
		if (getDifference(node->leftChild) >= 1) { // ����� LL, ������ LR
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		// RR, RL ���� �Ǻ� �� ���� ���
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);  // ȸ�� ���� ���� ����
	return node;
}


// ���� �Լ�
Node* insertNode(Node *node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	// ���� �� �׻� ���� ��� ����
	else if (data < node->data) {  // ������ ��尡 �� ���� ��� - ���� ����Ʈ���� ����
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {  // ������ ��尡 �� ū ��� - ������ ����Ʈ���� ����
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {  // Ű�� �ߺ� ���x
		printf("������ �ߺ� �߻�");
	}
	return node;
}


// ��� �Լ�
Node *root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		// ���� ���� ������ �湮
		display(node->rightChild, level + 1);
		printf("\n");

		if (node == root) {
			printf("ROOT : ");
		}

		for (int i = 0; i < level && node != root; i++) {
			printf("    ");
		}
		printf("%d(%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}

int main(void) {
	int n;
	while (true)
	{
		printf("�Է� : ");
		scanf("%d", &n);
		root = insertNode(root, n);
		display(root, 1);
		printf("\n");
	}
	return 0;
}
*/





// ����Ǯ�� 16������
/*
// 5��
// ���� �ٸ� 100���� ���� ������ �߻����� AVLƮ���� ����, Ʈ�� ���� ����

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Node {
	int data;
	int height;   // ���̸� �����ؾ� �ð� ���⵵�� ������ �� ����
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


// �ִ밪ã�� �Լ�
int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

// ���� ���ϴ� �Լ�
int getHeight(Node *node) {
	if (node == NULL) return 0;
	return node->height;
}

// ��� ���� ȸ���� ������ ���Ŀ� ���� ����
void setHeight(Node *node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

// ���� �μ� ��� �Լ�
int getDifference(Node *node) {
	if (node == NULL) return 0;
	return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// LL ȸ��
Node* rotateLL(Node * node) {
	puts("LL");
	Node *tmp = node->leftChild;
	node->leftChild = tmp->rightChild;
	tmp->rightChild = node;
	setHeight(node);  // ȸ�� ���� ���� �ٽ� ���
	return tmp;
}

// RR ȸ��
Node* rotateRR(Node *node) {
	puts("RR");
	Node *tmp = node->rightChild;
	node->rightChild = tmp->leftChild;
	tmp->leftChild = node;
	setHeight(node);  // ȸ�� ���� ���� �ٽ� ���
	return tmp;
}

// LR ȸ��
Node* rotateLR(Node *node) {
	puts("LR");
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

// RL ȸ��
Node* rotateRL(Node *node) {
	puts("RL");
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}


// ���� ���
Node *balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		// LL, LR ���� �Ǻ� �� ���� ���
		if (getDifference(node->leftChild) >= 1) { // ����� LL, ������ LR
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		// RR, RL ���� �Ǻ� �� ���� ���
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);  // ȸ�� ���� ���� ����
	return node;
}


// ���� �Լ�
Node* insertNode(Node *node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	// ���� �� �׻� ���� ��� ����
	else if (data < node->data) {  // ������ ��尡 �� ���� ��� - ���� ����Ʈ���� ����
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {  // ������ ��尡 �� ū ��� - ������ ����Ʈ���� ����
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {  // Ű�� �ߺ� ���x
		printf("������ �ߺ� �߻�");
	}
	return node;
}


// ��� �Լ�
Node *root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		// ���� ���� ������ �湮
		display(node->rightChild, level + 1);
		printf("\n");

		if (node == root) {
			printf("ROOT : ");
		}

		for (int i = 0; i < level && node != root; i++) {
			printf("    ");
		}
		printf("%d(%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}

int main(void) {
	int r, i, k;
	int randomnum[100];
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		r = rand() % 999 + 1;
		for (k = 0; k < i; k++) {
			if (randomnum[k] == r) { i--; break; }
		}
		if (k == i) randomnum[i] = r;
	}
	for (i = 0; i < 100; i++) {
		root = insertNode(root, randomnum[i]);
		display(root, 1);
		printf("\n");
	}
	printf("\n\nƮ���� ���� : %d\n",getHeight(root));
	
	return 0;
}
*/







/*


// 6�� AVL�� ���������� �߰��Ͽ� ���ô�.

// AVLƮ���� ����, ���� ���� ���� - notion�� �ʱ� (���� AVLƮ��(����) + �������� �߰�)

// �������� �� �ϼ���. ���� ������ �غôµ� �� �� ����. ������ �˻�ñ�
// �ٷ� �뷱�� ���� ������ �뷱���� �������µ� �� ���� ��� Ȥ�� ��Ʈ����� �뷱���� ������ ������ ���
// �׿� ���� ���� ���߱�� �� �̷����


#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	int height;   // ���̸� �����ؾ� �ð� ���⵵�� ������ �� ����
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


// �ִ밪ã�� �Լ�
int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

// ���� ���ϴ� �Լ�
int getHeight(Node *node) {
	if (node == NULL) return 0;
	return node->height;
}

// ��� ���� ȸ���� ������ ���Ŀ� ���� ����
void setHeight(Node *node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

// ���� �μ� ��� �Լ�
int getDifference(Node *node) {
	if (node == NULL) return 0;
	return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// LL ȸ��
Node* rotateLL(Node * node) {
	puts("LL");
	Node *tmp = node->leftChild;
	node->leftChild = tmp->rightChild;
	tmp->rightChild = node;
	setHeight(node);  // ȸ�� ���� ���� �ٽ� ���
	return tmp;
}

// RR ȸ��
Node* rotateRR(Node *node) {
	puts("RR");
	Node *tmp = node->rightChild;
	node->rightChild = tmp->leftChild;
	tmp->leftChild = node;
	setHeight(node);  // ȸ�� ���� ���� �ٽ� ���
	return tmp;
}

// LR ȸ��
Node* rotateLR(Node *node) {
	puts("LR");
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

// RL ȸ��
Node* rotateRL(Node *node) {
	puts("RL");
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}


// ���� ���
Node *balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		// LL, LR ���� �Ǻ� �� ���� ���
		if (getDifference(node->leftChild) >= 1) { // ����� LL, ������ LR
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		// RR, RL ���� �Ǻ� �� ���� ���
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);  // ȸ�� ���� ���� ����
	return node;
}


// ���� �Լ�
Node* insertNode(Node *node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	// ���� �� �׻� ���� ��� ����
	else if (data < node->data) {  // ������ ��尡 �� ���� ��� - ���� ����Ʈ���� ����
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {  // ������ ��尡 �� ū ��� - ������ ����Ʈ���� ����
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {  // Ű�� �ߺ� ���x
		printf("������ �ߺ� �߻�");
	}
	return node;
}


// ��� �Լ�
Node *root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		// ���� ���� ������ �湮
		display(node->rightChild, level + 1);
		printf("\n");

		if (node == root) {
			printf("ROOT : ");
		}

		for (int i = 0; i < level && node != root; i++) {
			printf("    ");
		}
		printf("%d(%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}



// ������ ���� Ž��
void search(Node* node, int level, int val, Node**key) {
	if (node != NULL) {
		// ���� ���� ������ �湮
		if (node->data == val) *key = node;
		search(node->rightChild, level + 1, val, key);
		search(node->leftChild, level + 1, val, key);
	}
}

// 3. �������� ���� - �ܸ������ ���
void find_parent_no_child(Node *node, Node *key, Node *before, char dir='a') {  // Head, �����ҳ��
	if (node) {
		if (root == key) {       // ������ ��尡 ��Ʈ����� ���
			root = NULL;
			printf("%d (root)��� �����Ϸ�.\n", key->data);
			return;
		}
		if (node->leftChild == key || node->rightChild == key) {
			if (node->leftChild == key)  node->leftChild = NULL; 
			else node->rightChild = NULL; 
			printf("%d ��� �����Ϸ�.\n", key->data);
			if (dir == 'l') before->leftChild = balance(node);
			else if (dir == 'r') before->rightChild = balance(node);
			else root = balance(node);
			return;
		}
		find_parent_no_child(node->leftChild, key, node, 'l');
		find_parent_no_child(node->rightChild, key, node, 'r');
	}
}
// 3. ���� �������� -  2. �ڽĳ�尡 �ϳ��� ��� - �θ��� ã��
void find_parent_one_child(Node *node, Node *key, Node *child, Node *before, char dir='a') {  // Head, �����ҳ��, �����ҳ���� �ڽĳ��
	if (node) {
		if (root == key) {       // ������ ��尡 ��Ʈ����� ���
			root = child;
			printf("%d (root)��� �����Ϸ�.\n", key->data);
			return;
		}
		if (node->leftChild == key || node->rightChild == key) {
			if (node->leftChild == key)  node->leftChild = child; 
			else  node->rightChild = child; 
			printf("%d ��� �����Ϸ�.\n", key->data);
			if (dir == 'l') before->leftChild = balance(node);
			else if (dir == 'r') before->rightChild = balance(node);
			else node = balance(node);
			return;
		}
		find_parent_one_child(node->leftChild, key, child, node, 'l');
		find_parent_one_child(node->rightChild, key, child, node, 'r');
	}
}
// 3. ���� �������� -  3. �ڽĳ�尡 ���� ��� - �θ��� ã��
void find_parent_two_child(Node *node, Node *key, Node *parent, char dir='a') {  // Head, �����ҳ��
	Node *tmp, *before;
	int flag = 0;
	if (node) {
		if (root == key) {        // ������ ��尡 ��Ʈ����� ���
			tmp = key->rightChild;  // right �ѹ� �̵�
			before = tmp;
			while (tmp->leftChild != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->leftChild;   // left�� ������ �̵�
			}
			if (flag == 1) {
				before->leftChild = tmp->rightChild;
				tmp->rightChild = root->rightChild;
			}
			tmp->leftChild = root->leftChild;
			root = tmp;

			printf("%d (root)��� �����Ϸ�.\n", key->data);
			root = balance(root);
			return;
		}

		if (node->leftChild == key || node->rightChild == key) {
			tmp = key->rightChild;  // right �ѹ� �̵�
			before = tmp;
			while (tmp->leftChild != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->leftChild;   // left�� ������ �̵�
			}
			if (node->leftChild == key) { node->leftChild = tmp; tmp->leftChild = key->leftChild;}
			else { node->rightChild = tmp;  tmp->leftChild = key->leftChild; }

			if (flag == 1) {
				before->leftChild = tmp->rightChild;
				tmp->rightChild = key->rightChild;
			}
			printf("%d ��� �����Ϸ�.\n", key->data);
			if (dir == 'l') parent->leftChild = balance(node->leftChild);
			else if (dir == 'r') parent->rightChild = balance(node->rightChild);
			else root = balance(node);
			return;
		}
		find_parent_two_child(node->leftChild, key, node);
		find_parent_two_child(node->rightChild, key, node);
	}
}


// 3. ����
void remove() {
	int val; // �����Ұ�
	Node *key = NULL;  // ������ ��� 
	Node *before;
	printf("������ Ű���� �Է��Ͻÿ� : ");
	scanf("%d", &val);
	search(root, 1, val, &key);
	if (key == NULL) printf("�Է��Ͻ� Ű���� �������� �ʽ��ϴ�.\n");
	else {
		//printf("ã�ҽ��ϴ�!  %d", key->data);
		// 1. �ڽĳ�尡 ���� ���(�ܸ������ ���)
		if (key->leftChild == NULL && key->rightChild == NULL) {
			find_parent_no_child(root, key, root);
		}
		// 2. �ڽĳ�尡 �ϳ��� ���
		else if ((key->leftChild != NULL && key->rightChild == NULL) || (key->leftChild == NULL && key->rightChild != NULL)) {
			if (key->leftChild != NULL) // ���� �ڽ��� ���
				find_parent_one_child(root, key, key->leftChild, root);
			else  // ������ �ڽ��� ���
				find_parent_one_child(root, key, key->rightChild, root);
		}
		// 3. �ڽĳ�尡 ���� ���
		else if (key->leftChild != NULL && key->rightChild != NULL) {
			find_parent_two_child(root, key, root);
		}
	}
}


int main(void) {
	int n, key;
	while (true)
	{
		printf("1. ����  2. ����  3. ���  4. ����\n");
		scanf("%d", &n);
		if (n == 1) {
			printf("������ �� �Է� : ");
			scanf("%d", &key);
			root = insertNode(root, key);
			display(root, 1);
			printf("\n");
		}
		else if (n == 2) {
			remove();
		}
		else if (n == 3) {
			display(root, 1);
			printf("\n");
		}
		else { printf("����Ǿ����ϴ�\n"); break; }
		
	}
	return 0;
}
*/





/*

// ���� ���Ϸ� ������ AVL Ʈ�� ���� �ڵ�

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
	int height;
}Node;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int height(Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

Node* newNode(int key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}
Node* rightRotate(Node* y)
{
	puts("LL");
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

Node* leftRotate(Node* x)
{
	puts("RR");
	struct Node* y = x->right;
	struct Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
Node* insert(Node* node, int key)
{
	if (node == NULL)
		return(newNode(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
Node* minValueNode(Node* node)
{
	Node* current = node;
	// loop down to find the leftmost leaf 
	while (current->left != NULL)
		current = current->left;
	return current;
}
Node* deleteNode(Node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			struct Node* temp = root->left ? root->left :
				root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			Node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL)
		return root;
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void preOrder(Node* root)
{
	if (root != NULL)
	{
		printf("%d -> ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
	Node* root = NULL;
	int cho, data;
	while (true)
	{
		puts("1.����   2.��ȸ  3.����  4.����");
		printf("==>");
		scanf("%d", &cho);
		if (cho == 1)
		{
			printf("data : ");
			scanf("%d", &data);
			root = insert(root, data);
		}
		if (cho == 2)
		{
			preOrder(root);
			printf("\n");
		}
		if (cho == 3)
		{
			printf("������� : ");
			scanf("%d", &data);
			root = deleteNode(root, data);
		}
		if (cho == 4)
			break;
	}
}

*/

