#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct {
    int intervalo;
    int intervaloMoneda;
    int intervaloDesaparicionMoneda;
    int anchoVentana;
    int altoVentana;
    int filas;
    int columnas;
    int direccion_previa;
    int direccion_siguiente;
    bool GameisnotOver;
    bool noEstaPausado;
}JUEGO;

void initJuego(JUEGO &juego);

void setJuegoIntervalo(JUEGO &juego,int intervalo);
void setJuegoIntervaloMoneda(JUEGO &juego,int intervalo);
void setintervaloDesaparicionMoneda(JUEGO &juego,int intervalo);
void setJuegoAnchoVentana(JUEGO &juego,int ancho);
void setJuegoAltoVentana(JUEGO &juego,int alto);
void setJuegoDireccionPrevia(JUEGO &juego,int direccion);
void setJuegoDireccionSiguiente(JUEGO &juego,int direccion);
void setJuegoGameisnotOver(JUEGO &juego, bool gameisnotover);
void setJuegonoEstaPausado(JUEGO &juego, bool pausa);
void setJuegoFilas(JUEGO &juego,int filas);
void setJuegoColumnas(JUEGO &juego,int columnas);

int getJuegoIntervalo(JUEGO &juego);
int getJuegoIntervaloMoneda(JUEGO &juego);
int getintervaloDesaparicionMoneda(JUEGO &juego);
bool getJuegoGameisnotOver(JUEGO &juego);
int getJuegoAnchoVentana(JUEGO &juego);
int getJuegoAltoVentana(JUEGO &juego);
int getJuegoDireccionPrevia(JUEGO &juego);
int getJuegoDireccionSiguiente(JUEGO &juego);
bool getJuegoNoEstaPausado(JUEGO &juego);
int getJuegoFilas(JUEGO &juego);
int getJuegoColumnas(JUEGO &juego);
#endif // JUEGO_H_INCLUDED
