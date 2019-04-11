
/**@file controller.h
 * @brief Functions for controlling state of elevator.
 */

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__


#include "elev_driver.h"
#include "state_machine.h"

/**@brief Finds the next state for the elevator.
 *
 * @return Next state for the elevator. Returns -1 if no valid state.
 */

state next_state();

/**
 * @brief Chooses which direction the elevator should drive next.
 *
 * @return New direction for the elevator.
 */

elev_motor_direction_t choose_dir();

/**@brief Checks floor sensor and sets the elevators current floor. If the elevator is at a floor, last floor is set and floor lights are updated.
 *
 */

void floor_sensor_poller();

/**@brief Checks if any buttons is pressed, and if so, adds the corresponding order to the orderlist.
 *
 */

void button_poller();

/**@brief Sets floor lights at @p last_floor.

 * @param[in] last_floor The floor where the sensor was last indicated.
 */

void update_floor_lights(int last_floor);



#endif
