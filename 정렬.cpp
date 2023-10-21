

/*
// 선택정렬

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
#define SWAP(x,y,t)  ( t = x, x = y, y = t )   //  (매크로 함수)

int list[MAX_SIZE];
int n;
void selection_sort(int list[], int n) {
	int i, k, min_idx, tmp;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (k = i+1; k < n; k++) {  // 최소값 탐색
			if (list[k] < list[min_idx]) min_idx = k;
		}
		SWAP(list[i], list[min_idx], tmp);
	}
}

int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // 난수 생성 밎 출력
		list[i] = rand() % n;     // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	selection_sort(list, n);   // 선택정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
}
*/



/*
// 삽입 정렬


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
			list[k + 1] = list[k];    // 레코드의 오른쪽 이동
		list[k + 1] = key;
	}
}

int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)       // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	insertion_sort(list, n);    // 삽입정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}

*/



/*
// 버블정렬 혼자서 짜보고 프린트 코드랑 비교해서 완성하기 - 했음.

// 버블정렬

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
	for (i = 0; i < n; i++)       // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	bubble_sort(list, n);    // 버블정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/




/*
// 셸 정렬
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t)  ( t = x, x = y, y = t)

int list[MAX_SIZE];
int n;

// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
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
		if (gap % 2 == 0) gap++;   // gap이 짝수일 경우 gap++ 해서 홀수로 만듦 (gap이 짝수면 하나가 남는 게 생기기 때문)
		for(i=0;i<gap;i++)      // 부분 리스트의 개수는 gap
			inc_insertion_sort(list,i, n-1, gap);
	}
}


int main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)       // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	shell_sort(list, n);    // 셸정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
}

*/





/*

// 합병정렬
// 쌤한테 검사받고 notion에 필기

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE];    // 추가 공간이 필요

// i는 정렬된 왼쪽 리스트에 대한 인덱스
// j는 정렬된 오른쪽 리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스
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

	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남아있는 레코드의 일괄 복사
	while (i <= mid) {
		sorted[k++] = list[i++];
	}
	while (j <= right) {
		sorted[k++] = list[j++];
	}

	// 배열 sorted를 list로 재복사
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
	for (i = 0; i < n; i++)      // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	merge_sort(list, 0, n - 1);   // 합병정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}

*/

