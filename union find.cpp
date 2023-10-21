


/*
// ���Ἲ��

#include<stdio.h>
#define MAX_VERTICES 20

typedef struct GraphType {
	int n;   // ��������
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
	else printf("�ߺ��� ����\n");
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
		if (!visited[i]) {    // �湮���� �ʾ�����
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

	printf("�������� : ");
	scanf("%d", &g.n);
	printf("������ �������� : ");
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
// union_find ����
#include<stdio.h>

int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ģ��
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;  // �� ���� ������ �����ֱ�
	else parent[a] = b;
}

// ���� �θ� ��带 �������� Ȯ��
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

	printf("\n����ȣ : ");
	for (int i = 1; i <= 10; i++)
	{
		printf("%3d", i);
	}

	printf("\n�θ��� : ");
	for (int i = 1; i <= 10; i++)
	{
		printf("%3d", parent[i]);
	}

	printf("\n\n������ Ȯ���� ��� : ");
	scanf("%d %d", &a, &b);
	if (findParent(parent, a, b))
		printf("%d %d ���� ����Ǿ� �ֽ��ϴ�", a, b);
	else
		printf("%d %d ���� ����Ǿ� ���� �ʽ��ϴ�", a, b);
}
*/



/*
// 3��. ���� �׷������� ����Ŭ�� �����ϴ��� ã�ƺ��ô�.
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

// �� �θ��带 ��ģ��
void unionParent(int a, int b) 
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� ��带 �������� Ȯ��
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

	printf("��尳�� : ");
	scanf("%d", &v);
	printf("�������� : ");
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
		printf("����Ŭ�� �����մϴ�.\n");
	}
	else {
		printf("����ȣ : ");
		for (i = 1; i <= v; i++)
			printf("%3d", i);
		printf("\n�θ��� : ");
		for (i = 1; i <= v; i++)
			printf("%3d", parent[i]);
	}

}

*/





// ����Ǯ�� 11������

/*
// 1��
// ���Ἲ�� - ���� �ڵ�� ����
#include<stdio.h>
#define MAX_VERTICES 20

typedef struct GraphType {
	int n;   // ��������
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
	else printf("�ߺ��� ����\n");
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
		if (!visited[i]) {    // �湮���� �ʾ�����
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

	printf("�������� : ");
	scanf("%d", &g.n);
	printf("������ �������� : ");
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
// 2��

// DFS�� ���Ἲ�� ���ϱ�
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void GInit();
void init_visited();
void GDestroy();     // �׷��� �����޸� ����
void dfs(int);    // �׷��� ���̿켱Ž��

int numberOfVertex;   // ��������
int numberOfEdge;   // ��������
int * visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)
int ** matrix;      // ���
int connected[MAX] = { 0, };  // ���Ἲ��
int count;


void GDestroy() {
	delete * matrix;
	delete visited;
}
// matrix�ʱ�ȭ
void GInit() {
	matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   
	for (int i = 0; i < numberOfVertex; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex); 
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = 0;
	}
}
// visited�ʱ�ȭ
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

	printf("��������: ");   scanf("%d", &numberOfVertex);
	GInit();
	init_visited();

	printf("��������: ");
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

	printf("\n���Ἲ��\n");
	for (i = 0; i < numberOfVertex; i++)
		printf("%3d", i);
	printf("\n");
	for (i = 0; i < numberOfVertex; i++)
		printf("%3d", connected[i]);

	GDestroy();
}
*/



/*
// 3��
// union-find������ ���� �θ� ������ Ȯ�εǸ� ���� ����
// �θ� �ٸ��� �ٸ� �������� �Ǵ�.

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
	printf("��尳��: ");
	scanf("%d", &n);
	printf("Edge����: ");
	scanf("%d", &e);

	for (int k = 0; k < n; k++)
		parent[k] = k;

	while (1) {
		printf("\n\n1. �����Է�  2. ����Ȯ��  3. ����-> ");
		scanf("%d", &i);
		if (i == 1) {
			if (cnt == e) printf("���������� �ʰ��Ͽ����ϴ�.\n");
			else {
				cnt++;
				printf("���� : ");
				scanf("%d %d", &a, &b);
				unionParent(a, b);
			}
		}
		else if (i == 2) {
			printf("���� : ");
			scanf("%d %d", &a, &b);
			if (findParent(a, b)) printf("���տ� ���� �ֽ��ϴ�.\n");
			else printf("���տ� ���� ���� �ʽ��ϴ�.\n");
		}
		else break;
	}
}
*/





