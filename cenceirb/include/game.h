
#ifndef GAME_H_
#define GAME_H_

#include <robot.h>
#include <map.h>

struct game {
	struct map* map;      
	struct robot* robot;
	struct fire* fire[NB_FIRE-1];
};

// Create a new game
struct game* game_new();

// Free a game
void game_free(struct game* game);

// Return the robot of the current game
struct robot* game_get_robot(struct game* game);

// Return the current map
struct map* game_get_current_map(struct game* game);

// Display the game on the screen
void game_display(struct game* game);

// update
int game_update(struct game* game);

#endif /* GAME_H_ */
