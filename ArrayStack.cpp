
// === ArrayStack.cpp

/*
#include<stdio.h>							--> 구조체 사용 안한 스택 함수
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
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}

element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return (stack[top]);
}

*/








// 구조체 사용한 스택 함수 (스택이랑 탑을 하나의 구조체에)



// === ArrayStack.cpp

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "ArrayStack.h"

// 스택 초기화 함수
void init(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		printf("스택 포화 에러\n");				// fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else s->stack[++(s->top)] = item;
}

// 삭제 함수(삭제 후 반환)
element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");				// fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

// 피크함수(삭제x 반환만)
element peek(StackType *s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");				// fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];

}



void display(StackType *s)				// 스택 요소 처음부터 다 출력하는 함수 			
{
	for (int i = 0; i <= s->top; i++)
		printf("%d , %d\n", s->stack[i]);
	printf("\n");
}




/*
int check(char str[])					// (식)괄호 검사하는 함수  (리턴값이 1이면 괄호 맞는거, 0이면 괄호 틀린거)
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
int pre(char fir, char sec)       // 부호 우선순위 파악하는 함수
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



