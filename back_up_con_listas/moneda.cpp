#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdlib>
#include "moneda.h"

void initMoneda(MONEDA &moneda)
{
    strcpy(moneda.imagen,"assets/images/moneda.png");
    moneda.valor = 1;
    moneda.posX = 0;
    moneda.posY = 0;
    moneda.imgW = 70;
    moneda.imgH = 70;
}

void generarMoneda(MONEDA &moneda,int intervalo,int valor_intervalo_desaparicion)
{
    moneda.posX = (rand() % 13) * moneda.imgW;
    moneda.posY = (rand() % 11) * moneda.imgH;
    moneda.intervalo_desaparicion = intervalo + valor_intervalo_desaparicion;
}

int getMonedaPosX(MONEDA &moneda)
{
    return moneda.posX;
}
int getMonedaPosY(MONEDA &moneda)
{
    return moneda.posY;
}

char* getMonedaImagen(MONEDA &moneda){
    return moneda.imagen;
}

int getMonedaImgW(MONEDA &moneda){
    return moneda.imgW;
}
int getMonedaImgH(MONEDA &moneda){
    return moneda.imgH;
}

int getMonedaIntervaloDesaparicion(MONEDA &moneda){
    return moneda.intervalo_desaparicion;
}

/******************************************************************************/
/* Definici�n de Tipos de Monedas para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos moneda1 y moneda2, devuelve
          mayor si moneda1 es mayor que moneda2,
          igual si moneda1 es igual a moneda2,
          menor si moneda1 es menor que moneda2.

  moneda1 : moneda a comparar.
  moneda2 : moneda a comparar.
  return resultado de comparar moneda1 respecto de moneda2.
*/
ResultadoComparacionMoneda compararMoneda(MONEDA moneda1, MONEDA moneda2) {
    if (moneda1.id_moneda > moneda2.id_moneda) {
        return MAYORMONEDA;
    }
    else if (moneda1.id_moneda < moneda2.id_moneda) {
        return MENORMONEDA;
    }
    else {
        return IGUALMONEDA;
    }
}


/******************************************************************************/
/* Implementaci�n de Primitivas */
/*------------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de monedas a ser creado.
*/
void crearListaMoneda(ListaMoneda &lista) {
  lista.primero = finMoneda();
}

/*
  pre : lista Creada con crearListaMoneda().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaMoneda(ListaMoneda &lista) {

  return (primeroMoneda(lista) == finMoneda());
}

/*
  pre : lista Creada con crearListaMoneda().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaMoneda finMoneda() {
  return NULL;
}

/*
  pre : lista Creada con crearListaMoneda().
  post: devuelve el puntero al primer elemento de la lista, o devuelve finMoneda() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMoneda primeroMoneda(ListaMoneda &lista) {
  return lista.primero;
}

/*
  pre : lista Creada con crearListaMoneda().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve finMoneda() si
        ptrNodo apuntaba a finMoneda() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMoneda siguienteMoneda(ListaMoneda &lista, PtrNodoListaMoneda ptrNodo) {

  /* verifica si la lista est� vacia o si ptrNodo es el �ltimo */
  if ((! listaVaciaMoneda(lista)) && (ptrNodo != finMoneda()))
    return ptrNodo->sgte;
  else
    return finMoneda();
}

/*
  pre : lista Creada con crearListaMoneda().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve finMoneda() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaMoneda anteriorMoneda(ListaMoneda &lista, PtrNodoListaMoneda ptrNodo) {

  PtrNodoListaMoneda ptrPrevio = finMoneda();
  PtrNodoListaMoneda ptrCursor = primeroMoneda(lista);

  while (( ptrCursor != finMoneda()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguienteMoneda(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : lista creada con crearListaMoneda().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve finMoneda() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaMoneda ultimoMoneda(ListaMoneda &lista) {

  /* el �ltimo nodo de la lista es el anterior al finMoneda() */
  return anteriorMoneda(lista,finMoneda());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaMoneda crearNodoListaMoneda(MONEDA moneda) {

  /* reserva memoria para el nodo y luego completa sus monedas */
  PtrNodoListaMoneda ptrAux = new NodoListaMoneda;

  ptrAux->moneda = moneda;
  ptrAux->sgte = finMoneda();

  return ptrAux;
}

