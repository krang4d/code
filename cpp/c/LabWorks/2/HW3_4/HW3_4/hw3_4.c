//c=(5/9)(f-32)): 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	double t;
	char s;

	system("chcp 1251 > nul");

	printf("������� ����������� � ����������� �����\n"
		"(f - ����� ����������, c - ����� �������: ");

	scanf("%lg %c", &t,&s)==2 
	  ? (  toupper(s)=='F' ? printf("%lgF = %lgC\n", t, (5./9.)*(t-32))
		 : toupper(s)=='C' ? printf("%lgC = %lgF\n",t,(9./5.)*t+32)
		 : printf("������ � ������ - ������� ������� �����\n")
	    ) 
	  : printf("������ � ������ - ���� ������� ����� � ������� �����\n");

	system("pause");
}

