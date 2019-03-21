#include "elev_driver.h"
#include "order_manager.h"
#include <stdio.h>

typedef enum State {MOVING, IDLE, DOOR_OPEN, STOP_FLOOR, STOP_SHAFT} state;


/*
    elev_motor_direction_t
    BUTTON_CALL_UP
    BUTTON_CALL_DOWN
    BUTTON_COMMAND
*/




int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    elev_set_motor_direction(DIRN_UP);
    init_orderlist();
    while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }

    return 0;
}