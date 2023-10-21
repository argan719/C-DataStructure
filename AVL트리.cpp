


// 11페이지 1번

/*
// AVL트리의 삽입연산을 구현하여 봅시다

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	int height;   // 높이를 저장해야 시간 복잡도를 보장할 수 있음
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


// 최대값찾기 함수
int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

// 높이 구하는 함수
int getHeight(Node *node) {
	if (node == NULL) return 0;
	return node -> height;
}

// 모든 노드는 회전을 수행한 이후에 높이 재계산
void setHeight(Node *node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

// 균형 인수 계산 함수
int getDifference(Node *node) {
	if (node == NULL) return 0;
	return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// LL 회전
Node* rotateLL(Node * node) {
	puts("LL");
	Node *tmp = node->leftChild;
	node->leftChild = tmp->rightChild;
	tmp->rightChild = node;
	setHeight(node);  // 회전 이후 높이 다시 계산
	return tmp;
}

// RR 회전
Node* rotateRR(Node *node) {
	puts("RR");
	Node *tmp = node->rightChild;
	node->rightChild = tmp->leftChild;
	tmp->leftChild = node;
	setHeight(node);  // 회전 이후 높이 다시 계산
	return tmp;
}

// LR 회전
Node* rotateLR(Node *node) {
	puts("LR");
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

// RL 회전
Node* rotateRL(Node *node) {
	puts("RL");
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}


// 균형 잡기
Node *balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		// LL, LR 형식 판별 후 균형 잡기
		if (getDifference(node->leftChild) >= 1) { // 양수면 LL, 음수면 LR
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		// RR, RL 형식 판별 후 균형 잡기
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);  // 회전 이후 높이 재계산
	return node;
}


// 삽입 함수
Node* insertNode(Node *node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	// 삽입 후 항상 균형 잡기 실행
	else if (data < node->data) {  // 삽입할 노드가 더 작은 경우 - 왼쪽 서브트리로 삽입
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {  // 삽입할 노드가 더 큰 경우 - 오른쪽 서브트리로 삽입
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {  // 키값 중복 허용x
		printf("데이터 중복 발생");
	}
	return node;
}


// 출력 함수
Node *root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		// 가장 우측 노드부터 방문
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
		printf("입력 : ");
		scanf("%d", &n);
		root = insertNode(root, n);
		display(root, 1);
		printf("\n");
	}
	return 0;
}
*/





// 문제풀이 16페이지
/*
// 5번
// 서로 다른 100개의 정수 난수를 발생시켜 AVL트리에 삽입, 트리 높이 측정

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Node {
	int data;
	int height;   // 높이를 저장해야 시간 복잡도를 보장할 수 있음
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


// 최대값찾기 함수
int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

// 높이 구하는 함수
int getHeight(Node *node) {
	if (node == NULL) return 0;
	return node->height;
}

// 모든 노드는 회전을 수행한 이후에 높이 재계산
void setHeight(Node *node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

// 균형 인수 계산 함수
int getDifference(Node *node) {
	if (node == NULL) return 0;
	return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// LL 회전
Node* rotateLL(Node * node) {
	puts("LL");
	Node *tmp = node->leftChild;
	node->leftChild = tmp->rightChild;
	tmp->rightChild = node;
	setHeight(node);  // 회전 이후 높이 다시 계산
	return tmp;
}

// RR 회전
Node* rotateRR(Node *node) {
	puts("RR");
	Node *tmp = node->rightChild;
	node->rightChild = tmp->leftChild;
	tmp->leftChild = node;
	setHeight(node);  // 회전 이후 높이 다시 계산
	return tmp;
}

// LR 회전
Node* rotateLR(Node *node) {
	puts("LR");
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

// RL 회전
Node* rotateRL(Node *node) {
	puts("RL");
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}


// 균형 잡기
Node *balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		// LL, LR 형식 판별 후 균형 잡기
		if (getDifference(node->leftChild) >= 1) { // 양수면 LL, 음수면 LR
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		// RR, RL 형식 판별 후 균형 잡기
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);  // 회전 이후 높이 재계산
	return node;
}


// 삽입 함수
Node* insertNode(Node *node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	// 삽입 후 항상 균형 잡기 실행
	else if (data < node->data) {  // 삽입할 노드가 더 작은 경우 - 왼쪽 서브트리로 삽입
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {  // 삽입할 노드가 더 큰 경우 - 오른쪽 서브트리로 삽입
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {  // 키값 중복 허용x
		printf("데이터 중복 발생");
	}
	return node;
}


// 출력 함수
Node *root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		// 가장 우측 노드부터 방문
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
	printf("\n\n트리의 높이 : %d\n",getHeight(root));
	
	return 0;
}
*/







