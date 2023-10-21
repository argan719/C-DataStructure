
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
		printf("1.enqueue  2.dequeue  3.����");
		scanf("%d", &cho);

		if (cho == 1) {
			printf("�����Է� :");
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
// 12������ 1��

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
		printf("1.enqueue  2.dequeue  3.ť�ǰ���  4.����");
		scanf("%d", &cho);

		if (cho == 1) {
			printf("�����Է� :");
			scanf("%d", &num);
			enqueue(&q, num);
			printf("front=%d  rear=%d\n", q.front, q.rear);
		}
		if (cho == 2) {
			printf("dequeue()=%d\n", dequeue(&q));
			printf("front=%d  rear=%d\n", q.front, q.rear);
		}
		if (cho == 3) printf("ť�� ���� : %d\n", get_count(&q));

		if (cho == 4) break;
	}

}
*/






/*
// 12������ 2��
// �� ���� ������ ����ؼ� ����ť ����

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
		printf("1.enqueue  2.dequeue  3.����");
		scanf("%d", &cho);

		if (cho == 1) {
			printf("�����Է� :");
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
// 7������ 3��
// ���༭�� �ùķ��̼� ���α׷�

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "CircularQueue.h"


// �ùķ��̼ǿ� �ʿ��� �������� ���� ����
int duration = 10;
double arrival_prob = 0.7;
int max_serv_time = 5;
int clock;


// �ùķ��̼��� ���
int customers;					// ��ü ����
int served_customers;		// ���� ���� ����
int waited_time;		// ������ ��ٸ� �ð�



// ��û ū ���� �߻���Ŵ
double random()
{
	return rand() / (double)RAND_MAX;	
}


// ���� ���ڸ� �����Ͽ� ���� �����ߴ��� �������� �ʾҴ����� �Ǵ�
int is_customer_arrived()
{
	if (random() < arrival_prob)
		return TRUE;
	else return FALSE;
}


// ���� ������ ���� ť�� ����
void insert_customer(int arrival_time)
{
	element customer;

	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time*random()) + 1;
	enqueue(&queue, customer);
	printf("�� %d�� %d�п� ���ɴϴ�. ���񽺽ð��� %d���Դϴ�.\n", customer.id, customer.arrival_time, customer.service_time);
}


// ť���� ��ٸ��� ���� ������ ���� ���� �ð��� ��ȯ (= ���� ����)
int remove_customer()
{
	element customer;
	int service_time = 0;

	if (is_empty(&queue)) return 0;
	customer = dequeue(&queue);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += clock - customer.arrival_time;
	printf("�� %d�� %d�п� ���񽺸� �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
	return service_time;
}


// ���ġ�� ���
void print_stat()
{
	printf("���񽺹��� ���� = %d\n", served_customers);
	printf("��ü ��� �ð� = %d��\n", waited_time);
	printf("1�δ� ��� ��� �ð� = %f��\n", (double)waited_time / served_customers);
	printf("���� ������� ���� = %d\n", customers - served_customers);
}


void main()
{
	int service_time = 0;

	clock = 0;
	while (clock < duration) {
		clock++;
		printf("����ð�=%d\n", clock);
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










// 13������ 3��
// �ܹ��� ���� �ùķ��̼� ���α׷�

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"CircularQueue.h"

#define WAIT_AREA_MAX  100		// ���� �����ο� (�ٲ㼭 �������ָ� �� 30,50,100,200...)
#define DURATION 3600 // �� ����(1�ð�)		


int menu = 3;
int sec;
//int wait_people;	// ���ǿ� �� �ִ� ��� ��

typedef struct {
	int cheese;		// ġ����� �ֹ� ����
	int meat;		// �Ұ����� �ֹ� ����
	int two;		// ������� �ֹ� ����
}burger;

burger tot = { 0,0,0 };

// �ܹ��� 3���� �޴� �� �����ϰ� �ϳ��� ��� ��ȯ�ϴ� �Լ� (�� �մԺ� �� �޴� ����)
int menu_dicision()
{
	int r;
	r = rand() % 3 + 1;
	return r;
}


// �մ��� ���ͼ� �޴� ���ϰ� ���Ƿ� ��(enqueue) 
void insert_customer()
{
	element host;
	int n = menu_dicision();
	if (n == 1) { host.service_time = 12; printf("ġ�� ���Ÿ� �����ϼ̽��ϴ�!		"); tot.cheese++; }
	else if (n == 2) { host.service_time = 15; printf("�Ұ�� ���Ÿ� �����ϼ̽��ϴ�!		"); tot.meat++; }
	else if (n == 3) { host.service_time = 24; printf("���� ���Ÿ� �����ϼ̽��ϴ�!		"); tot.two++; }
	host.arrival_time = sec;
	enqueue(&queue, host);
}

/*
// �մ� ���� �ð� ��ȯ
int get_out()
{
	element host;
	host = peek(&queue);
	return host.service_time;
}
*/



void main()
{
	printf("�ùķ��̼� Ƚ�� : 10\n");
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
			if (WAIT_AREA_MAX < wait_people) { printf("%d �� á���ϴ�!\n", i + 1); fail = 1; break; }

			if (sec % 20 == 0) {
				person++;
				printf("%d�� ��� ����		", person);
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
				printf("���� ��� �ð� : %d��", tottime);
			}


			if (person >= 1)
			{
				if (!is_empty(&queue)) {					

					if (servicetime > 0) servicetime--;
					else if(servicetime==0) {

						dequeue(&queue);
						wait_people--;
						printf("�����߽��ϴ�.\n");
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
			printf("\n�ùķ��̼� ���!\n");
			printf("- ���� ������ : %d\n", WAIT_AREA_MAX);
			printf("- ġ�� ���� : %d\n", tot.cheese);
			printf("- �Ұ����� : %d\n", tot.meat);
			printf("- ���� ���� : %d\n\n", tot.two);
		}
	}

	printf("������ Ƚ�� %d\n", possible);
	printf("�����ο��� %d���� ���� �������� ���� ������ Ȯ�� %d%\n", WAIT_AREA_MAX, possible * 10);
}

