#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <Roster.h>

class Time
{
    int month;
    int year;
    int elapsed_time;
public:
    Time(int startYear);
    void advance(Roster *rost);
    int getMonth(){return month;};
    std::string getMonthString();
    int getYear(){return year;};
    int getElapsed(){return elapsed_time;};

};

#endif // TIME_H
