

// - �ؽ� -
// ���̺�� �ؽ��� �����Ͽ� ���ô�.

#ifndef _SLOT_H_
#define _SLOT_H_
#include "Person.h"
typedef int Key;
typedef Person * Value;
enum SlotStatus {EMPTY, DELETED, INUSE};
typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;


// Slot�� �����ؼ��� ������ �Լ��� �������� �ʴ´�. 

#endif