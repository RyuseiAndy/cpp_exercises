#ifndef _COMPUTE_H_
#define _COMPUTE_H_

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

//中央値求める
double compute_median(std::vector<double> c)
{

    //size_t n = c.size() / 2;
    size_t n;

    if (c.size() % 2 == 1) {
        n = c.size() / 2;
        std::nth_element(c.begin(), c.begin() + n, c.end());
        return c[n];

    }
    if (c.size() % 2 == 0) {
        n = c.size() / 2-1;
        
        std::nth_element(c.begin(), c.begin() + n, c.end());
        size_t m =n+1;

        return (c[n]+c[m])/2;

    }

    std::nth_element(c.begin(), c.begin() + n, c.end());
    return c[n];

}

vector<double> compute_k_closest(int k, const vector<double>& n)
{
    auto median = compute_median(n);
    auto tmp = n;
    double result;
    //abs :絶対値求める関数
    auto compare = [median](int lhs, int rhs) {
        auto l = abs(lhs - median);
        auto r = abs(rhs - median);
        return l < r;

    };

    std::nth_element(tmp.begin(), tmp.begin() + n.size() / 2, tmp.end(), compare);


    return tmp;

}

#endif