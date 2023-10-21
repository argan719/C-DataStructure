

/*

// 우선순위큐 구현 - 배열
// 최대힙 구현  ( 최소힙도 만들것)
// 완전 이진 트리 아님. (balance 맞추는 건 나중에 배움)
// 값을 넣을 때 완전 이진 트리 되게 넣지 않으면 완전 이진트리로 자동적으로 자기가 되지 않음


#include<stdio.h>

// 배열 맨 끝에 삽입된 후 위로 거슬러 올라가는 과정
void up(int *arr, int idx) {
	int tmp;
	while (idx>1) {
		if(arr[idx/2] < arr[idx]) {
			tmp = arr[idx];
			arr[idx] = arr[idx / 2];
			arr[idx / 2] = tmp;
			idx = idx / 2;
		}
		else  break;
	}
}
// 삽입
void insert(int *arr, int idx) {
	int key;
	printf("삽입할 키값을 입력하시오 : ");
	scanf("%d", &key);
	arr[idx] = key;
	if (idx > 1) up(arr, idx);
}



// 삭제
void remove(int *arr, int idx) {
	arr[1] = arr[idx]; // 가장 마지막 노드가 루트노드로 이동
	int end = idx-1;  // 마지막 인덱스-1 = 삭제 후 배열에 들어있는 노드 총 개수(end)

	// 맨밑, 맨 아래 더이상 갈데가 없는 걸 어떻게 알지??
	// end가 총 노드 개수
	//end=1 아래로 갈필요 없음
	// end=2 아래로 한칸  end=3 아래로 한칸
	// end=4 아래로 두칸 
	//...
	// end=4,5,6,7 아래로 두칸
	// end= 8,9,10,11,12,13,14,15  아래로 세칸

	// end / 2 =0 2의 0승(0)  아래로 0칸
	// end / 2 < 2의 1승(1) 아래로 한칸
	// end / 2 < 2의 2승(2) 아래로 두칸
	// end / 2 < 2의 3승(3) 아래로 세칸

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
		
		if (arr[idx * 2] > arr[idx * 2 + 1]) {  // 왼쪽자식이 더클경우
			if (idx * 2 == end + 1) break;   // 왼쪽자식이 더 큰데 왼쪽자식이 맨 마지막 인덱스인(값이 없어질 인덱스) 경우 바꾸지 않음.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}
		
		}
		else {   // 오른쪽자식이 더 클 경우
			if (idx * 2 + 1 == end + 1) {  // 오른쪽자식이 더 큰데 오른쪽자식이 맨 마지막 인덱스인 경우 바꾸지 않음.
				if (arr[idx * 2] > tmp) {  // 만약 왼쪽자식이 본인보다 크다면 (오른쪽자식이 아니라)왼쪽 자식과 바꿈.
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
	// 자식이 하나만 있는 경우..?? (자식 하나가 원래 자기위치 = 루트노드일때)

}

int main()
{
	int n;
	int idx = 1;
	int heap[100];
	heap[0] = NULL;

	for (;;) {
		printf("\n1. 삽입  2. 출력  3. 삭제  4. 종료\n");
		scanf("%d", &n);

		if (n == 1) {
			insert(heap, idx);
			idx++;
		}
		else if (n == 2) {
			printf("\n===============================\n");
			for (int i = 1; i < idx; i++)
				printf("%d ", heap[i]);
			printf("\n===============================\n");

		}
		else if (n == 3) {
			remove(heap, --idx);  // 배열, 가장 마지막 인덱스
		}
		else { printf("종료되었습니다.\n"); break;}
	}
}

*/




