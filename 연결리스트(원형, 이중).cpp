

/*
// 13페이지 1번

#include<stdio.h>
#include<stdlib.h>

typedef struct circle {
	struct circle *before;
	int num;
	char name[30];
	struct circle *next;
}NODE;

void main()
{
	NODE *sp, *ep, *cp;
	sp = ep = NULL;

	int stnum, jump;

	for (int i = 0; i < 5; i++)
	{
		if (sp == NULL)
		{
			sp = (NODE *)malloc(sizeof(NODE));
			ep = sp;
			ep->before = sp;
			ep->next = sp;

		}

		else {
			ep->next = (NODE *)malloc(sizeof(NODE));
			ep->next->before = ep;
			ep = ep->next;
		}

		ep->next = sp;
		sp->before = ep;
		printf("사번과 이름을 입력하시오 : ");
		scanf("%d%s", &ep->num, ep->name);

	}



	printf("직원명단 : ");
	cp = sp;

	while (cp != ep)
	{
		printf("%d - %s  ", cp->num, cp->name);
		cp = cp->next;
	}
	printf("%d - %s\n\n", cp->num, cp->name);

	for (;;)
	{
		printf("시작할 직원번호 : ");
		scanf("%d", &stnum);
		if (stnum == 0) break;

		printf("건너뛸 간격 : ");
		scanf("%d", &jump);

		cp = sp;
		for (;;)
		{
			if (cp->num == stnum) break;
			cp = cp->next;
		}
		ep = cp;

		for (;;)
		{
			printf("%d - %s  ", cp->num, cp->name);
			for (int i = 0; i < jump; i++)
				cp = cp->next;
			if (cp == ep) break;

		}
		printf("\n");

	}

}
*/




/*
// 1페이지 1번 입력

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNODE {
	element data;
	struct ListNODE *link;
}ListNode;


ListNode *create_node(element data, ListNode *link);
void insert_first(ListNode **phead, ListNode *node);
void insert_last(ListNode **phead, ListNode *node);
void display(ListNode *head);;



ListNode *create_node(element data, ListNode *link)
{
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
	{
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

// phead : 리스트의 헤드 포인터의 포인터
// p : 선행 노드
// node : 삽입될 노드

void insert_first(ListNode **phead, ListNode *node)
{
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
	}
	
}

*/
// 다 입력안함 마저 입력하기 
