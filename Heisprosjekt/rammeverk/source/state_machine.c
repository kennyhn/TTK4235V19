/**@file state_machine.c
*/
#include "state_machine.h"
#include "elevator.h"
#include "elev_driver.h"
#include "order_manager.h"
#include "controller.h"
#include "timer.h"
#include <time.h>


void state_init(){
  elev_set_door_open_lamp(0);
  elev_set_motor_direction(DIRN_UP);
  while (elev_get_floor_sensor_signal() == (-1));
  set_current_motor_dir(DIRN_STOP);
  set_last_motor_dir(DIRN_STOP);
  elev_set_motor_direction(DIRN_STOP);
  elev_set_floor_indicator(elev_get_floor_sensor_signal());
  set_last_floor(elev_get_floor_sensor_signal());
}

void state_idle(){
  elev_set_door_open_lamp(0);
  elev_set_motor_direction(DIRN_STOP);
  if (elev_get_floor_sensor_signal() != (-1)){
    if (!is_active_orders()){
      set_current_motor_dir(DIRN_STOP);
    }
    set_current_floor(elev_get_floor_sensor_signal());
  }
}


void state_moving(elev_motor_direction_t motor_dir){
  elev_set_door_open_lamp(0);
  if (get_current_floor() != -1){
    set_last_motor_dir(motor_dir);
  }
  set_current_motor_dir(motor_dir);
  elev_set_motor_direction(get_current_motor_dir());
}

void state_door_open(){
  elev_set_motor_direction(DIRN_STOP);
  set_last_motor_dir(DIRN_STOP);
    time_t door_timer;
    start_timer(&door_timer);
    do{
      clear_all_orders_at_floor(get_current_floor());
      elev_set_door_open_lamp(1);
      button_poller();
      if(elev_get_stop_signal() == 1){
        break;
      }
    }while(!timer_3_sec(door_timer));
}

void state_STOP_shaft(){
  clear_all_orders();
  elev_set_door_open_lamp(0);
  elev_set_motor_direction(DIRN_STOP);
  set_current_motor_dir(DIRN_STOP);
  while(elev_get_stop_signal()){
    elev_set_stop_lamp(1);
  }
  elev_set_stop_lamp(0);
}

void state_STOP_floor(){
  clear_all_orders();
  elev_set_motor_direction(DIRN_STOP);
  set_current_motor_dir(DIRN_STOP);
  while(elev_get_stop_signal()){
    elev_set_stop_lamp(1);
    elev_set_door_open_lamp(1);
  }
  elev_set_stop_lamp(0);
}
