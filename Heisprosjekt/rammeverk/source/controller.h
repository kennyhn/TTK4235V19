/**@file controller.h
 * @brief Functions for controlling state of elevator.
 */

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__


#include "elev_driver.h"
#include "state_machine.h"

/**@brief Checks if any buttons is pressed, and if so adds the corresponding order to the orderlist.
 * 
 */
void button_poller();

/**@brief Sets @p current_floor if the elevator is at a floor.
 * 
 */
void floor_sensor_poller();

/**@brief Sets @p current_floor if the elevator is at a floor.
 * 
 */
void update_floor_lights(int last_floor);
elev_motor_direction_t choose_dir();
state next_state();

#endif
