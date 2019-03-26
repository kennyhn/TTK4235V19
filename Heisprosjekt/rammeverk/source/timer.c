#include "timer.h"
#include <stdlib.h>
#include <time.h>

void start_timer(time_t* current_time){
    //Start the timer
    time(current_time);
}

int timer_3_sec(time_t door_timer_start){
    //Find out current time
    time_t current_time;
    time(&current_time);

    return (labs(current_time-door_timer_start) >= 3);
}