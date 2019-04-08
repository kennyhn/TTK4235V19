#include "controller.h"
#include "elevator.h"
#include "order_manager.h"
#include "time.h"
#include <stdio.h>


state next_state(){
  if (elev_get_stop_signal()){
    if (elev_get_floor_sensor_signal() == -1)
      return STOP_SHAFT;

    return STOP_FLOOR;
  }
  if (is_order_at_floor(get_current_floor(), get_last_motor_dir())){
    return DOOR_OPEN;
  }
  if (is_active_orders()){
    return MOVING;
  }
  return -1;
}

elev_motor_direction_t choose_dir(float current_floor, elev_motor_direction_t curr_motor_dir){
  //float current_floor = get_last_floor();

  //Continue same direction
/*
  if (get_current_motor_dir() == DIRN_UP && orders_above(current_floor)){
      return DIRN_UP;
  }

  else if (get_current_motor_dir() == DIRN_DOWN && orders_below(current_floor)){
      return DIRN_DOWN;
  }


  if (get_current_floor() == -1){
    current_floor = current_floor+(float)get_last_motor_dir()*0.5;
  }
*/
  if (curr_motor_dir == DIRN_UP && orders_above(current_floor)){
      return DIRN_UP;
  }

  else if (curr_motor_dir == DIRN_DOWN && orders_below(current_floor)){
      return DIRN_DOWN;
  }


  if (current_floor == -1){
    current_floor = current_floor+(float)get_last_motor_dir()*0.5;
  }

  for (int floor = 0; floor < N_FLOORS; floor++){
    for (elev_button_type_t button = 0; button < N_BUTTONS; button++){
      if (get_order(floor, button).active){
          if (floor > current_floor)
            return DIRN_UP;
          else if (floor < current_floor)
            return DIRN_DOWN;
      }
    }
  }
  //If order at same floor
  return DIRN_STOP;
}


void floor_sensor_poller(){
    int floor = elev_get_floor_sensor_signal();
    if (floor != -1){
        set_last_floor(floor);
        update_floor_lights(floor);
    }
    set_current_floor(floor);
}

void button_poller(){
    for (int floor = 0; floor < N_FLOORS; floor++){
        for (elev_button_type_t button = 0; button < N_BUTTONS; button++){
            if (floor == 0 && button == BUTTON_CALL_DOWN){}
            else if (floor == (N_FLOORS - 1) && button == BUTTON_CALL_UP){}
            else{
                if (elev_get_button_signal(button, floor))
                    set_order(floor,button);
            }
        }
    }
}

void update_floor_lights(int last_floor){
    elev_set_floor_indicator(last_floor);
}
