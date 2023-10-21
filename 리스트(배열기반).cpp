
/*
// 1페이지 1번

#include<stdio.h>
int main(void)
{
	int arr[10];
	int readCount = 0;
	int readData;
	int i;

	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1) break;

		arr[readCount++] = readData;
	}

	for (i = 0; i < readCount; i++)
		printf("%d ", arr[i]);

	return 0;
}

*/




// 2페이지 2번










/*

// 14페이지 1번

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
		printf("쇼핑해야할 항목 입력 : ");
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
// 14페이지 2번


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
		printf("쇼핑해야할 품목 입력 : ");
		scanf("%s", list[index].name);

		if (list[index].name[0] == 'x') break;

		printf("수량 입력 : ");
		scanf("%d", &list[index].num);

		printf("단가 입력 : ");
		scanf("%d", &list[index].value);

		printf("구분 입력 (식품, 문구, 의류) : ");
		scanf("%s", list[index].category);
		
	}

	printf("%7s %7s %7s %7s\n", "품목", "수량", "단가", "구분(식품, 문구, 의류)");

	for(int i=0;i<index;i++)
		printf("%5s%5d\t%5d\t%5s\n", list[i].name, list[i].num, list[i].value, list[i].category);

}

*/








/*
// 14페이지 3번


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "14p3번 헤더파일.h"

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
		printf("쇼핑해야할 품목 입력 : ");
		scanf("%s", list[index].name);

		if (list[index].name[0] == 'x') break;

		printf("수량 입력 : ");
		scanf("%d", &list[index].num);

		printf("단가 입력 : ");
		scanf("%d", &list[index].value);

		printf("구분 입력 (식품, 문구, 의류) : ");
		scanf("%s", list[index].category);

	}

	printf("%7s %7s %7s %7s\n", "품목", "수량", "단가", "구분(식품, 문구, 의류)");

	for (int i = 0; i < index; i++)
		printf("%5s%5d\t%5d\t%5s\n", list[i].name, list[i].num, list[i].value, list[i].category);

	printf("====== 입력이 끝났습니다..\n");


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

		printf("==> 선택 : ");
		scanf("%d", &n);

		if (n == 5) break;

		if (n == 1) clear(&index);
		if (n == 2) {
			printf("바꿀 요소의 위치를 입력하시오 (index) : ");
			scanf("%d", &pos);
			printf("새로 넣을 품목의 이름을 입력하시오 (item) : ");
			scanf("%s", item);

			replace(list, pos, item);
		}

		if (n == 3) { 
			printf("반환받을 요소의 위치를 입력하시오 (index) : ");
			scanf("%d", &pos);

			shop value=get_entry(list, pos);
			
			printf("품목 : %s\n수량 : %d\n단가 : %d\n구분 : %s\n", value.name, value.num, value.value, value.category);
		}

		if (n == 4) {
			printf("리스트의 길이 : %d\n",get_length(list));
		}
	}

}

*/









// 14페이지 2번 데이터 가지고  <리스트 ADT> 전부 구현하기
// add, delete, clear replace, is_in_list, get_entry, get_length, is_empty, is_full, display,....

// main.cpp  함수.cpp  헤더파일       이렇게 3개 만들어서 구현


//typedef struct ArrayList {
//	int arr[LIST_LEN];   // #define LIST_LEN 10
//	int numOfData;
//	int curPosition;
//}List;

// 이 구조체 사용해서 만들 것.   (포함구조체)






//==== main.cpp

#include<stdio.h>
#include<string.h>
#include "14p헤더.h"


