

/*
// Dijkstra ����
// Ű����� ����, ����ġ �Է� �޾Ƽ� ��� �����ϴ� �ɷ� ����

#include<stdio.h>
#include<limits.h>
#define INF 1000       // ���Ѵ� (������ ���� ���)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // �����������κ����� �ִܰ�� �Ÿ�
int visited[MAX_VERTICES];   // �湮�� ���� ǥ��

int weight[MAX_VERTICES][MAX_VERTICES];    // ��Ʈ��ũ�� �������

int numberOfVertex;  // ��������
int numberOfEdge;   // ��������

void init()
{   // ������� �ʱⱸ��
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	weight[b][a] = val;       // �̺κ� �ּ�ó���ϸ� ���� �׷����� ��
}

int get_min_val() {
	int min = INT_MAX;
	int min_idx = -1;
	for (int i = 0; i < numberOfVertex; i++) {
		if (distance[i] < min && !visited[i]) {
			min = distance[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void dijkstra(int start, int n) {          
	int i, u;                                  
	int p;

	for (i = 0; i < n; i++) {    // �ʱ�ȭ
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;
	printf("%4d", start);

	for (i = 1; i < n; i++) {  // ���������� 7�̶�� �� ���� �� 6�� �ݺ� (�������� n�̶�� �� ���� n-1 �� �ݺ�)
		u = get_min_val();   // ���� ���� ��(���� ������ �������� ��) ���� ���� ����ġ ���� ����

		if (!visited[u]) {
			visited[u] = TRUE;
			printf("%4d", u);   // �ִܰ��, ����S �� �߰��� ���� ���
			p = distance[u];  // ���� �� - ���� ���������� ����ġ ��
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; // �������� ���簪���� �� �۴ٸ� ����
			}
		}
	}
}

void main()
{
	int i;
	int a, b, val;
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	printf("\n����1 ����2 ����ġ �Է�\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n����S =  ");
	dijkstra(0, numberOfVertex);

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++)
		sum += distance[i];

	printf("\n�ִܰŸ� => %d\n\n", sum);
}

*/




/*

// Dijkstra ����
// Ű����� ����, ����ġ �Է� �޾Ƽ� ��� �����ϴ� �ɷ� ����

// ������ ������ �ִ� �� ���� ����� �ڵ� (���� �Ȱ��� �ڵ忡 ���� �ڵ庸�� �� �߰���)

#include<stdio.h>
#include<limits.h>
#define INF 1000       
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   
int visited[MAX_VERTICES];   

int weight[MAX_VERTICES][MAX_VERTICES];    

int numberOfVertex;  
int numberOfEdge;  

void init()
{   // ������� �ʱⱸ��
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	//weight[b][a] = val;    // �̺κ� �ּ�ó���ϸ� ���� �׷����� ��
}

int get_min_val() {
	int min = INT_MAX;
	int min_idx = -1;
	for (int i = 0; i < numberOfVertex; i++) {
		if (distance[i] < min && !visited[i]) {
			min = distance[i];
			min_idx = i;
		}
	}
	if (min == INF) return -1;     // �ּҰ��� ���Ѵ��� ���
	return min_idx;
}

void dijkstra(int start, int n) {          
	int i, u;                                  
	int p;

	for (i = 0; i < n; i++) {  
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	printf("%4d", start);

	for (i = 1; i < n; i++) {  
		u = get_min_val();   
		if (u == -1) break;  // �ּҰ��� ���Ѵ��� ��� �� �̻� ���� �ʰ� ����.
		
		if (!visited[u]) {
			visited[u] = TRUE;
			printf("%4d", u);   
			p = distance[u];  
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; 
			}
		}
	}

}

void main()
{
	int i;
	int a, b, val;
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	printf("\n����1 ����2 ����ġ �Է�\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n����S =  ");
	dijkstra(0, numberOfVertex);

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++)
		if(distance[i] != INF) sum += distance[i];   // ����ġ �� ���Ҷ� ���Ѵ�� ����

	printf("\n�ִܰŸ� => %d\n\n", sum);
}

*/




