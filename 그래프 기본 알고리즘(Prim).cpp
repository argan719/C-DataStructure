
/*
// 1번
// Prim 알고리즘을 사용하여 최소비용 신장트리를 구현하여 봅시다.

//프린트에 있는 거 그대로 입력

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
int dist[MAX_VERTICES];  // 간선 가중치 저장



// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for(i=0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v])) v = i;  // 아마 dist[v] 는 INF
	return v;
}

// 이 부분 코드 이해하기
void prim(int s, int n)
{
	int i, u, v;
	for (u = 0; u < n; u++)
		dist[u] = INF;
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		u = get_min_vertex(n);  // dist 중 가장 작은 간선 선택
		selected[u] = TRUE;
		if (dist[u] == INF) return;
		printf("%d ", u);   // 가장 작은 간선을 타고 새로운 정점으로 이동
		for (v = 0; v < n; v++)
			if (weight[u][v] != INF)
				if (!selected[v] && weight[u][v] < dist[v])
					dist[v] = weight[u][v];  // 새로 선택된 정점의 모든 간선의 가중치 저장
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
// Prim 알고리즘을 사용하여 최소비용 신장트리를 구현하여 봅시다.
// 정점, 간선 입력받아서 생성하는 걸로 구현

#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int dist[MAX_VERTICES];   // 간선 가중치 저장
int sum = 0;

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;     // 본인꺼 0 (0행 0열, 1행 1열..)
			else matrix[i][j] = INF;     // 나머지 INF로 초기화
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
		if (!visited[i] && (dist[i] < dist[v])) v = i;  // 아마 dist[v] 는 INF
	return v;
}

void prim(int s, int n) {
	int i, u, v;
	for (u = 0; u < n; u++)
		dist[u] = INF;
	dist[s] = 0;
	for (i = 0; i < n; i++) {
		u = get_min_vertex(n);  // dist 중 가장 작은 간선 선택
		visited[u] = TRUE;
		if (dist[u] == INF) return;
		printf("%d ", u);   // 가장 작은 간선을 타고 새로운 정점으로 이동 - 지나간 정점 출력
		sum += dist[u]; //최소 비용 구하기(최단거리 가중치 합)
		for (v = 0; v < n; v++)
			if (matrix[u][v] != INF)
				if (!visited[v] && matrix[u][v] < dist[v])
					dist[v] = matrix[u][v];  // 새로 선택된 정점의 모든 간선의 가중치 저장
	}
}

void AddEdge(int a, int b, int val){
	matrix[a][b] = val;
	matrix[b][a] = val;
}

void main()
{
	printf("정점 개수: ");
	scanf("%d", &numberOfVertex);
	printf("간선 개수: ");
	scanf("%d", &numberOfEdge);
	init();

	int i, j;
	int a, b, val;
	printf("정점1 정점2 가중치\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n");
	prim(0, numberOfVertex);

	printf("\n\n결과 = %d\n", sum);   // 최소비용 가중치 합
}
*/





// 문제풀이 5페이지

// 1번
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
		printf("(%c %c : %d)  ", v+65, i+65, weight[v][i]);  // 정점 문자로 출력
		sum += weight[v][i];
		v = i;
	}

	return sum;
}

void main()
{
	int sum = Prim('A');   // 정점A를 시작
	printf("\n최단비용 : %d\n", sum);
}
*/




/*
// 3번
// 다음 그래프의 최소스패닝 트리(=최소비용 신장트리)를 구하는 프로그램을 작성하여 봅시다

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INF 1000


int matrix[MAX_VERTICES][MAX_VERTICES];   
int visited[MAX_VERTICES];  // 방문한 정점인지 1, 0

int numberOfVertex;  // 정점개수
int numberOfEdge;    // 간선개수

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
	printf("정점 개수 : ");
	scanf("%d", &numberOfVertex);
	getchar();
	printf("간선 개수 : ");
	scanf("%d", &numberOfEdge);

	init();
	printf("간선/가중치 입력\n");
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
	printf("시작 정점 : ");
	scanf("%c", &start);

	printf("최단비용 : %d\n", Prim(start));

}
*/








