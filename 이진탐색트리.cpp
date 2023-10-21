

// ����Ž��Ʈ�� ����


// ����Ǯ�� 12������
/*
// 4��
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
		Traverse(node->left);
		printf("%d -> ", node->data);
		Traverse(node->right);
	}
}


// 1. �Է� - ����
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// �������� �̵�
		if (node->data > newNode->data) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // ���������� �̵�
		else if (node->data < newNode->data) {
			if (node->right != NULL) node = node->right;
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


// 3. �ִ밪 ã��
TreeNode* search_maximum(TreeNode *node) {
	TreeNode *tmp;
	while (node->right != NULL) {
		node = node->right;
	}
	tmp = node;
	return tmp;
}

// 4. �ּҰ� ã��
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
		printf("\n=== �޴� ===\n");
		printf("1. ����\n");
		printf("2. ��ȸ\n");
		printf("3. �ִ밪 ���\n");
		printf("4. �ּҰ� ���\n");
		printf("5. ����\n");
		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			Traverse(Head);
		}
		else if (n == 3) {
			max = search_maximum(Head);
			printf("�ִ밪 : %d \n", max->data);
		}
		else if (n == 4) {
			min = search_minimum(Head);
			printf("�ּҰ� : %d \n", min->data);
		}
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}
}
*/

/*
// 5��
// ����Ž��Ʈ���� ��� ����� ���� 1�� ������Ű�� ���α׷�
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
		Traverse(node->left);
		printf("%d -> ", node->data);
		Traverse(node->right);
	}
}


// 1. �Է� - ����
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// �������� �̵�
		if (node->data > newNode->data) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // ���������� �̵�
		else if (node->data < newNode->data) {
			if (node->right != NULL) node = node->right;
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

// 3. ��� ����� �� 1����
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
		printf("\n=== �޴� ===\n");
		printf("1. ����\n");
		printf("2. ��ȸ\n");
		printf("3. ��� ����� �� 1����\n");
		printf("4. ����\n");
		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			Traverse(Head);
		}
		else if (n == 3) {
			increment(Head);
			printf("��� ����� ���� 1�� �����Ǿ����ϴ�.\n");
		}
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}
}
*/


