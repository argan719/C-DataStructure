

// 6������ 1��
// �����迭�� ǥ���� �׷����� ������ ����Ͽ� ���� �켱 Ž��.

/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// ����
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




// �׷���
typedef struct adjacent_graph {
	int numberOfVertex;   // ��������
	int numberOfEdge;    // ��������
	int** matrix;       // ���
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // �׷��� ����
void GDestroy(Graph* pGraph);              // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph, char from, char to);     // �׷��� �����߰�
int GDeleteEdge(Graph* pGraph, char from, char to);   // �׷��� ��������
int GIsConnected(Graph* pGraph, char from, char to);    // �׷��� ����Ȯ�� 
void dfs(Graph* pGraph);    // �׷��� ���̿켱Ž��

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

void GAddEdge(Graph* pGraph, char from, char to) {
	int f = from - 65;
	int t = to - 65;
	if (pGraph->matrix[f][t] == 0) {
		pGraph->numberOfEdge++;
		pGraph->matrix[f][t] = 1;
		pGraph->matrix[t][f] = 1;
	}
	else printf("�ߺ��� ����\n");
}

int GIsConnected(Graph* pGraph, char from, char to) {
	if (pGraph->matrix[from - 65][to - 65] == 1 && pGraph->matrix[to - 65][from - 65] == 1) return 1;  // ���� �����
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
	printf("�������� �ʴ� ����\n");
	return 0;
}


// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}

// ���� �켱 Ž��
void dfs(Graph* pGraph) {
	int i, k;
	//����0���� Ž������
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
		if (k == pGraph->numberOfVertex) {// 0���� �����ؼ� �ѹ� ������ ������
			i = Pop();
		}
	} while (!IsStackEmpty());
}


