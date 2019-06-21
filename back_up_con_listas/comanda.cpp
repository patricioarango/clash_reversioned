#include "comanda.h"

void setComandaOro(COMANDA &comanda,int valor)
{
    comanda.oro = valor;
}

void setComandaPlata(COMANDA &comanda,int valor)
{
    comanda.plata = valor;
}

void setComandaBronce(COMANDA &comanda,int valor)
{
    comanda.bronce = valor;
}

void setComandaPlatino(COMANDA &comanda,int valor)
{
    comanda.platino = valor;
}

void setComandaRoca(COMANDA &comanda,int valor)
{
    comanda.roca = valor;
}

void setComandaCarbon(COMANDA &comanda,int valor)
{
    comanda.carbon = valor;
}

int getComandaOro(COMANDA &comanda)
{
    return comanda.oro;
}

int getComandaPlata(COMANDA &comanda)
{
    return comanda.plata;
}

int getComandaBronce(COMANDA &comanda)
{
    return comanda.bronce;
}

int getComandaPlatino(COMANDA &comanda)
{
    return comanda.platino;
}

int getComandaRoca(COMANDA &comanda)
{
    return comanda.roca;
}

int getComandaCarbon(COMANDA &comanda)
{
    return comanda.carbon;
}
