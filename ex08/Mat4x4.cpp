#include "Mat4x4.h"
#include <iostream>


Mat4x4::Mat4x4() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j) array[i][j] = 1.0;
            else array[i][j] = 0.0;
        }
    }
}

Mat4x4::Mat4x4(double n[4][4]) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            array[i][j] = n[i][j];
        }
    }
}

Mat4x4::Mat4x4(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            array[i][j] = obj.array[i][j];
        }
    }
}

Mat4x4& Mat4x4::operator=(const Mat4x4& obj) {
    if(this != &obj) {
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                array[i][j] = obj.array[i][j];
            }
        }
    }
    return *this;
}

Mat4x4 Mat4x4::operator+(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            array[i][j] += obj.array[i][j];
        }
    }
    return *this;
}

Mat4x4 Mat4x4::operator-() const {
    Mat4x4 res;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(array[i][j]!=0){
            res.array[i][j] = -(this->array[i][j]);
            }
        }
    }
    return res;
}

Mat4x4 Mat4x4::operator*(const Mat4x4& obj) {
    Mat4x4 temp;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp.array[i][j] = 0.0;
            for(int k = 0; k < 4; k++){
                temp.array[i][j] += array[i][k]*obj.array[k][j];
            }
        }
    }
    return temp;
}

Mat4x4& Mat4x4::operator+=(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            array[i][j] += obj.array[i][j];
        }
    }
    return *this;
}

Mat4x4& Mat4x4::operator-=(const Mat4x4& obj) {
    for( int i=0 ; i < 4; ++i){
        for(int j=0; j< 4; ++j){
            array[i][j]=array[i][j]-obj.array[i][j];
        }
    }
    return *this;
}

Mat4x4& Mat4x4::operator*=(const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            array[i][j] *= obj.array[i][j];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Mat4x4& obj) {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            os << obj.array[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

double Mat4x4::operator()(int i, int j) const {
    return array[i][j];
}

bool Mat4x4::operator==(const Mat4x4& obj) const {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(array[i][j] != obj.array[i][j]) return false;
        }
    }
    return true;
}

Mat4x4::~Mat4x4() {

}