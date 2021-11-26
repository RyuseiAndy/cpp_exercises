#include <iostream>
#include "Date.h"

void Date::set(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

const void Date::print(){
    std::cout<<"month ->"<<month<<std::endl;
    std::cout<<"day ->"<<day<<std::endl;
    std::cout<<"year ->"<<year<<std::endl;
}

const int Date::get_month(){
    return month;
}

const int Date::get_year(){
    return year;
}

const int Date::get_day(){
    return day;
}

bool Date::uruu(int year){
    if(year%4==0&&year%100!=0||year%400==0){
        return true; 
    }else{
        return false;
    }
}

void Date::inc_day(){

day++;
    if (uruu(year)==true &&month==2){
        if(day>=28){
            day=1;
        }
        
    }
    else if (uruu(year)==false &&month==2){ 
        if(day>=29){
            day=1;
        }
    }
    else if(month==4||month==6||month==9||month==11){
        if(day>=30){
            day=1;
        }
    }
    else{
       if(day>=31){
           day=1;
       }
    else{
        day++;
    }
      
    }
    
}

void Date::inc_month() {
    if(1< month && month<12){
        month++;
    }
    else {
        month =1;
    }
}

void Date::inc_year() {
    year++;
}