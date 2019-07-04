/* TDA Lista
 * Implementaci�n Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versi�n : 1.1
 */
#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include "bandido.h"
using namespace std;

/******************************************************************************/
/* Definici�n de Tipos de BANDIDOs para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/
ResultadoComparacionBandido compararBANDIDO(BANDIDO dato1, BANDIDO dato2) {
    if (dato1.id_bandido > dato2.id_bandido) {
        return MAYORBANDIDO;
    }
    else if (dato1.id_bandido < dato2.id_bandido) {
        return MENORBANDIDO;
    }
    else {
        return IGUALBANDIDO;
    }
}

void crearBandido(BANDIDO &bandido)
{
    strcpy(bandido.imagen,"assets/images/villano.png");
    bandido.id_bandido = 0;
    bandido.posX = 0;;
    bandido.posY = 0;
    bandido.imgW = 70;
    bandido.imgH = 70;
    bandido.intervalo_aparicion = 0;
    bandido.intervalo_desaparicion = 0;
    bandido.roba_cantidad = 0;
    bandido.tipo_lingote = 0;
}

void setBandidoIdBandido(BANDIDO &bandido, int id)
{
    bandido.id_bandido=id;
}

void setBandidoPosX(BANDIDO &bandido, int posicion)
{
    bandido.posX=posicion;
}

void setBandidoPosY(BANDIDO &bandido, int posicion)
{
    bandido.posY=posicion;
}

void setBandidoIntervaloAparicion(BANDIDO &bandido, int intervalo)
{
    bandido.intervalo_aparicion=intervalo;
}

void setBandidoIntervaloDesaparicion(BANDIDO &bandido, int intervalo)
{
    bandido.intervalo_desaparicion=intervalo;
}

void setBandidoRobaCantidad(BANDIDO &bandido, int cantidad)
{
    bandido.roba_cantidad=cantidad;
}

void setBandidoTipoLingote(BANDIDO &bandido, int tipo)
{
    bandido.tipo_lingote=tipo;
}

int getBandidoIdBandido(BANDIDO &bandido)
{
   return bandido.id_bandido;
}

int getBandidoPosX(BANDIDO &bandido)
{
    return bandido.posX;
}

int getBandidoPosY(BANDIDO &bandido)
{
    return bandido.posY;
}

int getBandidoImgW(BANDIDO &bandido)
{
    return bandido.imgW;
}
int getBandidoImgH(BANDIDO &bandido)
{
    return bandido.imgH;
}

int getBandidoIntervaloAparicion(BANDIDO &bandido)
{
    return bandido.intervalo_aparicion;
}

int getBandidoIntervaloDesaparicion(BANDIDO &bandido)
{
    return bandido.intervalo_desaparicion;
}

int getBandidoRobaCantidad(BANDIDO &bandido)
{
    return bandido.roba_cantidad;
}

int getBandidoTipoLingote(BANDIDO &bandido)
{
    return bandido.tipo_lingote;
}

/******************************************************************************/
/* Implementaci�n de Primitivas */
/*------------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de datos a ser creado.
*/
void crearListaBandido(ListaBandido &lista) {
  lista.primero = finBandido();
}

/*
  pre : lista Creada con crearListaBandido().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaBandido(ListaBandido &lista) {

  return (primeroBandido(lista) == finBandido());
}

/*
  pre : lista Creada con crearListaBandido().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaBandido finBandido() {
  return NULL;
}

/*
  pre : lista Creada con crearListaBandido().
  post: devuelve el puntero al primer elemento de la lista, o devuelve finBandido() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaBandido primeroBandido(ListaBandido &lista) {
  return lista.primero;
}

/*
  pre : lista Creada con crearListaBandido().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve finBandido() si
        ptrNodo apuntaba a finBandido() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaBandido siguienteBandido(ListaBandido &lista, PtrNodoListaBandido ptrNodo) {

  /* verifica si la lista est� vacia o si ptrNodo es el �ltimo */
  if ((! listaVaciaBandido(lista)) && (ptrNodo != finBandido()))
    return ptrNodo->sgte;
  else
    return finBandido();
}

/*
  pre : lista Creada con crearListaBandido().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve finBandido() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaBandido anteriorBandido(ListaBandido &lista, PtrNodoListaBandido ptrNodo) {

  PtrNodoListaBandido ptrPrevio = finBandido();
  PtrNodoListaBandido ptrCursor = primeroBandido(lista);

  while (( ptrCursor != finBandido()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguienteBandido(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : lista creada con crearListaBandido().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve finBandido() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaBandido ultimoBandido(ListaBandido &lista) {

  /* el �ltimo nodo de la lista es el anterior al finBandido() */
  return anteriorBandido(lista,finBandido());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaBandido crearNodoListaBandido(BANDIDO dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaBandido ptrAux = new NodoListaBandido;

  ptrAux->bandido = dato;
  ptrAux->sgte = finBandido();

  return ptrAux;
}

