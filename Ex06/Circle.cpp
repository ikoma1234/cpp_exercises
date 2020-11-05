#include "lib.h"
#include "Circle.h"

Circle::Circle(const Point2D& p, float rad) : _point(p._px, p._py), _radius(rad) {
    std::cout << "Circle()" << std::endl;
}

Circle::~Circle() {
    std::cout << "~Circle()" << std::endl;
}

std::string Circle::get_name() const {
    return "Circle";
}

float Circle::compute_area() const {
    return Circle::PI*_radius*_radius;
}

void Circle::translate(float tx, float ty) {
    _point._px += tx;
    _point._py += ty;
}

/*
int main(){
    Point2D centre(0.0f, 0.0f);
    Circle* obj = new Circle(centre, 3.0f);
    std::cout << obj->get_name() << std::endl;
    std::cout << obj->compute_area() << std::endl;
    obj->translate(2.0f, 3.0f);

    delete obj;

    return 0;
}
*/