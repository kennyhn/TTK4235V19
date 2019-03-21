#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "elev_driver.h"

typedef struct Order {
    int floor;
    elev_button_type_t button_type;
    int active; //used as boolean
}order;

void init_orderlist();
void clear_all_orders();
void set_order(int floor, elev_button_type_t button_type);
int is_active_orders();
void clear_all_orders_at_floor(int floor);
void poller();
order is_order_active(int order_number);




#endif
