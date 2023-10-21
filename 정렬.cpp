

/*
// ��������

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
#define SWAP(x,y,t)  ( t = x, x = y, y = t )   //  (��ũ�� �Լ�)

int list[MAX_SIZE];
int n;
void selection_sort(int list[], int n) {
	int i, k, min_idx, tmp;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (k = i+1; k < n; k++) {  // �ּҰ� Ž��
			if (list[k] < list[min_idx]) min_idx = k;
		}
		SWAP(list[i], list[min_idx], tmp);
	}
}

int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // ���� ���� �G ���
		list[i] = rand() % n;     // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	selection_sort(list, n);   // �������� ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
}
*/



/*
// ���� ����


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ( t = x, x = y, y = t )

int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n) {
	int i, k, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (k = i - 1; 0 <= k && list[k] > key; k--) 
			list[k + 1] = list[k];    // ���ڵ��� ������ �̵�
		list[k + 1] = key;
	}
}

int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)       // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	insertion_sort(list, n);    // �������� ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}

*/



/*
// �������� ȥ�ڼ� ¥���� ����Ʈ �ڵ�� ���ؼ� �ϼ��ϱ� - ����.

// ��������

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ( t = x, x = y, y = t )

int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n)
{
	int i, j, tmp;
	for (i = n-1; 0 < i; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) SWAP(list[j], list[j + 1], tmp);
		}
	}
	
}


int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)       // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	bubble_sort(list, n);    // �������� ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/




/*
// �� ����
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t)  ( t = x, x = y, y = t)

int list[MAX_SIZE];
int n;

// gap ��ŭ ������ ��ҵ��� ���� ����
// ������ ������ first���� last
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}

}


void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap >= 1; gap = gap / 2) {
		if (gap % 2 == 0) gap++;   // gap�� ¦���� ��� gap++ �ؼ� Ȧ���� ���� (gap�� ¦���� �ϳ��� ���� �� ����� ����)
		for(i=0;i<gap;i++)      // �κ� ����Ʈ�� ������ gap
			inc_insertion_sort(list,i, n-1, gap);
	}
}


int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)       // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	shell_sort(list, n);    // ������ ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
}

*/





/*

// �պ�����
// ������ �˻�ް� notion�� �ʱ�

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE];    // �߰� ������ �ʿ�

// i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
// j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(int list[], int left, int mid ,int right) {
	int i, k, j;
	i = left;
	j = mid + 1;
	k = left;

	//while (!(k > right)) {
	//	if(list[i++] > list[k++]) sorted[i] = 
	//}
	//for (i = left; i <= mid; i++) {
	//	for(k=mid+1; k<=right;k++)
	//}

	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// �����ִ� ���ڵ��� �ϰ� ����
	while (i <= mid) {
		sorted[k++] = list[i++];
	}
	while (j <= right) {
		sorted[k++] = list[j++];
	}

	// �迭 sorted�� list�� �纹��
	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
}



void merge_sort(int list[], int left, int right) {
	int mid = (left + right) / 2;
	if (!(left < right)) return;

	merge_sort(list, left, mid);
	merge_sort(list, mid + 1, right);
	merge(list, left, mid, right);

}



void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	merge_sort(list, 0, n - 1);   // �պ����� ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}

*/