/*
// 합병정렬 - 프린트에 있는 거 그대로
// 합병정렬

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int n;

int sorted[MAX_SIZE];    // 추가 공간이 필요

// i는 정렬된 왼쪽리스트에 대한 인덱스
// j는 정렬된 오른쪽리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)    // 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else        // 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// 배열 sorted[]의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;    // 리스트의 균등 분할
		merge_sort(list, left, mid);   // 부분 리스트 정렬
		merge_sort(list, mid + 1, right);   // 부분 리스트 정렬
		merge(list, left, mid, right);   // 합병
	}
}

void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)     // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	merge_sort(list, 0, n - 1);  // 합병정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/




/*

// 퀵정렬
// 쌤한테 검사받고 notion에 필기


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define SWAP(x, y, t)  ( t = x, x = y, y = t)


int n;
int list[MAX_SIZE];

int partition(int list[], int left, int right)
{
	int tmp;
	int pivot = list[left];   // 피봇 설정
	int p = left;   // 피봇 인덱스 저장
	right++;

	while (left < right) {     // while문에서 못 빠져나오고 무한 루프 돌아감.
		// do while을 쓰는 이유가 조건에 안 맞아도 일단 한번은 ++, --가 되기 때문에 
		// 그냥 while문 쓰니까 조건에 안 맞으니까 left, right 둘다 ++,--가 어느순간부터 안되고 계속 무한루프 돔
		//printf("left : %d\n", left);
		//printf("right : %d\n", right);
		do {
			left++;
		} while (left <= right && list[left] < pivot);

		do {
			right--;
		} while (right >= p && list[right] > pivot);

		if (left < right) SWAP(list[left], list[right], tmp);  // 선택된 두 레코드 교환
	}

	SWAP(list[p], list[right], tmp);   // 인덱스 right이 가리키는 레코드와 피봇 교환

	return right;
}

void quick_sort(int list[], int left, int right)
{
	int q;
	if (left < right) {
		q = partition(list, left, right);

		quick_sort(list, left, q-1);       // 왼쪽 부분리스트를 퀵정렬
		quick_sort(list, q+1, right);      // 오른쪽 부분리스트를 퀵정렬
	}
}

void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	quick_sort(list, 0, n - 1);   // 퀵정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/


/*
// 프린트에 나와있는 퀵정렬 그대로
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
	pivot = list[left];    // 피봇 설정

	do {
		do
			low++;
		// 왼쪽 리스트에서 피봇보다 큰 레코드 선택
		while (low <= right && list[low] < pivot);
		do
			high--;
		// 오른쪽 리스트에서 피봇보다 작은 레코드 선택
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);    // 선택된 두 레코드 교환
	} while (low < high);    // 인덱스가 엇갈리지 않는 한 반복

	SWAP(list[left], list[high], temp);   // 인덱스 high가 가리키는 레코드와 피봇 교환
	return high;
}


void quick_sort(int list[], int left, int right)
{
	if (left < right) {   
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);      // 왼쪽 부분리스트를 퀵정렬
		quick_sort(list, q + 1, right);     // 오른쪽 부분리스트를 퀵정렬
	}
}


void main()
{
	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)      // 난수 생성 및 출력
		list[i] = rand() % n;   // 난수 발생 범위 0~n
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	quick_sort(list, 0, n - 1);   // 퀵정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/





/*
// 힙정렬
// 최소힙 사용


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int sorted[MAX_SIZE];
int k = 0;

// 배열 맨 끝에 삽입된 후 위로 거슬러 올라가는 과정
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
// 삽입
void insert(int *arr, int idx, int rkey) {
	arr[idx] = rkey;
	if (idx > 1) up(arr, idx);
}

// 삭제
void remove(int *arr, int idx) {
	sorted[k++] = arr[1];   // 정렬 리스트에 루트값 삽입 - 삭제되는 값 리스트에 저장

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
	int i = 0;
	int tmp;
	idx = 1;
	while (i < level) {
		tmp = arr[idx];

		if (arr[idx * 2] < arr[idx * 2 + 1]) {  // 왼쪽자식이 더작을경우
			if (idx * 2 == end + 1) break;   // 왼쪽자식이 더 큰데 왼쪽자식이 맨 마지막 인덱스인(값이 없어질 인덱스) 경우 바꾸지 않음.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}

		}
		else {   // 오른쪽자식이 더 작을 경우
			if (idx * 2 + 1 == end + 1) {  // 오른쪽자식이 더 큰데 오른쪽자식이 맨 마지막 인덱스인 경우 바꾸지 않음.
				if (arr[idx * 2] < tmp) {  // 만약 왼쪽자식이 본인보다 작다면 (오른쪽자식이 아니라)왼쪽 자식과 바꿈.
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

	for (i = 0; i < n; i++) {     // 난수 생성 및 출력
		r = rand() % n;
		insert(heap, idx, r);    // 난수 발생 범위 0~n
		idx++;
	}
	printf("==정렬전\n");
	for (i = 1; i < idx; i++)
		printf("%d ", heap[i]);

	printf("\n\n==정렬후\n");
	heap_sort(heap, idx);   // 힙정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", sorted[i]);
	printf("\n\n");
}
*/







/*
// 기수정렬

// 정렬할 레코드가 2자릿수라는 전제하에 프로그래밍

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

Node * bucket[10];  // 십의 자리 정렬을 위한 버킷
Node * bucket2[10];  // 일의 자리 정렬을 위한 버킷 (버킷이 따로 또 하나 있어야 함)


// 버킷 NULL로 전부 초기화
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

	// 십의 자리 정렬
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
	// 일의 자리 정렬
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
					list[i++] = p->val;     // list에 정렬된 값 재복사
					p = p->next;
					bucket2[l] = NULL;  // (= dequeue) list에 복사 뒤 그 자리 비움
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
	for (i = 0; i < n; i++)      // 난수 생성 및 출력
		list[i] = rand() % 90 + 10;   // 난수 발생 범위 10~99
	printf("==정렬전\n");
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);

	printf("\n\n==정렬후\n");
	radix_sort(list, n);      // 기수정렬 호출
	for (i = 0; i < n; i++)
		printf("%4d", list[i]);
	printf("\n\n");
}
*/





/*
// 18페이지 9번
// 정렬을 응용하여 영어 사전을 만들어 봅시다.

// 퀵정렬 사용

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

	printf("단어: ");
	gets_s(e.word);
	printf("의미: ");
	gets_s(e.meaning);

	if (n < MAX_SIZE) list[n++] = e;   // 삽입
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
	pivot = list[left];  // 피봇 설정

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
		quick_sort(list, left, q - 1);      // 왼쪽 부분리스트를 퀵정렬
		quick_sort(list, q + 1, right);     // 오른쪽 부분리스트를 퀵정렬
	}
}



void main()
{
	char a;
	n = 0;
	int flag = 0;
	for (;;) {
		printf("**********************\n");
		printf("i: 입력\n");
		printf("s: 정렬\n");
		printf("p: 출력\n");
		printf("q: 종료\n");
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




// 문제풀이 22페이지 



// 2번 




/*
// 3번
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
		printf("입력 : ");
		scanf("%d", &val); 
		list[n++] = val;
		insertion_sort(list, n);
	}
}
*/



/*
// 4번
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
			SWAP(list[low], list[high], temp);   // 선택된 두 레코드 교환
		
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

