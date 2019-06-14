#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include "mina.h"

void crearMina(MINA &mina){
    mina.id_mina = 0;
    mina.posX = 0;
    mina.posY = 0;
    mina.tipo = 0;
    strcpy(mina.imagen,"assets/images/mina.png");
}
void setMinaID(MINA &mina,int id_mina){
    mina.id_mina = id_mina;
}
void setMinaPosX(MINA &mina,int posX){
    mina.posX = posX;
}
void setMinaPosY(MINA &mina,int posy){
    mina.posY = posy;
}
void setMinaTipo(MINA &mina,int tipomina){
    mina.tipo = tipomina;
}

void initMinas(SDL_Renderer* renderer,MINA &mina){
    crearMina(mina);
    setMinaID(mina,1);
    setMinaPosX(mina,70);
    setMinaPosY(mina,0);
    int i;
    for (i=0;i<6; i++){
        crearMina(mina);
        setMinaID(mina,1);
        setMinaPosX(mina,70);
        setMinaPosY(mina,40*i);

        SDL_Surface* tmpsurface = IMG_Load(mina.imagen);
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect scrR,destR;
        destR.w = 70;
        destR.h = 40;
        destR.x = mina.posX;
        destR.y = mina.posY;
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
    }
}
