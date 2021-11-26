#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date() {}
  void set(const int m,const int d,const int y);
  const void print();
  const int get_month();
  const int get_day();
  const int get_year();
  void inc_day(); 
  void inc_month();
  void inc_year();
  bool uruu(int);
private:
  int month, day, year;
};

#endif
