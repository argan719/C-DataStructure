
// 이진트리 전위순회 헤더파일 (재귀x 스택사용)
// === node.h


#ifndef _TreeNode
#define _TreeNode

#include<stdio.h>
#include<stdlib.h>

typedef int Type;


typedef struct TreeNode {
	Type Data;
	struct TreeNode *Left, *Right;
}TreeNode;


// TreeNode *HeadNode, *endNode;


void InitStack(void);
void Push(TreeNode *);
TreeNode *Pop(void);
int IsStackEmpty(void);

TreeNode* Peek();


#endif

