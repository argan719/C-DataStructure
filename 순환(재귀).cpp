// 11페이지 10번

/*
#include<stdio.h>

int sum(int st)
{
	printf("%d+", st);
	if (st == 1) return (1);
	return(st + sum(st-1));
}

void main()
{
	printf("\b=%d", sum(10));

}
*/




/*
// 11페이지 11번

#include<stdio.h>

int sum(int st,int end)
{
	if (st==end) return (end);
	else return(st + sum(st+1,end));
}

void main()
{
	int num1, num2;
	int tot;
	printf("첫 번째수 입력 : ");
	scanf("%d", &num1);
	printf("두 번째수 입력 : ");
	scanf("%d", &num2);

	printf("%d부터 %d까지의 합 = %d", num1, num2, sum(num1,num2));
}

*/



/*
// 11페이지 13번

#include<stdio.h>
#include<string.h>

void sort(int bin[],int size)
{
	int i, k;
	int j;

	for (i = 0; i < size; i++)
	{
		for (k = i + 1; k <= size; k++)
		{
			if (bin[i] > bin[k]) {
				j = bin[i];
				bin[i] = bin[k];
				bin[k] = j;
			}
		}
	}
}

int binary(int bin[],int low, int high, int key)
{
	int m = (high + low)/ 2;

	if (low >= high) return -1;
	if (bin[m] == key) return m;
	else if (bin[m] > key) binary(bin, 0, m - 1, key);
	else if (bin[m] < key) binary(bin, m + 1, high, key);
	
}

void main()
{
	int key;
	int bin[] = { 30,10,20,50,40,60 };
	sort(bin, sizeof(bin) / sizeof(bin[0]) - 1);

	printf("찾을값 : ");
	scanf("%d", &key);

	int end = sizeof(bin) / sizeof(bin[0]) - 1;

	int result = binary(bin, 0, end, key);
	
	if (result == -1) printf("탐색실패");
	else printf("타겟저장인덱스 : %d",result);

}

*/



/*
//11페이지 14번

#include<stdio.h>

int mul(int num1, int num2)
{
	if (num2 == 1) return num1;
	return (num1*mul(num1, num2 - 1));
}

void main()
{
	int num1, num2;
	printf("어떤수의 몇 승을 구할까요 ?");
	
	scanf("%d%d", &num1, &num2);
	printf("%d",mul(num1, num2)); 
}


*/


/*
#include<stdio.h>

int sum(int n)
{
	if (n == 1) return(n*n*n);
	else return(n*n*n + sum(n - 1));
}

void main()
{
	int n;
	printf("n값을 입력하시오 : ");
	scanf("%d", &n);
	printf("%d",sum(n));
}
*/


