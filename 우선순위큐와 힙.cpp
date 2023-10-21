

/*

// �켱����ť ���� - �迭
// �ִ��� ����  ( �ּ����� �����)
// ���� ���� Ʈ�� �ƴ�. (balance ���ߴ� �� ���߿� ���)
// ���� ���� �� ���� ���� Ʈ�� �ǰ� ���� ������ ���� ����Ʈ���� �ڵ������� �ڱⰡ ���� ����


#include<stdio.h>

// �迭 �� ���� ���Ե� �� ���� �Ž��� �ö󰡴� ����
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
// ����
void insert(int *arr, int idx) {
	int key;
	printf("������ Ű���� �Է��Ͻÿ� : ");
	scanf("%d", &key);
	arr[idx] = key;
	if (idx > 1) up(arr, idx);
}



// ����
void remove(int *arr, int idx) {
	arr[1] = arr[idx]; // ���� ������ ��尡 ��Ʈ���� �̵�
	int end = idx-1;  // ������ �ε���-1 = ���� �� �迭�� ����ִ� ��� �� ����(end)

	// �ǹ�, �� �Ʒ� ���̻� ������ ���� �� ��� ����??
	// end�� �� ��� ����
	//end=1 �Ʒ��� ���ʿ� ����
	// end=2 �Ʒ��� ��ĭ  end=3 �Ʒ��� ��ĭ
	// end=4 �Ʒ��� ��ĭ 
	//...
	// end=4,5,6,7 �Ʒ��� ��ĭ
	// end= 8,9,10,11,12,13,14,15  �Ʒ��� ��ĭ

	// end / 2 =0 2�� 0��(0)  �Ʒ��� 0ĭ
	// end / 2 < 2�� 1��(1) �Ʒ��� ��ĭ
	// end / 2 < 2�� 2��(2) �Ʒ��� ��ĭ
	// end / 2 < 2�� 3��(3) �Ʒ��� ��ĭ

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
		
		if (arr[idx * 2] > arr[idx * 2 + 1]) {  // �����ڽ��� ��Ŭ���
			if (idx * 2 == end + 1) break;   // �����ڽ��� �� ū�� �����ڽ��� �� ������ �ε�����(���� ������ �ε���) ��� �ٲ��� ����.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}
		
		}
		else {   // �������ڽ��� �� Ŭ ���
			if (idx * 2 + 1 == end + 1) {  // �������ڽ��� �� ū�� �������ڽ��� �� ������ �ε����� ��� �ٲ��� ����.
				if (arr[idx * 2] > tmp) {  // ���� �����ڽ��� ���κ��� ũ�ٸ� (�������ڽ��� �ƴ϶�)���� �ڽİ� �ٲ�.
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
	// �ڽ��� �ϳ��� �ִ� ���..?? (�ڽ� �ϳ��� ���� �ڱ���ġ = ��Ʈ����϶�)

}

int main()
{
	int n;
	int idx = 1;
	int heap[100];
	heap[0] = NULL;

	for (;;) {
		printf("\n1. ����  2. ���  3. ����  4. ����\n");
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
			remove(heap, --idx);  // �迭, ���� ������ �ε���
		}
		else { printf("����Ǿ����ϴ�.\n"); break;}
	}
}

*/




