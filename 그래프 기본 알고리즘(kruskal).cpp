

/*
// 1번
// union find를 사용하여 Kruskal알고리즘 구현

#include<stdio.h>
#define MAX 100

typedef struct {
	int v1;    // 첫번째 노드
	int v2;    // 두번째 노드
	int distance;    // 간선가중치
}Edge;

Edge arr[MAX];
int parent[MAX];

int numberOfVertex;
int numberOfEdge;

void AddEdge(int i, Edge e){
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
	Edge tmp;
	Edge e;
	printf("노드개수 : ");
	scanf("%d", &numberOfVertex);
	printf("Edge개수 : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		printf("노드1, 노드2, 가중치 : ");
		scanf("%d %d %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// 간선 가중치 기준으로 정렬
	for (i = 0; i < numberOfEdge - 1; i++) {
		for(j = i+1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	for (i = 0; i < numberOfEdge; i++) 
	{
		// 사이클이 발생하지 않을 때만 선택
		if (!findParent(arr[i].v1, arr[i].v2))
		{
			unionParent(arr[i].v1, arr[i].v2);
			sum += arr[i].distance;
		}
	}
	printf("sum : %d\n", sum);  // 간선 가중치의 합
}
*/






/*
// 2번 - 잘나옴

// heap정렬을 이용하여 Kruskal의 알고리즘을 구현하여 봅시다.
// 최소힙 사용

// 배열 대신 최소힙 통해 간선 가중치 정렬해서 kruskal구현
// 나머지 다 똑같고 (간선 가중치를) 배열 대신 힙 써서 정렬하는 것만 다름
// 이거 구현하고 나머지 뒤에 문제 쭉 다 풀면 됨


#include<stdio.h>
#define MAX 100

typedef struct {
	int v1;    // 첫번째 노드
	int v2;    // 두번째 노드
	int distance;    // 간선가중치
}Edge;

int numberOfVertex;
int numberOfEdge;

Edge arr[MAX];
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


// 최소힙 - 간선가중치 기준으로 정렬
Edge heap_sort(int idx) {
	Edge root = arr[1];   // 루트 노드 저장 
	arr[1] = arr[idx]; // 가장 마지막 노드가 루트노드로 이동
	int end = idx - 1;  // 마지막 인덱스-1 = 삭제 후 배열에 들어있는 노드 총 개수(end)
	int level = end / 2;  // 아래로 level칸만큼 이동
	int sum = 1;
	if (end > 1) {
		for (int i = 1;; i++) {
			sum *= 2;
			if (level < sum) {
				level = i; break;
			}
		}
	}

	Edge tmp;
	int i = 0;
	idx = 1;
	while (i < level) {
		tmp = arr[idx];
		if (arr[idx * 2].distance < arr[idx * 2 + 1].distance) {  // 왼쪽자식이 더 작을 경우
			if (idx * 2 == end + 1) break;   
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}
		}
		else {   // 오른쪽자식이 더 작을 경우
			if (idx * 2 + 1 == end + 1) {  
				if (arr[idx * 2].distance < tmp.distance) {  
					arr[idx] = arr[idx * 2];
					arr[idx * 2] = tmp;
					idx = idx * 2;
					break;
				}
			}
			else {
				arr[idx] = arr[idx * 2 + 1];
				arr[idx * 2 + 1] = tmp;
				idx = idx * 2 + 1;
			}
		}
		i++;
	}

	return root;
}

void up(int idx) {
	Edge tmp;
	while (idx > 1) {
		if (arr[idx / 2].distance > arr[idx].distance) {
			tmp = arr[idx / 2];
			arr[idx / 2] = arr[idx];
			arr[idx] = tmp;
			idx = idx / 2;
		}
		else break;
	}
}
void insert_heap(int idx, Edge e) {
	arr[idx] = e;
	if (idx > 1) up(idx);
}

void main()
{
	int i, k, j;
	Edge e;
	printf("노드개수 : ");
	scanf("%d", &numberOfVertex);
	printf("Edge개수 : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 1;
	for (i = 0; i < numberOfEdge; i++) {
		printf("노드1, 노드2, 가중치 : ");
		scanf("%d %d %d", &e.v1, &e.v2, &e.distance);
		insert_heap(k, e);
		k++;
	}

	int sum = 0;
	for (i = 0; i < numberOfEdge; i++)
	{
		e = heap_sort(--k);
		// 사이클이 발생하지 않을 때만 선택
		if (!findParent(e.v1, e.v2))
		{
			unionParent(e.v1, e.v2);
			sum += e.distance;
		}
	}
	printf("sum : %d\n", sum);  // 간선 가중치의 합
}
*/



