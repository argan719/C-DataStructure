
/*
// 1������ 1��

#include<stdio.h>
int main(void)
{
	int arr[10];
	int readCount = 0;
	int readData;
	int i;

	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1) break;

		arr[readCount++] = readData;
	}

	for (i = 0; i < readCount; i++)
		printf("%d ", arr[i]);

	return 0;
}

*/




// 2������ 2��










/*

// 14������ 1��

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int index = 0;
	char *list[10];
	char shop[20];

	for (;;)
	{
		printf("�����ؾ��� �׸� �Է� : ");
		gets_s(shop);

		if (shop[0]=='x') break;

		list[index] = (char *)malloc(strlen(shop) + 1);
		strcpy(list[index], shop);
		index++;

	}

	for (int i = 0; i < index; i++)
		printf("%s\n", list[i]);
}

*/







/*
// 14������ 2��


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ss {
	char name[20];
	int num;
	int value;
	char category[20];
}shop;


void main()
{
	shop list[10];
	int index;

	for (index=0;index<10;index++)
	{
		printf("�����ؾ��� ǰ�� �Է� : ");
		scanf("%s", list[index].name);

		if (list[index].name[0] == 'x') break;

		printf("���� �Է� : ");
		scanf("%d", &list[index].num);

		printf("�ܰ� �Է� : ");
		scanf("%d", &list[index].value);

		printf("���� �Է� (��ǰ, ����, �Ƿ�) : ");
		scanf("%s", list[index].category);
		
	}

	printf("%7s %7s %7s %7s\n", "ǰ��", "����", "�ܰ�", "����(��ǰ, ����, �Ƿ�)");

	for(int i=0;i<index;i++)
		printf("%5s%5d\t%5d\t%5s\n", list[i].name, list[i].num, list[i].value, list[i].category);

}

*/








/*
// 14������ 3��


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "14p3�� �������.h"

//typedef struct ss {
//	char name[20];
//	int num;
//	int value;
//	char category[20];
//}shop;


void main()
{
	shop list[10];

	int index;

	for (index = 0; index < 10; index++)
	{
		printf("�����ؾ��� ǰ�� �Է� : ");
		scanf("%s", list[index].name);

		if (list[index].name[0] == 'x') break;

		printf("���� �Է� : ");
		scanf("%d", &list[index].num);

		printf("�ܰ� �Է� : ");
		scanf("%d", &list[index].value);

		printf("���� �Է� (��ǰ, ����, �Ƿ�) : ");
		scanf("%s", list[index].category);

	}

	printf("%7s %7s %7s %7s\n", "ǰ��", "����", "�ܰ�", "����(��ǰ, ����, �Ƿ�)");

	for (int i = 0; i < index; i++)
		printf("%5s%5d\t%5d\t%5s\n", list[i].name, list[i].num, list[i].value, list[i].category);

	printf("====== �Է��� �������ϴ�..\n");


	int n;
	int pos;
	char item[20];

	for (;;)
	{
		printf("1. clear\n");
		printf("2. replace\n");
		printf("3. get_entry\n");
		printf("4. get_length\n");
		printf("5. END\n");

		printf("==> ���� : ");
		scanf("%d", &n);

		if (n == 5) break;

		if (n == 1) clear(&index);
		if (n == 2) {
			printf("�ٲ� ����� ��ġ�� �Է��Ͻÿ� (index) : ");
			scanf("%d", &pos);
			printf("���� ���� ǰ���� �̸��� �Է��Ͻÿ� (item) : ");
			scanf("%s", item);

			replace(list, pos, item);
		}

		if (n == 3) { 
			printf("��ȯ���� ����� ��ġ�� �Է��Ͻÿ� (index) : ");
			scanf("%d", &pos);

			shop value=get_entry(list, pos);
			
			printf("ǰ�� : %s\n���� : %d\n�ܰ� : %d\n���� : %s\n", value.name, value.num, value.value, value.category);
		}

		if (n == 4) {
			printf("����Ʈ�� ���� : %d\n",get_length(list));
		}
	}

}

*/









// 14������ 2�� ������ ������  <����Ʈ ADT> ���� �����ϱ�
// add, delete, clear replace, is_in_list, get_entry, get_length, is_empty, is_full, display,....

// main.cpp  �Լ�.cpp  �������       �̷��� 3�� ���� ����


//typedef struct ArrayList {
//	int arr[LIST_LEN];   // #define LIST_LEN 10
//	int numOfData;
//	int curPosition;
//}List;

// �� ����ü ����ؼ� ���� ��.   (���Ա���ü)






//==== main.cpp

#include<stdio.h>
#include<string.h>
#include "14p���.h"


/*  // ������Ϸ� �ű�
# define LIST_LEN 10

typedef struct ss {
	char name[20];
	int num;
	int value;
	char category[20];
}shop;


typedef struct ArrayList {
	shop list[LIST_LEN];
	int length;
}List;
*/



