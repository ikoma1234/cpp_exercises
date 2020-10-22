#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
    public:
        Date() {};  
        void set(const int m, const int d, const int y){
            month = m;
            day = d;
            year = y;
        }
        void print() const{
            std::cout << year << " " << month << " " << day << std::endl;
        }
        int get_month() const{
            return month;
        }
        int get_year() const{
            return year;
        }
        int get_day() const{
            return day;
        }
    private:
        int month, day, year;
};

#endif