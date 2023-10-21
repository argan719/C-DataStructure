
/*

// Floyd 알고리즘으로 가중치 포함 그래프의 각 정점에서 다른 모든 정점까지의 최단거리를 계산하여 봅시다.

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define VERTICES 5    // 정점의 수
#define INF 10000     // 무한대 (연결이 없는 경우)


// 네트워크의 인접행렬
int weight[VERTICES][VERTICES] = {
	{0, 1, INF, 1, 5},
	{9, 0, 3, 2, INF},
	{INF, INF, 0, 4, INF},
	{INF, INF, 2, 0, 3},
	{3, INF, INF, INF, 0} };


int A[VERTICES][VERTICES];


void printA(int n, int k)
{
	int i, j;
	printf("%d 를 거친 이후\n", k);
	printf("===================================\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (A[i][j] == INF)
				printf("INF ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("===================================\n");
}


void floyd(int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = weight[i][j];

	// K를 거쳐가는 노드 - 중간노드
	for (k = 0; k < n; k++) {
		// i -> 출발노드
		for (i = 0; i < n; i++)
			// j <- 도착노드
			for (j = 0; j < n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printA(n, k);
	}
}

void main()
{
	floyd(VERTICES);
}

*/






/*
// Floyd 알고리즘 정점, 가중치 입력받는 걸로 구현

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100   
#define INF 10000     // 무한대 (연결이 없는 경우)

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = INF;
		}
	}
}

void floyd() 
{
	int i, j, k;
	for (k = 0; k < numberOfVertex; k++) {
		for (i = 0; i < numberOfVertex; i++)
			for (j = 0; j < numberOfVertex; j++)
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) matrix[i][j] = matrix[i][k] + matrix[k][j];
	}
}

void AddEdge(int a, int b, int val)
{
	matrix[a][b] = val;
	matrix[b][a] = val;   // 이 부분 주석처리하면 방향성 그래프
}

void print()
{
	printf("===================================\n");
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) 
			printf("%3d", matrix[i][j]);
		printf("\n");
	}
	printf("===================================\n");
}

void main()
{
	int i, j;
	int a, b, val;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);
	init();

	printf("정점1, 정점 2, 가중치 입력 \n");

	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}
	// matrix 값 설정 완료

	floyd();
	print();
}

*/





/*

// 5페이지 2번
// 그래프의 최단경로 출력 (모든 정점쌍에 대하여 최단경로 출력)

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100   
#define INF 10000     // 무한대 (연결이 없는 경우)

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];
int next[MAX_VERTICES][MAX_VERTICES];   // 경로 저장

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = INF;
		}
	}
}

void floyd()
{
	int i, j, k;
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++)
			next[i][j] = j;
	}
	// i: 출발노드, j: 도착 노드, k: 경유 노드
	for (k = 0; k < numberOfVertex; k++) {
		for (i = 0; i < numberOfVertex; i++)
			for (j = 0; j < numberOfVertex; j++) {
				if (matrix[i][k] == INF || matrix[k][j] == INF) continue;

				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					// matrix가 업데이트 될 때 next도 업데이트
					next[i][j] = next[i][k];   // next[i][j]에는 i j의 최단경로 일때의 중간노드가 저장돼있음
				}
			}
				
	}
}

void AddEdge(int a, int b, int val)
{
	matrix[a][b] = val;
	matrix[b][a] = val;   
}

// 최종 갱신된 matrix값 출력
void print()
{
	printf("===================================\n");
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++)
			printf("%3d", matrix[i][j]);
		printf("\n");
	}
	printf("===================================\n");
}


// 두 정점 간의 최단경로 출력
void trace_path(int u, int v) {
	// 출발지와 도착지가 같다면 멈춘다
	if (u != v) {
		// 정점 u 이후에 방문해야할 정점으로 u업데이트 후
		printf("-> %2d", next[u][v]);
		u = next[u][v];
		// 재귀를 통해 반복 (u가 중간 노드들을 지나 점점 v로 이동) : u -> v
		trace_path(u, v);
	}
}

void main()
{
	int i, j;
	int a, b, val;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);
	init();

	printf("정점1, 정점 2, 가중치 입력 \n");

	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}
	// matrix 값 설정 완료

	floyd();
	//print();

	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			printf("[ %d->%d ] : ", i, j);
			printf("%2d", i);
			trace_path(i, j);
			printf("\n");
		}
		printf("\n");
	}

	// 사용자로부터 입력받은 두 정점 간의 최단경로 출력
	int start, end;
	printf("\n\n");
	printf("시작 ~ 종점 : ");
	scanf("%d %d", &start, &end);
	printf("%2d", start);
	trace_path(start, end);
}

*/






