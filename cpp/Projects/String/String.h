#ifndef STRING_H
#define STRING_H

class String
{
public:
        friend std::ostream & operator<<(std::ostream &, const String &);
        char & operator[](int);
        const char & operator[](int) const;
        friend bool operator>(const String &, const String &);
        friend bool operator==(const String &, const String &);
        String & operator+=(const String &);
        String & operator=(const String &);     //перегрузка функции оператора присваивания
        String(const String &);
        String(const char *str = "");
        ~String();

        int Len() const { return n; }
        void Print() const;

private:
        char *s;
        int n;
};

std::istream & operator>>(std::istream &, String &);

bool operator>=(const String &lh, const String &rh);
bool operator<=(const String &lh, const String &rh);
bool operator<(const String &lh, const String &rh);
bool operator!=(const String &, const String &);
String operator+(const String &, const String &);

#endif // STRING_H

