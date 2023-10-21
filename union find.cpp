


/*
// 연결성분

#include<stdio.h>
#define MAX_VERTICES 20

typedef struct GraphType {
	int n;   // 정점개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


int count;
int visited[MAX_VERTICES] = { 0, };

void init(GraphType *g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) 
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
}

void AddEdge(GraphType *g, int a, int b) {
	if (!g->adj_mat[a][b]) {
		g->adj_mat[a][b] = 1;
		g->adj_mat[b][a] = 1;
	}
	else printf("중복된 간선\n");
}


void dfs_mat(GraphType *g, int v) {
	int w;
	printf("%4d", v);
	visited[v] = count;
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) dfs_mat(g, w);
	}
}

void find_connected_component(GraphType *g) {

	count = 0;
	for (int i = 0; i < g->n; i++) {
		if (!visited[i]) {    // 방문되지 않았으면
			count++;
			dfs_mat(g, i);
		}
	}
}


void main()
{
	GraphType g;
	init(&g);
	int edge;
	int n1, n2;

	printf("정점개수 : ");
	scanf("%d", &g.n);
	printf("삽입할 간선개수 : ");
	scanf("%d", &edge);

	for (int i = 0; i < edge; i++) {
		printf("Edge : ");
		scanf("%d %d", &n1, &n2);
		AddEdge(&g, n1, n2);
	}

	find_connected_component(&g);

	printf("\n");
	for (int i = 0; i < MAX_VERTICES; i++)
		printf("%4d", visited[i]);
}
*/




/*
// union_find 구현
#include<stdio.h>

int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 각 부모 노드를 합친다
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;  // 더 작은 쪽으로 몰아주기
	else parent[a] = b;
}

// 같은 부모 노드를 가지는지 확인
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main()
{
	int parent[11];
	int a, b;

	for (int i = 1; i <= 10; i++)
	{
		parent[i] = i;
	}

	unionParent(parent, 1, 2);   // 1-2
	unionParent(parent, 2, 3);   // 2-3
	unionParent(parent, 3, 4);   // 3-4
	unionParent(parent, 5, 6);   // 5-6
	unionParent(parent, 6, 7);   // 6-7
	unionParent(parent, 7, 8);   // 7-8
	unionParent(parent, 10, 9);  // 9-10

	printf("\n노드번호 : ");
	for (int i = 1; i <= 10; i++)
	{
		printf("%3d", i);
	}

	printf("\n부모노드 : ");
	for (int i = 1; i <= 10; i++)
	{
		printf("%3d", parent[i]);
	}

	printf("\n\n연결을 확인할 노드 : ");
	scanf("%d %d", &a, &b);
	if (findParent(parent, a, b))
		printf("%d %d 노드는 연결되어 있습니다", a, b);
	else
		printf("%d %d 노드는 연결되어 있지 않습니다", a, b);
}
*/



/*
// 3번. 다음 그래프에서 사이클이 존재하는지 찾아봅시다.
#include<stdio.h>

int graph[100][100] = { 0, };
int parent[100];
int a, b;

void initGraph(int x, int y)
{
	graph[x][y] = 1;
	graph[y][x] = 1;
}

int getParent(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 각 부모노드를 합친다
void unionParent(int a, int b) 
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모 노드를 가지는지 확인
int findParent(int a, int b)
{
	if (getParent(a) == getParent(b)) return 1;
	else return 0;
}


int main()
{
	int v, e;
	int i;
	int a, b;
	int cycle = 0;

	printf("노드개수 : ");
	scanf("%d", &v);
	printf("간선개수 : ");
	scanf("%d", &e);

	for (i = 1; i <= v; i++)
		parent[i] = i;

	for (i = 0; i < e; i++) {
		printf("Edge : ");
		scanf("%d %d", &a, &b);

		if (findParent(a, b)) {
			cycle = 1;
			break;
		}
		else unionParent(a, b);
	
	}

	if (cycle) {
		printf("사이클이 존재합니다.\n");
	}
	else {
		printf("노드번호 : ");
		for (i = 1; i <= v; i++)
			printf("%3d", i);
		printf("\n부모노드 : ");
		for (i = 1; i <= v; i++)
			printf("%3d", parent[i]);
	}

}

*/





