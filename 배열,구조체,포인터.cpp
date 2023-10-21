// 1페이지 1번

/*
#include<stdio.h>
# define MAX_SIZE 10
void sub(int var, int list[])
{
	var = 10;
	list[0] = 10;
}

void main()
{
	int var;
	int list[MAX_SIZE];
	var = 0;
	list[0] = 0;
	sub(var, list);
	printf("var=%d, list[0]=%d\n", var, list[0]);
}
*/


//2번

//#include<stdio.h>
//
//struct polynomial {
//	int degree;
//	int coefficient;
//};
//
//void main()
//{
//	struct polynomial p[5];
//
//}









/*
#include<stdio.h>								// 2번 질문하기
#include<stdlib.h>
void main()
{
	int maxdegree;
	int *p;
	int num;
	printf("다항식의 차수를 입력하시오 : ");
	scanf("%d", &maxdegree);

	p = (int *)malloc(sizeof(int)*(maxdegree+1));  // 동적메모리 이용 / 입력받은 다항식의 차수만큼 동적 메모리 이용해 배열을 만듦
	
	for (int i = 0; i <= maxdegree; i++)
	{
		printf("%d차항의 계수를 입력하시오 : ", i);
		scanf("%d", &num);
		p[i] = num;
	}


}
*/



/*
// 2번 그대로 입력해보기

#include<stdio.h>
# define MAX_DEGREE 10
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

void main()
{
	polynomial a = { 5,{3,6,0,0,0,10} };
	printf("%3d", a.degree);
	for (int i = 0; i < 6; i++)
		printf("%3.0f", a.coef[i]);
}
*/




/*
// 3번   그대로 입력									3번 이해 못함 해결할 것

#include<stdio.h>
# define MAX(a,b) (((a)>(b))?(a):(b))
# define MAX_DEGREE 10

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);


	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}

	return C;
}

void main()
{
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };

	polynomial c;
	c = poly_add1(a, b);

	printf("%3d", c.degree);
	for (int i = 0; i < 6; i++)
		printf("%3.0f", c.coef[i]);
}
*/







//4번    시도해봤는데 실패..(다시 시도하기)			  


/*
#include<stdio.h>
#include<stdlib.h>
# define MAX(a,b) (((a)>(b))?(a):(b))


typedef struct {
	int coef;
	int degree;
}polynomial;

void main()
{
	int *Cp;
	polynomial Ap[] = { {8,3},{7,1},{1,0} };
	polynomial Bp[] = { { 10,3 }, { 3,2 }, { 1,0 } };

	int Apos = 0; int Bpos = 0;

	int Amax = sizeof(Ap)/sizeof(Ap[0]) -1 ;
	int Bmax = sizeof(Bp)/sizeof(Bp[0]) -1;

	while (Apos <= Ap[0].coef || Bpos <= Bp[0].coef)
	{
		if (Bp[Bmax].degree<Ap[Amax].degree) {

		}
	}


}

*/






// 6페이지 6번

/*
#include<stdio.h>
# define ROWS 3
# define COLS 3
// C=A+B

void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	int r, c;
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			C[r][c] = A[r][c] + B[r][c];
}

void main()
{
	int array1[ROWS][COLS] = { {2,3,0},{8,9,1},{7,0,5} };
	int array2[ROWS][COLS] = { {1.0,0},{1,0,0},{1,0,0} };
	int array3[ROWS][COLS];
	sparse_matrix_add1(array1, array2, array3);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%3d", array3[i][j]);
		}
		printf("\n");
	}
}

*/






// 8페이지 8번

/*
#include<stdio.h>

void swap(int *px, int *py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

void main()
{
	int a = 1, b = 2;
	printf("swap을 호출하기 전 : a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap을 호출한 다음 : a=%d, b=%d\n", a, b);
}
*/






