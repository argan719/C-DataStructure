
/*

// Floyd �˰������� ����ġ ���� �׷����� �� �������� �ٸ� ��� ���������� �ִܰŸ��� ����Ͽ� ���ô�.

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define VERTICES 5    // ������ ��
#define INF 10000     // ���Ѵ� (������ ���� ���)


// ��Ʈ��ũ�� �������
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
	printf("%d �� ��ģ ����\n", k);
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

	// K�� ���İ��� ��� - �߰����
	for (k = 0; k < n; k++) {
		// i -> ��߳��
		for (i = 0; i < n; i++)
			// j <- �������
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
// Floyd �˰��� ����, ����ġ �Է¹޴� �ɷ� ����

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100   
#define INF 10000     // ���Ѵ� (������ ���� ���)

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
	matrix[b][a] = val;   // �� �κ� �ּ�ó���ϸ� ���⼺ �׷���
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
	printf("�������� : ");
	scanf("%d", &numberOfVertex);

	printf("�������� : ");
	scanf("%d", &numberOfEdge);
	init();

	printf("����1, ���� 2, ����ġ �Է� \n");

	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}
	// matrix �� ���� �Ϸ�

	floyd();
	print();
}

*/





/*

// 5������ 2��
// �׷����� �ִܰ�� ��� (��� �����ֿ� ���Ͽ� �ִܰ�� ���)

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100   
#define INF 10000     // ���Ѵ� (������ ���� ���)

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];
int next[MAX_VERTICES][MAX_VERTICES];   // ��� ����

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
	// i: ��߳��, j: ���� ���, k: ���� ���
	for (k = 0; k < numberOfVertex; k++) {
		for (i = 0; i < numberOfVertex; i++)
			for (j = 0; j < numberOfVertex; j++) {
				if (matrix[i][k] == INF || matrix[k][j] == INF) continue;

				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					// matrix�� ������Ʈ �� �� next�� ������Ʈ
					next[i][j] = next[i][k];   // next[i][j]���� i j�� �ִܰ�� �϶��� �߰���尡 ���������
				}
			}
				
	}
}

void AddEdge(int a, int b, int val)
{
	matrix[a][b] = val;
	matrix[b][a] = val;   
}

// ���� ���ŵ� matrix�� ���
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


// �� ���� ���� �ִܰ�� ���
void trace_path(int u, int v) {
	// ������� �������� ���ٸ� �����
	if (u != v) {
		// ���� u ���Ŀ� �湮�ؾ��� �������� u������Ʈ ��
		printf("-> %2d", next[u][v]);
		u = next[u][v];
		// ��͸� ���� �ݺ� (u�� �߰� ������ ���� ���� v�� �̵�) : u -> v
		trace_path(u, v);
	}
}

void main()
{
	int i, j;
	int a, b, val;
	printf("�������� : ");
	scanf("%d", &numberOfVertex);

	printf("�������� : ");
	scanf("%d", &numberOfEdge);
	init();

	printf("����1, ���� 2, ����ġ �Է� \n");

	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}
	// matrix �� ���� �Ϸ�

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

	// ����ڷκ��� �Է¹��� �� ���� ���� �ִܰ�� ���
	int start, end;
	printf("\n\n");
	printf("���� ~ ���� : ");
	scanf("%d %d", &start, &end);
	printf("%2d", start);
	trace_path(start, end);
}

*/






// 10������ ����Ǯ�� ����
// 1��


/*
// 2��

#include<stdio.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100   
#define INF 10000     // ���Ѵ� (������ ���� ���)

int numberOfVertex;
int numberOfEdge;

int matrix[MAX_VERTICES][MAX_VERTICES];
int next[MAX_VERTICES][MAX_VERTICES];   // ��� ����

int sum;  // �ִܰ�� ����ġ ��

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
	// i: ��߳��, j: ���� ���, k: ���� ���
	for (k = 0; k < numberOfVertex; k++) {
		for (i = 0; i < numberOfVertex; i++)
			for (j = 0; j < numberOfVertex; j++) {
				if (matrix[i][k] == INF || matrix[k][j] == INF) continue;

				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					// matrix�� ������Ʈ �� �� next�� ������Ʈ
					next[i][j] = next[i][k];   // next[i][j]���� i j�� �ִܰ�� �϶��� �߰���尡 ���������
				}
			}

	}
}

void AddEdge(int a, int b, int val)
{
	matrix[a][b] = val;
	//matrix[b][a] = val;
}


// �� ���� ���� �ִܰ�� ���
void trace_path(int u, int v) {
	// ������� �������� ���ٸ� �����
	if (u != v) {
		// ���� u ���Ŀ� �湮�ؾ��� �������� u������Ʈ ��
		sum += matrix[u][next[u][v]];   
		u = next[u][v];
		printf("-> %2d", u);
		// ��͸� ���� �ݺ� (u�� �߰� ������ ���� ���� v�� �̵�) : u -> v
		trace_path(u, v);
	}
}

void main()
{
	int i, j;
	int a, b, val;
	printf("�������� : ");
	scanf("%d", &numberOfVertex);

	printf("�������� : ");
	scanf("%d", &numberOfEdge);
	init();

	printf("����1, ���� 2, ����ġ �Է� \n");

	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d %d", &a, &b, &val);
		AddEdge(a, b, val);
	}
	// matrix �� ���� �Ϸ�

	floyd();

	printf("=== �� ���� ������ �ִܰ��\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			printf("[ %d->%d ] : ", i, j);
			printf("%2d", i);
			trace_path(i, j);
			printf("\n");
		}
		printf("\n");
	}

	// ����ڷκ��� �Է¹��� �� ���� ���� �ִܰ�� ���
	int start, end;
	printf("\n\n");
	printf("���� ~ ���� : ");
	scanf("%d %d", &start, &end);

	sum = 0; 
	printf("%2d", start);
	trace_path(start, end);
	printf("\n�Ÿ� : %d\n", sum);   
}
*/




