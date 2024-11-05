
#ifndef CONSTANT_H_
#define CONSTANT_H_

#define WINDOW_NAME "Censeirb 20$ sur steam en prèvente"

// Size (# of pixels) of a cell of the map
#define SIZE_BLOC       40

// Size (# of pixels) of banner
#define LINE_HEIGHT	4
#define BANNER_HEIGHT	40

// Time management
#define DEFAULT_GAME_FPS 30

// map size
#define STATIC_MAP_WIDTH  12
#define STATIC_MAP_HEIGHT 12

#define NB_FIRE 5

enum direction {
	NORTH = 0,
	EAST,  // 1
	SOUTH, // 2
	WEST   // 3
};

enum fire_size {
	SIZE_1 = 0,
	SIZE_2,
	SIZE_3,
	SIZE_4,
	SIZE_5
};

//robot
#define CAPACITY_MAX 9
#define INITIAL_WATER 0

#endif /* CONSTANT */
