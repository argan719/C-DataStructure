

// 이진탐색트리 구현


// 문제풀이 12페이지
/*
// 4번
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 2. 순회 (중위순회로 출력)
void Traverse(TreeNode *node) {
	if (node) {
		Traverse(node->left);
		printf("%d -> ", node->data);
		Traverse(node->right);
	}
}


// 1. 입력 - 삽입
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// 왼쪽으로 이동
		if (node->data > newNode->data) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // 오른쪽으로 이동
		else if (node->data < newNode->data) {
			if (node->right != NULL) node = node->right;
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


// 3. 최대값 찾기
TreeNode* search_maximum(TreeNode *node) {
	TreeNode *tmp;
	while (node->right != NULL) {
		node = node->right;
	}
	tmp = node;
	return tmp;
}

// 4. 최소값 찾기
TreeNode* search_minimum(TreeNode *node) {
	TreeNode *tmp;
	while (node->left != NULL) {
		node = node->left;
	}
	tmp = node;
	return tmp;
}


void main()
{
	int n;
	TreeNode* max;
	TreeNode* min;

	for (;;) {
		printf("\n=== 메뉴 ===\n");
		printf("1. 삽입\n");
		printf("2. 순회\n");
		printf("3. 최대값 출력\n");
		printf("4. 최소값 출력\n");
		printf("5. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			Traverse(Head);
		}
		else if (n == 3) {
			max = search_maximum(Head);
			printf("최대값 : %d \n", max->data);
		}
		else if (n == 4) {
			min = search_minimum(Head);
			printf("최소값 : %d \n", min->data);
		}
		else { printf("종료되었습니다.\n"); break; }
	}
}
*/

/*
// 5번
// 이진탐색트리의 모든 노드의 값을 1씩 증가시키는 프로그램
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 2. 순회 (중위순회로 출력)
void Traverse(TreeNode *node) {
	if (node) {
		Traverse(node->left);
		printf("%d -> ", node->data);
		Traverse(node->right);
	}
}


// 1. 입력 - 삽입
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// 왼쪽으로 이동
		if (node->data > newNode->data) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // 오른쪽으로 이동
		else if (node->data < newNode->data) {
			if (node->right != NULL) node = node->right;
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

// 3. 모든 노드의 값 1증가
void increment(TreeNode *node) {
	if (node) {
		node->data++;
		increment(node->left);
		increment(node->right);
	}
}


void main()
{
	int n;

	for (;;) {
		printf("\n=== 메뉴 ===\n");
		printf("1. 삽입\n");
		printf("2. 순회\n");
		printf("3. 모든 노드의 값 1증가\n");
		printf("4. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			Traverse(Head);
		}
		else if (n == 3) {
			increment(Head);
			printf("모든 노드의 값이 1씩 증가되었습니다.\n");
		}
		else { printf("종료되었습니다.\n"); break; }
	}
}
*/


