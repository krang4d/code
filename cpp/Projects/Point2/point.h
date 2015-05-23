#ifndef POINT_H
#define POINT_H


class Point
{
public:
    int x, y;
    void Print() const;

    Point(const Point &);   //конструктор копии
    Point();                //конструктор по умолчанию
//  explicit                //запрет на неявное преобразование
    Point(int);             //конструктор преобразования
    Point(int, int);        //параметрический конструктор
//  Point(int=0, int=0);    //3и в 1ом конструктор

    ~Point();
};

#endif // POINT_H
