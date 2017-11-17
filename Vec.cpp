#include "Vec.h"
#include <iostream>
#include <cmath>

Vec::Vec(double x, double y, double z):
x(x), y(y), z(z){}
Vec::~Vec() {}
Vec::Vec(const Vec& orig): x(orig.x), y(orig.y), z(orig.z) {}
Vec& Vec::operator =(const Vec& orig) {
    x = orig.x;
    y = orig.y;
    z = orig.z;
    return *this;
}
Vec operator +(const Vec& a, const Vec& b) {
    Vec ans(a.x + b.x, a.y + b.y, a.z + b.z);
    return ans;
}
Vec operator -(const Vec& a, const Vec& b) {
    Vec ans(a.x - b.x, a.y - b.y, a.z - b.z);
    return ans;
}
double operator *(const Vec& a, const Vec& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vec operator *(double lambda, const Vec& a) {
    Vec ans(lambda * a.x, lambda * a.y, lambda * a.z);
    return ans;
}
Vec operator *(const Vec& a, double lambda) {
    Vec ans(lambda * a.x, lambda * a.y, lambda * a.z);
    return ans;
}
std::ostream& operator <<(std::ostream& os, const Vec& a) {
    os << '(';
    os << a.x << ',';
    os << a.y << ',';
    os << a.z;
    os << ')';
    os << '\n';
    return os;
}
