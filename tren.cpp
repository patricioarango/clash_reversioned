#include <string>
#include <cstring>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include "tren.h"
using namespace std;

/*void recorrerListaVagones(SDL_Renderer* renderer,ListaVagon &lista,TREN& tren){
    PtrNodoListaVagon cursor = primeroVagon(lista);
    VAGON vagon,vagonAnterior;
    //al primer vagon le damos la posX y posY del Tren. al resto, el posX del
    //    vagon anterior

    int cantidadVagones = longitudVagon(lista);
    if (cantidadVagones == 1){
        obtenerVagon(lista, vagon, cursor);
        setVagonPosX(vagon, getTrenPosX(tren));
        setVagonPosY(vagon, getTrenPosY(tren));
        if (getTrenTipoDireccion(tren) == 1 && getTrenDireccion(tren) == 1){
           setVagonPosX(vagon, getTrenPosX(tren) - 70);
        }
        if (getTrenTipoDireccion(tren) == 0 && getTrenDireccion(tren) == 1){
            setVagonPosX(vagon,getTrenPosX(tren) + 70);
        }
        if (getTrenTipoDireccion(tren) == 1 && getTrenDireccion(tren) == 3){
            setVagonPosX(vagon,getTrenPosX(tren) - 70);
        }
        if (getTrenTipoDireccion(tren) == 0 && getTrenDireccion(tren) == 3){
            setVagonPosX(vagon,getTrenPosX(tren) + 70);
        }
        if (getTrenTipoDireccion(tren) == 0 && getTrenDireccion(tren) == 2){
            setVagonPosY(vagon,getTrenPosY(tren) + 70);
        }
        if (getTrenTipoDireccion(tren) == 1 && getTrenDireccion(tren) == 2){
            setVagonPosY(vagon,getTrenPosY(tren) - 70);
        }
        if (getTrenTipoDireccion(tren) == 0 && getTrenDireccion(tren) == 0){
           setVagonPosY(vagon,getTrenPosY(tren) + 70);
        }
        if (getTrenTipoDireccion(tren) == 1 && getTrenDireccion(tren) == 0){
            setVagonPosY(vagon,getTrenPosY(tren) - 70);
        }
        setVagonImagenporDireccion(vagon,getTrenDireccion(tren));
        setVagonSiguientePosX(vagon,getVagonPosX(vagon));
        setVagonSiguientePosY(vagon,getVagonPosY(vagon));
        setVagonSiguienteDireccion(vagon,getTrenDireccion(tren));
        setVagonSiguienteTipoDireccion(vagon,getTrenTipoDireccion(tren));
        SDL_Surface* tmpsurface = IMG_Load(getVagonImagen(vagon));
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect destR;
        destR.w = getVagonImgW(vagon);
        destR.h = getVagonImgH(vagon);
        destR.x = getVagonPosX(vagon);
        destR.y = getVagonPosY(vagon);
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
    } else { //porque si es 1 solo no tengo ANTERIOR
        while (cursor != finVagon()) {
        obtenerVagon(lista, vagon, cursor);
        PtrNodoListaVagon cursorAnterior = siguienteVagon(lista, cursor);
        obtenerVagon(lista, vagonAnterior, cursorAnterior);
        setVagonPosX(vagon, getVagonPosX(vagonAnterior));
        setVagonPosY(vagon, getVagonPosY(vagonAnterior));

        setVagonImagenporDireccion(vagon,getVagonSiguienteDireccion(vagonAnterior));
        setVagonSiguientePosX(vagon,getVagonPosX(vagon));
        setVagonSiguientePosY(vagon,getVagonPosY(vagon));
        setVagonSiguienteDireccion(vagon,getVagonDireccion(vagon));
        setVagonSiguienteTipoDireccion(vagon,getVagonTipoDireccion(vagon));
        SDL_Surface* tmpsurface = IMG_Load(vagon.imagen);
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect scrR,destR;
        destR.w = getVagonImgW(vagon);
        destR.h = getVagonImgH(vagon);
        destR.x = getVagonPosX(vagon);
        destR.y = getVagonPosY(vagon);
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
        cursor = siguienteVagon(lista, cursor);
       }
    }
}*/
void recorrerListaVagones(SDL_Renderer* renderer,ListaVagon &lista,TREN& tren){
    PtrNodoListaVagon cursor = primeroVagon(lista);
    VAGON vagon,vagonAnterior;
    /*
        al primer vagon le damos la posX y posY del Tren. al resto, el posX del
        vagon anterior
    */
    int contadorVagones = 0;
    int guiaPosX,guiaPosY,guiaSiguientePosX,guiaSiguientePosY,guiaDireccion,guiaTipoDireccion;
    while (cursor != finVagon()) {
        obtenerVagon(lista, vagon, cursor);
        if (contadorVagones == 0){
            guiaPosX = getTrenPosX(tren);
            guiaPosY = getTrenPosY(tren);
            guiaDireccion = getTrenDireccion(tren);
            guiaTipoDireccion = getTrenTipoDireccion(tren);
        } else { //porque si es 1 solo no tengo ANTERIOR

            PtrNodoListaVagon cursorAnterior = anteriorVagon(lista, cursor);
            obtenerVagon(lista, vagonAnterior, cursorAnterior);
            //guiaSiguientePosX = getVagonSiguientePosX(vagon);
            //guiaSiguientePosY = getVagonSiguientePosX(vagon);
            guiaPosX = getVagonSiguientePosX(vagonAnterior);
            guiaPosY = getVagonSiguientePosY(vagonAnterior);
            guiaDireccion = getVagonSiguienteDireccion(vagonAnterior);
            guiaTipoDireccion = getVagonSiguienteTipoDireccion(vagonAnterior);
        }
        setVagonPosX(vagon, guiaPosX);
        setVagonPosY(vagon, guiaPosY);
        setVagonSiguientePosX(vagon,guiaPosX);
        setVagonSiguientePosY(vagon,guiaPosY);
        setVagonTipoDireccion(vagon,guiaTipoDireccion);
        setVagonDireccion(vagon,guiaDireccion);

        if (guiaTipoDireccion == 1 && guiaDireccion == 1){
           setVagonPosX(vagon, guiaPosX - 70);
        }
        if (guiaTipoDireccion == 0 && guiaDireccion == 1){
            setVagonPosX(vagon,guiaPosX + 70);
        }
        if (guiaTipoDireccion == 1 && guiaDireccion == 3){
            setVagonPosX(vagon,guiaPosX - 70);
        }
        if (guiaTipoDireccion == 0 && guiaDireccion == 3){
            setVagonPosX(vagon,guiaPosX + 70);
        }
        if (guiaTipoDireccion == 0 && guiaDireccion == 2){
            setVagonPosY(vagon,guiaPosY + 70);
        }
        if (guiaTipoDireccion == 1 && guiaDireccion == 2){
            setVagonPosY(vagon,guiaPosY - 70);
        }
        if (guiaTipoDireccion == 0 && guiaDireccion == 0){
           setVagonPosY(vagon,guiaPosY + 70);
        }
        if (guiaTipoDireccion == 1 && guiaDireccion == 0){
            setVagonPosY(vagon,guiaPosY - 70);
        }
        setVagonSiguientePosX(vagon,guiaSiguientePosX);
        setVagonSiguientePosY(vagon,guiaSiguientePosY);
        setVagonImagenporDireccion(vagon,guiaDireccion);

        SDL_Surface* tmpsurface = IMG_Load(vagon.imagen);
        SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
        SDL_FreeSurface(tmpsurface);
        SDL_Rect scrR,destR;
        destR.w = getVagonImgW(vagon);
        destR.h = getVagonImgH(vagon);
        destR.x = getVagonPosX(vagon);
        destR.y = getVagonPosY(vagon);
        SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
        cursor = siguienteVagon(lista, cursor);
        contadorVagones++;
    }
}
/*----------------------------------------------------------------------------*/
PtrNodoListaVagon crearNodoListaVagon(VAGON vagon) {

  /* reserva memoria para el nodo y luego completa sus vagons */
  PtrNodoListaVagon ptrAux = new NodoListaVagon;

  ptrAux->vagon = vagon;
  ptrAux->sgte = finVagon();

  return ptrAux;
}

