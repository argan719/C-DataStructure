
/*
// 1������ 1��								--> �̰͵� ������ ���� �⺻��   �� �����س��� ��Ա�

// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include "ArrayStack.h"

void main()
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", is_empty());
}
*/









/*
// �������� ��� ����ü ����� ����    -- --> �� �����س��� ��Ա�
// 5������ 3��											



// === ArrayStack.h
#ifndef ArraySTACK
# define ArrayStack

# define MAX_STACK_SIZE 100

#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING]
}element;


typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType *s);
int is_empty(StackType *s);
int is_full(StackType *s);
void push(StackType *s, element item);
element pop(StackType *s);
element peek(StackType *s);

#endif







// === ArrayStack.cpp


#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "ArrayStack.h"

// ���� �ʱ�ȭ �Լ�
void init(StackType *s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");				// fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

// ���� �Լ�(���� �� ��ȯ)
element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");				// fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

// ��ũ�Լ�(����x ��ȯ��)
element peek(StackType *s)
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");				// fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];

}

*/







/*

// 10������ 5��
// === main.cpp


#include<stdio.h>
#include<string.h>
#include "ArrayStack.h"

int check(char str[])
{
	int length = strlen(str);
	StackType s;

	for (int i = 0; i < length; i++)
	{
		if (i == 0) init(&s);

		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			push(&s, str[i]);
		}
		else if (str[i] == ')')
		{
			if (peek(&s) != '(') return 0;
			else pop(&s);
		}
		else if (str[i] == ']')
		{
			if (peek(&s) != '[') return 0;
			else pop(&s);

		}
		else if (str[i] == '}')
		{
			if (peek(&s) != '{') return 0;
			else pop(&s);
		}

	}
	if (is_empty(&s)) return 1;
	else return 0;

}


int main()
{
	char str[30];
	printf("��ȣ�� �˻��� ���� �Է��Ͻÿ� :");
	gets_s(str);


	if (check(str)) printf("��ȣ�� �½��ϴ�\n");
	else printf("��ȣ�� Ʋ���ϴ�\n");

}

*/







/*

// 13������ 6��
// ����ǥ��� ��ȯ
// === main.cpp			

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ArrayStack.h"

int change(char str[], char value[])
{
	StackType s;
	int k = 0;
	int length = strlen(str);
	char c;


	if (check(str))
	{
		init(&s);
		for (int i = 0; i < length; i++)
		{
			
			if (str[i] == '(') { push(&s, str[i]);  continue; }

			else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
			{
				if (is_empty(&s)) push(&s, str[i]);

				else if (pre(peek(&s), str[i]))
				{
					// ���� �տ� �ִ� ��ȣ �켱������ �� ���ų� ������
					value[k] = pop(&s);
					push(&s, str[i]);
					k++;

				}
				else push(&s, str[i]);

			}

			else if (str[i] == ')')
			{
				for (;;)
				{
					c=pop(&s);
					if (c == '(') break;
					value[k] = c;
					k++;
				}
			}

			else {
				value[k] = str[i];
				k++;
			}
		}
		

		while (!is_empty(&s))
		{
			value[k] = pop(&s);
			k++;
		}
	}

	return k;

	
}

void main()
{
	char value[30];

	char str[30];
	for (;;)
	{
		printf("������ �Է��Ͻÿ� (x �Է� �� ����) : ");
		gets_s(str);
		if (str[0] == 'x') break;

		int length = change(str, value);

		for (int i = 0; i < length; i++)
			printf("%c", value[i]);
		printf("\n");
	}
	
}

*/








/*
// 23������ 7��
// ���� �����

// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ArrayStack.h"



int change(char str[], char value[])
{
	StackType s;
	int k = 0;
	int length = strlen(str);
	char c;


	if (check(str))
	{
		init(&s);
		for (int i = 0; i < length; i++)
		{

			if (str[i] == '(') { push(&s, str[i]);  continue; }

			else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
			{
				if (is_empty(&s)) push(&s, str[i]);

				else if (pre(peek(&s), str[i]))
				{
					// ���� �տ� �ִ� ��ȣ �켱������ �� ���ų� ������
					value[k] = pop(&s);
					push(&s, str[i]);
					k++;

				}
				else push(&s, str[i]);

			}

			else if (str[i] == ')')
			{
				for (;;)
				{
					c = pop(&s);
					if (c == '(') break;
					value[k] = c;
					k++;
				}
			}

			else {
				value[k] = str[i];
				k++;
			}
		}


		while (!is_empty(&s))
		{
			value[k] = pop(&s);
			k++;
		}
	}

	return k;

}


int calculate(char result[])			// ����ϴ� �Լ� (����) - ���ڸ� �����
{
	StackType s;
	init(&s);
	char type;
	int n3, n1, n2;
	int end = strlen(result);
	for (int i = 0; i < end; i++)
	{
		if (result[i] == '*' || result[i] == '/' || result[i] == '+' || result[i] == '-')
		{
			type = result[i];
			char t = pop(&s);
			char f = pop(&s);

			if (48 <= t && t <= 57)  n2 = t - 48;
			if (48 <= f && f <= 57) n1 = f - 48;

			if (type == '*') {
				n3 = n1 * n2;
				printf("\n%d\n", n3);
				push(&s, n3 + 48);
			}
			else if (type == '/') {
				n3 = n1 / n2;
				printf("\n%d\n", n3);

				push(&s, n3 + 48);
			}
			else if (type == '+') {
				n3 = n1 + n2;
				printf("\n%d\n", n3);

				push(&s, n3 + 48);
			}
			else if (type == '-') {
				n3 = n1 - n2;
				printf("\n%d\n", n3);

				push(&s, n3 + 48);
			}
		}

		else push(&s, result[i]);
		return n3;

	}
}



void main()
{
	char value[30];
	int i;
	char str[30];
	char result[30];
	for (;;)
	{
		printf("������ �Է��Ͻÿ� (x �Է� �� ����) : ");
		gets_s(str);
		if (str[0] == 'x') break;

		int length = change(str, value);

		printf("=== ���� ǥ�� ��� ===\n");
		for (i = 0; i < length; i++)
		{
			printf("%c", value[i]);
			result[i] = value[i];
		}
		result[i] = NULL;
		printf("\n");

		printf("=== ��� ��� ===\n");
		printf("%d\n", calculate(result));
	

	}

}

*/








