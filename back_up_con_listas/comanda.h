#ifndef COMANDA_H_INCLUDED
#define COMANDA_H_INCLUDED
typedef struct {
    int oro;
    int plata;
    int bronce;
    int platino;
    int roca;
    int carbon;
}COMANDA;

void setComandaOro(COMANDA &comanda,int valor);
void setComandaPlata(COMANDA &comanda,int valor);
void setComandaBronce(COMANDA &comanda,int valor);
void setComandaPlatino(COMANDA &comanda,int valor);
void setComandaRoca(COMANDA &comanda,int valor);
void setComandaCarbon(COMANDA &comanda,int valor);

int getComandaOro(COMANDA &comanda);
int getComandaPlata(COMANDA &comanda);
int getComandaBronce(COMANDA &comanda);
int getComandaPlatino(COMANDA &comanda);
int getComandaRoca(COMANDA &comanda);
int getComandaCarbon(COMANDA &comanda);

#endif // COMANDA_H_INCLUDED
