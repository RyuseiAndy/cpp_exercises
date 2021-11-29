#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using std::cout;
using std::endl;

double compute_median(std::vector<double> v) {
    double med = 0;
    int middle;
    if(v.size()%2 == 0) middle = (v.size()/2 + v.size()/2-1)/2;
    else middle = v.size()/2+1;

    std::sort(v.begin(), v.end());

    med = v[middle-1];
    cout << "median = " << med << endl;
    return med;
}

std::vector<int> compute_k_closest(std::vector<double> v, int k) {
    int med = compute_median(v);
    auto c = [=](int x, int y){
        return abs(x-med) > abs(y-med);
    };
    std::priority_queue<int, std::vector<int>, decltype(c)> que(c);

    for(int i = 0; i < v.size(); i++){
        que.push(v[i]);
    }

    std::vector<int> ans;
    for(int i = 0; i < k; i++){
        ans.push_back(que.top());
        que.pop();
    }
    return ans;
}

double compute_median2(std::vector<double> v) {
    for(int i = 0; i < v.size(); i++){
        std::nth_element(v.begin()+i, v.begin()+i+1, v.end());
    }

    return v[v.size()/2];
}

int main() {
    std::vector<double> array = {7.0,14.0,10.0,12.0,2.0,11.0,29.0,3.0,4.0};
    std::vector<int> output, output2;

    output = compute_k_closest(array, 3);
    cout << "output1" << endl;
    for(auto e : output){
        std::cout << e << std::endl;
    }

    return 0;
}