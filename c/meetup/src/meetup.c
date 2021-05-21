#include "meetup.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

size_t NUMBER_OF_DAYS=7;
char* DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Given a day, return its position in the Gregorian Calendar.
// Example: "Sunday" -> 0, "Tuesday" -> 2
// Note: The day must be formatted properly.
int day_to_int(const char *day_of_week)
{

    for (size_t i = 0; i < NUMBER_OF_DAYS; i++)
    {
        char *day = DAYS[i];

        // printf("i=%lu, day=%s\n",i,day);

        if (strcmp(day_of_week, day) == 0)
        {
            return i;
        }
    }

    return -1;
}

// There are 7 'teenth' days (13-19) in a month.
bool is_day_teenth(int day){
    return (day >= 13 && day <= 19);
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{

    // avoid compiler error :3
    int i = year + month + week[0] + day_of_week[0];

    assert(day_to_int("Sunday") == 0);
    assert(day_to_int("Monday") == 1);
    assert(day_to_int("monday") == -1);

    return i;
}