void main()
{
	Graph g;
	int n;
	char f, t;
	InitStack();  // �����ʱ�ȭ
	do {
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ��������\n");
		printf("5. ���\n");
		printf("6. ���̿켱Ž��\n");
		printf("7. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
			init_visited(g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("��������(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GAddEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");

		}break;
		case 3: {
			getchar();
			printf("������ ���� �Է�(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GDeleteEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");
		}break;
		case 4: {
			printf("���� ����: %d\n", g.numberOfEdge);
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

	printf("����Ǿ����ϴ�.\n");
	GDestroy(&g);
}
*/


/*
// ���� ������ �� - ����Ʈ�� �ִ� �� �״�� �Է�
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
// ����


void graphInit(GraphType *g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

int visited[MAX_VERTICES];

// ���� ���� ����
void insertVertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("�׷��� �������� �ʰ�");
		return;
	}
	g->n++;
}

// ���� ���� ����
void insertEdge(GraphType* g, int start, int end)
{
	if (start > g->n || end > g->n) {
		printf("�׷��� ���� ��ȣ ����");
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
	printf("�������� : ");
	scanf("%d", &nodeAmount);

	printf("Edge���� : ");
	scanf("%d", &edgeAmount);

	for (int i = 1; i < nodeAmount; i++)
		insertVertex(&g, i);

	getchar();
	for (int i = 1; i <= edgeAmount; i++) {
		printf("Edge(�����) : ");
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

	printf("�������� : ");
	scanf("%d", &start);
	printf("\n�迭�� ǥ���� �׷��� Ž��\n");
	dfs(&g, start);
}
*/



/*
// 12������ 3��

// ���� ����Ʈ�� ǥ���� �׷����� ������ ����Ͽ� ���� �켱 Ž��. 

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// ����
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



// �׷���
#include<stdio.h>
#include<stdlib.h>

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
int GDeleteEdge(Graph* pGraph, char from, char to);  // �׷��� ���� ����
int GIsConnected(Graph* pGraph, int from, int to);  // �׷��� ����Ȯ��
void init_visited(int n);    // visited�迭 �ʱ�ȭ
void dfs(Graph* pGraph);    // �׷��� ���̿켱Ž��

int *visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)


// ���� Ȯ�εǸ� return 1, ������ return 0
int GIsConnected(Graph* pGraph, int from, int to)
{
	// from-to�� 1�̸� ������ to-from�� 1�̱� ������
	// from-to �� Ȯ���ϸ� Ȯ�ΰ���
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
	for (int i = 0; i < n; i++) {   // ���ĺ� ��(A,B..)���� ����. ��, ���� �ÿ��� �� ��Ģ�� �𸥴ٰ� ����.
		pGraph->adj_list[i] = (GraphNode *)malloc(sizeof(GraphNode));
		pGraph->adj_list[i]->vertex = (char)(65 + i);
		pGraph->adj_list[i]->link = NULL;
	}
}

void GAddEdge(Graph* pGraph, char from, char to)
{
	// from���ĺ��� ��� �ִ� ������ ã�� ����
	// �� ��ġ�� null���� ������ Ž�� 
	// null��ġ Ž�� �� ���� to���̶� ������ �̹� ��ũ�Ǿ� �ִٸ� �н�
	// null��ġ ã�Ƽ� to���ĺ� ����

	// �ݴ�� to���ĺ� ��ġ ����� �� ã��
	// �� ��ġ�� ""
	// null��ġ ã�Ƽ� from���ĺ� ����
	int i, k;
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


int GDeleteEdge(Graph* pGraph, char from, char to)
{
	// ����from���ĺ� ��ġ�� ã�� ����
	// �ű⼭ ��ũŸ�� ������ ���鼭 to���ĺ� ��ġ Ž��
	// to���ĺ� ã�Ҵµ�
	// to���ĺ��� ������ ��ũ���� -> to���� *link(to�� �Ŵް� �ִ� link)�� null�� �ٲ۴�
	// �������� �ƴϾ���. -> to���� *link�� to ������ ��ũ(to�� *link����) �� �Ŵܴ�.

	// to�� �������� ������� �Ȱ��� ��������
	// ��ü ��������--
	GraphNode *p, *before;
	int i, flag;

	// from - to ����
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
				if (p->link == NULL) {  // to���ĺ��� �ִ� ��ġ�� �������� ���
					before->link = NULL;
				}
				else {  // �������� �ƴѰ��
					before->link = p->link;
				}
			}
			else {
				printf("�������� �ʴ� ����\n");
				return 0;
			}
		}
	}

	// to - from ����
	for (i = 0; i < pGraph->n; i++) {
		if (pGraph->adj_list[i]->vertex == to) {
			p = pGraph->adj_list[i];
			before = p;
			while (p->link != NULL) {
				before = p;
				p = p->link;
				if (p->vertex == from) break;
			}
			if (p->link == NULL) {  // from���ĺ��� �ִ� ��ġ�� �������� ���
				before->link = NULL;
			}
			else {  // �������� �ƴѰ��
				before->link = p->link;
			}
		}
	}
	pGraph->e--;
	return 1;
}



// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}

// ���� �켱 Ž��
void dfs(Graph* pGraph) {
	int i, k;
	// ����0���� ����
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
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ��������\n");
		printf("5. ���\n");
		printf("6. ���̿켱Ž��\n");
		printf("7. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.n);
			GInit(&g, g.n);
			init_visited(g.n);
		}break;
		case 2: {
			getchar();
			printf("��������(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GAddEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");

		}break;
		case 3: {
			getchar();
			printf("������ ���� �Է�(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GDeleteEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");
		}break;
		case 4: {
			printf("���� ����: %d\n", g.e);
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
	printf("����Ǿ����ϴ�.\n");
}
*/




/*
// 10������ 2��
// �����迭�� ǥ���� �׷����� ��͸� ����Ͽ� ���� �켱 Ž��

#include<stdio.h>
#include<stdlib.h>

// �׷���
typedef struct adjacent_graph {
	int numberOfVertex;   // ��������
	int numberOfEdge;    // ��������
	int** matrix;       // ���
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // �׷��� ����
void GDestroy(Graph* pGraph);              // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph, char from, char to);     // �׷��� �����߰�
int GDeleteEdge(Graph* pGraph, char from, char to);   // �׷��� ��������
int GIsConnected(Graph* pGraph, char from, char to);    // �׷��� ����Ȯ�� 
void dfs(Graph* pGraph);    // �׷��� ���̿켱Ž��

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

void GAddEdge(Graph* pGraph, char from, char to) {
	int f = from - 65;
	int t = to - 65;
	if (pGraph->matrix[f][t] == 0) {
		pGraph->numberOfEdge++;
		pGraph->matrix[f][t] = 1;
		pGraph->matrix[t][f] = 1;
	}
	else printf("�ߺ��� ����\n");
}

int GIsConnected(Graph* pGraph, char from, char to) {
	if (pGraph->matrix[from - 65][to - 65] == 1 && pGraph->matrix[to - 65][from - 65] == 1) return 1;  // ���� �����
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
	printf("�������� �ʴ� ����\n");
	return 0;
}


// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}
 
// ���� �켱 Ž�� - ���
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
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ��������\n");
		printf("5. ���\n");
		printf("6. ���̿켱Ž��\n");
		printf("7. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
			init_visited(g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("��������(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GAddEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");

		}break;
		case 3: {
			getchar();
			printf("������ ���� �Է�(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GDeleteEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");
		}break;
		case 4: {
			printf("���� ����: %d\n", g.numberOfEdge);
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
			dfs(&g, 0);   // ���� 0���� ����
			for (int i = 0; i < g.numberOfVertex; i++)  // visited�迭 0���� �ʱ�ȭ - �ٽ� Ž���� �� ���
				visited[i] = 0;
		}break;
		default: n = 7; break;
		}
		printf("\n");
	} while (n != 7);

	printf("����Ǿ����ϴ�.\n");
	GDestroy(&g);
}
*/


/*
// 10������ 2��
// ���� ���� - ����Ʈ ���� �״�� �Է�

#include<stdio.h>
#define MAX_VERTICES 10
typedef struct GraphType {
	int n;   // ������ ����
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

// ���� ���� ����
void insertVertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("�׷��� �������� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insertEdge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		printf("�׷��� ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


// ***  �����迭�� ǥ���� �׷���Ž��  ***
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
// 17������ 4��
// ��������Ʈ�� ǥ���� �׷����� ��͸� ����Ͽ� ���� �켱 Ž��

#include<stdio.h>
#include<stdlib.h>

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
int GDeleteEdge(Graph* pGraph, char from, char to);  // �׷��� ���� ����
int GIsConnected(Graph* pGraph, int from, int to);  // �׷��� ����Ȯ��
void init_visited(int n);    // visited�迭 �ʱ�ȭ
void dfs(Graph* pGraph);    // �׷��� ���̿켱Ž��

int *visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)


// ���� Ȯ�εǸ� return 1, ������ return 0
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
	for (int i = 0; i < n; i++) {   // ���ĺ� ��(A,B..)���� ����. ��, ���� �ÿ��� �� ��Ģ�� �𸥴ٰ� ����.
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


int GDeleteEdge(Graph* pGraph, char from, char to)
{
	GraphNode *p, *before;
	int i, flag;

	// from - to ����
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
				if (p->link == NULL) {  // to���ĺ��� �ִ� ��ġ�� �������� ���
					before->link = NULL;
				}
				else {  // �������� �ƴѰ��
					before->link = p->link;
				}
			}
			else {
				printf("�������� �ʴ� ����\n");
				return 0;
			}
		}
	}

	// to - from ����
	for (i = 0; i < pGraph->n; i++) {
		if (pGraph->adj_list[i]->vertex == to) {
			p = pGraph->adj_list[i];
			before = p;
			while (p->link != NULL) {
				before = p;
				p = p->link;
				if (p->vertex == from) break;
			}
			if (p->link == NULL) {  // from���ĺ��� �ִ� ��ġ�� �������� ���
				before->link = NULL;
			}
			else {  // �������� �ƴѰ��
				before->link = p->link;
			}
		}
	}
	pGraph->e--;
	return 1;
}


// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}


// ���� �켱 Ž�� - ���
void dfs(Graph* pGraph, int start) {
	// ����0���� ����
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
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ��������\n");
		printf("5. ���\n");
		printf("6. ���̿켱Ž��\n");
		printf("7. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.n);
			GInit(&g, g.n);
			init_visited(g.n);
		}break;
		case 2: {
			getchar();
			printf("��������(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GAddEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");

		}break;
		case 3: {
			getchar();
			printf("������ ���� �Է�(���ĺ�from~ to): ");
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if (65 <= f && f < 65 + g.n && 65 <= t && t < 65 + g.n) GDeleteEdge(&g, f, t);
			else printf("�߸��� ���� �Է�\n");
		}break;
		case 4: {
			printf("���� ����: %d\n", g.e);
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
	printf("����Ǿ����ϴ�.\n");
}
*/




/*
// ����Ʈ�� �ִ� �ڵ� - ��� �κ�

void dfs_list(GraphType *g, int v)
{
	GraphNode *w;
	visited[v] = 1;     // ����v�� �湮 ǥ��
	printf("%d ", v);   // �湮�� ���� ���
	for (w = g->adj_list[v]; w; w = w->link)    // ���� ���� Ž��
		if (!visited[w->vertext])
			dfs_list(g, w->vertex);    // ���� w���� DFS ���ν���
}
*/








/*

// 19������ 5��
// ����Ʋ ����

//- N x M ũ���� ����Ʋ�� �ִ�.
//- ������ �շ� �ִ� �κ��� 0, ĭ���̰� �����ϴ� �κ��� 1�� ǥ�õȴ�.
//- ������ �շ� �ִ� �κг��� ��, ��, ��, ��� �پ� �ִ� ��� ���� ����Ǿ� �ִ� ������ �����Ѵ�.
//- ���� Ʋ�� ����� ������ ���� �־����� �� �����Ǵ� �� ���̽�ũ���� ������ ���ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.
//
//ù ��° �ٿ� ���� Ʋ�� ���� ���� N�� ���α��� M�� �־�����.
//�� ��° �ٺ��� N + 1 ��° �ٱ��� ���� Ʋ�� ���°� �־�����.

#include<stdio.h>
#define MAX_SIZE 100

int visited[MAX_SIZE][MAX_SIZE] = { 0, };
int matrix[MAX_SIZE][MAX_SIZE];

int n, m;  //��,�� ����


bool dfs(int x, int y)
{
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	if (visited[x][y] == 0 && matrix[x][y] == 0) {
		visited[x][y] = 1;

		dfs(x - 1, y);   // ��
		dfs(x + 1, y);   // ��
		dfs(x, y - 1);   // ��
		dfs(x, y + 1);   // ��
		return true;
	}
	return false;
}


void main()
{
	int i, j;
	int ice = 0;   // ���� ����
	char s[20];
	printf("�࿭ size : ");
	scanf("%d %d", &n, &m);

	printf("����Ʋ�� ����\n");
	for (i = 0; i < n; i++) {
		scanf("%s", &s);    // ���پ� �Է¹���
		for (j = 0; j <m; j++) {
			matrix[i][j] = s[j] - '0';  // �࿭ ����
		}
	}
	// �ϳ��� �Է¹�������
	// for(i ~ n)
	//   for(j ~n)
	//      scanf("%d", &matrix[i][j]);
	
	printf("\n== ����Ʋ ==\n");
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

	printf("\n���̽�ũ�� ���� : %d\n", ice);

}
*/






/*
// 23������ 3�� - �°� �� �Ѱ��� ������ Ȯ�ιޱ� - �°��Ѱ���
// ���� �׷����� ��θ� ��� ã�� ����Ͽ� ���ô�.

#include<stdio.h>
#include<stdlib.h>

// �׷���
typedef struct adjacent_graph {
	int numberOfVertex;   // ��������
	int numberOfEdge;    // ��������
	int** matrix;       // ���
}Graph;

void GInit(Graph* pGraph, int numberOfVertex);    // �׷��� ����
void GDestroy(Graph* pGraph);              // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph, int from, int to);     // �׷��� �����߰�
void dfs(Graph* pGraph);    // �׷��� ���̿켱Ž��

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

void GAddEdge(Graph* pGraph, int from, int to) {
	if (pGraph->matrix[from][to] == 0) {
		pGraph->matrix[from][to] = 1;
		pGraph->matrix[to][from] = 1;
	}
	else printf("�ߺ��� ����\n");
}

// ���� ���� �������� visited�迭 �Ҵ�
void init_visited(int n) {
	visited = (int *)malloc(sizeof(int)*n);  // ���� ������ŭ visited�迭 ����
	for (int i = 0; i < n; i++)    // visited�迭 0���� �ʱ�ȭ
		visited[i] = 0;
}


// ���� �켱 Ž�� - ���
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

	printf("��������: ");   scanf("%d", &g.numberOfVertex);
	GInit(&g, g.numberOfVertex);
	init_visited(g.numberOfVertex);

	printf("��������: ");   scanf("%d", &g.numberOfEdge);

	for (i = 0; i < g.numberOfEdge; i++) {
		printf("��������(�����) : ");
		scanf("%d %d", &f, &t);
		if(0<= f && f < g.numberOfVertex && 0<= t && t < g.numberOfVertex) GAddEdge(&g, f, t);
		else printf("�߸��� ���� �Է�\n");
	}
	// ��� ���
	printf("\n\n");
	for (int i = 0; i < g.numberOfVertex; i++) {
		for (int k = 0; k < g.numberOfVertex; k++)
			printf("%4d", g.matrix[i][k]);
		printf("\n");
	}

	printf("\n����� �׷��� ���\n\n");
	dfs(&g, 0);   // ���� 0���� ����

	GDestroy(&g);
}
*/





/*
// 24������ 4��  
// ��Ʈ��ũ�� ������ ���� ���ô�


//- ��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��Ѵ�.
//- ���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, ��ǻ�� B�� ��ǻ�� C�� ����������
//  ����Ǿ� ���� �� ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ִ�.
//  ���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ִ�.
//- ��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��,
//  ��Ʈ��ũ�� ������ ����ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.


#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void GInit();    
void init_visited();
void GDestroy();     // �׷��� �����޸� ����
bool dfs(int );    // �׷��� ���̿켱Ž��

int numberOfVertex;   // �������� - ��ǻ�� ����
int * visited;   // �׷��� Ž�� �� �湮�� �������� ǥ�� (�湮������ 1, ���������� 0)
int ** matrix;      // ���


void GDestroy() {
	delete * matrix;
	delete visited;
}
// matrix�ʱ�ȭ
void GInit() {
	matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   // �� �����Ҵ�
	for (int i = 0; i < numberOfVertex; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex);  // �� �����Ҵ�
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = 0;
	}
}
// visited�ʱ�ȭ
void init_visited() {
	visited = (int *)malloc(sizeof(int) * numberOfVertex);  // �� �����Ҵ�
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

	printf("��ǻ�� ����: ");   scanf("%d", &numberOfVertex);
	GInit();
	init_visited();

	printf("�������\n");
	for (i = 0; i < numberOfVertex; i++) {
		scanf("%s", &s);    // ���پ� �Է¹���
		for (j = 0; j < numberOfVertex; j++) {
			matrix[i][j] = s[j] - '0';  // �࿭ ����
		}
	}

	// ��� ���
	printf("�������\n");
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
	printf("\n����� ��Ʈ��ũ ����: %d\n", network);
	GDestroy();
}
*/









// 26������ 5�� 
// ���̷����� �ɸ� ��ǻ�ͼ��� ���ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.

//���� �ٸ���� �� ���̷����� ��Ʈ��ũ�� ���� ���ĵȴ�. �� ��ǻ�Ͱ� �� ���̷����� �ɸ��� �� ��ǻ�Ϳ�
//��Ʈ��ũ �󿡼� ����Ǿ� �ִ� ��� ��ǻ�ʹ� �� ���̷����� �ɸ��� �ȴ�.
//
//��� �� 1�� ��ǻ�Ͱ� �� ���̷����� �ɷȴ�. ��ǻ���� ���� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ������
//�־��� ��, 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ����ϴ� ���α׷��� �ۼ�.
//
//
//[�Է�]
//ù° �ٿ��� ��ǻ���� ���� �־�����. ��ǻ���� ���� 100 �����̰� �� ��ǻ�Ϳ��� 1�� ���� ���ʴ�� ��ȣ��
//�Ű�����. ��° �ٿ��� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ���� �־�����. �̾
//�� ����ŭ �� �ٿ� �� �־� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ���� ��ȣ ���� �־�����.
//
//[���]
//�Էµ� ��ǻ�Ͱ� �� ���̷����� �ɷ��� ��, �Էµ� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ����
//���� ù° �ٿ� ����Ѵ�.


/*

#include<stdio.h>
#include<stdlib.h>
// DFS - ���� �켱 Ž��!!

typedef struct graph {
	int numberOfComputer;   // ��������
	int numberOfEdge;    // ��������
	int** matrix;       // ���
}Graph;

int *visited;
int virus = 0;

void GInit(Graph* pGraph, int numberOfVertex) {
	visited = (int*)malloc(sizeof(int) * numberOfVertex);
	pGraph->matrix = (int **)malloc(sizeof(int *) * numberOfVertex);   // �� �����Ҵ�
	for (int i = 0; i < numberOfVertex; i++) {
		pGraph->matrix[i] = (int *)malloc(sizeof(int) * numberOfVertex);  // �� �����Ҵ�
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
	else printf("�ߺ��� ����\n");
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

	printf("��ǻ�� �� : ");
	scanf("%d", &g.numberOfComputer);
	if (g.numberOfComputer > 100) {
		printf("��ǻ�� ���� 100 ���Ͽ��� �մϴ�"); exit(1);
	}
	GInit(&g, g.numberOfComputer);


	printf("����� ��ǻ�� ���� ���� : ");
	scanf("%d", &g.numberOfEdge);
	printf("��ǻ�� ��ȣ ��\n");    // ��ǻ�� ��ȣ�� 1���� ����
	for (int i = 0; i < g.numberOfEdge; i++) {
		scanf("%d %d", &n1, &n2);
		if( 1<= n1 && n1 <= g.numberOfComputer && 1 <= n2 && n2 <= g.numberOfComputer) GAddEdge(&g, n1, n2);
	}

	printf("���̷����� �ɸ� ��ǻ�� ��ȣ : ");
	scanf("%d", &v);

	dfs(&g, v - 1);
	printf("%d�� ��ǻ�Ϳ� ����Ǿ� ���̷����� �ɸ� ��ǻ�� : %d ��\n\n", v, virus);
}
*/







/*
// 27������ 6��
// ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.

//- 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
//- �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.
//  ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.
//  �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�.
//
//[�Է�]
//ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5<=N<=25)�� �Է�
//���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Է�
//
//[���]
//������ ��ȣ + ������ ������ ���
//��ü ���� �� ���

#include<stdio.h>
#include<stdlib.h>

int **matrix;
int **visited;
int size;
int cnt;  // ������ ������ count


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

		dfs(x - 1, y);   // ��
		dfs(x + 1, y);   // ��
		dfs(x, y - 1);   // ��
		dfs(x, y + 1);   // ��
		return true;
	}
	return false;
}

void main()
{
	int i, k;
	int village = 0;  // ������
	char s[30];
	printf("size : ");
	scanf("%d", &size);
	if (size < 5 || 25 < size) { printf("5�̻� 25������ ũ�⸦ �Է��ϼ���."); exit(1); }
	Init();

	printf("����ڷ��Է�\n");
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
				printf("%d ���� ������ %d \n", village, cnt);
			}
		}
	}
	printf("���� �� : %d\n", village);
}
*/







/*
// 7��   �ִܰŸ��� �ƴ����� �� ���� - ������ �˻�ޱ� - ������ 
// �̷� Ž��

// visited�迭 �������� �ʰ� matrix���� �ٲٴ� �ɷ� - �ѹ� ������ ���� 1 -> 0�� 
// �̷��� �Ҳ��� ���߿� �ٽ� Ž���ϰ� �� ���� ����� �� ������� �ٲ���� �� 0 -> 1��

// 1�̸� ���� 0�̸� ��

#include<stdio.h>
#include<stdlib.h>

int **matrix;
int n; int m;
int move;  // ������ ĭ��
int flag = 0;

// visited ���� �ʰ� �ѹ� ������ ĭ�� matrix�� ����
void Init(int n, int m) {
	matrix = (int**)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) 
		matrix[i] = (int*)malloc(sizeof(int) * m);
}

void dfs(int x, int y) {

	if (x < 0 || x >= n || y < 0 || y >= m) return;

	// �������� �����ϸ� �ٽ� ó����ġ�� �ǵ��ư��鼭 �׶� �̵�ĭ�� ++�ϸ鼭 ���
	if (x == n - 1 && y == m - 1 && matrix[x][y]) {
		move++;
		matrix[x][y] = 0;
		printf("�̷�Ż�� ����!\n");
		flag = 1;
	}

	if (matrix[x][y]) {
		if (flag == 1 && matrix[x][y]) return;
		
		matrix[x][y] = 0;  // �ѹ� ������ ĭ 0���� ����

		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);

		if (flag == 1) { move++;  printf("[ %d, %d ] -> ", x, y); }

		matrix[x][y] = 1; // ��ΰ� ������ �ǵ��ƿ��� ������� �ٸ���� �ٽ� Ž���ؾ��ϱ� ������ �ٽ� 1�� ����
	}
}


void main()
{
	char s[30];
	printf("N x M : ");
	scanf("%d %d", &n, &m);
	Init(n,m);

	printf("�̷� �Է�\n");
	for (int i = 0; i < n; i++) {
		scanf("%s", &s);
		for (int k = 0; k < m; k++)
			matrix[i][k] = s[k] - '0';
	}

	printf("�̷� ���\n");
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			printf("%4d ", matrix[i][k]);
		}
		printf("\n");
	}

	move = 0;
	dfs(0, 0);
	printf("\n\n�̵��� ĭ �� : %d\n", move);
}

*/






