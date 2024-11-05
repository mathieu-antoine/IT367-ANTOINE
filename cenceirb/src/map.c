
#include <SDL/SDL_image.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <map.h>
#include <constant.h>
#include <misc.h>
#include <sprite.h>
#include <window.h>

struct map {
	int width;
	int height;
	unsigned char* grid;
};

#define CELL(i,j) ( (i) + (j) * map->width) 

struct map* map_new(int width, int height)
{
	assert(width > 0 && height > 0);

	struct map* map = malloc(sizeof *map);
	if (map == NULL )
		error("map_new : malloc map failed");

	map->width = width;
	map->height = height;

	map->grid = malloc(height * width);
	if (map->grid == NULL) {
		error("map_new : malloc grid failed");
	}

	// Grid cleaning
	int i, j;
	for (i = 0; i < width; i++)
	  for (j = 0; j < height; j++)
	    map->grid[CELL(i,j)] = CELL_EMPTY;

	return map;
}

int map_is_inside(struct map* map, int x, int y)			
{	
	assert(map);			
	if ( (x < map->width) & (y < map->height) & ( -1 < x) & ( -1 < y))					
		return 1;											
	else 													
		return 0;											
}

void map_free(struct map *map)
{
	if (map == NULL )
		return;
	free(map->grid);
	free(map);
}

int map_get_width(struct map* map)
{
	assert(map != NULL);
	return map->width;
}

int map_get_height(struct map* map)
{
	assert(map);
	return map->height;
}

enum cell_type map_get_cell_type(struct map* map, int x, int y)
{
	assert(map && map_is_inside(map, x, y));
	return map->grid[CELL(x,y)] & 0xf0;
}

enum compose_type map_get_compose_type(struct map* map, int x, int y){
	assert(map && map_is_inside(map, x, y));
	return map->grid[CELL(x,y)];
}

void map_set_cell_type(struct map* map, int x, int y, enum cell_type type)
{
	assert(map && map_is_inside(map, x, y));
	map->grid[CELL(x,y)] = type;
}

void map_set_compose_type(struct map*map, int x,int y, enum compose_type type){
	assert(map && map_is_inside(map, x, y));
	map->grid[CELL(x,y)] = type;
}


void display_scenery(struct map* map, int x, int  y, unsigned char type)
{
	switch (type & 0x0f) { // sub-types are encoded with the 4 less significant bits
	case SCENERY_STONE:
		window_display_image(sprite_get_stone(), x, y);
		break;

	case SCENERY_TREE:
		window_display_image(sprite_get_tree(), x, y);
		break;
	
	case SCENERY_CITY:
		window_display_image(sprite_get_city(), x, y);
		break;
	}
}

void map_display(struct map* map)
{
	assert(map != NULL);
	assert(map->height > 0 && map->width > 0);

	int x, y;
	for (int i = 0; i < map->width; i++) {
	  for (int j = 0; j < map->height; j++) {
	    x = i * SIZE_BLOC;
	    y = j * SIZE_BLOC;

	    unsigned char type = map->grid[CELL(i,j)];
	    
	    switch (type & 0xf0) {
		case CELL_SCENERY:
		  display_scenery(map, x, y, type);
		  break;
	    case CELL_WATER:
	      window_display_image(sprite_get_water(), x, y);
	      break;


	    }
	  }
	}
}

int *taille(char *fichier){ // Récupères la taille de la matrice
    FILE *file=fopen(fichier,"r");
    int ligne=0;
    int colonne=1;
    char c;
    while (( c= fgetc(file)) != EOF){
        if ( c== '\n'){
            ligne++;
        }
        if ( (c==' ') && (ligne==0) ){
            colonne++;
        }
    }
    fclose(file);
    int *size1 = malloc(sizeof(int)*2);
    size1[0]=ligne; size1[1]=colonne;
    return size1;
}


void parser(char *fichier, int *tableau){
    FILE *file=fopen(fichier,"r");
    int i=0;
    int c;
    while (( c= fgetc(file)) != EOF){
        if ((c!=' ')&&(c!='\n')){
            tableau[i]=c-48;
            i++;
        }
    } 
}

struct map* map_get_static(void)
{
	int *size=taille("src/carte.txt");
	struct map* map = map_new(size[0], size[1]);
	int *tableau = malloc(sizeof(int)*(size[0]*size[1]));
	parser("src/carte.txt",tableau);
	for (int i = 0; i < size[0] * size[1]; i++){
        if (tableau[i]==5){
            map->grid[i]=CELL_EMPTY;
        }
        if (tableau[i]==4){
            map->grid[i]=CELL_CITY;
        }
        if (tableau[i]==3){
            map->grid[i]=CELL_STONE;
        }
        if (tableau[i]==2){
            map->grid[i]=CELL_TREE;
        }
        if (tableau[i]==0){
            map->grid[i]=CELL_WATER;
        }
	}
	return map;
}