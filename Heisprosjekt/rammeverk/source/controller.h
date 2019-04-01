#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__


#include "elev_driver.h"
#include "state_machine.h"
void button_poller();
void floor_sensor_poller();
void update_floor_lights(int last_floor);
elev_motor_direction_t choose_dir();
state next_state();

#endif