// 10페이지 문제풀이 시작
// 1번


/*
// 2번

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100   
#define INF 10000     // 무한대 (연결이 없는 경우)

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];
int next[MAX_VERTICES][MAX_VERTICES];   // 경로 저장

int sum;  // 최단경로 가중치 합

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = INF;
		}
	}
}

void floyd()
{
	int i, j, k;
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++)
			next[i][j] = j;
	}
	// i: 출발노드, j: 도착 노드, k: 경유 노드
	for (k = 0; k < numberOfVertex; k++) {
		for (i = 0; i < numberOfVertex; i++)
			for (j = 0; j < numberOfVertex; j++) {
				if (matrix[i][k] == INF || matrix[k][j] == INF) continue;

				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					// matrix가 업데이트 될 때 next도 업데이트
					next[i][j] = next[i][k];   // next[i][j]에는 i j의 최단경로 일때의 중간노드가 저장돼있음
				}
			}

	}
}

void AddEdge(int a, int b, int val)
{
	matrix[a][b] = val;
	//matrix[b][a] = val;
}


// 두 정점 간의 최단경로 출력
void trace_path(int u, int v) {
	// 출발지와 도착지가 같다면 멈춘다
	if (u != v) {
		// 정점 u 이후에 방문해야할 정점으로 u업데이트 후
		sum += matrix[u][next[u][v]];   
		u = next[u][v];
		printf("-> %2d", u);
		// 재귀를 통해 반복 (u가 중간 노드들을 지나 점점 v로 이동) : u -> v
		trace_path(u, v);
	}
}

void main()
{
	int i, j;
	int a, b, val;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);
	init();

	printf("정점1, 정점 2, 가중치 입력 \n");

	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}
	// matrix 값 설정 완료

	floyd();

	printf("=== 각 정점 사이의 최단경로\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			printf("[ %d->%d ] : ", i, j);
			printf("%2d", i);
			trace_path(i, j);
			printf("\n");
		}
		printf("\n");
	}

	// 사용자로부터 입력받은 두 정점 간의 최단경로 출력
	int start, end;
	printf("\n\n");
	printf("시작 ~ 종점 : ");
	scanf("%d %d", &start, &end);

	sum = 0; 
	printf("%2d", start);
	trace_path(start, end);
	printf("\n거리 : %d\n", sum);   
}
*/




/*
// 3번

//- 입력
//첫째 줄에 정점의 개수
//둘째 줄부터 N개의 줄에는 그래프의 인접 행렬
//i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고,
//0인 경우는 없다는 뜻, i번째 줄의 i번째 숫자는 항상 0이다.
//
//- 출력
//정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력한다.


#include<stdio.h>

#define MAX_VERTICES 100
#define INF 10000

int matrix[MAX_VERTICES][MAX_VERTICES];
int numberOfVertex;


void floyd()
{
	int k, i, j;

	for (k = 0; k < numberOfVertex; k++) {
		for (i = 0; i < numberOfVertex; i++) {
			for (j = 0; j < numberOfVertex; j++) {
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {   // floyd를 이용하는 것이므로 이 알고리즘은 변형하면 안됨.
					matrix[i][j] = matrix[i][k] + matrix[k][j];   // for문 3개 돌려서 하는 부분은 그대로 두고 ('부등호도 그대로')
				}									
				  // 그러니까 0을 INF로 만든거임.
			}     // 0 = INF 니까 INF보다 작으면 무조건 갱신 -> 경로 있는거임. INF였는데 중간노드 거치니까 INF 보다 작은 값으로 변경 => 경로생겼다는 뜻(불가능(0)에서 가능으로(1))
		}   // 값이 뭐든 INF보다 작은게 중요한거임. INF 보다 작은 값을 갖고 있으면 1로 출력 (=> 경로가 있는거기 때문에)
	}   // INF면 0으로 출력 (=>경로 없음)
	// 가중치가 없으므로, 
	// 모든 경로를 해봐도 여전히 매트릭스 값의 합이 0이면 경로 없는거고 (다 돌았는데도 매트릭스 값이 0이면)
}   // 매트릭스 값이 0이 아니고 다른 값으로 갱신됐으면 (INF보다 작으면) 경로가 있는거임 1, 1+1 ,1+1+1 ..


void main()
{
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	int i, j;
	char s[MAX_VERTICES];

	for (i = 0; i < numberOfVertex; i++) {
		scanf("%s", s);  // 한 줄씩 입력받기
		for (j = 0; j < numberOfVertex; j++) {
			if (s[j] - '0' == 0) matrix[i][j] = INF;   // 0은 INF - 경로없음을 뜻함.
			else matrix[i][j] = s[j] - '0';
		}
	}
	// 갱신 전 매트릭스 출력
	printf("\n\n- 입력\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			if (matrix[i][j] == INF) printf("%5d", 0);
			else printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}


	floyd();
	
	// 갱신 후 매트릭스 출력
	printf("\n\n- 출력\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			if (matrix[i][j] == INF ) matrix[i][j] = 0;
			else matrix[i][j] = 1;
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
}

*/