/*
// 9페이지 9번


#include<stdio.h>

typedef struct {
	int x;
	int y;
}pointtype;

int get_line_parameter(pointtype p1, pointtype p2, float *slope, float *yintercept)
{
	if (p1.x == p2.x) return(-1);
	else {
		*slope = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
		*yintercept = p1.y - (*slope * p1.x);
		return 0;
	}
}


void main()
{
	pointtype pt1 = { 3,3 }, pt2 = { 6,6 };
	float s, y;
	if (get_line_parameter(pt1, pt2, &s, &y) == -1) printf("error\n");
	else printf("기울기는 %f, y절편은 %f\n", s, y);
}

*/










// 12페이지 1번								

/*
#include<stdio.h>
# define COLS 3
# define ROWS 4

void main()
{
	int origin[COLS][ROWS] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int swap[ROWS][COLS];

	int i, k;

	for (i = 0; i < COLS; i++)
	{
		for (k = 0; k < ROWS; k++)
		{
			swap[k][i] = origin[i][k];
		}
	}



	for (int j = 0; j < ROWS; j++)
	{
		for (int c = 0; c < COLS; c++)
		{
			printf("%3d", swap[j][c]);
		}
		printf("\n");
	}
}

*/








// 12페이지 2번								// 구조체 이용한 동적메모리로 구현      


/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char *name;
	char *phone;
	int age;
}PERSON, *PPERSON;



void add(PERSON person[], int i)
{
	char name[30];
	char num[30];
	int age;

	printf("이름 : ");
	scanf("%s", name);
	printf("전화번호 : ");
	scanf("%s", num);
	printf("나이 : ");
	scanf("%d",&age);

	person[i].name = (char *)malloc(strlen(name)+1);
	strcpy(person[i].name, name);

	person[i].phone = (char *)malloc(strlen(num)+1);
	strcpy(person[i].phone, num);

	person[i].age = age;


}

int remove(PERSON person[], int i)
{
	char keyname[30];
	char *tmp;
	printf("삭제할 학생의 이름을 입력하시오 : ");
	scanf("%s", keyname);

	for (int k = 0; k < i; k++)
	{
		if (strcmp(keyname, person[k].name) == 0) {
			for (int j = k; j < i; j++)
			{
				person[j] = person[j + 1];

			}
			i--;
		}
	}
	return i;

}


void print(PERSON person[], int i)
{
	for (int k = 0; k < i; k++)
	{
		printf("%s %s %d\n", person[k].name, person[k].phone, person[k].age);
	}
	
}

void sort(PERSON person[], int i)
{
	char *tmp;
	int a;
	for (int k = 0; k < i-1; k++)
	{
		for (int j = k; j < i; j++)
		{
			if (strcmp(person[k].name, person[j].name) > 0) {
				tmp = person[k].name;
				person[k].name = person[j].name;
				person[j].name = tmp;

				tmp = person[k].phone;
				person[k].phone = person[j].phone;
				person[j].phone = tmp;

				a = person[k].age;
				person[k].age = person[j].age;
				person[j].age = a;

			}
		}
	}
}

void main()
{
	int num;
	PERSON person[10];
	int i = 0;

	for (;;)
	{
		printf("1. 등록\n");
		printf("2. 삭제\n");
		printf("3. 리스트 출력\n");
		printf("4. 정렬\n");
		printf("5. 종료\n");
		printf("===> ");
		scanf("%d", &num);

		if (num == 5) break;

		if (num == 1) { add(person,i); i++;}
		if (num == 2) { i=remove(person, i);}
		if (num == 3) print(person, i); 
		if (num == 4) sort(person, i);
	}
}

*/





// 다항식 덧셈   // 2페이지 3번


