
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	//�������� ����������
	int ch;
	double d;
	int x;

	//����������� ����������
	system("chcp 1251 > nul");

	printf("Hello, world!\n\n"); 
	printf("� ����� �����!\n");
/*
	ch = getchar();	putchar(ch);
	ch = getchar();	putchar(ch);
	ch = getchar();	putchar(ch);
	ch = getchar();	putchar(ch);
	ch = getchar();	putchar(ch);
*/
/*
	ch = 15;
	printf("%d\t%u\t%#o\t%#x\t%#X\n",ch,ch,ch,ch,ch);
	ch = 16;
	printf("%d\t%u\t%#o\t%#x\t%#X\n",ch,ch,ch,ch,ch);
	ch = -1;
	printf("%d\t%u\t%#o\t%#x\t%#X\n",ch,ch,ch,ch,ch);
*/

	d = 123.456789;
	printf("%20f %20e %20g\n",d,d,d);
	d = 123.456789E6;
	printf("%20f %20e %20g\n",d,d,d);
	d = 123.456789E-6;
	printf("%20f %20e %20g\n",d,d,d);

	d = 123.456789;
	printf("%20.3f %20.3e %20.3g\n",d,d,d);
	d = 123.456789E6;
	printf("%20.3f %20.3e %20.3g\n",d,d,d);
	d = 123.456789E-6;
	printf("%20.3f %20.3e %20.3g\n",d,d,d);

	ch = '*';
	printf("%c %d %#x %s\n", ch,ch,ch,"- ��� \"���������\"");

	printf("%02d.%02d.%4d\n", 2,1,2012);

	//=============================================

//	scanf("(%3d)%3d-%2d-%2d",&t1,&t2,&t3,&t4);

	system("pause");
	system("cls");
/*
	printf("������� ����� �����: ");
	scanf("%d  ",&ch);
	printf("%d\n",ch);
*/
	srand((unsigned)time(NULL));rand();rand();

	x = rand() % 20 + 1;
	printf("%d\n", x);
	x = rand() % 20 + 1;
	printf("%d\n", x);
	x = rand() % 20 + 1;
	printf("%d\n", x);
	x = rand() % 20 + 1;
	printf("%d\n", x);
	x = rand() % 20 + 1;
	printf("%d\n", x);

	system("pause");
}