/*
// 1페이지 1번

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	int readData;


	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);

		if (readData < 1) break;


		// 노드의 추가과정 

		newNode=(Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;

	}
}
*/






/*
// 15페이지 2번

#include<stdio.h>
#include<stdlib.h>
typedef struct intsum {
	int data;
	struct intsum *next;
}Sum;


void add(Sum **sp, Sum **ep, int *length)
{
	int num;
	printf("리스트에 넣을 정수를 입력하시오 : ");
	scanf("%d", &num);

	if (*sp == NULL)
	{
		*sp = (Sum *)malloc(sizeof(Sum));
		*ep = *sp;
	}
	else
	{
		(*ep)->next = (Sum *)malloc(sizeof(Sum));
		*ep = (*ep)->next;
	}
	(*ep)->data = num;
	(*ep)->next = NULL;

	*length += 1;
}

int sum(Sum *sp)
{
	Sum *cp;
	cp = sp;
	int sum = 0;

	while (cp != NULL)
	{
		sum += cp->data;
		cp = cp->next;
	}
	return sum;
}

void add_first(Sum **sp, Sum **ep, int *length)
{
	Sum *new_node;
	new_node = (Sum *)malloc(sizeof(Sum));
	printf("맨 앞에 추가할 값을 입력하시오 : ");
	scanf("%d", &new_node->data);

	if (*sp == NULL)
	{
		*sp = (Sum *)malloc(sizeof(Sum));
		*ep = *sp;

		(*ep)->data = new_node->data;
		(*ep)->next = NULL;
	}
	else {
		new_node->next = *sp;
		*sp = new_node;
	}
	*length += 1;

	

}

void add_last(Sum **ep, Sum **sp, int *length)
{
	Sum *new_node;
	new_node = (Sum *)malloc(sizeof(Sum));
	printf("맨 끝에 추가할 값을 입력하시오 : ");
	scanf("%d", &new_node->data);

	if (*sp == NULL)
	{
		*sp = (Sum *)malloc(sizeof(Sum));
		*ep = *sp;

		(*ep)->data = new_node->data;
		(*ep)->next = NULL;
	}
	else {
		(*ep)->next = new_node;
		new_node->next = NULL;
		(*ep) = (*ep)->next;
	}


	*length += 1;
}

void insert_node(Sum **sp, int *length)
{
	int n;
	printf("몇 번째 노드 뒤에 삽입하시겠습니까? : ");
	scanf("%d", &n);
	Sum *new_node;
	new_node = (Sum *)malloc(sizeof(Sum));

	Sum *cp, *bp;
	cp = *sp;
	bp = cp;

	if (n < 1 || *length <= n) printf("삽입이 불가능합니다\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			bp = cp;
			cp = cp->next;
		}

		printf("삽입할 정수를 입력하시오 : ");
		scanf("%d", &new_node->data);

		bp->next = new_node;
		new_node->next = cp;

		*length += 1;
	}
}

void remove_node(Sum **sp, Sum **ep, int *length)
{
	int n;
	printf("몇 번째 노드를 삭제하시겠습니까 ? : ");
	scanf("%d", &n);
	Sum *bp, *cp;
	cp = *sp;
	bp = cp;

	if (n < 1 || *length < n) printf("삭제가 불가능합니다\n");

	else if (n == 1) {
		*sp = cp->next;
		*length -= 1;
	}

	else if (n == *length) {
		while (cp != *ep)
		{
			bp = cp;
			cp = cp->next;
		}
		bp->next = NULL;
		*ep = bp;

		*length -= 1;
	}
	else {
		cp = *sp;
		for (int i = 0; i < n-1; i++)
		{
			bp = cp;
			cp = cp->next;
		}
		bp->next = cp->next;

		*length -= 1;
	}

}

void display(Sum **sp)
{
	Sum *cp;
	cp = *sp;
	printf("저장데이터 : ");
	while (cp != NULL)
	{
		printf("%d  ", cp->data);
		cp = cp->next;
	}
	printf("\n");
}

int get_length(int length)
{
	return length;
}

int get_entry(Sum **sp, int length)
{
	int n;
	Sum *cp;
	cp = *sp;

	printf("몇 번째 리스트를 반환받으시겠습니까? : ");
	scanf("%d", &n);

	if (n < 1 || length < n) printf("반환이 불가능합니다\n");
	else {
		for (int i = 0; i < n-1; i++)
		{
			cp = cp->next;
		}
		return (cp->data);
	}
}



void clear(Sum **sp, Sum **ep, int *length)
{
	*sp = NULL;
	*ep = NULL;
	*length = 0;
}


void main()
{
	int n;
	Sum *sp, *ep;
	sp = ep = NULL;
	int length = 0;

	for (;;)
	{
		printf("1.입력\n2.합계\n3.맨앞에 추가\n4.맨끝에 추가\n5.(중간)삽입\n6.삭제\n7.리스트 출력\n");
		printf("8.리스트의 길이 반환\n9.특정 리스트 값 반환\n10.삭제후 삭제한 요소 반환\n11.리스트 초기화\n12.종료\n");
		printf("==> ");
		scanf("%d", &n);


		if (n == 12) break;

		if (n == 1) add(&sp, &ep, &length);
		if (n == 2) printf("합 : %d\n\n",sum(sp));
		if (n == 3) add_first(&sp, &ep,&length);
		if (n == 4) add_last(&ep,&sp, &length);
		if (n == 5) insert_node(&sp, &length);
		if (n == 6) remove_node(&sp, &ep, &length);   
		if (n == 7) display(&sp);
		if (n == 8)printf("리스트의 길이 : %d\n", get_length(length));
		if (n == 9) get_entry(&sp, length);
		if (n == 11) clear(&sp, &ep, &length);
	}
}

*/