/*
// 6��
#include<stdio.h>
#include<stdlib.h>

typedef struct ST {
	int num;  // �й�
	char name[20];  // �̸�
	char address[20];  // �ּ�
	char department[20];  // �Ҽ��а�
	int score;  // ����
}element;

typedef struct Tree {
	element data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// ��ȸ (������ȸ�� ���)
void Traverse_preorder(TreeNode *node) {
	if (node) {
		printf("�й� : %d  �̸� : %s  �ּ� : %s  �Ҽ� �а� : %s  ���� : %d \n",node->data.num,  node->data.name, node->data.address, node->data.department, node->data.score);
		Traverse_preorder(node->left);
		Traverse_preorder(node->right);
	}
}
// ��ȸ (������ȸ�� ���)
void Traverse_inorder(TreeNode *node) {
	if (node) {
		Traverse_inorder(node->left);
		printf("�й� : %d  �̸� : %s  �ּ� : %s  �Ҽ� �а� : %s  ���� : %d \n", node->data.num, node->data.name, node->data.address, node->data.department, node->data.score);
		Traverse_inorder(node->right);
	}
}

// 5.�л����� �� ���� ���� - ��ȸ�ϸ鼭
int count(TreeNode *node) {
	int sum = 0;
	if (node) {
		sum = 1+ count(node->left) + count(node->right);
	}
	return sum;
}

// 7. ���� ���� ���� �л� ã�� - ��ȸ�ϸ鼭
void high_score(TreeNode *node, TreeNode *high) {
	if (node) {
		if (high->data.score < node->data.score) *high = *node;
		high_score(node->left, high);
		high_score(node->right, high);
	}
}

// 8. ��� ���� ���ϱ�
int aver(TreeNode *node, int sum) {

	if (node) {
		sum += node->data.score;
		sum = aver(node->left, sum);
		sum = aver(node->right, sum);
	}
	return sum;
}

// 9. ���� ���� �й� �л�
TreeNode * search_minimum(TreeNode *node) {
	TreeNode *tmp = NULL;
	while (node->left != NULL) {
		node = node->left;
	}
	if (node->left == NULL) tmp = node;
	return tmp;
}

// 10. ���� ū �й� �л�
TreeNode * search_maximum(TreeNode *node) {
	TreeNode *tmp = NULL;
	while (node->right != NULL) {
		node = node->right;
	}
	if (node->right == NULL) tmp = node;
	return tmp;
}

// 1. �Է� - ����
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// �������� �̵�
		if (node->data.num > newNode->data.num) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // ���������� �̵�
		else if (node->data.num < newNode->data.num) {
			if (node->right != NULL) node = node->right;
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
	printf("�й� : "); scanf("%d", &tmp->data.num);
	printf("�̸� : "); scanf("%s", &tmp->data.name);
	printf("�ּ� : "); scanf("%s", &tmp->data.address);
	printf("�Ҽ� �а� : "); scanf("%s", &tmp->data.department);
	printf("���� : "); scanf("%d", &tmp->data.score);


	if (Head == NULL) {
		Head = tmp;
	}
	else traverse_for_insert(Head, tmp);
}


// 3. ���� - ������ ��� ã��
void traverse_for_delete(TreeNode *node, int key, TreeNode **search) {
	if (node) {
		if (node->data.num == key) *search = node;
		traverse_for_delete(node->left, key, search);
		traverse_for_delete(node->right, key, search);
	}

}

// 3. ���� �������� - 1. �ڽĳ�尡 ���� ���  - �θ��� ã��
void find_parent_no_child(TreeNode *node, TreeNode *key) {  // Head, �����ҳ��
	if (node) {
		if (Head == key) {       // ������ ��尡 ��Ʈ����� ���
			Head = NULL;
			printf("%d %s �л� �����Ϸ�.\n", key->data.num, key->data.name);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("%d %s �л� �����Ϸ�.\n", key->data.num, key->data.name);
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
			printf("%d %s �л� �����Ϸ�.\n", key->data.num, key->data.name);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("%d %s �л� �����Ϸ�.\n", key->data.num, key->data.name);
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

			printf("%d %s �л� �����Ϸ�.\n", key->data.num, key->data.name);
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
			printf("%d %s �л� �����Ϸ�.\n", key->data.num, key->data.name);
			return;
		}
		find_parent_two_child(node->left, key);
		find_parent_two_child(node->right, key);
	}
}


// 3. ����
void remove() {
	int val; // ������ �й�
	TreeNode *key = NULL;  // ������ ��� 
	printf("������ �л��� �й��� �Է��Ͻÿ� : ");
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
			if (key->left != NULL) // ���� �ڽ��� ���
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
		printf("\n=== �л����� �˻� ���α׷� ===\n");
		printf("1. �л����� �Է�\n");
		printf("2. �л����� ����\n");
		printf("3. �л����� Ž��\n");
		printf("4. �л����� �й������� ���\n");
		printf("5. ���� ����� �л����� �� ����\n");
		printf("6. ���� ����\n");
		printf("7. ���� ���� ���� �л� ���\n");
		printf("8. �л����� ��� ���� ���\n");
		printf("9. ���� ���� �й� �л� ���\n");
		printf("10. ���� ū �й� �л� ���\n");
		printf("11. ����\n");


		scanf("%d", &n);
		if (n == 1) {
			insert();
		}
		else if (n == 2) {
			remove();
		}
		else if (n == 3) {
			// ������ȸ
			Traverse_preorder(Head);
		}
		else if (n == 4) {
			// ������ȸ
			Traverse_inorder(Head);
		}
		else if (n == 5) {
			printf("���� ����� �л����� �� ���� : %d \n", count(Head));
		}
		else if (n == 6) {
			Head = NULL;
			printf("���� �����Ǿ����ϴ�.\n");
		}
		else if (n == 7) {
			TreeNode high;
			high.data.score = -10;
			high_score(Head, &high);
			printf("���� ���� ������ ���� �л�\n");
			printf("�й� : %d\n", high.data.num);
			printf("�̸� : %s\n", high.data.name);
			printf("�ּ� : %s\n", high.data.address);
			printf("�Ҽ� �а� : %s\n", high.data.department);
			printf("���� : %d\n", high.data.score);

		}
		else if (n == 8) {
			int sum = aver(Head, 0);
			sum = sum / count(Head);
			printf("�л����� ��� ���� : %d ��\n", sum);
		}
		else if (n == 9) {
			TreeNode *min;
			min = search_minimum(Head);
			printf("���� ���� �й� �л����� ���\n");
			printf("�й� : %d\n", min->data.num);
			printf("�̸� : %s\n", min->data.name);
			printf("�ּ� : %s\n", min->data.address);
			printf("�Ҽ� �а� : %s\n", min->data.department);
			printf("���� : %d\n", min->data.score);
		}
		else if (n == 10) {
			TreeNode *max;
			max = search_maximum(Head);
			printf("���� ū �й� �л����� ���\n");
			printf("�й� : %d\n", max->data.num);
			printf("�̸� : %s\n", max->data.name);
			printf("�ּ� : %s\n", max->data.address);
			printf("�Ҽ� �а� : %s\n", max->data.department);
			printf("���� : %d\n", max->data.score);
		}
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}

}
*/

