#include "Info.h"

Name::Name(string fN, string lN) {
    fName = fN;
    lName = lN;
}

string Name::getFirstName() const {
    return fName;
}

void Name::setFirstName(string fN) {
    fName = fN;
}

string Name::getLastName() const {
    return lName;
}

void Name::setLastName(string lN) {
    lName = lN;
}

Name::~Name() {
}

Name::Name() {
    fName = '\0';
    lName = '\0';
}

Name::Name(const Name& other) {
    fName = other.fName;
    lName = other.lName;
}

ostream& operator<<(ostream& out, const Name& n) {
    out << n.fName << " " << n.lName << endl;
    return out;
}

////////////////////Date Implementation ////////////

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int d) {
    if (d >= 1 && d <= 31) {
        day = d;
    }
    else {
        throw invalid_argument("Invalid day value");
    }
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    }
    else {
        throw invalid_argument("Invalid month value");
    }
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int y) {
    if (y >= 2000 && y <= 9999) {
        year = y;
    }
    else {
        throw invalid_argument("Invalid year value");
    }
}

ostream& operator<<(ostream& out, const Date& date) {
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}
 
//////////////////////////////mTime Implementation////////////////////

#include <iomanip>

mTime::mTime(int h, int m, int s) {
    setHour(h);
    setMin(m);
    setSec(s);
}

int mTime::getHour() const {
    return hour;
}

void mTime::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
    }
    else {
        throw invalid_argument("Invalid hour value");
    }
}

int mTime::getMin() const {
    return min;
}

void mTime::setMin(int m) {
    if (m >= 0 && m < 60) {
        min = m;
    }
    else {
        throw invalid_argument("Invalid minute value");
    }
}

int mTime::getSec() const {
    return sec;
}

void mTime::setSec(int s) {
    if (s >= 0 && s < 60) {
        sec = s;
    }
    else {
        throw invalid_argument("Invalid second value");
    }
}
ostream& operator<<(ostream& out, const mTime& time) {
    out << setw(2) << setfill('0') << time.hour << " : " << setw(2) << setfill('0') << time.min << " : " << setw(2) << setfill('0') << time.sec;
    return out;
}
