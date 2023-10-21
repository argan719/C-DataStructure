

/*
// 1��
// union find�� ����Ͽ� Kruskal�˰��� ����

#include<stdio.h>
#define MAX 100

typedef struct {
	int v1;    // ù��° ���
	int v2;    // �ι�° ���
	int distance;    // ��������ġ
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
	printf("��尳�� : ");
	scanf("%d", &numberOfVertex);
	printf("Edge���� : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		printf("���1, ���2, ����ġ : ");
		scanf("%d %d %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// ���� ����ġ �������� ����
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
		// ����Ŭ�� �߻����� ���� ���� ����
		if (!findParent(arr[i].v1, arr[i].v2))
		{
			unionParent(arr[i].v1, arr[i].v2);
			sum += arr[i].distance;
		}
	}
	printf("sum : %d\n", sum);  // ���� ����ġ�� ��
}
*/






/*
// 2�� - �߳���

// heap������ �̿��Ͽ� Kruskal�� �˰����� �����Ͽ� ���ô�.
// �ּ��� ���

// �迭 ��� �ּ��� ���� ���� ����ġ �����ؼ� kruskal����
// ������ �� �Ȱ��� (���� ����ġ��) �迭 ��� �� �Ἥ �����ϴ� �͸� �ٸ�
// �̰� �����ϰ� ������ �ڿ� ���� �� �� Ǯ�� ��


#include<stdio.h>
#define MAX 100

typedef struct {
	int v1;    // ù��° ���
	int v2;    // �ι�° ���
	int distance;    // ��������ġ
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


// �ּ��� - ��������ġ �������� ����
Edge heap_sort(int idx) {
	Edge root = arr[1];   // ��Ʈ ��� ���� 
	arr[1] = arr[idx]; // ���� ������ ��尡 ��Ʈ���� �̵�
	int end = idx - 1;  // ������ �ε���-1 = ���� �� �迭�� ����ִ� ��� �� ����(end)
	int level = end / 2;  // �Ʒ��� levelĭ��ŭ �̵�
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
		if (arr[idx * 2].distance < arr[idx * 2 + 1].distance) {  // �����ڽ��� �� ���� ���
			if (idx * 2 == end + 1) break;   
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}
		}
		else {   // �������ڽ��� �� ���� ���
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
	printf("��尳�� : ");
	scanf("%d", &numberOfVertex);
	printf("Edge���� : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 1;
	for (i = 0; i < numberOfEdge; i++) {
		printf("���1, ���2, ����ġ : ");
		scanf("%d %d %d", &e.v1, &e.v2, &e.distance);
		insert_heap(k, e);
		k++;
	}

	int sum = 0;
	for (i = 0; i < numberOfEdge; i++)
	{
		e = heap_sort(--k);
		// ����Ŭ�� �߻����� ���� ���� ����
		if (!findParent(e.v1, e.v2))
		{
			unionParent(e.v1, e.v2);
			sum += e.distance;
		}
	}
	printf("sum : %d\n", sum);  // ���� ����ġ�� ��
}
*/



/*
// 2�� - ���� ������ ���� ����Ʈ�� �ִ� �ڵ�

#include<stdio.h>
#define MAX_VERTICES 10

int parent[MAX_VERTICES];   // �θ� ���
int num[MAX_VERTICES];    // �� ������ ũ��

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

	s = i;    // ������ ��ǥ ����
	for (i = vertex; (p = parent[i]) >= 0; i = p)
		parent[i] = s;   // ������ ��� ���ҵ��� �θ� p�� ����
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
	int distance;  // ������ ����ġ
	int u;   // ���� 1
	int v;   // ���� 2
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


// Heap ���
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

// ����
void insertHeap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.distance < h->heap[i / 2].distance)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;   // ���ο� ��带 ����
}

// ����
element deleteHeap(HeapType* h)   
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].distance) > h->heap[child + 1].distance)
			child++;
		if (temp.distance <= h->heap[child].distance) break;
		// �Ѵܰ� �Ʒ��� �̵�
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
	int edge_accepted = 0;  // ������� ���õ� ������ ��
	HeapType h;   // �ּ� ��
	int uset, vset;   // ���� u�� ���� v�� ���� ��ȣ
	element e;    // �� ���

	init(&h);    // �� �ʱ�ȭ
	insertAllEdge(&h);   // ���� ������ ����
	printHeap(&h);
	printf("\n");
	setInit(n);   // ���� �ʱ�ȭ

	while (edge_accepted < (n - 1))  // ������ �� < (n-1)
	{
		e = deleteHeap(&h);    // �ּ� ������ ����

		uset = findParent(e.u);    // ���� u�� ���� ��ȣ
		vset = findParent(e.v);    // ���� v�� ���� ��ȣ

		if (uset != vset) {    // ���� ���� ������ �ٸ���
			printf("(%d,%d)  %d  \n", e.u, e.v, e.distance);
			edge_accepted++;
			unionParent(uset, vset);   // �ΰ��� ������ ��ģ��.
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
	kruskal(7);  // (�Է��ϰ��� �ϴ� �׷�����)��� ����=7
}
*/








// 12������ ����Ǯ��

/*
// 2��
// ���� �׷����� kruskal�˰����� �̿��Ͽ� �ִܰŸ��� ��θ� ����Ͽ� ���ô�

#include<stdio.h>
#define MAX 100

typedef struct {
	int v1;    // ù��° ���
	int v2;    // �ι�° ���
	int distance;    // ��������ġ
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
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		printf("����1, ����2, ����ġ : ");
		scanf("%d %d %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// ���� ����ġ �������� ����
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	printf("�ִܰŸ� ��� : ");
	for (i = 0; i < numberOfEdge; i++)
	{
		// ����Ŭ�� �߻����� ���� ���� ����
		if (!findParent(arr[i].v1, arr[i].v2))
		{
			unionParent(arr[i].v1, arr[i].v2);
			sum += arr[i].distance;
			printf("(%d  %d :  %d)  ", arr[i].v1, arr[i].v2, arr[i].distance);  // ������
		}
	}
	printf("\n�ִܰŸ�  : %d\n", sum);  // ���� ����ġ�� ��
}
*/





