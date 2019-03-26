#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

typedef enum State {MOVING, IDLE, DOOR_OPEN, STOP_FLOOR, STOP_SHAFT} state;


void button_poller();
int floor_sensor_poller();
void update_floor_lights(int last_floor);
int choose_dir(order Orderlist, elevator elev);
state next_state();

#endif