/*
// 6번
#include<stdio.h>
#include<stdlib.h>

typedef struct ST {
	int num;  // 학번
	char name[20];  // 이름
	char address[20];  // 주소
	char department[20];  // 소속학과
	int score;  // 점수
}element;

typedef struct Tree {
	element data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 순회 (전위순회로 출력)
void Traverse_preorder(TreeNode *node) {
	if (node) {
		printf("학번 : %d  이름 : %s  주소 : %s  소속 학과 : %s  점수 : %d \n",node->data.num,  node->data.name, node->data.address, node->data.department, node->data.score);
		Traverse_preorder(node->left);
		Traverse_preorder(node->right);
	}
}
// 순회 (중위순회로 출력)
void Traverse_inorder(TreeNode *node) {
	if (node) {
		Traverse_inorder(node->left);
		printf("학번 : %d  이름 : %s  주소 : %s  소속 학과 : %s  점수 : %d \n", node->data.num, node->data.name, node->data.address, node->data.department, node->data.score);
		Traverse_inorder(node->right);
	}
}

// 5.학생들의 총 숫자 세기 - 순회하면서
int count(TreeNode *node) {
	int sum = 0;
	if (node) {
		sum = 1+ count(node->left) + count(node->right);
	}
	return sum;
}

// 7. 가장 높은 점수 학생 찾기 - 순회하면서
void high_score(TreeNode *node, TreeNode *high) {
	if (node) {
		if (high->data.score < node->data.score) *high = *node;
		high_score(node->left, high);
		high_score(node->right, high);
	}
}

// 8. 평균 점수 구하기
int aver(TreeNode *node, int sum) {

	if (node) {
		sum += node->data.score;
		sum = aver(node->left, sum);
		sum = aver(node->right, sum);
	}
	return sum;
}

// 9. 가장 작은 학번 학생
TreeNode * search_minimum(TreeNode *node) {
	TreeNode *tmp = NULL;
	while (node->left != NULL) {
		node = node->left;
	}
	if (node->left == NULL) tmp = node;
	return tmp;
}

// 10. 가장 큰 학번 학생
TreeNode * search_maximum(TreeNode *node) {
	TreeNode *tmp = NULL;
	while (node->right != NULL) {
		node = node->right;
	}
	if (node->right == NULL) tmp = node;
	return tmp;
}

// 1. 입력 - 삽입
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// 왼쪽으로 이동
		if (node->data.num > newNode->data.num) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // 오른쪽으로 이동
		else if (node->data.num < newNode->data.num) {
			if (node->right != NULL) node = node->right;
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
	printf("학번 : "); scanf("%d", &tmp->data.num);
	printf("이름 : "); scanf("%s", &tmp->data.name);
	printf("주소 : "); scanf("%s", &tmp->data.address);
	printf("소속 학과 : "); scanf("%s", &tmp->data.department);
	printf("점수 : "); scanf("%d", &tmp->data.score);


	if (Head == NULL) {
		Head = tmp;
	}
	else traverse_for_insert(Head, tmp);
}


// 3. 삭제 - 삭제할 노드 찾기
void traverse_for_delete(TreeNode *node, int key, TreeNode **search) {
	if (node) {
		if (node->data.num == key) *search = node;
		traverse_for_delete(node->left, key, search);
		traverse_for_delete(node->right, key, search);
	}

}

// 3. 삭제 연산진행 - 1. 자식노드가 없는 경우  - 부모노드 찾기
void find_parent_no_child(TreeNode *node, TreeNode *key) {  // Head, 삭제할노드
	if (node) {
		if (Head == key) {       // 삭제할 노드가 루트노드인 경우
			Head = NULL;
			printf("%d %s 학생 삭제완료.\n", key->data.num, key->data.name);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("%d %s 학생 삭제완료.\n", key->data.num, key->data.name);
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
			printf("%d %s 학생 삭제완료.\n", key->data.num, key->data.name);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("%d %s 학생 삭제완료.\n", key->data.num, key->data.name);
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

			printf("%d %s 학생 삭제완료.\n", key->data.num, key->data.name);
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
			printf("%d %s 학생 삭제완료.\n", key->data.num, key->data.name);
			return;
		}
		find_parent_two_child(node->left, key);
		find_parent_two_child(node->right, key);
	}
}


// 3. 삭제
void remove() {
	int val; // 삭제할 학번
	TreeNode *key = NULL;  // 삭제할 노드 
	printf("삭제할 학생의 학번을 입력하시오 : ");
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
			if (key->left != NULL) // 왼쪽 자식인 경우
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
		printf("\n=== 학생정보 검색 프로그램 ===\n");
		printf("1. 학생정보 입력\n");
		printf("2. 학생정보 삭제\n");
		printf("3. 학생정보 탐색\n");
		printf("4. 학생정보 학번순으로 출력\n");
		printf("5. 현재 저장된 학생들의 총 숫자\n");
		printf("6. 전부 삭제\n");
		printf("7. 가장 높은 점수 학생 출력\n");
		printf("8. 학생들의 평균 점수 출력\n");
		printf("9. 가장 작은 학번 학생 출력\n");
		printf("10. 가장 큰 학번 학생 출력\n");
		printf("11. 종료\n");


		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			remove();
		}
		else if (n == 3) {
			// 전위순회
			Traverse_preorder(Head);
		}
		else if (n == 4) {
			// 중위순회
			Traverse_inorder(Head);
		}
		else if (n == 5) {
			printf("현재 저장된 학생들의 총 숫자 : %d \n", count(Head));
		}
		else if (n == 6) {
			Head = NULL;
			printf("전부 삭제되었습니다.\n");
		}
		else if (n == 7) {
			TreeNode high;
			high.data.score = -10;
			high_score(Head, &high);
			printf("가장 높은 점수를 가진 학생\n");
			printf("학번 : %d\n", high.data.num);
			printf("이름 : %s\n", high.data.name);
			printf("주소 : %s\n", high.data.address);
			printf("소속 학과 : %s\n", high.data.department);
			printf("점수 : %d\n", high.data.score);

		}
		else if (n == 8) {
			int sum = aver(Head, 0);
			sum = sum / count(Head);
			printf("학생들의 평균 점수 : %d 점\n", sum);
		}
		else if (n == 9) {
			TreeNode *min;
			min = search_minimum(Head);
			printf("가장 작은 학번 학생정보 출력\n");
			printf("학번 : %d\n", min->data.num);
			printf("이름 : %s\n", min->data.name);
			printf("주소 : %s\n", min->data.address);
			printf("소속 학과 : %s\n", min->data.department);
			printf("점수 : %d\n", min->data.score);
		}
		else if (n == 10) {
			TreeNode *max;
			max = search_maximum(Head);
			printf("가장 큰 학번 학생정보 출력\n");
			printf("학번 : %d\n", max->data.num);
			printf("이름 : %s\n", max->data.name);
			printf("주소 : %s\n", max->data.address);
			printf("소속 학과 : %s\n", max->data.department);
			printf("점수 : %d\n", max->data.score);
		}
		else { printf("종료되었습니다.\n"); break; }
	}

}
*/

