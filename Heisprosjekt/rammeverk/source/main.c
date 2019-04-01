#include "elev_driver.h"
#include "order_manager.h"
#include "controller.h"
#include "state_machine.h"
#include "timer.h"
#include "elevator.h"

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

    elev_motor_direction_t motor_dir;
    init_orderlist();
    state_init();
    while (1) {
        button_poller();
        floor_sensor_poller();
       
        state current_state = next_state();
        switch(current_state){
            case STOP_SHAFT:
                printf("STOP SHAFT\n");
                break;
            case STOP_FLOOR:
                printf("STOP FLOOR\n");
                break;
            case DOOR_OPEN:
                printf("DOOR OPEN\n");
                break;
            case IDLE:
                printf("IDLE\n");
                break;
            case MOVING:
                printf("MOVING\n");
                break;
        }
        switch(current_state){
            
            case STOP_SHAFT:
                printf("STOP SHAFT\n");
                state_STOP_shaft();
                break;
            case STOP_FLOOR:
                printf("STOP FLOOR\n");
                state_STOP_floor();
            case DOOR_OPEN:
                printf("DOOR OPEN\n");
                state_door_open();
            case IDLE:
                printf("IDLE\n");
                state_idle();
                break;
            case MOVING:
                motor_dir = choose_dir();
                switch(get_last_motor_dir()) {
                    case DIRN_UP:
                        printf("OPP\n");
                        break;
                    case DIRN_STOP:
                        printf("stop\n");
                        break;
                    case DIRN_DOWN:
                        printf("Ned\n");
                        break;
                }
                state_moving(motor_dir);
                break;
        }
    }
    
    return 0;
}
