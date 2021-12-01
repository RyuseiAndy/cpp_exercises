#include <iostream>
#include "Date.h"

void Date::set(const int m,const int d,const int y){
    month = m;
    day = d;
    year = y;
}

void Date::print()const{
    std::cout<<"month ->"<<month<<std::endl;
    std::cout<<"day ->"<<day<<std::endl;
    std::cout<<"year ->"<<year<<std::endl;
}

int Date::get_month()const{
    return month;
}

int Date::get_year()const{
    return year;
}

int Date::get_day()const{
    return day;
}

void Date::inc_day(){
    day++;
    if(month==2&& day==29){
        day=1;
    }
    if(month==1||month==3||month==5||month==8||month==7||month==10||month==12){
        if(day==31||day ==32){
            day=1;
        }
    }
    else {
        if(day==30){
            day=1;
        }
    }
}


void Date::inc_month(){
    month++;
    if(month==13){
        month=1;
    }
}

void Date::inc_year() {
    year++;
}