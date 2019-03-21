#include "controller.h"
#include "order_manager.h"

state next_state(){
    // Stop button pushed
    if (elev_get_stop_signal()){
        if (elev_get_floor_sensor_signal() == -1){
           return STOP_SHAFT;
        }
        return STOP_FLOOR;
    }

    //There is no orders
    if (!is_active_orders()){
        return IDLE;
    }

    // TBD: Logic for when to go to MOVING and DOOR_OPEN

}


void poller(){

    for (int floor = 0; floor<N_FLOORS; floor++){
        for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
            if (floor == 0 && button == BUTTON_CALL_DOWN);

            else if (floor == (N_FLOORS - 1) && button == BUTTON_CALL_UP);

            else{
                if (elev_get_button_signal(button, floor)){
                  set_order(floor,button);
                }
            }
        }
    }
    // Kanskje ha denne her et annet sted? Knappene funker nå iaf.
    update_button_lights();
}

void update_floor_lights(int last_floor){
    elev_set_floor_indicator(last_floor)
}
