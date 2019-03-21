#include "elev_driver.h";
#include <stdio.h>

typedef struct ElevatorInfo {
    elev_motor_direction_t curr_motor_dir;
    elev_motor_direction_t last_motor_dir;
    int curr_floor;
    int last_floor;
}elevatorInfo;

elevatorInfo elev;

void set_motor_dir(elev_motor_direction_t curr_motor_dir){
    elev.curr_motor_dir = curr_motor_dir;
}

void set_last_motor_dir(elev_motor_direction_t last_motor_dir){
    elev.last_motor_dir = last_motor_dir;
}

void set_current_floor(int curr_floor ){
    elev.curr_floor = curr_floor;
}

void set_last_floor(int last_floor){
    elev.last_floor = last_floor;
}

elev_motor_direction_t get_last_motor_dir(){
    return elev.last_motor_dir;
}

int get_last_floor(){
    return elev.last_floor;
}
