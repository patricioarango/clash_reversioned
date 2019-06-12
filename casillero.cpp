#include <SDL.h>
#include <SDL_image.h>
#include "casillero.h"

void initCasillero(SDL_Renderer* renderer,CASILLERO &casillero)
{
    //casillero.imagen = IMG_LoadTexture(renderer,"img/suelo_0.png");
    casillero.rectImag.y=0;//coordenada de dibujo y
    casillero.rectImag.x=0;//coordenada de dibujo x
    casillero.rectImag.w = 70;//ancho
    casillero.rectImag.h = 40;//alto
        SDL_Surface* tmpsurface = IMG_Load("assets/images/suelo_0.png");
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect scrR,destR;
        destR.w = 70;
        destR.h = 40;
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}
