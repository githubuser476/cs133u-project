/*author    : russ loewe
 * date     : 20 feb 2018
 * file     : init.c
 * purpose:
 *          Initialize the SDL video whatever and open a screen. Largly
 *          taken from SDL's doc pages.
 */
#include "./headers/init.h"

int init_video(void){
    
    SDL_Surface *screen;  //declar pointer to SDL Surface
    
    /*
     * Initialize the SDL subsytem for video only. 
     * If initai
     */ 
    if( SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("ERROR: init.c -> init_video -> SDL_Init\n");
        SDL_GetError();
        return 1;
    }
    
    /*
     * Open a screen 640 by 480, no frame with the double buffer feature 
     * to speed rendering.
     */
    screen = SDL_SetVideoMode(640, 480, 0, SDL_HWPALETTE|SDL_NOFRAME|SDL_DOUBLEBUF);
    
    if(screen == NULL){
        printf("ERROR: init.c -> init_video -> SDL_SetVideoMode \n");
        SDL_GetError();
        return 1;
    }
    
    
    return 0;
}

void cleanup(){
    /*
     * Close down whatever SDL is doing or you might get a runaway screen
     */
    SDL_Quit();
}