/*
#include<stdio.h>
# define MAX_DEGREE 10

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;


void main()
{
	polynomial A = { 5,{10,0,0,0,6,3} };
	polynomial B = { 5,{3,0,4,0,2,1} };
	polynomial C;

	int max = ((A.degree) > (B.degree)) ? (A.degree) : (B.degree);
	C.degree = max;

	int index = 0;

	while (index <= max)
	{
		C.coef[index] = A.coef[index] + B.coef[index];
		index++;
	}

	for (int i = 0; i <= max; i++)
	{
		printf("%3.0f", C.coef[i]);
	}
}

*/








/*

// 3페이지 4번

#include<stdio.h>						
# define MAX_DEGREE 10

typedef struct {
	int coef;
	int degree;
}polynomial;


void main()
{
	int max;
	int i = 0, k = 0, a = 0;
	int index = 0;
	int tot = 0, cnt = 0;
														// 원래 A 초기값 예시에 {2,5} 추가함
	polynomial A[] = { {2,5},{8,3},{7,1},{1,0} };		 // 제일 높은 차수가 맨 앞에 있음  (전제)
	polynomial B[] = { {10,3},{3,2},{1,0} };
	polynomial C[10];

	int Asize = sizeof(A) / sizeof(A[0]);
	int Bsize = sizeof(B) / sizeof(B[0]);
	max = (Asize > Bsize) ? (Asize) : (Bsize);

	tot = Asize + Bsize;

	for (int j = 0; j < Asize; j++)
	{
		for (int u = 0; u < Bsize; u++)
		{
			if (A[j].degree == B[u].degree) cnt++;
		}
	}

	tot -= cnt;


	while (i < Asize || k < Bsize)
	{

		if (B[k].degree < A[i].degree) {
			C[index] = A[i];
			i++;
		}
		else if (A[i].degree < B[k].degree) {
			C[index] = B[k];
			k++;
		}
		else if (A[i].degree == B[k].degree) {
			C[index].degree = A[i].degree;
			C[index].coef = A[i].coef + B[k].coef;
			i++;
			k++;
		}

		index++;
	}

	

	for(a=0;a<tot;a++)					// 계수 출력
	{
		printf("%3d", C[a].coef);
	}
	printf("\n");


	for (a = 0; a < tot; a++)				// 차수 출력		
	{
		printf("%3d", C[a].degree);
	}
}

*/