/*
// 13페이지 4번
// 아이스크림 가게 시뮬레이션


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TIME  60   // 총 60분동안 시뮬레이션
#define MAX 20   // 힙에는 20명이 최대 - 대기 고객 20명이 최대

typedef struct c {
	char name[20];  // 고객이름
	char ice_cream[20];   // 아이스크림 종류
	int num;   // 주문한 아이스크림 개수 (3개가 최대)
	int total_price;   // 아이스크림 총 가격   price * num
	int total_time;   // 아이스크림 제조시간   time * num
	int arrive_time;   // 고객이 도착한 시간
}Customer;

struct icecream {
	char ice_cream_name[20];
	int price;
	int time;
};

char people_name_list[10][10] = { "abc", "aaa", "paul", "sara", "gildong", "manila","rosie","david","patrick","jacob" };
icecream flavor[3] = { {"체리", 500, 2}, {"망고", 700,3}, {"베리", 900,5} };
// flavor[0] = 체리 500원 2분
// flavor[1] = 망고 700원 3분
// flavor[2] = 베리 900원 5분




// 배열 맨 끝에 삽입된 후 위로 거슬러 올라가는 과정 - 최종 정비된 상태의 내 인덱스 반환
int up(Customer *arr, int idx) {
	Customer tmp;
	while (idx > 1) {
		if (arr[idx / 2].total_price < arr[idx].total_price) {  // 총 가격 많은 순대로 우선
			tmp = arr[idx];
			arr[idx] = arr[idx / 2];
			arr[idx / 2] = tmp;
			idx = idx / 2;
		}
		else break;
	}
	return idx;
}

// 자신보다 가격이 비싸거나 같은 고객의 제조시간만 내 대기시간에 더함.
int my_wait_time(Customer *arr, int myidx) {
	int sum = 0;
	for (int i = 1; i < myidx; i++) {
		if (arr[i].total_time > 0 && (arr[myidx].total_price <= arr[i].total_price)) {
			sum += arr[i].total_time;
		}
	}
	return sum;
}


// 삭제
void remove(Customer *arr, int idx, int t) {
	printf("%s님이 퇴장하셨습니다.현재 시각 : %d분   안녕히 가십시오\n\n", arr[1].name, t);
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
	Customer tmp;
	idx = 1;
	while (i < level) {
		tmp = arr[idx];

		if (arr[idx * 2].total_price > arr[idx * 2 + 1].total_price) {  // 왼쪽자식이 더클경우
			if (idx * 2 == end + 1) break;   // 왼쪽자식이 더 큰데 왼쪽자식이 맨 마지막 인덱스인(값이 없어질 인덱스) 경우 바꾸지 않음.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}
		}
		else {   // 오른쪽자식이 더 클 경우
			if (idx * 2 + 1 == end + 1) {  // 오른쪽자식이 더 큰데 오른쪽자식이 맨 마지막 인덱스인 경우 바꾸지 않음.
				if (arr[idx * 2].total_price >= tmp.total_price) {  // 만약 왼쪽자식이 본인보다 크다면 (오른쪽자식이 아니라)왼쪽 자식과 바꿈.
					arr[idx] = arr[idx * 2];       // 가격이 같을 때 먼저 온 손님이 먼저 나가게 하기 위헤 같을 때도 swap
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


int main()
{
	int r, q;
	Customer customer[MAX];
	Customer tmp;
	int idx = 1;
	int wait_time = 0;   // 모든 고객들의 대기 시간의 총합 ( wait_time / 들어온 고객수(total_customer) = 평균 대기 시간)
	int total_customer = 0;   // 제한시간 동안 입장한 총 고객수
	int wait;

	srand(time(NULL));
	for (int t = 0; t < TIME; t++) {
		if (idx > 1) {
			if (customer[1].total_time == 0) {  // 삭제진행
				remove(customer, --idx, t);
			}
		}
		r = rand() % 10;
		if (r < 3) { // 고객 입장
			if (MAX <= idx) printf("좌석이 다 찼습니다.\n"); 
			else {
				r = rand() % 3;
				strcpy(tmp.ice_cream, flavor[r].ice_cream_name);
				q = rand() % 3+1;
				tmp.num = q;   // 아이스크림 구매 개수
				tmp.total_price = q * flavor[r].price;  // 총 가격
				tmp.total_time = q * flavor[r].time;   // 총 제조시간
				r = rand() % 10;
				strcpy(tmp.name, people_name_list[r]);  // 고객 이름
				tmp.arrive_time = t;   // 고객이 도착한 시간


				printf("%s님이 입장하셨습니다. 도착 시간 : %d 분\n", tmp.name, tmp.arrive_time);
				printf("== 주문 내역 ==\n");
				printf("아이스크림 종류 : %s\n", tmp.ice_cream);
				printf("아이스크림 개수 : %d\n", tmp.num);
				printf("지불하실 총 금액 : %d\n", tmp.total_price);
				printf("아이스크림 제조 시간 : %d\n", tmp.total_time);

				// 힙에 삽입
				customer[idx++] = tmp;
				total_customer++;
				if (idx > 1) {
					wait = my_wait_time(customer, up(customer, idx-1));
				}
				else wait = 0;
				printf("고객님의 예상 대기 시간은 %d분입니다.\n\n", wait);
				wait_time += wait;
			}
		}
		
		
		customer[1].total_time--;
	}

	printf("\n\n*** 영업이 마감되었습니다 ***\n");
	printf("\n- 총 %d 명의 고객들의 주문을 받았습니다.\n", total_customer);
	printf("- 고객들의 평균 대기 시간은 %d 분이었습니다.\n\n\n", wait_time / total_customer);
}

*/



