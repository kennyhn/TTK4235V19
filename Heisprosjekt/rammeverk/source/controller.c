#include "controller.h"
#include "elevator.h"
#include "order_manager.h"


state next_state(){
  if (elev_get_stop_signal()){
    if (elev_get_floor_sensor_signal() == -1){
      return STOP_SHAFT;
    }
    return STOP_FLOOR;
  }
  if (!is_active_orders()){
    return IDLE;
  }
  if (is_active_orders){
    return MOVING;
  }
  if (is_order_at_floor(get_current_floor(), get_last_motor_dir()))
    return DOOR_OPEN;
}

int choose_dir(order Orderlist, elevator elev){
  for (int floor = 0; floor < N_FLOORS; i++){
    for (int button = BUTTON_CALL_UP; button < BUTTON_CALL_DOWN; button++){
      if (Orderlist[floor][button].active){
        if (floor > elev.get_current_floor()){
          set_motor_dir(DIRN_UP);
        }
        else if (floor < elev.get_current_floor()){
          set_motor_dir(DIRN_DOWN);
        }
        else{
          set_motor_dir(DIRN_STOP);
        }
      }
    }
  }
}

int floor_sensor_poller(){
    int floor = elev_get_floor_sensor_signal();
    if (floor != -1){
        set_last_floor(floor);
        update_floor_lights(floor);
    }
    return floor;
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
