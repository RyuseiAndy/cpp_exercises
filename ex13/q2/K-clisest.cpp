#include <vector>
#include <iostream>
#include "compute.h"
int main()
{
    vector<double> med;
    med.push_back(7.0);
    med.push_back(14.0);
    med.push_back(10.0);
    med.push_back(12.0);
    med.push_back(2.0);
    med.push_back(11.0);
    med.push_back(29.0);
    med.push_back(3.0);
    
    double closest = compute_median(med);

    cout << "\n The median is : " << closest << endl;

    vector<double> closest2 = compute_k_closest(3, med);
    
    cout << "for k=3,the k-closest numbers to the median are" << endl;

    for (size_t i = 0; i < 3; ++i) {
        std::cout << closest2[i] << std::endl;
    }

    return 0;
}