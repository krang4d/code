#ifndef STRING_H
#define STRING_H

class String
{
public:
	String & operator+=(const String &);
	String & operator=(const String &);
	String(const String &);
	String(const char *str = "");
	~String();

	int Len() const { return n; }
	void Print() const;
private:
	char *s;
	int n;
};

String operator+(const String &, const String &);

#endif