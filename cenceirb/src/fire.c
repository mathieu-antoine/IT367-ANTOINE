
#include <robot.h>
#include <sprite.h>
#include <window.h>
#include <misc.h>
#include <constant.h>
#include <game.h>
#include <assert.h>
#include <fire.h>
#include <robot.h>
 


struct fire *fire_init( int x, int y, int init_size) {
	struct fire *fire= malloc(sizeof(*fire));
	if (!fire)
		error("Memory error");
	fire->x=x;
	fire->y=y;
	fire->size=init_size;
	return fire;
}



void fire_free(struct fire* fire) {
	assert(fire);
	free(fire);
}

int fire_get_size(struct fire* fire){
	assert(fire);
	return fire->size;
}

int fire_get_x(struct fire *fire) {
	assert(fire);
	return fire->x;
}

int fire_get_y(struct fire *fire) {
	assert(fire);
	return fire->y;
}



void fire_set_position(struct fire *fire, int x, int y) {
	assert(fire);
	fire->x = x;
	fire->y = y;
}

void fire_display(struct fire* fire) {
	assert(fire);
	if (fire->size>=0)
		window_display_image(sprite_get_fire(fire->size),fire->x * SIZE_BLOC, fire->y * SIZE_BLOC);
}

