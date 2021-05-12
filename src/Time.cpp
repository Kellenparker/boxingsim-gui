#include "Time.h"

Time::Time(int startYear)
{
    Time::month = 0;
    Time::year = startYear;
    Time::elapsed_time = 0;
}

void Time::advance(){

    if (month < 11) month++;
    else {
        month = 0;
        year++;
    }
    elapsed_time++;

}

const char* Time::getMonthString(){

    static const char* monthNames[] = { "January", "February", "March", "April",
                                        "May", "June", "July", "August", "September",
                                        "October", "November", "December" };
    return monthNames[month];

}
