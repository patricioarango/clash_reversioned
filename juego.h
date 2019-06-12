#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct {
    int intervalo;
    int intervaloMoneda;
    int anchoVentana;
    int altoVentana;
    bool GameisnotOver;
}JUEGO;

void initJuego(JUEGO &juego);

void setJuegoIntervalo(JUEGO &juego,int intervalo);
void setJuegoIntervaloMoneda(JUEGO &juego,int intervalo);
void setJuegoAnchoVentana(JUEGO &juego,int ancho);
void setJuegoAltoVentana(JUEGO &juego,int alto);
void setJuegoGameisnotOver(JUEGO &juego, bool gameisnotover);

int getJuegoIntervalo(JUEGO &juego);
int getJuegoIntervaloMoneda(JUEGO &juego);
bool getJuegoGameisnotOver(JUEGO &juego);
int getJuegoAnchoVentana(JUEGO &juego);
int getJuegoAltoVentana(JUEGO &juego);
#endif // JUEGO_H_INCLUDED
