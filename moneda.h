#include <SDL.h>
#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

typedef struct {
    int valor;
    int posX;
    int posY;
    int imgW;
    int imgH;
    char imagen[27];
    int intervalo_desaparicion;
}MONEDA;

void initMoneda(MONEDA &moneda);

void generarMoneda(MONEDA &moneda, int intervalo,int valor_intervalo_desaparicion);
int getMonedaPosX(MONEDA &moneda);
int getMonedaPosY(MONEDA &moneda);
int getMonedaImgW(MONEDA &moneda);
int getMonedaImgH(MONEDA &moneda);
char* getMonedaImagen(MONEDA &moneda);
#endif // MONEDA_H_INCLUDED