/*

// 21������ 2��
// ����� ���Ḯ��Ʈ ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ArrayStack.h"

void create(StackType *s, student **sp, student **ep)
{
	student *bp;
	bp = NULL;

	if (*sp == NULL)
	{
		*sp = (student *)malloc(sizeof(student));
		*ep = *sp;
		(*sp)->before = NULL;
	}
	else
	{
		(*ep)->next = (student *)malloc(sizeof(student));
		bp = *ep;
		*ep = (*ep)->next;
	}
	printf("�й� : ");
	scanf("%d", &(*ep)->num);
	printf("�̸� : ");
	scanf("%s", (*ep)->name);
	printf("��ȭ��ȣ : ");
	scanf("%s",(*ep)->tell);
	(*ep)->next = NULL;
	(*ep)->before = bp;

	push(s, **ep);
}


void display_list(StackType *s)
{
	
	for (int i = 0; i <= s->top; i++)
		printf("�й� : %d  �̸� : %s  ��ȭ��ȣ :  %s\n", s->stack[i].num, s->stack[i].name, s->stack[i].tell);
	printf("\n");
	
}


void remove(student **sp, student **ep)
{
	student *cp, *bp;
	bp = NULL;
	cp = *sp;
	while (cp->next != NULL)
	{
		bp = cp;
		cp = cp->next;
	}
	bp->next = NULL; 
	*ep = bp;
}



void main()
{
	student temp;
	int n;
	StackType s;
	student *sp, *ep;
	sp = ep = NULL;
	init(&s);

	for (;;)
	{
		printf("1.push  2.pop  3.list  4.����  =>  ");
		scanf("%d", &n);

		if (n == 4) break;

		if (n == 1) create(&s, &sp, &ep);
		if (n == 2) { temp = pop(&s); printf("%d  %s  %s\n", temp.num, temp.name, temp.tell); remove(&sp, &ep); }
		if (n == 3) display_list(&s);
	}
}


*/






/*

// 21������ 1��
// �̷� ã��

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ArrayStack.h"

int miro[6][6] = { {1,1,1,1,1,1},{0,0,0,0,1,1},{1,1,0,1,1,1},{1,1,0,1,1,1,},{1,0,0,0,0,0},{1,1,1,1,1,1} };

void main()
{
	StackType s;
	pos p;
	int a = 1, b = 0;
	pos end = { 4,5 };
	init(&s);
	pos error = { -1,-1 };

	for (;;)
	{

		if (a == end.x && b == end.y) { printf("Ż�⼺��\n"); printf("Ż����\n"); display(&s);  break; }

		if (miro[a - 1][b] == 0) { p = { a - 1,b }; push(&s, p); }

		else if (miro[a][b + 1] == 0) { p = { a ,b + 1 }; push(&s, p); }

		else if (miro[a + 1][b] == 0) { p = { a + 1,b };  push(&s, p); }

		else if (miro[a][b - 1] == 0) { p = { a,b - 1 }; push(&s, p); }

		else {
			if (error.x == pop(&s).x && error.y==pop(&s).y) { printf("Ż�����\n"); break; }
			else p = peek(&s);
		}

		miro[a][b] = 9;
		a = p.x;
		b = p.y;


	}
}

*/








/*
// 24������ 8��
// ������ ž


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ArrayStack.h"


void main()
{
	StackType s;
	init(&s);

	int n, k;
	int high;
	printf("ž�� ���� : ");
	scanf("%d", &n);
	int cnt = n;

	for (int i = 1; i <= n; i++)
	{
		printf("%d��° ž�� ���� : ", i);   // ���� �� �ѹ��� �� ���� ������ �ٽ� �������� ���鼭 pop�Ϥ���
		scanf("%d", &high);
		push(&s, high);
	}

	int *top;
	top = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		top[i] = s.stack[i];					// �迭�� ���� ������ ����
	}
	printf("\n");

	for (int i = n; 1<=i; i--)
	{
		printf("%d��° ž\n", i);

		int now = pop(&s);
		for (k = i - 2; 0 <= k; k--)
		{
			if (now <= top[k]) break;
		}
		if (k < 0) k = -1;
	
		printf("==> ���Ű����� ž %d��\n\n", k+1);
	}
}

*/







