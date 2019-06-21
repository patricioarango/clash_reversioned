#include <SDL.h>
#include <SDL_image.h>
#include "casillero.h"
#include <string.h>
void initCasilleros(SDL_Renderer* renderer,CASILLERO &casillero,JUEGO &juego)
{
        int i,j;
        for (i=0; i<=getJuegoColumnas(juego);i++){
            for (j=0;j<=getJuegoFilas(juego);j++){
            SDL_Surface* tmpsurface = IMG_Load("assets/images/suelo_1.png");
            SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
            SDL_FreeSurface(tmpsurface);
            SDL_Rect scrR,destR;
                destR.w = 40;
                destR.h = 40;
                destR.x = 40*i;
                destR.y = 40*j;
                SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
            }
        }
}