// 문제풀이 11페이지

/*
// 1번
// 연결성분 - 위에 코드와 동일
#include<stdio.h>
#define MAX_VERTICES 20

typedef struct GraphType {
	int n;   // 정점개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;


int count;
int visited[MAX_VERTICES] = { 0, };

void init(GraphType *g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
}

void AddEdge(GraphType *g, int a, int b) {
	if (!g->adj_mat[a][b]) {
		g->adj_mat[a][b] = 1;
		g->adj_mat[b][a] = 1;
	}
	else printf("중복된 간선\n");
}


void dfs_mat(GraphType *g, int v) {
	int w;
	printf("%4d", v);
	visited[v] = count;
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) dfs_mat(g, w);
	}
}

void find_connected_component(GraphType *g) {

	count = 0;
	for (int i = 0; i < g->n; i++) {
		if (!visited[i]) {    // 방문되지 않았으면
			count++;
			dfs_mat(g, i);
		}
	}
}


void main()
{
	GraphType g;
	init(&g);
	int edge;
	int n1, n2;

	printf("정점개수 : ");
	scanf("%d", &g.n);
	printf("삽입할 간선개수 : ");
	scanf("%d", &edge);

	for (int i = 0; i < edge; i++) {
		printf("Edge : ");
		scanf("%d %d", &n1, &n2);
		AddEdge(&g, n1, n2);
	}

	find_connected_component(&g);

	printf("\n");
	for (int i = 0; i < MAX_VERTICES; i++)
		printf("%4d", visited[i]);
}
*/




/*
// 2번

// DFS로 연결성분 구하기
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void GInit();
void init_visited();
void GDestroy();     // 그래프 동적메모리 해제
void dfs(int);    // 그래프 깊이우선탐색

int numberOfVertex;   // 정점개수
int numberOfEdge;   // 간선개수
int * visited;   // 그래프 탐색 중 방문한 정점인지 표시 (방문했으면 1, 한적없으면 0)
int ** matrix;      // 행렬
int connected[MAX] = { 0, };  // 연결성분
int count;


void GDestroy() {
	delete * matrix;
	delete visited;
}
// matrix초기화
void GInit() {
	matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   
	for (int i = 0; i < numberOfVertex; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex); 
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = 0;
	}
}
// visited초기화
void init_visited() {
	visited = (int *)malloc(sizeof(int) * numberOfVertex);  
	for (int k = 0; k < numberOfVertex; k++)
		visited[k] = 0;
}

void AddEdge(int a, int b) {
	matrix[a][b] = 1;
	matrix[b][a] = 1;
}

void dfs(int start) {
	int i, k;
	i = start;
	connected[i] = count;
	visited[i] = 1;
	for (k = 0; k < numberOfVertex; k++) {
		if (matrix[i][k] && !visited[k]) dfs(k);
	}
}


void main()
{
	int i, j;
	int network = 0;
	int a, b;
	count = 0;

	printf("정점개수: ");   scanf("%d", &numberOfVertex);
	GInit();
	init_visited();

	printf("간선개수: ");
	scanf("%d", &numberOfEdge);

	for (i = 0; i < numberOfEdge; i++) {
		printf("Edge : ");
		scanf("%d %d", &a, &b);
		AddEdge(a, b);
	}

	for (i = 0; i < numberOfVertex; i++) {
		if (!visited[i]) {
			count++;
			dfs(i);		
		}
	}

	printf("\n연결성분\n");
	for (i = 0; i < numberOfVertex; i++)
		printf("%3d", i);
	printf("\n");
	for (i = 0; i < numberOfVertex; i++)
		printf("%3d", connected[i]);

	GDestroy();
}
*/



