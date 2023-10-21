
/*
// CircularQueue
// === main.cpp

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CircularQueue.h"

void main()
{
	QueueType q;
	init(&q);
	int cho, num;
	printf("front=%d  rear=%d\n", q.front, q.rear);

	while (1)
	{
		printf("1.enqueue  2.dequeue  3.종료");
		scanf("%d", &cho);

		if (cho == 1) {
			printf("정수입력 :");
			scanf("%d", &num);
			enqueue(&q, num);
			printf("front=%d  rear=%d\n", q.front, q.rear);
		}
		if (cho == 2) {
			printf("dequeue()=%d\n", dequeue(&q));
			printf("front=%d  rear=%d\n", q.front, q.rear);
		}
		if (cho == 3) break;
	}

}

*/





/*
// 12페이지 1번

#include<stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"

void main()
{
	QueueType q;
	init(&q);
	int cho, num;
	printf("front=%d  rear=%d\n", q.front, q.rear);

	while (1)
	{
		printf("1.enqueue  2.dequeue  3.큐의개수  4.종료");
		scanf("%d", &cho);

		if (cho == 1) {
			printf("정수입력 :");
			scanf("%d", &num);
			enqueue(&q, num);
			printf("front=%d  rear=%d\n", q.front, q.rear);
		}
		if (cho == 2) {
			printf("dequeue()=%d\n", dequeue(&q));
			printf("front=%d  rear=%d\n", q.front, q.rear);
		}
		if (cho == 3) printf("큐의 개수 : %d\n", get_count(&q));

		if (cho == 4) break;
	}

}
*/






/*
// 12페이지 2번
// 두 개의 스택을 사용해서 선형큐 구현

#include<stdio.h>
#include<stdlib.h>
#include "ArrayStack.h"



void main()
{
	StackType s;
	StackType s2;

	init(&s);
	init(&s2);


	int cho, num;
	while (1)
	{
		printf("1.enqueue  2.dequeue  3.종료");
		scanf("%d", &cho);

		if (cho == 1) {
			printf("정수입력 :");
			scanf("%d", &num);
			push(&s, num);
			
		}
		if (cho == 2) {

			if (is_empty(&s2))
			{
				while (!is_empty(&s))
				{
					int item = pop(&s);
					push(&s2, item);
				}	
			}
			printf("dequeue() : %d\n", pop(&s2));

		}
		if (cho == 3) break;

	}

	
}

*/







/*
// 7페이지 3번
// 은행서비스 시뮬레이션 프로그램

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "CircularQueue.h"


// 시뮬레이션에 필요한 여러가지 상태 변수
int duration = 10;
double arrival_prob = 0.7;
int max_serv_time = 5;
int clock;


// 시뮬레이션의 결과
int customers;					// 전체 고객수
int served_customers;		// 서비스 받은 고객수
int waited_time;		// 고객들이 기다린 시간



// 엄청 큰 난수 발생시킴
double random()
{
	return rand() / (double)RAND_MAX;	
}


// 랜덤 숫자를 생성하여 고객이 도착했는지 도착하지 않았는지를 판단
int is_customer_arrived()
{
	if (random() < arrival_prob)
		return TRUE;
	else return FALSE;
}


// 새로 도착한 고객을 큐에 삽입
void insert_customer(int arrival_time)
{
	element customer;

	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time*random()) + 1;
	enqueue(&queue, customer);
	printf("고객 %d이 %d분에 들어옵니다. 서비스시간은 %d분입니다.\n", customer.id, customer.arrival_time, customer.service_time);
}


// 큐에서 기다리는 고객을 꺼내어 고객의 서비스 시간을 반환 (= 서비스 시작)
int remove_customer()
{
	element customer;
	int service_time = 0;

	if (is_empty(&queue)) return 0;
	customer = dequeue(&queue);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += clock - customer.arrival_time;
	printf("고객 %d이 %d분에 서비스를 시작합니다. 대기시간은 %d분이었습니다.\n", customer.id, clock, clock - customer.arrival_time);
	return service_time;
}


// 통계치를 출력
void print_stat()
{
	printf("서비스받은 고객수 = %d\n", served_customers);
	printf("전체 대기 시간 = %d분\n", waited_time);
	printf("1인당 평균 대기 시간 = %f분\n", (double)waited_time / served_customers);
	printf("아직 대기중인 고객수 = %d\n", customers - served_customers);
}


void main()
{
	int service_time = 0;

	clock = 0;
	while (clock < duration) {
		clock++;
		printf("현재시각=%d\n", clock);
		if (is_customer_arrived()) {
			insert_customer(clock);
		}

		if (service_time > 0)
			service_time--;
		else {
			service_time = remove_customer();
		}
	}
	print_stat();
}
*/










