/**@file timer.h
 * @brief Functions for controlling the door timer.
 */

#ifndef __TIMER_H__
#define __TIMER_H__
#include <time.h>

/**
 * @brief Starts a timer from @p current time.
 *
 * @param current_time The current time.
 */

void start_timer(time_t* current_time);

/**
 * @brief Counts 3 seconds from @p door_timer_start.
 *
 * @param door_timer_start The start of the timer.
 *
 * @return Return 0 if it has been 3 seconds from @p door_timer_start, 1 if not.
 */

int timer_3_sec(time_t door_timer_start);
#endif
