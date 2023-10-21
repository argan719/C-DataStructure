#pragma once


#ifndef ARRAY_LIST
# define ARRAY_LIST

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


void add_first(List *L, shop item);
void add_list(List *L, shop item);
int is_full(List *L);
int is_empty(List *L);
void add(List *L, int pos, shop item);
shop remove(List *L, int pos);
void clear(List *L);
void replace(List *L, int pos, shop item);
int is_in_list(List *L, char name[]);
shop get_entry(List *L, int pos);
int get_length(List *L);
void display(List *L);

#endif

