#include "Date.h"
Date::Date(string date){
    this->day=date.split("-")[0];
    this->month=date.split("-")[1];
    this->year=date.split("-")[2];
}

Date::Date() {}

bool Date::operator<(const Date &rhs) const {
    if (year < rhs.year)
        return true;
    if (rhs.year < year)
        return false;
    if (month < rhs.month)
        return true;
    if (rhs.month < month)
        return false;
    return day < rhs.day;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.day << "-" << date.month << "-" << date.year;
    return os;
}