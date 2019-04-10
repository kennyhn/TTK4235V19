#ifndef __TIMER_H__
#define __TIMER_H__
#include <time.h>

/**
 * @brief Starts a timer from the current time.
 *
 * @param current_time The current time.
 */

void start_timer(time_t* current_time);

/**
 * @brief Counts 3 seconds from the start time.
 *
 * @param door_timer_start The start of the timer.
 *
 * @return Return 0 if it has been 3 seconds from door_timer_start, 1 if not. 
 */

int timer_3_sec(time_t door_timer_start);
#endif