/*
// 3번
// union-find연산을 통해 부모가 같은지 확인되면 같은 집합
// 부모가 다르면 다른 집합으로 판단.

#include<stdio.h>
#define MAX 50

int parent[MAX];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

int findParent(int a, int b) {
	if (getParent(a) == getParent(b)) return 1;
	else return 0;
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


void main()
{
	int n, e;
	int i, cnt = 0;
	int a, b;
	printf("노드개수: ");
	scanf("%d", &n);
	printf("Edge개수: ");
	scanf("%d", &e);

	for (int k = 0; k < n; k++)
		parent[k] = k;

	while (1) {
		printf("\n\n1. 간선입력  2. 집합확인  3. 종료-> ");
		scanf("%d", &i);
		if (i == 1) {
			if (cnt == e) printf("간선개수를 초과하였습니다.\n");
			else {
				cnt++;
				printf("간선 : ");
				scanf("%d %d", &a, &b);
				unionParent(a, b);
			}
		}
		else if (i == 2) {
			printf("간선 : ");
			scanf("%d %d", &a, &b);
			if (findParent(a, b)) printf("집합에 속해 있습니다.\n");
			else printf("집합에 속해 있지 않습니다.\n");
		}
		else break;
	}
}
*/





/*
// 4번 
// 여행 일정이 주어졌을때, 이 여행 경로가 가능한 것인지 union find를 사용하여 알아봅시다
//- 중간에 다른 도시를 경유해서 여행을 할 수도 있다.
//- 예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고,
//  여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D 라는 여행경로를 통해 목적을 달성할 수 있다.
//- 같은 도시를 여러 번 방문하는 것도 가능하다.
//- 1이면 연결된 것이고 0이면 연결이 되지 않은 것이다.


#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int numberOfVertex;  // 전체 도시의 수
int **matrix;
int parent[MAX] = { 0, };

void Init() {
	matrix = (int**)malloc(sizeof(int*) * numberOfVertex);
	for (int i = 0; i < numberOfVertex; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * numberOfVertex);
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = 0;
	}
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void union_find() {
	for (int i = 0; i < numberOfVertex; i++) {
		for (int k = 0; k < numberOfVertex; k++) {
			if (matrix[i][k] == 1) unionParent(i+1, k+1);  // 1이면 두 노드 union
		}
	}
}

void travel(int country[], int n) {
	int p = getParent(country[0]);
	for (int i = 1; i < n; i++) {
		if (p != getParent(country[i])) { printf("여행할 수 없습니다 ㅠㅠ\n"); return; }
	}
	printf("여행이 가능합니다!!!\n");

	// country배열의 n개의 노드 모두가 같은 부모를 가져야지만 여행 가능.
	// 한개라도 다른 부모를 가지고 있다면 여행할 수 없음
}

void main()
{
	char s[MAX];
	int n;
	int country[MAX];

	printf("도시의 수 : ");
	scanf("%d", &numberOfVertex);
	Init();

	for (int i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	printf("도시의 연결정보\n");
	for (int i = 0; i < numberOfVertex; i++) {
		scanf("%s", &s);
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = s[k] - '0';
	}

	printf("\n");
	for (int i = 0; i < numberOfVertex; i++) {
		for (int k = 0; k < numberOfVertex; k++)
			printf("%3d", matrix[i][k]);
		printf("\n");
	}

	union_find();

	// 도시는 1번부터 시작
	printf("\n여행계획에 속한 도시들의 수 : ");
	scanf("%d", &n);
	printf("여행할 도시들\n");
	printf("=> ");  
	for (int i = 0; i < n; i++) {
		scanf("%d", &country[i]);
	}
	// parent값 출력
	printf("\nparent\n");
	for (int i = 1; i <= numberOfVertex; i++)
		printf("%3d ", parent[i]);

	printf("\n\n");
	travel(country, n);
}

*/







