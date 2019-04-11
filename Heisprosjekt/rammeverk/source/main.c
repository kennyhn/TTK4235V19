/**@file main.c
*@brief The main file for the elevator.
*/

#include "elev_driver.h"
#include "order_manager.h"
#include "controller.h"
#include "state_machine.h"
#include "timer.h"
#include "elevator.h"

#include <stdio.h>





int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    elev_motor_direction_t motor_dir;
    init_orderlist();
    state_init();
    while (1) {
        button_poller();
        floor_sensor_poller();

        state current_state = next_state();
        switch(current_state){

            case STOP_SHAFT:
                state_STOP_shaft();
                break;
            case STOP_FLOOR:
                state_STOP_floor();
            case DOOR_OPEN:
                state_door_open();
            case IDLE:
                state_idle();
                break;
            case MOVING:
                motor_dir = choose_dir();
                state_moving(motor_dir);
                break;
        }
    }

    return 0;
}
