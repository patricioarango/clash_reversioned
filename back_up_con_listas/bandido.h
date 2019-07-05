#ifndef BANDIDO_H_INCLUDED
#define BANDIDO_H_INCLUDED

typedef struct {
    int id_bandido;
    int posX;
    int posY;
    int imgW;
    int imgH;
    char imagen[27];
    int intervalo_aparicion;
    int intervalo_desaparicion;
    int roba_cantidad;
    int tipo_lingote;
}BANDIDO;


/* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionBandido {
  MAYORBANDIDO,
  IGUALBANDIDO,
  MENORBANDIDO
};

/**
Pre: El bandido no debe haber sido creado;
Post: Se crea el bandido;
*/
void crearBandido(BANDIDO &bandido);

/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a id_bandido;
*/
void setBandidoIdBandido(BANDIDO &bandido, int id);
/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a posX;
*/
void setBandidoPosX(BANDIDO &bandido, int posicion);
/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a posY;
*/
void setBandidoPosY(BANDIDO &bandido, int posicion);
/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a intervalo_aparicion;
*/
void setBandidoIntervaloAparicion(BANDIDO &bandido, int intervalo);
/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a intervalo_desaparicion;
*/
void setBandidoIntervaloDesaparicion(BANDIDO &bandido, int intervalo);
/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a roba_cantidad;
*/
void setBandidoRobaCantidad(BANDIDO &bandido, int cantidad);
/**
Pre: el bandido debe haber sido creado;
Post: se le asigna el valor a tipo_lingote;
*/
void setBandidoTipoLingote(BANDIDO &bandido, int tipo);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de id_bandido;
*/
int getBandidoIdBandido(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de posX;
*/
int getBandidoPosX(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de posY;
*/
int getBandidoPosY(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de ImgW;
*/
int getBandidoImgW(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de ImgH;
*/
int getBandidoImgH(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de intervalo_aparicion;
*/
int getBandidoIntervaloAparicion(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de intervalo_desaparicion;
*/
int getBandidoIntervaloDesaparicion(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de roba_cantidad;
*/
int getBandidoRobaCantidad(BANDIDO &bandido);
/**
Pre: el bandido debe haber sido creado;
Post: devuelve el valor de tipo_lingote;
*/
int getBandidoTipoLingote(BANDIDO &bandido);

/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como Dato. */

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaBandido {
    BANDIDO bandido; // dato almacenado
    NodoListaBandido* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus Datos. */
typedef NodoListaBandido* PtrNodoListaBandido;


/* Tipo de Estructura de la Lista */
struct ListaBandido{
    PtrNodoListaBandido primero;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de datos a ser creado.
*/
void crearListaBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaBandido().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaVaciaBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaBandido().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaBandido finBandido();

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaBandido().
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaBandido primeroBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaBandido().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaBandido siguienteBandido(ListaBandido &lista, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaBandido().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaBandido anteriorBandido(ListaBandido &lista, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaBandido ultimoBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo nuevo al principio de la lista con el dato proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarPrincipioBandido(ListaBandido &lista, BANDIDO dato);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarDespuesBandido(ListaBandido &lista, BANDIDO dato, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo al final de la lista con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarFinalBandido(ListaBandido &lista, BANDIDO dato);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoListaBandido adicionarAntesBandido(ListaBandido &lista, BANDIDO dato, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido(), no vacia. ptrNodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarBANDIDO(ListaBandido &lista, BANDIDO &dato, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerBANDIDO(ListaBandido &lista, BANDIDO &dato, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoBandido(ListaBandido &lista, PtrNodoListaBandido ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimeroBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimoBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaBandido().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaBandidoBandido(ListaBandido &lista);


/******************************************************************************/
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaBandido().
  post: si el dato se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoListaBandido localizarBANDIDO(ListaBandido &lista , BANDIDO dato);

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearListaBandido() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaBandido insertarBANDIDO(ListaBandido &lista, BANDIDO dato);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaBandido().
  post : elimina el dato de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarBANDIDO(ListaBandido &lista, BANDIDO dato);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaBandido().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarBandido(ListaBandido &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaBandido().
  post : devuelve la cantidad de datos que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitudBandido(ListaBandido &lista);

void renderizarBandido(SDL_Renderer* renderer,BANDIDO &bandido);

void imprimirBandido(BANDIDO &bandido);

void generarBandido(ListaBandido &lista, BANDIDO &bandido,int intervalo,int valor_intervalo_desaparicion);

void recorrerListaBandidos(SDL_Renderer* renderer,ListaBandido &lista);

void evaluarBandidos(ListaBandido &lista,int intervalo);

#endif // BANDIDO_H_INCLUDED
