#ifndef MAT4X4_H
#define MAT4X4_H
#include <iostream>
#include <cmath>
#include <cstring>
#define MAT_SIZE 4

template<class T, int N>
class Mat4x4 {
public:
    Mat4x4() {
    array[0][0] = 1.0;  array[0][1] = 0.0;  array[0][2] = 0.0; array[0][3] = 0.0;
    array[1][0] = 0.0;  array[1][1] = 1.0;  array[1][2] = 0.0; array[1][3] = 0.0;
    array[2][0] = 0.0;  array[2][1] = 0.0;  array[2][2] = 1.0; array[2][3] = 0.0;
    array[3][0] = 0.0;  array[3][1] = 0.0;  array[3][2] = 0.0; array[3][3] = 1.0;
    }

    Mat4x4(const double coefficients[MAT_SIZE][MAT_SIZE]) {
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            array[i][j] = coefficients[i][j];
        }
    }
    }

    ~Mat4x4() {
        std::cout << "Destructor called" << std::endl;
    }

    Mat4x4& operator=(const Mat4x4& o) {
        if(this != &o) {
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    array[i][j] = o.array[i][j];
                }
            }
        }
        return *this;
    }

    Mat4x4 operator+(const Mat4x4& o) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                array[i][j] += o.array[i][j];
            }
        }
        return *this;
    }

    Mat4x4 operator-() const {
        Mat4x4 res;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(array[i][j]!=0){
                res.array[i][j] = -(this->array[i][j]);
            }
            }
        }
        return res;
    }

    Mat4x4 operator*(const Mat4x4& o) {
        Mat4x4 temp;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                temp.array[i][j] = 0.0;
                for(int k = 0; k < 4; k++){
                    temp.array[i][j] += array[i][k]*o.array[k][j];
                }
            }
        }
        return temp;
    }

    Mat4x4& operator+=(const Mat4x4& o) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                array[i][j] += o.array[i][j];
            }
        }
        return *this;
    }

    Mat4x4& operator-=(const Mat4x4& o) {
        *this += -o;
        return *this;
    }

    Mat4x4& operator*=(const Mat4x4& o) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                array[i][j] *= o.array[i][j];
            }
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Mat4x4& o) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                os << o.array[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    T operator()(int i, int j) const {
        return array[i][j];
    }

    bool operator==(const Mat4x4& o) const {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(array[i][j] != o.array[i][j]) return false;
            }
        }
        return true;
    }

private:
    T array[N][N];
};

#endif