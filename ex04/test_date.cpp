#include "Date.h"
#include "Date.cpp"

int main(void) {
  Date d;
  d.set(12, 31, 2001);
  //uruu(2001);
  d.print();

  d.inc_day();
  d.inc_month(); 
  d.print(); 

  d.inc_year();
  d.print(); 
}
