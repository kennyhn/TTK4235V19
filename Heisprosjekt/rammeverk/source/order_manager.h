#ifndef __ORDER_MANAGER_H__
#define __ORDER_MANAGER_H__

#include "elev_driver.h"

typedef struct Order {
    int floor;
    elev_button_type_t button_type;
    int active; //used as boolean
}order;

/**
 * @brief Intialize the orderlist and sets all orders to be inactive.
 *
 */
void init_orderlist();

/**
 * @brief Sets all orders to be inactive.
 */

void clear_all_orders();

/**
 * @brief Sets all orders at the floor to inactive and updates button lights(????).
 *
 * @param[in] floor The floor you want to clear all orders at.
 *
 */

void clear_all_orders_at_floor(int floor);

/**
 * @brief Sets an order to active and updates order lights.
 *
 * @param[in] floor At which floor the order is at
 * @param[in] button_type If the order is UP, DOWN or CAB
 *
 */

void set_order(int floor, elev_button_type_t button_type);

/**
 * @brief Gets order given of the parameteres.
 *
 * @param[in] floor At which floor we want the order from.
 * @param[in] button_type If we want the order for UP, DOWN or CAB. (?????)
 *
 * @return The order at the place in Orderlist given by the parameters.
 */

order get_order(int floor, elev_button_type_t button_type);

/**
 * @brief Checks if it is any orders above the given floor.
 *
 * @param[in] current_floor The floor we want to check if it is any orders above.
 *
 * @return 1 if any orders above, 0 if not.
 */

int orders_above(int current_floor);

/**
 * @brief Checks if it is any orders below the given floor.
 *
 * @param[in] current_floor The floor we want to check if it is any orders below.
 *
 * @return 1 if any orders below, 0 if not.
 */

int orders_below(int current_floor);

/**
 * @brief Goes through the orderlist and Checks if it is any active orders.
 *
 * @return 1 if any active orders, 0 if not.
 */

int is_active_orders();

/**
 * @brief Checks if an order is at a given floor and if the elevator should stop.
 *        The elevator should only stop if the elevator's motor direction and order is in the same direction.
 *
 * @param[in] floor The floor we want to check if it is any orders at.
 * @param[in] motor_dir Motor direction of elevator
 *
 * @return 1 if it is order at floor and the elevator should stop, 0 if not.
 */

int is_order_at_floor(int floor, elev_motor_direction_t motor_dir);

/**
 * @brief Updates button lights. Turns off lights if order at floor is completed.
 *
 */

void update_button_lights();



#endif
