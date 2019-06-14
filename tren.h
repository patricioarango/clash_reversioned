#include <string>
#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED

typedef struct{
    int posX;
    int posY;
    char imagen[27];
    int carga;
    int tipo_carga;
}VAGON;

typedef struct {
    int posX = 0;
    int posY = 0;
    int imgW;
    int imgH;
    int monedas;
    int direccion = 1; //0 arriba, 1 der, 2 abajo, 3 izq
    int tipo_direccion = 1; //1 suma 0 resta
    char imagen[27];
    VAGON *vagon;
}TREN;

void initTren(SDL_Renderer* renderer,TREN &tren);
void setTrenDireccion(TREN &tren,int direccion);
void setTrenImagenporDireccion(TREN &tren,int direccion);
void setTrenTipoDireccion(TREN &tren,int tipo_direccion);
void setTrenPosX(TREN &tren,int posicion);
void setTrenPosY(TREN &tren,int posicion);
void setTrenImgW(TREN &tren, int img);
void setTrenImgH(TREN &tren, int img);

int getTrenPosX(TREN &tren);
int getTrenPosY(TREN &tren);
char* getTrenImagen(TREN &tren);
int getTrenImgW(TREN &tren);
int getTrenImgH(TREN &tren);
#endif // TREN_H_INCLUDED
