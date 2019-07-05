#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include "estacion.h"

void setEstacionPosX(ESTACION &estacion, int pos){
    estacion.posX = pos;
}
void setEstacionPosY(ESTACION &estacion, int pos){
    estacion.posY = pos;
}

int getEstacionPosX(ESTACION &estacion){
    return estacion.posX;
}
int getEstacionPosY(ESTACION &estacion){
    return estacion.posY;
}

void initEstacion(SDL_Renderer* renderer,ESTACION &estacion){
        strcpy(estacion.imagen,"assets/images/estacion.png");
        estacion.imgH = 40;
        estacion.imgW = 40;
        SDL_Surface* tmpsurface = IMG_Load(estacion.imagen);
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect scrR,destR;
        destR.w = 40;
        destR.h = 40;
        destR.x = estacion.posX;
        destR.y = estacion.posY;
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}
