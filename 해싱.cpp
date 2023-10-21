

// �ؽ��Լ� ���ַ� ����
// �ؽ��Լ� ������� ���� ����ϴ���
// ����Ʈ�� �ִ°� �ϳ��ϳ� �Է��غ��� �Ĳ��� �����ϱ�

// �浹 ��� �ذ��ϴ���


/*

// ����������� ����-1
// �ؽ� ���̺� ����, ���ϴ� �ϳ��� ������ �����Ѵ�
#define KEY_SIZE 10   // Ž��Ű�� �ִ����
#define TABLE_SIZE 13   // �ؽ� ���̺��� ũ��=�Ҽ�
typedef struct
{
	char key[KEY_SIZE];
	// �ٸ� �ʿ��� �ʵ���� ���⿡ �ִ´�.
}element;
element hash_table[TABLE_SIZE];    // �ؽ� ���̺�


// ����������� ����-2
// �ؽ����̺��� �ʱ�ȭ����
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}

// ����������� ����-3
// ���ڷ� �� Ž��Ű�� ���ڷ� ��ȯ
int transform(char *key)
{
	int number = 0;
	while (*key)        // ������ ���� ��� ��� �ڿ��� ����
		number += *key++;
	return number;
}
// ���� �Լ��� ����� �ؽ��Լ�
int hash_function(char *key)
{
	return transform(key) % TABLE_SIZE;
}



// ����������� ����-4
#define empty(e) (strlen(e.key)==0)
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// ����������� �̿��Ͽ� ���̺� Ű�� �����ϰ�,
// ���̺��� ���� �� ���� ����
void hash_Ip_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
			return;
		}
	}
	ht[i] = item;
}



// ����������� ����-5

//����������� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_Ip_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž������: ��ġ = %d\n", i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "ã�� ���� ���̺� ����\n");
			return;
		}
	}
	fprintf(stderr, "ã�� ���� ���̺� ����\n");
}



// ����������� ����-6
// �ؽ� ���̺��� ������ ���
void hash_Ip_print(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]   %s\n", i, ht[i].key);
	
}
// �ؽ� ���̺��� ����� ����
main()
{
	element tmp;
	int op;
	while (1) {
		printf("���ϴ� ������ �Է��Ͻÿ�(0=�Է�, 1=Ž��, 2=����) : ");
		scanf("%d", &op);
		if (op == 2) break;
		printf("Ű�� �Է��Ͻÿ�=");
		scanf("%s", tmp.key);
		if (op == 0)
			hash_Ip_add(tmp, hash_table);
		else if (op == 1)
			hash_Ip_search(tmp, hash_table);
		hash_Ip_print(hash_table);
	}
}

*/



/*

// �ؽ����α׷��� �ϼ��Ͽ� ���ô�.
#include<stdio.h>
#include<string.h>

// �ؽ� ���̺� ����, ���ϴ� �ϳ��� ������ �����Ѵ�.
#define KEY_SIZE 10    // Ž��Ű�� �ִ����
#define TABLE_SIZE 13   // �ؽ� ���̺��� ũ��(=�Ҽ�)
typedef struct {
	char key[KEY_SIZE];
	// �ٸ� �ʿ��� �ʵ���� ���⿡ �ִ´�.
}element;

element hash_table[TABLE_SIZE];   // �ؽ� ���̺�


// �ؽ����̺��� �ʱ�ȭ ����
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}

// ���ڷ� �� Ž��Ű�� ���ڷ� ��ȯ
int transform(char *key)
{
	int number = 0;
	while (*key)       // ������ ���� ��� ��� �ڿ��� ����
		number += *key++;
	return number;
}
// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char *key)
{
	return transform(key) % TABLE_SIZE;
}

#define empty(e) (strlen(e.key)==0)
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// ���� ������� �̿��Ͽ� ���̺� Ű�� �����ϰ�,
// ���̺��� ���� �� ���� ����
void hash_Ip_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "����Ű�� �ߺ��Ǿ����ϴ�\n");
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
			return;
		}
	}
	ht[i] = item;
}

// ����������� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_Ip_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž������! ��ġ = %d\n", i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "ã�� ���� ���̺� ����\n");
			return;
		}
	}
	fprintf(stderr, "ã�� ���� ���̺� ����\n");
}

// �ؽ� ���̺��� ������ ���
void hash_Ip_print(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]   %s\n", i, ht[i].key);
}


// �ؽ� ���̺��� ����� ����
void main()
{
	element tmp;
	int op;
	while (1) {
		printf("���ϴ� ������ �Է��Ͻÿ�(0=�Է�, 1=Ž��, 2=����) : ");
		scanf("%d", &op);
		if (op == 2) break;
		printf("Ű�� �Է��Ͻÿ�=");
		scanf("%s", tmp.key);
		if (op == 0)
			hash_Ip_add(tmp, hash_table);
		else if (op == 1)
			hash_Ip_search(tmp, hash_table);
		hash_Ip_print(hash_table);
	}
}
*/



/*
// ����������� ����

void hash_qp_add(element item, element ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	// printf("hash_address=%d\n", i);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
			exit(1);
		}
		i = (hash_value + inc * inc) % TABLE_SIZE;
		inc = inc + 1;
		if (i == hash_value) {
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
			exit(1)
		}
	}
	ht[i] = item;
}
*/



/*
// ���� �ؽ̹� ����

void hash_dh_add(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
			return;
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
			exit(1);
		}
	}
	ht[i] = item;
}

*/




/*

// ���̺�� �ؽ��� �����Ͽ� ���ô�.

// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;    // Ű�� �κ������θ� ����� ���� ���� ���� �ؽ��� ��!!!
}

int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;
	TBLInit(&myTbl, MyHashFunc);
	// ������ �Է�
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ �˻�
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20130012);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20170049);
	if (sp != NULL)
		ShowPerInfo(sp);


	// ������ ����
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL)
		free(rp);

	return 0;
}

*/




/*
// ü�̴��� ����
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// ü�ι��� �̿��Ͽ� ���̺� Ű�� ����
void hash_chain_add(element item, ListNode *ht[])
{
	int hash_value = hash_function(item.key);
	ListNode *ptr;        // ���ο� ���
	ListNode *node_before = NULL;   // �������
	ListNode *node = ht[hash_value];  // ������
	for (; node; node_before = node, node = node->link) {
		if (equal(node->item, item)) {
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	ptr = (ListNode *)malloc(sizeof(ListNode));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)       // ������ ���Ḯ��Ʈ�� ������
		node_before->link = ptr;
	else                   // ������ ���Ḯ��Ʈ�� ������
		ht[hash_value] = ptr;
}

// ü�ι��� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_chain_find(element item, ListNode *ht[])
{
	ListNode *node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (equal(node->item, item)) {
			printf("Ű�� ã����\n");
			return;
		}
	}
	printf("Ű�� ã��������\n");
}
*/





// �浹���� �ذ��� ���� ü�̴��� �����Ͽ� ���ô�.
