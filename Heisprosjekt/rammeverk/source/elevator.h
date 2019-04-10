#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__
#include "elev_driver.h"

/**
 * @brief Sets the elevator's current motor direction.
 *
 * @param[in] curr_motor_dir Current motor direction
 */
void set_current_motor_dir(elev_motor_direction_t curr_motor_dir); //i elev_driver.c??

/**
 * @brief Sets the elevator's last motor direction.
 *
 * @param[in] last_motor_dir Last motor direction
 */
void set_last_motor_dir(elev_motor_direction_t last_motor_dir);

/**
 * @brief Sets the elevator's current floor.
 *
 * @param[in] curr_floor Current floor
 */

void set_current_floor(int curr_floor);

/**
 * @brief Sets the elevator's last floor.
 *
 * @param[in] last_floor Last floor
 */
void set_last_floor(int last_floor);

/**
 * @brief Gets the elevator's current motor direction.
 *
 * @return elev_motor_direction_t current motor direction
 */
elev_motor_direction_t get_current_motor_dir();

/**
 * @brief Gets the elevator's last motor direction.
 *
 * @return elev_motor_direction_t last motor direction
 */

elev_motor_direction_t get_last_motor_dir();

/**
 * @brief Gets the last floor the elevator has been at.
 *
 * @return last floor (int)
 */
int get_last_floor();

/**
 * @brief Gets which floor the elevator is at.
 *
 * @return current floor (int) if elevator at a floor. -1 if between two floors.
 */
int get_current_floor();


#endif
