#include <SDL.h>
#include <SDL_image.h>
#include "moneda.h"

void initMoneda(SDL_Renderer* renderer,MONEDA &moneda)
{
    moneda.valor = 25;
    moneda.posX = 2;
    moneda.posY = 23;
            SDL_Surface* tmpsurface = IMG_Load("assets/images/moneda.png");
            SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
            SDL_FreeSurface(tmpsurface);
            SDL_Rect scrR,destR;
                destR.w = 70;
                destR.h = 40;
                destR.x = 0;
                destR.y = 0;
                SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}

void generarMoneda(MONEDA &moneda)
{
    moneda.posX = 3434;
}

int getMonedaPosX(MONEDA &moneda)
{
    return moneda.posX;
}
int getMonedaPosY(MONEDA &moneda)
{
    return moneda.posY;
}
