#pragma once

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define MAX_LIST_SIZE 100 // 배열의 최대크기


typedef int element;
typedef struct {
	int list[MAX_LIST_SIZE];
	int length;
}ArrayListType;


void init(ArrayListType *L);
int is_empty(ArrayListType *L);
void error(char *message);
int is_full(ArrayListType *L);
void add(ArrayListType *L, int position, element item);
void display(ArrayListType *L);

#endif
