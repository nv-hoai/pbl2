#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

class Date {
public:
    // Constructors
    Date() : day(1), month(1), year(1900) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {
        validate();
    }

    // Accessors
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Mutators
    void setDay(int day) { this->day = day; validate(); }
    void setMonth(int month) { this->month = month; validate(); }
    void setYear(int year) { this->year = year; validate(); }

    // Additional methods
    std::string toString() const {
        return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    }

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth() const {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && isLeapYear()) {
            return 29;
        }
        return days[month - 1];
    }

private:
    int day, month, year;

    void validate() {
        if (day < 1 || day > daysInMonth()) {
            throw std::invalid_argument("Invalid day");
        }
        if (month < 1 || month > 12) {
            throw std::invalid_argument("Invalid month");
        }
        if (year < 1900) {
            throw std::invalid_argument("Invalid year");
        }
    }
};

#endif