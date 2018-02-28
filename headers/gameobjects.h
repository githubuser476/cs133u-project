#ifndef _GAMEOBJECTS_H_
#define _GAMEOBJECTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

enum piecetype{PLAYER_TYPE, MONSTER_TYPE};
enum direction{MVUP, MVDOWN, MVLEFT, MVRIGHT};


struct gamepiece{
    SDL_Rect * rect;
    SDL_Texture * img;
    enum piecetype type;
};

typedef struct gamepiece gamepiece;
typedef enum piecetype piecetype;

gamepiece * create_piece(int x, int y, SDL_Texture * img, enum piecetype type);
int move_piece(gamepiece * piece, enum direction direc);
int destroy_piece(gamepiece * piece);

#endif