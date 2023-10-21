


/*
// �����迭�� ǥ���� �׷����� ť�� ����Ͽ� �ʺ� �켱 Ž��

#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"

// ����ť
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


// �׷���
typedef struct adjacent_graph {
	int numberOfVertex;   // ��������
	int numberOfEdge;    // ��������
	int** matrix;       // ���
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // �׷��� ����
void GDestroy(Graph* pGraph);              // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph, int from, int to);     // �׷��� �����߰�
void bfs(Graph* pGraph, int);    // �׷��� �ʺ�켱Ž��

int *visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)

void GDestroy(Graph* pGraph) {
	delete pGraph->matrix;
}

void GInit(Graph* pGraph, int numberOfVertex) {
	pGraph->numberOfEdge = 0;
	pGraph->matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   // �� �����Ҵ�
	for (int i = 0; i < numberOfVertex; i++) {
		pGraph->matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex);  // �� �����Ҵ�
		for (int k = 0; k < numberOfVertex; k++)
			pGraph->matrix[i][k] = 0;
	}
}

void GAddEdge(Graph* pGraph, int f, int t) {
	if (pGraph->matrix[f][t] == 0) {
		pGraph->numberOfEdge++;
		pGraph->matrix[f][t] = 1;
		pGraph->matrix[t][f] = 1;
	}
	else printf("�ߺ��� ����\n");
}

// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}

// �ʺ� �켱 Ž�� - ����ť 
void bfs(Graph* pGraph, int start) {
	int i, k;
	i = start;
	QueueType q;
	init(&q);
	enqueue(&q, i);
	visited[i] = 1;

	do {
		i = dequeue(&q);
		printf("%4d -> ", i);
		for (k = 0; k < pGraph->numberOfVertex; k++) {
			if (pGraph->matrix[i][k] && !visited[k]) {
				enqueue(&q, k);
				visited[k] = 1;
			}
		}
	} while (!is_empty(&q));

}


void main()
{
	Graph g;
	int n;
	int f, t;
	do {
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ���\n");
		printf("5. �ʺ�켱Ž��\n");
		printf("6. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
			init_visited(g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("�������� : ");
			scanf("%d %d", &f, &t);

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (-1 < f && f < g.numberOfVertex && -1 < t && t < g.numberOfVertex) GAddEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");

		}break;
		case 3: {
			printf("���� ����: %d\n", g.numberOfEdge);
		}break;
		case 4: {
			printf("\n");
			for (int i = 0; i < g.numberOfVertex; i++) {
				for (int k = 0; k < g.numberOfVertex; k++)
					printf("%4d", g.matrix[i][k]);
				printf("\n");
			}
		}break;
		case 5: {
			bfs(&g, 0);   
			for (int i = 0; i < g.numberOfVertex; i++)  
				visited[i] = 0;
		}break;
		default: n = 6; break;
		}
		printf("\n");
	} while (n != 6);

	printf("����Ǿ����ϴ�.\n");
	GDestroy(&g);
}
*/


/*
// ������ �Ȱ��� �� - ����Ʈ�� �ִ� �� �״�� �Է�.��
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


void error(const char* message) {
	printf("%s", message);
	exit(1);
}

void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("overflow");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("underflow");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void graph_init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "overflow");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "graph index error");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;

	queue_init(&q);
	visited[v] = TRUE;
	printf("%d -> ", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for(w = 0; w<g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d -> ", w);
				enqueue(&q, w);
			}
	}
}


int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	for (int i = 0; i < 7; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 4);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);

	printf("BFS\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}
*/