void setTrenImagenporDireccion(TREN &tren,int direccion){
    if (direccion == 0){
        strcpy(tren.imagen,"assets/images/c1/arr/0.png");
    }
    if (direccion == 1){
        strcpy(tren.imagen,"assets/images/c1/der/0.png");
    }
    if (direccion == 2){
        strcpy(tren.imagen,"assets/images/c1/aba/0.png");
    }
    if (direccion == 3){
        strcpy(tren.imagen,"assets/images/c1/izq/0.png");
    }
}

void setVagonImagenporDireccion(VAGON& vagon,int direccion){
    if (direccion == 0){
        strcpy(vagon.imagen,"assets/images/c2/arr/0.png");
    }
    if (direccion == 1){
        strcpy(vagon.imagen,"assets/images/c2/der/0.png");
    }
    if (direccion == 2){
        strcpy(vagon.imagen,"assets/images/c2/aba/0.png");
    }
    if (direccion == 3){
        strcpy(vagon.imagen,"assets/images/c2/izq/0.png");
    }
}

void setTrenDireccion(TREN &tren,int direccion){
    tren.direccion = direccion;
}

char* getTrenImagen(TREN &tren){
    return tren.imagen;
}

void setTrenTipoDireccion(TREN &tren,int tipo_direccion){
    tren.tipo_direccion = tipo_direccion;
}