/*  // 헤더파일로 옮김
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



/*    // 14p함수.cpp 로 옮김
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
		printf("위치가 잘못 되었습니다\n"); 
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
		printf("위치가 잘못 되었습니다\n");
	}
	else L->list[pos] = item;
}

int is_in_list(List *L, char name[])
{
	for (int i = 0; i < (L->length); i++)
	{
		if (strcmp(name, L->list[i].name) == 0) {
			printf("품목 :%s\n수량: %d\n단가: %d\n구분: %s\n", L->list[i].name, L->list[i].num,
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
		printf("위치가 잘못 되었습니다\n");
	}

	else return(L->list[pos]);
	
}

int get_length(List *L)
{
	return L->length;
}

void display(List *L)
{
	printf("%5s%5s%5s%5s\n", "품목", "수량", "단가", "구분");
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
		printf("1.맨 앞에 요소 추가\n");
		printf("2.맨 끝에 요소 추가\n");
		printf("3.특정 위치에 요소 추가\n");
		printf("4.특정 위치의 요소 제거\n");
		printf("5.모든 요소 제거\n");
		printf("6.특정 위치의 요소 대체(replace)\n");
		printf("7.특정 값이 리스트 안에 있는지 검색\n");
		printf("8.특정 위치의 요소 반환\n");
		printf("9.리스트의 길이를 반환\n");
		printf("10.리스트의 모든 요소 출력\n");
		printf("11.종료\n");

		printf("==> ");
		scanf("%d", &n);

		if (n == 11)  break;

		if (n == 1) {
			printf("맨 앞에 넣을 값 입력\n");
			printf("품목 : ");
			scanf("%s", item.name);
			printf("수량 : ");
			scanf("%d", &item.num);
			printf("단가 : ");
			scanf("%d", &item.value);
			printf("구분(식품, 문구, 의류) : ");
			scanf("%s", item.category);

			add_first(&list, item);
		}

		if (n == 2) {

			printf("맨 끝에 넣을 값 입력\n");
			printf("품목 : ");
			scanf("%s", item.name);
			printf("수량 : ");
			scanf("%d", &item.num);
			printf("단가 : ");
			scanf("%d", &item.value);
			printf("구분(식품, 문구, 의류) : ");
			scanf("%s", item.category);

			add_list(&list, item);

		}

		if (n == 3) {
			printf("추가할 위치 입력 : ");
			scanf("%d", &pos);

			printf("추가할 값 입력\n");
			printf("품목 : ");
			scanf("%s", item.name);
			printf("수량 : ");
			scanf("%d", &item.num);
			printf("단가 : ");
			scanf("%d", &item.value);
			printf("구분(식품, 문구, 의류) : ");
			scanf("%s", item.category);

			add(&list, pos, item);
		}

		if (n == 4)
		{
			printf("삭제할 위치 입력 : ");
			scanf("%d", &pos);

			remove(&list, pos);
		}
			
		if (n == 5) clear(&list);

		if (n == 6)
		{
			printf("바꿀 위치 입력 : ");
			scanf("%d", &pos);

			printf("바꿀 값 입력\n");
			printf("품목 : ");
			scanf("%s", item.name);
			printf("수량 : ");
			scanf("%d", &item.num);
			printf("단가 : ");
			scanf("%d", &item.value);
			printf("구분(식품, 문구, 의류) : ");
			scanf("%s", item.category);

			replace(&list,pos, item);
		}
		

		if (n == 7)
		{
			char name[20];
			printf("검색할 상품의 품목을 입력 : ");
			scanf("%s",name);

			int fact = is_in_list(&list, name);

			if (fact == 1) printf("존재합니다!\n");
			if (fact == 0) printf("존재하지 않습니다\n");
		}

		if (n == 8)
		{
			printf("위치 입력 : ");
			scanf("%d", &pos);

			item=get_entry(&list, pos);
			printf("반환받은 값\n 품목 : %s  수량 : %d  단가 : %d  구분 : %s\n", item.name, item.num, item.value, item.category);
		}

		if (n == 9) printf("리스트의 길이 : %d\n", get_length(&list));

		if (n == 10)
		{
			printf("리스트의 모든 요소 출력\n");
			display(&list);
		}
	}



}

*/


