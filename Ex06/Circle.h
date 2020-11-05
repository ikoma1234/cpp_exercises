#include "Shape2D.h"

class Circle : public Shape2D {
public:
    std::string get_name() const override;
    float compute_area() const override;
    void translate(float, float) override;
    Circle(const Point2D&, float);
    ~Circle();

private:
    const static float constexpr PI = 3.141593f;
    Point2D _point;
    float _radius;
};