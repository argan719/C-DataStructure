

#ifndef CircularQUEUE
#define CircularQUEUE

#define TRUE 1
#define FALSE 0

#define MAX_QUEUE_SIZE 200


//typedef struct Tree {
//	char Data;
//	struct Tree *Left, *Right;
//}TreeNode;

typedef int element;


typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


//static QueueType queue;


void error(char *message);
void init(QueueType *q);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, element item);
element dequeue(QueueType *q);
element peek(QueueType *q);


element get_count(QueueType *q);

#endif
