#include <fstream>
#include <vector>
#include "Shape.h"

class CAD {
    /**
    This class has two main features.
    1. Store user's Shape
    2. Print those Shapes as .stl file
    */
private:
    std::vector<Shape*> shapes;
public:
    CAD();
    ~CAD();
    void add(Shape* s);
    void write(const char filename[]);
};
