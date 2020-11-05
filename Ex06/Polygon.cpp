#include "lib.h"
#include "Polygon.h"

Polygon::Polygon(Point2D* p[], int size) : _size(size) {
    for(int i = 0; i < _size; i++){
        _point[i]->_px = p[i]->_px;
        _point[i]->_py = p[i]->_py;
    }
    std::cout << "Polygon()" << std::endl;
}

Polygon::~Polygon() {
    std::cout << "~Polygon()" << std::endl;
}

std::string Polygon::get_name() const {
    return "Polygon";
}

float Polygon::compute_area() const {
    float area = 0;
    for (int i = 0; i < _size-1; i++) {
        area += (_point[i]->_px)*(_point[i+1]->_py) - (_point[i]->_py)*(_point[i+1]->_px);
    }
    return area;
}

void Polygon::translate(float tx, float ty) {
    for (int i = 0; i < _size; i++) {
        _point[i]->_px += tx;
        _point[i]->_py += ty;
    }
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