/*

// 5번
// 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지
// union find를 사용하여 프로그램을 작성하여 봅시다
// - 친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.



// matrix안 쓰고 간선 들어오는대로 union-find해서 다시 만들어보기
// => matrix쓰지 말기!! -> 필요없음

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct node {

	char s[30];
	int num;
}Node;

int numberOfVertex;  // 전체 노드개수
int numberOfEdge;  // 전체 간선개수
int **matrix;
int parent[MAX] = { 0, };

Node *node_list;  // (노드 문자열)이름 관리 

void Init() {
	matrix = (int**)malloc(sizeof(int*) * numberOfVertex);
	for (int i = 0; i < numberOfVertex; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * numberOfVertex);
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = 0;
	}
	node_list = (Node*)malloc(sizeof(node) * numberOfVertex);
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void union_find() {
	for (int i = 0; i < numberOfVertex; i++) {
		for (int k = 0; k < numberOfVertex; k++) {
			if (matrix[i][k] == 1) unionParent(i , k);  // 1이면 두 노드 union
		}
	}
}


void search_friend(int f) {
	int p = parent[f];
	printf("같은 네트워크상의 친구들 : ");
	for (int i = 0; i < numberOfVertex; i++) 
		if (p == parent[i]) printf("%s ", node_list[i].s);
	

}

void main()
{
	int n, i;
	char find[20];
	Node node1, node2;

	printf("노드개수 : ");
	scanf("%d", &numberOfVertex);
	Init();
	printf("간선개수  ");
	scanf("%d", &numberOfEdge);

	printf("\n간선입력\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%s %s", &node1.s, &node2.s);
		node1.num = node1.s[0] - 65;
		node2.num = node2.s[0] - 65;

		node_list[node1.num] = node1;
		node_list[node2.num] = node2;

		matrix[node1.num][node2.num] = 1;
		matrix[node2.num][node1.num] = 1;
	}

	for (i = 0; i < numberOfVertex; i++)
		parent[i] = i;


	printf("\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (int k = 0; k < numberOfVertex; k++)
			printf("%3d", matrix[i][k]);
		printf("\n");
	}

	union_find();

	printf("\n\n검색할 사람 이름 : ");
	scanf("%s", &find);

	int f;
	for (i = 0; i < numberOfVertex; i++) {
		if(strcmp(find, node_list[i].s) == 0) { f = i; search_friend(f); break; }
	}
	if (i == numberOfVertex) printf("존재하지 않는 친구\n");




	//printf("\nparent\n");
	//for (int i = 1; i <= numberOfVertex; i++)
	//	printf("%3d ", parent[i]);

	printf("\n\n");
}

*/




/*
// 5번 - 똑같은 문제 matrix안쓰고 다시 만들기

// 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지
// union find를 사용하여 프로그램을 작성하여 봅시다
// - 친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

// 숫자나 문자가 아닌 문자열을 노드값으로 처리할때!! - 어떻게 하는지 응용해서 풀라고 이 문제 푸는 것임
// 노드 값이 AAA, BBB, CCC.. 라고 가정

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct node {
	char s[30];
	int num;
}Node;

int numberOfVertex;  // 전체 노드개수
int numberOfEdge;  // 전체 간선개수
int parent[MAX] = { 0, };

Node *node_list;  // (노드 문자열)이름 관리 

void Init() {
	node_list = (Node*)malloc(sizeof(node) * numberOfVertex);
}

int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void search_friend(int f) {
	int p = parent[f];
	printf("같은 네트워크상의 친구들 : ");
	for (int i = 0; i < numberOfVertex; i++)
		if (p == parent[i]) printf("%s ", node_list[i].s);
}

void main()
{
	int n, i;
	char find[20];
	Node node1, node2;

	printf("노드개수 : ");
	scanf("%d", &numberOfVertex);
	Init();
	printf("간선개수  ");
	scanf("%d", &numberOfEdge);

	for (i = 0; i < numberOfVertex; i++)
		parent[i] = i;

	printf("\n간선입력\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%s %s", &node1.s, &node2.s);
		node1.num = node1.s[0] - 65;  // 첫문자의 -65한 값을 인덱스 번호로 설정하기로 정함. (A=0, B=1..)
		node2.num = node2.s[0] - 65;

		node_list[node1.num] = node1;
		node_list[node2.num] = node2;

		unionParent(node1.num, node2.num);
	}

	printf("parent\n");
	for (i = 0; i < numberOfVertex; i++)
		printf("%3d", parent[i]);

	printf("\n\n검색할 사람 이름 : ");
	scanf("%s", &find);

	int f;
	for (i = 0; i < numberOfVertex; i++) {
		if (strcmp(find, node_list[i].s) == 0) { f = i; search_friend(f); break; }
	}
	if (i == numberOfVertex) printf("존재하지 않는 친구\n");
	printf("\n\n");
}
*/

