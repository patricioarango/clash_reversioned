#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdlib>
#include "moneda.h"

void initMoneda(MONEDA &moneda)
{
    strcpy(moneda.imagen,"assets/images/moneda.png");
    moneda.valor = 1;
    moneda.posX = 0;
    moneda.posY = 0;
    moneda.imgW = 70;
    moneda.imgH = 70;
}

void generarMoneda(MONEDA &moneda,int intervalo,int valor_intervalo_desaparicion)
{
    moneda.posX = (rand() % 13) * moneda.imgW;
    moneda.posY = (rand() % 11) * moneda.imgH;
    moneda.intervalo_desaparicion = intervalo * valor_intervalo_desaparicion;
}

int getMonedaPosX(MONEDA &moneda)
{
    return moneda.posX;
}
int getMonedaPosY(MONEDA &moneda)
{
    return moneda.posY;
}

char* getMonedaImagen(MONEDA &moneda){
    return moneda.imagen;
}

int getMonedaImgW(MONEDA &moneda){
    return moneda.imgW;
}
int getMonedaImgH(MONEDA &moneda){
    return moneda.imgH;
}

int getMonedaIntervaloDesaparicion(MONEDA &moneda){
    return moneda.intervalo_desaparicion;
}