// 문제풀이 4번, 5번 남음 -  두 문제 이어서 풀기

// 4번 - 이어서 풀기
#include<stdio.h>
#define MAX_VERTICES 100
#define INF 100000

int numberOfStudent;  // 정점개수
int numberOfEdge;   // 간선개수
int numberOfCompare;   // 비교횟수
int matrix[MAX_VERTICES][MAX_VERTICES];   // i, j의 값이 1이면 i < j  (i -> j : 방향성그래프)

int visited[MAX_VERTICES];

typedef struct twin {
	int a;  // i
	int b;  // j   (i < j)
}compare_student;


void init()
{
	for (int i = 0; i < numberOfStudent; i++) {
		for (int j = 0; j < numberOfStudent; j++) {
			matrix[i][j] = INF;
		}
		visited[i] = 0;
	}
}

void AddEdge(int i, int j)
{
	matrix[i][j] = 1;   // 방향성 그래프 (i학생의 키가 j학생의 키보다 작은 것을 뜻함. i < j)
}


void floyd()
{
	int i, j, k;
	for (k = 0; k < numberOfStudent; k++) {
		for (i = 0; i < numberOfStudent; i++)
			for (j = 0; j < numberOfStudent; j++)
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) matrix[i][j] = matrix[i][k] + matrix[k][j];
	}
}

void main()
{
	int i, j;
	printf("학생의 수 : ");
	scanf("%d", &numberOfStudent);
	printf("간선의 수 : ");
	scanf("%d", &numberOfEdge);
	init();

	int x, y;
	printf("키 입력 ( i < j ) : i j \n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d", &x, &y);
		AddEdge(x-1, y-1);
	}

	printf("\n비교한 횟수 : ");
	scanf("%d", &numberOfCompare);

	compare_student arr[MAX_VERTICES];

	floyd();

	printf("A < B : \n");
	int sum = 0;
	for (i = 0; i < numberOfStudent; i++) {
		for (j = 0; j < numberOfStudent; j++) {
			if (matrix[j][i] < INF) {
				printf("%d %d\n", j+1, i+1);    // -> 이걸 따로 저장해야함 - 자신의 키를 알 수 있는 학생 수 구하기 위해선
				arr[sum].a = j;
				arr[sum].b = i;
				sum++;
			}
			if (sum == numberOfCompare) break;
		}
		if (sum == numberOfCompare) break;

	}

	 // 뭔가가 오지게 잘못됨.
	int start;
	int cnt = 0;
	int tot = 0;
	for (i = 0; i < numberOfStudent; i++) {
		start = arr[i].a;
		if (visited[start] == 1) continue;
		visited[start] = 1;
		cnt = 0;

		/*
		for (j = 0; j < numberOfCompare; j++) {
			if (matrix[start][j] < INF) cnt++;     // 나보다 큰 사람 (내가 작은 경우)
			if (matrix[j][start] < INF) cnt++;     // 나보다 작은 사람 (내가 큰 경우)
		}*/

		// 전체 matrix에서 돌리는게 아니라 arr안에서 돌려서 찾아야 하는거임.
		for (j = 0; j < numberOfCompare; j++) {
			if(matrix[arr[j].a][])
		}


		if (cnt == numberOfStudent - 1) {
			tot++;  // 나보다 작은 학생 수 + 나보다 큰 학생 수 = (전체학생수 - 1)   => 자신의 키가 몇번째인지 알 수 있음
			printf("\n알 수 있는 학생 번호 : %d\n", start + 1);
		}
	}

	printf("\n자신의 키를 알 수 있는 학생 수 : %d\n\n", tot);

}