/*
// ��������Ʈ�� ǥ���� �׷��� ť�� ����Ͽ� �ʺ�Ž��

#include<stdio.h>
#include<stdlib.h>

// ����ť
#define MAX_QUEUE_SIZE 20

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


void error(const char* message) {
	printf("%s", message);
	exit(1);
}

void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("overflow");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("underflow");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


// �׷���
typedef struct GraphNode {
	int vertex;     // ��
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // ��������
	int e;   // ��������
	GraphNode **adj_list;
}Graph;


void GInit(Graph* pGraph, int nubmerOfVertex);   // �׷��� ����
void GDestroy(Graph* pGraph);               // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph, int from, int to);   // �׷��� �����߰�
void init_visited(int n);    // visited�迭 �ʱ�ȭ
void bfs(Graph* pGraph, int);    // �׷��� ���̿켱Ž��

int *visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)


void GDestroy(Graph* pGraph) {
	delete pGraph->adj_list;
}

void GInit(Graph* pGraph, int n)
{
	pGraph->e = 0;
	pGraph->adj_list = (GraphNode**)malloc(sizeof(GraphNode *) * n);  
	for (int i = 0; i < n; i++)
		pGraph->adj_list[i] = NULL;    // adj_list[] �� null�� �ʱ�ȭ
}

void GAddEdge(Graph* pGraph, int from, int to)
{
	int flag;
	GraphNode *p;

	flag = 0;
	p = pGraph->adj_list[from];
	// ó�� �Ŵٴ� ���
	if (p == NULL) {
		pGraph->adj_list[from] = (GraphNode*)malloc(sizeof(GraphNode));
		pGraph->adj_list[from]->vertex = to;
		pGraph->adj_list[from]->link = NULL;
	}
	else {
		while (p->link != NULL) {
			p = p->link;
			if (p->vertex == to) flag = 1;
		}
		if (flag == 1) { printf("�ߺ��� ����\n"); return; }
		p->link = (GraphNode*)malloc(sizeof(GraphNode));
		p->link->vertex = to;
		p->link->link = NULL;
	}

	

	p = pGraph->adj_list[to];
	// ó�� �Ŵٴ� ���
	if (p == NULL) {
		pGraph->adj_list[to] = (GraphNode*)malloc(sizeof(GraphNode));
		pGraph->adj_list[to]->vertex = from;
		pGraph->adj_list[to]->link = NULL;
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = (GraphNode*)malloc(sizeof(GraphNode));
		p->link->vertex = from;
		p->link->link = NULL;
	}
	pGraph->e++;
}


// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}

// �ʺ�켱Ž�� - ����ť ���
void bfs(Graph* pGraph, int start) {
	int i, k;
	QueueType q;
	queue_init(&q);
	GraphNode* p;

	enqueue(&q,start);
	visited[start] = 1;

	while (!is_empty(&q)) {
		i = dequeue(&q);
		printf("%4d -> ", i);

		p = pGraph->adj_list[i];
		while (p!= NULL) {
			if (!visited[p->vertex]) {
				enqueue(&q, p->vertex);
				visited[p->vertex] = 1;
			}
			p = p->link;
		}
	}

}

void main()
{
	Graph g;
	GraphNode *p;
	int f, t;
	int n;
	do {
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ���\n");
		printf("5. �ʺ�켱Ž��\n");
		printf("6. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.n);
			GInit(&g, g.n);
			init_visited(g.n);
		}break;
		case 2: {
			printf("�������� : ");
			scanf("%d %d", &f, &t);

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (-1 < f && f < g.n && -1 < t && t < g.n) GAddEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");
		}break;
		case 3: {
			printf("���� ����: %d\n", g.e);
		}break;
		case 4: {
			for (int i = 0; i < g.n; i++) {
				printf("%4d : ", i);
				p = g.adj_list[i];
				while (p != NULL) {
					printf("%4d", p->vertex);
					p = p->link;
				}
				printf("\n");
			}
		} break;
		case 5: {
			bfs(&g, 3);
			for (int i = 0; i < g.n; i++)
				visited[i] = 0;
		} break;
		default: n = 6; break;
		}
		printf("\n");

	} while (n != 6);

	GDestroy(&g);
	printf("����Ǿ����ϴ�.\n");
}
*/


/*
// ����Ʈ�� �ִ� �ڵ� �Է� - bfs�κи�
void bfs_list(GraphType* g, int v)
{
	GraphNode* w;
	QueueType q;
	init(&q);

	visited[v] = TRUE;
	printf("%d -> ", v);
	enqueue(&q, v);

	while (!is_empty(&q)) {
		v = dequeue(&q);
		for(w = g->adj_list[v]; w; w = w->link)
			if (!visited[w->vertex]) {
				visited[w->vertex] = TRUE;
				printf("%d -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
	}
}
*/




