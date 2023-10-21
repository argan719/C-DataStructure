


/*
// 인접배열로 표현된 그래프를 큐를 사용하여 너비 우선 탐색

#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"

// 원형큐
// 초기화 함수
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return q->front == q->rear;
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		printf("큐가 포화상태입니다\n");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}

}
// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		printf("큐가 공백상태입니다\n");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}

}


// 그래프
typedef struct adjacent_graph {
	int numberOfVertex;   // 정점개수
	int numberOfEdge;    // 간선개수
	int** matrix;       // 행렬
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // 그래프 생성
void GDestroy(Graph* pGraph);              // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph, int from, int to);     // 그래프 간선추가
void bfs(Graph* pGraph, int);    // 그래프 너비우선탐색

int *visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)

void GDestroy(Graph* pGraph) {
	delete pGraph->matrix;
}

void GInit(Graph* pGraph, int numberOfVertex) {
	pGraph->numberOfEdge = 0;
	pGraph->matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   // 행 동적할당
	for (int i = 0; i < numberOfVertex; i++) {
		pGraph->matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex);  // 열 동적할당
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
	else printf("중복된 간선\n");
}

// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}

// 너비 우선 탐색 - 원형큐 
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
		printf("1. 정점개수\n");
		printf("2. 간선추가\n");
		printf("3. 간선개수\n");
		printf("4. 출력\n");
		printf("5. 너비우선탐색\n");
		printf("6. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
			init_visited(g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("간선삽입 : ");
			scanf("%d %d", &f, &t);

			if (f == t) printf("잘못된 간선 입력\n");
			else if (-1 < f && f < g.numberOfVertex && -1 < t && t < g.numberOfVertex) GAddEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");

		}break;
		case 3: {
			printf("간선 개수: %d\n", g.numberOfEdge);
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

	printf("종료되었습니다.\n");
	GDestroy(&g);
}
*/


/*
// 위에랑 똑같은 거 - 프린트에 있는 거 그대로 입력.비교
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
// 인접리스트로 표현된 그래프 큐를 사용하여 너비탐색

#include<stdio.h>
#include<stdlib.h>

// 원형큐
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


// 그래프
typedef struct GraphNode {
	int vertex;     // 값
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // 정점개수
	int e;   // 간선개수
	GraphNode **adj_list;
}Graph;


void GInit(Graph* pGraph, int nubmerOfVertex);   // 그래프 생성
void GDestroy(Graph* pGraph);               // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph, int from, int to);   // 그래프 간선추가
void init_visited(int n);    // visited배열 초기화
void bfs(Graph* pGraph, int);    // 그래프 깊이우선탐색

int *visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)


void GDestroy(Graph* pGraph) {
	delete pGraph->adj_list;
}

void GInit(Graph* pGraph, int n)
{
	pGraph->e = 0;
	pGraph->adj_list = (GraphNode**)malloc(sizeof(GraphNode *) * n);  
	for (int i = 0; i < n; i++)
		pGraph->adj_list[i] = NULL;    // adj_list[] 값 null로 초기화
}

void GAddEdge(Graph* pGraph, int from, int to)
{
	int flag;
	GraphNode *p;

	flag = 0;
	p = pGraph->adj_list[from];
	// 처음 매다는 경우
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
		if (flag == 1) { printf("중복된 간선\n"); return; }
		p->link = (GraphNode*)malloc(sizeof(GraphNode));
		p->link->vertex = to;
		p->link->link = NULL;
	}

	

	p = pGraph->adj_list[to];
	// 처음 매다는 경우
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


// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}

// 너비우선탐색 - 원형큐 사용
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
		printf("1. 정점개수\n");
		printf("2. 간선추가\n");
		printf("3. 간선개수\n");
		printf("4. 출력\n");
		printf("5. 너비우선탐색\n");
		printf("6. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.n);
			GInit(&g, g.n);
			init_visited(g.n);
		}break;
		case 2: {
			printf("간선삽입 : ");
			scanf("%d %d", &f, &t);

			if (f == t) printf("잘못된 간선 입력\n");
			else if (-1 < f && f < g.n && -1 < t && t < g.n) GAddEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");
		}break;
		case 3: {
			printf("간선 개수: %d\n", g.e);
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
	printf("종료되었습니다.\n");
}
*/


