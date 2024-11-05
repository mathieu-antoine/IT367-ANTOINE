#ifndef MAP_H_
#define MAP_H_

enum cell_type {
	CELL_EMPTY=0x00,   		//  0000 0000
	CELL_SCENERY=0x10, 		//  0001 0000
	CELL_WATER=0x20,   		//  0010 0000


};

/* enum bonus_type {
	BONUS_FIRE_RANGE_DEC=1,
	BONUS_FIRE_RANGE_INC,
	BONUS_FIRE_NB_DEC,
	BONUS_FIRE_NB_INC,
	BONUS_MONSTER,
	BONUS_LIFE
};  */

enum scenery_type {
	SCENERY_STONE = 1,    // 0001 
	SCENERY_TREE  = 2,    // 0010 
	SCENERY_CITY = 4  // 0100 
};

enum compose_type {
	CELL_TREE     = CELL_SCENERY | SCENERY_TREE,
	CELL_STONE    = CELL_SCENERY | SCENERY_STONE,
	CELL_CITY = CELL_SCENERY | SCENERY_CITY,

/*  CELL_WATER_RANGEINC = CELL_WATER | BONUS_FIRE_RANGE_DEC,
    CELL_WATER_RANGEDEC = CELL_WATER | BONUS_FIRE_RANGE_INC,
	CELL_WATER_FIREINC  = CELL_WATER | BONUS_FIRE_NB_DEC,
    CELL_WATER_FIREDEC  = CELL_WATER | BONUS_FIRE_NB_INC,
    CELL_WATER_LIFE     = CELL_WATER | BONUS_MONSTER,
    CELL_WATER_MONSTER  = CELL_WATER | BONUS_LIFE,
*/
};

struct map;

// Create a new empty map
struct map* map_new(int width, int height);
void map_free(struct map* map);


// Return the height and width of a map
int map_get_width(struct map* map);
int map_get_height(struct map* map);

// Return the type of a cell
enum cell_type map_get_cell_type(struct map* map, int x, int y);

enum compose_type map_get_compose_type(struct map* map, int x, int y);


// Set the type of a cell
void  map_set_cell_type(struct map* map, int x, int y, enum cell_type type);

void map_set_compose_type(struct map*map, int x,int y, enum compose_type type);

// Test if (x,y) is within the map
int map_is_inside(struct map* map, int x, int y);

// Return a default static map
struct map* map_get_static();

// Display the map on the screen
void map_display(struct map* map);

#endif /* MAP_H_ */