/*
// 9������ ����Ǯ��
// 3��
// ���ĺ� ���� ��������Ʈ - �ʺ�켱Ž��
#include<stdio.h>
#include<stdlib.h>

//����ť
#define MAX_QUEUE_SIZE 20

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(const char* message) {
	printf("%s", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("overflow");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("underflow");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}



// �׷���
typedef struct GraphNode {
	char vertex;     // ��(���ĺ�)
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // ��������
	int e;   // ��������
	GraphNode **adj_list;
}Graph;

void GInit(Graph* pGraph, int nubmerOfVertex);   // �׷��� ����
void GDestroy(Graph* pGraph);               // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph, char from, char to);   // �׷��� �����߰�
void init_visited(int n);    // visited�迭 �ʱ�ȭ
void bfs(Graph* pGraph, int);    // �׷��� ���̿켱Ž��

int *visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)

void GDestroy(Graph* pGraph) {
	delete pGraph->adj_list;
}

void GInit(Graph* pGraph, int n)
{
	pGraph->e = 0;
	pGraph->adj_list = (GraphNode**)malloc(sizeof(GraphNode *) * n);
	for (int i = 0; i < n; i++) {   // ���ĺ� ��(A,B..)���� ����. ��, ���� �ÿ��� �� ��Ģ�� �𸥴ٰ� ����.
		pGraph->adj_list[i] = (GraphNode *)malloc(sizeof(GraphNode));
		pGraph->adj_list[i]->vertex = (char)(65 + i);
		pGraph->adj_list[i]->link = NULL;
	}
}

void GAddEdge(Graph* pGraph, char from, char to)
{
	int i;
	int flag;
	GraphNode *p;

	// from��ġ ã�Ƽ� to ����
	for (i = 0; i < pGraph->n; i++) {
		flag = 0;
		if (pGraph->adj_list[i]->vertex == from) {
			p = pGraph->adj_list[i];
			while (p->link != NULL) {
				p = p->link;
				if (p->vertex == to) flag = 1;
			}
			if (flag == 1) { printf("�ߺ��� ����\n"); break; }
			p->link = (GraphNode*)malloc(sizeof(GraphNode));
			p->link->vertex = to;
			p->link->link = NULL;
		}
	}
	// to��ġ ã�Ƽ� from ����
	if (flag == 0) {
		for (i = 0; i < pGraph->n; i++) {
			if (pGraph->adj_list[i]->vertex == to) {
				p = pGraph->adj_list[i];
				while (p->link != NULL) {
					p = p->link;
				}
				p->link = (GraphNode*)malloc(sizeof(GraphNode));
				p->link->vertex = from;
				p->link->link = NULL;
			}
		}
		pGraph->e++;
	}
}

// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}


// �ʺ� �켱 Ž��
void bfs(Graph* pGraph, int v) {
	GraphNode* p;
	QueueType q;
	init(&q);

	visited[v] = 1;
	printf("%4c ", v + 65);
	enqueue(&q, v);

	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (p = pGraph->adj_list[v]; p; p = p->link)
			if (!visited[p->vertex - 65]) {
				visited[p->vertex - 65] = 1;
				printf("%4c ", p->vertex);
				enqueue(&q, p->vertex - 65);
			}
	}
}


void main()
{
	Graph g;
	GraphNode *p;
	char f, t;
	int i;
	int e;

	printf("��������: ");   
	scanf("%d", &g.n);
	GInit(&g, g.n);  init_visited(g.n);

	printf("��������: "); 
	scanf("%d", &e);     // ���� - &g.e�� �Է¹޾Ƽ� for�� ������ g.e���� �� ���߰� ��� ��

	for(i=0;i<e;i++) {
		printf("Edge(�����) : ");
		getchar();
		scanf("%c %c", &f, &t);

		if (f >= 97) f = f - 32;
		if (t >= 97) t = t - 32;

		if (f == t) printf("�߸��� ���� �Է�\n");
		else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GAddEdge(&g, f, t);
		else printf("�߸��� ���� �Է�\n");
	}


	printf("\n== ���� ����Ʈ ==\n");
	for (i = 0; i < g.n; i++) {
		p = g.adj_list[i];
		printf("%4c : ", p->vertex);
		while (p->link != NULL) {
			p = p->link;
			printf("%4c -> ", p->vertex);
		}
		printf("\n");
	}
	printf("\n /////////////////// \n");

	printf("\n�ʺ� �켱 Ž�� >> ");
	bfs(&g, 0);
	printf("\n\n");
	GDestroy(&g);
}
*/







