#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__
#include "elev_driver.h";

void set_current_motor_dir(elev_motor_direction_t curr_motor_dir); //i elev_driver.c??
void set_last_motor_dir(elev_motor_direction_t last_motor_dir);
void set_current_floor(int curr_floor);
void set_last_floor(int last_floor);
elev_motor_direction_t get_last_motor_dir();
int get_last_floor();

void idle();
void moving();
void door_open();
void STOP_shaft();
void STOP_floor();
void initial_elev();


#endif
