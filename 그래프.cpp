

/*
// 9페이지 1번
// 인접 행렬을 이용한 그래프 추상 데이터 타입을 구현하여 봅시다.

// 직접 구현
#include<stdio.h>
#define MAX_VERTICES 10
typedef struct GraphType {
	int n;   // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];    // 10행 10열
}GraphType;

typedef struct edge {
	int start;
	int end;
}Edge;

// 0으로 배열 초기화
void init(GraphType *g) {
	for (int i = 0; i < MAX_VERTICES; i++) {
		for(int k=0; k<MAX_VERTICES; k++)
			g->adj_mat[i][k] = 0;
	}

}

void main()
{
	GraphType graph;
	int e, i, k;
	Edge line;
	init(&graph);
	printf("정점 개수: ");
	scanf("%d", &graph.n);
	printf("간선 개수: ");
	scanf("%d", &e);
	for (i = 0; i < e; i++) {
		printf("간선(a,b): ");
		scanf("%d  %d", &line.start, &line.end);
		graph.adj_mat[line.start][line.end] = 1;
		graph.adj_mat[line.end][line.start] = 1;
	}

	// 출력
	for (i = 0; i < graph.n; i++) {
		for (k = 0; k < graph.n; k++)
			printf("%4d", graph.adj_mat[i][k]);
		printf("\n");
	}
}
*/



/*
// 9페이지 1)
// 프린트에 있는 거 그대로 입력

#include<stdio.h>
#define MAX_VERTICES 10
typedef struct GraphType {
	int n;   // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}


// 정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("그래프 정점개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType *g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		printf("그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void main()
{
	GraphType g;
	graph_init(&g);

	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);

	insert_edge(&g, 0, 1);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);

	insert_edge(&g, 1, 0);
	insert_edge(&g, 1, 2);

	insert_edge(&g, 2, 1);
	insert_edge(&g, 2, 3);

	insert_edge(&g, 3, 0);
	insert_edge(&g, 3, 2);

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			printf("%3d", g.adj_mat[i][j]);
		}
		printf("\n");
	}
}
*/



/*
// 11페이지 2번
// 인접 리스트를 이용한 그래프 추상 데이터 타입을 구현하여 봅시다.

// 직접 구현
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}Node;

void init(Node ***list, int v) {
	for (int i = 0; i < v; i++) 
		(*list)[i] = NULL;
}

void main()
{
	Node **list;
	Node *tmp1, *tmp2;
	Node *p;
	int v, e;
	int i, k;
	int start, end;
	int flag;
	printf("정점 개수: ");
	scanf("%d", &v);
	printf("간선 개수: ");
	scanf("%d", &e);

	list = (Node**)malloc(sizeof(Node *) * v); // 정점 개수만큼 *할당
	init(&list, v);

	for (i = 0; i < e; i++) {
		printf("간선(a,b): ");
		scanf("%d %d", &start, &end);
		flag = 0;

		// start에 end 링크
		tmp1 = (Node *)malloc(sizeof(Node));
		tmp1->val = end;  tmp1->next = NULL;

		if (list[start] == NULL) {
			list[start] = tmp1;
		}
		else {
			p = list[start];   
			if (end == p->val) flag = 1; 
			while (p->next != NULL) {
				if (end == p->val) flag = 1;   
				p = p->next;
				if (end == p->val) flag = 1;
			}
			if (flag == 1) continue;
			p->next = tmp1;
		}

		// end에 start 링크
		tmp2 = (Node *)malloc(sizeof(Node));
		tmp2->val = start;  tmp2->next = NULL;

		if (list[end] == NULL) {
			list[end] = tmp2;
		}
		else {
			p = list[end];
			while (p->next!= NULL) {
				p = p->next; 
			}
			p->next = tmp2;
		}
	}


	// 출력
	for (i = 0; i < v; i++) {
		printf("%d: ", i);
		p = list[i];
		while (p != NULL) {
			printf("%d -> ", p->val);
			p = p->next;
		}
		printf("\n");
	}
}
*/



