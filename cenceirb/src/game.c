
#include <assert.h>
#include <time.h>

#include <game.h>
#include <misc.h>
#include <window.h>
#include <sprite.h>
#include <robot.h>
#include <fire.h>



struct game* game_new(void) {
	sprite_load(); // load sprites into process memory

	struct game* game = malloc(sizeof(*game));
	game->map = malloc(sizeof(struct game));
	game->map = map_get_static();
	game->fire[0] = fire_init(2,10,4);	
	game->fire[1] = fire_init(2,7,4);
	game->fire[2] = fire_init(8,5,4);
	game->fire[3] = fire_init(11,5,4);
	game->fire[4] = fire_init(5,3,4);
	game->robot = robot_init();
	// Set default location of the robot and fire
	robot_set_position(game->robot, 1, 0);
	return game;
}

void game_free(struct game* game) {
	assert(game);

	robot_free(game->robot);
	map_free(game->map);
/*	for (int i = 0; i < NB_FIRE; i++)
		if (game->fire[i] != NULL)
			fire_free(game->fire[i]);*/
}

struct map* game_get_current_map(struct game* game) {
	assert(game);
	return game->map;
}


struct robot* game_get_robot(struct game* game) {
	assert(game);
	return game->robot;
}

void game_banner_display(struct game* game) {
	assert(game);

	struct map* map = game_get_current_map(game);

	int y = (map_get_height(map)) * SIZE_BLOC;
	for (int i = 0; i < map_get_width(map); i++)
		window_display_image(sprite_get_banner_line(), i * SIZE_BLOC, y);

	int white_bloc = ((map_get_width(map) * SIZE_BLOC) - 6 * SIZE_BLOC) / 4;
	int x = white_bloc;

	x = 2 * white_bloc + 2 * SIZE_BLOC;
	window_display_image(sprite_get_water(), x, y);

	x = 2 * white_bloc + 3 * SIZE_BLOC;
	window_display_image(sprite_get_number(robot_get_nb_water(game->robot)), x, y);

}

void game_display(struct game* game) {
	assert(game);

	window_clear();
	game_banner_display(game);
	map_display(game_get_current_map(game));
	robot_display(game->robot);
	for (int i = 0; i < 5; i++)
		fire_display(game->fire[i]);

	window_refresh();
}

void verser(struct game *game) {
	for (int i = 0 ; i < NB_FIRE; i++){
		if((fire_get_x(game->fire[i])==robot_get_x(game->robot))&&(fire_get_y(game->fire[i])==robot_get_y(game->robot))&&game->robot->water>0){
			if (fire_get_size(game->fire[i])>=0){
				game->fire[i]->size -=1;
				game->robot->water -=1;
			}
/*			else if(fire_get_size(game->fire[i])==0)
			{
				game->robot->water -=1;	
				fire_free(game->fire[i]);
			}*/
		}
	}
}

static short input_keyboard(struct game* game) {
	SDL_Event event;
	struct robot* robot = game_get_robot(game);
	struct map* map = game_get_current_map(game);


	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			return 1;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				return 1;
			case SDLK_UP:
				robot_set_current_way(robot, NORTH);
				robot_move(robot, map);
				break;
			case SDLK_DOWN:
				robot_set_current_way(robot, SOUTH);
				robot_move(robot, map);
				break;
			case SDLK_RIGHT:
				robot_set_current_way(robot, EAST);
				robot_move(robot, map);
				break;
			case SDLK_LEFT:
				robot_set_current_way(robot, WEST);
				robot_move(robot, map);
				break;
			case SDLK_SPACE:
				remplir(robot, map);
				break;
			case SDLK_DOLLAR:
				verser(game);
			default:
				break;
			}

			break;
		}
	}
	return 0;
}

int game_update(struct game* game) {
	if (input_keyboard(game))
		return 1; // exit game

	return 0;
}
