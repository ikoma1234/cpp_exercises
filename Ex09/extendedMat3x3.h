#ifndef MAT3X3_H
#define MAT3X3_H
#include <iostream>

using namespace std;

template<class T, int N>
class Mat3x3 {
public:
    Mat3x3() {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(i==j) _array[i][j] = 1.0;
                else _array[i][j] = 0.0;
            }
        }
    }
    
    Mat3x3(T matrix[N][N]) {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                _array[i][j] = matrix[i][j];
            }
        }
    }
    
    Mat3x3(const Mat3x3& object) {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                _array[i][j] = object._array[i][j];
            }
        }
    }
    
    ~Mat3x3() {}

    Mat3x3& operator=(const Mat3x3& object) {
        int i,j;

        if(this != &object) {
            for(i=0; i<N; i++){
                for(j=0; j<N; j++){
                    _array[i][j] = object._array[i][j];
                }
            }
        }    
        return *this;
    }
    
    Mat3x3 operator+(const Mat3x3& object) {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                _array[i][j] += object._array[i][j];
            }
        }
        return *this;
    }

    Mat3x3 operator-() const {
        int i,j;
        Mat3x3 res;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                res._array[i][j] = -(this->_array[i][j]);
            }
        }
        return res;
    }
    
    Mat3x3 operator*(const Mat3x3& object) {
        int i,j,k;
        Mat3x3 temparray;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                temparray._array[i][j] = 0.0;
                for(k=0; k<3; k++){
                    temparray._array[i][j] += _array[i][k]*object._array[k][j];
                }
            }
        }
        return temparray;
    }
    
    Mat3x3& operator+=(const Mat3x3& object) {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                _array[i][j] += object._array[i][j];
            }
        }
        return *this;
    }

    Mat3x3& operator-=(const Mat3x3& object) {
        *this += -object;
        return *this;
    }
    
    Mat3x3& operator*=(const Mat3x3& object) {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                _array[i][j] *= object._array[i][j];
            }
        }
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const Mat3x3& object) {
        int i,j;

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                os << object._array[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    
    T operator()(int i, int j) const {
        return _array[i][j];
    }
    
    bool operator==(const Mat3x3& object) const {
        int i,j; 

        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(_array[i][j]!=object._array[i][j]) return false;
            }
        }
        return true;
    }

private:
    T _array[N][N];
};

#endif