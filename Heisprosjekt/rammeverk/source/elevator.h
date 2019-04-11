/**@file elevator.h
 * @brief Functions for getting and setting the elevators floor and motor direction.
 */

#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__
#include "elev_driver.h"

/**
 * @brief Sets @p curr_motor_dir.
 *
 * @param[in] curr_motor_dir The elevator's current motor direction.
 */
void set_current_motor_dir(elev_motor_direction_t curr_motor_dir);

/**
 * @brief Sets @p last_motor_dir.
 *
 * @param[in] last_motor_dir The elevator's last motor direction.
 */
void set_last_motor_dir(elev_motor_direction_t last_motor_dir);

/**
 * @brief Sets @p curr_floor.
 *
 * @param[in] curr_floor Elevator's current floor.
 */

void set_current_floor(int curr_floor);

/**
 * @brief Sets @p last_floor.
 *
 * @param[in] last_floor Elevator's last floor.
 */
void set_last_floor(int last_floor);

/**
 * @brief Gets the elevator's current motor direction.
 *
 * @return The elevator's current motor direction.
 */
elev_motor_direction_t get_current_motor_dir();

/**
 * @brief Gets the elevator's last motor direction.
 *
 * @return The elevator's last motor direction.
 */

elev_motor_direction_t get_last_motor_dir();

/**
 * @brief Gets the last floor the elevator has been at.
 *
 * @return Last floor
 */
int get_last_floor();

/**
 * @brief Gets which floor the elevator is at.
 *
 * @return Current floor if elevator at floor. -1 if between two floors.
 */
int get_current_floor();


#endif