/*
// 프린트에 있는 코드 입력 - bfs부분만
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
// 9페이지 문제풀이
// 3번
// 알파벳 정점 인접리스트 - 너비우선탐색
#include<stdio.h>
#include<stdlib.h>

//원형큐
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



// 그래프
typedef struct GraphNode {
	char vertex;     // 값(알파벳)
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // 정점개수
	int e;   // 간선개수
	GraphNode **adj_list;
}Graph;

void GInit(Graph* pGraph, int nubmerOfVertex);   // 그래프 생성
void GDestroy(Graph* pGraph);               // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph, char from, char to);   // 그래프 간선추가
void init_visited(int n);    // visited배열 초기화
void bfs(Graph* pGraph, int);    // 그래프 깊이우선탐색

int *visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)

void GDestroy(Graph* pGraph) {
	delete pGraph->adj_list;
}

void GInit(Graph* pGraph, int n)
{
	pGraph->e = 0;
	pGraph->adj_list = (GraphNode**)malloc(sizeof(GraphNode *) * n);
	for (int i = 0; i < n; i++) {   // 알파벳 순(A,B..)으로 삽입. 단, 연산 시에는 이 규칙을 모른다고 가정.
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

	// from위치 찾아서 to 삽입
	for (i = 0; i < pGraph->n; i++) {
		flag = 0;
		if (pGraph->adj_list[i]->vertex == from) {
			p = pGraph->adj_list[i];
			while (p->link != NULL) {
				p = p->link;
				if (p->vertex == to) flag = 1;
			}
			if (flag == 1) { printf("중복된 간선\n"); break; }
			p->link = (GraphNode*)malloc(sizeof(GraphNode));
			p->link->vertex = to;
			p->link->link = NULL;
		}
	}
	// to위치 찾아서 from 삽입
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

// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}


// 너비 우선 탐색
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

	printf("정점개수: ");   
	scanf("%d", &g.n);
	GInit(&g, g.n);  init_visited(g.n);

	printf("간선개수: "); 
	scanf("%d", &e);     // 질문 - &g.e로 입력받아서 for문 돌리면 g.e에서 안 멈추고 계속 돔

	for(i=0;i<e;i++) {
		printf("Edge(양방향) : ");
		getchar();
		scanf("%c %c", &f, &t);

		if (f >= 97) f = f - 32;
		if (t >= 97) t = t - 32;

		if (f == t) printf("잘못된 간선 입력\n");
		else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GAddEdge(&g, f, t);
		else printf("잘못된 간선 입력\n");
	}


	printf("\n== 인접 리스트 ==\n");
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

	printf("\n너비 우선 탐색 >> ");
	bfs(&g, 0);
	printf("\n\n");
	GDestroy(&g);
}
*/







/*
// 4번
// 촌수계산 


//- 촌수는 다음과 같은 방식으로 계산된다.
//기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 사람들 간의 촌수를 계산한다.
//예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고,
//아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
//
//- 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는
//프로그램을 작성하여 봅시다.
//
//[입력]
//- 사람들은 1, 2, 3, ..., n (1 <= n <= 100)의 연속된 번호로 각각 표시된다.
//- 입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고,
//- 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다.
//- 그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다.
//- 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다.
//  이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.
//
//- 각 사람의 부모는 최대 한 명만 주어진다.
//
//[출력]
//입력에서 요구한 두 사람의 촌수를 마타내는 정수를 출력한다.
//어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다.
//이때에는 -1을 출력해야 한다.




// 전체 사람의 수 n -> 정점 개수
// 계산해야하는 두 정점 번호
// 부모 자식들 간의 관계의 개수 m -> 간선 개수


// 인접정점이면 1촌
// 인접정점의 인접정점이면 2촌
// 인접정점의 인접정점의 인접정점이면 3촌
// 인접정점 타고 끝까지 돌았는데도 발견 못하면 친척 관계가 전혀 없는 것(-1)

#include<stdio.h>
#include<stdlib.h>

//원형큐
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
	int numberOfPeople;   // 정점개수
	int numberOfBridge;   // 간선개수
}Famliy;

int **matrix; 
int *visited;

void init(int n) {
	visited = (int*)malloc(sizeof(int) * n);    // visited배열 초기화
	matrix = (int **)malloc(sizeof(int *) * n);   // matrix 초기화
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
	else printf("중복된 간선\n");
}


// 촌수 계산
// 너비우선탐색 활용
int count_bridge(int n, int f1, int f2) {  // 정점개수, 촌수 계산해야 하는 번호 f1-f2
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
				if (w == f2) return cnt;   // 촌수리턴
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

	printf("전체 사람의 수 : ");
	scanf("%d", &f.numberOfPeople);
	printf("촌수 계산해야 하는 두사람 번호 : ");
	scanf("%d %d", &f1, &f2);
	printf("부모 자식간의 관계개수(Edge) : ");
	scanf("%d", &f.numberOfBridge);

	init(f.numberOfPeople);

	for (int i = 0; i < f.numberOfBridge; i++) {
		printf("Edge : ");
		scanf("%d %d", &s, &e);
		if( 1<= s && s <= f.numberOfPeople && 1<=e && e<= f.numberOfPeople) AddEdge(s-1, e-1);
		else printf("잘못된 간선 입력\n");
	}
	printf("%d와 %d의 촌수 :  %d\n\n", f1, f2, count_bridge(f.numberOfPeople, f1-1, f2-1));
}
*/







