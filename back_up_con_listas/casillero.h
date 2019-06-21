#include <SDL.h>
#include "juego.h"
#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

typedef struct{
    int f;
    int c;
} CASILLERO;

void initCasilleros(SDL_Renderer* renderer,CASILLERO &casillero,JUEGO &juego);
#endif // CASILLERO_H_INCLUDED