void initTren(SDL_Renderer* renderer,TREN &tren,ListaVagon &lista){
        setTrenImagenporDireccion(tren,tren.direccion);
        setTrenImgW(tren,70);
        setTrenImgH(tren,70);
        if (tren.tipo_direccion == 1 && tren.direccion == 1){
           tren.posX = tren.posX + 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 1){
            tren.posX = tren.posX - 70;
        }
        if (tren.tipo_direccion == 1 && tren.direccion == 3){
            tren.posX = tren.posX + 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 3){
            tren.posX = tren.posX - 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 2){
            tren.posY = tren.posY - 70;
        }
        if (tren.tipo_direccion == 1 && tren.direccion == 2){
            tren.posY = tren.posY + 70;
        }
        if (tren.tipo_direccion == 0 && tren.direccion == 0){
           tren.posY = tren.posY - 70;
        }
        if (tren.tipo_direccion == 1 && tren.direccion == 0){
            tren.posY = tren.posY + 70;
        }

     SDL_Surface* tmpsurface = IMG_Load(tren.imagen);
     SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
     SDL_FreeSurface(tmpsurface);
     SDL_Rect scrR,destR;
        destR.w = getTrenImgW(tren);
        destR.h = getTrenImgH(tren);
        destR.x = getTrenPosX(tren);
        destR.y = getTrenPosY(tren);
    SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
    //recorremos los vagones
    recorrerListaVagones(renderer,lista,tren);
}

int getTrenPosX(TREN &tren){
    return tren.posX;
}

int getTrenPosY(TREN &tren){
    return tren.posY;
}
void setTrenImgW(TREN &tren, int img){
    tren.imgW = img;
}
void setTrenImgH(TREN &tren, int img){
    tren.imgH = img;
}

int getTrenImgW(TREN &tren){
    return tren.imgW;
}

int getTrenImgH(TREN &tren){
    return tren.imgH;
}

int getVagonPosX(VAGON &vagon){
    return vagon.posX;
}
int getVagonPosY(VAGON &vagon){
    return vagon.posY;
}
char* getVagonImagen(VAGON &vagon){
    return vagon.imagen;
}

