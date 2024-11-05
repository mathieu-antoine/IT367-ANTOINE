
#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL/SDL.h>
#include <map.h>
#include <constant.h>

// load game's sprites
void		 sprite_load();

SDL_Surface* sprite_get_robot(enum direction direction);
SDL_Surface* sprite_get_tree();
SDL_Surface* sprite_get_water();
SDL_Surface* sprite_get_stone();
SDL_Surface* sprite_get_city();
SDL_Surface* sprite_get_fire();




SDL_Surface* sprite_get_number(short number);
SDL_Surface* sprite_get_banner_water();
SDL_Surface* sprite_get_banner_line();

#endif /* SPRITE_H_ */
