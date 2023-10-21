

/*
// Dijkstra 구현
// 키보드로 정점, 가중치 입력 받아서 행렬 생성하는 걸로 구현

#include<stdio.h>
#include<limits.h>
#define INF 1000       // 무한대 (연결이 없는 경우)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // 시작정점으로부터의 최단경로 거리
int visited[MAX_VERTICES];   // 방문한 정점 표시

int weight[MAX_VERTICES][MAX_VERTICES];    // 네트워크의 인접행렬

int numberOfVertex;  // 정점개수
int numberOfEdge;   // 간선개수

void init()
{   // 인접행렬 초기구성
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	weight[b][a] = val;       // 이부분 주석처리하면 방향 그래프로 됨
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

	for (i = 0; i < n; i++) {    // 초기화
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;
	printf("%4d", start);

	for (i = 1; i < n; i++) {  // 정점개수가 7이라면 이 과정 총 6번 반복 (정점개수 n이라면 이 과정 n-1 번 반복)
		u = get_min_val();   // 현재 상태 중(현재 정점의 인접정점 중) 가장 작은 가중치 정점 선택

		if (!visited[u]) {
			visited[u] = TRUE;
			printf("%4d", u);   // 최단경로, 집합S 에 추가된 정점 출력
			p = distance[u];  // 기준 값 - 현재 정점까지의 가중치 합
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; // 누적값이 현재값보다 더 작다면 갱신
			}
		}
	}
}

void main()
{
	int i;
	int a, b, val;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	printf("\n정점1 정점2 가중치 입력\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n집합S =  ");
	dijkstra(0, numberOfVertex);

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++)
		sum += distance[i];

	printf("\n최단거리 => %d\n\n", sum);
}

*/




/*

// Dijkstra 구현
// 키보드로 간선, 가중치 입력 받아서 행렬 생성하는 걸로 구현

// 연결이 끊어져 있는 것 까지 대비한 코드 (위와 똑같은 코드에 위에 코드보다 더 추가함)

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
{   // 인접행렬 초기구성
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	//weight[b][a] = val;    // 이부분 주석처리하면 방향 그래프로 됨
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
	if (min == INF) return -1;     // 최소값이 무한대인 경우
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
		if (u == -1) break;  // 최소값이 무한대인 경우 더 이상 가지 않고 종료.
		
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
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	printf("\n정점1 정점2 가중치 입력\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n집합S =  ");
	dijkstra(0, numberOfVertex);

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++)
		if(distance[i] != INF) sum += distance[i];   // 가중치 합 구할때 무한대는 제외

	printf("\n최단거리 => %d\n\n", sum);
}

*/




/*
// 프린트에 있는 코드 그대로 입력
// Dijkstra 최단거리 프로그램을 작성하여 봅시다.

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7      // 정점의 수
#define INF 1000   // 무한대 (연결이 없는 경우)


// 네트워크의 인접행렬
int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0} };


int distance[MAX_VERTICES];  // 시작정점으로부터의 최단경로 거리
int found[MAX_VERTICES];     // 방문한 정점 표시

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
	for (i = 0; i < n; i++)   // 초기화
	{
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;   // 시작 정점 방문 표시
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
	printf("==> 최단거리 : %d", tot);
}
*/








// 문제풀이 시작
/*
// 4번

#include<stdio.h>
#include<limits.h>
#define INF 1000       // 무한대 (연결이 없는 경우)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // 시작정점으로부터의 최단경로 거리
int visited[MAX_VERTICES];   // 방문한 정점 표시

int weight[MAX_VERTICES][MAX_VERTICES];    // 네트워크의 인접행렬

int numberOfVertex;  // 정점개수
int numberOfEdge;   // 간선개수

void init()
{   // 인접행렬 초기구성
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

// 방향성 그래프
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

	for (i = 0; i < n; i++) {  // 초기화
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
	printf("도시개수 : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("도로개수 : ");
	scanf("%d", &numberOfEdge);

	printf("출발도시 : ");
	scanf("%d", &start);
	printf("거리정보 : ");
	scanf("%d", &dis);


	printf("\n도로(간선)/소요시간1\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d", &a, &b);  // 도로는 1부터 시작, 방향성 그래프
		AddEdge(a-1, b-1, 1);
	}

	dijkstra(start-1, numberOfVertex);

	int flag = 0;
	printf("\n==> 거리가 %d인 도시 : ", dis);
	for (i = 0; i < numberOfVertex; i++) {
		if (distance[i] == dis) { printf("%2d ", i+1); flag = 1; }   
	}

	if (flag == 0) printf(" 없음");
	printf("\n");
}

*/





