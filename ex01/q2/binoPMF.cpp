#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "binoPMF.h"
using namespace std;

double binomialPMF(int n, double p, int k)
{
    double nk, sumn = 1, sumk = 1, sumnk = 1;
    double fl;
    double i, j, q, pk, qnk;

    q = 1 - p;
    pk = p;
    qnk = q;
    nk = (double)n - (double)k;

    for (i = 1; i <= (double)n; i++){
        sumn *= i;
    }

    for (i = 1; i <= (double)k; i++){
        sumk *= i;
    }

    for (i = 1; i <= nk; i++){
        sumnk *= i;
    }

    for (j = 1; j < (double)k; j++){
        pk *= p;
    }

    for (j = 1; j < nk; j++){
        qnk *= q;
    }

    fl = sumn / (sumk * sumnk) * pk * qnk;
    return fl;

}