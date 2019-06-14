#include <string>
#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED

typedef struct {
    int posX = 0;
    int posY = 0;
    int direccion = 1; //0 arriba, 1 der, 2 abajo, 3 izq
    int tipo_direccion = 1; //1 suma 0 resta
    char imagen[27];
}TREN;

void initTren(SDL_Renderer* renderer,TREN &tren);
void setTrenDireccion(TREN &tren,int direccion);
void setTrenImagenporDireccion(TREN &tren,int direccion);
void setTrenTipoDireccion(TREN &tren,int tipo_direccion);
int getTrenImagen(TREN &tren);
#endif // TREN_H_INCLUDED
