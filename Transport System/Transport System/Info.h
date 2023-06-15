#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Name {
private:
    string fName;
    string lName;
public:
    Name(string fN, string lN);
    //getters and setters
    string getFirstName() const;
    void setFirstName(string fN);
    string getLastName() const;
    void setLastName(string lN);
    //destructor
    ~Name();
    // default constructor
    Name();
    //copy constructor
    Name(const Name& other);
    // friend stream output operator
    friend ostream& operator<<(ostream& out, const Name& n);
};

//////////////////////////////////////////////////////

class Date {
private:
    int day;
    int month;
    int year;
public:
    // constructors
    Date(int d = 1, int m = 1, int y = 2000);
    // getters and setters
    int getDay() const;
    void setDay(int d);
    int getMonth() const;
    void setMonth(int m);
    int getYear() const;
    void setYear(int y);
    // stream output operator
    friend ostream& operator<<(ostream& out, const Date& date);
};

////////////////////////////////////////////////

class mTime {
private:
    int hour;
    int min;
    int sec;
public:
    //constructor
    mTime(int h = 0, int m = 0, int s = 0);
    //setter and getters
    int getHour() const;
    void setHour(int h);
    int getMin() const;
    void setMin(int m);
    int getSec() const;
    void setSec(int s);
    //stream output operator
    friend ostream& operator<<(ostream& out, const mTime& time);
};
