#ifndef MAT4X4_H
#define MAT4X4_H
#include <iostream>

template<class T, int N>
class Mat4x4 {
public:
    Mat4x4() {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i == j) array[i][j] = 1.0;
                else array[i][j] = 0.0;
            }
        }
    }

    Mat4x4(T matrix[N][N]) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                array[i][j] = matrix[i][j];
            }
        }
    }

    Mat4x4(const Mat4x4& obj) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                array[i][j] = obj.array[i][j];
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