/*
// 11페이지 2)
// 프린트에 있는 거 그대로 입력

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // 정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

//정접 삽입 연산
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("그래프 정점개수 초과");
		return;
	}
	g->n++;
}
//간선 삽입 연산
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if (u >= g->n || v >= g->n) {
		printf("그래프 정점 번호 오류");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
	// null만날 때까지 링크 타고 가서 null자리에 삽입하는 것이 아니라
	// 새로 들어온 링크를 list 처음에 매달고 원래 있던 링크를 새로 들어온 링크 뒤로 매달음.
}

void main()
{
	GraphType g;
	graph_init(&g);

	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);

	insert_edge(&g, 0, 1);
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);

	insert_edge(&g, 1, 0);
	insert_edge(&g, 1, 2);

	insert_edge(&g, 2, 0);
	insert_edge(&g, 2, 1);
	insert_edge(&g, 2, 3);

	insert_edge(&g, 3, 0);
	insert_edge(&g, 3, 2);

	for (int i = 0; i < g.n; i++)
	{
		GraphNode *ap = g.adj_list[i];

		while (1) {
			printf("%3d", ap->vertex);
			if (ap->link == NULL) break;
			ap = ap->link;
		}
		printf("\n");
	}
}
*/






// 18페이지 10번, 11번
// 숫자말고 알파벳으로 하기




/*
// 10번
// 인접행렬을 사용하여 그래프 생성하는 프로그램
#include<stdio.h>
#include<stdlib.h>

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
		printf("6. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("정점의 개수: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("간선삽입(알파벳from~ to): "); 
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;  
			if (t >= 97) t = t - 32;

			if (f == t) printf("잘못된 간선 입력\n");
			else if(65<= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GAddEdge(&g, f, t);
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
		default: n = 6; break;
		}
		printf("\n");
	} while (n != 6);
	
	printf("종료되었습니다.\n");
	GDestroy(&g);
}
*/






// 11번
// 인접리스트를 사용하여 그래프 생성하는 프로그램 

// 11번
// 맨 처음에 인접 정점을 다는 게 아니라 각 정점인 알파벳부터 달고 시작해야 함
// 리스트 각 인덱스의 첫번째 값이 그 정점의 인접정점이 아니라 그 정점의 값인 알파벳이다.

//전에는 리스트의 0번째이면 그게 정점0을 의미하는 것으로 가정하고 바로 0의 인접정점부터 매달기 시작했지만
// 알파벳으로 하므로 (어떤 알파벳이 어떤 인덱스인지 모른다고 가정) 각 인덱스의 맨 처음에는 (그 정점의 값인)알파벳이 달려야 하고
// 그 뒤로 인접정점이 달려야 한다.



/*
#include<stdio.h>
#include<stdlib.h>

typedef struct GraphNode {
	char vertex;     // 값(알파벳)
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // 정점개수
	int v;   // 간선개수
	GraphNode **adj_list;
}Graph;


void GInit(Graph* pGraph, int nubmerOfVertex);   // 그래프 생성
void GDestroy(Graph* pGraph);               // 그래프 동적메모리 해제
void GAddEdge(Graph* pGraph,  char from, char to);   // 그래프 간선추가
int GDeleteEdge(Graph* pGraph, char from, char to);  // 그래프 간선 삭제
int GIsConnected(Graph* pGraph, int from, int to);  // 그래프 간선확인


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
	pGraph->v = 0;
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
		pGraph->v++;
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
				if (p->vertex == to) { flag = 1; break;}
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
	pGraph->v--;
	return 1;
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
		printf("6. 종료\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1:{		
			printf("정점의 개수: ");   scanf("%d", &g.n);
			GInit(&g, g.n); 
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
			printf("간선 개수: %d\n", g.v);
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
		default: n = 6; break;
		}
		printf("\n");

	} while (n != 6);

	GDestroy(&g);
	printf("종료되었습니다.\n");
}

*/



