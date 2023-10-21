#pragma once

// === ArrayStack.h

/*
#ifndef ArraySTACK					.-->  구조체 사용안하고 (static 전역변수 사용해서) 만든 스택 헤더함수
# define ArraySTACK


# define MAX_STACK_SIZE 100
typedef int element;
static element stack[MAX_STACK_SIZE];
static int top = -1;

int is_empty();
int is_full();
void push(element item);
element pop();
element peek();

#endif

*/








// 구조체 사용한 스택 헤더함수


// === ArrayStack.h

#ifndef ArraySTACK
# define ArraySTACK

# define MAX_STACK_SIZE 100

#define MAX_STRING 100

#define TRUE 1
#define FALSE 0



typedef int element;					 // 문제 다른거 만들 때마다 element만 바꿔주면 됨

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

void display(StackType *s);	// 스택 요소 다 출력하는 함수

int check(char str[]);		// 괄호 검사하는 함수


int pre(char fir, char sec);  // 부호 우선순위 함수


#endif