/*

// 16페이지 6번

#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node *next;
}NODE;


void Alist(NODE **sp, NODE **ep)
{
	int num;
	printf("값을 입력하시오 : ");
	scanf("%d", &num);
	if (*sp == NULL)
	{
		*sp = (NODE *)malloc(sizeof(NODE));
		*ep = *sp;

	}
	else {
		(*ep)->next = (NODE *)malloc(sizeof(NODE));
		*ep = (*ep)->next;
	}

	(*ep)->data = num;
	(*ep)->next = NULL;

	NODE *cp;
	cp = *sp;

	while (cp != NULL)
	{
		printf("%d  ", cp->data);
		cp = cp->next;
	}
	printf("\n");
}


void Blist(NODE **sp, NODE **ep)
{
	int num;
	printf("값을 입력하시오 : ");
	scanf("%d", &num);
	if (*sp == NULL)
	{
		*sp = (NODE *)malloc(sizeof(NODE));
		*ep = *sp;

	}
	else {
		(*ep)->next = (NODE *)malloc(sizeof(NODE));
		*ep = (*ep)->next;
	}

	(*ep)->data = num;
	(*ep)->next = NULL;

	NODE *cp;
	cp = *sp;

	while (cp != NULL)
	{
		printf("%d  ", cp->data);
		cp = cp->next;
	}
	printf("\n");

}


void Clist(NODE **Asp, NODE **Bsp)
{
	NODE *Acp, *Bcp;
	Acp = *Asp;
	Bcp = *Bsp;

	NODE *sp, *ep, *cp;
	sp = ep = NULL;
	

	while (Acp != NULL && Bcp != NULL)
	{
		if (sp == NULL)
		{
			sp = (NODE *)malloc(sizeof(NODE));
			ep = sp;
		}

		else {
			ep->next = (NODE *)malloc(sizeof(NODE));
			ep = ep->next;
		}


		if (Acp->data<Bcp->data)
		{
			ep->data = Acp->data;
			ep->next = NULL;
			Acp = Acp->next;
		}

		else if (Bcp->data<Acp->data)
		{
			ep->data = Bcp->data;
			ep->next = NULL;
			Bcp = Bcp->next;
		}


	}


	if (Acp == NULL)
	{
		while (Bcp != NULL)
		{
			ep->next = (NODE *)malloc(sizeof(NODE));
			ep = ep->next;

			ep->data = Bcp->data;
			ep->next = NULL;
			Bcp = Bcp->next;
		}
	}

	if (Bcp == NULL)
	{
		while (Acp != NULL)
		{
			ep->next = (NODE *)malloc(sizeof(NODE));
			ep = ep->next;

			ep->data = Acp->data;
			ep->next = NULL;
			Acp = Acp->next;
		}
	}


	cp = sp;
	while (cp != NULL)
	{
		printf("%d  ", cp->data);
		cp = cp->next;
	}
	printf("\n");
}


void main()
{
	NODE *Asp, *Aep;
	NODE *Bsp, *Bep;

	Asp = Aep = NULL;
	Bsp = Bep = NULL;
	int n;

	for (;;)
	{
		printf("1. A 리스트 입력\n");					// 단, AB는 오름차순으로 정렬되어있다는 전제
		printf("2. B 리스트 입력\n");
		printf("3. C 병합 연결리스트 출력\n");
		printf("4. 종료\n");
		scanf("%d", &n);

		if (n == 4) break;

		if (n == 1) Alist(&Asp,&Aep);
		if (n == 2) Blist(&Bsp,&Bep);

		if (n == 3) Clist(&Asp,&Bsp);
		
	}


}


*/

