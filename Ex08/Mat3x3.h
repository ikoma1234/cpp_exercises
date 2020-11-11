#ifndef MAT3X3_H
#define MAT3X3_H
#include <iostream>

using namespace std;

class Mat3x3 {
public:
    Mat3x3();
    Mat3x3(double [3][3]);
    Mat3x3(const Mat3x3&);
    
    Mat3x3& operator=(const Mat3x3&);

    Mat3x3 operator+(const Mat3x3&);
    Mat3x3 operator-() const;
    Mat3x3 operator*(const Mat3x3&);
    
    Mat3x3& operator+=(const Mat3x3&);
    Mat3x3& operator-=(const Mat3x3&);
    Mat3x3& operator*=(const Mat3x3&);
    
    friend ostream& operator<<(ostream&, const Mat3x3&);
    
    double operator()(int, int) const;
    
    bool operator==(const Mat3x3&) const;
    
    ~Mat3x3();

private:
    double _array[3][3];
};


#endif
