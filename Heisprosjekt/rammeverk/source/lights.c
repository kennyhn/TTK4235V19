#include "lights.h"
#include "elev_driver.h"
#include "order_manager.h"

void update_button_lights(){
    for (int floor = 0; floor<N_FLOORS; floor++){
        for (elev_button_type_t button = 0; button<N_BUTTONS; button++){
            if (floor == (N_FLOORS-1) && button == BUTTON_CALL_UP){}
            else if (floor == 0 && button == BUTTON_CALL_DOWN){}
            else{
                order order = get_order(floor, button);
                elev_set_button_lamp(order.button_type, order.floor, order.active);
            }
        }
    }
}
