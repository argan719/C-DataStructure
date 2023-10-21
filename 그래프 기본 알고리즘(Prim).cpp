
/*
// 1��
// Prim �˰����� ����Ͽ� �ּҺ�� ����Ʈ���� �����Ͽ� ���ô�.

//����Ʈ�� �ִ� �� �״�� �Է�

#include<stdio.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 7
#define INF 1000


int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0, 29, INF, INF, INF, 10, INF},
	{29, 0, 16, INF, INF, INF, 15},
	{INF, 16, 0, 12, INF, INF, INF},
	{INF, INF, 12, 0, 22, INF, 18},
	{INF, INF, INF, 22, 0, 27, 25},
	{10, INF, INF, INF, 27, 0, INF},
	{INF, 15, INF, 18, 25, INF, 0} };

int selected[MAX_VERTICES];
int dist[MAX_VERTICES];  // ���� ����ġ ����



// �ּ� dist[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
	int v, i;
	for(i=0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v])) v = i;  // �Ƹ� dist[v] �� INF
	return v;
}

// �� �κ� �ڵ� �����ϱ�
void prim(int s, int n)
{
	int i, u, v;
	for (u = 0; u < n; u++)
		dist[u] = INF;
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		u = get_min_vertex(n);  // dist �� ���� ���� ���� ����
		selected[u] = TRUE;
		if (dist[u] == INF) return;
		printf("%d ", u);   // ���� ���� ������ Ÿ�� ���ο� �������� �̵�
		for (v = 0; v < n; v++)
			if (weight[u][v] != INF)
				if (!selected[v] && weight[u][v] < dist[v])
					dist[v] = weight[u][v];  // ���� ���õ� ������ ��� ������ ����ġ ����
	}
}

void main()
{
	prim(0, MAX_VERTICES);
	//for (int i = 0; i < MAX_VERTICES; i++)
	//	printf("%4d", dist[i]);
}
*/





/*
// Prim �˰����� ����Ͽ� �ּҺ�� ����Ʈ���� �����Ͽ� ���ô�.
// ����, ���� �Է¹޾Ƽ� �����ϴ� �ɷ� ����

#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int dist[MAX_VERTICES];   // ���� ����ġ ����
int sum = 0;

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;     // ���β� 0 (0�� 0��, 1�� 1��..)
			else matrix[i][j] = INF;     // ������ INF�� �ʱ�ȭ
		}
	}
}
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!visited[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!visited[i] && (dist[i] < dist[v])) v = i;  // �Ƹ� dist[v] �� INF
	return v;
}

void prim(int s, int n) {
	int i, u, v;
	for (u = 0; u < n; u++)
		dist[u] = INF;
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		u = get_min_vertex(n);  // dist �� ���� ���� ���� ����
		visited[u] = TRUE;
		if (dist[u] == INF) return;
		printf("%d ", u);   // ���� ���� ������ Ÿ�� ���ο� �������� �̵� - ������ ���� ���
		sum += dist[u]; //�ּ� ��� ���ϱ�(�ִܰŸ� ����ġ ��)
		for (v = 0; v < n; v++)
			if (matrix[u][v] != INF)
				if (!visited[v] && matrix[u][v] < dist[v])
					dist[v] = matrix[u][v];  // ���� ���õ� ������ ��� ������ ����ġ ����
	}
}

void AddEdge(int a, int b, int val){
	matrix[a][b] = val;
	matrix[b][a] = val;
}

void main()
{
	printf("���� ����: ");
	scanf("%d", &numberOfVertex);
	printf("���� ����: ");
	scanf("%d", &numberOfEdge);
	init();

	int i, j;
	int a, b, val;
	printf("����1 ����2 ����ġ\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n");
	prim(0, numberOfVertex);

	printf("\n\n��� = %d\n", sum);   // �ּҺ�� ����ġ ��
}
*/





// ����Ǯ�� 5������

