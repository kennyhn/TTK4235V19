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

/**@brief Sets floor lights at floor.

 * @param[in] last_floor The floor which the sensor was last indicated.
 */

void update_floor_lights(int last_floor);

/**
 * @brief Chooses wich direction the elevator should drive next.
 *
 * @param[in] current_floor Floor wich elevator is at
 * @param[in] curr_motor_dir Direction which elevator is currently driving
 *
 * @return A elev_motor_direction_t which is the new direction for the elevator. 
 */

elev_motor_direction_t choose_dir(float current_floor, elev_motor_direction_t curr_motor_dir);

/**@brief Finds next state for the elevator.
 *
 * @return A state which is the next state.
 */

state next_state();

#endif
