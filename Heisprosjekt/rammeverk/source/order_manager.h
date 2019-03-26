#ifndef __ORDER_MANAGER_H__
#define __ORDER_MANAGER_H__

#include "elev_driver.h"

typedef struct Order {
    int floor;
    elev_button_type_t button_type;
    int active; //used as boolean
}order;

void init_orderlist();
void clear_all_orders();
void clear_all_orders_at_floor(int floor);
void set_order(int floor, elev_button_type_t button_type);
order get_order(int floor, elev_button_type_t button_type);
int is_order_at_floor(int floor, elev_motor_direction_t motor_dir);
void update_button_lights();


#endif
