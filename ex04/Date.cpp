#include <iostream>
#include "Date.h"

void Date::set(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void Date::print() {
    std::cout<<"month ->"<<month<<std::endl;
    std::cout<<"day ->"<<day<<std::endl;
    std::cout<<"year ->"<<year<<std::endl;
}

int Date::get_month() const{
    return month;
}

int Date::get_year()const{
    return year;
}

int Date::get_day()const{
    return day;
}

void Date::inc_day() {
    day++;
}

void Date::inc_month() {
    month++;
}

void Date::inc_year() {
    year++;
}