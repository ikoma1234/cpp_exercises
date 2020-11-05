#include "lib.h"
#include "Rectangle.h"

Rectangle::Rectangle(const Point2D& p, float w, float h) : _point(p._px, p._py), _width(w), _height(h) {
    std::cout << "Rectangle()"  << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "~Rectangle()" << std::endl;
}

std::string Rectangle::get_name() const {
    return "Rectangle";
}

float Rectangle::compute_area() const {
    return _width*_height;
}

void Rectangle::translate(float tx, float ty) {
    _point._px += tx;
    _point._py += ty;
}

/*
int main(){
    Point2D left_corner(-1.0f, -1.0f);
    //Point2D centre(0.0f, 0.0f);
    //Circle* obj = new Circle(centre, 3.0f);
    Rectangle* obj = new Rectangle(left_corner, 4.0f, 2.0f);
    std::cout << obj->get_name() << std::endl;
    std::cout << obj->compute_area() << std::endl;
    obj->translate(2.0f, 3.0f);
    std::cout << obj->compute_area() << std::endl;
    
    delete obj;

    return 0;
}
*/