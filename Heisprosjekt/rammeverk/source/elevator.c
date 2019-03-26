#include "elev_driver.h"
#include "timer.h"
#include "controller.h"
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

int get_current_floor(){
    return elev.curr_floor;
}

int get_last_floor(){
    return elev.last_floor;
}

elev_motor_direction_t get_last_motor_dir(){
    return elev.last_motor_dir;
}

int get_last_floor(){
    return elev.last_floor;
}

void initial_elev(){
  elev_set_door_open_lamp(0);
  elev_set_motor_direction(DIRN_UP);
  while (elev_get_floor_sensor_signal() == (-1));
  set_current_motor_dir(DIRN_STOP);
  set_last_motor_dir(DIRN_STOP);
  elev_set_motor_direction(DIRN_STOP);
  elev_set_floor_indicator(elev_get_floor_sensor_signal());
  set_last_floor(elev_get_floor_sensor_signal());
}

void idle(){
  elev_set_door_open_lamp(0);
  elev_set_motor_direction(DIRN_STOP);
  if (elev_get_floor_sensor_signal() != (-1)){
    set_last_motor_dir(elev.curr_motor_dir);
    elev.set_current_motor_dir(DIRN_STOP);
    elev.set_current_floor(elev_get_floor_sensor_signal());
  }
}

void moving(elev_motor_direction_t motor_dir){
  elev_set_door_open_lamp(0);
  set_current_motor_dir(motor_dir);
  elev_set_motor_direction(motor_dir);
}

void door_open(){
  elev_set_motor_direction(DIRN_STOP);
    while (3_sec_timer()){
      clear_all_orders_at_floor(curr_floor);
      elev_set_door_open_lamp(1);
      button_poller();
      if(elev_get_stop_signal() == 1){
        State = STOP_FLOOR;
        break;
      }
    }
  elev_set_door_open_lamp(0);
}

void STOP_shaft(){
  clear_all_orders();
  elev_set_motor_direction(DIRN_STOP);
  while(elev_get_stop_signal() == 1){
    elev_set_stop_lamp(1);
    elev_set_door_open_lamp(1);
  }
  while (3_sec_timer());
  elev_set_stop_lamp(0);
  elev_set_door_open_lamp(0);
  }
}

void STOP_floor(){
  clear_all_orders();
  elev_set_motor_direction(DIRN_STOP);
  elev_set_floor_indicator(elev_get_floor_sensor_signal());
  while(elev_get_stop_signal() == 1){
    elev_set_stop_lamp(1);
    elev_set_door_open_lamp(1);
  }
  elev_set_stop_lamp(0);
}
