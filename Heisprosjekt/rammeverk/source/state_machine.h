#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "elev_driver.h"

typedef enum State {MOVING, IDLE, DOOR_OPEN, STOP_FLOOR, STOP_SHAFT} state;

void state_init();
void state_idle();
void state_moving(elev_motor_direction_t motor_dir);
void state_door_open();
void state_STOP_shaft();
void state_STOP_floor();  

#endif