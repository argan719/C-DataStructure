
/*
// 위상정렬 알고리즘 구현

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100

// 원형큐 사용
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType q;

// 초기화 함수
void init_queue()
{
	q.front = q.rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return q->front == q->rear;
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
// 삽입 함수
void enqueue(element item)
{
	if (is_full(&q))
		printf("큐가 포화상태입니다\n");
	else {
		q.rear = (q.rear + 1) % MAX_QUEUE_SIZE;
		q.queue[q.rear] = item;
	}

}
// 삭제 함수
element dequeue()
{
	if (is_empty(&q))
		printf("큐가 공백상태입니다\n");
	else {
		q.front = (q.front + 1) % MAX_QUEUE_SIZE;
		return q.queue[q.front];
	}
}


// 그래프 형성
int numberOfVertex;
int numberOfEdge;
int matrix[MAX_VERTICES][MAX_VERTICES];

void init()
{
	for (int i = 0; i < numberOfVertex; i++) {
		for (int j = 0; j < numberOfVertex; j++) {
			matrix[i][j] = 0;
		}
	}
}

// 방향성 그래프 - 위상정렬 조건
void AddEdge(int x, int y)
{
	matrix[x][y] = 1;
}


// 위상정렬
void topo_sort()
{
	int i, j;
	// arr - 진입차수 개수 저장
	int *arr = (int *)malloc(sizeof(int) * numberOfVertex);
	// 큐에 들어왔던 노드 저장 (진입차수가 0 돼서 큐에 한번 들어왔으면 visited값 0->1)
	int *visited = (int *)malloc(sizeof(int) * numberOfVertex);
	// 초기화
	for (i = 0; i < numberOfVertex; i++) {
		arr[i] = 0;
		visited[i] = 0;
	}
	// 진입차수 카운트
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			if (matrix[i][j] == 1) arr[j]++;
		}
	}

	// 맨 처음 진입차수가 0인 모든 노드 큐에 삽입
	for (i = 0; i < numberOfVertex; i++) {
		if (arr[i] == 0) {
			enqueue(i);
			visited[i] = 1;
		}
	}

	int v;
	while (!is_empty(&q)) {
		v = dequeue();
		printf("%2d -> ", v+1);  // 출력
		for (i = 0; i < numberOfVertex; i++) {
			if (matrix[v][i] == 1) arr[i]--;   // 진입차수 제거 (진입차수--)

			if (arr[i] == 0 && !visited[i]) {
				enqueue(i);    // 새롭게 진입차수가 0된 노드가 있다면 큐에 삽입
				visited[i] = 1;
			}
		}
	}
}

void main()
{
	int i, j;
	printf("노드개수 : ");
	scanf("%d", &numberOfVertex);

	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);
	init();
	init_queue();

	int a, b;
	printf("\n간선입력(A,B)\n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d", &a, &b);
		AddEdge(a-1, b-1);
	}

	printf("\n");
	topo_sort();
}
*/



