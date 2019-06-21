
/* TDA Lista
 * Implementaci�n Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versi�n : 1.1
 */

#include <cstddef>
#include "mina.h"

/******************************************************************************/
/* Definici�n de Tipos de Minas para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos mina1 y mina2, devuelve
          mayor si mina1 es mayor que mina2,
          igual si mina1 es igual a mina2,
          menor si mina1 es menor que mina2.

  mina1 : mina a comparar.
  mina2 : mina a comparar.
  return resultado de comparar mina1 respecto de mina2.
*/
ResultadoComparacionMina compararMina(MINA mina1, MINA mina2) {
    if (mina1.id_mina > mina2.id_mina) {
        return MAYORMINA;
    }
    else if (mina1.id_mina < mina2.id_mina) {
        return MENORMINA;
    }
    else {
        return IGUALMINA;
    }
}


/******************************************************************************/
/* Implementaci�n de Primitivas */
/*------------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de minas a ser creado.
*/
void crearListaMina(ListaMina &lista) {
  lista.primero = finMina();
}

/*
  pre : lista Creada con crearListaMina().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaMina(ListaMina &lista) {

  return (primeroMina(lista) == finMina());
}

/*
  pre : lista Creada con crearListaMina().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaMina finMina() {
  return NULL;
}

/*
  pre : lista Creada con crearListaMina().
  post: devuelve el puntero al primer elemento de la lista, o devuelve finMina() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMina primeroMina(ListaMina &lista) {
  return lista.primero;
}

/*
  pre : lista Creada con crearListaMina().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve finMina() si
        ptrNodo apuntaba a finMina() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMina siguienteMina(ListaMina &lista, PtrNodoListaMina ptrNodo) {

  /* verifica si la lista est� vacia o si ptrNodo es el �ltimo */
  if ((! listaVaciaMina(lista)) && (ptrNodo != finMina()))
    return ptrNodo->sgte;
  else
    return finMina();
}

/*
  pre : lista Creada con crearListaMina().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve finMina() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaMina anteriorMina(ListaMina &lista, PtrNodoListaMina ptrNodo) {

  PtrNodoListaMina ptrPrevio = finMina();
  PtrNodoListaMina ptrCursor = primeroMina(lista);

  while (( ptrCursor != finMina()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguienteMina(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : lista creada con crearListaMina().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve finMina() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaMina ultimoMina(ListaMina &lista) {

  /* el �ltimo nodo de la lista es el anterior al finMina() */
  return anteriorMina(lista,finMina());
}

/*----------------------------------------------------------------------------*/
PtrNodoListaMina crearNodoListaMina(MINA mina) {

  /* reserva memoria para el nodo y luego completa sus minas */
  PtrNodoListaMina ptrAux = new NodoListaMina;

  ptrAux->mina = mina;
  ptrAux->sgte = finMina();

  return ptrAux;
}

