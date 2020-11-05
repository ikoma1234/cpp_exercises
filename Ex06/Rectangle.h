#include "Shape2D.h"

class Rectangle : public Shape2D {
public:
    string get_name() const override;
    float compute_area() const override;
    void translate(float, float) override;
    Rectangle(const Point2D&, float, float);
    ~Rectangle();
    
private:
    Point2D _point;
    float _width;
    float _height;
};