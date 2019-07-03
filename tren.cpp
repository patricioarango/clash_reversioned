#include <string>
#include <cstring>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include "tren.h"
using namespace std;

/*
void recorrerListaVagones(SDL_Renderer* renderer,ListaVagon &lista,TREN& tren){
    PtrNodoListaVagon cursor,cursorSiguiente,cursorAnterior;
    cursor = primeroVagon(lista);
    VAGON vagon,vagonSiguiente,vagonAnterior;
    //al primer vagon le damos la posX y posY del Tren. al resto, el posX del
    //vagon anterior
    while (cursor != finVagon()) {
        obtenerVagon(lista, vagon, cursor);
        if (getVagonId(vagon) == 0){
            setVagonPosX(vagon, getTrenPosX(tren));
            setVagonPosY(vagon, getTrenPosY(tren));
            setVagonTipoDireccion(vagon,getTrenTipoDireccion(tren));
            setVagonDireccion(vagon,getTrenDireccion(tren));
            setVagonPosXAnterior(vagon,getVagonPosX(vagon));
            setVagonPosYAnterior(vagon,getVagonPosY(vagon));
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
            setVagonImagenporDireccion(vagon,getVagonDireccion(vagon));

        } else {
            cursorAnterior = anteriorVagon(lista,cursor);
            obtenerVagon(lista,vagonAnterior,cursorAnterior);
            //imprimirVagon(vagonAnterior);
            setVagonPosX(vagon, getVagonPosX(vagonAnterior));
            setVagonPosY(vagon, getVagonPosY(vagonAnterior));
            setVagonTipoDireccion(vagon,getTrenTipoDireccion(tren));
            setVagonDireccion(vagon,getTrenDireccion(tren));
            setVagonPosXAnterior(vagon,getVagonPosX(vagon));
            setVagonPosYAnterior(vagon,getVagonPosY(vagon));
            setVagonImagenporDireccion(vagon,getVagonDireccion(vagon));
        }
        renderizarVagon(renderer,vagon);
        cursor = siguienteVagon(lista, cursor);
    }
}
*/

