#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 2, b = 5;
	int y;

	system("chcp 1251 > nul");

	printf("������� ��� ��������� 2 ����� �����: ");
	scanf("%d %d", &a,&b);

	printf("%d %c %d\n", 
			 a, 
			   a>b ? '>' : a<b ? '<' : '=', 
			       b);

	printf("\n������� ���: ");
	scanf("%4d", &y);

	printf("� ���� %d %d ����\n", y,
		365 + (y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0 ) )
		);

	system("pause");
}

double f, c, a;
char s;
scanf("%lg %c", &a,&s);