// 4번
// 다음 문제를 Kruskal알고리즘과 Prim알고리즘을 사용하여 각각 작성하여 봅시다. (4386 별자리)
//- 별들이 2차원 평면 위에 놓여 있다.
//- 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을
//구하는 프로그램을 작성하여 봅시다.

// 거리: sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));


/*
// 1. Kruskal 이용

#include<stdio.h>
#include<math.h>  // sqrt
#define MAX 100


// 별
typedef struct {
	double x;
	double y;
	int idx;  // parent값 매칭 위해 별마다 인덱스 설정(0부터 시작) (for findParent, unionParent)
}Star;

// 별 사이 거리
typedef struct {
	Star a;  // 첫번째 노드
	Star b;  // 두번째 노드
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
	printf("별의 개수 : ");
	scanf("%d", &numberOfVertex);
	numberOfEdge = 0;

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	printf("각 별의 좌표(x, y)\n");
	for (i = 0; i < numberOfVertex; i++) {
		scanf("%lf %lf", &e.x, &e.y);     
		e.idx = i;
		AddEdge(i, e);
	}

	// 별 사이 거리 계산 후 저장
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

	// 별 사이 거리 오름차순으로 정렬
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
		// 사이클이 발생하지 않을 때만 선택
		if (!findParent(distance[i].a.idx, distance[i].b.idx))   // i랑 i+1이 아니라 Star a, Star b 비교
		{
			unionParent(distance[i].a.idx, distance[i].b.idx);
			sum += distance[i].val;
		}
	}
	printf("\n\n별자리를 만드는 최소 비용 : %.2f\n", sum);  // 최단거리 간선 가중치의 합
}
*/





/*
// 2. Prim 이용

#include<stdio.h>
#include<math.h>  // sqrt
#define MAX_VERTICES 100
#define INF 1000

#define TRUE 1
#define FALSE 0


// 별
typedef struct {
	double x;
	double y;
	int idx;   // matrix에서의 행열 값 매칭 위해 별마다 인덱스 설정(0부터 시작) = matrix 에서의 행열값
}Star;

Star arr[MAX_VERTICES];  // 별 저장

int numberOfVertex;

double matrix[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES];
double dist[MAX_VERTICES];   // 간선 가중치 저장
double sum = 0;

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;     // 본인꺼 0 (0행 0열, 1행 1열..)
			else matrix[i][j] = INF;     // 나머지 INF로 초기화
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
		u = get_min_vertex(n);  // dist 중 가장 작은 간선 선택
		visited[u] = TRUE;
		if (dist[u] == INF) return;
		printf("%d ", u);   // 가장 작은 간선을 타고 새로운 정점으로 이동 - 지나간 정점 출력
		sum += dist[u];  // 최소 비용(최단거리 가중치 합)
		for (v = 0; v < n; v++)
			if (matrix[u][v] != INF)
				if (!visited[v] && matrix[u][v] < dist[v])
					dist[v] = matrix[u][v];  // 새로 선택된 정점의 모든 간선의 가중치 저장
	}
}

void AddEdge(int a, int b, double val) {  // 첫번째 별의 idx, 두번째 별의 idx, 두 별 사이의 거리
	matrix[a][b] = val;
	matrix[b][a] = val;
}


void main()
{
	int i, j;
	Star e;
	printf("별의 개수 : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("각 별의 좌표(x, y)\n");
	for (i = 0; i < numberOfVertex; i++) {
		scanf("%lf %lf", &e.x, &e.y);
		e.idx = i;
		arr[i] = e;
	}

	// 거리 구하기
	double distance;
	for (i = 0; i < numberOfVertex - 1; i++) {
		for (j = i + 1; j < numberOfVertex; j++) {
			distance = sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
			AddEdge(arr[i].idx, arr[j].idx, distance);
		}
	}

	prim(0, numberOfVertex);
	printf("\n\n별자리를 만드는 최소 비용 : %.2f\n", sum);
}
*/


