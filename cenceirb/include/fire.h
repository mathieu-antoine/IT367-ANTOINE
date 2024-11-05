#ifndef FIRE_H_
#define FIRE_H_


struct fire{
	int x;
	int y;
	int size;
};

struct fire *fire_init( int x, int y, int init_size);

int fire_get_x(struct fire *fire);

int fire_get_y(struct fire *fire);

void verser(struct game * game);

void fire_free(struct fire* fire);

int fire_get_size(struct fire* fire);



void fire_display(struct fire* fire);

#endif /* FIRE_H_ */
