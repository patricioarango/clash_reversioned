#ifndef ESTACION_H_INCLUDED
#define ESTACION_H_INCLUDED

typedef struct{
    int posX;
    int posY;
    int imgW;
    int imgH;
    char imagen[27];
}ESTACION;

void setEstacionPosX(ESTACION &estacion, int pos);
void setEstacionPosY(ESTACION &estacion, int pos);
void setEstacionImagen(ESTACION &estacion, char imagen);
int getEstacionPosX(ESTACION &estacion);
int getEstacionPosY(ESTACION &estacion);
void initEstacion(SDL_Renderer* renderer,ESTACION &estacion);
#endif // ESTACION_H_INCLUDED