/*
// 4�� 
// ���� ������ �־�������, �� ���� ��ΰ� ������ ������ union find�� ����Ͽ� �˾ƺ��ô�
//- �߰��� �ٸ� ���ø� �����ؼ� ������ �� ���� �ִ�.
//- ���� ��� ���ð� 5�� �ְ�, A-B, B-C, A-D, B-D, E-A�� ���� �ְ�,
//  ���� ��ȹ�� E C B C D ��� E-A-B-C-B-C-B-D ��� �����θ� ���� ������ �޼��� �� �ִ�.
//- ���� ���ø� ���� �� �湮�ϴ� �͵� �����ϴ�.
//- 1�̸� ����� ���̰� 0�̸� ������ ���� ���� ���̴�.


#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int numberOfVertex;  // ��ü ������ ��
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
			if (matrix[i][k] == 1) unionParent(i+1, k+1);  // 1�̸� �� ��� union
		}
	}
}

void travel(int country[], int n) {
	int p = getParent(country[0]);
	for (int i = 1; i < n; i++) {
		if (p != getParent(country[i])) { printf("������ �� �����ϴ� �Ф�\n"); return; }
	}
	printf("������ �����մϴ�!!!\n");

	// country�迭�� n���� ��� ��ΰ� ���� �θ� ���������� ���� ����.
	// �Ѱ��� �ٸ� �θ� ������ �ִٸ� ������ �� ����
}

void main()
{
	char s[MAX];
	int n;
	int country[MAX];

	printf("������ �� : ");
	scanf("%d", &numberOfVertex);
	Init();

	for (int i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	printf("������ ��������\n");
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

	// ���ô� 1������ ����
	printf("\n�����ȹ�� ���� ���õ��� �� : ");
	scanf("%d", &n);
	printf("������ ���õ�\n");
	printf("=> ");  
	for (int i = 0; i < n; i++) {
		scanf("%d", &country[i]);
	}
	// parent�� ���
	printf("\nparent\n");
	for (int i = 1; i <= numberOfVertex; i++)
		printf("%3d ", parent[i]);

	printf("\n\n");
	travel(country, n);
}

*/







/*

// 5��
// ����Ʈ�� ģ�� ���谡 ���� ������� �־����� ��, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ���
// union find�� ����Ͽ� ���α׷��� �ۼ��Ͽ� ���ô�
// - ģ�� ��Ʈ��ũ�� ģ�� ���踸���� �̵��� �� �ִ� ���̸� ���Ѵ�.



// matrix�� ���� ���� �����´�� union-find�ؼ� �ٽ� ������
// => matrix���� ����!! -> �ʿ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct node {

	char s[30];
	int num;
}Node;

int numberOfVertex;  // ��ü ��尳��
int numberOfEdge;  // ��ü ��������
int **matrix;
int parent[MAX] = { 0, };

Node *node_list;  // (��� ���ڿ�)�̸� ���� 

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
			if (matrix[i][k] == 1) unionParent(i , k);  // 1�̸� �� ��� union
		}
	}
}


void search_friend(int f) {
	int p = parent[f];
	printf("���� ��Ʈ��ũ���� ģ���� : ");
	for (int i = 0; i < numberOfVertex; i++) 
		if (p == parent[i]) printf("%s ", node_list[i].s);
	

}

void main()
{
	int n, i;
	char find[20];
	Node node1, node2;

	printf("��尳�� : ");
	scanf("%d", &numberOfVertex);
	Init();
	printf("��������  ");
	scanf("%d", &numberOfEdge);

	printf("\n�����Է�\n");
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

	printf("\n\n�˻��� ��� �̸� : ");
	scanf("%s", &find);

	int f;
	for (i = 0; i < numberOfVertex; i++) {
		if(strcmp(find, node_list[i].s) == 0) { f = i; search_friend(f); break; }
	}
	if (i == numberOfVertex) printf("�������� �ʴ� ģ��\n");




	//printf("\nparent\n");
	//for (int i = 1; i <= numberOfVertex; i++)
	//	printf("%3d ", parent[i]);

	printf("\n\n");
}

*/




/*
// 5�� - �Ȱ��� ���� matrix�Ⱦ��� �ٽ� �����

// ����Ʈ�� ģ�� ���谡 ���� ������� �־����� ��, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ���
// union find�� ����Ͽ� ���α׷��� �ۼ��Ͽ� ���ô�
// - ģ�� ��Ʈ��ũ�� ģ�� ���踸���� �̵��� �� �ִ� ���̸� ���Ѵ�.

// ���ڳ� ���ڰ� �ƴ� ���ڿ��� ��尪���� ó���Ҷ�!! - ��� �ϴ��� �����ؼ� Ǯ��� �� ���� Ǫ�� ����
// ��� ���� AAA, BBB, CCC.. ��� ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct node {
	char s[30];
	int num;
}Node;

int numberOfVertex;  // ��ü ��尳��
int numberOfEdge;  // ��ü ��������
int parent[MAX] = { 0, };

Node *node_list;  // (��� ���ڿ�)�̸� ���� 

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
	printf("���� ��Ʈ��ũ���� ģ���� : ");
	for (int i = 0; i < numberOfVertex; i++)
		if (p == parent[i]) printf("%s ", node_list[i].s);
}

void main()
{
	int n, i;
	char find[20];
	Node node1, node2;

	printf("��尳�� : ");
	scanf("%d", &numberOfVertex);
	Init();
	printf("��������  ");
	scanf("%d", &numberOfEdge);

	for (i = 0; i < numberOfVertex; i++)
		parent[i] = i;

	printf("\n�����Է�\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%s %s", &node1.s, &node2.s);
		node1.num = node1.s[0] - 65;  // ù������ -65�� ���� �ε��� ��ȣ�� �����ϱ�� ����. (A=0, B=1..)
		node2.num = node2.s[0] - 65;

		node_list[node1.num] = node1;
		node_list[node2.num] = node2;

		unionParent(node1.num, node2.num);
	}

	printf("parent\n");
	for (i = 0; i < numberOfVertex; i++)
		printf("%3d", parent[i]);

	printf("\n\n�˻��� ��� �̸� : ");
	scanf("%s", &find);

	int f;
	for (i = 0; i < numberOfVertex; i++) {
		if (strcmp(find, node_list[i].s) == 0) { f = i; search_friend(f); break; }
	}
	if (i == numberOfVertex) printf("�������� �ʴ� ģ��\n");
	printf("\n\n");
}
*/

