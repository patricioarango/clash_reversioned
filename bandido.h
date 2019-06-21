#ifndef BANDIDO_H_INCLUDED
#define BANDIDO_H_INCLUDED

typedef struct {
    int posX;
    int posY;
    int imgW;
    int imgH;
    char imagen[27];
    int intervalo_aparicion;
    int intervalo_desaparicion;
}BANDIDO;

#endif // BANDIDO_H_INCLUDED
