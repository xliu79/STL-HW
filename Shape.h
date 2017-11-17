#pragma once
#include <fstream>
#include "Vec.h"

class Shape {
    /*
    Shape is a abstract class defines behaviors of any Shape.
    Any instance of Shape would have these features:
    1. Original location stored as double x, y, z in Shape's
    protected data.
    2. Private methods that could write a traingle and
    rectangle into given .stl file.
    3. All children of Shape are able to write itself into a
    given .stl file.
    */
protected:
    double x, y, z;
    // Shape::writeTra(...) method is design for writing any
    // triangle into .stl file defined by three points from
    // their location vector.
    void writeTra(std::fstream& file, const Vec& a,
    const Vec& b, const Vec& c) const;

    // Shape::writeRec(...) method is design for writing any
    // triangle into .stl file defined by four points from
    // their location vector. PS: Sequence of these four points
    // are important, which must listed as clockwise or anti-
    // clockwise.
    void writeRec(std::fstream& file, const Vec& a,
    const Vec& b, const Vec& c, const Vec& d) const;
public:
    Shape(double x = 0, double y = 0, double z = 0);
    ~Shape();
    Shape(const Shape& orig);
    Shape& operator =(const Shape& orig);
    virtual void write(std::fstream& file) const = 0;
};
