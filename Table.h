

// - �ؽ� -
// ���̺��� �ؽ��� �����Ͽ� ���ô�.

#ifndef _TABLE_H_
#define _TABLE_H_
#include "Slot.h"
#define MAX_TBL 100
typedef int HashFunc(Key k);

typedef struct _table
{
	Slot tbl[MAX_TBL];
	HashFunc *hf;
}Table;


// ���̺��� �ʱ�ȭ
void TBLInit(Table *pt, HashFunc * f);

// ���̺��� Ű�� ���� ����
void TBLInsert(Table * pt, Key k, Value v);

// Ű�� �ٰŷ� ���̺����� ������ ����
Value TBLDelete(Table *pt, Key k);

// Ű�� �ٰŷ� ���̺����� ������ Ž��
Value TBLSearch(Table *pt, Key k);

#endif