/*
// 7��
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	char data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;


// 2. ��ȸ (������ȸ�� ���)
void Traverse(TreeNode *node) {
	if (node) {
		Traverse(node->left);
		printf("%c_", node->data);
		Traverse(node->right);
	}
}


// 1. �Է� - ����
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// �������� �̵�
		if (node->data > newNode->data) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // ���������� �̵�
		else if (node->data < newNode->data) {
			if (node->right != NULL) node = node->right;
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
	printf("������ ���� : ");
	scanf(" %c", &tmp->data);
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
			printf("%c (root)��� �����Ϸ�.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("%c ��� �����Ϸ�.\n", key->data);
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
			printf("%c (root)��� �����Ϸ�.\n", key->data);
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("%c ��� �����Ϸ�.\n", key->data);
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

			printf("%c (root)��� �����Ϸ�.\n", key->data);
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
			printf("%c ��� �����Ϸ�.\n", key->data);
			return;
		}
		find_parent_two_child(node->left, key);
		find_parent_two_child(node->right, key);
	}
}


// 3. ����
void remove() {
	char val; // �����Ұ�
	TreeNode *key = NULL;  // ������ ��� 
	printf("������ Ű���� �Է��Ͻÿ� : ");
	scanf(" %c", &val);
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
			if (key->left != NULL) // ���� �ڽ��� ���
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

void search_traverse(TreeNode* node, char key, bool &bit) {
	if (node) {
		if (node->data == key) {
			printf("%c �� �����մϴ�!\n", node->data);
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
	printf("�˻��� ���� : ");
	scanf(" %c", &c);
	search_traverse(Head, c, bit);
	if(bit == false) printf("%c�� �������� �ʽ��ϴ�!\n", c);
}
void main()
{
	int n;

	for (;;) {
		printf("\n=== �޴� ===\n");
		printf("1. Ʈ�����\n");
		printf("2. ���ڻ���\n");
		printf("3. ���ڻ���\n");
		printf("4. ���ڰ˻�\n");
		printf("5. ����\n");
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
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}

}
*/


/*
// 8��
#include<stdio.h>
#include<stdlib.h>

typedef struct ST {
	int num;  // ��ȣ
	char name[20];  // �̸�
}element;

typedef struct Tree {
	element data;
	struct Tree *left, *right;
}TreeNode;

TreeNode *Head = NULL;

// 2. ��ȸ (������ȸ�� ���)
void Traverse(TreeNode *node) {
	if (node) {
		Traverse(node->left);
		printf("%d %s\n", node->data.num, node->data.name);
		Traverse(node->right);
	}
}


// 1. �Է� - ����
void traverse_for_insert(TreeNode *node, TreeNode *newNode) {

	while (true) {
		// �������� �̵�
		if (node->data.num > newNode->data.num) {
			if (node->left != NULL) node = node->left;
			else { node->left = newNode;  break; }
		} // ���������� �̵�
		else if (node->data.num < newNode->data.num) {
			if (node->right != NULL) node = node->right;
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
	printf("��ȣ : "); scanf("%d", &tmp->data.num);
	printf("�̸� : "); scanf("%s", &tmp->data.name);
	if (Head == NULL) {
		Head = tmp;
	}
	else traverse_for_insert(Head, tmp);
}


// 3. ���� - ������ ��� ã��
void traverse_for_delete(TreeNode *node, int key, TreeNode **search) {
	if (node) {
		if (node->data.num == key) *search = node;
		traverse_for_delete(node->left, key, search);
		traverse_for_delete(node->right, key, search);
	}

}

// 3. ���� �������� - 1. �ڽĳ�尡 ���� ���  - �θ��� ã��
void find_parent_no_child(TreeNode *node, TreeNode *key) {  // Head, �����ҳ��
	if (node) {
		if (Head == key) {       // ������ ��尡 ��Ʈ����� ���
			Head = NULL;
			printf("�����Ϸ�!\n");
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = NULL;
			else node->right = NULL;
			printf("�����Ϸ�!\n");
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
			printf("�����Ϸ�!\n");
			return;
		}
		if (node->left == key || node->right == key) {
			if (node->left == key) node->left = child;
			else node->right = child;
			printf("�����Ϸ�!\n");
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

			printf("�����Ϸ�!\n");
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
			printf("�����Ϸ�!\n");
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
	printf("������ ��ȣ : ");
	scanf("%d", &val);
	traverse_for_delete(Head, val, &key);
	if (key == NULL) printf("�Է��Ͻ� ��ȣ�� �������� �ʽ��ϴ�.\n");
	else {
		//printf("ã�ҽ��ϴ�!  %d", key->data);
		// 1. �ڽĳ�尡 ���� ���(�ܸ������ ���)
		if (key->left == NULL && key->right == NULL) {
			find_parent_no_child(Head, key);
		}
		// 2. �ڽĳ�尡 �ϳ��� ���
		else if ((key->left != NULL && key->right == NULL) || (key->left == NULL && key->right != NULL)) {
			if (key->left != NULL) // ���� �ڽ��� ���
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
	printf("�˻���ȣ : ");
	scanf(" %d", &num);
	search_traverse(Head, num, bit);
	if (bit == false) printf("%d ��ȣ�� �������� �ʽ��ϴ�!\n", num);
}

void main()
{
	int n;

	for (;;) {
		printf("\n=== �޴� ===\n");
		printf("1. �Է�\n");
		printf("2. ����Ʈ ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("5. ����\n");
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
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}

}
*/

