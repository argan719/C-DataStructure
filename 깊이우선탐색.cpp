

// 6페이지 1번
// 인접배열로 표현된 그래프를 스택을 사용하여 깊이 우선 탐색.

/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// 스택
typedef int element;

void InitStack(void);
int Pop(void);
void Push(element item);
int IsStackEmpty(void);

int Top;
element Stack[MAX];

void InitStack(void)
{
	Top = 0;
}
int Pop(void)
{
	element item;
	if (!IsStackEmpty()) {
		item = Stack[--Top];
		return item;
	}
	else
		printf("Stack is Empty!\n");
	return NULL;
}
void Push(element item)
{
	Stack[Top] = item;
	Top = (Top++) % MAX;
}
int IsStackEmpty(void)
{
	if (Top == 0)
		return 1;
	else
		return 0;
}




// 그래프
typedef struct adjacent_graph {
	int numberOfVertex;   // 정점개수
	int numberOfEdge;    // 간선개수
	int** matrix;       // 행렬
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // 그래프 생성
void GDestroy(Graph* pGraph);              // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph, char from, char to);     // 그래프 간선추가
int GDeleteEdge(Graph* pGraph, char from, char to);   // 그래프 간선삭제
int GIsConnected(Graph* pGraph, char from, char to);    // 그래프 간선확인 
void dfs(Graph* pGraph);    // 그래프 깊이우선탐색

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

void GAddEdge(Graph* pGraph, char from, char to) {
	int f = from - 65;
	int t = to - 65;
	if (pGraph->matrix[f][t] == 0) {
		pGraph->numberOfEdge++;
		pGraph->matrix[f][t] = 1;
		pGraph->matrix[t][f] = 1;
	}
	else printf("중복된 간선\n");
}

int GIsConnected(Graph* pGraph, char from, char to) {
	if (pGraph->matrix[from - 65][to - 65] == 1 && pGraph->matrix[to - 65][from - 65] == 1) return 1;  // 간선 연결됨
	else return 0;
}

int GDeleteEdge(Graph* pGraph, char from, char to) {
	int f = from - 65;
	int t = to - 65;
	if (pGraph->matrix[f][t] == 1) {
		pGraph->matrix[f][t] = 0;
		pGraph->matrix[t][f] = 0;
		pGraph->numberOfEdge--;
		return 1;
	}
	printf("존재하지 않는 간선\n");
	return 0;
}


// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}

// 깊이 우선 탐색
void dfs(Graph* pGraph) {
	int i, k;
	//정점0부터 탐색시작
	i = 0;
	do {
		if (visited[i] == 0) {
			printf("%4c -> ", i+65);
			Push(i);
			visited[i] = 1;
		}
		for (k = 0; k < pGraph->numberOfVertex; k++) {
			if (pGraph->matrix[i][k] == 1) {
				if (visited[k] == 0) { i = k; break; }
			}
		}
		if (k == pGraph->numberOfVertex) {// 0부터 시작해서 한번 끝까지 간거임
			i = Pop();
		}
	} while (!IsStackEmpty());
}


void main()
{
	Graph g;
	int n;
	char f, t;
	InitStack();  // 스택초기화
	do {
		printf("1. 정점개수\n");
		printf("2. 간선추가\n");
		printf("3. 간선삭제\n");
		printf("4. 간선개수\n");
		printf("5. 출력\n");
		printf("6. 깊이우선탐색\n");
		printf("7. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
			init_visited(g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("간선삽입(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GAddEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");

		}break;
		case 3: {
			getchar();
			printf("삭제할 간선 입력(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GDeleteEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");
		}break;
		case 4: {
			printf("간선 개수: %d\n", g.numberOfEdge);
		}
				break;
		case 5: {
			printf("    ");
			for (int i = 0; i < g.numberOfVertex; i++)
				printf("%4c", 65 + i);
			printf("\n");
			for (int i = 0; i < g.numberOfVertex; i++) {
				printf("%4c", 65 + i);
				for (int k = 0; k < g.numberOfVertex; k++)
					printf("%4d", g.matrix[i][k]);
				printf("\n");
			}
		}
		break;
		case 6: {
			dfs(&g);
		}break;
		default: n = 7; break;
		}
		printf("\n");
	} while (n != 7);

	printf("종료되었습니다.\n");
	GDestroy(&g);
}
*/


/*
// 위와 동일한 거 - 프린트에 있는 거 그대로 입력
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

typedef int element;

typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top;


int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}
void push(int item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}
int pop() {
	int item;
	stackNode* temp = top;

	if (isEmpty()) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}
int peek() {
	int item;
	stackNode* temp = top;

	if (isEmpty()) {
		printf("\n]n Stack is empty !\n");
		return 0;
	}
	else {
		item = temp->data;
		return item;
	}
}
// 스택


void graphInit(GraphType *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

int visited[MAX_VERTICES];

// 정점 삽입 연산
void insertVertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("그래프 정점개수 초과");
		return;
	}
	g->n++;
}

// 간선 삽입 연산
void insertEdge(GraphType* g, int start, int end)
{
	if (start > g->n || end > g->n) {
		printf("그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


void dfs(GraphType* g, int start)
{
	push(start);
	while (!isEmpty()) {
		int current = pop();

		if (!visited[current])
		{
			printf("%d ", current);
			visited[current] = true;
		}

		for (int i = g->n - 1; i >= 0; i--) {
			if (g->adj_mat[current][i] == 1 && visited[i] == 0) push(i);
		}
	}
}


void main()
{
	GraphType g;
	graphInit(&g);

	int nodeAmount, edgeAmount, u, v, start;
	printf("정점개수 : ");
	scanf("%d", &nodeAmount);

	printf("Edge개수 : ");
	scanf("%d", &edgeAmount);

	for (int i = 1; i < nodeAmount; i++)
		insertVertex(&g, i);

	getchar();
	for (int i = 1; i <= edgeAmount; i++) {
		printf("Edge(양방향) : ");
		scanf("%d %d", &u, &v);
		insertEdge(&g, u, v);
		getchar();
	}

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			printf("%3d", g.adj_mat[i][j]);
		}
		printf("\n");
	}

	printf("시작정점 : ");
	scanf("%d", &start);
	printf("\n배열로 표현된 그래프 탐색\n");
	dfs(&g, start);
}
*/



/*
// 12페이지 3번

// 인접 리스트로 표현된 그래프를 스택을 사용하여 깊이 우선 탐색. 

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// 스택
typedef int element;

void InitStack(void);
int Pop(void);
void Push(element item);
int IsStackEmpty(void);

int Top;
element Stack[MAX];

void InitStack(void)
{
	Top = 0;
}
int Pop(void)
{
	element item;
	if (!IsStackEmpty()) {
		item = Stack[--Top];
		return item;
	}
	else
		printf("Stack is Empty!\n");
	return NULL;
}
void Push(element item)
{
	Stack[Top] = item;
	Top = (Top++) % MAX;
}
int IsStackEmpty(void)
{
	if (Top == 0)
		return 1;
	else
		return 0;
}
int Peek() {
	return Stack[Top-1];
}



// 그래프
#include<stdio.h>
#include<stdlib.h>

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
int GDeleteEdge(Graph* pGraph, char from, char to);  // 그래프 간선 삭제
int GIsConnected(Graph* pGraph, int from, int to);  // 그래프 간선확인
void init_visited(int n);    // visited배열 초기화
void dfs(Graph* pGraph);    // 그래프 깊이우선탐색

int *visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)


// 간선 확인되면 return 1, 없으면 return 0
int GIsConnected(Graph* pGraph, int from, int to)
{
	// from-to가 1이면 무조건 to-from도 1이기 때문에
	// from-to 만 확인하면 확인가능
	GraphNode *p;
	int i;
	for (i = 0; i < pGraph->n; i++) {
		if (pGraph->adj_list[i]->vertex == from) {
			p = pGraph->adj_list[i];
			while (p->link != NULL) {
				p = p->link;
				if (p->vertex == to) return 1;
			}
		}
	}
	return 0;
}

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
	// from알파벳이 어디에 있는 지부터 찾은 다음
	// 그 위치로 null만날 때까지 탐색 
	// null위치 탐색 중 만약 to값이랑 같은게 이미 링크되어 있다면 패스
	// null위치 찾아서 to알파벳 삽입

	// 반대로 to알파벳 위치 어딘지 또 찾음
	// 그 위치로 ""
	// null위치 찾아서 from알파벳 삽입
	int i, k;
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


int GDeleteEdge(Graph* pGraph, char from, char to)
{
	// 먼저from알파벳 위치를 찾은 다음
	// 거기서 링크타고 끝까지 가면서 to알파벳 위치 탐색
	// to알파벳 찾았는데
	// to알파벳이 마지막 링크였다 -> to전꺼 *link(to를 매달고 있는 link)를 null로 바꾼다
	// 마지막이 아니었다. -> to전꺼 *link에 to 다음꺼 링크(to의 *link값을) 를 매단다.

	// to도 마찬가지 방법으로 똑같이 삭제해줌
	// 전체 간선개수--
	GraphNode *p, *before;
	int i, flag;

	// from - to 삭제
	for (i = 0; i < pGraph->n; i++) {
		flag = 0;
		if (pGraph->adj_list[i]->vertex == from) {
			p = pGraph->adj_list[i];
			before = p;
			while (p->link != NULL) {
				before = p;
				p = p->link;
				if (p->vertex == to) { flag = 1; break; }
			}
			if (flag == 1) {
				if (p->link == NULL) {  // to알파벳이 있는 위치가 마지막인 경우
					before->link = NULL;
				}
				else {  // 마지막이 아닌경우
					before->link = p->link;
				}
			}
			else {
				printf("존재하지 않는 간선\n");
				return 0;
			}
		}
	}

	// to - from 삭제
	for (i = 0; i < pGraph->n; i++) {
		if (pGraph->adj_list[i]->vertex == to) {
			p = pGraph->adj_list[i];
			before = p;
			while (p->link != NULL) {
				before = p;
				p = p->link;
				if (p->vertex == from) break;
			}
			if (p->link == NULL) {  // from알파벳이 있는 위치가 마지막인 경우
				before->link = NULL;
			}
			else {  // 마지막이 아닌경우
				before->link = p->link;
			}
		}
	}
	pGraph->e--;
	return 1;
}



// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}

// 깊이 우선 탐색
void dfs(Graph* pGraph) {
	int i, k;
	// 정점0부터 시작
	// 0-A , 1-B, 2-C.. 
	GraphNode* p;
	int flag = 0;
	i = 0;
	p = pGraph->adj_list[i];
	do {
		if (flag != 1 && p == NULL) i = Pop();
		if (visited[i] == 0) {
			printf("%4c ->", i + 65);
			Push(i);
			visited[i] = 1;
		}
		flag = 0;
		p = pGraph->adj_list[i];
		do {
			if (!visited[p->vertex-65]) {
				i = (p->vertex - 65);
				flag = 1;
				break;
			}
			p = p->link;
		} while (p != NULL);

	}while (!IsStackEmpty());
}

void main()
{
	Graph g;
	GraphNode *p;
	char f, t;
	int n;
	do {
		printf("1. 정점개수\n");
		printf("2. 간선추가\n");
		printf("3. 간선삭제\n");
		printf("4. 간선개수\n");
		printf("5. 출력\n");
		printf("6. 깊이우선탐색\n");
		printf("7. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.n);
			GInit(&g, g.n);
			init_visited(g.n);
		}break;
		case 2: {
			getchar();
			printf("간선삽입(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GAddEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");

		}break;
		case 3: {
			getchar();
			printf("삭제할 간선 입력(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GDeleteEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");
		}break;
		case 4: {
			printf("간선 개수: %d\n", g.e);
		} break;
		case 5: {
			for (int i = 0; i < g.n; i++) {
				p = g.adj_list[i];
				while (p != NULL) {
					printf("%4c", p->vertex);
					p = p->link;
				}
				printf("\n");
			}
		} break;
		case 6: {
			dfs(&g);
		}break;
		default: n = 7; break;
		}
		printf("\n");

	} while (n != 7);

	GDestroy(&g);
	printf("종료되었습니다.\n");
}
*/




/*
// 10페이지 2번
// 인접배열로 표현된 그래프를 재귀를 사용하여 깊이 우선 탐색

#include<stdio.h>
#include<stdlib.h>

// 그래프
typedef struct adjacent_graph {
	int numberOfVertex;   // 정점개수
	int numberOfEdge;    // 간선개수
	int** matrix;       // 행렬
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // 그래프 생성
void GDestroy(Graph* pGraph);              // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph, char from, char to);     // 그래프 간선추가
int GDeleteEdge(Graph* pGraph, char from, char to);   // 그래프 간선삭제
int GIsConnected(Graph* pGraph, char from, char to);    // 그래프 간선확인 
void dfs(Graph* pGraph);    // 그래프 깊이우선탐색

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

void GAddEdge(Graph* pGraph, char from, char to) {
	int f = from - 65;
	int t = to - 65;
	if (pGraph->matrix[f][t] == 0) {
		pGraph->numberOfEdge++;
		pGraph->matrix[f][t] = 1;
		pGraph->matrix[t][f] = 1;
	}
	else printf("중복된 간선\n");
}

int GIsConnected(Graph* pGraph, char from, char to) {
	if (pGraph->matrix[from - 65][to - 65] == 1 && pGraph->matrix[to - 65][from - 65] == 1) return 1;  // 간선 연결됨
	else return 0;
}

int GDeleteEdge(Graph* pGraph, char from, char to) {
	int f = from - 65;
	int t = to - 65;
	if (pGraph->matrix[f][t] == 1) {
		pGraph->matrix[f][t] = 0;
		pGraph->matrix[t][f] = 0;
		pGraph->numberOfEdge--;
		return 1;
	}
	printf("존재하지 않는 간선\n");
	return 0;
}


// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}
 
// 깊이 우선 탐색 - 재귀
void dfs(Graph* pGraph, int start) {
	int i, k;

	i = start; 
	if (visited[i] == 0) {
		visited[i] = 1;
		printf("%4c -> ", i + 65);
	}
	for (k = 0; k < pGraph->numberOfVertex; k++) {
		if (pGraph->matrix[i][k] == 1 && visited[k] == 0) dfs(pGraph, k);
	}
	if (k == pGraph->numberOfVertex) return;
}


void main()
{
	Graph g;
	int n;
	char f, t;
	do {
		printf("1. 정점개수\n");
		printf("2. 간선추가\n");
		printf("3. 간선삭제\n");
		printf("4. 간선개수\n");
		printf("5. 출력\n");
		printf("6. 깊이우선탐색\n");
		printf("7. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
			init_visited(g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("간선삽입(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GAddEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");

		}break;
		case 3: {
			getchar();
			printf("삭제할 간선 입력(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GDeleteEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");
		}break;
		case 4: {
			printf("간선 개수: %d\n", g.numberOfEdge);
		}break;
		case 5: {
			printf("    ");
			for (int i = 0; i < g.numberOfVertex; i++)
				printf("%4c", 65 + i);
			printf("\n");
			for (int i = 0; i < g.numberOfVertex; i++) {
				printf("%4c", 65 + i);
				for (int k = 0; k < g.numberOfVertex; k++)
					printf("%4d", g.matrix[i][k]);
				printf("\n");
			}
		}break;
		case 6: {
			dfs(&g, 0);   // 정점 0부터 시작
			for (int i = 0; i < g.numberOfVertex; i++)  // visited배열 0으로 초기화 - 다시 탐색할 때 대비
				visited[i] = 0;
		}break;
		default: n = 7; break;
		}
		printf("\n");
	} while (n != 7);

	printf("종료되었습니다.\n");
	GDestroy(&g);
}
*/


/*
// 10페이지 2번
// 위와 동일 - 프린트 보고 그대로 입력

#include<stdio.h>
#define MAX_VERTICES 10
typedef struct GraphType {
	int n;   // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


void graphInit(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
int visited[MAX_VERTICES];

// 정점 삽입 연산
void insertVertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("그래프 정점개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insertEdge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		printf("그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


// ***  인접배열로 표현된 그래프탐색  ***
void dfs(GraphType* g, int v) // v=start
{
	visited[v] = 1;
	printf("%d -> ", v);
	for (int w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w])
			dfs(g, w);
	}
}
*/



/*
// 17페이지 4번
// 인접리스트로 표현된 그래프를 재귀를 사용하여 깊이 우선 탐색

#include<stdio.h>
#include<stdlib.h>

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
int GDeleteEdge(Graph* pGraph, char from, char to);  // 그래프 간선 삭제
int GIsConnected(Graph* pGraph, int from, int to);  // 그래프 간선확인
void init_visited(int n);    // visited배열 초기화
void dfs(Graph* pGraph);    // 그래프 깊이우선탐색

int *visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)


// 간선 확인되면 return 1, 없으면 return 0
int GIsConnected(Graph* pGraph, int from, int to)
{
	GraphNode *p;
	int i;
	for (i = 0; i < pGraph->n; i++) {
		if (pGraph->adj_list[i]->vertex == from) {
			p = pGraph->adj_list[i];
			while (p->link != NULL) {
				p = p->link;
				if (p->vertex == to) return 1;
			}
		}
	}
	return 0;
}

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
	int i, k;
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


int GDeleteEdge(Graph* pGraph, char from, char to)
{
	GraphNode *p, *before;
	int i, flag;

	// from - to 삭제
	for (i = 0; i < pGraph->n; i++) {
		flag = 0;
		if (pGraph->adj_list[i]->vertex == from) {
			p = pGraph->adj_list[i];
			before = p;
			while (p->link != NULL) {
				before = p;
				p = p->link;
				if (p->vertex == to) { flag = 1; break; }
			}
			if (flag == 1) {
				if (p->link == NULL) {  // to알파벳이 있는 위치가 마지막인 경우
					before->link = NULL;
				}
				else {  // 마지막이 아닌경우
					before->link = p->link;
				}
			}
			else {
				printf("존재하지 않는 간선\n");
				return 0;
			}
		}
	}

	// to - from 삭제
	for (i = 0; i < pGraph->n; i++) {
		if (pGraph->adj_list[i]->vertex == to) {
			p = pGraph->adj_list[i];
			before = p;
			while (p->link != NULL) {
				before = p;
				p = p->link;
				if (p->vertex == from) break;
			}
			if (p->link == NULL) {  // from알파벳이 있는 위치가 마지막인 경우
				before->link = NULL;
			}
			else {  // 마지막이 아닌경우
				before->link = p->link;
			}
		}
	}
	pGraph->e--;
	return 1;
}


// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}


// 깊이 우선 탐색 - 재귀
void dfs(Graph* pGraph, int start) {
	// 정점0부터 시작
	// 0-A , 1-B, 2-C.. 
	int i, k;
	GraphNode* p;
	p = pGraph->adj_list[start];
	if (!visited[p->vertex - 65]) {
		visited[p->vertex - 65] = 1;
		printf("%4c -> ", p->vertex);
	}
	p = p->link;
	while(p!=NULL) {
		if (!visited[p->vertex - 65]) dfs(pGraph, p->vertex - 65);
		p = p->link;
	}

}

void main()
{
	Graph g;
	GraphNode *p;
	char f, t;
	int n;
	do {
		printf("1. 정점개수\n");
		printf("2. 간선추가\n");
		printf("3. 간선삭제\n");
		printf("4. 간선개수\n");
		printf("5. 출력\n");
		printf("6. 깊이우선탐색\n");
		printf("7. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.n);
			GInit(&g, g.n);
			init_visited(g.n);
		}break;
		case 2: {
			getchar();
			printf("간선삽입(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GAddEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");

		}break;
		case 3: {
			getchar();
			printf("삭제할 간선 입력(알파벳from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GDeleteEdge(&g, f, t);
			else printf("잘못된 간선 입력\n");
		}break;
		case 4: {
			printf("간선 개수: %d\n", g.e);
		} break;
		case 5: {
			for (int i = 0; i < g.n; i++) {
				p = g.adj_list[i];
				while (p != NULL) {
					printf("%4c", p->vertex);
					p = p->link;
				}
				printf("\n");
			}
		} break;
		case 6: {
			dfs(&g, 0);
			for (int i = 0; i < g.n; i++)  
				visited[i] = 0;
		}break;
		default: n = 7; break;
		}
		printf("\n");

	} while (n != 7);

	GDestroy(&g);
	printf("종료되었습니다.\n");
}
*/




/*
// 프린트에 있는 코드 - 재귀 부분

void dfs_list(GraphType *g, int v)
{
	GraphNode *w;
	visited[v] = 1;     // 정점v의 방문 표시
	printf("%d ", v);   // 방문한 정점 출력
	for (w = g->adj_list[v]; w; w = w->link)    // 인접 정점 탐색
		if (!visited[w->vertext])
			dfs_list(g, w->vertex);    // 정점 w에서 DFS 새로시작
}
*/








/*

// 19페이지 5번
// 얼음틀 문제

//- N x M 크기의 얼음틀이 있다.
//- 구멍이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 표시된다.
//- 구멍이 뚫려 있는 부분끼리 상, 하, 좌, 우로 붙어 있는 경우 서로 연결되어 있는 것으로 간주한다.
//- 얼음 틀의 모양이 다음과 같이 주어졌을 때 생성되는 총 아이스크림의 개수를 구하는 프로그램을 작성하여 봅시다.
//
//첫 번째 줄에 얼음 틀의 세로 길이 N과 가로길이 M이 주어진다.
//두 번째 줄부터 N + 1 번째 줄까지 얼음 틀의 형태가 주어진다.

#include<stdio.h>
#define MAX_SIZE 100

int visited[MAX_SIZE][MAX_SIZE] = { 0, };
int matrix[MAX_SIZE][MAX_SIZE];

int n, m;  //행,열 개수


bool dfs(int x, int y)
{
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	if (visited[x][y] == 0 && matrix[x][y] == 0) {
		visited[x][y] = 1;

		dfs(x - 1, y);   // 상
		dfs(x + 1, y);   // 하
		dfs(x, y - 1);   // 좌
		dfs(x, y + 1);   // 우
		return true;
	}
	return false;
}


void main()
{
	int i, j;
	int ice = 0;   // 얼음 개수
	char s[20];
	printf("행열 size : ");
	scanf("%d %d", &n, &m);

	printf("얼음틀의 형태\n");
	for (i = 0; i < n; i++) {
		scanf("%s", &s);    // 한줄씩 입력받음
		for (j = 0; j <m; j++) {
			matrix[i][j] = s[j] - '0';  // 행열 생성
		}
	}
	// 하나씩 입력받으려면
	// for(i ~ n)
	//   for(j ~n)
	//      scanf("%d", &matrix[i][j]);
	
	printf("\n== 얼음틀 ==\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
	

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (dfs(i, j)) {
				ice++;
			}
		}
	}

	printf("\n아이스크림 개수 : %d\n", ice);

}
*/






/*
// 23페이지 3번 - 맞게 잘 한건지 쌤한테 확인받기 - 맞게한거임
// 다음 그래프의 경로를 모두 찾아 출력하여 봅시다.

#include<stdio.h>
#include<stdlib.h>

// 그래프
typedef struct adjacent_graph {
	int numberOfVertex;   // 정점개수
	int numberOfEdge;    // 간선개수
	int** matrix;       // 행렬
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // 그래프 생성
void GDestroy(Graph* pGraph);              // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph, int from, int to);     // 그래프 간선추가
void dfs(Graph* pGraph);    // 그래프 깊이우선탐색

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

void GAddEdge(Graph* pGraph, int from, int to) {
	if (pGraph->matrix[from][to] == 0) {
		pGraph->matrix[from][to] = 1;
		pGraph->matrix[to][from] = 1;
	}
	else printf("중복된 간선\n");
}

// 정점 개수 정해지면 visited배열 할당
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // 정점 개수만큼 visited배열 생성
	for (int i = 0; i < n; i++)    // visited배열 0으로 초기화
		visited[i] = 0;
}


// 깊이 우선 탐색 - 재귀
void dfs(Graph* pGraph, int start) {
	int i, k;
	i = start;
	if (visited[i] == 0) {
		visited[i] = 1;
		printf("%d -> ", i);
	}
	for (k = 0; k < pGraph->numberOfVertex; k++) {
		if (pGraph->matrix[i][k] == 1 && visited[k] == 0) dfs(pGraph, k);
	}
	if (k == pGraph->numberOfVertex) {
		printf("\n");
		if(i + 1 < pGraph->numberOfVertex) dfs(pGraph, i + 1);
	}
}


void main()
{
	Graph g;
	int i;
	int f, t;

	printf("정점개수: ");   scanf("%d", &g.numberOfVertex);
	GInit(&g, g.numberOfVertex);
	init_visited(g.numberOfVertex);

	printf("간선개수: ");   scanf("%d", &g.numberOfEdge);

	for (i = 0; i < g.numberOfEdge; i++) {
		printf("간선삽입(양방향) : ");
		scanf("%d %d", &f, &t);
		if(0<= f && f < g.numberOfVertex && 0<= t && t < g.numberOfVertex) GAddEdge(&g, f, t);
		else printf("잘못된 간선 입력\n");
	}
	// 행렬 출력
	printf("\n\n");
	for (int i = 0; i < g.numberOfVertex; i++) {
		for (int k = 0; k < g.numberOfVertex; k++)
			printf("%4d", g.matrix[i][k]);
		printf("\n");
	}

	printf("\n연결된 그래프 경로\n\n");
	dfs(&g, 0);   // 정점 0부터 시작

	GDestroy(&g);
}
*/





/*
// 24페이지 4번  
// 네트워크의 개수를 구해 봅시다


//- 네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미한다.
//- 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로
//  연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있다.
//  따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있다.
//- 컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때,
//  네트워크의 개수를 출력하는 프로그램을 작성하여 봅시다.


#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void GInit();    
void init_visited();
void GDestroy();     // 그래프 동적메모리 해제
bool dfs(int );    // 그래프 깊이우선탐색

int numberOfVertex;   // 정점개수 - 컴퓨터 개수
int * visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)
int ** matrix;      // 행렬


void GDestroy() {
	delete * matrix;
	delete visited;
}
// matrix초기화
void GInit() {
	matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   // 행 동적할당
	for (int i = 0; i < numberOfVertex; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex);  // 열 동적할당
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = 0;
	}
}
// visited초기화
void init_visited() {
	visited = (int *)malloc(sizeof(int) * numberOfVertex);  // 열 동적할당
	for (int k = 0; k < numberOfVertex; k++)
		visited[k] = 0;
}

bool dfs(int start) {
	int i, k;
	i = start;
	visited[i] = 1;
	for (k = 0; k < numberOfVertex; k++) {
		if (matrix[i][k] && !visited[k]) dfs(k);
	}
	if (k == numberOfVertex) return true;
	
	return true;
}


void main()
{
	int i, j;
	char s[MAX];
	int network = 0;

	printf("컴퓨터 개수: ");   scanf("%d", &numberOfVertex);
	GInit();
	init_visited();

	printf("연결상태\n");
	for (i = 0; i < numberOfVertex; i++) {
		scanf("%s", &s);    // 한줄씩 입력받음
		for (j = 0; j < numberOfVertex; j++) {
			matrix[i][j] = s[j] - '0';  // 행열 생성
		}
	}

	// 행렬 출력
	printf("연결상태\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}

	for (i = 0; i < numberOfVertex; i++) {
		if (!visited[i]) {
			if (dfs(i)) network++;
		}
	}
	printf("\n연결된 네트워크 개수: %d\n", network);
	GDestroy();
}
*/









// 26페이지 5번 
// 바이러스에 걸린 컴퓨터수를 구하는 프로그램을 작성하여 봅시다.

//신종 바리어스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와
//네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
//
//어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가
//주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성.
//
//
//[입력]
//첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가
//매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서
//그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 검퓨터의 번호 쌍이 주어진다.
//
//[출력]
//입력된 컴퓨터가 웜 바이러스에 걸렸을 때, 입력된 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의
//수를 첫째 줄에 출력한다.


/*

#include<stdio.h>
#include<stdlib.h>
// DFS - 깊이 우선 탐색!!

typedef struct graph {
	int numberOfComputer;   // 정점개수
	int numberOfEdge;    // 간선개수
	int** matrix;       // 행렬
}Graph;

int *visited;
int virus = 0;

void GInit(Graph* pGraph, int numberOfVertex) {
	visited = (int*)malloc(sizeof(int) * numberOfVertex);
	pGraph->matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   // 행 동적할당
	for (int i = 0; i < numberOfVertex; i++) {
		pGraph->matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex);  // 열 동적할당
		for (int k = 0; k < numberOfVertex; k++){
			pGraph->matrix[i][k] = 0;
			visited[k] = 0;
		}
	}
}

void GAddEdge(Graph* pGraph, int from, int to) {
	from = from - 1;
	to = to - 1;
	if (pGraph->matrix[from][to] == 0) {
		pGraph->matrix[from][to] = 1;
		pGraph->matrix[to][from] = 1;
	}
	else printf("중복된 간선\n");
}

void dfs(Graph* pGraph, int v) {
	int i, k;
	i = v;
	visited[i] = 1;

	for (k = 0; k < pGraph->numberOfComputer; k++) {
		if (pGraph->matrix[i][k] && !visited[k]) {
			virus++;
			visited[k] = 1;
			dfs(pGraph, k);
		}
	}
}

void main()
{
	int n1, n2;
	Graph g;
	int v;

	printf("컴퓨터 수 : ");
	scanf("%d", &g.numberOfComputer);
	if (g.numberOfComputer > 100) {
		printf("컴퓨터 수는 100 이하여야 합니다"); exit(1);
	}
	GInit(&g, g.numberOfComputer);


	printf("연결된 컴퓨터 쌍의 개수 : ");
	scanf("%d", &g.numberOfEdge);
	printf("컴퓨터 번호 쌍\n");    // 컴퓨터 번호는 1부터 시작
	for (int i = 0; i < g.numberOfEdge; i++) {
		scanf("%d %d", &n1, &n2);
		if( 1<= n1 && n1 <= g.numberOfComputer && 1 <= n2 && n2 <= g.numberOfComputer) GAddEdge(&g, n1, n2);
	}

	printf("바이러스에 걸린 컴퓨터 번호 : ");
	scanf("%d", &v);

	dfs(&g, v - 1);
	printf("%d번 컴퓨터와 연결되어 바이러스에 걸린 컴퓨터 : %d 대\n\n", v, virus);
}
*/







/*
// 27페이지 6번
// 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 출력하는 프로그램을 작성하여 봅시다.

//- 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
//- 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
//  여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
//  대각선상에 집이 있는 경우는 연결된 것이 아니다.
//
//[입력]
//첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5<=N<=25)을 입력
//다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력
//
//[출력]
//단지의 번호 + 단지의 가구수 출력
//전체 단지 수 출력

#include<stdio.h>
#include<stdlib.h>

int **matrix;
int **visited;
int size;
int cnt;  // 단지별 가구수 count


void Init() {
	matrix = (int **)malloc(sizeof(int *) * size);
	visited = (int **)malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * size);
		visited[i] = (int*)malloc(sizeof(int) * size);
	}
	for (int i = 0; i < size; i++)
		for (int k = 0; k < size; k++)
			visited[i][k] = 0;
}

bool dfs(int x, int y)
{
	if (x <= -1 || x >= size || y <= -1 || y >= size)
		return false;

	if (!visited[x][y] && matrix[x][y] ) {
		visited[x][y] = 1;
		cnt++;

		dfs(x - 1, y);   // 상
		dfs(x + 1, y);   // 하
		dfs(x, y - 1);   // 좌
		dfs(x, y + 1);   // 우
		return true;
	}
	return false;
}

void main()
{
	int i, k;
	int village = 0;  // 단지수
	char s[30];
	printf("size : ");
	scanf("%d", &size);
	if (size < 5 || 25 < size) { printf("5이상 25이하의 크기를 입력하세요."); exit(1); }
	Init();

	printf("행렬자료입력\n");
	for (i = 0; i < size; i++) {
		scanf("%s", &s);
		for (k = 0; k < size; k++)
			matrix[i][k] = s[k] - '0';
	}

	printf("\n\n");
	for (i = 0; i < size; i++) {
		for (k = 0; k < size; k++) {
			cnt = 0;
			if (dfs(i, k)) {
				village++;
				printf("%d 단지 가구수 %d \n", village, cnt);
			}
		}
	}
	printf("단지 수 : %d\n", village);
}
*/







/*
// 7번   최단거리는 아니지만 잘 나옴 - 쌤한테 검사받기 - 잘했음 
// 미로 탐색

// visited배열 생성하지 않고 matrix값을 바꾸는 걸로 - 한번 지나간 값은 1 -> 0로 
// 이렇게 할꺼면 나중에 다시 탐색하게 될 때를 대비해 값 원래대로 바꿔줘야 함 0 -> 1로

// 1이면 가고 0이면 벽

#include<stdio.h>
#include<stdlib.h>

int **matrix;
int n; int m;
int move;  // 움직인 칸수
int flag = 0;

// visited 쓰지 않고 한번 지나간 칸의 matrix값 변경
void Init(int n, int m) {
	matrix = (int**)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) 
		matrix[i] = (int*)malloc(sizeof(int) * m);
}

void dfs(int x, int y) {

	if (x < 0 || x >= n || y < 0 || y >= m) return;

	// 도착지점 도달하면 다시 처음위치로 되돌아가면서 그때 이동칸수 ++하면서 계산
	if (x == n - 1 && y == m - 1 && matrix[x][y]) {
		move++;
		matrix[x][y] = 0;
		printf("미로탈출 성공!\n");
		flag = 1;
	}

	if (matrix[x][y]) {
		if (flag == 1 && matrix[x][y]) return;
		
		matrix[x][y] = 0;  // 한번 지나간 칸 0으로 변경

		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);

		if (flag == 1) { move++;  printf("[ %d, %d ] -> ", x, y); }

		matrix[x][y] = 1; // 경로가 막혀서 되돌아오면 여기부터 다른길로 다시 탐색해야하기 때문에 다시 1로 변경
	}
}


void main()
{
	char s[30];
	printf("N x M : ");
	scanf("%d %d", &n, &m);
	Init(n,m);

	printf("미로 입력\n");
	for (int i = 0; i < n; i++) {
		scanf("%s", &s);
		for (int k = 0; k < m; k++)
			matrix[i][k] = s[k] - '0';
	}

	printf("미로 출력\n");
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			printf("%4d ", matrix[i][k]);
		}
		printf("\n");
	}

	move = 0;
	dfs(0, 0);
	printf("\n\n이동한 칸 수 : %d\n", move);
}

*/






