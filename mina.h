#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED
/**Tipo minas Mina
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
Las minas producen un único ítem, en forma de lingotes, con una secuencia establecida.
 Por ejemplo, una mina de oro puede tener la secuencia 2, 2, 4, 3, 5.
 Esto significa que, en el primer intervalo, generará una caja con dos lingotes;
 en el segundo,  otra con 2; en el tercero, una con 4; en el cuarto, una con 3;
 y en el quinto, una con 5. Al finalizar, vuelve a iniciar la secuencia.
 La producción de cada caja ocurre cada IP intervalos.
*/

/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como MINA. */
typedef struct{
    int id_mina;
    int posX;
    int posY;
    int tipo; //1 oro 2 cobre 3 bronce
    int intervalo_produccion;
    int secuencia_produccion1;
    int secuencia_produccion2;
    int secuencia_produccion3;
    int secuencia_produccion4;
    int secuencia_produccion5;
    int material_generado;
    int flag_sec1;
    int flag_sec2;
    int flag_sec3;
    int flag_sec4;
    char imagen[27];
    int imgW;
    int imgH;
} MINA;
/******************************************************************************/
/* Definiciones de Tipos de MINAs */
/*--------------------------------*/

/* tipo enumerado para realizar comparaciones */
enum ResultadoComparacionMina {
  MAYORMINA,
  IGUALMINA,
  MENORMINA
};
/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como MINA. */
/**-----------------------------------------------------------------------------*/
/*
PRE :La mina no debe haber sido creada.
POST :  Se mina queda creada y lista para ser usada.
*/
void crearMina(MINA &mina);
void renderizarMina(SDL_Renderer* renderer,MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo f para a contener el dato del archivo minas.txt
*/
void setMinaPosX(MINA &mina, int posicion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo c para a contener el dato del archivo minas.txt
*/
void setMinaPosY(MINA &mina, int posicion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo tipo para a contener el dato del archivo minas.txt
*/
void setMinaTipo(MINA &minas, int tipo);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : el campo intervaloproduccion para a contener el dato del archivo minas.txt
*/
void setMinaIntervaloProduccion(MINA &mina, int intervalo);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea Secuenciaproduccion 1.
*/
void setMinaSecuenciaProduccion1(MINA &mina, int secuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea Secuenciaproduccion 2.
*/
void setMinaSecuenciaProduccion2(MINA &mina, int secuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea Secuenciaproduccion 3.
*/
void setMinaSecuenciaProduccion3(MINA &mina, int secuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea Secuenciaproduccion 4.
*/
void setMinaSecuenciaProduccion4(MINA &mina, int secuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea Secuenciaproduccion 5.
*/
void setMinaSecuenciaProduccion5(MINA &mina, int secuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : genera X kilos de mineral de la/s mina/s segun intervalo de produccion correspondiente.
*/
int setMinaMaterialGenerado(MINA &mina, int secuenciaproduccion);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea la bandera para saber si ya genero decha secuencia de produccion.
*/
void setMinaFlagSec1(MINA &mina, int flag);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea la bandera para saber si ya genero decha secuencia de produccion.
*/
void setMinaFlagSec2(MINA &mina, int flag);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea la bandera para saber si ya genero decha secuencia de produccion.
*/
void setMinaFlagSec3(MINA &mina, int flag);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : setea la bandera para saber si ya genero decha secuencia de produccion.
*/
void setMinaFlagSec4(MINA &mina, int flag);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene el id de la mina.
*/
int getMinaIdMina(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la ubicacion de la fila donde sera ubicada la mina.
*/
int getMinaPosX(MINA &mina);
//-------------------------------------------------------------------------------------]
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la ubicacion de la columna donde sera dibujada la mina.
*/
int getMinaPosY(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene el intervalo de produccion de la mina.
*/
int getMinaIntervaloProduccion(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene el tipo de mineral que producira la mina.
*/
int getMinaTipo(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia 1 en que producira minerales la mina.
*/
int getMinaSecuenciaProduccion1(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia 2 en que producira minerales la mina.
*/
int getMinaSecuenciaProduccion2(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia 3 en que producira minerales la mina.
*/
int getMinaSecuenciaProduccion3(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia 4 en que producira minerales la mina.
*/
int getMinaSecuenciaProduccion4(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia 5 en que producira minerales la mina.
*/
int getMinaSecuenciaProduccion5(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : Se obtiene la secuencia 5 en que producira minerales la mina.
*/
int getMinaMaterialGenerado(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : devuelve la bandera para saber si ya genero decha secuencia de produccion.
*/
int getMinaFlagSec1(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : devuelve la bandera para saber si ya genero decha secuencia de produccion.
*/
int getMinaFlagSec2(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : devuelve la bandera para saber si ya genero decha secuencia de produccion.
*/
int getMinaFlagSec3(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : mina creada por la funcion crearMina
POST : devuelve la bandera para saber si ya genero decha secuencia de produccion.
*/
int getMinaFlagSec4(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      La mina debe haber sido dibujada por la funcion dibujarMina.
      La locomotora debe haber chocado con la mina.
      Se debe tener los valores de las funciones getTipomineral y getSecuenciaproduccion.
POST : Si hay minerales en la mina y se tiene espacio disponible se le entrega minerales en bagon del mismo mineral al jugador.
*/
int EntregarMinerales(MINA &mina);
//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
POST : La mina es eliminada de la partida.
*/
void eliminarMina(MINA &mina);


/**-----------------------------------------------------------------------------*/

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaMina {
    MINA mina; // mina almacenado
    NodoListaMina* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus MINAs. */
typedef NodoListaMina* PtrNodoListaMina;


/* Tipo de Estructura de la Lista */
struct ListaMina{
    PtrNodoListaMina primero;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de minas a ser creado.
*/
void crearListaMina(ListaMina &lista);
void recorrerListaMina(SDL_Renderer* renderer,ListaMina &lista);
void imprimirMina(MINA &mina);
/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMina().
  post: Devuelve true si lista esta vacia, sino devuelve false.

  lista : lista sobre la cual se invoca la primitiva.
*/
bool listaMinaVacia(ListaMina &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMina().
  post: devuelve la representacion de lo Siguiente al �ltimo Nodo de la lista,
        o sea el valor Null, que en esta implementacion representa el final de
        la lista.

  return representaci�n del fin de la lista.
*/
PtrNodoListaMina finMina();

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMina().
  post: devuelve el puntero al primer elemento de la lista, o devuelve fin() si
        esta vacia

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoListaMina primeroMina(ListaMina &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMina().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoListaMina siguienteMina(ListaMina &lista, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista Creada con crearListaMina().
        ptrNodo es un puntero a un nodo de lista.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoListaMina anteriorMina(ListaMina &lista, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: devuelve el puntero al ultimo nodo de la lista, o devuelve fin() si
        si lista esta vacia.

  lista : lista sobre la cual se invoca la primitiva.
  return puntero al �ltimo nodo.
*/
PtrNodoListaMina ultimoMina(ListaMina &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo nuevo al principio de la lista con el mina proporcionado
        y devuelve un puntero a ese elemento.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar al principio de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarPrincipioMina(ListaMina &lista, MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo despues del apuntado por ptrNodo con el mina
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la lista esta vac�a agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar.
  ptrNodo : puntero al nodo despu�s del cual se quiere adicionar el mina.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarDespuesMina(ListaMina &lista, MINA mina, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo al final de la lista con el mina proporcionado y devuelve
        un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar al final de la lista.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarFinalMina(ListaMina &lista, MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: agrega un nodo con el mina proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la lista esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el mina.
  return puntero al nodo adicionado.
*/
PtrNodoListaMina adicionarAntesMina(ListaMina &lista, MINA mina, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina(), no vacia. ptrNodo es distinto de fin().
  post: coloca el mina proporcionado en el nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el mina.
*/
void colocarMina(ListaMina &lista, MINA &mina, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el mina del nodo apuntado por ptrNodo.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el mina.
*/
void obtenerMina(ListaMina &lista, MINA &mina, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
        esta vacia o si ptrNodo apunta a fin().

  lista : lista sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodoMina(ListaMina &lista, PtrNodoListaMina ptrNodo);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: si la lista no esta vacia, elimina su nodo primero, sino no realiza
        accion alguna.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoPrimeroMina(ListaMina &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: si la lista no esta vacia elimina su nodo ultimo,
        sino no realiza accion.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarNodoUltimoMina(ListaMina &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : lista creada con crearListaMina().
  post: elimina todos los Nodos de la lista quedando destruida e inhabilitada
        para su uso.

  lista : lista sobre la cual se invoca la primitiva.
*/
void eliminarListaMinaMina(ListaMina &lista);


/******************************************************************************/
/* Definici�n de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : lista fue creada con crearListaMina().
  post: si el mina se encuentra en la lista, devuelve el puntero al primer nodo
        que lo contiene. Si el mina no se encuentra en la lista devuelve fin().

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoListaMina localizarMina(ListaMina &lista , MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : lista fue creada con crearListaMina() y cargada con minas ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la lista el mina manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoListaMina insertarMina(ListaMina &lista, MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaMina().
  post : elimina el mina de la lista, si el mismo se encuentra.

  lista : lista sobre la cual se invoca la primitiva.
  mina : elemento a eliminar.
*/
void eliminarMina(ListaMina &lista, MINA mina);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaMina().
  post : reordena la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
void reordenarMina(ListaMina &lista);

/*----------------------------------------------------------------------------*/
/*
  pre : la lista fue creada con crearListaMina().
  post : devuelve la cantidad de minas que tiene la lista.

  lista : lista sobre la cual se invoca la primitiva.
*/
int longitudMina(ListaMina &lista);

//-------------------------------------------------------------------------------------
/**
PRE : La mina debe haber sido creada por la funcion crearMina.
      La mina debe haber sido ubicada en el mapa por la funcion ubicarMina.
POST : Se producen minerales en la mina segun secuencia de intervalos.
*/
int generacionMina(ListaMina &lista, int intervalo);

#endif