/*
// 5번 - 잘 나오는데 맞게 한건지 쌤한테 검사받기. - 맞게 잘 함
// 큐 element를 x,y좌표로 구성된 구조체로 설정 - 이렇게 하는거 맞는지 질문 - 이렇게 하는 거 맞음 


// 다음 그래프에서 BFS를 사용하여 아이스크림의 개수를 구하여 봅시다.


//- N x M 크기의 얼음 틀이 있다.
//- 구멍이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 표시된다.
//
//- 구멍이 뚫려 있는 부분끼리 상,하,좌,우 로 붙어 있는 경우 서로 연결되어 있는 것으로 간주한다.
//- 이때 얼음 틀의 모양이 주어졌을 때 생성되는 총 아이스크림의 개수를 구하여 봅시다. 
//
//
//[입력]
//첫 번째 줄에 얼음 틀의 세로 길이 N과 가로 길이 M이 주어진다. (1 <= N, M <= 1,000)
//두 번째 줄에 첫번째 줄부터  N + 1 번째 줄까지 얼음 틀의 형태가 주어진다.
//이때 구멍이 뚫려 있는 부분은 0, 그렇지 않은 부분은 1이다.
//
//[출력]
//한 번에 만들 수 있는 아이스크림의 개수를 출력한다.


// 너비우선탐색이기 때문에 재귀사용X. 큐사용O

// 큐 element를 x,y좌표로 구성된 구조체로 설정


#include<stdio.h>
#include<stdlib.h>
//원형큐
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

// visited안쓰고 한번 방문한 ice값을 1로 바꾸는 걸로
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

			if (p.x - 1 > -1) {  // 상
				tmp = p;
				tmp.x--;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp);  ice[tmp.x][tmp.y] = 1; }
			}
			if (p.y - 1 > -1) {  // 좌
				tmp = p;
				tmp.y--;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp); ice[tmp.x][tmp.y] = 1; }
			}
			if (p.x + 1 < n) {   // 하
				tmp = p;
				tmp.x++;
				if (!ice[tmp.x][tmp.y]) { enqueue(&q, tmp);  ice[tmp.x][tmp.y] = 1; }
			}
			if (p.y + 1 < m) {   // 우
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

	// 얼음틀 생성 
	ice = (int**)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++) {
		ice[i] = (int *)malloc(sizeof(int) * m);
	}
	// 얼음 틀 형태 입력
	for (int i = 0; i < n; i++) {
		scanf("%s", &s);
		for (int k = 0; k < m; k++) {
			ice[i][k] = s[k] - '0';
		}
	}


	// 아이스크림 개수 구하기
	for (i = 0; i < n; i++) {
		for (k = 0; k < m; k++) {
			if (bfs(i, k)) icecream++;
		}
	}
	printf("\n아이스크림 총 개수 : %d\n", icecream);
}

*/






/*

// 6번
// 미로찾기

//N x M 크기의 배열로 표현되는 미로가 있다.
//- 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
//- 이러한 미로가 주어졌을 때, (1,1)에서 출발하여 (N,M)의 위치로 이동할 때 지나야 하는
//최소의 칸 수를 구하는 프로그램을 작성하여 봅시다.
//- 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
//
//- 위의 예에서는 15칸을 지나야 (N,M)의 위치로 이동할 수 있다.
//- 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
//
//[입력]
//첫째 줄에 두 정수 N,M(2 <= N, M <=100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
//
//[출력]
//첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착 위치로 이동할 수 있는 경우만 입력으로 주어진다. 




#include<stdio.h>
#include<stdlib.h>
//원형큐
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

	NM pos;  // 좌표 
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
		
		if (pos.y < m-1  && matrix[pos.x][pos.y + 1] && !visited[pos.x][pos.y + 1]) {   // 우
			visited[pos.x][pos.y + 1] = 1;
			tmp = pos;
			tmp.y++;
			enqueue(&q, tmp);
		}
		if (pos.x < n-1  && matrix[pos.x + 1][pos.y] && !visited[pos.x + 1][pos.y]) {  // 하
			visited[pos.x + 1][pos.y] = 1;
			tmp = pos;
			tmp.x++;
			enqueue(&q, tmp);
		}
		if (pos.x > 0 && matrix[pos.x - 1][pos.y] && !visited[pos.x - 1][pos.y]) {   // 상
			visited[pos.x - 1][pos.y] = 1;
			tmp = pos;
			tmp.x--;
			enqueue(&q, tmp);
		}
		if (pos.y > 0 && matrix[pos.x][pos.y - 1] && !visited[pos.x][pos.y - 1]) {   // 좌
			visited[pos.x][pos.y - 1] = 1;
			tmp = pos;
			tmp.y--;
			enqueue(&q, tmp);
		}

		if (pos.x == tmp.x && pos.y == tmp.y) {}
		else move++;

		//printf("[ %d, %d ] -> ", tmp.x, tmp.y);
		if (tmp.x == n-1 && tmp.y == m-1) {
			printf("미로 탈출 성공!\n"); return move;
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

	// 미로 출력
	for (i = 0; i < n; i++) {
		for (k = 0; k < m; k++) 
			printf("%3d ", matrix[i][k]);
		printf("\n");
	}

	int a = bfs(n, m);
	if (a == -1) printf("미로탈출 실패!\n");
	else printf("\n\n[미로탈출] 지나야 하는 최소 칸수 : %d\n", a);
}

*/



