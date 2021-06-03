#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	������ �������� const ��� ��� ���
	 �� ���� ������� ��� ����
	 1. ������ ���� ������ �ּҰ� ���� ����
		�ּҰ��� �������Ͽ� �ش� ��ġ�� ������ ���� X

		const �ڷ���* �����̸� = ������;

	 2. ������ ���� ������ �ּҰ� ���� X
		�ּҰ��� �������Ͽ� �ش� ��ġ�� ������ ���� ����

		�ڷ���* const �����̸� = ������;

		* �ּҰ��� �ش� ��ġ�� ������ ��ü�� ���� X
			
			const �ڷ���* const �����̸� = ������;
*/

	/*
		����ü
		 ������ �ڷ����� ���� �����͸� ��� �迭�� �ٸ���
		 �������� �ڷ����� ���� �����͸� ���� �� �ִ� �ڷ����� �ǹ�
		  > ���� �ڷ����� ������ ���� ����

		����ü ����

			struct <����ü �̸�>{
				<�ڷ���> <�����̸�>;
				<�ڷ���> <�迭�̸�>;
				...
			};

		����ü ���

			struct <����ü �̸�> <������>;		// ������ ���� ����ü�� �ϳ��� �ڷ������� ���
	*/

//struct test1 {
//	int a;			//	test1
//	double b;		//		| int a | double b |
//};
//
//typedef struct test1 T1;		// �̸� ���� - typedef <������ ����> <�̸�>;
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
	����ü ��� �ʵ� ���

	 ����ü�̸�.����ʵ��
*/

//typedef struct test2 {		// ����ü ����� ���ÿ� �̸� ����
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
//	// manA = { "�����",32 };	// error code : �迭ó�� ���� �����͸� �ѹ��� �ִ°� ����� ���ÿ��� ����
//
//	strcpy_s(manA.name, sizeof(manA.name), "�����");
//	manA.age = 32;
//
//	printf("�̸� : %s\n���� : %d ��\n", manA.name, manA.age);
//
//	Person manB = manA;
//	printf("%s - %d\n", manB.name, manB.age);
//
//	printf("manA size : %d byte\n", sizeof(manA));
//}

/*
	����ü �迭
	 ����ü���� �̿��� �迭 ���� ����
*/

//int main() {
//
//	Person arr[2] = { "������",22,"����Ƽ",33 };
//	int arrLen = sizeof(arr) / sizeof(Person);
//
//	for (int i = 0; i < arrLen; i++)
//		printf("%s - %d\n", arr[i].name, arr[i].age);
//
//	// arr
//	//		| ������ | 22 | ����Ƽ | 33 |
//	//		[0]				[1]
//}

/*
	����ü ��ø
	 ����ü ������ ��� �ʵ�� �ٸ� ����ü ��� ����
*/

//typedef struct member {		// member
//	char id[10];			//		|  id	|  basic	|
//	Person basic;			//				| name | age|
//}Mem;

//int main() {
//	Mem memA = { "A-001","�����",32 };
//	//  member
//	//		|  A-001  |    basic	|
//	//				  | ����� | 32 |

//	printf("ID\t : %s\n", memA.id);
//	printf("�̸�\t : %s\n", memA.basic.name);
//	printf("����\t : %d\n", memA.basic.age);
//}

/*
	����ü �����͸� ����� ��� �ʵ� ����
	 ����Ʈ������->����ʵ��
	 (*�����ͺ�����).����ʵ��
*/

//int main() {

//	Person user1 = { "�����",32 };
//	Person* p = &user1;

//	printf("�̸� : %s %s %s\n", user1.name, p->name, (*p).name);
//	printf("���� : %d %d %d\n", user1.age, p->age, (*p).age);
//}

/*
	�޸� ����
	 �����ּ�	stack ����	: ��������,�Ű��������� ����
				heap ����	: �����Ҵ� ����
				data ����	: ��������, static����, ���ڿ� ���� ����
	 �����ּ�	code ����	: ������ ���α׷��� �ڵ尡 ����ִ� ����


	�����Ҵ�
	 compile �������� �Ҵ�� �޸��� ũ�� ����
	 > ���α׷��� ����� ���� �޸��� ũ�Ⱑ ����

	 ���α׷��� ����� �� ������ �޸� ������ �ش� ���α׷��� �Ҵ�
	 ���α׷��� ����� �� �Ҵ�� �޸� ������ ���� ��ȯ

	 �Ҵ� �޴� �޸� ������ ������ �ִ� �����̶� ���� �Ұ���
	 stack ������ �Ҵ�Ǳ� ������ ���� �Ҵ翡 ���� �ִ� ��� ������ �޸� ������ �� ����

	�����Ҵ�
	 ���α׷� ���� �߿� �޸��� ũ�� ����
	  > ���α׷��� �����ϸ鼭 �޸��� ũ�Ⱑ ���������� ���Ѵ�

	 ���α׷��� �����ϸ鼭 ���� �Ҵ� �ڵ带 ������ �޸� ���� �߰� ���
	 �Ҵ��� �����Ǹ鼭 �ش� ���� ��ȯ

	 �Ҵ� ������ ���� ������ ���α׷��� ����� �� ���� �޸� ������ ��� ���
	  > �����Ҵ�� ������ �������� �Ǹ� ���α׷��� ����Ǳ� ������ �������� �޸� ������ ��� �þ��

	 �����Ҵ� ��� ���(�����Ҵ� �Լ��� stdlib.h �� ���ԵǾ� �ִ�)
	  �Ҵ�
			�����ͺ��� = (�ڷ���)malloc(ũ��)

	  �Ҵ� ����
			free(�����ͺ���)
*/

//typedef struct person{
//	char name[20];
//	int age;
//}Person;

//int main() {
	
	//int* p = (int*)malloc(sizeof(int));		// ������ ���� p�� 4byte ������ ���� �ּҰ� �Է�
	//printf("�����Ҵ�� ���� �ּ� : %p\n", p);

	//*p = 10;
	//printf("�����Ҵ�� ���� ���� ������ : %d\n", *p);

	//free(p);

	//int* iar = (int*)malloc(sizeof(int) * 5);
	//for (int i = 0; i < 5; i++) {
	//	int val;
	//	printf("%d�� �ε��� �Է� : ",i);
	//	scanf_s("%d", &val);
	//	iar[i] = val;
	//}
	//puts("");
	//printf("�迭 ���� ������ : ");
	//for (int i = 0; i < 5; i++)
	//	printf("%d ", iar[i]);
	//puts("");

	//free(iar);

	//Person* sp = (Person*)malloc(sizeof(Person));
	//strcpy_s(sp->name, sizeof(sp->name), "�����");
	//sp->age = 32;
	////strcpy_s((*sp).name, sizeof((*sp).name), "�����");
	//// (*sp).age = 32;

	//printf("�̸� : %s\n���� : %d\n", sp->name, (*sp).age);

	//free(sp);

//}

//typedef struct {
//	char name[30];
//	char writer[20];
//	int price;
//}Book;

//int main() {

//	Book bookA;
//	printf("������ �Է�\t: ");	
//	gets_s(bookA.name,sizeof(bookA.name));
//	printf("���� �Է�\t: ");
//	gets_s(bookA.writer, sizeof(bookA.writer));
//	printf("���� �Է�\t: ");
//	scanf_s("%d", &bookA.price);
//	puts("");

//	printf("���� : %s\n���� : %s\n���� : %d��\n", bookA.name, bookA.writer, bookA.price);
//}