#include "elev_driver.h"
#include "order_manager.h"
#include "controller.h"
#include <stdio.h>



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
    init_orderlist();
    while (1) {

        poller();
        //update_floor_lights();
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