PtrVagon crearVagon()
{
    PtrVagon ptrvagon;
    ptrvagon = new VAGON;
    return ptrvagon;
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

void setVagonImagenporDireccion(VAGON &vagon,int direccion){
    cout << "la direccion es " << direccion <<endl;
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
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo) {

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
void eliminarNodoPrimero(ListaVagon &lista) {

  if (! listaVaciaVagon(lista))
    eliminarNodoVagon(lista,primeroVagon(lista));
}

/*...*/
void eliminarNodoUltimoVagon(ListaVagon &lista) {

  if (! listaVaciaVagon(lista))
    eliminarNodoVagon(lista,ultimoVagon(lista));
}

/*
  pre : lista creada con crearListaVagon().
  post: elivagon todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaVagon(ListaVagon &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaVagon(lista))
    eliminarNodoVagon(lista,primeroVagon(lista));
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
  vagon : elemento a eliminar.
*/
void eliminarVagon(ListaVagon &lista, VAGON vagon) {

  /* localiza el vagon y luego lo elivagon */
  PtrNodoListaVagon ptrNodo = localizarVagon(lista,vagon);
  if (ptrNodo != finVagon())
    eliminarNodoVagon(lista,ptrNodo);
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
        eliminarNodoVagon( temp, ptrCursor );
        ptrCursor = primeroVagon(temp);
  }
  eliminarListaVagon( temp );
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

void crearVagon(VAGON &vagon){
    vagon.posX = 0;
    vagon.posY = 0;
    vagon.posX_anterior =0;
    vagon.posY_anterior = 0;
    vagon.id_vagon = 0;
    vagon.direccion = 0;
    vagon.carga = 0;
    vagon.tipo_carga = 0;
    vagon.tipo_direccion = 0;
}

void setVagonPosX(VAGON &vagon, int pos)
{
    vagon.posX = pos;
}

void setVagonPosY(VAGON &vagon, int pos)
{
    vagon.posY = pos;
}

void setVagonDireccion(VAGON &vagon, int pos)
{
    vagon.direccion = pos;
}

int getVagonCarga(VAGON &vagon)
{
    return vagon.carga;
}

int getVagonTipoCarga(VAGON &vagon)
{
    return vagon.tipo_carga;
}

int getTrenDireccion(TREN &tren)
{
    return tren.direccion;
}

int getTrenTipoDireccion(TREN &tren)
{
    return tren.tipo_direccion;
}

int getVagonDireccion(VAGON &vagon)
{
    return vagon.direccion;
}

void setVagonTipoDireccion(VAGON &vagon, int direccion){
    vagon.tipo_direccion = direccion;
}

int getVagonTipoDireccion(VAGON &vagon)
{
    return vagon.tipo_direccion;
}


int getVagonId(VAGON &vagon)
{
    return vagon.id_vagon;
}

void setVagonId(VAGON &vagon, int id){
    vagon.id_vagon = id;
}

void setVagonPosXAnterior(VAGON &vagon, int pos)
{
    vagon.posX_anterior = pos;
}
void setVagonPosYAnterior(VAGON &vagon, int pos)
{
    vagon.posY_anterior = pos;
}
int getVagonPosXAnterior(VAGON &vagon)
{
    return vagon.posX_anterior;
}

int getVagonPosYAnterior(VAGON &vagon)
{
    return vagon.posY_anterior;
}

void setVagonImgW(VAGON &vagon, int img)
{
    vagon.imgW = img;
}
void setVagonImgH(VAGON &vagon, int img)
{
    vagon.imgH = img;
}

void recorrerListaVagones(SDL_Renderer* renderer,ListaVagon &lista,TREN &tren){
    PtrNodoListaVagon cursor,cursorSiguiente,cursorAnterior;
    cursor = primeroVagon(lista);
    VAGON vagon,vagonSiguiente,vagonAnterior;
    //al primer vagon le damos la posX y posY del Tren. al resto, el posX del
    //vagon anterior
    while (cursor != finVagon()) {
        obtenerVagon(lista, vagon, cursor);
        if (getVagonId(vagon) == 0){
            setVagonPosX(vagon, getTrenPosX(tren));
            setVagonPosY(vagon, getTrenPosY(tren));
            setVagonTipoDireccion(vagon,getTrenTipoDireccion(tren));
            setVagonDireccion(vagon,getTrenDireccion(tren));
            setVagonPosXAnterior(vagon,getVagonPosX(vagon));
            setVagonPosYAnterior(vagon,getVagonPosY(vagon));
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
            setVagonImagenporDireccion(vagon,getVagonDireccion(vagon));

        } else {
            cursorAnterior = anteriorVagon(lista,cursor);
            obtenerVagon(lista,vagonAnterior,cursorAnterior);
            //imprimirVagon(vagonAnterior);
            setVagonPosX(vagon, getVagonPosX(vagonAnterior));
            setVagonPosY(vagon, getVagonPosY(vagonAnterior));
            setVagonTipoDireccion(vagon,getTrenTipoDireccion(tren));
            setVagonDireccion(vagon,getTrenDireccion(tren));
            setVagonPosXAnterior(vagon,getVagonPosX(vagon));
            setVagonPosYAnterior(vagon,getVagonPosY(vagon));
            setVagonImagenporDireccion(vagon,getVagonDireccion(vagon));
        }
        renderizarVagon(renderer,vagon);
        cursor = siguienteVagon(lista, cursor);
    }
}

void agregarVagonTren(TREN &tren,ListaVagon &listavagones)
{

        VAGON *p_vagon = new VAGON;
    PtrNodoListaVagon ptrCursor;
    int id_vagon;
    VAGON vagonFinal;

    setVagonImgW(*p_vagon,70);
    setVagonImgH(*p_vagon,70);
    setVagonTipoDireccion(*p_vagon,0);

    if (longitudVagon(listavagones) == 0){
        setVagonId(*p_vagon,0);
        setVagonPosX(*p_vagon,tren.posX);
        setVagonPosY(*p_vagon,tren.posY);
        setVagonPosYAnterior(*p_vagon,tren.posY);
        setVagonPosXAnterior(*p_vagon,tren.posX);
        setVagonDireccion(*p_vagon,tren.direccion);
        setVagonImagenporDireccion(*p_vagon,tren.direccion);
        adicionarPrincipioVagon(listavagones,*p_vagon);
    } else
    {
        ptrCursor = ultimoVagon(listavagones);
        obtenerVagon(listavagones,vagonFinal,ptrCursor);
        setVagonId(*p_vagon,getVagonId(vagonFinal) + 1);
        setVagonPosX(*p_vagon,getVagonPosX(vagonFinal));
        setVagonPosY(*p_vagon,getVagonPosY(vagonFinal));
        setVagonPosYAnterior(*p_vagon,getVagonPosY(vagonFinal));
        setVagonPosXAnterior(*p_vagon,getVagonPosX(vagonFinal));
        setVagonDireccion(*p_vagon,getVagonDireccion(vagonFinal));
        setVagonImagenporDireccion(*p_vagon,3);
        adicionarDespuesVagon(listavagones,*p_vagon,ptrCursor);
    }
delete p_vagon->imagen;
delete p_vagon;
p_vagon = NULL;
}

void imprimirVagon(VAGON &vagon)
{
    cout << "***VAGON***" << endl;
    cout << "vagon.id_vagon "<< vagon.id_vagon <<endl;
    cout << "vagon.posX "<< vagon.posX <<endl;
    cout << "vagon.posX_anterior "<< vagon.posX_anterior <<endl;
    cout << "vagon.posY "<< vagon.posY <<endl;
    cout << "vagon.posY_anterior "<< vagon.posY_anterior <<endl;
    cout << "vagon.imgW "<< vagon.imgW <<endl;
    cout << "vagon.imgH "<< vagon.imgH <<endl;
    cout << "vagon.carga "<< vagon.carga <<endl;
    cout << "vagon.tipo_carga "<< vagon.tipo_carga <<endl;
    cout << "vagon.direccion "<< vagon.direccion <<endl;
    cout << "vagon.tipo_direccion " << vagon.tipo_direccion <<endl;
     cout << "vagon.tipo_direccion " << &vagon <<endl;
    std::string imagentp22 = vagon.imagen;
    cout <<  "imagen " << imagentp22 <<endl;
    cout << "******" << endl;
}

void renderizarVagon(SDL_Renderer* renderer,VAGON &vagon)
{
    imprimirVagon(vagon);
    SDL_Surface* tmpsurface = IMG_Load(vagon.imagen);
    SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
    SDL_FreeSurface(tmpsurface);
    SDL_Rect destR;
    destR.w = getVagonImgW(vagon);
    destR.h = getVagonImgH(vagon);
    destR.x = getVagonPosX(vagon);
    destR.y = getVagonPosY(vagon);
    SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}
