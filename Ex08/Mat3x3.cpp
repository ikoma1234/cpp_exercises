#include "Mat3x3.h"
#include <iostream>

using namespace std;

Mat3x3::Mat3x3() {
    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(i==j) _array[i][j] = 1.0;
            else _array[i][j] = 0.0;
        }
    }
}

Mat3x3::Mat3x3(double matrix[3][3]) {
    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            _array[i][j] = matrix[i][j];
        }
    }
}

Mat3x3::Mat3x3(const Mat3x3& object) {
    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            _array[i][j] = object._array[i][j];
        }
    }
}

Mat3x3& Mat3x3::operator=(const Mat3x3& object) {
    int i,j;

    if(this!=&object) {
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                _array[i][j] = object._array[i][j];
            }
        }
    }
    return *this;
}

Mat3x3 Mat3x3::operator+(const Mat3x3& object) {
    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            _array[i][j] += object._array[i][j];
        }
    }
    return *this;
}

Mat3x3 Mat3x3::operator-() const {
    int i,j;
    Mat3x3 res;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            res._array[i][j] = -(this->_array[i][j]);
        }
    }
    return res;
}

Mat3x3 Mat3x3::operator*(const Mat3x3& object) {
    int i,j,k;
    Mat3x3 tmparray;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            tmparray._array[i][j] = 0.0;
            for(k=0; k<3; k++){
                tmparray._array[i][j] += _array[i][k]*object._array[k][j];
            }
        }
    }
    return tmparray;
}

Mat3x3& Mat3x3::operator+=(const Mat3x3& object) {
    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            _array[i][j] += object._array[i][j];
        }
    }
    return *this;
}

Mat3x3& Mat3x3::operator-=(const Mat3x3& object) {
    *this += -object;
    return *this;
}

Mat3x3& Mat3x3::operator*=(const Mat3x3& object) {
    int i,j;
    
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            _array[i][j] *= object._array[i][j];
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, const Mat3x3& object) {
    int i,j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            os << object._array[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

double Mat3x3::operator()(int i, int j) const {
    return _array[i][j];
}

bool Mat3x3::operator==(const Mat3x3& object) const {
    int i,j;
    
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(_array[i][j] != object._array[i][j]) return false;
        }
    }
    return true;
}

Mat3x3::~Mat3x3() {}