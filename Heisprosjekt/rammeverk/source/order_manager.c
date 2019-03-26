#include "order_manager.h"
#include "elev_driver.h"
#include <stdio.h>

order Orderlist[N_FLOORS][N_BUTTONS];

void init_orderlist(){
    for (int floor = 0; floor < N_FLOORS; floor++){
        for (elev_button_type_t button = 0; button < N_BUTTONS; button++) {
            order order = {floor, (elev_button_type_t)button, 0};
            Orderlist[floor][button] = order;
        }
    }
}

void clear_all_orders(){
    for (int floor = 0; floor<N_FLOORS; floor++){
        for (elev_button_type_t button = 0; button < N_BUTTONS; button++ )
            Orderlist[floor][button].active = 0;
    }
    update_button_lights();
}

void clear_all_orders_at_floor(int floor){
    for (elev_button_type_t button = 0; button < N_BUTTONS; button++)
        Orderlist[floor][button].active = 0;
    update_button_lights();
}

void set_order(int floor, elev_button_type_t button_type){
    //In case of faulty code
    if (floor == 0 && button_type == BUTTON_CALL_DOWN){}
    else if (floor == N_FLOORS-1 && button_type == BUTTON_CALL_UP){}
    
    else
    {
        Orderlist[floor][button_type].active=1;
        update_button_lights();
    }
    
}

order get_order(int floor, elev_button_type_t button_type){
    return Orderlist[floor][button_type];
}


int is_active_orders(){
    for (int floor = 0; floor < N_FLOORS; floor++){
        for (elev_button_type_t button = 0; button < N_BUTTONS; button++)
        if (Orderlist[floor][button].active)
            return 1;
    }
    return 0;
}



int is_order_at_floor(int floor, elev_motor_direction_t motor_dir){
    for (elev_button_type_t button = 0; button < N_BUTTONS; button++){
        if (Orderlist[floor][button].active){
            if (Orderlist[floor][button].button_type == BUTTON_COMMAND)
                return 1; //true
            if (Orderlist[floor][button].button_type == BUTTON_CALL_UP && motor_dir == DIRN_UP)
                return 1; //true
            if (Orderlist[floor][button].button_type == BUTTON_CALL_DOWN && motor_dir == DIRN_DOWN)
                return 1; //true
         }
    }
    return 0; //false
}

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

