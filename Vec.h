#pragma once
#include <iostream>
class Vec {
    /**
    Vec(actually vector in math) class is designed for
    solve these basic vector operation:
    1. vector + vector
    2. vector - vector
    3. vector * number / number * vector (scalar mulitple)
    4. vector * vector(inner product)
    Also, Shape is friend class of Vec leading to a lot
    convient of writting .stl file.
    */
private:
    double x, y, z;
public:
    Vec(double x = 0, double y = 0, double z = 0);
    ~Vec();
    Vec(const Vec& orig);
    Vec& operator =(const Vec& orig);
    double magnitue();
    friend Vec operator +(const Vec& a, const Vec& b);
    friend Vec operator -(const Vec& a, const Vec& b);
    friend double operator *(const Vec& a, const Vec& b);
    friend Vec operator *(double lambda, const Vec& a);
    friend Vec operator *(const Vec& b, double lambda);
    friend std::ostream& operator <<(std::ostream& os, const Vec& a);
    friend class Shape;
};
