

// 해싱함수 위주로 공부
// 해싱함수 어떤식으로 만들어서 사용하는지
// 프린트에 있는거 하나하나 입력해보고 꼼꼼히 공부하기

// 충돌 어떻게 해결하는지


/*

// 선형조사법의 구현-1
// 해시 테이블 정의, 버켓당 하나의 슬롯을 가정한다
#define KEY_SIZE 10   // 탐색키의 최대길이
#define TABLE_SIZE 13   // 해싱 테이블의 크기=소수
typedef struct
{
	char key[KEY_SIZE];
	// 다른 필요한 필드들을 여기에 넣는다.
}element;
element hash_table[TABLE_SIZE];    // 해싱 테이블


// 선형조사법의 구현-2
// 해시테이블의 초기화과정
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}

// 선형조사법의 구현-3
// 문자로 된 탐색키를 숫자로 변환
int transform(char *key)
{
	int number = 0;
	while (*key)        // 간단한 덧셈 방식 사용 자연수 생성
		number += *key++;
	return number;
}
// 제산 함수를 사용한 해싱함수
int hash_function(char *key)
{
	return transform(key) % TABLE_SIZE;
}



// 선형조사법의 구현-4
#define empty(e) (strlen(e.key)==0)
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// 선형조사법을 이용하여 테이블에 키를 삽입하고,
// 테이블이 가득 찬 경우는 종료
void hash_Ip_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			return;
		}
	}
	ht[i] = item;
}



// 선형조사법의 구현-5

//선형조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_Ip_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색성공: 위치 = %d\n", i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n");
}



// 선형조사법의 구현-6
// 해싱 테이블의 내용을 출력
void hash_Ip_print(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]   %s\n", i, ht[i].key);
	
}
// 해싱 테이블을 사용한 예제
main()
{
	element tmp;
	int op;
	while (1) {
		printf("원하는 연산을 입력하시오(0=입력, 1=탐색, 2=종료) : ");
		scanf("%d", &op);
		if (op == 2) break;
		printf("키를 입력하시오=");
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

// 해싱프로그램을 완성하여 봅시다.
#include<stdio.h>
#include<string.h>

// 해시 테이블 정의, 버켓당 하나의 슬롯을 가정한다.
#define KEY_SIZE 10    // 탐색키의 최대길이
#define TABLE_SIZE 13   // 해싱 테이블의 크기(=소수)
typedef struct {
	char key[KEY_SIZE];
	// 다른 필요한 필드들을 여기에 넣는다.
}element;

element hash_table[TABLE_SIZE];   // 해싱 테이블


// 해시테이블의 초기화 과정
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}

// 문자로 된 탐색키를 숫자로 변환
int transform(char *key)
{
	int number = 0;
	while (*key)       // 간단한 덧셈 방식 사용 자연수 생성
		number += *key++;
	return number;
}
// 제산 함수를 사용한 해싱 함수
int hash_function(char *key)
{
	return transform(key) % TABLE_SIZE;
}

#define empty(e) (strlen(e.key)==0)
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// 선형 조사법을 이용하여 테이블에 키를 삽입하고,
// 테이블이 가득 찬 경우는 종료
void hash_Ip_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "참색키가 중복되었습니다\n");
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			return;
		}
	}
	ht[i] = item;
}

// 선형조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_Ip_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색성공! 위치 = %d\n", i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n");
}

// 해싱 테이블의 내용을 출력
void hash_Ip_print(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]   %s\n", i, ht[i].key);
}


// 해싱 테이블을 사용한 예제
void main()
{
	element tmp;
	int op;
	while (1) {
		printf("원하는 연산을 입력하시오(0=입력, 1=탐색, 2=종료) : ");
		scanf("%d", &op);
		if (op == 2) break;
		printf("키를 입력하시오=");
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
// 이차조사법의 구현

void hash_qp_add(element item, element ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	// printf("hash_address=%d\n", i);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (hash_value + inc * inc) % TABLE_SIZE;
		inc = inc + 1;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1)
		}
	}
	ht[i] = item;
}
*/



/*
// 이중 해싱법 구현

void hash_dh_add(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			return;
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
		}
	}
	ht[i] = item;
}

*/




/*

// 테이블과 해쉬를 구현하여 봅시다.

// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;    // 키를 부분적으로만 사용한 별로 좋지 않은 해쉬의 예!!!
}

int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;
	TBLInit(&myTbl, MyHashFunc);
	// 데이터 입력
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// 데이터 검색
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20130012);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 20170049);
	if (sp != NULL)
		ShowPerInfo(sp);


	// 데이터 삭제
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
// 체이닝의 구현
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

// 체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, ListNode *ht[])
{
	int hash_value = hash_function(item.key);
	ListNode *ptr;        // 새로운 노드
	ListNode *node_before = NULL;   // 이전노드
	ListNode *node = ht[hash_value];  // 현재노드
	for (; node; node_before = node, node = node->link) {
		if (equal(node->item, item)) {
			fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
			return;
		}
	}
	ptr = (ListNode *)malloc(sizeof(ListNode));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)       // 기존의 연결리스트가 있으면
		node_before->link = ptr;
	else                   // 기존의 연결리스트가 없으면
		ht[hash_value] = ptr;
}

// 체인법을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_find(element item, ListNode *ht[])
{
	ListNode *node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (equal(node->item, item)) {
			printf("키를 찾았음\n");
			return;
		}
	}
	printf("키를 찾지못했음\n");
}
*/





// 충돌문제 해결을 위한 체이닝을 구현하여 봅시다.
