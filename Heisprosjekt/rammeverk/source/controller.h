#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

typedef enum State {MOVING, IDLE, DOOR_OPEN, STOP_FLOOR, STOP_SHAFT} state;
#include "elev_driver.h"

void button_poller();
void floor_sensor_poller();
void update_floor_lights(int last_floor);
elev_motor_direction_t choose_dir();
state next_state();

#endif
