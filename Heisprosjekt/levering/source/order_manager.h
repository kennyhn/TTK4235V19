/**@file order_manager.h
 * @brief Functions for how the elevator should handle orders.
 */

#ifndef __ORDER_MANAGER_H__
#define __ORDER_MANAGER_H__

#include "elev_driver.h"
/**
 * At which floor and what type an order is. Active says if the order has been taken or not.
 */
typedef struct Order {
    int floor;
    elev_button_type_t button_type;
    int active; //used as boolean
}order;

/**
 * @brief Intialize a list of orders and sets all orders to be inactive.
 *
 */
void init_orderlist();

/**
 * @brief Sets all orders to be inactive.
 */

void clear_all_orders();

/**
 * @brief Sets all orders at @p floor to inactive and updates button lights.
 *
 * @param[in] floor The floor you want to clear all orders at.
 *
 */

void clear_all_orders_at_floor(int floor);

/**
 * @brief Sets an order to active and updates order lights.
 *
 * @param[in] floor At which floor the order is at
 * @param[in] button_type If the order is UP, DOWN or COMMAND.
 *
 */

void set_order(int floor, elev_button_type_t button_type);

/**
 * @brief Gets order given by @p floor and @p button_type.
 *
 * @param[in] floor At which floor we want the order from.
 * @param[in] button_type If we want the order for UP, DOWN or COMMAND.
 *
 * @return The order at the place in Orderlist given by the parameters.
 */

order get_order(int floor, elev_button_type_t button_type);

/**
 * @brief Checks if it is any orders above @p current_floor.
 *
 * @param[in] current_floor The floor we want to check if it is any orders above.
 *
 * @return 1 if any orders above, 0 if not.
 */

int orders_above(int current_floor);

/**
 * @brief Checks if it is any orders below @p current_floor.
 *
 * @param[in] current_floor The floor we want to check if it is any orders below.
 *
 * @return 1 if any orders below, 0 if not.
 */

int orders_below(int current_floor);

/**
 * @brief Goes through the Orderlist and checks if it is any active orders.
 *
 * @return 1 if any active orders, 0 if not.
 */

int is_active_orders();

/**
 * @brief Checks if an order is at a given floor and if the elevator should stop.
 *        The elevator should only stop if the elevator's motor direction and order is in the same direction.
 *
 * @param[in] floor The floor we want to check if it is any orders at.
 * @param[in] motor_dir Motor direction of the elevator
 *
 * @return 1 if order at floor and the elevator should stop, 0 if not.
 */

int is_order_at_floor(int floor, elev_motor_direction_t motor_dir);

/**
 * @brief Updates button lights. Turns off lights if order at floor is completed.
 *
 */

void update_button_lights();



#endif