// 13페이지 3번
// 햄버거 가게 시뮬레이션 프로그램

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"CircularQueue.h"

#define WAIT_AREA_MAX  100		// 대기실 수용인원 (바꿔서 실험해주면 됨 30,50,100,200...)
#define DURATION 3600 // 초 단위(1시간)		


int menu = 3;
int sec;
//int wait_people;	// 대기실에 들어가 있는 사람 수

typedef struct {
	int cheese;		// 치즈버거 주문 갯수
	int meat;		// 불고기버거 주문 갯수
	int two;		// 더블버거 주문 갯수
}burger;

burger tot = { 0,0,0 };

// 햄버거 3가지 메뉴 중 랜덤하게 하나를 골라 반환하는 함수 (각 손님별 고른 메뉴 결정)
int menu_dicision()
{
	int r;
	r = rand() % 3 + 1;
	return r;
}


// 손님이 들어와서 메뉴 정하고 대기실로 들어감(enqueue) 
void insert_customer()
{
	element host;
	int n = menu_dicision();
	if (n == 1) { host.service_time = 12; printf("치즈 버거를 선택하셨습니다!		"); tot.cheese++; }
	else if (n == 2) { host.service_time = 15; printf("불고기 버거를 선택하셨습니다!		"); tot.meat++; }
	else if (n == 3) { host.service_time = 24; printf("더블 버거를 선택하셨습니다!		"); tot.two++; }
	host.arrival_time = sec;
	enqueue(&queue, host);
}

/*
// 손님 서비스 시간 반환
int get_out()
{
	element host;
	host = peek(&queue);
	return host.service_time;
}
*/



void main()
{
	printf("시뮬레이션 횟수 : 10\n");
	int person;
	int servicetime;
	int tottime;
	int fail;
	int possible = 0;
	int wait_people;

	for (int i = 0; i < 10; i++)
	{
		init(&queue);
		sec = 0;
		wait_people = 0;
		person = 0;
		tottime = 0;
		fail = 0;
		tot = { 0,0,0 };

		srand(time(NULL));
		while (sec <= DURATION)
		{
			sec++;
			if (WAIT_AREA_MAX < wait_people) { printf("%d 꽉 찼습니다!\n", i + 1); fail = 1; break; }

			if (sec % 20 == 0) {
				person++;
				printf("%d번 사람 입장		", person);
				insert_customer();
				wait_people++;

				if(person==1) servicetime = peek(&queue).service_time;


				int k = queue.front;

				tottime = 0;
				for(;;)
				{
					if ((k + 1) % MAX_QUEUE_SIZE == queue.rear) break;
					tottime += queue.queue[k+1].service_time;
					k++;
				}
				printf("예상 대기 시간 : %d초", tottime);
			}


			if (person >= 1)
			{
				if (!is_empty(&queue)) {					

					if (servicetime > 0) servicetime--;
					else if(servicetime==0) {

						dequeue(&queue);
						wait_people--;
						printf("퇴장했습니다.\n");
						servicetime = peek(&queue).service_time;

					}
				}
				else {
					if (servicetime > 0) servicetime--;
					else {
						wait_people--;
					}
				}
			}

			
		
		}
		if (fail == 0) {
			possible++;
			printf("\n시뮬레이션 결과!\n");
			printf("- 대기실 사이즈 : %d\n", WAIT_AREA_MAX);
			printf("- 치즈 버거 : %d\n", tot.cheese);
			printf("- 불고기버거 : %d\n", tot.meat);
			printf("- 더블 버거 : %d\n\n", tot.two);
		}
	}

	printf("성공한 횟수 %d\n", possible);
	printf("수용인원이 %d명인 공간 안정적인 고객을 수용할 확률 %d%\n", WAIT_AREA_MAX, possible * 10);
}

