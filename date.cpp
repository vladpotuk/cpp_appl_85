#include "date.h"

bool isValidDate(int d, int m, int y) {
    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;

    static const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
        return d <= 29;
    else
        return d <= daysInMonth[m];
}

Date::Date(int d, int m, int y) {
    if (!isValidDate(d, m, y)) {
        std::cerr << "Invalid date!" << std::endl;
        exit(1);
    }

    day = d;
    month = m;
    year = y;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

int Date::operator-(const Date& other) const {
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int result = 0;

    Date earlier = (*this < other) ? (*this) : other;
    Date later = (*this < other) ? other : (*this);

    while (earlier != later) {
        result++;
        earlier = earlier + 1;
    }

    return result;
}

Date Date::operator+(int days) const {
    Date result = *this;

    while (days > 0) {
        result.day++;
        if (result.day > 31) {
            result.day = 1;
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }
        days--;
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getDay() << '/' << date.getMonth() << '/' << date.getYear();
    return os;
}

bool Date::operator<(const Date& other) const {
    if (getYear() != other.getYear()) {
        return getYear() < other.getYear();
    }
    else if (getMonth() != other.getMonth()) {
        return getMonth() < other.getMonth();
    }
    else {
        return getDay() < other.getDay();
    }
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator==(const Date& other) const {
    return getYear() == other.getYear() && getMonth() == other.getMonth() && getDay() == other.getDay();
}
