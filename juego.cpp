#include "juego.h"

void initJuego(JUEGO &juego)
{
    juego.intervalo = 1;
    juego.GameisnotOver = true;
}

void setJuegoIntervalo(JUEGO &juego, int intervalo)
{
    juego.intervalo = intervalo;
}

void setJuegoIntervaloMoneda(JUEGO &juego, int intervalo)
{
    juego.intervaloMoneda = intervalo;
}

void setJuegoGameisnotOver(JUEGO &juego, bool gameisnotover)
{
    juego.GameisnotOver = gameisnotover;
}

void setJuegoAnchoVentana(JUEGO &juego,int ancho)
{
    juego.anchoVentana = ancho;
}
void setJuegoAltoVentana(JUEGO &juego,int alto)
{
    juego.altoVentana = alto;
}

int getJuegoIntervalo(JUEGO &juego)
{
    return juego.intervalo;
}

int getJuegoIntervaloMoneda(JUEGO &juego)
{
    return juego.intervaloMoneda;
}

bool getJuegoGameisnotOver(JUEGO &juego)
{
    return juego.GameisnotOver;
}

int getJuegoAnchoVentana(JUEGO &juego)
{
    return juego.anchoVentana;
}
int getJuegoAltoVentana(JUEGO &juego)
{
    return juego.altoVentana;
}
