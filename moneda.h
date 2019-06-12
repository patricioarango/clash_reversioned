#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

typedef struct {
    int valor;
    int posX;
    int posY;
}MONEDA;

void initMoneda(MONEDA &moneda);

void generarMoneda(MONEDA &moneda);
int getMonedaPosX(MONEDA &moneda);
int getMonedaPosY(MONEDA &moneda);

#endif // MONEDA_H_INCLUDED