/*
// �պ����� - ����Ʈ�� �ִ� �� �״��
// �պ�����

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE];    // �߰� ������ �ʿ�

// i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
// j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)    // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else        // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;    // ����Ʈ�� �յ� ����
		merge_sort(list, left, mid);   // �κ� ����Ʈ ����
		merge_sort(list, mid + 1, right);   // �κ� ����Ʈ ����
		merge(list, left, mid, right);   // �պ�
	}
}

void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)     // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	merge_sort(list, 0, n - 1);  // �պ����� ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/




/*

// ������
// ������ �˻�ް� notion�� �ʱ�


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define SWAP(x, y, t)  ( t = x, x = y, y = t)


int n;
int list[MAX_SIZE];

int partition(int list[], int left, int right)
{
	int tmp;
	int pivot = list[left];   // �Ǻ� ����
	int p = left;   // �Ǻ� �ε��� ����
	right++;

	while (left < right) {     // while������ �� ���������� ���� ���� ���ư�.
		// do while�� ���� ������ ���ǿ� �� �¾Ƶ� �ϴ� �ѹ��� ++, --�� �Ǳ� ������ 
		// �׳� while�� ���ϱ� ���ǿ� �� �����ϱ� left, right �Ѵ� ++,--�� ����������� �ȵǰ� ��� ���ѷ��� ��
		//printf("left : %d\n", left);
		//printf("right : %d\n", right);
		do {
			left++;
		} while (left <= right && list[left] < pivot);

		do {
			right--;
		} while (right >= p && list[right] > pivot);

		if (left < right) SWAP(list[left], list[right], tmp);  // ���õ� �� ���ڵ� ��ȯ
	}

	SWAP(list[p], list[right], tmp);   // �ε��� right�� ����Ű�� ���ڵ�� �Ǻ� ��ȯ

	return right;
}

void quick_sort(int list[], int left, int right)
{
	int q;
	if (left < right) {
		q = partition(list, left, right);

		quick_sort(list, left, q-1);       // ���� �κи���Ʈ�� ������
		quick_sort(list, q+1, right);      // ������ �κи���Ʈ�� ������
	}
}

void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	quick_sort(list, 0, n - 1);   // ������ ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/


/*
// ����Ʈ�� �����ִ� ������ �״��
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define SWAP(x, y, t)  ( t = x, x = y, y = t)

int n;
int list[MAX_SIZE];

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];    // �Ǻ� ����

	do {
		do
			low++;
		// ���� ����Ʈ���� �Ǻ����� ū ���ڵ� ����
		while (low <= right && list[low] < pivot);
		do
			high--;
		// ������ ����Ʈ���� �Ǻ����� ���� ���ڵ� ����
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);    // ���õ� �� ���ڵ� ��ȯ
	} while (low < high);    // �ε����� �������� �ʴ� �� �ݺ�

	SWAP(list[left], list[high], temp);   // �ε��� high�� ����Ű�� ���ڵ�� �Ǻ� ��ȯ
	return high;
}


void quick_sort(int list[], int left, int right)
{
	if (left < right) {   
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);      // ���� �κи���Ʈ�� ������
		quick_sort(list, q + 1, right);     // ������ �κи���Ʈ�� ������
	}
}


void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // ���� ���� �� ���
		list[i] = rand() % n;   // ���� �߻� ���� 0~n
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	quick_sort(list, 0, n - 1);   // ������ ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/





/*
// ������
// �ּ��� ���


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int sorted[MAX_SIZE];
int k = 0;

// �迭 �� ���� ���Ե� �� ���� �Ž��� �ö󰡴� ����
void up(int *arr, int idx) {
	int tmp;
	while (idx > 1) {
		if (arr[idx / 2] > arr[idx]) {
			tmp = arr[idx];
			arr[idx] = arr[idx / 2];
			arr[idx / 2] = tmp;
			idx = idx / 2;
		}
		else  break;
	}
}
// ����
void insert(int *arr, int idx, int rkey) {
	arr[idx] = rkey;
	if (idx > 1) up(arr, idx);
}

// ����
void remove(int *arr, int idx) {
	sorted[k++] = arr[1];   // ���� ����Ʈ�� ��Ʈ�� ���� - �����Ǵ� �� ����Ʈ�� ����

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
	int i = 0;
	int tmp;
	idx = 1;
	while (i < level) {
		tmp = arr[idx];

		if (arr[idx * 2] < arr[idx * 2 + 1]) {  // �����ڽ��� ���������
			if (idx * 2 == end + 1) break;   // �����ڽ��� �� ū�� �����ڽ��� �� ������ �ε�����(���� ������ �ε���) ��� �ٲ��� ����.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}

		}
		else {   // �������ڽ��� �� ���� ���
			if (idx * 2 + 1 == end + 1) {  // �������ڽ��� �� ū�� �������ڽ��� �� ������ �ε����� ��� �ٲ��� ����.
				if (arr[idx * 2] < tmp) {  // ���� �����ڽ��� ���κ��� �۴ٸ� (�������ڽ��� �ƴ϶�)���� �ڽİ� �ٲ�.
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
}

void heap_sort(int *arr, int idx)
{
	for(int i=0; i<MAX_SIZE; i++)
		remove(arr, --idx);
}


void main()
{
	int i, r;
	int n = MAX_SIZE;
	int idx = 1;
	int heap[MAX_SIZE];
	heap[0] = NULL;

	for (i = 0; i < n; i++) {     // ���� ���� �� ���
		r = rand() % n;
		insert(heap, idx, r);    // ���� �߻� ���� 0~n
		idx++;
	}
	printf("==������\n");
	for (i = 1; i < idx; i++)
		printf("%d ", heap[i]);

	printf("\n\n==������\n");
	heap_sort(heap, idx);   // ������ ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", sorted[i]);
	printf("\n\n");
}
*/







