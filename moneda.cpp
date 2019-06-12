#include "moneda.h"

void initMoneda(MONEDA &moneda)
{
    moneda.valor = 25;
    moneda.posX = 2;
    moneda.posY = 23;
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
