#include "CAD.h"
#include "Shape.h"
#include "Cube.h"
#include "Cylinder.h"


using namespace std;
int main() {
    //main function are copied from 05STLwriterHW.cc
    CAD c;
    c.add(new Cube(0,0,0,   5));
    c.add(new Cylinder(100,0,0,    3, 10, 10));
    c.write("test.stl");
}