int getVagonImgW(VAGON &vagon){
    return vagon.imgW;
}
int getVagonImgH(VAGON &vagon){
    return vagon.imgH;
}

/*
  pre : ninguna.
  post: compara ambos vagon1 y vagon2, devuelve
          mayor si vagon1 es mayor que vagon2,
          igual si vagon1 es igual a vagon2,
          menor si vagon1 es menor que vagon2.

  vagon1 : vagon a comparar.
  vagon2 : vagon a comparar.
  return resultado de comparar vagon1 respecto de vagon2.
*/
ResultadoComparacionVagon compararVagon(VAGON vagon1, VAGON vagon2) {
    if (vagon1.id_vagon > vagon2.id_vagon) {
        return MAYORVAGON;
    }
    else if (vagon1.id_vagon < vagon2.id_vagon) {
        return MENORVAGON;
    }
    else {
        return IGUALVAGON;
    }
}


/******************************************************************************/
/* Implementaci�n de Primitivas */
/*------------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de vagons a ser creado.
*/
void crearListaVagon(ListaVagon &lista) {
  lista.primero = finVagon();
}

/*
  pre : lista Creada con crearListaVagon().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaVagon(ListaVagon &lista) {

  return (primeroVagon(lista) == finVagon());
}

/*
  pre : lista Creada con crearListaVagon().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaVagon finVagon() {
  return NULL;
}

/*
  pre : lista Creada con crearListaVagon().
  post: devuelve el puntero al primer elemento de la lista, o devuelve finVagon() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaVagon primeroVagon(ListaVagon &lista) {
  return lista.primero;
}

/*
  pre : lista Creada con crearListaVagon().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve finVagon() si
        ptrNodo apuntaba a finVagon() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaVagon siguienteVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo) {

  /* verifica si la lista est� vacia o si ptrNodo es el �ltimo */
  if ((! listaVaciaVagon(lista)) && (ptrNodo != finVagon()))
    return ptrNodo->sgte;
  else
    return finVagon();
}

/*
  pre : lista Creada con crearListaVagon().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve finVagon() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaVagon anteriorVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo) {

  PtrNodoListaVagon ptrPrevio = finVagon();
  PtrNodoListaVagon ptrCursor = primeroVagon(lista);

  while (( ptrCursor != finVagon()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguienteVagon(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : lista creada con crearListaVagon().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve finVagon() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaVagon ultimoVagon(ListaVagon &lista) {

  /* el �ltimo nodo de la lista es el anterior al finVagon() */
  return anteriorVagon(lista,finVagon());
}

