#include "juego.h"

void initJuego(JUEGO &juego)
{
    juego.intervalo = 1;
    juego.direccion_previa = 1;
    juego.direccion_siguiente = 1;
    juego.GameisnotOver = true;
    juego.noEstaPausado = true;
}

void setJuegoIntervalo(JUEGO &juego, int intervalo)
{
    juego.intervalo = intervalo;
}

void setJuegoIntervaloMoneda(JUEGO &juego, int intervalo)
{
    juego.intervaloMoneda = intervalo;
}

void setintervaloDesaparicionMoneda(JUEGO &juego,int intervalo)
{
    juego.intervaloDesaparicionMoneda = intervalo;
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

void setJuegonoEstaPausado(JUEGO &juego, bool pausa){
    juego.noEstaPausado = pausa;
}

void setJuegoFilas(JUEGO &juego,int filas){
    juego.filas = filas;
}
void setJuegoColumnas(JUEGO &juego,int columnas){
    juego.columnas = columnas;
}

int getJuegoIntervalo(JUEGO &juego)
{
    return juego.intervalo;
}

int getJuegoIntervaloMoneda(JUEGO &juego)
{
    return juego.intervaloMoneda;
}

int getintervaloDesaparicionMoneda(JUEGO &juego)
{
    return juego.intervaloDesaparicionMoneda;
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

bool getJuegoNoEstaPausado(JUEGO &juego){
    return juego.noEstaPausado;
}

int getJuegoFilas(JUEGO &juego){
    return juego.filas;
}

int getJuegoColumnas(JUEGO &juego){
    return juego.columnas;
}