/*
// 4��
// �̼���� 


//- �̼��� ������ ���� ������� ���ȴ�.
//�⺻������ �θ�� �ڽ� ���̸� 1������ �����ϰ� �̷κ��� ����� ���� �̼��� ����Ѵ�.
//���� ��� ���� �ƹ���, �ƹ����� �Ҿƹ����� ���� 1������ ���� �Ҿƹ����� 2���� �ǰ�,
//�ƹ��� ������� �Ҿƹ����� 1��, ���� �ƹ��� ��������� 3���� �ȴ�.
//
//- ���� ����鿡 ���� �θ� �ڽĵ� ���� ���谡 �־����� ��, �־��� �� ����� �̼��� ����ϴ�
//���α׷��� �ۼ��Ͽ� ���ô�.
//
//[�Է�]
//- ������� 1, 2, 3, ..., n (1 <= n <= 100)�� ���ӵ� ��ȣ�� ���� ǥ�õȴ�.
//- �Է� ������ ù° �ٿ��� ��ü ����� �� n�� �־�����,
//- ��° �ٿ��� �̼��� ����ؾ� �ϴ� ���� �ٸ� �� ����� ��ȣ�� �־�����.
//- �׸��� ��° �ٿ��� �θ� �ڽĵ� ���� ������ ���� m�� �־�����.
//- ��° �ٺ��ʹ� �θ� �ڽİ��� ���踦 ��Ÿ���� �� ��ȣ x,y�� �� �ٿ� ���´�.
//  �̶� �տ� ������ ��ȣ x�� �ڿ� ������ ���� y�� �θ� ��ȣ�� ��Ÿ����.
//
//- �� ����� �θ�� �ִ� �� �� �־�����.
//
//[���]
//�Է¿��� �䱸�� �� ����� �̼��� ��Ÿ���� ������ ����Ѵ�.
//� ��쿡�� �� ����� ģô ���谡 ���� ���� �̼��� ����� �� ���� ���� �ִ�.
//�̶����� -1�� ����ؾ� �Ѵ�.




// ��ü ����� �� n -> ���� ����
// ����ؾ��ϴ� �� ���� ��ȣ
// �θ� �ڽĵ� ���� ������ ���� m -> ���� ����


// ���������̸� 1��
// ���������� ���������̸� 2��
// ���������� ���������� ���������̸� 3��
// �������� Ÿ�� ������ ���Ҵµ��� �߰� ���ϸ� ģô ���谡 ���� ���� ��(-1)

#include<stdio.h>
#include<stdlib.h>

//����ť
#define MAX_QUEUE_SIZE 30
typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(const char* message) {
	printf("%s", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("overflow");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("underflow");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}



typedef struct graph {
	int numberOfPeople;   // ��������
	int numberOfBridge;   // ��������
}Famliy;

int **matrix; 
int *visited;

void init(int n) {
	visited = (int*)malloc(sizeof(int) * n);    // visited�迭 �ʱ�ȭ
	matrix = (int **)malloc(sizeof(int *) * n);   // matrix �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
		matrix[i] = (int *)malloc(sizeof(int) * n);
		for (int k = 0; k < n; k++) {
			matrix[i][k] = 0;
		}
	}
}

void AddEdge(int s, int e)
{
	if (matrix[s][e] == 0) {
		matrix[s][e] = 1;
		matrix[e][s] = 1;
	}
	else printf("�ߺ��� ����\n");
}


// �̼� ���
// �ʺ�켱Ž�� Ȱ��
int count_bridge(int n, int f1, int f2) {  // ��������, �̼� ����ؾ� �ϴ� ��ȣ f1-f2
	QueueType q;
	init(&q);
	int w, v;
	int cnt = 0;

	visited[f1] = 1;
	enqueue(&q, f1);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		cnt++;
		for (w = 0; w < n; w++) {
			if (matrix[v][w] && !visited[w]) {
				visited[w] = 1;
				if (w == f2) return cnt;   // �̼�����
				enqueue(&q, w);
			}
		}
	}
	return -1;
}


void main()
{
	Famliy f;
	int f1, f2;
	int s, e;

	printf("��ü ����� �� : ");
	scanf("%d", &f.numberOfPeople);
	printf("�̼� ����ؾ� �ϴ� �λ�� ��ȣ : ");
	scanf("%d %d", &f1, &f2);
	printf("�θ� �ڽİ��� ���谳��(Edge) : ");
	scanf("%d", &f.numberOfBridge);

	init(f.numberOfPeople);

	for (int i = 0; i < f.numberOfBridge; i++) {
		printf("Edge : ");
		scanf("%d %d", &s, &e);
		if( 1<= s && s <= f.numberOfPeople && 1<=e && e<= f.numberOfPeople) AddEdge(s-1, e-1);
		else printf("�߸��� ���� �Է�\n");
	}
	printf("%d�� %d�� �̼� :  %d\n\n", f1, f2, count_bridge(f.numberOfPeople, f1-1, f2-1));
}
*/