/*
// 4번
// 아이스크림 가게 시뮬레이션
// 프린트에 나와 있는거 그대로 입력해보고 공부

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3

int free_seats = 10;
double profit = 0.0;

#define MAX_ELEMENT 100
typedef struct {
	int type;  // 이벤트의 종류 (ARRIVAL, ORDER, LEAVE)
	int key;  // 이벤트가 일어난 시각
	int number;  // 고객의 숫자
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


// 초기화 함수
void init(HeapType *h)
{
	h->heap_size = 0;
}

int is_empty(HeapType *h)
{
	if (h->heap_size == 0)
		return TRUE;
	else
		return FALSE;
}

// 삽입 함수
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) { // 부모가 더 크면 swap
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;    // 새로운 노드를 삽입
}
// 삭제 함수
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	// 삭제시 맨 밑에 있던 게 루트노드가 되니까(루트노드에서 비교를 시작하니까) 
	// 무조건 맨 처음 비교대상은 2,3으로 시작함 (1의 자식노드 = 2,3)
	// 그러니까 child값 2로 두고 ++ 하면서 비교하면서 내려가는 거임 ( heap_size 넘지 않을 때까지 )
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 0에서 n사이의 정수 난수 생성 함수 (1~n)
int random(int n)
{
	return rand() % n + 1;
}
// 자리가 가능하면 빈 자리수를 사람수만큼 감소시킨다.
int is_seat_available(int number)
{
	printf("%d명의 고객 도착\n", number);
	if (free_seats >= number) {
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("자리가 없어서 떠남\n");
		return FALSE;
	}
}
// 주문을 받으면 순익을 나타내는 변수를 증가시킨다.
void order(int scoops)
{
	printf("아이스크림 %d개 주문 받음\n", scoops);
	profit += 0.35 * scoops;
}
// 고객이 떠나면 빈자리수를 증가시킨다.
void leave(int number)
{
	printf("%d명이 매장을 떠남\n", number);
	free_seats += number;
}
// 이벤트를 처리한다.
void process_event(HeapType *heap, element e)
{
	int i = 0;
	element new_event;

	printf("현재 시간=%d\n", e.key);
	switch (e.type) {
	case ARRIVAL:
		// 자리가 가능하면 주문 이벤트를 만든다.
		if (is_seat_available(e.number)) {
			new_event.type = ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number = e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// 사람수만큼 주문을 받는다.
		for (i = 0; i < e.number; i++) {
			order(1 + random(3));
		}
		// 매장을 떠나는 이벤트를 생성한다.
		new_event.type = LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number = e.number;
		insert_min_heap(heap, new_event);
		break;
	case LEAVE:
		// 고객이 떠나면 빈자리수를 증가시킨다.
		leave(e.number);
		break;
	}

}

void main()
{
	element event;
	HeapType heap;
	unsigned int t = 0;
	init(&heap);
	// 처음에 몇개의 초기 이벤트를 생성시킨다.
	srand((unsigned)time(NULL));
	while (t < 5) {
		t += random(6);
		event.type = ARRIVAL;
		event.key = t;
		event.number = 1 + random(4);
		insert_min_heap(&heap, event);
	}
	// 시뮬레이션을 수행한다.
	while (!is_empty(&heap)) {
		event = delete_min_heap(&heap);
		process_event(&heap, event);
	}
	printf("전체 순이익은 = %f입니다.\n", profit);
}
*/




/*
// 문제풀이 17페이지

// 6번
// 우선순위 큐에서 find 연산을 하는 함수 작성
// find(q)  : 우선순위가 가장 높은 요소를 반환한다. 

// 최대힙

#include<stdio.h>

// 배열 맨 끝에 삽입된 후 위로 거슬러 올라가는 과정
void up(int *arr, int idx) {
	int tmp;
	while (idx > 1) {
		if (arr[idx / 2] < arr[idx]) {
			tmp = arr[idx];
			arr[idx] = arr[idx / 2];
			arr[idx / 2] = tmp;
			idx = idx / 2;
		}
		else  break;
	}
}
// 삽입
void insert(int *arr, int idx) {
	int key;
	printf("삽입할 키값을 입력하시오 : ");
	scanf("%d", &key);
	arr[idx] = key;
	if (idx > 1) up(arr, idx);
}

// 삭제
void remove(int *arr, int idx) {
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

		if (arr[idx * 2] > arr[idx * 2 + 1]) {  // 왼쪽자식이 더클경우
			if (idx * 2 == end + 1) break;   // 왼쪽자식이 더 큰데 왼쪽자식이 맨 마지막 인덱스인(값이 없어질 인덱스) 경우 바꾸지 않음.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}

		}
		else {   // 오른쪽자식이 더 클 경우
			if (idx * 2 + 1 == end + 1) {  // 오른쪽자식이 더 큰데 오른쪽자식이 맨 마지막 인덱스인 경우 바꾸지 않음.
				if (arr[idx * 2] > tmp) {  // 만약 왼쪽자식이 본인보다 크다면 (오른쪽자식이 아니라)왼쪽 자식과 바꿈.
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


// find 
int find(int *arr) {
	return arr[1];
}

int main()
{
	int n;
	int idx = 1;
	int heap[100];
	heap[0] = NULL;

	for (;;) {
		printf("1. 삽입  2. 삭제  3. 출력  4. find()  5. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			insert(heap, idx);
			idx++;
		}
		else if (n == 2) {
			remove(heap, --idx);
		}
		else if (n == 3) {
			printf("\n===============================\n");
			for (int i = 1; i < idx; i++)
				printf("%d ", heap[i]);
			printf("\n===============================\n");
		}
		else if (n == 4) {
			// find 함수 구현
			printf("우선순위 가장 높은 요소 : %d \n", find(heap));
		}
		else { printf("종료되었습니다.\n"); break; }
	}
}
*/

