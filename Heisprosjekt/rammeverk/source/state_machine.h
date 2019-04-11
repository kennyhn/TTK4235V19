/**@file state_machine.h
 * @brief Functions for the state of the elevatormake break
 */

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
 * @brief Sets elevator to move in the direction @p motor_dir.
 *
 * @param motor_dir The direction the elevator should move.
 */
void state_moving(elev_motor_direction_t motor_dir);

/**
 * @brief Opens door and holds door for 3 sec. Clear all orders at floor.
 */

void state_door_open();

/**
 * @brief Delete all orders and stops the elevator as long as the STOP button is pressed between floors.
 */

void state_STOP_shaft();

/**
 * @brief Delete all orders and stops the elevator as long as the STOP button is pressed at a floor. 
 */

void state_STOP_floor();

#endif
