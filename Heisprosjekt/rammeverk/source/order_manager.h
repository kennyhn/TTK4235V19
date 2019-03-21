#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "elev_driver.h"

void init_orderlist();
void clear_all_orders();
void set_order(int floor, elev_button_type_t button_type);
int is_active_orders();
void clear_all_orders_at_floor(int floor);



#endif
