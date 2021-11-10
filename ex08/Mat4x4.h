#ifndef MAT4X4_H
#define MAT4X4_H
#include <iostream>

class Mat4x4 {
public:
    Mat4x4();
    Mat4x4(double [4][4]);
    Mat4x4(const Mat4x4&);
    Mat4x4 operator*(const Mat4x4&);
    Mat4x4& operator=(const Mat4x4&);
    Mat4x4 operator+(const Mat4x4&);
    Mat4x4 operator-() const;
    
    ~Mat4x4();
    
    Mat4x4& operator+=(const Mat4x4&);
    Mat4x4& operator-=(const Mat4x4&);
    Mat4x4& operator*=(const Mat4x4&);
    friend std::ostream& operator<<(std::ostream&, const Mat4x4&);
    double operator()(int, int) const;
    bool operator==(const Mat4x4&) const;
    
private:
    double _array[4][4];

};


#endif