/*
// 2번 - 위와 동일한 문제 프린트에 있는 코드

#include<stdio.h>
#define MAX_VERTICES 10

int parent[MAX_VERTICES];   // 부모 노드
int num[MAX_VERTICES];    // 각 집합의 크기

void setInit(int n)
{
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = -1;
		num[i] = 1;
	}
}

int findParent(int vertex)   
{
	int p, s, i = -1;
	for (i = vertex; (p = parent[i]) >= 0; i = p);

	s = i;    // 집합의 대표 원소
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		parent[i] = s;   // 집합의 모든 원소들의 부모를 p로 설정
	return s;
}

void unionParent(int s1, int s2)  
{
	if (num[s1] < num[s2]) {
		parent[s1] = s2;
		num[s2] += num[s1];
	}
	else {
		parent[s2] = s1;
		num[s1] += num[s2];
	}
}


typedef struct {
	int distance;  // 간선의 가중치
	int u;   // 정점 1
	int v;   // 정점 2
}element;


#define MAX_ELEMENT 100
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}


// Heap 출력
void printHeap(HeapType* h)
{
	int i;
	int level = 1;
	printf("\n=======================================");
	for (i = 1; i <= h->heap_size; i++) {
		if (i == level) {
			printf("\n");
			level *= 2;
		}
		printf("\t%d", h->heap[i].distance);
	}
	printf("\n=======================================");
}

// 삽입
void insertHeap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.distance < h->heap[i / 2].distance)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;   // 새로운 노드를 삽입
}

// 삭제
element deleteHeap(HeapType* h)   
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].distance) > h->heap[child + 1].distance)
			child++;
		if (temp.distance <= h->heap[child].distance) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}


void insertHeapEdge(HeapType* h, int u, int v, int weight)
{
	element e;
	e.u = u;
	e.v = v;
	e.distance = weight;
	insertHeap(h, e);
}

void insertAllEdge(HeapType* h)
{
	insertHeapEdge(h, 0, 1, 29);
	insertHeapEdge(h, 1, 2, 16);
	insertHeapEdge(h, 2, 3, 12);
	insertHeapEdge(h, 3, 4, 22);
	insertHeapEdge(h, 4, 5, 27);
	insertHeapEdge(h, 5, 0, 10);
	insertHeapEdge(h, 6, 1, 15);
	insertHeapEdge(h, 6, 3, 18);
	insertHeapEdge(h, 6, 4, 25);
}

void kruskal(int n)
{
	int edge_accepted = 0;  // 현재까지 선택된 간선의 수
	HeapType h;   // 최소 힙
	int uset, vset;   // 정점 u와 정점 v의 집합 번호
	element e;    // 힙 요소

	init(&h);    // 힙 초기화
	insertAllEdge(&h);   // 힙에 간선들 삽입
	printHeap(&h);
	printf("\n");
	setInit(n);   // 집합 초기화

	while (edge_accepted < (n - 1))  // 간선의 수 < (n-1)
	{
		e = deleteHeap(&h);    // 최소 힙에서 삭제

		uset = findParent(e.u);    // 정점 u의 집합 번호
		vset = findParent(e.v);    // 정점 v의 집합 번호

		if (uset != vset) {    // 서로 속한 집합이 다르면
			printf("(%d,%d)  %d  \n", e.u, e.v, e.distance);
			edge_accepted++;
			unionParent(uset, vset);   // 두개의 집합을 합친다.
		}
	}
	printf("\n");
	for (int i = 0; i <= MAX_VERTICES; i++)
		printf("%3d", parent[i]);
	printf("\n");
	for (int i = 0; i <= MAX_VERTICES; i++)
		printf("%3d", num[i]);
}

void main()
{
	kruskal(7);  // (입력하고자 하는 그래프의)노드 개수=7
}
*/








// 12페이지 문제풀이

/*
// 2번
// 다음 그래프를 kruskal알고리즘을 이용하여 최단거리와 경로를 출력하여 봅시다

#include<stdio.h>
#define MAX 100

typedef struct {
	int v1;    // 첫번째 노드
	int v2;    // 두번째 노드
	int distance;    // 간선가중치
}Edge;

Edge arr[MAX];
int parent[MAX];

int numberOfVertex;
int numberOfEdge;

void AddEdge(int i, Edge e) {
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
	Edge tmp;
	Edge e;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		printf("정점1, 정점2, 가중치 : ");
		scanf("%d %d %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// 간선 가중치 기준으로 정렬
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	printf("최단거리 경로 : ");
	for (i = 0; i < numberOfEdge; i++)
	{
		// 사이클이 발생하지 않을 때만 선택
		if (!findParent(arr[i].v1, arr[i].v2))
		{
			unionParent(arr[i].v1, arr[i].v2);
			sum += arr[i].distance;
			printf("(%d  %d :  %d)  ", arr[i].v1, arr[i].v2, arr[i].distance);  // 경로출력
		}
	}
	printf("\n최단거리  : %d\n", sum);  // 간선 가중치의 합
}
*/





