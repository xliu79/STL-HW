#include <fstream>
#include "Cube.h"
#include "Shape.h"
#include <vector>
#include "Vec.h"
#include <stdio.h>

Cube::Cube(double x, double y, double z, double size): Shape(x, y, z), size(size) {
}

Cube::~Cube() {}

Cube::Cube(const Cube& orig): size(orig.size), Shape(orig) {}

Cube& Cube::operator =(const Cube& orig) {
    (*((Shape*)this)) = (const Shape&)orig;
    size = orig.size;
}


void Cube::write(std::fstream& file) const {
    std::vector<Vec> data(8);
    Vec ex(1, 0, 0);
    Vec ey(0, 1, 0);
    Vec ez(0, 0, 1);
    data[0] = Vec(x, y, z);
    data[1] = size * (ex) + data[0];
    data[2] = size * (ex + ey) + data[0];
    data[3] = size * (ey) + data[0];
    data[4] = size * (ez) + data[0];
    data[5] = size * (ex + ez) + data[0];
    data[6] = size * (ex + ey + ez) + data[0];
    data[7] = size * (ey + ez) + data[0];

    writeRec(file, data[0], data[1], data[2], data[3]);
    writeRec(file, data[4], data[5], data[6], data[7]);

    writeRec(file, data[0], data[1], data[5], data[4]);
    writeRec(file, data[3], data[2], data[6], data[7]);

    writeRec(file, data[0], data[4], data[7], data[3]);
    writeRec(file, data[1], data[5], data[6], data[2]);
}
