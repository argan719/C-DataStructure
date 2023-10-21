
/*
// �������� �˰��� ����

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100

// ����ť ���
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType q;

// �ʱ�ȭ �Լ�
void init_queue()
{
	q.front = q.rear = 0;
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
void enqueue(element item)
{
	if (is_full(&q))
		printf("ť�� ��ȭ�����Դϴ�\n");
	else {
		q.rear = (q.rear + 1) % MAX_QUEUE_SIZE;
		q.queue[q.rear] = item;
	}

}
// ���� �Լ�
element dequeue()
{
	if (is_empty(&q))
		printf("ť�� ��������Դϴ�\n");
	else {
		q.front = (q.front + 1) % MAX_QUEUE_SIZE;
		return q.queue[q.front];
	}
}


// �׷��� ����
int numberOfVertex;
int numberOfEdge;
int matrix[MAX_VERTICES][MAX_VERTICES];

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			matrix[i][j] = 0;
		}
	}
}

// ���⼺ �׷��� - �������� ����
void AddEdge(int x, int y)
{
	matrix[x][y] = 1;
}


// ��������
void topo_sort()
{
	int i, j;
	// arr - �������� ���� ����
	int *arr = (int *)malloc(sizeof(int) * numberOfVertex);
	// ť�� ���Դ� ��� ���� (���������� 0 �ż� ť�� �ѹ� �������� visited�� 0->1)
	int *visited = (int *)malloc(sizeof(int) * numberOfVertex);
	// �ʱ�ȭ
	for (i = 0; i < numberOfVertex; i++) {
		arr[i] = 0;
		visited[i] = 0;
	}
	// �������� ī��Ʈ
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			if (matrix[i][j] == 1) arr[j]++;
		}
	}

	// �� ó�� ���������� 0�� ��� ��� ť�� ����
	for (i = 0; i < numberOfVertex; i++) {
		if (arr[i] == 0) {
			enqueue(i);
			visited[i] = 1;
		}
	}

	int v;
	while (!is_empty(&q)) {
		v = dequeue();
		printf("%2d -> ", v+1);  // ���
		for (i = 0; i < numberOfVertex; i++) {
			if (matrix[v][i] == 1) arr[i]--;   // �������� ���� (��������--)

			if (arr[i] == 0 && !visited[i]) {
				enqueue(i);    // ���Ӱ� ���������� 0�� ��尡 �ִٸ� ť�� ����
				visited[i] = 1;
			}
		}
	}
}

void main()
{
	int i, j;
	printf("��尳�� : ");
	scanf("%d", &numberOfVertex);

	printf("�������� : ");
	scanf("%d", &numberOfEdge);
	init();
	init_queue();

	int a, b;
	printf("\n�����Է�(A,B)\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d", &a, &b);
		AddEdge(a-1, b-1);
	}

	printf("\n");
	topo_sort();
}
*/



/*
// ����Ʈ�� �ִ� �������� �˰��� ���� �ڵ� �״�� �Է��غ��� ���ϱ�
// 6������ 1��

// �������� �˰����� �����Ͽ� ���ô�.
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // ������ ����
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// ���� ���� ����
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if(u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}


// Stack�κ�
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType *s)
{
	s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return(s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}



// ���������� �����Ѵ�
int topo_sort(GraphType *g)
{
	int i;
	StackType s;
	GraphNode *node;

	// ��� ������ ���� ������ ���
	int *in_degree = (int *)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)    // �ʱ�ȭ
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode *node = g->adj_list[i];    // ���� i���� ������ ������
		while (node != NULL) {
			in_degree[node->vertex]++;  // ��������++ (�������� ī��Ʈ)
			node = node->link;
		}
	}
	// ���� ������ 0�� ������ ���ÿ� ����
	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) push(&s, i);
	}
	// ���� ������ ����
	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		printf("%d", w);  // ���� ���
		node = g->adj_list[w];  // �� ������ ���� ������ ����
		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;    // ���� ������ ���� (pop�� ���� w�� ����Ǿ��� ��� ����� ��������--)
			if (in_degree[u] == 0) push(&s, u);  // ���Ӱ� ���������� 0�� ��尡 ������ ����
			node = node->link;  // ���� ����
		}
	}
	free(in_degree);
	return (i == g->n);   // ��ȯ���� 1�̸� ����, 0�̸� ����
}

void main()
{
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	// ���� 0�� ���� ����Ʈ ����
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	// ���� 1�� ���� ����Ʈ ����
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	// ���� 2�� ���� ����Ʈ ����
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	// ���� 3�� ���� ����Ʈ ����
	insert_edge(&g, 3, 5);
	// ���� 4�� ���� ����Ʈ ����
	insert_edge(&g, 4, 5);
	// ���� ����
	topo_sort(&g);
}
*/




