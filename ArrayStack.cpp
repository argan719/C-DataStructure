
// === ArrayStack.cpp

/*
#include<stdio.h>							--> ����ü ��� ���� ���� �Լ�
#include<Stdlib.h>
#include "ArrayStack.h"

int is_empty()
{
	return (top == -1);
}

int is_full()
{
	return (top == (MAX_STACK_SIZE-1));
}


void push(element item)
{
	if (is_full())
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return (stack[top]);
}

*/








// ����ü ����� ���� �Լ� (�����̶� ž�� �ϳ��� ����ü��)



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
		exit(1);
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



void display(StackType *s)				// ���� ��� ó������ �� ����ϴ� �Լ� 			
{
	for (int i = 0; i <= s->top; i++)
		printf("%d , %d\n", s->stack[i]);
	printf("\n");
}




/*
int check(char str[])					// (��)��ȣ �˻��ϴ� �Լ�  (���ϰ��� 1�̸� ��ȣ �´°�, 0�̸� ��ȣ Ʋ����)
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
*/




/*
int pre(char fir, char sec)       // ��ȣ �켱���� �ľ��ϴ� �Լ�
{
	int f, s;

	if (fir == '(') f = 0;
	else if (fir == '*' || fir == '/' ) f = 2; 
	else f = 1; 

	if (sec == '(') s = 0;
	else if (sec == '*' || sec == '/' ) s = 2;
	else s = 1;


	if (s <= f) return 1;
	else if (f < s) return 0;

}
*/



