#include <SDL.h>
#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

typedef struct{
    int f;
    int c;
	SDL_Texture *imagen;
    SDL_Rect rectImag;
}CASILLERO;

void initCasillero(SDL_Renderer* renderer,CASILLERO &casillero);
#endif // CASILLERO_H_INCLUDED