/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo nuevo al principio de la lista con el vagon proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarPrincipioVagon(ListaVagon &lista, VAGON vagon) {

  /* crea el nodo */
  PtrNodoListaVagon ptrNuevoNodo = crearNodoListaVagon(vagon);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo despues del apuntado por ptrNodo con el vagon
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a finVagon() no inserta
        nada y devuelve finVagon().

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el vagon.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarDespuesVagon(ListaVagon &lista, VAGON vagon, PtrNodoListaVagon ptrNodo) {

  PtrNodoListaVagon ptrNuevoNodo = finVagon();

  /* si la lista est� vacia se adiciona la principio */
  if (listaVaciaVagon(lista))
    ptrNuevoNodo = adicionarPrincipioVagon(lista,vagon);

  else {
    if (ptrNodo != finVagon()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaVagon(vagon);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo al final de la lista con el vagon proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarFinalVagon(ListaVagon &lista, VAGON vagon) {

  /* adiciona el vagon despu�s del �ltimo nodo de la lista */
  return adicionarDespuesVagon(lista,vagon,ultimoVagon(lista));
}

/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo con el vagon proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve finVagon(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el vagon.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarAntesVagon(ListaVagon &lista, VAGON vagon, PtrNodoListaVagon ptrNodo) {

  PtrNodoListaVagon ptrNuevoNodo = finVagon();

  if (! listaVaciaVagon(lista)) {
    if (ptrNodo != primeroVagon(lista))
      ptrNuevoNodo = adicionarDespuesVagon(lista,vagon,anteriorVagon(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipioVagon(lista,vagon);
   }
   return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaVagon(), no vacia. ptrNodo es distinto de finVagon().
  post: coloca el vagon proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el vagon.
*/
void colocarVagon(ListaVagon &lista, VAGON &vagon, PtrNodoListaVagon ptrNodo) {

  if ( (! listaVaciaVagon(lista)) && (ptrNodo != finVagon()))
    ptrNodo->vagon = vagon;
}

/*
  pre : lista creada con crearListaVagon(), no vacia. ptrNodo es distinto de finVagon().
  post: devuelve el vagon del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el vagon.
*/
void obtenerVagon(ListaVagon &lista, VAGON &vagon, PtrNodoListaVagon ptrNodo) {

  if ((! listaVaciaVagon(lista)) && (ptrNodo != finVagon()))
    vagon = ptrNodo->vagon;
}

/*
  pre : lista creada con crearListaVagon().
  post: elivagon el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a finVagon().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea elivagonr.
*/
void elivagonrNodoVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo) {

  PtrNodoListaVagon ptrPrevio;

  /* verifica que la lista no est� vacia y que nodo no sea fin*/
  if ((! listaVaciaVagon(lista)) && (ptrNodo != finVagon())) {

    if (ptrNodo == primeroVagon(lista))
      lista.primero = siguienteVagon(lista,primeroVagon(lista));

    else {
      ptrPrevio = anteriorVagon( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el vagon es un TDA, ac� habr�a que llamar al destructor.

    delete ptrNodo;
  }
}

/*...*/
void elivagonrNodoPrimero(ListaVagon &lista) {

  if (! listaVaciaVagon(lista))
    elivagonrNodoVagon(lista,primeroVagon(lista));
}

/*...*/
void elivagonrNodoUltimoVagon(ListaVagon &lista) {

  if (! listaVaciaVagon(lista))
    elivagonrNodoVagon(lista,ultimoVagon(lista));
}

/*
  pre : lista creada con crearListaVagon().
  post: elivagon todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void elivagonrListaVagon(ListaVagon &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaVagon(lista))
    elivagonrNodoVagon(lista,primeroVagon(lista));
}
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaVagon().
  post: si el vagon se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el vagon no se encuentra en la lista devuelve finVagon().

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a localizar.
  return puntero al nodo localizado o finVagon().
*/
PtrNodoListaVagon localizarVagon(ListaVagon &lista, VAGON vagon) {

   bool encontrado = false;
   VAGON vagonCursor;
   PtrNodoListaVagon ptrCursor = primeroVagon(lista);

  /* recorre los nodos hasta llegar al �ltimo o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finVagon()) && (! encontrado)) {

    /* obtiene el vagon del nodo y lo compara */
    obtenerVagon(lista,vagonCursor,ptrCursor);
    if (compararVagon(vagonCursor,vagon) == IGUALVAGON)
      encontrado = true;
    else
      ptrCursor = siguienteVagon(lista,ptrCursor);
  }

  /* si no lo encontr� devuelve fin */
  if (! encontrado)
    ptrCursor = finVagon();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearListaVagon().
  post : elivagon el vagon de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a elivagonr.
*/
void elivagonrVagon(ListaVagon &lista, VAGON vagon) {

  /* localiza el vagon y luego lo elivagon */
  PtrNodoListaVagon ptrNodo = localizarVagon(lista,vagon);
  if (ptrNodo != finVagon())
    elivagonrNodoVagon(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearListaVagon() y cargada con vagons ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el vagon manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaVagon insertarVagon(ListaVagon &lista, VAGON vagon) {

  PtrNodoListaVagon ptrPrevio = primeroVagon(lista);
  PtrNodoListaVagon ptrCursor = primeroVagon(lista);
  PtrNodoListaVagon ptrNuevoNodo;
  VAGON vagonCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserci�n */
  while ((ptrCursor != finVagon()) && (! ubicado)) {

    obtenerVagon(lista,vagonCursor,ptrCursor);
    if (compararVagon(vagonCursor,vagon) == MAYORVAGON)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguienteVagon(lista,ptrCursor);
    }
  }

  if (ptrCursor == primeroVagon(lista))
    ptrNuevoNodo = adicionarPrincipioVagon(lista,vagon);
  else
    ptrNuevoNodo = adicionarDespuesVagon(lista,vagon,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la lista fue creada con crearListaVagon().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarVagon(ListaVagon &lista) {

  ListaVagon temp = lista;
  PtrNodoListaVagon ptrCursor = primeroVagon(temp);
  crearListaVagon(lista);
  while ( ptrCursor != finVagon() ) {
        VAGON vagon;
        obtenerVagon( temp, vagon, ptrCursor);
        insertarVagon( lista, vagon );
        elivagonrNodoVagon( temp, ptrCursor );
        ptrCursor = primeroVagon(temp);
  }
  elivagonrListaVagon( temp );
}

/*
  pre : la lista fue creada con crearListaVagon().
  post : devuelve la cantidad de vagons que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitudVagon(ListaVagon &lista){
  PtrNodoListaVagon ptrCursor = primeroVagon(lista);
  int longitud = 0;
  while ( ptrCursor != finVagon() ) {
        longitud++;
        ptrCursor = siguienteVagon( lista, ptrCursor);
  }
  return longitud;
}

void agregarVagonTren(TREN &tren,ListaVagon &listavagones,VAGON &vagon)
{
    crearNodoListaVagon(vagon);
    vagon.id_vagon = (rand() % 99);
    vagon.posX = getTrenPosX(tren);
    vagon.posY = getTrenPosY(tren);
    vagon.imgW = 70;
    vagon.imgH = 70;
    adicionarFinalVagon(listavagones,vagon);
}

void setVagonPosX(VAGON& vagon, int pos)
{
    vagon.posX = pos;
}

void setVagonSiguientePosX(VAGON& vagon, int pos)
{
    vagon.siguientePosX = pos;
}

void setVagonPosY(VAGON& vagon, int pos)
{
    vagon.posY = pos;
}

void setVagonSiguientePosY(VAGON& vagon, int pos)
{
    vagon.siguientePosY = pos;
}

void setVagonDireccion(VAGON& vagon, int pos)
{
    vagon.direccion = pos;
}

int getVagonCarga(VAGON& vagon)
{
    return vagon.carga;
}

int getVagonTipoCarga(VAGON& vagon)
{
    return vagon.tipo_carga;
}

int getTrenDireccion(TREN& tren)
{
    return tren.direccion;
}

int getTrenTipoDireccion(TREN& tren)
{
    return tren.tipo_direccion;
}

int getVagonDireccion(VAGON& vagon)
{
    return vagon.direccion;
}

int getVagonSiguientePosX(VAGON& vagon)
{
    return vagon.siguientePosX;
}

int getVagonSiguientePosY(VAGON& vagon)
{
    return vagon.siguientePosY;
}

void setVagonSiguienteDireccion(VAGON& vagon, int direccion)
{
   vagon.direccion = direccion;
}

void setVagonSiguienteTipoDireccion(VAGON& vagon, int direccion)
{
   vagon.siguienteTipoDireccion = direccion;
}

void setVagonTipoDireccion(VAGON& vagon, int direccion){
    vagon.tipo_direccion = direccion;
}

int getVagonTipoDireccion(VAGON& vagon)
{
    return vagon.tipo_direccion;
}

int getVagonSiguienteDireccion(VAGON& vagon)
{
    return vagon.siguienteDireccion;
}

int getVagonSiguienteTipoDireccion(VAGON& vagon)
{
    return vagon.siguienteTipoDireccion;
}