/*
// ����Ʈ�� �ִ� �ڵ� �״�� �Է�
// Dijkstra �ִܰŸ� ���α׷��� �ۼ��Ͽ� ���ô�.

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7      // ������ ��
#define INF 1000   // ���Ѵ� (������ ���� ���)


// ��Ʈ��ũ�� �������
int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0} };


int distance[MAX_VERTICES];  // �����������κ����� �ִܰ�� �Ÿ�
int found[MAX_VERTICES];     // �湮�� ���� ǥ��

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}


void shortest_path(int start, int n)
{
	int i, u, w;
	for (i = 0; i < n; i++)   // �ʱ�ȭ
	{
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;   // ���� ���� �湮 ǥ��
	distance[start] = 0;

	for (i = 0; i < n - 1; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
	}
}

void main()
{
	shortest_path(0, MAX_VERTICES);
	int tot = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		printf("%3d", distance[i]);
		tot += distance[i];
	}
	printf("==> �ִܰŸ� : %d", tot);
}
*/








// ����Ǯ�� ����
/*
// 4��

#include<stdio.h>
#include<limits.h>
#define INF 1000       // ���Ѵ� (������ ���� ���)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // �����������κ����� �ִܰ�� �Ÿ�
int visited[MAX_VERTICES];   // �湮�� ���� ǥ��

int weight[MAX_VERTICES][MAX_VERTICES];    // ��Ʈ��ũ�� �������

int numberOfVertex;  // ��������
int numberOfEdge;   // ��������

void init()
{   // ������� �ʱⱸ��
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

// ���⼺ �׷���
void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	//weight[b][a] = val;
}


int get_min_val() {
	int min = INT_MAX;
	int min_idx = -1;
	for (int i = 0; i < numberOfVertex; i++) {
		if (distance[i] < min && !visited[i]) {
			min = distance[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void dijkstra(int start, int n) {          
	int i, u;                                  
	int p;

	for (i = 0; i < n; i++) {  // �ʱ�ȭ
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;

	for (i = 1; i < n; i++) {  
		u = get_min_val();   

		if (!visited[u]) {
			visited[u] = TRUE;
			p = distance[u]; 
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; 
			}
		}
	}

}

void main()
{
	int i;
	int a, b;
	int start;
	int dis;
	printf("���ð��� : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("���ΰ��� : ");
	scanf("%d", &numberOfEdge);

	printf("��ߵ��� : ");
	scanf("%d", &start);
	printf("�Ÿ����� : ");
	scanf("%d", &dis);


	printf("\n����(����)/�ҿ�ð�1\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d", &a, &b);  // ���δ� 1���� ����, ���⼺ �׷���
		AddEdge(a-1, b-1, 1);
	}

	dijkstra(start-1, numberOfVertex);

	int flag = 0;
	printf("\n==> �Ÿ��� %d�� ���� : ", dis);
	for (i = 0; i < numberOfVertex; i++) {
		if (distance[i] == dis) { printf("%2d ", i+1); flag = 1; }   
	}

	if (flag == 0) printf(" ����");
	printf("\n");
}

*/





// 5��   // �� ���������� �ִܰ�� ����ϴ� �κ� �ذ����

#include<stdio.h>
#include<limits.h>
#define INF 1000       // ���Ѵ� (������ ���� ���)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // �����������κ����� �ִܰ�� �Ÿ�
int visited[MAX_VERTICES];   // �湮�� ���� ǥ��

int weight[MAX_VERTICES][MAX_VERTICES];    // ��Ʈ��ũ�� �������

int numberOfVertex;  // ��������
int numberOfEdge;   // ��������


void init()
{   // ������� �ʱⱸ��
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	weight[b][a] = val;      
}