/*    // 14p�Լ�.cpp �� �ű�
void add_first(List *L, shop item)
{
	if (L->length != 0)
	{
		for (int i = (L->length - 1); 0 <= i; i--)
			L->list[i + 1] = L->list[i];
	}

	L->list[0] = item;
	L->length++;
}



void add_list(List *L, shop item)
{
	
	L->list[L->length] = item;
	L->length++;
}

int is_full(List *L)
{
	return L->length == LIST_LEN;
}

int is_empty(List *L)
{
	return L->length == 0;
}

void add(List *L, int pos, shop item)
{
	if (!(is_full(L)) && (pos >= 0) && (pos <= L->length))
	{
		for (int i = (L->length - 1); pos <= i; i--)
			L->list[i + 1] = L->list[i];

		L->list[pos] = item;
		L->length++;
	}

}

shop remove(List *L, int pos)
{
	if (pos < 0 || L->length <= pos)
	{
		printf("��ġ�� �߸� �Ǿ����ϴ�\n"); 
	}
	else 
	{
		shop item = L->list[pos];
		for (int i = pos; i < (L->length - 1); i++)
			L->list[i] = L->list[i + 1];
		L->length--;
		return item;
	}

}

void clear(List *L)
{
	L->length = 0;
}


void replace(List *L, int pos, shop item)
{
	if (pos < 0 || L->length <= pos)
	{
		printf("��ġ�� �߸� �Ǿ����ϴ�\n");
	}
	else L->list[pos] = item;
}

int is_in_list(List *L, char name[])
{
	for (int i = 0; i < (L->length); i++)
	{
		if (strcmp(name, L->list[i].name) == 0) {
			printf("ǰ�� :%s\n����: %d\n�ܰ�: %d\n����: %s\n", L->list[i].name, L->list[i].num,
				L->list[i].value, L->list[i].category);
			return 1;
		}
	}
	return 0;
}

shop get_entry(List *L, int pos)
{
	if (pos < 0 || L->length <= pos)
	{
		printf("��ġ�� �߸� �Ǿ����ϴ�\n");
	}

	else return(L->list[pos]);
	
}

int get_length(List *L)
{
	return L->length;
}

void display(List *L)
{
	printf("%5s%5s%5s%5s\n", "ǰ��", "����", "�ܰ�", "����");
	for (int i = 0; i < L->length; i++)
	{
		printf("%5s%5d%5d%5s\n", L->list[i].name, L->list[i].num, L->list[i].value, L->list[i].category);
	}

}
*/





/*
//=== main.cpp
void main()
{
	List list;
	list.length = 0;

	shop item;

	int n;
	int pos;
	for (;;)
	{
		printf("1.�� �տ� ��� �߰�\n");
		printf("2.�� ���� ��� �߰�\n");
		printf("3.Ư�� ��ġ�� ��� �߰�\n");
		printf("4.Ư�� ��ġ�� ��� ����\n");
		printf("5.��� ��� ����\n");
		printf("6.Ư�� ��ġ�� ��� ��ü(replace)\n");
		printf("7.Ư�� ���� ����Ʈ �ȿ� �ִ��� �˻�\n");
		printf("8.Ư�� ��ġ�� ��� ��ȯ\n");
		printf("9.����Ʈ�� ���̸� ��ȯ\n");
		printf("10.����Ʈ�� ��� ��� ���\n");
		printf("11.����\n");

		printf("==> ");
		scanf("%d", &n);

		if (n == 11)  break;

		if (n == 1) {
			printf("�� �տ� ���� �� �Է�\n");
			printf("ǰ�� : ");
			scanf("%s", item.name);
			printf("���� : ");
			scanf("%d", &item.num);
			printf("�ܰ� : ");
			scanf("%d", &item.value);
			printf("����(��ǰ, ����, �Ƿ�) : ");
			scanf("%s", item.category);

			add_first(&list, item);
		}

		if (n == 2) {

			printf("�� ���� ���� �� �Է�\n");
			printf("ǰ�� : ");
			scanf("%s", item.name);
			printf("���� : ");
			scanf("%d", &item.num);
			printf("�ܰ� : ");
			scanf("%d", &item.value);
			printf("����(��ǰ, ����, �Ƿ�) : ");
			scanf("%s", item.category);

			add_list(&list, item);

		}

		if (n == 3) {
			printf("�߰��� ��ġ �Է� : ");
			scanf("%d", &pos);

			printf("�߰��� �� �Է�\n");
			printf("ǰ�� : ");
			scanf("%s", item.name);
			printf("���� : ");
			scanf("%d", &item.num);
			printf("�ܰ� : ");
			scanf("%d", &item.value);
			printf("����(��ǰ, ����, �Ƿ�) : ");
			scanf("%s", item.category);

			add(&list, pos, item);
		}

		if (n == 4)
		{
			printf("������ ��ġ �Է� : ");
			scanf("%d", &pos);

			remove(&list, pos);
		}
			
		if (n == 5) clear(&list);

		if (n == 6)
		{
			printf("�ٲ� ��ġ �Է� : ");
			scanf("%d", &pos);

			printf("�ٲ� �� �Է�\n");
			printf("ǰ�� : ");
			scanf("%s", item.name);
			printf("���� : ");
			scanf("%d", &item.num);
			printf("�ܰ� : ");
			scanf("%d", &item.value);
			printf("����(��ǰ, ����, �Ƿ�) : ");
			scanf("%s", item.category);

			replace(&list,pos, item);
		}
		

		if (n == 7)
		{
			char name[20];
			printf("�˻��� ��ǰ�� ǰ���� �Է� : ");
			scanf("%s",name);

			int fact = is_in_list(&list, name);

			if (fact == 1) printf("�����մϴ�!\n");
			if (fact == 0) printf("�������� �ʽ��ϴ�\n");
		}

		if (n == 8)
		{
			printf("��ġ �Է� : ");
			scanf("%d", &pos);

			item=get_entry(&list, pos);
			printf("��ȯ���� ��\n ǰ�� : %s  ���� : %d  �ܰ� : %d  ���� : %s\n", item.name, item.num, item.value, item.category);
		}

		if (n == 9) printf("����Ʈ�� ���� : %d\n", get_length(&list));

		if (n == 10)
		{
			printf("����Ʈ�� ��� ��� ���\n");
			display(&list);
		}
	}



}

*/