/*
// 13������ 4��
// ���̽�ũ�� ���� �ùķ��̼�


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TIME  60   // �� 60�е��� �ùķ��̼�
#define MAX 20   // ������ 20���� �ִ� - ��� �� 20���� �ִ�

typedef struct c {
	char name[20];  // ���̸�
	char ice_cream[20];   // ���̽�ũ�� ����
	int num;   // �ֹ��� ���̽�ũ�� ���� (3���� �ִ�)
	int total_price;   // ���̽�ũ�� �� ����   price * num
	int total_time;   // ���̽�ũ�� �����ð�   time * num
	int arrive_time;   // ���� ������ �ð�
}Customer;

struct icecream {
	char ice_cream_name[20];
	int price;
	int time;
};

char people_name_list[10][10] = { "abc", "aaa", "paul", "sara", "gildong", "manila","rosie","david","patrick","jacob" };
icecream flavor[3] = { {"ü��", 500, 2}, {"����", 700,3}, {"����", 900,5} };
// flavor[0] = ü�� 500�� 2��
// flavor[1] = ���� 700�� 3��
// flavor[2] = ���� 900�� 5��




// �迭 �� ���� ���Ե� �� ���� �Ž��� �ö󰡴� ���� - ���� ����� ������ �� �ε��� ��ȯ
int up(Customer *arr, int idx) {
	Customer tmp;
	while (idx > 1) {
		if (arr[idx / 2].total_price < arr[idx].total_price) {  // �� ���� ���� ����� �켱
			tmp = arr[idx];
			arr[idx] = arr[idx / 2];
			arr[idx / 2] = tmp;
			idx = idx / 2;
		}
		else break;
	}
	return idx;
}

// �ڽź��� ������ ��ΰų� ���� ���� �����ð��� �� ���ð��� ����.
int my_wait_time(Customer *arr, int myidx) {
	int sum = 0;
	for (int i = 1; i < myidx; i++) {
		if (arr[i].total_time > 0 && (arr[myidx].total_price <= arr[i].total_price)) {
			sum += arr[i].total_time;
		}
	}
	return sum;
}


// ����
void remove(Customer *arr, int idx, int t) {
	printf("%s���� �����ϼ̽��ϴ�.���� �ð� : %d��   �ȳ��� ���ʽÿ�\n\n", arr[1].name, t);
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
	Customer tmp;
	idx = 1;
	while (i < level) {
		tmp = arr[idx];

		if (arr[idx * 2].total_price > arr[idx * 2 + 1].total_price) {  // �����ڽ��� ��Ŭ���
			if (idx * 2 == end + 1) break;   // �����ڽ��� �� ū�� �����ڽ��� �� ������ �ε�����(���� ������ �ε���) ��� �ٲ��� ����.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}
		}
		else {   // �������ڽ��� �� Ŭ ���
			if (idx * 2 + 1 == end + 1) {  // �������ڽ��� �� ū�� �������ڽ��� �� ������ �ε����� ��� �ٲ��� ����.
				if (arr[idx * 2].total_price >= tmp.total_price) {  // ���� �����ڽ��� ���κ��� ũ�ٸ� (�������ڽ��� �ƴ϶�)���� �ڽİ� �ٲ�.
					arr[idx] = arr[idx * 2];       // ������ ���� �� ���� �� �մ��� ���� ������ �ϱ� ���� ���� ���� swap
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
	int wait_time = 0;   // ��� ������ ��� �ð��� ���� ( wait_time / ���� ����(total_customer) = ��� ��� �ð�)
	int total_customer = 0;   // ���ѽð� ���� ������ �� ����
	int wait;

	srand(time(NULL));
	for (int t = 0; t < TIME; t++) {
		if (idx > 1) {
			if (customer[1].total_time == 0) {  // ��������
				remove(customer, --idx, t);
			}
		}
		r = rand() % 10;
		if (r < 3) { // �� ����
			if (MAX <= idx) printf("�¼��� �� á���ϴ�.\n"); 
			else {
				r = rand() % 3;
				strcpy(tmp.ice_cream, flavor[r].ice_cream_name);
				q = rand() % 3+1;
				tmp.num = q;   // ���̽�ũ�� ���� ����
				tmp.total_price = q * flavor[r].price;  // �� ����
				tmp.total_time = q * flavor[r].time;   // �� �����ð�
				r = rand() % 10;
				strcpy(tmp.name, people_name_list[r]);  // �� �̸�
				tmp.arrive_time = t;   // ���� ������ �ð�


				printf("%s���� �����ϼ̽��ϴ�. ���� �ð� : %d ��\n", tmp.name, tmp.arrive_time);
				printf("== �ֹ� ���� ==\n");
				printf("���̽�ũ�� ���� : %s\n", tmp.ice_cream);
				printf("���̽�ũ�� ���� : %d\n", tmp.num);
				printf("�����Ͻ� �� �ݾ� : %d\n", tmp.total_price);
				printf("���̽�ũ�� ���� �ð� : %d\n", tmp.total_time);

				// ���� ����
				customer[idx++] = tmp;
				total_customer++;
				if (idx > 1) {
					wait = my_wait_time(customer, up(customer, idx-1));
				}
				else wait = 0;
				printf("������ ���� ��� �ð��� %d���Դϴ�.\n\n", wait);
				wait_time += wait;
			}
		}
		
		
		customer[1].total_time--;
	}

	printf("\n\n*** ������ �����Ǿ����ϴ� ***\n");
	printf("\n- �� %d ���� ������ �ֹ��� �޾ҽ��ϴ�.\n", total_customer);
	printf("- ������ ��� ��� �ð��� %d ���̾����ϴ�.\n\n\n", wait_time / total_customer);
}

*/



