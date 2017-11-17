#include <fstream>
#include "Shape.h"
#include "Cylinder.h"
#include "Vec.h"
#include <cmath>
#include <vector>

Cylinder::Cylinder(double x, double y, double z, double r, double h, int facets): Shape(x, y, z),
r(r), h(h), facets(facets) {}

Cylinder::~Cylinder() {}

Cylinder::Cylinder(const Cylinder& orig): Shape(orig), r(orig.r), h(orig.h), facets(orig.facets) {}

Cylinder& Cylinder::operator =(const Cylinder& orig) {}

std::vector<Vec*> Cylinder::generatePoints() const {
    const double Pi=3.14159265358979323846264338328;
    const double dTheta = 2 * Pi / facets;
    std::vector<Vec*> ans(facets);
    for(int i = 0; i < facets; i++) {
        ans[i] = new Vec(r * cos(i * dTheta), r * sin(i * dTheta), 0);
    }
    return ans;
}
void Cylinder::write(std::fstream& file) const {
    std::vector<Vec*> points = generatePoints();
    Vec origin(x, y, z);
    Vec axis(0, 0, h);
    for(int i = 0; i < facets; i++) {
        Vec v1 = origin + *points[i];
        Vec v2 = origin + *points[(i + 1) % facets];
        Vec v3 = v1 + axis;
        Vec v4 = v2 + axis;
        writeTra(file, origin, v1, v2);
        writeTra(file, origin + axis, v3, v4);
        writeRec(file, v1, v2, v4, v3);
    }
}
