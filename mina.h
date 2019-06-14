#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED
/**Tipo datos Mina
Atributos:
*posX,
*posY,
*tipoMineral,
*intervaloProduccion,
*SecuenciaProducion,
Axiomas:
*PosX > 0 & < 15 & no ocupada por otra entidad (estacion, posicion inicial del carro u otra mina)
*posY > 0 & < 20 & no ocupada por otra entidad (estacion, posicion inicial del carro u otra mina)
*TipoMaterial = oro, plata, cobre, platino, carbon o roca
*intervaloProduccion > 0
*SecuenciaProduccion > 0
*/
typedef struct{
    int id_mina;
    int posX;
    int posY;
    int tipo; //1 oro 2 cobre 3 bronce
    char imagen[27];
    int imgW;
    int imgH;
} MINA;

void crearMina(MINA &mina);
void setMinaID(MINA &mina,int id_mina);
void setMinaPosX(MINA &mina,int posX);
void setMinaPosY(MINA &mina,int posy);
void setMinaTipo(MINA &mina,int tipomina);
int getMinaPosX(MINA &mina);
int getMinaPosY(MINA &mina);
int getMinaImgW(MINA &mina);
int getMinaImgH(MINA &mina);
char* getMinaImg(MINA &mina);
void initMinas(SDL_Renderer* renderer,MINA &mina);
#endif // MINA_H_INCLUDED
