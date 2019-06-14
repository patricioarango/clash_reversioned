#include <string>
#include <cstring>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "tren.h"

void setTrenImagenporDireccion(TREN &tren,int direccion){
    if (direccion == 0){
        strcpy(tren.imagen,"assets/images/c1/arr/0.png");
    }
    if (direccion == 1){
        strcpy(tren.imagen,"assets/images/c1/der/0.png");
    }
    if (direccion == 2){
        strcpy(tren.imagen,"assets/images/c1/aba/0.png");
    }
    if (direccion == 3){
        strcpy(tren.imagen,"assets/images/c1/izq/0.png");
    }
}

void setTrenDireccion(TREN &tren,int direccion){
    tren.direccion = direccion;
}

char* getTrenImagen(TREN &tren){
    return tren.imagen;
}

void setTrenTipoDireccion(TREN &tren,int tipo_direccion){
    tren.tipo_direccion = tipo_direccion;
}

void initTren(SDL_Renderer* renderer,TREN &tren){
        setTrenImagenporDireccion(tren,tren.direccion);
        setTrenImgW(tren,70);
        setTrenImgH(tren,70);
        if (tren.tipo_direccion == 1 && tren.direccion == 1){
           tren.posX = tren.posX + 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 1){
            tren.posX = tren.posX - 70;
        }
        if (tren.tipo_direccion == 1 && tren.direccion == 3){
            tren.posX = tren.posX + 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 3){
            tren.posX = tren.posX - 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 2){
            tren.posY = tren.posY - 70;
        }
        if (tren.tipo_direccion == 1 && tren.direccion == 2){
            tren.posY = tren.posY + 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 0){
           tren.posY = tren.posY - 70;
        }
        if (tren.tipo_direccion == 1 && tren.direccion == 0){
            tren.posY = tren.posY + 70;
        }

     SDL_Surface* tmpsurface = IMG_Load(tren.imagen);
     SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
     SDL_FreeSurface(tmpsurface);
     SDL_Rect scrR,destR;
        destR.w = getTrenImgW(tren);
        destR.h = getTrenImgH(tren);
        destR.x = getTrenPosX(tren);
        destR.y = getTrenPosY(tren);
    SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}

int getTrenPosX(TREN &tren){
    return tren.posX;
}

int getTrenPosY(TREN &tren){
    return tren.posY;
}
void setTrenImgW(TREN &tren, int img){
    tren.imgW = img;
}
void setTrenImgH(TREN &tren, int img){
    tren.imgH = img;
}

int getTrenImgW(TREN &tren){
    return tren.imgW;
}

int getTrenImgH(TREN &tren){
    return tren.imgH;
}
