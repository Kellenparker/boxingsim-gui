#include "time.h"

time::time(int startYear)
{
    time::month = 0;
    time::year = startYear;
    time::elapsed_time = 0;
}

void time::advance(){

    if (month < 11) month++;
    else {
        month = 0;
        year++;
    }
    elapsed_time++;

}

const char* time::getMonthString(){

    static const char* monthNames[] = { "January", "February", "March", "April",
                                        "May", "June", "July", "August", "September",
                                        "October", "November", "December" };
    return monthNames[month];

}
