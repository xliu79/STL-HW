#pragma once
#include <fstream>
#include "Shape.h"
#include <vector>

class Cylinder: public Shape {
private:
    double r, h;
    int facets;
    std::vector<Vec*> generatePoints() const;
public:
    Cylinder(double x, double y, double z, double r = 0, double h = 0, int facets = 10);
    ~Cylinder();
    Cylinder(const Cylinder& orig);
    Cylinder& operator =(const Cylinder& orig);
    void write(std::fstream& file) const;
};