// 5번   // 각 정점마다의 최단경로 출력하는 부분 해결못함

#include<stdio.h>
#include<limits.h>
#define INF 1000       // 무한대 (연결이 없는 경우)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // 시작정점으로부터의 최단경로 거리
int visited[MAX_VERTICES];   // 방문한 정점 표시

int weight[MAX_VERTICES][MAX_VERTICES];    // 네트워크의 인접행렬

int numberOfVertex;  // 정점개수
int numberOfEdge;   // 간선개수


void init()
{   // 인접행렬 초기구성
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

	for (i = 0; i < n; i++) {    // 초기화
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;

	for (i = 1; i < n; i++) {  
		u = get_min_val();   

		if (!visited[u]) {
			visited[u] = TRUE;
			p = distance[u];  // 기준 값 - 현재 정점까지의 가중치 합
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; // 누적값이 현재값보다 더 작다면 갱신
			}
		}
	}
}

int path[MAX_VERTICES][MAX_VERTICES];
int idx[MAX_VERTICES];   
// 이 함수 - 해결하기 - 해결함 - 더 깔끔하게 수정
void get_shortest_path_each_node(int start, int n, int v) {
	int i, u;
	int p;

	for (i = 0; i < n; i++) {    // 초기화
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

			p = distance[u];  // 기준 값 - 현재 정점까지의 가중치 합
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
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	printf("\n정점1 정점2 가중치 입력\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n\n각 정점의 최단경로:\n");     
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

	printf("\n\n시작정점 0 에서\n각 정점까지의 최단거리\n");
	for(i=0;i<numberOfVertex;i++)
		printf("%3d", i);
	printf("\n");

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++) {
		sum += distance[i];
		printf("%3d", distance[i]);
	}

	printf("\n\n최단거리 => %d\n\n", sum);
}


// 6번은 5번과 같은 유형
// 5번 코드 더 깔끔하게 수정해보고
// 6번도 풀기
// 7번은 진득하게 생각많이 해서 풀기



/*

// 7번
// 다음의 경우에서 N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하는 
// 프로그램을 작성하여 봅시다.

//- N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.
//- 어느 날 이 N명의 학생이 X번 마을에 모여서 파티를 벌이기로 했다.
//  이 마을 사이에는 총 M개의 단방향 도로들이 있고 각 도로마다 소요되는 시간이 있다.
//- 각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다.
//- 이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를수도 있다.




#include<stdio.h>
#include<limits.h>
#define INF 1000       // 무한대 (연결이 없는 경우)
#define MAX_VERTICES 100   

#define TRUE 1
#define FALSE 0

int distance[MAX_VERTICES];   // 시작정점으로부터의 최단경로 거리
int visited[MAX_VERTICES];   // 방문한 정점 표시

int weight[MAX_VERTICES][MAX_VERTICES];    // 네트워크의 인접행렬

int numberOfVertex;  // 정점개수
int numberOfEdge;   // 간선개수

void init()
{   // 인접행렬 초기구성
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = INF;
		}
	}
}

void AddEdge(int a, int b, int val) {
	weight[a][b] = val;
	//weight[b][a] = val;       // 이부분 주석처리하면 방향 그래프로 됨
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

	for (i = 0; i < n; i++) {    // 초기화
		distance[i] = weight[start][i];
		visited[i] = FALSE;
	}
	visited[start] = TRUE;
	distance[start] = 0;
	printf("%4d", start);

	for (i = 1; i < n; i++) {  // (정점개수 n이라면 이 과정 n-1 번 반복)
		u = get_min_val();   // 현재 상태 중(현재 정점의 인접정점 중) 가장 작은 가중치 정점 선택

		if (!visited[u]) {
			visited[u] = TRUE;
			printf("%4d", u);   // 최단경로, 집합S 에 추가된 정점 출력
			p = distance[u];  // 기준 값 - 현재 정점까지의 가중치 합
			for (int k = 0; k < n; k++) {
				if (!visited[k] && p + weight[u][k] < distance[k]) distance[k] = p + weight[u][k]; // 누적값이 현재값보다 더 작다면 갱신
			}
		}
	}
}

void main()
{
	int i;
	int a, b, val;
	printf("학생수 : ");
	scanf("%d", &numberOfVertex);
	init();

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	printf("\n정점1 정점2 가중치 입력\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}

	printf("\n집합S =  ");
	dijkstra(0, numberOfVertex);

	int sum = 0;
	for (i = 0; i < numberOfVertex; i++)
		sum += distance[i];

	printf("\n최단거리 => %d\n\n", sum);
}

*/


