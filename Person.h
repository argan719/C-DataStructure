

// - �ؽ� -
// ���̺�� �ؽ��� �����Ͽ� ���ô�.

#ifndef _PERSON_H_
#define _PERSON_H_
#define STR_LEN 50
typedef struct _person
{
	int ssn;    // �ֹε�Ϲ�ȣ
	char name[STR_LEN];   // �̸�
	char addr[STR_LEN];   // �ּ�
}Person;

int GetSSN(Person *p);
void ShowPerInfo(Person *p);
Person * MakePersonData(int ssn, char *name, char *addr);

#endif