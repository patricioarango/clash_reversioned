#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdlib>
#include "mina.h"


/******************************************************************************/
/* Definición de Tipos de MINAs para manejo interno */
/*--------------------------------------------------*/
    /* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionMinas {
  MAYOR,
  IGUAL,
  MENOR
};

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
ResultadoComparacionMinas compararMINA(MINA mina1, MINA mina2) {
    if (mina1.id_mina > mina2.id_mina) {
        return MAYOR;
    }
    else if (mina1.id_mina < mina2.id_mina) {
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

  lista : estructura de minas a ser creado.
*/
void crearListaMina(ListaMinas &listaminas) {
  listaminas.primero = fin();
}

/*
  pre : lista Creada con crearLista().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representación del fin de la lista.
*/
PtrNodoListaMinas fin() {
  return NULL;
}

/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMinas primeroMinas(ListaMinas &listaminas) {
  return listaminas.primero;
}

/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMinas siguienteMinas(ListaMinas &listaminas, PtrNodoListaMinas ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if (ptrNodo != fin())
    return ptrNodo->sgte;
  else
    return fin();
}



/*----------------------------------------------------------------------------*/
PtrNodoListaMinas crearNodoListaMinas(MINA mina) {

  /* reserva memoria para el nodo y luego completa sus minas */
  PtrNodoListaMinas ptrAux = new NodoListaMinas;

  ptrAux->mina = mina;
  ptrAux->sgte = fin();

  return ptrAux;
}

/*
  pre : lista creada con crearLista().
  post: agrega un nodo nuevo al principio de la lista con el mina proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMinas adicionarPrincipioMinas(ListaMinas &listaminas, MINA mina) {

  /* crea el nodo */
  PtrNodoListaMinas ptrNuevoNodo = crearNodoListaMinas(mina);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = listaminas.primero;
  listaminas.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: coloca el mina proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el mina.
*/
void colocarMINA(ListaMinas &lista, MINA &mina, PtrNodoListaMinas ptrNodo) {

  if (ptrNodo != fin())
    ptrNodo->mina = mina;
}

/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el mina del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el mina.
*/
void obtenerMINA(ListaMinas &lista, MINA &mina, PtrNodoListaMinas ptrNodo) {

  if (ptrNodo != fin())
    mina = ptrNodo->mina;
}

/*
  pre : lista creada con crearLista().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoMina(ListaMinas &listaminas, PtrNodoListaMinas ptrNodo) {
}


/*
  pre : lista creada con crearLista().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/

/* Definición de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearLista().
  post: si el mina se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el mina no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoListaMinas localizarMINA(ListaMinas &lista, MINA mina) {

   bool encontrado = false;
   MINA minaCursor;
   PtrNodoListaMinas ptrCursor = primeroMinas(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin()) && (! encontrado)) {

    /* obtiene el mina del nodo y lo compara */
    obtenerMINA(lista,minaCursor,ptrCursor);
    if (compararMINA(minaCursor,mina) == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguienteMinas(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin();

  return ptrCursor;
}

/*
  pre : la lista fue creada con crearLista().
  post : elimina el mina de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a eliminar.
*/
void eliminarMINA(ListaMinas &lista, MINA mina) {

  /* localiza el mina y luego lo elimina */
  PtrNodoListaMinas ptrNodo = localizarMINA(lista,mina);
  if (ptrNodo != fin())
    eliminarNodoMina(lista,ptrNodo);
}

/*
  pre : lista fue creada con crearLista() y cargada con minas ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el mina manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMinas insertarMINA(ListaMinas &lista, MINA mina) {

  PtrNodoListaMinas ptrPrevio = primeroMinas(lista);
  PtrNodoListaMinas ptrCursor = primeroMinas(lista);
  PtrNodoListaMinas ptrNuevoNodo;
  MINA minaCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin()) && (! ubicado)) {

    obtenerMINA(lista,minaCursor,ptrCursor);
    if (compararMINA(minaCursor,mina) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguienteMinas(lista,ptrCursor);
    }
  }

  if (ptrCursor == primeroMinas(lista))
    ptrNuevoNodo = adicionarPrincipioMinas(lista,mina);
  else
    ptrNuevoNodo = adicionarDespuesMinas(lista,mina,ptrPrevio);

  return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaMinas adicionarDespuesMinas(ListaMinas &lista, MINA mina, PtrNodoListaMinas ptrNodo) {

  PtrNodoListaMinas ptrNuevoNodo = fin();

  /* si la lista está vacia se adiciona la principio */
  if (listaVaciaMinas(lista))
    ptrNuevoNodo = adicionarPrincipioMinas(lista,mina);

  else {
    if (ptrNodo != fin()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaMinas(mina);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

bool listaVaciaMinas(ListaMinas &lista) {

  return (primeroMinas(lista) == fin());
}
