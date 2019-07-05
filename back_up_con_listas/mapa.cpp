/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versión : 1.1
 */
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "mapa.h"

/******************************************************************************/
/* Definición de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/
    /* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionMapa {
  MAYOR,
  IGUAL,
  MENOR
};

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
ResultadoComparacionMapa compararDatoMapa(Dato dato1, Dato dato2) {
    if (dato1.tipo_elemento > dato2.tipo_elemento) {
        return MAYOR;
    }
    else if (dato1.tipo_elemento < dato2.tipo_elemento) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de datos a ser creado.
*/
void crearDato(Dato &dato)
{
    dato.id_mapa = 0;
    dato.posX = 0;
    dato.posY = 0;
    dato.tipo_elemento = 0;
}

void crearLista(Lista &lista) {
  lista.primero = finMapa();
}

/*
  pre : lista Creada con crearLista().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVacia(Lista &lista) {

  return (primero(lista) == finMapa());
}

/*
  pre : lista Creada con crearLista().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representación del fin de la lista.
*/
PtrNodoListaMapa finMapa() {
  return NULL;
}

/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al primer elemento de la lista, o devuelve finMapa() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMapa primero(Lista &lista) {
  return lista.primero;
}

/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve finMapa() si
        ptrNodo apuntaba a finMapa() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMapa siguiente(Lista &lista, PtrNodoListaMapa ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != finMapa()))
    return ptrNodo->sgte;
  else
    return finMapa();
}

/*
  pre : lista Creada con crearLista().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve finMapa() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaMapa anterior(Lista &lista, PtrNodoListaMapa ptrNodo) {

  PtrNodoListaMapa ptrPrevio = finMapa();
  PtrNodoListaMapa ptrCursor = primero(lista);

  while (( ptrCursor != finMapa()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : lista creada con crearLista().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve finMapa() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoListaMapa ultimo(Lista &lista) {

  /* el último nodo de la lista es el anterior al finMapa() */
  return anterior(lista,finMapa());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaMapa crearNodoLista(Dato dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaMapa ptrAux = new NodoListaMapa;

  ptrAux->dato = dato;
  ptrAux->sgte = finMapa();

  return ptrAux;
}

/*
  pre : lista creada con crearLista().
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMapa adicionarPrincipio(Lista &lista, Dato dato) {

  /* crea el nodo */
  PtrNodoListaMapa ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearLista().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a finMapa() no inserta
        nada y devuelve finMapa().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaMapa adicionarDespues(Lista &lista, Dato dato, PtrNodoListaMapa ptrNodo) {

  PtrNodoListaMapa ptrNuevoNodo = finMapa();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != finMapa()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearLista().
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMapa adicionarFinal(Lista &lista, Dato dato) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*
  pre : lista creada con crearLista().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve finMapa(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaMapa adicionarAntes(Lista &lista, Dato dato, PtrNodoListaMapa ptrNodo) {

  PtrNodoListaMapa ptrNuevoNodo = finMapa();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de finMapa().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(Lista &lista, Dato &dato, PtrNodoListaMapa ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != finMapa()))
    ptrNodo->dato = dato;
}

/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de finMapa().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(Lista &lista, Dato &dato, PtrNodoListaMapa ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != finMapa()))
    dato = ptrNodo->dato;
}

/*
  pre : lista creada con crearLista().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a finMapa().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(Lista &lista, PtrNodoListaMapa ptrNodo) {

  PtrNodoListaMapa ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != finMapa())) {

    if (ptrNodo == primero(lista))
      lista.primero = siguiente(lista,primero(lista));

    else {
      ptrPrevio = anterior( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*...*/
void eliminarNodoPrimero(Lista &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*...*/
void eliminarNodoUltimo(Lista &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*
  pre : lista creada con crearLista().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarLista(Lista &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}
/* Definición de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearLista().
  post: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve finMapa().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o finMapa().
*/
PtrNodoListaMapa localizarDato(Lista &lista, Dato dato) {

   bool encontrado = false;
   Dato datoCursor;
   PtrNodoListaMapa ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finMapa()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDatoMapa(datoCursor,dato) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finMapa();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearLista().
  post : elimina el dato de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarDato(Lista &lista, Dato dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaMapa ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != finMapa())
    eliminarNodo(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMapa insertarDato(Lista &lista, Dato dato) {

  PtrNodoListaMapa ptrPrevio = primero(lista);
  PtrNodoListaMapa ptrCursor = primero(lista);
  PtrNodoListaMapa ptrNuevoNodo;
  Dato datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finMapa()) && (! ubicado)) {

    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDatoMapa(datoCursor,dato) == MENOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues(lista,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la lista fue creada con crearLista().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenar(Lista &lista) {

  Lista temp = lista;
  PtrNodoListaMapa ptrCursor = primero(temp);
  crearLista(lista);
  while ( ptrCursor != finMapa() ) {
        Dato dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*
  pre : la lista fue creada con crearLista().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud(Lista &lista){
  PtrNodoListaMapa ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finMapa() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

void imprimirMapa(Dato &dato)
{
    cout << "*****MAPA*******"<<endl;
    cout << "dato.id_mapa"<<dato.id_mapa<<endl;
    cout << "mapa.posX"<<dato.posX<<endl;
    cout << "mapa.posY"<<dato.posY<<endl;
    switch(dato.tipo_elemento)
    {
    case 1:
        cout <<"TREN"<<endl;
        break;
    case 2:
        cout <<"MONEDA"<<endl;
        break;
    case 3:
        cout <<"ESTACION"<<endl;
        break;
    case 4:
        cout <<"MINA"<<endl;
        break;
    case 5:
        cout <<"VAGON"<<endl;
        break;
    case 6:
        cout <<"BANDIDO"<<endl;
        break;
    }
    cout << "*****END//MAPA*******"<<endl;
}

void vaciarListaMapa(Lista &listaMapa){
    PtrNodoListaMapa cursor = primero(listaMapa);
    Dato dato;

    while (cursor != finMapa()) {
        obtenerDato(listaMapa, dato, cursor);
        eliminarDato(listaMapa,dato);
        cursor = siguiente(listaMapa, cursor);
    }
    eliminarLista(listaMapa);
}
int getMapaPosX(Dato &dato)
{
    return dato.posX;
}
int getMapaPosY(Dato &dato)
{
    return dato.posY;
}
int getMapaId(Dato &dato)
{
    return dato.id_mapa;
}
/*----------------------------------------------------------------------------*/
