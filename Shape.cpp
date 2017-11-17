#include "Vec.h"
#include "Shape.h"

Shape::Shape(double x, double y, double z): x(x), y(y), z(z){}
Shape::~Shape() {}
Shape::Shape(const Shape& orig) {
    x = orig.x;
    y = orig.y;
    z = orig.z;
}
Shape& Shape::operator =(const Shape& orig) {
    x = orig.x;
    y = orig.y;
    z = orig.z;
    return *this;
}
void Shape::writeTra(std::fstream& file, const Vec& a,
const Vec& b, const Vec& c) const {
    char current[30];
    file << "facet normal 0 0 0\n";
    file << "outer loop\n";
    sprintf(current, "vertex %f %f %f\n", a.x, a.y, a.z);
    file << current;
    sprintf(current, "vertex %f %f %f\n", b.x, b.y, b.z);
    file << current;
    sprintf(current, "vertex %f %f %f\n", c.x, c.y, c.z);
    file << current;
    file << "endloop\n";
    file << "endfacet\n";
}
void Shape::writeRec(std::fstream& file, const Vec& a,
const Vec& b, const Vec& c, const Vec& d) const{
    writeTra(file, a, b, c);
    writeTra(file, c, d, a);
}
