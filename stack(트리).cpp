
// ���� Ʈ�� ������ȸ (���x ���û��)
// === stack.cpp

#include"node.h"
#define MAX 100
#define TRUE 1
#define FALSE 0

TreeNode *Stack[MAX];
int Top;


void InitStack(void)
{
	Top = 0;
}

void Push(TreeNode *ptrNode)
{
	Stack[Top] = ptrNode;
	Top = (Top++) % MAX;
}

TreeNode *Pop(void)
{
	TreeNode *ptrNode;
	if (!IsStackEmpty()) {
		ptrNode = Stack[--Top];
		return ptrNode;
	}
	else
		printf("Stack is Empty!\n");
	return NULL;
}

int IsStackEmpty(void)
{
	if (Top == 0)
		return TRUE;
	else
		return FALSE;
}


/*
// (pop���� �ʰ�) top ���� 
TreeNode* Peek() {
	return Stack[Top];
}

*/