/*
// �������

// ������ ���ڵ尡 2�ڸ������ �����Ͽ� ���α׷���

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<malloc.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

typedef struct Data {
	int val;
	struct Data *next;
}Node;

Node * bucket[10];  // ���� �ڸ� ������ ���� ��Ŷ
Node * bucket2[10];  // ���� �ڸ� ������ ���� ��Ŷ (��Ŷ�� ���� �� �ϳ� �־�� ��)


// ��Ŷ NULL�� ���� �ʱ�ȭ
void init() {
	for (int i = 0; i < 10; i++) {
		bucket[i] = NULL;
		bucket2[i] = NULL;
	}
}

void radix_sort(int list[], int n) {
	int idx, i, k;
	int l;
	Node *tmp;
	Node *p;

	// ���� �ڸ� ����
	for (i = 0; i < n; i++) {
		idx = list[i] / 10;
		tmp = (Node *)malloc(sizeof(Node));
		tmp->val = list[i];   tmp->next = NULL;

		if (bucket[idx] == NULL) {
			bucket[idx] = tmp;
		}
		else {
			tmp->next = bucket[idx];
			bucket[idx] = tmp;
		}
	}
	// ���� �ڸ� ����
	for (i = 0, k = 0; k<10; k++) {
		if (bucket[k] == NULL) continue;
		else {
			p = bucket[k];
			do {
				tmp = (Node *)malloc(sizeof(Node));
				tmp->val = p->val;   tmp->next = NULL;

				idx = p->val % 10;
				if (bucket2[idx] == NULL) {
					bucket2[idx] = tmp;
				}
				else {
					tmp->next = bucket2[idx];
					bucket2[idx] = tmp;
				}
				p = p->next;

			} while (p != NULL);

			for (l = 0; l < 10; l++) {
				p = bucket2[l];
				while (p != NULL) {
					list[i++] = p->val;     // list�� ���ĵ� �� �纹��
					p = p->next;
					bucket2[l] = NULL;  // (= dequeue) list�� ���� �� �� �ڸ� ���
				}
			}
		}
	}
	
}


void main()
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	init();
	for (i = 0; i < n; i++)      // ���� ���� �� ���
		list[i] = rand() % 90 + 10;   // ���� �߻� ���� 10~99
	printf("==������\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==������\n");
	radix_sort(list, n);      // ������� ȣ��
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/





/*
// 18������ 9��
// ������ �����Ͽ� ���� ������ ����� ���ô�.

// ������ ���

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define SWAP(x, y, t) ( t = x, x = y, y = t )
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define MAX_SIZE 1000

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

element list[MAX_SIZE];
int n;


void insert() {
	element e;
	getchar();

	printf("�ܾ�: ");
	gets_s(e.word);
	printf("�ǹ�: ");
	gets_s(e.meaning);

	if (n < MAX_SIZE) list[n++] = e;   // ����
}
void print()
{
	for (int i = 0; i < n; i++)
		printf("%s  :  %s\n", list[i].word, list[i].meaning);
	printf("\n\n");
}


int partition(element list[], int left, int right)
{
	element pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];  // �Ǻ� ����

	do {
		do
			low++;
		while (strcmp(list[low].word, pivot.word) < 0);
		do
			high--;
		while (strcmp(list[high].word, pivot.word) > 0);
		if (low < high) SWAP(list[low], list[high], temp);    
	} while (low < high);    

	SWAP(list[left], list[high], temp);   
	return high;
}


void quick_sort(element list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);      // ���� �κи���Ʈ�� ������
		quick_sort(list, q + 1, right);     // ������ �κи���Ʈ�� ������
	}
}



void main()
{
	char a;
	n = 0;
	int flag = 0;
	for (;;) {
		printf("**********************\n");
		printf("i: �Է�\n");
		printf("s: ����\n");
		printf("p: ���\n");
		printf("q: ����\n");
		printf("**********************\n");
		printf("=> ");
		scanf("%c", &a);

		switch (a) {
		case 'i': insert(); break;
		case 's': quick_sort(list, 0, n - 1); break;
		case 'p': print(); break;
		}
		getchar();
		if (a == 'q') break;
	}
}
*/




// ����Ǯ�� 22������ 



// 2�� 




/*
// 3��
#include<stdio.h>
#define MAX_SIZE 100

void insertion_sort(int list[], int n) {
	int i, k, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (k = i - 1; 0 <= k && list[k] > key; k--)
			list[k + 1] = list[k];  
		list[k + 1] = key;
	}
	for (int i = 0; i < n; i++)
		printf("%d- ", list[i]);
	printf("\n");
}

void main()
{
	int val;
	int n = 0;
	int list[MAX_SIZE];
	for (;;) {
		printf("�Է� : ");
		scanf("%d", &val); 
		list[n++] = val;
		insertion_sort(list, n);
	}
}
*/



/*
// 4��
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x, y, t)  ( t = x, x = y, y = t)


int partition(int list[], int left, int right, int size)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];   

	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) 
			SWAP(list[low], list[high], temp);   // ���õ� �� ���ڵ� ��ȯ
		
		printf("low=%d, high=%d\n\n", low, high);
	} while (low < high);    

	SWAP(list[left], list[high], temp);  
	for (int i = 0; i < size; i++)
		printf("%4d ", list[i]);
	printf("\n\n");

	return high;
}


void quick_sort(int list[], int left, int right, int size)
{
	if (left < right) {
		int q = partition(list, left, right, size);
		quick_sort(list, left, q - 1, size);      
		quick_sort(list, q + 1, right, size);     
	}
}


void main()
{
	int n;
	int list[] = { 67, 90, 57, 25, 84, 32, 73, 54 };
	n = sizeof(list) / sizeof(list[0]);

	quick_sort(list, 0, n - 1, n);
}
*/

