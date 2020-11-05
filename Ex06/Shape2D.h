#ifndef SHAPE2D_H
#define SHAPE2D_H
#include <string>
#include <iostream>

using namespace std;

class Shape2D {
public:
    virtual string get_name() const = 0;
    virtual float compute_area() const = 0;
    virtual void translate(float, float) = 0;
    virtual ~Shape2D() { cout << "~Shape2D()" << endl; };
};
#endif

#ifndef POINT2D_H
#define POINT2D_H

struct Point2D {
    float _px;
    float _py;

    Point2D(float px, float py) : _px(px), _py(py) {
        std::cout << "Point2D()" << std::endl;
    }
    ~Point2D() {
        std::cout << "~Point2D()" << std::endl;
    }
};

#endif