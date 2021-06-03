#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	포인터 변수에서 const 상수 사용 방법
	 두 가지 방식으로 사용 가능
	 1. 포인터 변수 내부의 주소값 변경 가능
		주소값을 역참조하여 해당 위치의 데이터 변경 X

		const 자료형* 변수이름 = 데이터;

	 2. 포인터 변수 내부의 주소값 변경 X
		주소값을 역참조하여 해당 위치의 데이터 변경 가능

		자료형* const 변수이름 = 데이터;

		* 주소값과 해당 위치의 데이터 전체를 변경 X
			
			const 자료형* const 변수이름 = 데이터;
*/

	/*
		구조체
		 동일한 자료형의 여러 데이터를 담는 배열과 다르게
		 여러가지 자료형의 여러 데이터를 담을 수 있는 자료형을 의미
		  > 여러 자료형의 변수가 묶인 구조

		구조체 생성

			struct <구조체 이름>{
				<자료형> <변수이름>;
				<자료형> <배열이름>;
				...
			};

		구조체 사용

			struct <구조체 이름> <변수명>;		// 생성해 놓은 구조체를 하나의 자료형으로 사용
	*/

//struct test1 {
//	int a;			//	test1
//	double b;		//		| int a | double b |
//};
//
//typedef struct test1 T1;		// 이름 정의 - typedef <정의할 내용> <이름>;
//
//
//int main() {
//
//	struct test1 tA =	{ 1,2.2222};
//	//	tA
//	//	  | 1 | 2.2222 |
//
//	T1 tB = { 2,1.111 };
//	//	tB
//	//	  |  2  | 1.111 |
//
//}

/*
	구조체 멤버 필드 사용

	 구조체이름.멤버필드명
*/

//typedef struct test2 {		// 구조체 선언과 동시에 이름 정의
//	char name[20];
//	int age;
//}Person;

//int main() {
//
//	Person manA = { "none",0 };
//	//	manA
//	//		|  none  |  0  |
//	//		 char[20]  int
//
//	// manA = { "김기태",32 };	// error code : 배열처럼 여러 데이터를 한번에 넣는건 선언과 동시에만 가능
//
//	strcpy_s(manA.name, sizeof(manA.name), "김기태");
//	manA.age = 32;
//
//	printf("이름 : %s\n나이 : %d 세\n", manA.name, manA.age);
//
//	Person manB = manA;
//	printf("%s - %d\n", manB.name, manB.age);
//
//	printf("manA size : %d byte\n", sizeof(manA));
//}

/*
	구조체 배열
	 구조체들을 이용한 배열 생성 가능
*/

//int main() {
//
//	Person arr[2] = { "케이지",22,"아이티",33 };
//	int arrLen = sizeof(arr) / sizeof(Person);
//
//	for (int i = 0; i < arrLen; i++)
//		printf("%s - %d\n", arr[i].name, arr[i].age);
//
//	// arr
//	//		| 케이지 | 22 | 아이티 | 33 |
//	//		[0]				[1]
//}

/*
	구조체 중첩
	 구조체 내부의 멤버 필드로 다른 구조체 사용 가능
*/

//typedef struct member {		// member
//	char id[10];			//		|  id	|  basic	|
//	Person basic;			//				| name | age|
//}Mem;

//int main() {
//	Mem memA = { "A-001","김기태",32 };
//	//  member
//	//		|  A-001  |    basic	|
//	//				  | 김기태 | 32 |

//	printf("ID\t : %s\n", memA.id);
//	printf("이름\t : %s\n", memA.basic.name);
//	printf("나이\t : %d\n", memA.basic.age);
//}

/*
	구조체 포인터를 사용한 멤버 필드 접근
	 포인트변수명->멤버필드명
	 (*포인터변수명).멤버필드명
*/

//int main() {

//	Person user1 = { "김기태",32 };
//	Person* p = &user1;

//	printf("이름 : %s %s %s\n", user1.name, p->name, (*p).name);
//	printf("나이 : %d %d %d\n", user1.age, p->age, (*p).age);
//}

/*
	메모리 구조
	 높은주소	stack 영역	: 지역변수,매개변수들을 저장
				heap 영역	: 동적할당 영역
				data 영역	: 전역변수, static변수, 문자열 등이 저장
	 낮은주소	code 영역	: 실행할 프로그램의 코드가 들어있는 영역


	정적할당
	 compile 과정에서 할당된 메모리의 크기 결정
	 > 프로그램이 만들어 질때 메모리의 크기가 결정

	 프로그램이 실행될 때 정해진 메모리 공간이 해당 프로그램에 할당
	 프로그램이 종료될 때 할당된 메모리 공간이 전부 반환

	 할당 받는 메모리 공간이 정해져 있는 개념이라 조절 불가능
	 stack 영역에 할당되기 때문에 동적 할당에 비해 최대 사용 가능한 메모리 공간이 더 적다

	동적할당
	 프로그램 구동 중에 메모리의 크기 결정
	  > 프로그램이 동작하면서 메모리의 크기가 유동적으로 변한다

	 프로그램이 동작하면서 동적 할당 코드를 만나면 메모리 공간 추가 사용
	 할당이 해제되면서 해당 공간 반환

	 할당 해제를 하지 않으면 프로그램이 종료될 때 까지 메모리 공간을 계속 사용
	  > 동적할당된 공간이 많아지게 되면 프로그램이 종료되기 전까지 점유중인 메모리 공간이 계속 늘어난다

	 동적할당 사용 방식(동적할당 함수는 stdlib.h 에 포함되어 있다)
	  할당
			포인터변수 = (자료형)malloc(크기)

	  할당 해제
			free(포인터변수)
*/

//typedef struct person{
//	char name[20];
//	int age;
//}Person;

//int main() {
	
	//int* p = (int*)malloc(sizeof(int));		// 포인터 변수 p에 4byte 공간의 시작 주소값 입력
	//printf("동적할당된 공간 주소 : %p\n", p);

	//*p = 10;
	//printf("동적할당된 공간 내부 데이터 : %d\n", *p);

	//free(p);

	//int* iar = (int*)malloc(sizeof(int) * 5);
	//for (int i = 0; i < 5; i++) {
	//	int val;
	//	printf("%d번 인덱스 입력 : ",i);
	//	scanf_s("%d", &val);
	//	iar[i] = val;
	//}
	//puts("");
	//printf("배열 내부 데이터 : ");
	//for (int i = 0; i < 5; i++)
	//	printf("%d ", iar[i]);
	//puts("");

	//free(iar);

	//Person* sp = (Person*)malloc(sizeof(Person));
	//strcpy_s(sp->name, sizeof(sp->name), "김기태");
	//sp->age = 32;
	////strcpy_s((*sp).name, sizeof((*sp).name), "김기태");
	//// (*sp).age = 32;

	//printf("이름 : %s\n나이 : %d\n", sp->name, (*sp).age);

	//free(sp);

//}

//typedef struct {
//	char name[30];
//	char writer[20];
//	int price;
//}Book;

//int main() {

//	Book bookA;
//	printf("도서명 입력\t: ");	
//	gets_s(bookA.name,sizeof(bookA.name));
//	printf("저자 입력\t: ");
//	gets_s(bookA.writer, sizeof(bookA.writer));
//	printf("가격 입력\t: ");
//	scanf_s("%d", &bookA.price);
//	puts("");

//	printf("제목 : %s\n저자 : %s\n가격 : %d원\n", bookA.name, bookA.writer, bookA.price);
//}