#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "binoPMF.h"
using namespace std;

int main()
{
    double a, b, c, d, e;
    a = binomialPMF(5, 0.25, 1);
    b = binomialPMF(5, 0.25, 2);
    c = binomialPMF(25, 0.25, 2);
    d = binomialPMF(25, 0.25, 10);
    e = binomialPMF(25, 0.25, 15);

cout << fixed << setprecision(6) << "binomialPMF(5, 0.25, 1):" << a << endl;
cout << fixed << setprecision(6) << "binomialPMF(5, 0.25, 2):" << b << endl;
cout << fixed << setprecision(7) <<"binomialPMF(25, 0.25, 2):" << c << endl;
cout << fixed << setprecision(7) <<"binomialPMF(25, 0.25, 10):" << d << endl;
cout << fixed << setprecision(9) <<"binomialPMF(25, 0.25, 15):" << e << endl;

}