/*
// 프린트에 있는 위상정렬 알고리즘 구현 코드 그대로 입력해보고 비교하기
// 6페이지 1번

// 위상정렬 알고리즘을 구현하여 봅시다.
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct GraphType {
	int n;   // 정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
}GraphType;

// 그래프 초기화
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// 정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;
	if(u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}


// Stack부분
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화 함수
void init(StackType *s)
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return(s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}



// 위상정렬을 수행한다
int topo_sort(GraphType *g)
{
	int i;
	StackType s;
	GraphNode *node;

	// 모든 정점의 진입 차수를 계산
	int *in_degree = (int *)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)    // 초기화
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode *node = g->adj_list[i];    // 정점 i에서 나오는 간선들
		while (node != NULL) {
			in_degree[node->vertex]++;  // 진입차수++ (진입차수 카운트)
			node = node->link;
		}
	}
	// 진입 차수가 0인 정점을 스택에 삽입
	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) push(&s, i);
	}
	// 위상 순서를 생성
	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		printf("%d", w);  // 정점 출력
		node = g->adj_list[w];  // 각 정점의 진입 차수를 변경
		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;    // 진입 차수를 감소 (pop한 정점 w와 연결되었던 모든 노드의 진입차수--)
			if (in_degree[u] == 0) push(&s, u);  // 새롭게 진입차수가 0된 노드가 있으면 삽입
			node = node->link;  // 다음 정점
		}
	}
	free(in_degree);
	return (i == g->n);   // 반환값이 1이면 성공, 0이면 실패
}

void main()
{
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	// 정점 0의 인접 리스트 생성
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	// 정점 1의 인접 리스트 생성
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	// 정점 2의 인접 리스트 생성
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	// 정점 3의 인접 리스트 생성
	insert_edge(&g, 3, 5);
	// 정점 4의 인접 리스트 생성
	insert_edge(&g, 4, 5);
	// 위상 정렬
	topo_sort(&g);
}
*/




// 문제풀이 시작
// 4번
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100

// 원형큐 사용
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType q;

