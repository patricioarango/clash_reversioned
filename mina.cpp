#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdlib>
#include "mina.h"

void crearMina(MINA &mina){
    mina.id_mina = 0;
    mina.posX = (rand() % 13) * mina.imgW;
    mina.posY = (rand() % 11) * mina.imgH;
    mina.tipo = 0;
    mina.imgW = 70;
    mina.imgH = 70;
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

int getMinaPosX(MINA &mina){
    return mina.posX;
}

int getMinaPosY(MINA &mina){
    return mina.posY;
}

int getMinaImgW(MINA &mina){
    return mina.imgW;
}

int getMinaImgH(MINA &mina){
    return mina.imgH;
}

char* getMinaImg(MINA &mina){
    return mina.imagen;
}

void initMinas(SDL_Renderer* renderer,MINA &mina){
    int i;
    for (i=1;i<=6; i++){
        crearMina(mina);
        setMinaID(mina,1);
        setMinaPosX(mina,70*(i+1));
        if (i == 1){
            setMinaPosY(mina,70);
        }
        if (i == 2){
            setMinaPosY(mina,210);
        }
        if (i == 3){
            setMinaPosY(mina,250);
        }
        if (i == 4){
            setMinaPosY(mina,320);
        }
        if (i == 5){
            setMinaPosY(mina,540);
        }
        if (i == 6){
            setMinaPosY(mina,630);
        }
        SDL_Surface* tmpsurface = IMG_Load(mina.imagen);
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect scrR,destR;
        destR.w = mina.imgW;
        destR.h = mina.imgH;
        destR.x = mina.posX;
        destR.y = mina.posY;
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
    }
}