/*
// 7번
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	char data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 2. 순회 (중위순회로 출력)
void Traverse(TreeNode *node) {
	if (node) {
		Traverse(node->left);
		printf("%c_", node->data);
		Traverse(node->right);
	}
}


// 1. 입력 - 삽입
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// 왼쪽으로 이동
		if (node->data > newNode->data) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // 오른쪽으로 이동
		else if (node->data < newNode->data) {
			if (node->right != NULL) node = node->right;
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
	printf("삽입할 문자 : ");
	scanf(" %c", &tmp->data);
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
			printf("%c (root)노드 삭제완료.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("%c 노드 삭제완료.\n", key->data);
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
			printf("%c (root)노드 삭제완료.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("%c 노드 삭제완료.\n", key->data);
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

			printf("%c (root)노드 삭제완료.\n", key->data);
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
			printf("%c 노드 삭제완료.\n", key->data);
			return;
		}
		find_parent_two_child(node->left, key);
		find_parent_two_child(node->right, key);
	}
}


// 3. 삭제
void remove() {
	char val; // 삭제할값
	TreeNode *key = NULL;  // 삭제할 노드 
	printf("삭제할 키값을 입력하시오 : ");
	scanf(" %c", &val);
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
			if (key->left != NULL) // 왼쪽 자식인 경우
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

void search_traverse(TreeNode* node, char key, bool &bit) {
	if (node) {
		if (node->data == key) {
			printf("%c 는 존재합니다!\n", node->data);
			bit = true;
		}
		search_traverse(node->left, key, bit);
		search_traverse(node->right, key, bit);
	}
}

void search()
{
	char c;
	bool bit = false;
	printf("검색할 문자 : ");
	scanf(" %c", &c);
	search_traverse(Head, c, bit);
	if(bit == false) printf("%c는 존재하지 않습니다!\n", c);
}
void main()
{
	int n;

	for (;;) {
		printf("\n=== 메뉴 ===\n");
		printf("1. 트리출력\n");
		printf("2. 문자삽입\n");
		printf("3. 문자삭제\n");
		printf("4. 문자검색\n");
		printf("5. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			Traverse(Head);
		}
		else if (n == 2) {
			insert();
		}
		else if (n == 3) {
			remove();
		}
		else if (n == 4) {
			search();
		}
		else { printf("종료되었습니다.\n"); break; }
	}

}
*/