/*
// 3��

//- �Է�
//ù° �ٿ� ������ ����
//��° �ٺ��� N���� �ٿ��� �׷����� ���� ���
//i��° ���� j��° ���ڰ� 1�� ��쿡�� i���� j�� ���� ������ �����Ѵٴ� ���̰�,
//0�� ���� ���ٴ� ��, i��° ���� i��° ���ڴ� �׻� 0�̴�.
//
//- ���
//���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1��, ������ 0���� ����Ѵ�.


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
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {   // floyd�� �̿��ϴ� ���̹Ƿ� �� �˰����� �����ϸ� �ȵ�.
					matrix[i][j] = matrix[i][k] + matrix[k][j];   // for�� 3�� ������ �ϴ� �κ��� �״�� �ΰ� ('�ε�ȣ�� �״��')
				}									
				  // �׷��ϱ� 0�� INF�� �������.
			}     // 0 = INF �ϱ� INF���� ������ ������ ���� -> ��� �ִ°���. INF���µ� �߰���� ��ġ�ϱ� INF ���� ���� ������ ���� => ��λ���ٴ� ��(�Ұ���(0)���� ��������(1))
		}   // ���� ���� INF���� ������ �߿��Ѱ���. INF ���� ���� ���� ���� ������ 1�� ��� (=> ��ΰ� �ִ°ű� ������)
	}   // INF�� 0���� ��� (=>��� ����)
	// ����ġ�� �����Ƿ�, 
	// ��� ��θ� �غ��� ������ ��Ʈ���� ���� ���� 0�̸� ��� ���°Ű� (�� ���Ҵµ��� ��Ʈ���� ���� 0�̸�)
}   // ��Ʈ���� ���� 0�� �ƴϰ� �ٸ� ������ ���ŵ����� (INF���� ������) ��ΰ� �ִ°��� 1, 1+1 ,1+1+1 ..


void main()
{
	printf("�������� : ");
	scanf("%d", &numberOfVertex);
	int i, j;
	char s[MAX_VERTICES];

	for (i = 0; i < numberOfVertex; i++) {
		scanf("%s", s);  // �� �پ� �Է¹ޱ�
		for (j = 0; j < numberOfVertex; j++) {
			if (s[j] - '0' == 0) matrix[i][j] = INF;   // 0�� INF - ��ξ����� ����.
			else matrix[i][j] = s[j] - '0';
		}
	}
	// ���� �� ��Ʈ���� ���
	printf("\n\n- �Է�\n");
	for (i = 0; i < numberOfVertex; i++) {
		for (j = 0; j < numberOfVertex; j++) {
			if (matrix[i][j] == INF) printf("%5d", 0);
			else printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}


	floyd();
	
	// ���� �� ��Ʈ���� ���
	printf("\n\n- ���\n");
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





// ����Ǯ�� 4��, 5�� ���� -  �� ���� �̾ Ǯ��

// 4�� - �̾ Ǯ��
#include<stdio.h>
#define MAX_VERTICES 100
#define INF 100000

int numberOfStudent;  // ��������
int numberOfEdge;   // ��������
int numberOfCompare;   // ��Ƚ��
int matrix[MAX_VERTICES][MAX_VERTICES];   // i, j�� ���� 1�̸� i < j  (i -> j : ���⼺�׷���)

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
	matrix[i][j] = 1;   // ���⼺ �׷��� (i�л��� Ű�� j�л��� Ű���� ���� ���� ����. i < j)
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
	printf("�л��� �� : ");
	scanf("%d", &numberOfStudent);
	printf("������ �� : ");
	scanf("%d", &numberOfEdge);
	init();

	int x, y;
	printf("Ű �Է� ( i < j ) : i j \n");
	for (i = 0; i < numberOfEdge; i++) {
		scanf("%d %d", &x, &y);
		AddEdge(x-1, y-1);
	}

	printf("\n���� Ƚ�� : ");
	scanf("%d", &numberOfCompare);

	compare_student arr[MAX_VERTICES];

	floyd();

	printf("A < B : \n");
	int sum = 0;
	for (i = 0; i < numberOfStudent; i++) {
		for (j = 0; j < numberOfStudent; j++) {
			if (matrix[j][i] < INF) {
				printf("%d %d\n", j+1, i+1);    // -> �̰� ���� �����ؾ��� - �ڽ��� Ű�� �� �� �ִ� �л� �� ���ϱ� ���ؼ�
				arr[sum].a = j;
				arr[sum].b = i;
				sum++;
			}
			if (sum == numberOfCompare) break;
		}
		if (sum == numberOfCompare) break;

	}

	 // ������ ������ �߸���.
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
			if (matrix[start][j] < INF) cnt++;     // ������ ū ��� (���� ���� ���)
			if (matrix[j][start] < INF) cnt++;     // ������ ���� ��� (���� ū ���)
		}*/

		// ��ü matrix���� �����°� �ƴ϶� arr�ȿ��� ������ ã�ƾ� �ϴ°���.
		for (j = 0; j < numberOfCompare; j++) {
			if(matrix[arr[j].a][])
		}


		if (cnt == numberOfStudent - 1) {
			tot++;  // ������ ���� �л� �� + ������ ū �л� �� = (��ü�л��� - 1)   => �ڽ��� Ű�� ���°���� �� �� ����
			printf("\n�� �� �ִ� �л� ��ȣ : %d\n", start + 1);
		}
	}

	printf("\n�ڽ��� Ű�� �� �� �ִ� �л� �� : %d\n\n", tot);

}