/*
// 5�� - �� �����µ� �°� �Ѱ��� ������ �˻�ޱ�. - �°� �� ��
// ť element�� x,y��ǥ�� ������ ����ü�� ���� - �̷��� �ϴ°� �´��� ���� - �̷��� �ϴ� �� ���� 


// ���� �׷������� BFS�� ����Ͽ� ���̽�ũ���� ������ ���Ͽ� ���ô�.


//- N x M ũ���� ���� Ʋ�� �ִ�.
//- ������ �շ� �ִ� �κ��� 0, ĭ���̰� �����ϴ� �κ��� 1�� ǥ�õȴ�.
//
//- ������ �շ� �ִ� �κг��� ��,��,��,�� �� �پ� �ִ� ��� ���� ����Ǿ� �ִ� ������ �����Ѵ�.
//- �̶� ���� Ʋ�� ����� �־����� �� �����Ǵ� �� ���̽�ũ���� ������ ���Ͽ� ���ô�. 
//
//
//[�Է�]
//ù ��° �ٿ� ���� Ʋ�� ���� ���� N�� ���� ���� M�� �־�����. (1 <= N, M <= 1,000)
//�� ��° �ٿ� ù��° �ٺ���  N + 1 ��° �ٱ��� ���� Ʋ�� ���°� �־�����.
//�̶� ������ �շ� �ִ� �κ��� 0, �׷��� ���� �κ��� 1�̴�.
//
//[���]
//�� ���� ���� �� �ִ� ���̽�ũ���� ������ ����Ѵ�.


// �ʺ�켱Ž���̱� ������ ��ͻ��X. ť���O

// ť element�� x,y��ǥ�� ������ ����ü�� ����


#include<stdio.h>
#include<stdlib.h>
//����ť
#define MAX_QUEUE_SIZE 30

struct pos {
	int x;
	int y;
};

typedef struct pos element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(const char* message) {
	printf("%s", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("overflow");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("underflow");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}



int **ice;   // matrix
int n, m;  // size

// visited�Ⱦ��� �ѹ� �湮�� ice���� 1�� �ٲٴ� �ɷ�
bool bfs(int i, int k) {
	QueueType q;
	init(&q);
	struct pos p;
	struct pos tmp;
	p.x = i;
	p.y = k;

	if (!ice[p.x][p.y]) {
		ice[p.x][p.y] = 1;
		enqueue(&q, p);
		while (!is_empty(&q)) {
			p = dequeue(&q);

			if (p.x - 1 > -1) {  // ��
				tmp = p;
				tmp.x--;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp);  ice[tmp.x][tmp.y] = 1; }
			}
			if (p.y - 1 > -1) {  // ��
				tmp = p;
				tmp.y--;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp); ice[tmp.x][tmp.y] = 1; }
			}
			if (p.x + 1 < n) {   // ��
				tmp = p;
				tmp.x++;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp);  ice[tmp.x][tmp.y] = 1; }
			}
			if (p.y + 1 < m) {   // ��
				tmp = p;
				tmp.y++;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp);  ice[tmp.x][tmp.y] = 1; }
			}
		}
		return true;
	}

	return false;
}

void main()
{
	char s[30];
	int i, k;
	int icecream = 0;

	printf("N x M : ");
	scanf("%d %d", &n, &m);

	// ����Ʋ ���� 
	ice = (int**)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		ice[i] = (int *)malloc(sizeof(int) * m);
	}
	// ���� Ʋ ���� �Է�
	for (int i = 0; i < n; i++) {
		scanf("%s", &s);
		for (int k = 0; k < m; k++) {
			ice[i][k] = s[k] - '0';
		}
	}


	// ���̽�ũ�� ���� ���ϱ�
	for (i = 0; i < n; i++) {
		for (k = 0; k < m; k++) {
			if (bfs(i, k)) icecream++;
		}
	}
	printf("\n���̽�ũ�� �� ���� : %d\n", icecream);
}

*/






