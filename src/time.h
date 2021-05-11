#ifndef TIME_H
#define TIME_H

class time
{
    int month;
    int year;
    int elapsed_time;
public:
    time(int startYear);
    void advance();
    int getMonth(){return month;};
    const char* getMonthString();
    int getYear(){return year;};
    int getElapsed(){return elapsed_time;};

};

#endif // TIME_H
