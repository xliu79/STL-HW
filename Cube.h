#pragma once
#include <fstream>
#include "Shape.h"
#include "Vec.h"
class Cube: public Shape {
private:
    double size;
public:
    Cube(double x, double y, double z, double size = 0);
    ~Cube();
    Cube(const Cube& orig);
    Cube& operator =(const Cube& orig);
    void write(std::fstream& file) const;
};