/*

// 5페이지 5번 (희소행렬 두 개 더하기)  --> 6페이지 7번

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int A[6][6] = { {2,0,0,0,0,0},{0,0,0,0,0,3},{0,0,8,0,9,0},{0,1,0,0,0,0},{0,0,0,0,0,0},{7,0,0,0,0,5} };
	int B[6][6] = { {0,0,0,7,0,0},{9,0,0,0,0,8},{0,0,0,0,0,0},{6,5,0,0,0,0},{0,0,0,0,0,1},{0,0,2,0,0,0} };

	int Asize = sizeof(A) / sizeof(A[0][0]);
	int Bsize = sizeof(B) / sizeof(B[0][0]);

	int Acnt = 0, Bcnt = 0;


	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (A[i][k] != 0) Acnt++;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (B[i][k] != 0) Bcnt++;
		}
	}


	// **이용해서 동적메모리로 2차원 배열 만들기

	int **Arow;
	Arow = (int **)malloc(sizeof(int *)*Acnt);

	for (int i = 0; i < Acnt; i++)
	{
		Arow[i] = (int *)malloc(sizeof(int) * 3);
	}
	
	// 접근할때는 Arow[0][0]이런식으로 접근
	// A 희소행렬 축소시킨 2차원 배열 완성


	int **Brow;
	Brow=(int **)malloc(sizeof(int *)*Bcnt);

	for(int i=0;i<Bcnt;i++)
	{
		Brow[i]=(int *)malloc(sizeof(int)*3);
	}

	// B 희소행렬 축소시킨 2차원 배열 완성


	// 축소시킨 배열에 값 넣기


	int Arowcnt = 0;
	int Browcnt = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (A[i][k] != 0) {
				Arow[Arowcnt][0] = i;
				Arow[Arowcnt][1] = k;
				Arow[Arowcnt][2] = A[i][k];

				Arowcnt++;

			}
		}
	}


	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (B[i][k] != 0) {
				Brow[Browcnt][0] = i;
				Brow[Browcnt][1] = k;
				Brow[Browcnt][2] = B[i][k];

				Browcnt++;

			}
		}
	}


	

	int samecnt = 0;
	int Ccnt = Acnt + Bcnt;   // Ccnt는 A+B=C 의 C의 행 갯수임

	for (int i = 0; i < Acnt; i++)
	{
		for (int k = 0; k < Bcnt; k++)
		{
			if (Arow[i][0] == Brow[k][0] && Arow[i][1] == Brow[k][1])
				samecnt++;
			
		}
	}

	Ccnt -= samecnt;

	int **Crow;
	Crow = (int **)malloc(sizeof(int *)*Ccnt);

	for (int i = 0; i < Ccnt; i++)
	{
		Crow[i] = (int *)malloc(sizeof(int) * 3);
	}


	// C채우기 (A+B 해서 C 채우기)

	int Cindex = 0;
	int r;

	for (int i = 0; i < Acnt; i++)
	{
		for (int k = 0; k < Bcnt; k++)
		{
			r = 0;
			if (Arow[i][0] == Brow[k][0] && Arow[i][1] == Brow[k][1])
			{
				Crow[Cindex][0] = Arow[i][0];
				Crow[Cindex][1] = Arow[i][1];
				Crow[Cindex][2] = Arow[i][2] + Brow[k][2];
				Cindex++;
				r = 1;
				break;
			}
			
		}
		if (r != 1) {
			Crow[Cindex][0] = Arow[i][0];
			Crow[Cindex][1] = Arow[i][1];
			Crow[Cindex][2] = Arow[i][2];
			Cindex++;
			
		}
		
	}


	for (int i = 0; i < Bcnt; i++)
	{
		for (int k = 0; k < Acnt; k++)
		{
			r = 0;
			if (Arow[k][0] == Brow[i][0] && Arow[k][1] == Brow[i][1])
			{
				r = 1;
				break;
			}

		}
		if (r != 1) {
			Crow[Cindex][0] = Brow[i][0];
			Crow[Cindex][1] = Brow[i][1];
			Crow[Cindex][2] = Brow[i][2];
			Cindex++;

		}

	}


	printf("\nA출력\n");
	for (int i = 0; i < Acnt; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			printf("%3d", Arow[i][k]);
		}
		printf("\n");
	}


	printf("\nB출력\n");
	for (int i = 0; i < Bcnt; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			printf("%3d", Brow[i][k]);
		}
		printf("\n");
	}

	printf("\nC출력 (A+B=C)\n");
	for (int i = 0; i < Ccnt; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			printf("%3d", Crow[i][k]);
		}
		printf("\n");
	}
}


*/





/*
// 10페이지 10번 출력해보기


#include<stdio.h>
int main(void)
{
	int num = 123;
	float num_f = 56.6;
	char text_c = 'M';

	void *void_p;
	void_p = &num;
	printf("int %d\n", *((int *)void_p));

	void_p = &num_f;
	printf("float %f\n", *((float *)void_p));

	void_p = &text_c;
	printf("char %c\n", *((char *)void_p));
	return 0;
}

*/





/*
// 10페이지 11번
// 출력해보기

#include<stdio.h>
void arDump(void *array, int length);

void main()
{
	int ari[] = { 1,2,3,4,5 };
	char arc[] = "Pointer";

	arDump(ari, sizeof(ari));
	arDump(arc, sizeof(arc));
}

void arDump(void *array, int length)
{
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", *((unsigned char *)array + i));
	}
	printf("\n");
}

*/





/*
// 11페이지 12번

#include<stdio.h>
void foo(int a)
{
	printf("foo : %d\n", a);
}

void main()
{
	// f는 함수의 주소를 담는 포인터 타입이다.
	void(*f)(int);
	f = foo;
	f(10);
	(*f)(10);
}

*/






