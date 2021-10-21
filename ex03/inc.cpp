#include "inc.h"

void inc(double &x)
{
    x++;
}

void inc(double *x)
{
    (*x)++;
}