// ����Ǯ�� ����
// 4��
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100

// ����ť ���
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType q;

// �ʱ�ȭ �Լ�
void init_queue()
{
	q.front = q.rear = 0;
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
void enqueue(element item)
{
	if (is_full(&q))
		printf("ť�� ��ȭ�����Դϴ�\n");
	else {
		q.rear = (q.rear + 1) % MAX_QUEUE_SIZE;
		q.queue[q.rear] = item;
	}

}
// ���� �Լ�
element dequeue()
{
	if (is_empty(&q))
		printf("ť�� ��������Դϴ�\n");
	else {
		q.front = (q.front + 1) % MAX_QUEUE_SIZE;
		return q.queue[q.front];
	}

}


int numberOfStudent;
int numberOfCompare;
int matrix[MAX_VERTICES][MAX_VERTICES];

void init()
{
	for (int i = 0; i < numberOfStudent; i++) {
		for (int j = 0; j < numberOfStudent; j++) {
			matrix[i][j] = 0;
		}
	}
}

void AddEdge(int x, int y)
{
	matrix[x][y] = 1;
}

// ��������
void topo_sort()
{
	int i, j;
	// arr - �������� ���� ����
	int *arr = (int *)malloc(sizeof(int) * numberOfStudent);
	// ť�� ���Դ� ��� ���� (���������� 0 �ż� ť�� �ѹ� �������� visited�� 0->1)
	int *visited = (int *)malloc(sizeof(int) * numberOfStudent);
	// �ʱ�ȭ
	for (i = 0; i < numberOfStudent; i++) {
		arr[i] = 0;
		visited[i] = 0;
	}
	// �������� ī��Ʈ
	for (i = 0; i < numberOfStudent; i++) {
		for (j = 0; j < numberOfStudent; j++) {
			if (matrix[i][j] == 1) arr[j]++;
		}
	}

	// �� ó�� ���������� 0�� ��� ��� ť�� ����
	for (i = 0; i < numberOfStudent; i++) {
		if (arr[i] == 0) {
			enqueue(i);
			visited[i] = 1;
		}
	}

	int v;
	while (!is_empty(&q)) {
		v = dequeue();
		printf("%2d -> ", v + 1);  // ���
		for (i = 0; i < numberOfStudent; i++) {
			if (matrix[v][i] == 1) arr[i]--;   // �������� ���� (��������--)

			if (arr[i] == 0 && !visited[i]) {
				enqueue(i);    // ���Ӱ� ���������� 0�� ��尡 �ִٸ� ť�� ����
				visited[i] = 1;
			}
		}
	}
}


void main()
{
	printf("�л��� : ");
	scanf("%d", &numberOfStudent);
	printf("���� Ƚ�� : ");
	scanf("%d", &numberOfCompare);
	printf("���� �� A<B\n");  // ����ڷκ��� �Է¹���.
	init();

	int a, b;
	for (int i = 0; i < numberOfCompare; i++) {
		scanf("%d %d", &a, &b);
		AddEdge(a-1, b-1);
	}

	printf("\n�ټ��� ���\n");
	topo_sort();
	printf("\n");
}
*/




/*
// 5��
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100
// ����ť ���
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType q;

// �ʱ�ȭ �Լ�
void init_queue()
{
	q.front = q.rear = 0;
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
void enqueue(element item)
{
	if (is_full(&q))
		printf("ť�� ��ȭ�����Դϴ�\n");
	else {
		q.rear = (q.rear + 1) % MAX_QUEUE_SIZE;
		q.queue[q.rear] = item;
	}

}
// ���� �Լ�
element dequeue()
{
	if (is_empty(&q))
		printf("ť�� ��������Դϴ�\n");
	else {
		q.front = (q.front + 1) % MAX_QUEUE_SIZE;
		return q.queue[q.front];
	}

}


typedef struct task {
	int time;  // �۾��ð�
	int front_task;  // �����۾����� (���� ������ �����۾�����)
	int front_task_num[MAX_VERTICES];  // �����۾���ȣ
	int front_task_final;   // (-- �Ǵ� �����۾�����)
}Task;

int numberOfTask;
int sum = 0;
Task *t;

void topo_sort()
{
	int i, j;
	int max;
	// ť�� ���Դ� ��� ���� (���������� 0 �ż� ť�� �ѹ� �������� visited�� 0->1)
	int *visited = (int *)malloc(sizeof(int) * numberOfTask);
	// �ʱ�ȭ
	for (i = 0; i < numberOfTask; i++) {
		visited[i] = 0;
	}

	max = 0;
	// �� ó�� ���������� 0�� ��� ��� ť�� ����
	for (i = 0; i < numberOfTask; i++) {
		if (t[i].front_task == 0) {
			enqueue(i);
			visited[i] = 1;
			if (max < t[i].time) max = t[i].time;
		}
	}
	sum += max;
	//printf("\n���� �� : %d\n", max);

	int v;
	int flag;
	max = 0;
	while (!is_empty(&q)) {
		v = dequeue();
		flag = 0;
		printf("%2d  ", v + 1);  // ���
		for (i = 0; i < numberOfTask; i++) {
			for (j = 0; j < t[i].front_task; j++) {
				if (t[i].front_task_num[j] == v) {
					t[i].front_task_final--;
					if (max < t[i].time) max = t[i].time;
					flag++;   // ���� �����۾���ȣ�� �� ��� ���� - �� ���� �ִ� ��� ����
				}
			}
		}

		for (i = 0; i < numberOfTask; i++) {
			if (t[i].front_task_final == 0 && !visited[i]) {
				enqueue(i);    // ���Ӱ� ���������� 0�� ��尡 �ִٸ� ť�� ����
				flag--;
				visited[i] = 1;
			}
		}
		if (flag == 0) {  // ���� ���� �ִ� ��� ��� �� (�۾��ð�)�ִ��� ���ؾ� �� - �� ���� sum�� ���ؾ� ��
			sum += max; 
			printf("\n���� �� : %d\n", max);
			max = 0;
		}
	}
}

void main()
{
	int num;
	printf("�۾��� ���� : ");
	scanf("%d", &numberOfTask);
	t= (Task *)malloc(sizeof(Task) * numberOfTask);

	printf("�۾��ð�/�����۾�����/�����۾���ȣ\n");
	for (int i = 0; i < numberOfTask; i++) {
		scanf("%d %d", &t[i].time, &t[i].front_task);
		t[i].front_task_final = t[i].front_task;
		for (int j = 0; j < t[i].front_task; j++) {
			printf("�����۾���ȣ (%d) ", j + 1);
			scanf("%d", &num);
			t[i].front_task_num[j] = num - 1;
		}
	}

	printf("\n\n");
	topo_sort();
	printf("\n��� �۾��� �Ϸ��ϱ� ���� �ּ� �ð� : %d \n", sum);
}
*/
