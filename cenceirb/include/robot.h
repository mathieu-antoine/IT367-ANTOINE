
#ifndef ROBOT_H_
#define ROBOT_H_

#include <map.h>
#include <constant.h>

struct robot {
	int x, y;
	enum direction direction;
	int water;
	int capacity;
};

// Creates a new robot with a given number of available water
struct robot* robot_init();
void   robot_free(struct robot* robot);

// Set the position of the robot
void robot_set_position(struct robot *robot, int x, int y);

// Returns the current position of the robot
int robot_get_x(struct robot* robot);
int robot_get_y(struct robot* robot);

// Set the direction of the next move of the robot
void robot_set_current_way(struct robot * robot, enum direction direction);

// Set, Increase, Decrease the number of water that robot can put
int  robot_get_nb_water(struct robot * robot);
void robot_inc_nb_water(struct robot * robot);
void robot_dec_nb_water(struct robot * robot);

// Move the robot according to the current direction
int robot_move(struct robot* robot, struct map* map);

// Display the robot on the screen
void robot_display(struct robot* robot);

void remplir(struct robot *robot,struct map* map);


#endif /* ROBOT_H_ */
