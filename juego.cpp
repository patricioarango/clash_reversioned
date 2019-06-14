#include "juego.h"

void initJuego(JUEGO &juego)
{
    juego.intervalo = 1;
    juego.direccion_previa = 1;
    juego.direccion_siguiente = 1;
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

void setJuegoDireccionPrevia(JUEGO &juego,int direccion){
    juego.direccion_previa = direccion;
}

void setJuegoDireccionSiguiente(JUEGO &juego,int direccion){
    juego.direccion_siguiente = direccion;
}
void setJuegoGameisnotOver(JUEGO &juego, bool gameisnotover);

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

int getJuegoDireccionPrevia(JUEGO &juego){
    return juego.direccion_previa;
}
int getJuegoDireccionSiguiente(JUEGO &juego){
    return juego.direccion_siguiente;
}
