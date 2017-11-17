#include <iostream>
#include <fstream>
#include <vector>
#include "Shape.h"
#include "CAD.h"

CAD::CAD() {}

CAD::~CAD() {
    for(int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}

void CAD::add(Shape* s) {
    shapes.push_back(s);
}

void CAD::write(const char filename[]) {
    std::fstream file(filename, std::ios::out);
    if(file.is_open()) {
        file << "solid my3D" << '\n';
        for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->write(file);
        }
            file << "endsolid my3D" << '\n';
            file.close();
    } else {
        std::cout << "Open file fail!" << std::endl;
    }
}