/*
// 8번
#include<stdio.h>
#include<stdlib.h>

typedef struct ST {
	int num;  // 번호
	char name[20];  // 이름
}element;

typedef struct Tree {
	element data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;

// 2. 순회 (중위순회로 출력)
void Traverse(TreeNode *node) {
	if (node) {
		Traverse(node->left);
		printf("%d %s\n", node->data.num, node->data.name);
		Traverse(node->right);
	}
}


// 1. 입력 - 삽입
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// 왼쪽으로 이동
		if (node->data.num > newNode->data.num) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // 오른쪽으로 이동
		else if (node->data.num < newNode->data.num) {
			if (node->right != NULL) node = node->right;
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
	printf("번호 : "); scanf("%d", &tmp->data.num);
	printf("이름 : "); scanf("%s", &tmp->data.name);
	if (Head == NULL) {
		Head = tmp;
	}
	else traverse_for_insert(Head, tmp);
}


// 3. 삭제 - 삭제할 노드 찾기
void traverse_for_delete(TreeNode *node, int key, TreeNode **search) {
	if (node) {
		if (node->data.num == key) *search = node;
		traverse_for_delete(node->left, key, search);
		traverse_for_delete(node->right, key, search);
	}

}

// 3. 삭제 연산진행 - 1. 자식노드가 없는 경우  - 부모노드 찾기
void find_parent_no_child(TreeNode *node, TreeNode *key) {  // Head, 삭제할노드
	if (node) {
		if (Head == key) {       // 삭제할 노드가 루트노드인 경우
			Head = NULL;
			printf("삭제완료!\n");
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("삭제완료!\n");
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
			printf("삭제완료!\n");
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("삭제완료!\n");
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

			printf("삭제완료!\n");
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
			printf("삭제완료!\n");
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
	printf("삭제할 번호 : ");
	scanf("%d", &val);
	traverse_for_delete(Head, val, &key);
	if (key == NULL) printf("입력하신 번호가 존재하지 않습니다.\n");
	else {
		//printf("찾았습니다!  %d", key->data);
		// 1. 자식노드가 없는 경우(단말노드인 경우)
		if (key->left == NULL && key->right == NULL) {
			find_parent_no_child(Head, key);
		}
		// 2. 자식노드가 하나인 경우
		else if ((key->left != NULL && key->right == NULL) || (key->left == NULL && key->right != NULL)) {
			if (key->left != NULL) // 왼쪽 자식인 경우
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


void search_traverse(TreeNode* node, int key, bool &bit) {
	if (node) {
		if (node->data.num == key) {
			printf("==> %s\n", node->data.name);
			bit = true;
		}
		search_traverse(node->left, key, bit);
		search_traverse(node->right, key, bit);
	}
}

void search()
{
	int num;
	bool bit = false;
	printf("검색번호 : ");
	scanf(" %d", &num);
	search_traverse(Head, num, bit);
	if (bit == false) printf("%d 번호는 존재하지 않습니다!\n", num);
}

void main()
{
	int n;

	for (;;) {
		printf("\n=== 메뉴 ===\n");
		printf("1. 입력\n");
		printf("2. 리스트 출력\n");
		printf("3. 검색\n");
		printf("4. 삭제\n");
		printf("5. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			Traverse(Head);
		}
		else if (n == 3) {
			search();
		}
		else if (n == 4) {
			remove();
		}
		else { printf("종료되었습니다.\n"); break; }
	}

}
*/