/*
// 3��
// Kruskal �˰����� �̿��Ͽ� �ּҺ�� ����Ʈ���� ���Ͽ� ���ô�

// 2���� �Ȱ��� �ڵ� ���
// ��, ���� �� ���ĺ����� ����

#include<stdio.h>
#include<string>
#define MAX 100

typedef struct {
	char v1;    // ù��° ���
	char v2;    // �ι�° ���
	int distance;    // ��������ġ
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
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		getchar();

		printf("����1, ����2, ����ġ : ");
		scanf("%c %c %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// ���� ����ġ �������� ����
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	printf("�ִܰŸ� ��� : ");
	for (i = 0; i < numberOfEdge; i++)
	{
		// ����Ŭ�� �߻����� ���� ���� ����
		if (!findParent(arr[i].v1 - 64, arr[i].v2 - 64))  // A�̸� 1, B�̸� 2..
		{
			unionParent(arr[i].v1 - 64, arr[i].v2 - 64);
			sum += arr[i].distance;
			printf("(%c  %c :  %d)  ", arr[i].v1, arr[i].v2, arr[i].distance);  // ������
		}
	}
	printf("\n�ִܰŸ�  : %d\n", sum);  // ���� ����ġ�� ��
}
*/




/*
// 4��
// ���� ���� �׷����� ���Ͽ� ����Į �˰����� �����Ͽ� �ּҺ�� ����Ʈ���� ���Ͽ� ���ô�.

// 3���� �Ȱ��� �ڵ� ���
#include<stdio.h>
#include<string>
#define MAX 100

typedef struct {
	char v1;    // ù��° ���
	char v2;    // �ι�° ���
	int distance;    // ��������ġ
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
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	printf("�������� : ");
	scanf("%d", &numberOfEdge);

	for (i = 1; i <= numberOfVertex; i++)
		parent[i] = i;

	k = 0;
	for (i = 0; i < numberOfEdge; i++) {
		getchar();

		printf("����1, ����2, ����ġ : ");
		scanf("%c %c %d", &e.v1, &e.v2, &e.distance);
		AddEdge(k, e);
		k++;
	}

	// ���� ����ġ �������� ����
	for (i = 0; i < numberOfEdge - 1; i++) {
		for (j = i + 1; j < numberOfEdge; j++)
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}

	int sum = 0;
	printf("�ִܰŸ� ��� : ");
	for (i = 0; i < numberOfEdge; i++)
	{
		// ����Ŭ�� �߻����� ���� ���� ����
		if (!findParent(arr[i].v1 - 64, arr[i].v2 - 64))  // A�̸� 1, B�̸� 2..
		{
			unionParent(arr[i].v1 - 64, arr[i].v2 - 64);
			sum += arr[i].distance;
			printf("(%c  %c :  %d)  ", arr[i].v1, arr[i].v2, arr[i].distance);  // ������
		}
	}
	printf("\n�ִܰŸ�  : %d\n", sum);  // ���� ����ġ�� ��
}
*/





/*
// 5��
// �л����� ���θ� ���� ȿ�������� �� �� �ֵ��� ������ ����� �ִ� �п����� ��Ʈ��ũ�� �����Ϸ��� �Ѵ�.
//- ��� �п����� ��Ʈ��ũ�� �����Ϸ��� �ʹ� ���� ����� �ʿ��ϱ� ������ �п����� �����ϴ� �����
//�ּҰ� �ǰ� �Ϸ��� �Ѵ�.
//- �п����� ����Ǿ� �ִ� �ٸ� �п��� ȸ���� ������ �� �ִ�. 
//- �Ʒ� �׸��� ���� �п� ���̸� �����ϱ� ���� ����� �־����� ��� �п��� �����ϱ� ���� �ּ���
//����� ���ϴ� ���α׷��� �ۼ��Ͽ� ���ô�.


//=== �Է�����
//ù�ٿ� �п��� �� N(3<= N <=100)�� �־�����. ��° �ٺ��� NxN�� ��ķ� 100,000������ ������ ��������
//���еǾ� �Էµȴ�.
//����� i j�� i�� �п����� j�� �п��� �����ϱ� ���� ����� ��Ÿ����.



#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
	int v;   // ù��° ����
	int e;   // �ι�° ����
	int distance;   // ��������ġ
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

	printf("\nmatrix ���\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (k = 0; k < numberOfVertex; k++)  
			printf("%4d", matrix[i][k]);  
		printf("\n");
	}
	printf("\n");


	// Edge�迭�� ���� ���� (matrix���� Edge������ ����)
	int idx = 0;
	for (i = 0; i < numberOfVertex - 1; i++) {
		for (k = i + 1; k < numberOfVertex; k++) {
			arr[idx].v = i;   
			arr[idx].e = k;
			arr[idx].distance = matrix[i][k];
			idx++;
		}
	}

	// Edge�迭 ��������ġ ���� �������� ����
	for (i = 0; i < idx - 1; i++) {
		for (j = i + 1; j < idx; j++) {
			if (arr[i].distance > arr[j].distance) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	//printf("\n���ĵ� ���� ���\n");
	//for (int i = 0; i < 20; i++)
	//	printf("%d %d : %d\n", arr[i].v, arr[i].e, arr[i].distance);

	// parent�� �ʱ�ȭ
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

	printf("�ּҺ�� : %d\n\n", sum);
}
*/