/*

// 6��
// �̷�ã��

//N x M ũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.
//- �̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.
//- �̷��� �̷ΰ� �־����� ��, (1,1)���� ����Ͽ� (N,M)�� ��ġ�� �̵��� �� ������ �ϴ�
//�ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.
//- �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.
//
//- ���� �������� 15ĭ�� ������ (N,M)�� ��ġ�� �̵��� �� �ִ�.
//- ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.
//
//[�Է�]
//ù° �ٿ� �� ���� N,M(2 <= N, M <=100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����.
//
//[���]
//ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ���� ��ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����. 




#include<stdio.h>
#include<stdlib.h>
//����ť
#define MAX_QUEUE_SIZE 50

typedef struct xy {
	int x;
	int y;
}NM;

typedef NM element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(const char* message) {
	printf("%s", message);
	exit(1);
}
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("overflow");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("underflow");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


int **matrix;
int **visited;


void init(int n, int m)
{
	int i, k;
	matrix = (int**)malloc(sizeof(int *) * n);
	visited = (int**)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * m);
		visited[i] = (int*)malloc(sizeof(int) * m);
	}
	for (i = 0; i < n; i++)
		for (k = 0; k < m; k++)
			visited[i][k] = 0;
}


int bfs(int n, int m)
{
	// (0,0) ~ (N-1,M-1)
	QueueType q;
	init(&q);

	NM pos;  // ��ǥ 
	NM tmp, before;
	pos.x = 0;  pos.y = 0;
	int move = 0;

	visited[pos.x][pos.y] = 1;
	move++;
	enqueue(&q, pos);
	while (!is_empty(&q)) {
		pos = dequeue(&q);
		tmp = pos;
		printf("dequeue : %d, %d\n", pos.x, pos.y);
		
		if (pos.y < m-1  && matrix[pos.x][pos.y + 1] && !visited[pos.x][pos.y + 1]) {   // ��
			visited[pos.x][pos.y + 1] = 1;
			tmp = pos;
			tmp.y++;
			enqueue(&q, tmp);
		}
		if (pos.x < n-1  && matrix[pos.x + 1][pos.y] && !visited[pos.x + 1][pos.y]) {  // ��
			visited[pos.x + 1][pos.y] = 1;
			tmp = pos;
			tmp.x++;
			enqueue(&q, tmp);
		}
		if (pos.x > 0 && matrix[pos.x - 1][pos.y] && !visited[pos.x - 1][pos.y]) {   // ��
			visited[pos.x - 1][pos.y] = 1;
			tmp = pos;
			tmp.x--;
			enqueue(&q, tmp);
		}
		if (pos.y > 0 && matrix[pos.x][pos.y - 1] && !visited[pos.x][pos.y - 1]) {   // ��
			visited[pos.x][pos.y - 1] = 1;
			tmp = pos;
			tmp.y--;
			enqueue(&q, tmp);
		}

		if (pos.x == tmp.x && pos.y == tmp.y) {}
		else move++;

		//printf("[ %d, %d ] -> ", tmp.x, tmp.y);
		if (tmp.x == n-1 && tmp.y == m-1) {
			printf("�̷� Ż�� ����!\n"); return move;
		}
	}

	return -1;
}



void main()
{
	int n, m;
	printf("N x M : ");
	scanf("%d %d", &n, &m);
	char s[30];
	int i, k;
	init(n, m);

	for (i = 0; i < n; i++) {
		scanf("%s", &s);
		for (k = 0; k < m; k++)
			matrix[i][k] = s[k] - '0';
	}

	// �̷� ���
	for (i = 0; i < n; i++) {
		for (k = 0; k < m; k++) 
			printf("%3d ", matrix[i][k]);
		printf("\n");
	}

	int a = bfs(n, m);
	if (a == -1) printf("�̷�Ż�� ����!\n");
	else printf("\n\n[�̷�Ż��] ������ �ϴ� �ּ� ĭ�� : %d\n", a);
}

*/



