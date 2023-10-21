

/*
// 9������ 1��
// ���� ����� �̿��� �׷��� �߻� ������ Ÿ���� �����Ͽ� ���ô�.

// ���� ����
#include<stdio.h>
#define MAX_VERTICES 10
typedef struct GraphType {
	int n;   // ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];    // 10�� 10��
}GraphType;

typedef struct edge {
	int start;
	int end;
}Edge;

// 0���� �迭 �ʱ�ȭ
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
	printf("���� ����: ");
	scanf("%d", &graph.n);
	printf("���� ����: ");
	scanf("%d", &e);
	for (i = 0; i < e; i++) {
		printf("����(a,b): ");
		scanf("%d  %d", &line.start, &line.end);
		graph.adj_mat[line.start][line.end] = 1;
		graph.adj_mat[line.end][line.start] = 1;
	}

	// ���
	for (i = 0; i < graph.n; i++) {
		for (k = 0; k < graph.n; k++)
			printf("%4d", graph.adj_mat[i][k]);
		printf("\n");
	}
}
*/



/*
// 9������ 1)
// ����Ʈ�� �ִ� �� �״�� �Է�

#include<stdio.h>
#define MAX_VERTICES 10
typedef struct GraphType {
	int n;   // ������ ����
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


// ���� ���� ����
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("�׷��� �������� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType *g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		printf("�׷��� ���� ��ȣ ����");
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
// 11������ 2��
// ���� ����Ʈ�� �̿��� �׷��� �߻� ������ Ÿ���� �����Ͽ� ���ô�.

// ���� ����
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
	printf("���� ����: ");
	scanf("%d", &v);
	printf("���� ����: ");
	scanf("%d", &e);

	list = (Node**)malloc(sizeof(Node *) * v); // ���� ������ŭ *�Ҵ�
	init(&list, v);

	for (i = 0; i < e; i++) {
		printf("����(a,b): ");
		scanf("%d %d", &start, &end);
		flag = 0;

		// start�� end ��ũ
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

		// end�� start ��ũ
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


	// ���
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
// 11������ 2)
// ����Ʈ�� �ִ� �� �״�� �Է�

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10

typedef struct GraphNode {
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // ������ ����
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

//���� ���� ����
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("�׷��� �������� �ʰ�");
		return;
	}
	g->n++;
}
//���� ���� ����
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if (u >= g->n || v >= g->n) {
		printf("�׷��� ���� ��ȣ ����");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
	// null���� ������ ��ũ Ÿ�� ���� null�ڸ��� �����ϴ� ���� �ƴ϶�
	// ���� ���� ��ũ�� list ó���� �Ŵް� ���� �ִ� ��ũ�� ���� ���� ��ũ �ڷ� �Ŵ���.
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






// 18������ 10��, 11��
// ���ڸ��� ���ĺ����� �ϱ�




/*
// 10��
// ��������� ����Ͽ� �׷��� �����ϴ� ���α׷�
#include<stdio.h>
#include<stdlib.h>

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
		printf("6. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1: {
			printf("������ ����: ");   scanf("%d", &g.numberOfVertex);
			GInit(&g, g.numberOfVertex);
		}break;
		case 2: {
			getchar();
			printf("��������(���ĺ�from~ to): "); 
			scanf("%c %c", &f, &t);
			if (f >= 97) f = f - 32;  
			if (t >= 97) t = t - 32;

			if (f == t) printf("�߸��� ���� �Է�\n");
			else if(65<= f && f < 65 + g.numberOfVertex && 65 <= t && t < 65 + g.numberOfVertex) GAddEdge(&g, f, t);
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
		default: n = 6; break;
		}
		printf("\n");
	} while (n != 6);
	
	printf("����Ǿ����ϴ�.\n");
	GDestroy(&g);
}
*/






// 11��
// ��������Ʈ�� ����Ͽ� �׷��� �����ϴ� ���α׷� 

// 11��
// �� ó���� ���� ������ �ٴ� �� �ƴ϶� �� ������ ���ĺ����� �ް� �����ؾ� ��
// ����Ʈ �� �ε����� ù��° ���� �� ������ ���������� �ƴ϶� �� ������ ���� ���ĺ��̴�.

//������ ����Ʈ�� 0��°�̸� �װ� ����0�� �ǹ��ϴ� ������ �����ϰ� �ٷ� 0�� ������������ �Ŵޱ� ����������
// ���ĺ����� �ϹǷ� (� ���ĺ��� � �ε������� �𸥴ٰ� ����) �� �ε����� �� ó������ (�� ������ ����)���ĺ��� �޷��� �ϰ�
// �� �ڷ� ���������� �޷��� �Ѵ�.



/*
#include<stdio.h>
#include<stdlib.h>

typedef struct GraphNode {
	char vertex;     // ��(���ĺ�)
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // ��������
	int v;   // ��������
	GraphNode **adj_list;
}Graph;


void GInit(Graph* pGraph, int nubmerOfVertex);   // �׷��� ����
void GDestroy(Graph* pGraph);               // �׷��� �����޸� ����
void GAddEdge(Graph* pGraph,  char from, char to);   // �׷��� �����߰�
int GDeleteEdge(Graph* pGraph, char from, char to);  // �׷��� ���� ����
int GIsConnected(Graph* pGraph, int from, int to);  // �׷��� ����Ȯ��


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
	pGraph->v = 0;
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
		pGraph->v++;
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
				if (p->vertex == to) { flag = 1; break;}
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
		printf("1. ��������\n");
		printf("2. �����߰�\n");
		printf("3. ��������\n");
		printf("4. ��������\n");
		printf("5. ���\n");
		printf("6. ����\n");
		printf("==> ");   scanf("%d", &n);

		switch (n) {
		case 1:{		
			printf("������ ����: ");   scanf("%d", &g.n);
			GInit(&g, g.n); 
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
			printf("���� ����: %d\n", g.v);
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
	printf("����Ǿ����ϴ�.\n");
}

*/