/*
// 4��
// ���̽�ũ�� ���� �ùķ��̼�
// ����Ʈ�� ���� �ִ°� �״�� �Է��غ��� ����

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
	int type;  // �̺�Ʈ�� ���� (ARRIVAL, ORDER, LEAVE)
	int key;  // �̺�Ʈ�� �Ͼ �ð�
	int number;  // ���� ����
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


// �ʱ�ȭ �Լ�
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

// ���� �Լ�
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) { // �θ� �� ũ�� swap
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;    // ���ο� ��带 ����
}
// ���� �Լ�
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	// ������ �� �ؿ� �ִ� �� ��Ʈ��尡 �Ǵϱ�(��Ʈ��忡�� �񱳸� �����ϴϱ�) 
	// ������ �� ó�� �񱳴���� 2,3���� ������ (1�� �ڽĳ�� = 2,3)
	// �׷��ϱ� child�� 2�� �ΰ� ++ �ϸ鼭 ���ϸ鼭 �������� ���� ( heap_size ���� ���� ������ )
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 0���� n������ ���� ���� ���� �Լ� (1~n)
int random(int n)
{
	return rand() % n + 1;
}
// �ڸ��� �����ϸ� �� �ڸ����� �������ŭ ���ҽ�Ų��.
int is_seat_available(int number)
{
	printf("%d���� �� ����\n", number);
	if (free_seats >= number) {
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("�ڸ��� ��� ����\n");
		return FALSE;
	}
}
// �ֹ��� ������ ������ ��Ÿ���� ������ ������Ų��.
void order(int scoops)
{
	printf("���̽�ũ�� %d�� �ֹ� ����\n", scoops);
	profit += 0.35 * scoops;
}
// ���� ������ ���ڸ����� ������Ų��.
void leave(int number)
{
	printf("%d���� ������ ����\n", number);
	free_seats += number;
}
// �̺�Ʈ�� ó���Ѵ�.
void process_event(HeapType *heap, element e)
{
	int i = 0;
	element new_event;

	printf("���� �ð�=%d\n", e.key);
	switch (e.type) {
	case ARRIVAL:
		// �ڸ��� �����ϸ� �ֹ� �̺�Ʈ�� �����.
		if (is_seat_available(e.number)) {
			new_event.type = ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number = e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// �������ŭ �ֹ��� �޴´�.
		for (i = 0; i < e.number; i++) {
			order(1 + random(3));
		}
		// ������ ������ �̺�Ʈ�� �����Ѵ�.
		new_event.type = LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number = e.number;
		insert_min_heap(heap, new_event);
		break;
	case LEAVE:
		// ���� ������ ���ڸ����� ������Ų��.
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
	// ó���� ��� �ʱ� �̺�Ʈ�� ������Ų��.
	srand((unsigned)time(NULL));
	while (t < 5) {
		t += random(6);
		event.type = ARRIVAL;
		event.key = t;
		event.number = 1 + random(4);
		insert_min_heap(&heap, event);
	}
	// �ùķ��̼��� �����Ѵ�.
	while (!is_empty(&heap)) {
		event = delete_min_heap(&heap);
		process_event(&heap, event);
	}
	printf("��ü �������� = %f�Դϴ�.\n", profit);
}
*/




/*
// ����Ǯ�� 17������

// 6��
// �켱���� ť���� find ������ �ϴ� �Լ� �ۼ�
// find(q)  : �켱������ ���� ���� ��Ҹ� ��ȯ�Ѵ�. 

// �ִ���

#include<stdio.h>

// �迭 �� ���� ���Ե� �� ���� �Ž��� �ö󰡴� ����
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
// ����
void insert(int *arr, int idx) {
	int key;
	printf("������ Ű���� �Է��Ͻÿ� : ");
	scanf("%d", &key);
	arr[idx] = key;
	if (idx > 1) up(arr, idx);
}

// ����
void remove(int *arr, int idx) {
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

		if (arr[idx * 2] > arr[idx * 2 + 1]) {  // �����ڽ��� ��Ŭ���
			if (idx * 2 == end + 1) break;   // �����ڽ��� �� ū�� �����ڽ��� �� ������ �ε�����(���� ������ �ε���) ��� �ٲ��� ����.
			else {
				arr[idx] = arr[idx * 2];
				arr[idx * 2] = tmp;
				idx = idx * 2;
			}

		}
		else {   // �������ڽ��� �� Ŭ ���
			if (idx * 2 + 1 == end + 1) {  // �������ڽ��� �� ū�� �������ڽ��� �� ������ �ε����� ��� �ٲ��� ����.
				if (arr[idx * 2] > tmp) {  // ���� �����ڽ��� ���κ��� ũ�ٸ� (�������ڽ��� �ƴ϶�)���� �ڽİ� �ٲ�.
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
		printf("1. ����  2. ����  3. ���  4. find()  5. ����\n");
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
			// find �Լ� ����
			printf("�켱���� ���� ���� ��� : %d \n", find(heap));
		}
		else { printf("����Ǿ����ϴ�.\n"); break; }
	}
}
*/

