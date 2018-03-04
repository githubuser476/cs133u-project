#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "gameobjects.h"

int init_video(void);
void cleanup();
SDL_Texture * load_image(char * filename);
int render_objects( gamepiece * pieces[]);
SDL_Texture * make_colored_texture(int height, int width, Uint8 red, Uint8 blue, Uint8 green);
int render_background();



#endif