// 1��
/*
#include<stdio.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 7
#define INF 1000    

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0, 3, 17, 6, INF, INF, INF},  // A
	{3, 0, INF, 5, INF, INF, 12},   // B
	{17, INF, 0, INF, 10, 8, INF},  // C
	{6, 5, INF, 0, 9, INF, INF},   // D
	{INF, INF, 10, 9, 0, 4, 2},   // E
	{INF, INF, 8, INF, 4, 0, 14},  // F
	{INF, 12, INF, INF, 2, 14, 0} }; // G


int selected[MAX_VERTICES] = { 0, };
int dist[MAX_VERTICES];


int compare() {
	int min = INF;
	int idx;
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (dist[i] != 0 && dist[i] < min && !selected[i]) {
			min = dist[i];
			idx = i;
		}
	}
	return idx;
}

int Prim(int v) {
	v -= 65;
	int i, k;
	int min;
	int edge_accepted = 0;
	int sum = 0;

	while (edge_accepted < MAX_VERTICES - 1) {
		selected[v] = 1;
		for (k = 0; k < MAX_VERTICES; k++) {
			dist[k] = weight[v][k];
		}

		i = compare();
		edge_accepted++;
		printf("(%c %c : %d)  ", v+65, i+65, weight[v][i]);  // ���� ���ڷ� ���
		sum += weight[v][i];
		v = i;
	}

	return sum;
}

void main()
{
	int sum = Prim('A');   // ����A�� ����
	printf("\n�ִܺ�� : %d\n", sum);
}
*/




/*
// 3��
// ���� �׷����� �ּҽ��д� Ʈ��(=�ּҺ�� ����Ʈ��)�� ���ϴ� ���α׷��� �ۼ��Ͽ� ���ô�

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INF 1000


int matrix[MAX_VERTICES][MAX_VERTICES];   
int visited[MAX_VERTICES];  // �湮�� �������� 1, 0

int numberOfVertex;  // ��������
int numberOfEdge;    // ��������

void AddEdge(int a, int b, int val) {
	matrix[a][b] = val;
}

void init() {
	for (int i = 0; i < numberOfVertex; i++) {
		visited[i] = 0;
		for (int k = 0; k < numberOfVertex; k++)
			matrix[i][k] = INF;
	}
}


int compare() {
	int min = INF;
	int idx;
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (dist[i] != 0 && dist[i] < min && !visited[i]) {
			min = dist[i];
			idx = i;
		}
	}
	return idx;
}

int Prim(int v) {
	int i, k;
	int min;
	int edge_accepted = 0;
	int sum = 0;

	while (edge_accepted < MAX_VERTICES - 1) {
		visited[v-65] = 1;
		for (k = 0; k < MAX_VERTICES; k++) {
			dist[k] = weight[v][k];
		}

		i = compare();
		edge_accepted++;
		printf("(%d %d : %d)  ", v, i, weight[v][i]);
		sum += weight[v][i];
		v = i;
	}

	return sum;
}


void main()
{
	printf("���� ���� : ");
	scanf("%d", &numberOfVertex);
	getchar();
	printf("���� ���� : ");
	scanf("%d", &numberOfEdge);

	init();
	printf("����/����ġ �Է�\n");
	int i;
	char a, b;
	int val;
	char start;

	for (i = 0; i < numberOfEdge; i++) {
		getchar();
		scanf("%c %c %d", &a, &b, &val);
		//getchar();
		if (a >= 97) a -= 32;
		if (b >= 97) b -= 32;
		AddEdge(a-65, b-65, val); 
	}

	for (i = 0; i < numberOfVertex; i++) {
		for (int k = 0; k < numberOfVertex; k++)
			printf("%4d", matrix[i][k]);
		printf("\n");
	}

	getchar();
	printf("���� ���� : ");
	scanf("%c", &start);

	printf("�ִܺ�� : %d\n", Prim(start));

}
*/








// 4��
// ���� ������ Kruskal�˰���� Prim�˰����� ����Ͽ� ���� �ۼ��Ͽ� ���ô�. (4386 ���ڸ�)
//- ������ 2���� ��� ���� ���� �ִ�.
//- ���� �ϳ� ���� ������ �� �� ������ �Ÿ���ŭ�� ����� ��ٰ� �� ��, ���ڸ��� ����� �ּ� �����
//���ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.

// �Ÿ�: sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));


