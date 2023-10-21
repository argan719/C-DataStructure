
/*
// 1페이지 1번								--> 이것도 스택의 완전 기본형   잘 보관해놓고 써먹기

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
// 전역변수 대신 구조체 사용한 스택    -- --> 잘 보관해놓고 써먹기
// 5페이지 3번											



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
		return;
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

*/







/*

// 10페이지 5번
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
	printf("괄호를 검사할 식을 입력하시오 :");
	gets_s(str);


	if (check(str)) printf("괄호가 맞습니다\n");
	else printf("괄호가 틀립니다\n");

}

*/







/*

// 13페이지 6번
// 후위표기법 변환
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
					// 원래 앞에 있던 부호 우선순위가 더 높거나 같을때
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
		printf("계산식을 입력하시오 (x 입력 시 종료) : ");
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
// 23페이지 7번
// 계산기 만들기

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
					// 원래 앞에 있던 부호 우선순위가 더 높거나 같을때
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


int calculate(char result[])			// 계산하는 함수 (계산기) - 한자리 양수만
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
		printf("계산식을 입력하시오 (x 입력 시 종료) : ");
		gets_s(str);
		if (str[0] == 'x') break;

		int length = change(str, value);

		printf("=== 후위 표기 결과 ===\n");
		for (i = 0; i < length; i++)
		{
			printf("%c", value[i]);
			result[i] = value[i];
		}
		result[i] = NULL;
		printf("\n");

		printf("=== 계산 결과 ===\n");
		printf("%d\n", calculate(result));
	

	}

}

*/








/*

// 21페이지 2번
// 양방향 연결리스트 스택

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
	printf("학번 : ");
	scanf("%d", &(*ep)->num);
	printf("이름 : ");
	scanf("%s", (*ep)->name);
	printf("전화번호 : ");
	scanf("%s",(*ep)->tell);
	(*ep)->next = NULL;
	(*ep)->before = bp;

	push(s, **ep);
}


void display_list(StackType *s)
{
	
	for (int i = 0; i <= s->top; i++)
		printf("학번 : %d  이름 : %s  전화번호 :  %s\n", s->stack[i].num, s->stack[i].name, s->stack[i].tell);
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
		printf("1.push  2.pop  3.list  4.종료  =>  ");
		scanf("%d", &n);

		if (n == 4) break;

		if (n == 1) create(&s, &sp, &ep);
		if (n == 2) { temp = pop(&s); printf("%d  %s  %s\n", temp.num, temp.name, temp.tell); remove(&sp, &ep); }
		if (n == 3) display_list(&s);
	}
}


*/






/*

// 21페이지 1번
// 미로 찾기

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

		if (a == end.x && b == end.y) { printf("탈출성공\n"); printf("탈출경로\n"); display(&s);  break; }

		if (miro[a - 1][b] == 0) { p = { a - 1,b }; push(&s, p); }

		else if (miro[a][b + 1] == 0) { p = { a ,b + 1 }; push(&s, p); }

		else if (miro[a + 1][b] == 0) { p = { a + 1,b };  push(&s, p); }

		else if (miro[a][b - 1] == 0) { p = { a,b - 1 }; push(&s, p); }

		else {
			if (error.x == pop(&s).x && error.y==pop(&s).y) { printf("탈출실패\n"); break; }
			else p = peek(&s);
		}

		miro[a][b] = 9;
		a = p.x;
		b = p.y;


	}
}

*/








/*
// 24페이지 8번
// 레이저 탑


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
	printf("탑의 개수 : ");
	scanf("%d", &n);
	int cnt = n;

	for (int i = 1; i <= n; i++)
	{
		printf("%d번째 탑의 높이 : ", i);   // 넣을 때 한번에 다 넣은 다음에 다시 왼쪽으로 가면서 pop하ㅏ기
		scanf("%d", &high);
		push(&s, high);
	}

	int *top;
	top = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		top[i] = s.stack[i];					// 배열에 스택 데이터 복사
	}
	printf("\n");

	for (int i = n; 1<=i; i--)
	{
		printf("%d번째 탑\n", i);

		int now = pop(&s);
		for (k = i - 2; 0 <= k; k--)
		{
			if (now <= top[k]) break;
		}
		if (k < 0) k = -1;
	
		printf("==> 수신가능한 탑 %d번\n\n", k+1);
	}
}

*/







