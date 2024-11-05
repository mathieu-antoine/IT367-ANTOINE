
#include <SDL/SDL_image.h>
#include <assert.h>

#include <sprite.h>
#include <misc.h>

// Sprites general
#define MAP_WATER		"sprite/water.png"

// Sprites fire
#define FIRE_1			"sprite/flamme1.png"		
#define FIRE_2			"sprite/flamme2.png"
#define FIRE_3			"sprite/flamme3.png"
#define FIRE_4			"sprite/flamme4.png"
#define FIRE_5			"sprite/flamme5.png"




// Scenery elements
#define MAP_STONE		"sprite/stone.png"
#define MAP_TREE        "sprite/tree.png"
#define MAP_CITY      	"sprite/city.png"


// Sprites of Banner
#define BANNER_LINE		"sprite/banner_line.png"
#define DIGIT_0			"sprite/banner_0.jpg"
#define DIGIT_1			"sprite/banner_1.jpg"
#define DIGIT_2			"sprite/banner_2.jpg"
#define DIGIT_3			"sprite/banner_3.jpg"
#define DIGIT_4			"sprite/banner_4.jpg"
#define DIGIT_5			"sprite/banner_5.jpg"
#define DIGIT_6			"sprite/banner_6.jpg"
#define DIGIT_7			"sprite/banner_7.jpg"
#define DIGIT_8			"sprite/banner_8.jpg"
#define DIGIT_9			"sprite/banner_9.jpg"




// Sprites of ROBOTs
#define ROBOT_LEFT     "sprite/robot.png"
#define ROBOT_UP       "sprite/robot.png"
#define ROBOT_RIGHT    "sprite/robot.png"
#define ROBOT_DOWN     "sprite/robot.png"

// banner
SDL_Surface* numbers[10];
SDL_Surface* banner_line;

// map
SDL_Surface* city;
SDL_Surface* goal;
SDL_Surface* water;
SDL_Surface* stone;
SDL_Surface* tree;



// ROBOT
SDL_Surface* ROBOT_img[4];

//FIRE
SDL_Surface* FIRE[5];

static void banner_load() {
	// numbers imgs
	numbers[0] = image_load(DIGIT_0);
	numbers[1] = image_load(DIGIT_1);
	numbers[2] = image_load(DIGIT_2);
	numbers[3] = image_load(DIGIT_3);
	numbers[4] = image_load(DIGIT_4);
	numbers[5] = image_load(DIGIT_5);
	numbers[6] = image_load(DIGIT_6);
	numbers[7] = image_load(DIGIT_7);
	numbers[8] = image_load(DIGIT_8);
	numbers[9] = image_load(DIGIT_9);

	// other banner sprites
	banner_line = image_load(BANNER_LINE);
}

static void banner_unload() {
	// numbers imgs
	for (int i = 0; i < 10; i++) {
		SDL_FreeSurface(numbers[i]);
	}
}

static void map_load() {
	// Sprite loading
	tree = image_load(MAP_TREE);
	water = image_load(MAP_WATER);
	stone = image_load(MAP_STONE);
	city = image_load(MAP_CITY);
}

static void map_unload() {
	SDL_FreeSurface(tree);
	SDL_FreeSurface(water);
	SDL_FreeSurface(goal);
	SDL_FreeSurface(stone);
	SDL_FreeSurface(city);
}


static void ROBOT_load() {
	ROBOT_img[WEST] = image_load(ROBOT_LEFT);
	ROBOT_img[EAST] = image_load(ROBOT_RIGHT);
	ROBOT_img[NORTH] = image_load(ROBOT_UP);
	ROBOT_img[SOUTH] = image_load(ROBOT_DOWN);
}

static void ROBOT_unload() {
	for (int i = 0; i < 4; i++)
		SDL_FreeSurface(ROBOT_img[i]);
}

static void FIRE_load() {
	FIRE[SIZE_1] = image_load(FIRE_1);
	FIRE[SIZE_2] = image_load(FIRE_2);
	FIRE[SIZE_3] = image_load(FIRE_3);
	FIRE[SIZE_4] = image_load(FIRE_4);
	FIRE[SIZE_5] = image_load(FIRE_5);
}

static void FIRE_unload() {
	for (int i = 0; i < 5; i++)
		SDL_FreeSurface(FIRE[i]);
}


void sprite_load() {
	map_load();
	banner_load();
	ROBOT_load();
	FIRE_load();
}

void sprite_free() {
	map_unload();
	banner_unload();
	ROBOT_unload();
	FIRE_unload();
}

SDL_Surface* sprite_get_number(short number) {
	assert(number >= 0 && number < 10);
	return numbers[number];
}

SDL_Surface* sprite_get_robot(enum direction direction) {
	assert(ROBOT_img[direction]);
	return ROBOT_img[direction];
}

SDL_Surface* sprite_get_fire(enum fire_size fire_size) {
	assert(FIRE[fire_size]);
	return FIRE[fire_size];
}




SDL_Surface* sprite_get_banner_line() {
	assert(banner_line);
	return banner_line;
}


SDL_Surface* sprite_get_tree() {
	assert(tree);
	return tree;
}

SDL_Surface* sprite_get_water() {
	assert(water);
	return water;
}


SDL_Surface* sprite_get_stone() {
	assert(stone);
	return stone;
}

SDL_Surface* sprite_get_city() {
	assert(city);
	return city;
}