/*
// 1. Kruskal �̿�

#include<stdio.h>
#include<math.h>  // sqrt
#define MAX 100


// ��
typedef struct {
	double x;
	double y;
	int idx;  // parent�� ��Ī ���� ������ �ε��� ����(0���� ����) (for findParent, unionParent)
}Star;

// �� ���� �Ÿ�
typedef struct {
	Star a;  // ù��° ���
	Star b;  // �ι�° ���
	double val;
}Distance;

Star arr[MAX];
Distance distance[MAX];
int parent[MAX];

int numberOfVertex;
int numberOfEdge;

void AddEdge(int i, Star e) {
	arr[i] = e;
}

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
	int i, k, j;
	Distance tmp;
	Star e;
	printf("���� ���� : ");
	scanf("%d", &numberOfVertex);
	numberOfEdge = 0;

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	printf("�� ���� ��ǥ(x, y)\n");
	for (i = 0; i < numberOfVertex; i++) {
		scanf("%lf %lf", &e.x, &e.y);     
		e.idx = i;
		AddEdge(i, e);
	}

	// �� ���� �Ÿ� ��� �� ����
	int idx = 0;
	for (i = 0; i < numberOfVertex - 1; i++) {
		for (j = i + 1; j < numberOfVertex; j++) {
			distance[idx].a = arr[i];
			distance[idx].b = arr[j];
			distance[idx].val = sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
			idx++;
			numberOfEdge++;
		}
	}

	// �� ���� �Ÿ� ������������ ����
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (distance[i].val > distance[j].val) {
				tmp = distance[i];
				distance[i] = distance[j];
				distance[j] = tmp;
			}
	}

	double sum = 0;
	for (i = 0; i < numberOfEdge; i++)
	{
		// ����Ŭ�� �߻����� ���� ���� ����
		if (!findParent(distance[i].a.idx, distance[i].b.idx))   // i�� i+1�� �ƴ϶� Star a, Star b ��
		{
			unionParent(distance[i].a.idx, distance[i].b.idx);
			sum += distance[i].val;
		}
	}
	printf("\n\n���ڸ��� ����� �ּ� ��� : %.2f\n", sum);  // �ִܰŸ� ���� ����ġ�� ��
}
*/





/*
// 2. Prim �̿�

#include<stdio.h>
#include<math.h>  // sqrt
#define MAX_VERTICES 100
#define INF 1000

#define TRUE 1
#define FALSE 0


// ��
typedef struct {
	double x;
	double y;
	int idx;   // matrix������ �࿭ �� ��Ī ���� ������ �ε��� ����(0���� ����) = matrix ������ �࿭��
}Star;

Star arr[MAX_VERTICES];  // �� ����

int numberOfVertex;

double matrix[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES];
double dist[MAX_VERTICES];   // ���� ����ġ ����
double sum = 0;

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;     // ���β� 0 (0�� 0��, 1�� 1��..)
			else matrix[i][j] = INF;     // ������ INF�� �ʱ�ȭ
		}
	}
}
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!visited[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!visited[i] && (dist[i] < dist[v])) v = i;  
	return v;
}

void prim(int s, int n) {
	int i, u, v;
	for (u = 0; u < n; u++)
		dist[u] = INF;
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		u = get_min_vertex(n);  // dist �� ���� ���� ���� ����
		visited[u] = TRUE;
		if (dist[u] == INF) return;
		printf("%d ", u);   // ���� ���� ������ Ÿ�� ���ο� �������� �̵� - ������ ���� ���
		sum += dist[u];  // �ּ� ���(�ִܰŸ� ����ġ ��)
		for (v = 0; v < n; v++)
			if (matrix[u][v] != INF)
				if (!visited[v] && matrix[u][v] < dist[v])
					dist[v] = matrix[u][v];  // ���� ���õ� ������ ��� ������ ����ġ ����
	}
}

void AddEdge(int a, int b, double val) {  // ù��° ���� idx, �ι�° ���� idx, �� �� ������ �Ÿ�
	matrix[a][b] = val;
	matrix[b][a] = val;
}


void main()
{
	int i, j;
	Star e;
	printf("���� ���� : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("�� ���� ��ǥ(x, y)\n");
	for (i = 0; i < numberOfVertex; i++) {
		scanf("%lf %lf", &e.x, &e.y);
		e.idx = i;
		arr[i] = e;
	}

	// �Ÿ� ���ϱ�
	double distance;
	for (i = 0; i < numberOfVertex - 1; i++) {
		for (j = i + 1; j < numberOfVertex; j++) {
			distance = sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
			AddEdge(arr[i].idx, arr[j].idx, distance);
		}
	}

	prim(0, numberOfVertex);
	printf("\n\n���ڸ��� ����� �ּ� ��� : %.2f\n", sum);
}
*/