/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo nuevo al principio de la lista con el moneda proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarPrincipioMoneda(ListaMoneda &lista, MONEDA moneda) {

  /* crea el nodo */
  PtrNodoListaMoneda ptrNuevoNodo = crearNodoListaMoneda(moneda);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo despues del apuntado por ptrNodo con el moneda
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a finMoneda() no inserta
        nada y devuelve finMoneda().

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el moneda.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarDespuesMoneda(ListaMoneda &lista, MONEDA moneda, PtrNodoListaMoneda ptrNodo) {

  PtrNodoListaMoneda ptrNuevoNodo = finMoneda();

  /* si la lista est� vacia se adiciona la principio */
  if (listaVaciaMoneda(lista))
    ptrNuevoNodo = adicionarPrincipioMoneda(lista,moneda);

  else {
    if (ptrNodo != finMoneda()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaMoneda(moneda);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo al final de la lista con el moneda proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarFinalMoneda(ListaMoneda &lista, MONEDA moneda) {

  /* adiciona el moneda despu�s del �ltimo nodo de la lista */
  return adicionarDespuesMoneda(lista,moneda,ultimoMoneda(lista));
}

/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo con el moneda proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve finMoneda(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el moneda.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarAntesMoneda(ListaMoneda &lista, MONEDA moneda, PtrNodoListaMoneda ptrNodo) {

  PtrNodoListaMoneda ptrNuevoNodo = finMoneda();

  if (! listaVaciaMoneda(lista)) {
    if (ptrNodo != primeroMoneda(lista))
      ptrNuevoNodo = adicionarDespuesMoneda(lista,moneda,anteriorMoneda(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipioMoneda(lista,moneda);
   }
   return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMoneda(), no vacia. ptrNodo es distinto de finMoneda().
  post: coloca el moneda proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el moneda.
*/
void colocarMoneda(ListaMoneda &lista, MONEDA &moneda, PtrNodoListaMoneda ptrNodo) {

  if ( (! listaVaciaMoneda(lista)) && (ptrNodo != finMoneda()))
    ptrNodo->moneda = moneda;
}

/*
  pre : lista creada con crearListaMoneda(), no vacia. ptrNodo es distinto de finMoneda().
  post: devuelve el moneda del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el moneda.
*/
void obtenerMoneda(ListaMoneda &lista, MONEDA &moneda, PtrNodoListaMoneda ptrNodo) {

  if ((! listaVaciaMoneda(lista)) && (ptrNodo != finMoneda()))
    moneda = ptrNodo->moneda;
}

/*
  pre : lista creada con crearListaMoneda().
  post: elimoneda el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a finMoneda().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea elimonedar.
*/
void elimonedarNodoMoneda(ListaMoneda &lista, PtrNodoListaMoneda ptrNodo) {

  PtrNodoListaMoneda ptrPrevio;

  /* verifica que la lista no est� vacia y que nodo no sea fin*/
  if ((! listaVaciaMoneda(lista)) && (ptrNodo != finMoneda())) {

    if (ptrNodo == primeroMoneda(lista))
      lista.primero = siguienteMoneda(lista,primeroMoneda(lista));

    else {
      ptrPrevio = anteriorMoneda( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el moneda es un TDA, ac� habr�a que llamar al destructor.

    delete ptrNodo;
  }
}

/*...*/
void elimonedarNodoPrimero(ListaMoneda &lista) {

  if (! listaVaciaMoneda(lista))
    elimonedarNodoMoneda(lista,primeroMoneda(lista));
}

/*...*/
void elimonedarNodoUltimoMoneda(ListaMoneda &lista) {

  if (! listaVaciaMoneda(lista))
    elimonedarNodoMoneda(lista,ultimoMoneda(lista));
}

/*
  pre : lista creada con crearListaMoneda().
  post: elimoneda todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void elimonedarListaMoneda(ListaMoneda &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaMoneda(lista))
    elimonedarNodoMoneda(lista,primeroMoneda(lista));
}
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaMoneda().
  post: si el moneda se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el moneda no se encuentra en la lista devuelve finMoneda().

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a localizar.
  return puntero al nodo localizado o finMoneda().
*/
PtrNodoListaMoneda localizarMoneda(ListaMoneda &lista, MONEDA moneda) {

   bool encontrado = false;
   MONEDA monedaCursor;
   PtrNodoListaMoneda ptrCursor = primeroMoneda(lista);

  /* recorre los nodos hasta llegar al �ltimo o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finMoneda()) && (! encontrado)) {

    /* obtiene el moneda del nodo y lo compara */
    obtenerMoneda(lista,monedaCursor,ptrCursor);
    if (compararMoneda(monedaCursor,moneda) == IGUALMONEDA)
      encontrado = true;
    else
      ptrCursor = siguienteMoneda(lista,ptrCursor);
  }

  /* si no lo encontr� devuelve fin */
  if (! encontrado)
    ptrCursor = finMoneda();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearListaMoneda().
  post : elimoneda el moneda de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a elimonedar.
*/
void elimonedarMoneda(ListaMoneda &lista, MONEDA moneda) {

  /* localiza el moneda y luego lo elimoneda */
  PtrNodoListaMoneda ptrNodo = localizarMoneda(lista,moneda);
  if (ptrNodo != finMoneda())
    elimonedarNodoMoneda(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearListaMoneda() y cargada con monedas ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el moneda manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMoneda insertarMoneda(ListaMoneda &lista, MONEDA moneda) {

  PtrNodoListaMoneda ptrPrevio = primeroMoneda(lista);
  PtrNodoListaMoneda ptrCursor = primeroMoneda(lista);
  PtrNodoListaMoneda ptrNuevoNodo;
  MONEDA monedaCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserci�n */
  while ((ptrCursor != finMoneda()) && (! ubicado)) {

    obtenerMoneda(lista,monedaCursor,ptrCursor);
    if (compararMoneda(monedaCursor,moneda) == MAYORMONEDA)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguienteMoneda(lista,ptrCursor);
    }
  }

  if (ptrCursor == primeroMoneda(lista))
    ptrNuevoNodo = adicionarPrincipioMoneda(lista,moneda);
  else
    ptrNuevoNodo = adicionarDespuesMoneda(lista,moneda,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la lista fue creada con crearListaMoneda().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarMoneda(ListaMoneda &lista) {

  ListaMoneda temp = lista;
  PtrNodoListaMoneda ptrCursor = primeroMoneda(temp);
  crearListaMoneda(lista);
  while ( ptrCursor != finMoneda() ) {
        MONEDA moneda;
        obtenerMoneda( temp, moneda, ptrCursor);
        insertarMoneda( lista, moneda );
        elimonedarNodoMoneda( temp, ptrCursor );
        ptrCursor = primeroMoneda(temp);
  }
  elimonedarListaMoneda( temp );
}

/*
  pre : la lista fue creada con crearListaMoneda().
  post : devuelve la cantidad de monedas que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud(ListaMoneda &lista){
  PtrNodoListaMoneda ptrCursor = primeroMoneda(lista);
  int longitud = 0;
  while ( ptrCursor != finMoneda() ) {
        longitud++;
        ptrCursor = siguienteMoneda( lista, ptrCursor);
  }
  return longitud;
}
