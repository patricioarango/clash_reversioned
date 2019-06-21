#include <SDL.h>
#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

typedef struct {
    int id_moneda;
    int valor;
    int posX;
    int posY;
    int imgW;
    int imgH;
    char imagen[27];
    int intervalo_desaparicion;
}MONEDA;

void initMoneda(MONEDA &moneda);

void generarMoneda(MONEDA &moneda, int intervalo,int valor_intervalo_desaparicion);
int getMonedaPosX(MONEDA &moneda);
int getMonedaPosY(MONEDA &moneda);
int getMonedaImgW(MONEDA &moneda);
int getMonedaImgH(MONEDA &moneda);
int getMonedaIntervaloDesaparicion(MONEDA &moneda);
char* getMonedaImagen(MONEDA &moneda);

/* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionMoneda {
  MAYORMONEDA,
  IGUALMONEDA,
  MENORMONEDA
};
/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como MONEDA. */


/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaMoneda {
    MONEDA moneda; // moneda almacenado
    NodoListaMoneda* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus MONEDAs. */
typedef NodoListaMoneda* PtrNodoListaMoneda;


/* Tipo de Estructura de la Lista */
struct ListaMoneda{
    PtrNodoListaMoneda primero;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de monedas a ser creado.
*/
void crearListaMoneda(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMoneda().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaMonedaVacia(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMoneda().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaMoneda finMoneda();

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMoneda().
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMoneda primeroMoneda(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMoneda().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMoneda siguienteMoneda(ListaMoneda &lista, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMoneda().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaMoneda anteriorMoneda(ListaMoneda &lista, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaMoneda ultimoMoneda(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo nuevo al principio de la lista con el moneda proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarPrincipioMoneda(ListaMoneda &lista, MONEDA moneda);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo despues del apuntado por ptrNodo con el moneda
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el moneda.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarDespuesMoneda(ListaMoneda &lista, MONEDA moneda, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo al final de la lista con el moneda proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarFinalMoneda(ListaMoneda &lista, MONEDA moneda);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: agrega un nodo con el moneda proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el moneda.
  return puntero al nodo adicionado.
*/
PtrNodoListaMoneda adicionarAntesMoneda(ListaMoneda &lista, MONEDA moneda, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda(), no vacia. ptrNodo es distinto de fin().
  post: coloca el moneda proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el moneda.
*/
void colocarMoneda(ListaMoneda &lista, MONEDA &moneda, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el moneda del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el moneda.
*/
void obtenerMoneda(ListaMoneda &lista, MONEDA &moneda, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: elimoneda el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea elimonedar.
*/
void elimonedarNodoMoneda(ListaMoneda &lista, PtrNodoListaMoneda ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: si la lista no esta vacia, elimoneda su nodo primero, sino no realiza
        accion alguna.

  lista : lista sobre la cual se invoca la primitiva.
*/
void elimonedarNodoPrimeroMoneda(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: si la lista no esta vacia elimoneda su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void elimonedarNodoUltimoMoneda(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMoneda().
  post: elimoneda todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void elimonedarListaMonedaMoneda(ListaMoneda &lista);


/******************************************************************************/
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaMoneda().
  post: si el moneda se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el moneda no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoListaMoneda localizarMoneda(ListaMoneda &lista , MONEDA moneda);

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearListaMoneda() y cargada con monedas ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el moneda manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMoneda insertarMoneda(ListaMoneda &lista, MONEDA moneda);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaMoneda().
  post : elimoneda el moneda de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  moneda : elemento a elimonedar.
*/
void elimonedarMoneda(ListaMoneda &lista, MONEDA moneda);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaMoneda().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarMoneda(ListaMoneda &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaMoneda().
  post : devuelve la cantidad de monedas que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitudMoneda(ListaMoneda &lista);

#endif // MONEDA_H_INCLUDED
