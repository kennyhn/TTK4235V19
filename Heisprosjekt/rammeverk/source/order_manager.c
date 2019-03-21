#include "order_manager.h"
#include "lights.h"
#include "elev_driver.h"
#include <stdio.h>


#define NUM_OF_BUTTONS 10
#define NUM_OF_BUTTON_TYPES 3

order Orderlist[NUM_OF_BUTTONS];

void init_orderlist(){
    int added_order_number = 0;
    for (int i = 0; i<N_FLOORS; i++){
        for (int j = 0; j<NUM_OF_BUTTON_TYPES; j++){
            //Create order
            order order={i, (elev_button_type_t)j, 0};
            //If at ground, don't add order for hall down
            if (i == 0 && j == BUTTON_CALL_DOWN);
            //If at top floor, don't add order for hall up
            else if (i==(N_FLOORS-1) && j == BUTTON_CALL_UP);

            else{
                Orderlist[added_order_number] = order;
                added_order_number++;
            }
        }
    }
}

void clear_all_orders(){

    for (int i = 0; i<NUM_OF_BUTTONS; i++){
        Orderlist[i].active = 0;
    }
}

void clear_all_orders_at_floor(int floor){

    if (floor == 0) {
        for (int i = 0; i < (NUM_OF_BUTTON_TYPES - 1); i++){
            Orderlist[floor + i].active = 0;
        }
    }
    else if (floor == (N_FLOORS - 1)){
        for (int i = 0; i < (NUM_OF_BUTTON_TYPES - 1); i++){
            Orderlist[2 + (NUM_OF_BUTTON_TYPES)*(floor - 1) + i].active = 0;
        }
    }
    else{
        for (int i = 0; i < (NUM_OF_BUTTON_TYPES); i++){
            Orderlist[2 + (NUM_OF_BUTTON_TYPES)*(floor - 1) + i].active = 0;
        }
    }
    /* Forslag til forbedring:
    Gjør som i poller? Lettere kode
    Trenger ikke å knote med matten i listen
    */
}

void set_order(int floor, elev_button_type_t button_type){

    for (int i = 0; i<N_FLOORS; i++) {
        if (Orderlist[i].floor == floor && Orderlist[i].type == button_type)
            Orderlist.active = 1;
    }
}


int is_active_orders(){

    for (int i = 0; i<NUM_OF_BUTTONS; i++){
        if (Orderlist[i].active == 1){
            return 1;
        }
    }
    return 0;
}



order is_order_active(int order_number){
    return Orderlist[order_number];
}
