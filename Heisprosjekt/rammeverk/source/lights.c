#include "lights.h"
#include "elev_driver.h"
#include "order_manager.h"

void update_button_lights(){
    for (int i = 0; i<N_FLOORS; i++){
        order order = is_order_active(i);
        elev_set_button_lamp(order.button_type, order.floor, order.active);
    }
}
