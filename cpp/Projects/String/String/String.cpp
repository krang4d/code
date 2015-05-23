#include<iostream>
#include<cstring>
#include"String.h"
using namespace std;

String operator+(const String &lh, const String &rh)
{
	String t = lh;
	return t += rh;
}

String & String::operator+=(const String &str)
{
	char *t = new char[n + str.n + 1];
	//здесь д.б. обработка ошибок
	strcpy(t, s);
	strcat(t, str.s);
	delete[] s;
	s = t; n += str.n;
	return *this;
}

String & String::operator=(const String &str)
{
	if(this == &str)	//защита от самоприсваивания
		return *this;
	delete[] s;
	n = str.n;
	s = new char[n + 1];
	//здесь д.б. обработка ошибок
	strcpy(s, str.s);
	return *this;
}

String::String(const String &str)
{
	n = str.n;
	s = new char[n + 1];
	//здесь д.б. обработка ошибок
	strcpy(s, str.s);
}

String::String(const char *str)
{
	n = strlen(str);
	s = new char[n + 1];
	//здесь д.б. обработка ошибок
	strcpy(s, str);
}

String::~String()
{
	delete[] s;
}

void String::Print() const
{
	cout << s;
}