/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo nuevo al principio de la lista con el mina proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarPrincipioMina(ListaMina &lista, MINA mina) {

  /* crea el nodo */
  PtrNodoListaMina ptrNuevoNodo = crearNodoListaMina(mina);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo despues del apuntado por ptrNodo con el mina
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a finMina() no inserta
        nada y devuelve finMina().

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el mina.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarDespuesMina(ListaMina &lista, MINA mina, PtrNodoListaMina ptrNodo) {

  PtrNodoListaMina ptrNuevoNodo = finMina();

  /* si la lista est� vacia se adiciona la principio */
  if (listaVaciaMina(lista))
    ptrNuevoNodo = adicionarPrincipioMina(lista,mina);

  else {
    if (ptrNodo != finMina()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaMina(mina);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo al final de la lista con el mina proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarFinalMina(ListaMina &lista, MINA mina) {

  /* adiciona el mina despu�s del �ltimo nodo de la lista */
  return adicionarDespuesMina(lista,mina,ultimoMina(lista));
}

/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo con el mina proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve finMina(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el mina.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarAntesMina(ListaMina &lista, MINA mina, PtrNodoListaMina ptrNodo) {

  PtrNodoListaMina ptrNuevoNodo = finMina();

  if (! listaVaciaMina(lista)) {
    if (ptrNodo != primeroMina(lista))
      ptrNuevoNodo = adicionarDespuesMina(lista,mina,anteriorMina(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipioMina(lista,mina);
   }
   return ptrNuevoNodo;
}

/*
  pre : lista creada con crearListaMina(), no vacia. ptrNodo es distinto de finMina().
  post: coloca el mina proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el mina.
*/
void colocarMina(ListaMina &lista, MINA &mina, PtrNodoListaMina ptrNodo) {

  if ( (! listaVaciaMina(lista)) && (ptrNodo != finMina()))
    ptrNodo->mina = mina;
}

/*
  pre : lista creada con crearListaMina(), no vacia. ptrNodo es distinto de finMina().
  post: devuelve el mina del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el mina.
*/
void obtenerMina(ListaMina &lista, MINA &mina, PtrNodoListaMina ptrNodo) {

  if ((! listaVaciaMina(lista)) && (ptrNodo != finMina()))
    mina = ptrNodo->mina;
}

/*
  pre : lista creada con crearListaMina().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a finMina().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoMina(ListaMina &lista, PtrNodoListaMina ptrNodo) {

  PtrNodoListaMina ptrPrevio;

  /* verifica que la lista no est� vacia y que nodo no sea fin*/
  if ((! listaVaciaMina(lista)) && (ptrNodo != finMina())) {

    if (ptrNodo == primeroMina(lista))
      lista.primero = siguienteMina(lista,primeroMina(lista));

    else {
      ptrPrevio = anteriorMina( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el mina es un TDA, ac� habr�a que llamar al destructor.

    delete ptrNodo;
  }
}

/*...*/
void eliminarNodoPrimero(ListaMina &lista) {

  if (! listaVaciaMina(lista))
    eliminarNodoMina(lista,primeroMina(lista));
}

/*...*/
void eliminarNodoUltimoMina(ListaMina &lista) {

  if (! listaVaciaMina(lista))
    eliminarNodoMina(lista,ultimoMina(lista));
}

/*
  pre : lista creada con crearListaMina().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaMina(ListaMina &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaMina(lista))
    eliminarNodoMina(lista,primeroMina(lista));
}
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaMina().
  post: si el mina se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el mina no se encuentra en la lista devuelve finMina().

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a localizar.
  return puntero al nodo localizado o finMina().
*/
PtrNodoListaMina localizarMina(ListaMina &lista, MINA mina) {

   bool encontrado = false;
   MINA minaCursor;
   PtrNodoListaMina ptrCursor = primeroMina(lista);

  /* recorre los nodos hasta llegar al �ltimo o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finMina()) && (! encontrado)) {

    /* obtiene el mina del nodo y lo compara */
    obtenerMina(lista,minaCursor,ptrCursor);
    if (compararMina(minaCursor,mina) == IGUALMINA)
      encontrado = true;
    else
      ptrCursor = siguienteMina(lista,ptrCursor);
  }

  /* si no lo encontr� devuelve fin */
  if (! encontrado)
    ptrCursor = finMina();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearListaMina().
  post : elimina el mina de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a eliminar.
*/
void eliminarMina(ListaMina &lista, MINA mina) {

  /* localiza el mina y luego lo elimina */
  PtrNodoListaMina ptrNodo = localizarMina(lista,mina);
  if (ptrNodo != finMina())
    eliminarNodoMina(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearListaMina() y cargada con minas ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el mina manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMina insertarMina(ListaMina &lista, MINA mina) {

  PtrNodoListaMina ptrPrevio = primeroMina(lista);
  PtrNodoListaMina ptrCursor = primeroMina(lista);
  PtrNodoListaMina ptrNuevoNodo;
  MINA minaCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserci�n */
  while ((ptrCursor != finMina()) && (! ubicado)) {

    obtenerMina(lista,minaCursor,ptrCursor);
    if (compararMina(minaCursor,mina) == MAYORMINA)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguienteMina(lista,ptrCursor);
    }
  }

  if (ptrCursor == primeroMina(lista))
    ptrNuevoNodo = adicionarPrincipioMina(lista,mina);
  else
    ptrNuevoNodo = adicionarDespuesMina(lista,mina,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la lista fue creada con crearListaMina().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarMina(ListaMina &lista) {

  ListaMina temp = lista;
  PtrNodoListaMina ptrCursor = primeroMina(temp);
  crearListaMina(lista);
  while ( ptrCursor != finMina() ) {
        MINA mina;
        obtenerMina( temp, mina, ptrCursor);
        insertarMina( lista, mina );
        eliminarNodoMina( temp, ptrCursor );
        ptrCursor = primeroMina(temp);
  }
  eliminarListaMina( temp );
}

/*
  pre : la lista fue creada con crearListaMina().
  post : devuelve la cantidad de minas que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitud(ListaMina &lista){
  PtrNodoListaMina ptrCursor = primeroMina(lista);
  int longitud = 0;
  while ( ptrCursor != finMina() ) {
        longitud++;
        ptrCursor = siguienteMina( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/
