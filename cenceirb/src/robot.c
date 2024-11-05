
#include <SDL/SDL_image.h>
#include <assert.h>

#include <robot.h>
#include <sprite.h>
#include <window.h>
#include <misc.h>
#include <constant.h>
#include <game.h>



struct robot* robot_init() {
	struct robot* robot = malloc(sizeof(*robot));
	if (!robot)
		error("Memory error");

	robot->direction = NORTH;
	robot->water = INITIAL_WATER;
	robot->capacity = CAPACITY_MAX;

	return robot;
}


void robot_set_position(struct robot *robot, int x, int y) {
	assert(robot);
	robot->x = x;
	robot->y = y;
}


void robot_free(struct robot* robot) {
	assert(robot);
	free(robot);
}

int robot_get_x(struct robot* robot) {
	assert(robot != NULL);
	return robot->x;
}

int robot_get_y(struct robot* robot) {
	assert(robot != NULL);
	return robot->y;
}

void robot_set_current_way(struct robot* robot, enum direction way) {
	assert(robot);
	robot->direction = way;
}

int robot_get_nb_water(struct robot* robot) {
	assert(robot);
	return robot->water;
}

void robot_inc_nb_water(struct robot* robot) {
	assert(robot);
	robot->water += 1;
}

void robot_dec_nb_water(struct robot* robot) {
	assert(robot);
	robot->water -= 1;
}

void remplir(struct robot *robot,struct map* map){
	/*FAUDRA MODIFIER LES NOTATIONS UNE FOIS LA MAP MODIFIE	ET DISCUTER DE SI ON PRENDS LES DIAGONALE*/
	int x = robot->x;
	int y = robot->y;
	if ((map_is_inside(map,x-1,y)&&(map_get_cell_type(map,x-1,y)==CELL_WATER))||(map_is_inside(map,x+1,y)&&(map_get_cell_type(map,x+1,y)==CELL_WATER))||(map_is_inside(map,x,y-1)&&(map_get_cell_type(map,x,y-1)==CELL_WATER))||(map_is_inside(map,x,y+1)&&(map_get_cell_type(map,x,y+1)==CELL_WATER))){
		//FAURA METTRE LE TEMPS ICI AUSSI
		while (robot->water<robot->capacity){
			robot_inc_nb_water(robot);
		}
	}
}

static int robot_move_aux(struct robot* robot, struct map* map, int x, int y) {

	if (!map_is_inside(map, x, y))
		return 0;

	switch (map_get_cell_type(map, x, y)) {
	case CELL_SCENERY:
		return 1;																// IL FAUT QUE JE GERE LA VITESSE DE MON ROBOT ICI
		break;

	case CELL_WATER:
		return 0;
		break;


	default:
		break;
	}

	// robot has moved
	return 1;
}

int robot_move(struct robot* robot, struct map* map) {
	int x = robot->x;
	int y = robot->y;
	int move = 0;

	switch (robot->direction) {
	case NORTH:
		if (robot_move_aux(robot, map, x, y - 1)) {
			robot->y--;
			move = 1;
		}
		break;

	case SOUTH:
		if (robot_move_aux(robot, map, x, y + 1)) {
			robot->y++;
			move = 1;
		}
		break;

	case WEST:
		if (robot_move_aux(robot, map, x - 1, y)) {
			robot->x--;
			move = 1;
		}
		break;

	case EAST:
		if (robot_move_aux(robot, map, x + 1, y)) {
			robot->x++;
			move = 1;
		}
		break;
	}
	return move;
}

void robot_display(struct robot* robot) {
	assert(robot);
	window_display_image(sprite_get_robot(robot->direction),robot->x * SIZE_BLOC, robot->y * SIZE_BLOC);
}