/*
// 15페이지 4번

#include<stdio.h>
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

void main()
{
	double(*pf[4])(double x, double y) = { add,sub,mul,div };
	int num;
	int n1, n2;
	for (;;)
	{
		printf("=====================\n");
		printf("0. 덧셈\n");
		printf("1. 뺄셈\n");
		printf("2. 곱셈\n");
		printf("3. 나눗셈\n");
		printf("4. 종료\n");
		printf("=====================\n");
		printf("메뉴를 선택하시오 : ");
		scanf("%d", &num);

		if (num == 4) { printf("종료되었습니다.\n"); break;}
		else {
			printf("2개의 정수를 입력하시오 : ");
			scanf("%d%d", &n1, &n2);
		}

		if (num == 0) printf("연산결과 = %.2f\n",(pf[0])(n1, n2));
		if (num == 1) printf("연산결과 = %.2f\n",(pf[1])(n1, n2));
		if (num == 2) printf("연산결과 = %.2f\n",(pf[2])(n1, n2));
		if (num == 3) printf("연산결과 = %.2f\n",(pf[3])(n1, n2));
	}
}



double add(double x, double y)			// 0덧셈
{
	return (x + y);
}

double sub(double x, double y)			// 1뺄셈
{
	if (x > y) return(x - y);
	else return(y - x);
}

double mul(double x, double y)			// 2곱셈
{
	return (x*y);
}

double div(double x, double y)			// 3나눗셈
{
	return(x / y);
}

*/






/*

// 13페이지 3번

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _sData {
	int type;
	void *vp;
}DATA, *PDATA;



void add(DATA *data, int index)
{
	char n3[100];

	printf("자료의 종류를 입력하세요 [정수:1, 실수:2, 문자열:3 ]=>");
	scanf("%d", &data[index].type);

	if (data[index].type == 1) {
		printf("정수를 입력하세요 : ");
		
		data[index].vp = malloc(sizeof(int));
		scanf("%d", data[index].vp);

	}

	if (data[index].type == 2) {
		printf("실수를 입력하세요 : ");

		data[index].vp = malloc(sizeof(float));
		scanf("%f", data[index].vp);

	}

	if (data[index].type == 3) {
		printf("문자열을 입력하세요 : ");
		scanf("%s", n3);

		data[index].vp = (char *)malloc(sizeof(char)*(strlen(n3)+1));
		strcpy((char *)data[index].vp, n3);
	}
}

void remove(DATA *data, int *index)
{
	int num;
	printf("삭제할 index를 입력하세요 : ");
	scanf("%d", &num);

	if (num < *index)
	{
		for (int i = num; i < *index; i++)
		{
			data[i] = data[i + 1];
		}

		*index--;
	}

	else printf("자료가 존재하지 않습니다\n");


}

void print(DATA *data, int index) 
{
	for (int i = 0; i < index; i++)
	{
		if (data[i].type == 1) printf("%d : 정수[ %d ]\n", i, *((int *)data[i].vp));

		if (data[i].type == 2) printf("%d : 실수[ %.5f ]\n", i,*((float *)data[i].vp));

		if (data[i].type == 3) printf("%d : 문자열[ %s ]\n", i, ((char *)data[i].vp));
	}
}


void main()
{
	int n;
	DATA data[100];
	int index = 0;

	for (;;)
	{
		printf("=====================\n");
		printf("1. 자료 등록\n");
		printf("2. 자료 삭제\n");
		printf("3. 자료 출력\n");
		printf("4. 종료\n");
		printf("=====================\n");
		printf("==> ");
		scanf("%d", &n);


		if (n == 4) break;

		if (n == 1) { add(data, index); index++; }
		if (n == 2) remove(data,&index);
		if (n == 3) print(data, index);

	}
}


*/

