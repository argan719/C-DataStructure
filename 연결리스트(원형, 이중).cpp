

/*
// 13������ 1��

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
		printf("����� �̸��� �Է��Ͻÿ� : ");
		scanf("%d%s", &ep->num, ep->name);

	}



	printf("������� : ");
	cp = sp;

	while (cp != ep)
	{
		printf("%d - %s  ", cp->num, cp->name);
		cp = cp->next;
	}
	printf("%d - %s\n\n", cp->num, cp->name);

	for (;;)
	{
		printf("������ ������ȣ : ");
		scanf("%d", &stnum);
		if (stnum == 0) break;

		printf("�ǳʶ� ���� : ");
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
// 1������ 1�� �Է�

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
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

// phead : ����Ʈ�� ��� �������� ������
// p : ���� ���
// node : ���Ե� ���

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
// �� �Է¾��� ���� �Է��ϱ� 
