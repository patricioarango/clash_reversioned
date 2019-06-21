#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED
/**Tipo datos Mina
Atributos:
*posX,
*posY,
*tipoMineral,
*intervaloProduccion,
*SecuenciaProducion,
Axiomas:
*PosX > 0 & < 15 & no ocupada por otra entidad (estacion, posicion inicial del carro u otra mina)
*posY > 0 & < 20 & no ocupada por otra entidad (estacion, posicion inicial del carro u otra mina)
*TipoMaterial = oro, plata, cobre, platino, carbon o roca
*intervaloProduccion > 0
*SecuenciaProduccion > 0
*/

/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como MINA. */
typedef struct{
    int id_mina;
    int posX;
    int posY;
    int tipo; //1 oro 2 cobre 3 bronce
    char imagen[27];
    int imgW;
    int imgH;
} MINA;

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaMinas {
    MINA mina; // mina almacenado
    NodoListaMinas* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus MINAs. */
typedef NodoListaMinas* PtrNodoListaMinas;


/* Tipo de Estructura de la Lista */
struct ListaMinas{
    PtrNodoListaMinas primero;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de minas a ser creado.
*/
void crearListaMinas(ListaMinas &listaminas);
PtrNodoListaMinas primeroMinas(ListaMinas &listaminas);
/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: devuelve la representacion de lo Siguiente al último Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representación del fin de la lista.
*/
PtrNodoListaMinas fin();

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearLista().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMinas siguienteMinas(ListaMinas &listaminas, PtrNodoListaMinas ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: agrega un nodo nuevo al principio de la lista con el mina proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMinas adicionarPrincipioMinas(ListaMinas &listaminas, MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el mina del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el mina.
*/
void obtenerMINA(ListaMinas &listaminas, MINA &mina, PtrNodoListaMinas ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoMina(ListaMinas &listaminas, PtrNodoListaMinas ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearLista().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaMinas(ListaMinas &listaminas);


/******************************************************************************/
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
PtrNodoListaMinas localizarMINA(ListaMinas &listaminas , MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearLista() y cargada con minas ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el mina manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMinas insertarMINA(ListaMinas &listaminas, MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearLista().
  post : elimina el mina de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a eliminar.
*/
void eliminarMINA(ListaMinas &listaminas, MINA mina);
bool listaVaciaMinas(ListaMinas &listaminas);
PtrNodoListaMinas adicionarDespuesMinas(ListaMinas &lista, MINA mina, PtrNodoListaMinas ptrNodo);
#endif // MINA_H_INCLUDED
