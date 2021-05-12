#ifndef TIME_H
#define TIME_H

class Time
{
    int month;
    int year;
    int elapsed_time;
public:
    Time(int startYear);
    void advance();
    int getMonth(){return month;};
    const char* getMonthString();
    int getYear(){return year;};
    int getElapsed(){return elapsed_time;};

};

#endif // TIME_H