/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarPrincipioBandido(ListaBandido &lista, BANDIDO dato) {

  /* crea el nodo */
  PtrNodoListaBandido ptrNuevoNodo = crearNodoListaBandido(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a finBandido() no inserta
        nada y devuelve finBandido().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarDespuesBandido(ListaBandido &lista, BANDIDO dato, PtrNodoListaBandido ptrNodo) {

  PtrNodoListaBandido ptrNuevoNodo = finBandido();

  /* si la lista est� vacia se adiciona la principio */
  if (listaVaciaBandido(lista))
    ptrNuevoNodo = adicionarPrincipioBandido(lista,dato);

  else {
    if (ptrNodo != finBandido()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaBandido(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarFinal(ListaBandido &lista, BANDIDO dato) {

  /* adiciona el dato despu�s del �ltimo nodo de la lista */
  return adicionarDespuesBandido(lista,dato,ultimoBandido(lista));
}

/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve finBandido(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarAntes(ListaBandido &lista, BANDIDO dato, PtrNodoListaBandido ptrNodo) {

  PtrNodoListaBandido ptrNuevoNodo = finBandido();

  if (! listaVaciaBandido(lista)) {
    if (ptrNodo != primeroBandido(lista))
      ptrNuevoNodo = adicionarDespuesBandido(lista,dato,anteriorBandido(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipioBandido(lista,dato);
   }
   return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaBandido(), no vacia. ptrNodo es distinto de finBandido().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarBANDIDO(ListaBandido &lista, BANDIDO &dato, PtrNodoListaBandido ptrNodo) {

  if ( (! listaVaciaBandido(lista)) && (ptrNodo != finBandido()))
    ptrNodo->bandido = dato;
}

/*
  pre : lista creada con crearListaBandido(), no vacia. ptrNodo es distinto de finBandido().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerBANDIDO(ListaBandido &lista, BANDIDO &dato, PtrNodoListaBandido ptrNodo) {

  if ((! listaVaciaBandido(lista)) && (ptrNodo != finBandido()))
    dato = ptrNodo->bandido;
}

/*
  pre : lista creada con crearListaBandido().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a finBandido().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoBandido(ListaBandido &lista, PtrNodoListaBandido ptrNodo) {

  PtrNodoListaBandido ptrPrevio;

  /* verifica que la lista no est� vacia y que nodo no sea fin*/
  if ((! listaVaciaBandido(lista)) && (ptrNodo != finBandido())) {

    if (ptrNodo == primeroBandido(lista))
      lista.primero = siguienteBandido(lista,primeroBandido(lista));

    else {
      ptrPrevio = anteriorBandido( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, ac� habr�a que llamar al destructor.

    delete ptrNodo;
  }
}

/*...*/
void eliminarNodoPrimero(ListaBandido &lista) {

  if (! listaVaciaBandido(lista))
    eliminarNodoBandido(lista,primeroBandido(lista));
}

/*...*/
void eliminarNodoUltimoBandido(ListaBandido &lista) {

  if (! listaVaciaBandido(lista))
    eliminarNodoBandido(lista,ultimoBandido(lista));
}

/*
  pre : lista creada con crearListaBandido().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaBandido(ListaBandido &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaBandido(lista))
    eliminarNodoBandido(lista,primeroBandido(lista));
}
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaBandido().
  post: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve finBandido().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o finBandido().
*/
PtrNodoListaBandido localizarBANDIDO(ListaBandido &lista, BANDIDO dato) {

   bool encontrado = false;
   BANDIDO datoCursor;
   PtrNodoListaBandido ptrCursor = primeroBandido(lista);

  /* recorre los nodos hasta llegar al �ltimo o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finBandido()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerBANDIDO(lista,datoCursor,ptrCursor);
    if (compararBANDIDO(datoCursor,dato) == IGUALBANDIDO)
      encontrado = true;
    else
      ptrCursor = siguienteBandido(lista,ptrCursor);
  }

  /* si no lo encontr� devuelve fin */
  if (! encontrado)
    ptrCursor = finBandido();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearListaBandido().
  post : elimina el dato de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarBANDIDO(ListaBandido &lista, BANDIDO dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaBandido ptrNodo = localizarBANDIDO(lista,dato);
  if (ptrNodo != finBandido())
    eliminarNodoBandido(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearListaBandido() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaBandido insertarBANDIDO(ListaBandido &lista, BANDIDO dato) {

  PtrNodoListaBandido ptrPrevio = primeroBandido(lista);
  PtrNodoListaBandido ptrCursor = primeroBandido(lista);
  PtrNodoListaBandido ptrNuevoNodo;
  BANDIDO datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserci�n */
  while ((ptrCursor != finBandido()) && (! ubicado)) {

    obtenerBANDIDO(lista,datoCursor,ptrCursor);
    if (compararBANDIDO(datoCursor,dato) == MAYORBANDIDO)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguienteBandido(lista,ptrCursor);
    }
  }

  if (ptrCursor == primeroBandido(lista))
    ptrNuevoNodo = adicionarPrincipioBandido(lista,dato);
  else
    ptrNuevoNodo = adicionarDespuesBandido(lista,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la lista fue creada con crearListaBandido().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarBandido(ListaBandido &lista) {

  ListaBandido temp = lista;
  PtrNodoListaBandido ptrCursor = primeroBandido(temp);
  crearListaBandido(lista);
  while ( ptrCursor != finBandido() ) {
        BANDIDO dato;
        obtenerBANDIDO( temp, dato, ptrCursor);
        insertarBANDIDO( lista, dato );
        eliminarNodoBandido( temp, ptrCursor );
        ptrCursor = primeroBandido(temp);
  }
  eliminarListaBandido( temp );
}

/*
  pre : la lista fue creada con crearListaBandido().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitudBandido(ListaBandido &lista){
  PtrNodoListaBandido ptrCursor = primeroBandido(lista);
  int longitud = 0;
  while ( ptrCursor != finBandido() ) {
        longitud++;
        ptrCursor = siguienteBandido( lista, ptrCursor);
  }
  return longitud;
}

void renderizarBandido(SDL_Renderer* renderer,BANDIDO &bandido)
{
    SDL_Surface* tmpsurface = IMG_Load(bandido.imagen);
    SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
    SDL_FreeSurface(tmpsurface);
    SDL_Rect destR;
    destR.w = getBandidoImgW(bandido);
    destR.h = getBandidoImgH(bandido);
    destR.x = getBandidoPosX(bandido);
    destR.y = getBandidoPosY(bandido);
    SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}

void generarBandido(ListaBandido &lista, BANDIDO &bandido,int intervalo,int valor_intervalo_desaparicion)
{
    int id_bandido;
    crearBandido(bandido);
    if (longitudBandido(lista) == 0)
    {
        id_bandido = 0;
    } else {
        PtrNodoListaBandido cursor;
        BANDIDO ultimaBandido;
        cursor = ultimoBandido(lista);
        obtenerBANDIDO(lista,ultimaBandido,cursor);
        id_bandido = ultimaBandido.id_bandido + 1;
    }
    bandido.id_bandido = id_bandido;
    bandido.posX = (rand() % 12) * bandido.imgW;
    bandido.posY = (rand() % 9) * bandido.imgH;
    bandido.intervalo_desaparicion = intervalo + valor_intervalo_desaparicion;
    bandido.roba_cantidad = (1 + rand() % (6 - 1));
    insertarBANDIDO(lista,bandido);
}

void imprimirBandido(BANDIDO &bandido)
{
    cout<<"******BANDIDO***********"<<endl;
    cout<<"Id_bandido : "<<bandido.id_bandido<<endl;
    cout<<"PosX: "<<bandido.posX<<endl;
    cout<<"PosY: "<<bandido.posY<<endl;
    cout<<"Intervalo desaparicion: "<<bandido.intervalo_desaparicion<<endl;
    cout<<"Catidad a robar"<<bandido.roba_cantidad<<endl;
    cout<<"*******************"<<endl;
}

void recorrerListaBandidos(SDL_Renderer* renderer,ListaBandido &lista)
{
    PtrNodoListaBandido ptrCursor = primeroBandido(lista);
    BANDIDO bandido;
    while ( ptrCursor != finBandido() ) {
        obtenerBANDIDO(lista,bandido,ptrCursor);
        //imprimirBandido(bandido);
        renderizarBandido(renderer,bandido);
        ptrCursor = siguienteBandido( lista, ptrCursor);
    }
}

void evaluarBandidos(ListaBandido &lista,int intervalo)
{
     PtrNodoListaBandido ptrCursor = primeroBandido(lista);
    BANDIDO bandido;
    while ( ptrCursor != finBandido() ) {
        obtenerBANDIDO(lista,bandido,ptrCursor);
        if (intervalo > bandido.intervalo_desaparicion)
        {
            eliminarBANDIDO(lista,bandido);
        }

        ptrCursor = siguienteBandido( lista, ptrCursor);
    }
}

/*----------------------------------------------------------------------------*/
