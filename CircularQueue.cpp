#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"


/*
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
*/

// �ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return q->front == q->rear;
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// ���� �Լ�
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		printf("ť�� ��ȭ�����Դϴ�\n");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
	
}

// ���� �Լ�
element dequeue(QueueType *q)
{
	if (is_empty(q))
		printf("ť�� ��������Դϴ�\n");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
	
}

// ��ũ �Լ� (����x ��ȯ��)
element peek(QueueType *q)
{
	if (is_empty(q))
		printf("ť�� ��������Դϴ�\n");
	return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
}






/*
// ���� ť�� ��� ���� ��ȯ �Լ�
element get_count(QueueType *q)
{
	return q->rear-q->front;
}
*/
