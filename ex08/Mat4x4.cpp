#include "Mat4x4.h"
#include <iostream>

Mat4x4::Mat4x4() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j) _array[i][j] = 1.0;
            else _array[i][j] = 0.0;
        }
    }
}

Mat4x4::Mat4x4(double n[4][4]) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            _array[i][j] = n[i][j];
        }
    }
}

Mat4x4::Mat4x4(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            _array[i][j] = obj._array[i][j];
        }
    }
}

Mat4x4& Mat4x4::operator=(const Mat4x4& obj) {
    if(this != &obj) {
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                _array[i][j] = obj._array[i][j];
            }
        }
    }
    return *this;
}

Mat4x4 Mat4x4::operator+(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            _array[i][j] += obj._array[i][j];
        }
    }
    return *this;
}

Mat4x4 Mat4x4::operator-() const {
    Mat4x4 res;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res._array[i][j] = -(this->_array[i][j]);
        }
    }
    return res;
}

Mat4x4 Mat4x4::operator*(const Mat4x4& obj) {
    Mat4x4 temp;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp._array[i][j] = 0.0;
            for(int k = 0; k < 4; k++){
                temp._array[i][j] += _array[i][k]*obj._array[k][j];
            }
        }
    }
    return temp;
}

Mat4x4& Mat4x4::operator+=(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            _array[i][j] += obj._array[i][j];
        }
    }
    return *this;
}

Mat4x4& Mat4x4::operator-=(const Mat4x4& obj) {
    *this += -obj;
    return *this;
}

Mat4x4& Mat4x4::operator*=(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            _array[i][j] *= obj._array[i][j];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            os << obj._array[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

double Mat4x4::operator()(int i, int j) const {
    return _array[i][j];
}

bool Mat4x4::operator==(const Mat4x4& obj) const {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(_array[i][j] != obj._array[i][j]) return false;
        }
    }
    return true;
}

Mat4x4::~Mat4x4() {

}
