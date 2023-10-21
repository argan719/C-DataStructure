

// - 해싱 -
// 테이블과 해쉬를 구현하여 봅시다.

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


// Slot과 관련해서는 별도의 함수를 정의하지 않는다. 

#endif