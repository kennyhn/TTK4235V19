#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

typedef enum State {MOVING, IDLE, DOOR_OPEN, STOP_FLOOR, STOP_SHAFT} state;

state next_state();
void poller();
void update_floor_lights(int last_floor);
#endif