/*


// 6번 AVL에 삭제연산을 추가하여 봅시다.

// AVL트리의 삽입, 삭제 연산 구현 - notion에 필기 (원래 AVL트리(삽입) + 삭제연산 추가)

// 삭제까지 다 완성함. 검토 여러번 해봤는데 다 잘 나옴. 쌤한테 검사맡기
// 바로 밸런스 깨진 조상노드 밸런스는 맞춰지는데 그 위에 노드 혹은 루트노드의 밸런스도 여전히 깨졌을 경우
// 그에 대한 군형 맞추기는 안 이루어짐


#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	int height;   // 높이를 저장해야 시간 복잡도를 보장할 수 있음
	struct Node* leftChild;
	struct Node* rightChild;
}Node;


// 최대값찾기 함수
int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

// 높이 구하는 함수
int getHeight(Node *node) {
	if (node == NULL) return 0;
	return node->height;
}

// 모든 노드는 회전을 수행한 이후에 높이 재계산
void setHeight(Node *node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

// 균형 인수 계산 함수
int getDifference(Node *node) {
	if (node == NULL) return 0;
	return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// LL 회전
Node* rotateLL(Node * node) {
	puts("LL");
	Node *tmp = node->leftChild;
	node->leftChild = tmp->rightChild;
	tmp->rightChild = node;
	setHeight(node);  // 회전 이후 높이 다시 계산
	return tmp;
}

// RR 회전
Node* rotateRR(Node *node) {
	puts("RR");
	Node *tmp = node->rightChild;
	node->rightChild = tmp->leftChild;
	tmp->leftChild = node;
	setHeight(node);  // 회전 이후 높이 다시 계산
	return tmp;
}

// LR 회전
Node* rotateLR(Node *node) {
	puts("LR");
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

// RL 회전
Node* rotateRL(Node *node) {
	puts("RL");
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}


// 균형 잡기
Node *balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		// LL, LR 형식 판별 후 균형 잡기
		if (getDifference(node->leftChild) >= 1) { // 양수면 LL, 음수면 LR
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		// RR, RL 형식 판별 후 균형 잡기
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node);  // 회전 이후 높이 재계산
	return node;
}


// 삽입 함수
Node* insertNode(Node *node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	// 삽입 후 항상 균형 잡기 실행
	else if (data < node->data) {  // 삽입할 노드가 더 작은 경우 - 왼쪽 서브트리로 삽입
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {  // 삽입할 노드가 더 큰 경우 - 오른쪽 서브트리로 삽입
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {  // 키값 중복 허용x
		printf("데이터 중복 발생");
	}
	return node;
}


// 출력 함수
Node *root = NULL;

void display(Node* node, int level) {
	if (node != NULL) {
		// 가장 우측 노드부터 방문
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



// 삭제를 위한 탐색
void search(Node* node, int level, int val, Node**key) {
	if (node != NULL) {
		// 가장 우측 노드부터 방문
		if (node->data == val) *key = node;
		search(node->rightChild, level + 1, val, key);
		search(node->leftChild, level + 1, val, key);
	}
}

// 3. 삭제연산 진행 - 단말노드인 경우
void find_parent_no_child(Node *node, Node *key, Node *before, char dir='a') {  // Head, 삭제할노드
	if (node) {
		if (root == key) {       // 삭제할 노드가 루트노드인 경우
			root = NULL;
			printf("%d (root)노드 삭제완료.\n", key->data);
			return;
		}
		if (node->leftChild == key || node->rightChild == key) {
			if (node->leftChild == key)  node->leftChild = NULL; 
			else node->rightChild = NULL; 
			printf("%d 노드 삭제완료.\n", key->data);
			if (dir == 'l') before->leftChild = balance(node);
			else if (dir == 'r') before->rightChild = balance(node);
			else root = balance(node);
			return;
		}
		find_parent_no_child(node->leftChild, key, node, 'l');
		find_parent_no_child(node->rightChild, key, node, 'r');
	}
}
// 3. 삭제 연산진행 -  2. 자식노드가 하나인 경우 - 부모노드 찾기
void find_parent_one_child(Node *node, Node *key, Node *child, Node *before, char dir='a') {  // Head, 삭제할노드, 삭제할노드의 자식노드
	if (node) {
		if (root == key) {       // 삭제할 노드가 루트노드인 경우
			root = child;
			printf("%d (root)노드 삭제완료.\n", key->data);
			return;
		}
		if (node->leftChild == key || node->rightChild == key) {
			if (node->leftChild == key)  node->leftChild = child; 
			else  node->rightChild = child; 
			printf("%d 노드 삭제완료.\n", key->data);
			if (dir == 'l') before->leftChild = balance(node);
			else if (dir == 'r') before->rightChild = balance(node);
			else node = balance(node);
			return;
		}
		find_parent_one_child(node->leftChild, key, child, node, 'l');
		find_parent_one_child(node->rightChild, key, child, node, 'r');
	}
}
// 3. 삭제 연산진행 -  3. 자식노드가 둘인 경우 - 부모노드 찾기
void find_parent_two_child(Node *node, Node *key, Node *parent, char dir='a') {  // Head, 삭제할노드
	Node *tmp, *before;
	int flag = 0;
	if (node) {
		if (root == key) {        // 삭제할 노드가 루트노드인 경우
			tmp = key->rightChild;  // right 한번 이동
			before = tmp;
			while (tmp->leftChild != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->leftChild;   // left로 끝까지 이동
			}
			if (flag == 1) {
				before->leftChild = tmp->rightChild;
				tmp->rightChild = root->rightChild;
			}
			tmp->leftChild = root->leftChild;
			root = tmp;

			printf("%d (root)노드 삭제완료.\n", key->data);
			root = balance(root);
			return;
		}

		if (node->leftChild == key || node->rightChild == key) {
			tmp = key->rightChild;  // right 한번 이동
			before = tmp;
			while (tmp->leftChild != NULL) {
				flag = 1;
				before = tmp;
				tmp = tmp->leftChild;   // left로 끝까지 이동
			}
			if (node->leftChild == key) { node->leftChild = tmp; tmp->leftChild = key->leftChild;}
			else { node->rightChild = tmp;  tmp->leftChild = key->leftChild; }

			if (flag == 1) {
				before->leftChild = tmp->rightChild;
				tmp->rightChild = key->rightChild;
			}
			printf("%d 노드 삭제완료.\n", key->data);
			if (dir == 'l') parent->leftChild = balance(node->leftChild);
			else if (dir == 'r') parent->rightChild = balance(node->rightChild);
			else root = balance(node);
			return;
		}
		find_parent_two_child(node->leftChild, key, node);
		find_parent_two_child(node->rightChild, key, node);
	}
}


// 3. 삭제
void remove() {
	int val; // 삭제할값
	Node *key = NULL;  // 삭제할 노드 
	Node *before;
	printf("삭제할 키값을 입력하시오 : ");
	scanf("%d", &val);
	search(root, 1, val, &key);
	if (key == NULL) printf("입력하신 키값이 존재하지 않습니다.\n");
	else {
		//printf("찾았습니다!  %d", key->data);
		// 1. 자식노드가 없는 경우(단말노드인 경우)
		if (key->leftChild == NULL && key->rightChild == NULL) {
			find_parent_no_child(root, key, root);
		}
		// 2. 자식노드가 하나인 경우
		else if ((key->leftChild != NULL && key->rightChild == NULL) || (key->leftChild == NULL && key->rightChild != NULL)) {
			if (key->leftChild != NULL) // 왼쪽 자식인 경우
				find_parent_one_child(root, key, key->leftChild, root);
			else  // 오른쪽 자식인 경우
				find_parent_one_child(root, key, key->rightChild, root);
		}
		// 3. 자식노드가 둘인 경우
		else if (key->leftChild != NULL && key->rightChild != NULL) {
			find_parent_two_child(root, key, root);
		}
	}
}


int main(void) {
	int n, key;
	while (true)
	{
		printf("1. 삽입  2. 삭제  3. 출력  4. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			printf("삽입할 값 입력 : ");
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
		else { printf("종료되었습니다\n"); break; }
		
	}
	return 0;
}
*/





/*

// 쌤이 메일로 보내준 AVL 트리 삭제 코드

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
		puts("1.삽입   2.순회  3.삭제  4.종료");
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
			printf("삭제노드 : ");
			scanf("%d", &data);
			root = deleteNode(root, data);
		}
		if (cho == 4)
			break;
	}
}

*/

