#include <string>
#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED
#ifndef NULL
#define NULL      0
#endif

typedef struct{
    int id_vagon;
    int posX;
    int posY;
    int direccion;
    int posX_anterior;
    int posY_anterior;
    int tipo_direccion;
    int imgW;
    int imgH;
    char imagen[27];
    int carga;
    int tipo_carga;
}VAGON;

typedef struct {
    int posX = 0;
    int posY = 0;
    int imgW;
    int imgH;
    int monedas;
    int direccion = 1; //0 arriba, 1 der, 2 abajo, 3 izq
    int tipo_direccion = 1; //1 suma 0 resta
    char imagen[27];
    VAGON *vagon;
}TREN;


void setTrenDireccion(TREN &tren,int direccion);
void setTrenImagenporDireccion(TREN &tren,int direccion);
void setTrenTipoDireccion(TREN &tren,int tipo_direccion);
void setTrenPosX(TREN &tren,int posicion);
void setTrenPosY(TREN &tren,int posicion);
void setTrenImgW(TREN &tren, int img);
void setTrenImgH(TREN &tren, int img);

int getTrenPosX(TREN &tren);
int getTrenPosY(TREN &tren);
char* getTrenImagen(TREN &tren);
int getTrenImgW(TREN &tren);
int getTrenImgH(TREN &tren);
int getTrenDireccion(TREN &tren);
int getTrenTipoDireccion(TREN &tren);

void setVagonId(VAGON &vagon, int id);
void setVagonPosX(VAGON &vagon, int pos);
void setVagonPosY(VAGON &vagon, int pos);
void setVagonPosXAnterior(VAGON &vagon, int pos);
void setVagonPosYAnterior(VAGON &vagon, int pos);
void setVagonDireccion(VAGON &vagon, int pos);
void setVagonTipoDireccion(VAGON &vagon, int direccion);
void setVagonImagenporDireccion(VAGON &vagon,int direccion);

int getVagonId(VAGON &vagon);
int getVagonPosX(VAGON &vagon);
int getVagonPosY(VAGON &vagon);
int getVagonPosXAnterior(VAGON &vagon);
int getVagonPosYAnterior(VAGON &vagon);
int getVagonDireccion(VAGON &vagon);
int getVagonTipoDireccion(VAGON &vagon);
char* getVagonImagen(VAGON &vagon);
int getVagonImgW(VAGON &vagon);
int getVagonImgH(VAGON &vagon);
int getVagonCarga(VAGON &vagon);
int getVagonTipoCarga(VAGON &vagon);

/* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionVagon {
  MAYORVAGON,
  IGUALVAGON,
  MENORVAGON
};
/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como VAGON. */

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaVagon {
    VAGON vagon; // vagon almacenado
    NodoListaVagon* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus VAGONs. */
typedef NodoListaVagon* PtrNodoListaVagon;


/* Tipo de Estructura de la Lista */
struct ListaVagon{
    PtrNodoListaVagon primero;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de vagons a ser creado.
*/
void crearListaVagon(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaVagon().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVagonVacia(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaVagon().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaVagon finVagon();

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaVagon().
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaVagon primeroVagon(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaVagon().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaVagon siguienteVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaVagon().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaVagon anteriorVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaVagon ultimoVagon(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo nuevo al principio de la lista con el vagon proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarPrincipioVagon(ListaVagon &lista, VAGON vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo despues del apuntado por ptrNodo con el vagon
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el vagon.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarDespuesVagon(ListaVagon &lista, VAGON vagon, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo al final de la lista con el vagon proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarFinalVagon(ListaVagon &lista, VAGON vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: agrega un nodo con el vagon proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el vagon.
  return puntero al nodo adicionado.
*/
PtrNodoListaVagon adicionarAntesVagon(ListaVagon &lista, VAGON vagon, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon(), no vacia. ptrNodo es distinto de fin().
  post: coloca el vagon proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el vagon.
*/
void colocarVagon(ListaVagon &lista, VAGON &vagon, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el vagon del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el vagon.
*/
void obtenerVagon(ListaVagon &lista, VAGON &vagon, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: elivagon el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea elivagonr.
*/
void eliminarNodoVagon(ListaVagon &lista, PtrNodoListaVagon ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: si la lista no esta vacia, elivagon su nodo primero, sino no realiza
        accion alguna.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimeroVagon(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: si la lista no esta vacia elivagon su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimoVagon(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaVagon().
  post: elivagon todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaVagonVagon(ListaVagon &lista);


/******************************************************************************/
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaVagon().
  post: si el vagon se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el vagon no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoListaVagon localizarVagon(ListaVagon &lista , VAGON vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearListaVagon() y cargada con vagons ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el vagon manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaVagon insertarVagon(ListaVagon &lista, VAGON vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaVagon().
  post : elivagon el vagon de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  vagon : elemento a elivagonr.
*/
void eliminarVagon(ListaVagon &lista, VAGON vagon);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaVagon().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarVagon(ListaVagon &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaVagon().
  post : devuelve la cantidad de vagons que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitudVagon(ListaVagon &lista);
void recorrerListaVagones(SDL_Renderer* renderer,ListaVagon &lista,TREN& tren);
void agregarVagonTren(TREN &tren,ListaVagon &lista);
void initTren(SDL_Renderer* renderer,TREN &tren,ListaVagon &lista);
void imprimirVagon(VAGON &vagon);
void renderizarVagon(SDL_Renderer* renderer,VAGON &vagon);
void crearVagon(VAGON &vagon);
#endif // TREN_H_INCLUDED