int get_min_val() {
	int min = INT_MAX;
	int min_idx = -1;
	for (int i = 0; i < numberOfVertex; i++) {
		if (distance[i] < min && !visited[i]) {
			min = distance[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void dijkstra(int start, int n) {
	int i, u;
	int p;

	for (i = 0; i < n; i++) {    // �ʱ�ȭ
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;

	for (i = 1; i < n; i++) {  
		u = get_min_val();   

		if (!visited[u]) {
			visited[u] = TRUE;
			p = distance[u];  // ���� �� - ���� ���������� ����ġ ��
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; // �������� ���簪���� �� �۴ٸ� ����
			}
		}
	}
}

int path[MAX_VERTICES][MAX_VERTICES];
int idx[MAX_VERTICES];   
// �� �Լ� - �ذ��ϱ� - �ذ��� - �� ����ϰ� ����
void get_shortest_path_each_node(int start, int n, int v) {
	int i, u;
	int p;

	for (i = 0; i < n; i++) {    // �ʱ�ȭ
		distance[i] = weight[start][i];
		visited[i] = FALSE;
		idx[i] = 0;
		for (int k = 0; k < n; k++)
			path[i][k] = 0;
	}
	visited[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < n; i++) {
		path[i][0] = start;
	}

	for (i = 1; i < n; i++) {
		u = get_min_val();

		if (!visited[u]) {
			visited[u] = TRUE;
			path[u][++idx[u]] = u;  

			p = distance[u];  // ���� �� - ���� ���������� ����ġ ��
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) {
					distance[k] = p + weight[u][k];
					idx[k] = -1;
					for (int j = 0; j <= idx[u]; j++) {
						path[k][++idx[k]] = path[u][j];
					}
				}
			}
		}
	}
}



void main()
{
	int i;
	int a, b, val;
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	printf("\n����1 ����2 ����ġ �Է�\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n\n�� ������ �ִܰ��:\n");     
	for (i = 1; i < numberOfVertex; i++) {
		get_shortest_path_each_node(0, numberOfVertex, i);
	}

	for (int a = 0; a < numberOfVertex; a++) {
		for (int b = idx[a]; 0<= b ; b--) {
			printf("%2d <- ", path[a][b]);
		}
		printf("\n");
	}

	dijkstra(0, numberOfVertex);

	printf("\n\n�������� 0 ����\n�� ���������� �ִܰŸ�\n");
	for(i=0;i<numberOfVertex;i++)
		printf("%3d", i);
	printf("\n");

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++) {
		sum += distance[i];
		printf("%3d", distance[i]);
	}

	printf("\n\n�ִܰŸ� => %d\n\n", sum);
}


// 6���� 5���� ���� ����
// 5�� �ڵ� �� ����ϰ� �����غ���
// 6���� Ǯ��
// 7���� �����ϰ� �������� �ؼ� Ǯ��



/*

// 7��
// ������ ��쿡�� N���� �л��� �� ���� ���µ� ���� ���� �ð��� �Һ��ϴ� �л��� �������� ���ϴ� 
// ���α׷��� �ۼ��Ͽ� ���ô�.

//- N���� ���ڷ� ���е� ������ ������ �� ���� �л��� ��� �ִ�.
//- ��� �� �� N���� �л��� X�� ������ �𿩼� ��Ƽ�� ���̱�� �ߴ�.
//  �� ���� ���̿��� �� M���� �ܹ��� ���ε��� �ְ� �� ���θ��� �ҿ�Ǵ� �ð��� �ִ�.
//- ������ �л����� ��Ƽ�� �����ϱ� ���� �ɾ�� �ٽ� �׵��� ������ ���ƿ;� �Ѵ�.
//- �� ���ε��� �ܹ����̱� ������ �Ƹ� �׵��� ���� ���� ���� �ٸ����� �ִ�.




#include<stdio.h>
#include<limits.h>
#define INF 1000       // ���Ѵ� (������ ���� ���)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // �����������κ����� �ִܰ�� �Ÿ�
int visited[MAX_VERTICES];   // �湮�� ���� ǥ��

int weight[MAX_VERTICES][MAX_VERTICES];    // ��Ʈ��ũ�� �������

int numberOfVertex;  // ��������
int numberOfEdge;   // ��������

void init()
{   // ������� �ʱⱸ��
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	//weight[b][a] = val;       // �̺κ� �ּ�ó���ϸ� ���� �׷����� ��
}

int get_min_val() {
	int min = INT_MAX;
	int min_idx = -1;
	for (int i = 0; i < numberOfVertex; i++) {
		if (distance[i] < min && !visited[i]) {
			min = distance[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void dijkstra(int start, int n) {
	int i, u;
	int p;

	for (i = 0; i < n; i++) {    // �ʱ�ȭ
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;
	printf("%4d", start);

	for (i = 1; i < n; i++) {  // (�������� n�̶�� �� ���� n-1 �� �ݺ�)
		u = get_min_val();   // ���� ���� ��(���� ������ �������� ��) ���� ���� ����ġ ���� ����

		if (!visited[u]) {
			visited[u] = TRUE;
			printf("%4d", u);   // �ִܰ��, ����S �� �߰��� ���� ���
			p = distance[u];  // ���� �� - ���� ���������� ����ġ ��
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; // �������� ���簪���� �� �۴ٸ� ����
			}
		}
	}
}

void main()
{
	int i;
	int a, b, val;
	printf("�л��� : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	printf("\n����1 ����2 ����ġ �Է�\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n����S =  ");
	dijkstra(0, numberOfVertex);

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++)
		sum += distance[i];

	printf("\n�ִܰŸ� => %d\n\n", sum);
}

*/


