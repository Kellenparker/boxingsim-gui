#include "Time.h"

Time::Time(int startYear)
{
    Time::month = 0;
    Time::year = startYear;
    Time::elapsed_time = 0;
}

void Time::advance(Roster *rost){

    rost->Progress();

    if (month < 11)  month++;
    else {
        rost->IncrementAge();
        month = 0;
        year++;
    }
    elapsed_time++;

}

std::string Time::getMonthString(){

    static const char* monthNames[] = { "January", "February", "March", "April",
                                        "May", "June", "July", "August", "September",
                                        "October", "November", "December" };
    return monthNames[month];

}