/*
// 3번
// Kruskal 알고리즘을 이용하여 최소비용 신장트리를 구하여 봅시다

// 2번과 똑같은 코드 사용
// 단, 정점 값 알파벳으로 변경

#include<stdio.h>
#include<string>
#define MAX 100

typedef struct {
	char v1;    // 첫번째 노드
	char v2;    // 두번째 노드
	int distance;    // 간선가중치
}Edge;

Edge arr[MAX];
int parent[MAX];

int numberOfVertex;
int numberOfEdge;

void AddEdge(int i, Edge e) {
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
	Edge tmp;
	Edge e;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		getchar();

		printf("정점1, 정점2, 가중치 : ");
		scanf("%c %c %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// 간선 가중치 기준으로 정렬
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	printf("최단거리 경로 : ");
	for (i = 0; i < numberOfEdge; i++)
	{
		// 사이클이 발생하지 않을 때만 선택
		if (!findParent(arr[i].v1 - 64, arr[i].v2 - 64))  // A이면 1, B이면 2..
		{
			unionParent(arr[i].v1 - 64, arr[i].v2 - 64);
			sum += arr[i].distance;
			printf("(%c  %c :  %d)  ", arr[i].v1, arr[i].v2, arr[i].distance);  // 경로출력
		}
	}
	printf("\n최단거리  : %d\n", sum);  // 간선 가중치의 합
}
*/




/*
// 4번
// 다음 가중 그래프에 대하여 쿠르스칼 알고리즘을 수행하여 최소비용 신장트리를 구하여 봅시다.

// 3번과 똑같은 코드 사용
#include<stdio.h>
#include<string>
#define MAX 100

typedef struct {
	char v1;    // 첫번째 노드
	char v2;    // 두번째 노드
	int distance;    // 간선가중치
}Edge;

Edge arr[MAX];
int parent[MAX];

int numberOfVertex;
int numberOfEdge;

void AddEdge(int i, Edge e) {
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
	Edge tmp;
	Edge e;
	printf("정점개수 : ");
	scanf("%d", &numberOfVertex);
	printf("간선개수 : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		getchar();

		printf("정점1, 정점2, 가중치 : ");
		scanf("%c %c %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// 간선 가중치 기준으로 정렬
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	printf("최단거리 경로 : ");
	for (i = 0; i < numberOfEdge; i++)
	{
		// 사이클이 발생하지 않을 때만 선택
		if (!findParent(arr[i].v1 - 64, arr[i].v2 - 64))  // A이면 1, B이면 2..
		{
			unionParent(arr[i].v1 - 64, arr[i].v2 - 64);
			sum += arr[i].distance;
			printf("(%c  %c :  %d)  ", arr[i].v1, arr[i].v2, arr[i].distance);  // 경로출력
		}
	}
	printf("\n최단거리  : %d\n", sum);  // 간선 가중치의 합
}
*/





/*
// 5번
// 학생들이 공부를 더욱 효율적으로 할 수 있도록 전국에 흩어져 있는 학원들을 네트워크로 연결하려고 한다.
//- 모든 학원들을 네트워크로 연결하려면 너무 많은 비용이 필요하기 때문에 학원들을 연결하는 비용을
//최소가 되게 하려고 한다.
//- 학원들은 연결되어 있는 다른 학원의 회선을 공유할 수 있다. 
//- 아래 그림과 같이 학원 사이를 연결하기 위한 비용이 주어지면 모든 학원을 연결하기 위한 최소의
//비용을 구하는 프로그램을 작성하여 봅시다.


//=== 입력형식
//첫줄에 학원의 수 N(3<= N <=100)이 주어진다. 둘째 줄부터 NxN의 행렬로 100,000이하의 정수가 공백으로
//구분되어 입력된다.
//행렬의 i j는 i번 학원에서 j번 학원을 연결하기 위한 비용을 나타낸다.



#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
	int v;   // 첫번째 정점
	int e;   // 두번째 정점
	int distance;   // 간선가중치
}Edge;

int matrix[MAX][MAX];
int numberOfVertex;

Edge arr[MAX] = { 0, };
int parent[MAX];


int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
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


int main()
{
	int i, k, j;
	Edge tmp;
	scanf("%d", &numberOfVertex);
	for (i = 0; i < numberOfVertex; i++) {
		for (k = 0; k < numberOfVertex; k++)
			scanf("%d", &matrix[i][k]);
	}

	printf("\nmatrix 출력\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (k = 0; k < numberOfVertex; k++)  
			printf("%4d", matrix[i][k]);  
		printf("\n");
	}
	printf("\n");


	// Edge배열에 간선 삽입 (matrix값을 Edge구조로 저장)
	int idx = 0;
	for (i = 0; i < numberOfVertex - 1; i++) {
		for (k = i + 1; k < numberOfVertex; k++) {
			arr[idx].v = i;   
			arr[idx].e = k;
			arr[idx].distance = matrix[i][k];
			idx++;
		}
	}

	// Edge배열 간선가중치 기준 오름차순 정렬
	for (i = 0; i < idx - 1; i++) {
		for (j = i + 1; j < idx; j++) {
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	//printf("\n정렬된 간선 출력\n");
	//for (int i = 0; i < 20; i++)
	//	printf("%d %d : %d\n", arr[i].v, arr[i].e, arr[i].distance);

	// parent값 초기화
	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	int edge_accepted = 0;
	i = 0;
	int sum = 0;
	while (edge_accepted < (numberOfVertex - 1)) {
		if (!findParent(arr[i].v, arr[i].e)) {
			sum += arr[i].distance;
			unionParent(arr[i].v, arr[i].e);
			edge_accepted++;
		}
		i++;
	}

	printf("최소비용 : %d\n\n", sum);
}
*/



