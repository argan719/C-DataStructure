

#include<stdio.h>
#include<string.h>
#include"14p헤더.h"


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