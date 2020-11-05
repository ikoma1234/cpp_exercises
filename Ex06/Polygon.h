#include "Shape2D.h"

class Polygon : public Shape2D {
public:
    std::string get_name() const override;
    float compute_area() const override;
    void translate(float, float) override;
    Polygon(Point2D*[], int);
    ~Polygon();

private:
    Point2D* _point[4];
    int _size;
};