// 초기화 함수
void init_queue()
{
	q.front = q.rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return q->front == q->rear;
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
// 삽입 함수
void enqueue(element item)
{
	if (is_full(&q))
		printf("큐가 포화상태입니다\n");
	else {
		q.rear = (q.rear + 1) % MAX_QUEUE_SIZE;
		q.queue[q.rear] = item;
	}

}
// 삭제 함수
element dequeue()
{
	if (is_empty(&q))
		printf("큐가 공백상태입니다\n");
	else {
		q.front = (q.front + 1) % MAX_QUEUE_SIZE;
		return q.queue[q.front];
	}

}


int numberOfStudent;
int numberOfCompare;
int matrix[MAX_VERTICES][MAX_VERTICES];

void init()
{
	for (int i = 0; i < numberOfStudent; i++) {
		for (int j = 0; j < numberOfStudent; j++) {
			matrix[i][j] = 0;
		}
	}
}

void AddEdge(int x, int y)
{
	matrix[x][y] = 1;
}

// 위상정렬
void topo_sort()
{
	int i, j;
	// arr - 진입차수 개수 저장
	int *arr = (int *)malloc(sizeof(int) * numberOfStudent);
	// 큐에 들어왔던 노드 저장 (진입차수가 0 돼서 큐에 한번 들어왔으면 visited값 0->1)
	int *visited = (int *)malloc(sizeof(int) * numberOfStudent);
	// 초기화
	for (i = 0; i < numberOfStudent; i++) {
		arr[i] = 0;
		visited[i] = 0;
	}
	// 진입차수 카운트
	for (i = 0; i < numberOfStudent; i++) {
		for (j = 0; j < numberOfStudent; j++) {
			if (matrix[i][j] == 1) arr[j]++;
		}
	}

	// 맨 처음 진입차수가 0인 모든 노드 큐에 삽입
	for (i = 0; i < numberOfStudent; i++) {
		if (arr[i] == 0) {
			enqueue(i);
			visited[i] = 1;
		}
	}

	int v;
	while (!is_empty(&q)) {
		v = dequeue();
		printf("%2d -> ", v + 1);  // 출력
		for (i = 0; i < numberOfStudent; i++) {
			if (matrix[v][i] == 1) arr[i]--;   // 진입차수 제거 (진입차수--)

			if (arr[i] == 0 && !visited[i]) {
				enqueue(i);    // 새롭게 진입차수가 0된 노드가 있다면 큐에 삽입
				visited[i] = 1;
			}
		}
	}
}


void main()
{
	printf("학생수 : ");
	scanf("%d", &numberOfStudent);
	printf("비교한 횟수 : ");
	scanf("%d", &numberOfCompare);
	printf("비교한 값 A<B\n");  // 사용자로부터 입력받음.
	init();

	int a, b;
	for (int i = 0; i < numberOfCompare; i++) {
		scanf("%d %d", &a, &b);
		AddEdge(a-1, b-1);
	}

	printf("\n줄세운 결과\n");
	topo_sort();
	printf("\n");
}
*/




/*
// 5번
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100
// 원형큐 사용
typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

QueueType q;

// 초기화 함수
void init_queue()
{
	q.front = q.rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return q->front == q->rear;
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
// 삽입 함수
void enqueue(element item)
{
	if (is_full(&q))
		printf("큐가 포화상태입니다\n");
	else {
		q.rear = (q.rear + 1) % MAX_QUEUE_SIZE;
		q.queue[q.rear] = item;
	}

}
// 삭제 함수
element dequeue()
{
	if (is_empty(&q))
		printf("큐가 공백상태입니다\n");
	else {
		q.front = (q.front + 1) % MAX_QUEUE_SIZE;
		return q.queue[q.front];
	}

}


typedef struct task {
	int time;  // 작업시간
	int front_task;  // 선행작업개수 (최초 설정된 선행작업개수)
	int front_task_num[MAX_VERTICES];  // 선행작업번호
	int front_task_final;   // (-- 되는 선행작업개수)
}Task;

int numberOfTask;
int sum = 0;
Task *t;

void topo_sort()
{
	int i, j;
	int max;
	// 큐에 들어왔던 노드 저장 (진입차수가 0 돼서 큐에 한번 들어왔으면 visited값 0->1)
	int *visited = (int *)malloc(sizeof(int) * numberOfTask);
	// 초기화
	for (i = 0; i < numberOfTask; i++) {
		visited[i] = 0;
	}

	max = 0;
	// 맨 처음 진입차수가 0인 모든 노드 큐에 삽입
	for (i = 0; i < numberOfTask; i++) {
		if (t[i].front_task == 0) {
			enqueue(i);
			visited[i] = 1;
			if (max < t[i].time) max = t[i].time;
		}
	}
	sum += max;
	//printf("\n더한 값 : %d\n", max);

	int v;
	int flag;
	max = 0;
	while (!is_empty(&q)) {
		v = dequeue();
		flag = 0;
		printf("%2d  ", v + 1);  // 출력
		for (i = 0; i < numberOfTask; i++) {
			for (j = 0; j < t[i].front_task; j++) {
				if (t[i].front_task_num[j] == v) {
					t[i].front_task_final--;
					if (max < t[i].time) max = t[i].time;
					flag++;   // 같은 선행작업번호를 둔 노드 갯수 - 한 위상에 있는 노드 개수
				}
			}
		}

		for (i = 0; i < numberOfTask; i++) {
			if (t[i].front_task_final == 0 && !visited[i]) {
				enqueue(i);    // 새롭게 진입차수가 0된 노드가 있다면 큐에 삽입
				flag--;
				visited[i] = 1;
			}
		}
		if (flag == 0) {  // 같은 위상에 있는 모든 노드 중 (작업시간)최댓값을 구해야 함 - 그 값만 sum에 더해야 함
			sum += max; 
			printf("\n더한 값 : %d\n", max);
			max = 0;
		}
	}
}

void main()
{
	int num;
	printf("작업의 개수 : ");
	scanf("%d", &numberOfTask);
	t= (Task *)malloc(sizeof(Task) * numberOfTask);

	printf("작업시간/선행작업개수/선행작업번호\n");
	for (int i = 0; i < numberOfTask; i++) {
		scanf("%d %d", &t[i].time, &t[i].front_task);
		t[i].front_task_final = t[i].front_task;
		for (int j = 0; j < t[i].front_task; j++) {
			printf("선행작업번호 (%d) ", j + 1);
			scanf("%d", &num);
			t[i].front_task_num[j] = num - 1;
		}
	}

	printf("\n\n");
	topo_sort();
	printf("\n모든 작업을 완료하기 위한 최소 시간 : %d \n", sum);
}
*/
