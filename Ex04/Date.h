#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
    public:
        Date() {}
        int get_month() const;
        int get_day() const;
        int get_year() const;
        void set(const int m, const int d, const int y);
        void print() const;
    private:
        int month, day, year;
};

inline void Date::set(const int m, const int d, const int y){
    month=m;
    day=d;
    year=y;
}

inline void Date::print() const{
    std::cout << year << " " << month << " " << day << std::endl;
}

inline int Date::get_month() const{
    return month;
}

inline int Date::get_year() const{
    return year;
}

inline int Date::get_day() const{
    return day;
}

#endif