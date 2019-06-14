#include <SDL.h>
#include <SDL_image.h>
#include "casillero.h"
#include <string.h>
void initCasilleros(SDL_Renderer* renderer,CASILLERO &casillero)
{
        int i,j;
        for (i=0; i<12;i++){
            for (j=0;j<15;j++){
            SDL_Surface* tmpsurface = IMG_Load("assets/images/suelo_1.png");
            SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
            SDL_FreeSurface(tmpsurface);
            SDL_Rect scrR,destR;
                destR.w = 70;
                destR.h = 40;
                destR.x = 70*i;
                destR.y = 40*j;
                SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
            }
        }
}
