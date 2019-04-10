#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "elev_driver.h"

typedef enum State {MOVING, IDLE, DOOR_OPEN, STOP_FLOOR, STOP_SHAFT} state;

/**
 * @brief Intialize the elevator.
 */

void state_init();

/**
 * @brief Sets elevator to idle.
 */

void state_idle();

/**
 * @brief Sets elevator to move in a direction.
 *
 * @param motor_dir The direction the elevator is moving.
 */
void state_moving(elev_motor_direction_t motor_dir);

/**
 * @brief Opens door and sets door lights for 3 sec.
 */

void state_door_open();

/**
 * @brief Clear all orders and stops the elevator as long as the STOP button is pressed in shaft.
 */

void state_STOP_shaft();

/**
 * @brief Clear all orders and stops the elevator as long as the STOP button is pressed at floor. 
 */

void state_STOP_floor();

#endif
