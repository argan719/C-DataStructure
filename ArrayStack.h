#pragma once

// === ArrayStack.h

/*
#ifndef ArraySTACK					.-->  ����ü �����ϰ� (static �������� ����ؼ�) ���� ���� ����Լ�
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








// ����ü ����� ���� ����Լ�


// === ArrayStack.h

#ifndef ArraySTACK
# define ArraySTACK

# define MAX_STACK_SIZE 100

#define MAX_STRING 100

#define TRUE 1
#define FALSE 0



typedef int element;					 // ���� �ٸ��� ���� ������ element�� �ٲ��ָ� ��

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

void display(StackType *s);	// ���� ��� �� ����ϴ� �Լ�

int check(char str[]);		// ��ȣ �˻��ϴ� �Լ�


int pre(char fir, char sec);  // ��ȣ �켱���� �Լ�


#endif






