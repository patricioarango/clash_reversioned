

/* TDA Lista
 * Implementaci�n Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versi�n : 1.1
 */
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include "mina.h"
using namespace std;

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

void crearMina(MINA &mina)
{
    strcpy(mina.imagen,"assets/images/mina.png");
    mina.id_mina = 0;
    mina.posX = 0;
    mina.posY = 0;
    mina.intervalo_produccion = 0;
    mina.tipo = 0;
    mina.secuencia_produccion1 = 0;
    mina.secuencia_produccion2 = 0;
    mina.secuencia_produccion3 = 0;
    mina.secuencia_produccion4 = 0;
    mina.secuencia_produccion5 = 0;
    mina.material_generado = 0;
    mina.flag_sec1 = 0;
    mina.flag_sec2 = 0;
    mina.flag_sec3 = 0;
    mina.flag_sec4 = 0;
    mina.imgW = 70;
    mina.imgH = 70;
}
//-------------------------------------------------------------------------------------
void setMinaPosX(MINA &mina, int posicion)
{
    mina.posX= posicion;
}
//-------------------------------------------------------------------------------------
void setMinaPosY(MINA &mina, int posicion)
{
    mina.posY=posicion;
}
//-------------------------------------------------------------------------------------
void setMinaTipo(MINA &mina, int tipo)
{
    mina.tipo=tipo;
}
//-------------------------------------------------------------------------------------
void setMinaIntervaloProduccion(MINA &mina, int intervalo)
{
    mina.intervalo_produccion=intervalo;
}
//-------------------------------------------------------------------------------------
void setMinaSecuenciaProduccion1(MINA &mina, int secuenciaproduccion)
{
    mina.secuencia_produccion1=secuenciaproduccion;
}
//-------------------------------------------------------------------------------------
void setMinaSecuenciaProduccion2(MINA &mina, int secuenciaproduccion)
{
    mina.secuencia_produccion2=secuenciaproduccion;
}
//-------------------------------------------------------------------------------------
void setMinaSecuenciaProduccion3(MINA &mina, int secuenciaproduccion)
{
    mina.secuencia_produccion3=secuenciaproduccion;
}
//-------------------------------------------------------------------------------------
void setMinaSecuenciaProduccion4(MINA &mina, int secuenciaproduccion)
{
    mina.secuencia_produccion4=secuenciaproduccion;
}
//-------------------------------------------------------------------------------------
void setMinaSecuenciaProduccion5(MINA &mina, int secuenciaproduccion)
{
    mina.secuencia_produccion5=secuenciaproduccion;
}
//-------------------------------------------------------------------------------------
int setMinaMaterialGenerado(MINA &mina, int secuenciaproduccion)
{
    mina.material_generado=secuenciaproduccion;
}
//-------------------------------------------------------------------------------------
void setMinaFlagSec1(MINA &mina, int flag)
{
    mina.flag_sec1=flag;
}
//-------------------------------------------------------------------------------------
void setMinaFlagSec2(MINA &mina, int flag)
{
    mina.flag_sec2=flag;
}
//-------------------------------------------------------------------------------------
void setMinaFlagSec3(MINA &mina, int flag)
{
    mina.flag_sec3=flag;
}
//-------------------------------------------------------------------------------------
void setMinaFlagSec4(MINA &mina, int flag)
{
    mina.flag_sec4=flag;
}
//-------------------------------------------------------------------------------------
int getMinaIdMina(MINA &mina)
{
    return mina.id_mina;
}
//-------------------------------------------------------------------------------------
int getMinaPosX(MINA &mina)
{
    return mina.posX;
}
//--------------------------------------------------------------------------------------
int getMinaPosY(MINA &mina)
{
    return mina.posY;
}
//-------------------------------------------------------------------------------------
int getMinaIntervaloProduccion(MINA &mina)
{
    return mina.intervalo_produccion;
}
//-------------------------------------------------------------------------------------
int getMinaTipo(MINA &mina)
{
    return mina.tipo;
}
//-------------------------------------------------------------------------------------
int getMinaSecuenciaProduccion1(MINA &mina)
{
        return mina.secuencia_produccion1;
}
//-------------------------------------------------------------------------------------
int getMinaSecuenciaProduccion2(MINA &mina)
{
        return mina.secuencia_produccion2;
}
//-------------------------------------------------------------------------------------
int getMinaSecuenciaProduccion3(MINA &mina)
{
        return mina.secuencia_produccion3;
}
//-------------------------------------------------------------------------------------
int getMinaSecuenciaProduccion4(MINA &mina)
{
        return mina.secuencia_produccion4;
}
//-------------------------------------------------------------------------------------
int getMinaSecuenciaProduccion5(MINA &mina)
{
        return mina.secuencia_produccion5;
}
//-------------------------------------------------------------------------------------
int getMinaMaterialGenerado(MINA &mina)
{
    return mina.material_generado;
}
//-------------------------------------------------------------------------------------
int getMinaFlagSec1(MINA &mina)
{
    return mina.flag_sec1;
}
//-------------------------------------------------------------------------------------
int getMinaFlagSec2(MINA &mina)
{
    return mina.flag_sec2;
}
//-------------------------------------------------------------------------------------
int getMinaFlagSec3(MINA &mina)
{
    return mina.flag_sec3;
}
//-------------------------------------------------------------------------------------
int getMinaFlagSec4(MINA &mina)
{
    return mina.flag_sec4;
}
//-------------------------------------------------------------------------------------
int generacionMina(ListaMina &lista,int intervalo)
{
    int id_mina;
    int posX;
    int posY;
    int tipo;
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
    MINA mina;
    PtrNodoListaMina cursor = primeroMina(lista);
    while(cursor != finMina())
    {
        obtenerMina(lista,mina,cursor);
            //cout<<intervalo<<""<<endl;
        if(intervalo %getMinaIntervaloProduccion(mina) == 0){
                if((mina.flag_sec1 == 0)&&(mina.material_generado == 0)){
            setMinaMaterialGenerado(mina,mina.secuencia_produccion1);
            setMinaFlagSec1(mina, 1);
            //cout<<mina.material_generado<<""<<endl;
                }else if((mina.flag_sec2 == 0)&&(mina.material_generado == 0)){
            setMinaMaterialGenerado(mina,mina.secuencia_produccion2);
            setMinaFlagSec2(mina, 1);
                }else if((mina.flag_sec3 == 0)&&(mina.material_generado == 0)){
            setMinaMaterialGenerado(mina,mina.secuencia_produccion3);
            setMinaFlagSec3(mina, 1);
            }else if((mina.flag_sec4 == 0)&&(mina.material_generado == 0)){
            setMinaMaterialGenerado(mina,mina.secuencia_produccion4);
            setMinaFlagSec4(mina, 1);
            }else if((mina.flag_sec4 == 1)&&(mina.material_generado == 0)){
            setMinaMaterialGenerado(mina,mina.secuencia_produccion5);
            setMinaFlagSec1(mina, 0);
            setMinaFlagSec2(mina, 0);
            setMinaFlagSec3(mina, 0);
            setMinaFlagSec4(mina, 0);
            }
        }
        id_mina = getMinaIdMina(mina);
        posX = getMinaPosX(mina);
        posY = getMinaPosY(mina);
        tipo = getMinaTipo(mina);
        intervalo_produccion = getMinaIntervaloProduccion(mina);
        secuencia_produccion1 = getMinaSecuenciaProduccion1(mina);
        secuencia_produccion2 = getMinaSecuenciaProduccion2(mina);
        secuencia_produccion3 = getMinaSecuenciaProduccion3(mina);
        secuencia_produccion4 = getMinaSecuenciaProduccion4(mina);
        secuencia_produccion5 = getMinaSecuenciaProduccion5(mina);
        material_generado = getMinaMaterialGenerado(mina);
        flag_sec1 = getMinaFlagSec1(mina);
        flag_sec2 = getMinaFlagSec2(mina);
        flag_sec3 = getMinaFlagSec3(mina);
        flag_sec4 = getMinaFlagSec4(mina);
        eliminarMina(lista, mina);
        crearMina(mina);
        mina.id_mina = id_mina;
        setMinaPosX(mina, posX);
        setMinaPosY(mina, posY);
        setMinaTipo(mina, tipo);
        setMinaIntervaloProduccion(mina, intervalo_produccion);
        setMinaSecuenciaProduccion1(mina, secuencia_produccion1);
        setMinaSecuenciaProduccion2(mina, secuencia_produccion2);
        setMinaSecuenciaProduccion3(mina, secuencia_produccion3);
        setMinaSecuenciaProduccion4(mina, secuencia_produccion4);
        setMinaSecuenciaProduccion5(mina, secuencia_produccion5);
        setMinaMaterialGenerado(mina, material_generado);
        setMinaFlagSec1(mina, flag_sec1);
        setMinaFlagSec2(mina, flag_sec2);
        setMinaFlagSec3(mina, flag_sec3);
        setMinaFlagSec4(mina, flag_sec4);
        insertarMina(lista,mina);
        cursor = siguienteMina(lista,cursor);
    }
}
//-------------------------------------------------------------------------------------
int EntregarMinerales(ListaMina &lista)
{
    int id_mina;
    int posX;
    int posY;
    int tipo;
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
    int entregar_material;
    MINA mina;
    PtrNodoListaMina cursor = primeroMina(lista);
    while(cursor != finMina())
    {
        obtenerMina(lista,mina,cursor);
                if(mina.material_generado > 0){
            entregar_material = getMinaMaterialGenerado(mina);
            setMinaMaterialGenerado(mina, 0);
            //cout<<mina.material_generado<<""<<endl;
            }
        id_mina = getMinaIdMina(mina);
        posX = getMinaPosX(mina);
        posY = getMinaPosY(mina);
        tipo = getMinaTipo(mina);
        intervalo_produccion = getMinaIntervaloProduccion(mina);
        secuencia_produccion1 = getMinaSecuenciaProduccion1(mina);
        secuencia_produccion2 = getMinaSecuenciaProduccion2(mina);
        secuencia_produccion3 = getMinaSecuenciaProduccion3(mina);
        secuencia_produccion4 = getMinaSecuenciaProduccion4(mina);
        secuencia_produccion5 = getMinaSecuenciaProduccion5(mina);
        material_generado = getMinaMaterialGenerado(mina);
        flag_sec1 = getMinaFlagSec1(mina);
        flag_sec2 = getMinaFlagSec2(mina);
        flag_sec3 = getMinaFlagSec3(mina);
        flag_sec4 = getMinaFlagSec4(mina);
        eliminarMina(lista, mina);
        crearMina(mina);
        mina.id_mina = id_mina;
        setMinaPosX(mina, posX);
        setMinaPosY(mina, posY);
        setMinaTipo(mina, tipo);
        setMinaIntervaloProduccion(mina, intervalo_produccion);
        setMinaSecuenciaProduccion1(mina, secuencia_produccion1);
        setMinaSecuenciaProduccion2(mina, secuencia_produccion2);
        setMinaSecuenciaProduccion3(mina, secuencia_produccion3);
        setMinaSecuenciaProduccion4(mina, secuencia_produccion4);
        setMinaSecuenciaProduccion5(mina, secuencia_produccion5);
        setMinaMaterialGenerado(mina, material_generado);
        setMinaFlagSec1(mina, flag_sec1);
        setMinaFlagSec2(mina, flag_sec2);
        setMinaFlagSec3(mina, flag_sec3);
        setMinaFlagSec4(mina, flag_sec4);
        insertarMina(lista,mina);
        cursor = siguienteMina(lista,cursor);
    }
    return entregar_material;
}
//-------------------------------------------------------------------------------------
void destructorMina(MINA &mina)
{
}
//-------------------------------------------------------------------------------------
/*
  pre : la lista no debe haber sido creada.
  post: lista queda creada y preparada para ser usada.

  lista : estructura de minas a ser creado.
*/
void crearListaMina(ListaMina &lista) {
  lista.primero = finMina();
}
void recorrerListaMina(SDL_Renderer* renderer,ListaMina &lista)
{
    MINA mina;
    PtrNodoListaMina cursor = primeroMina(lista);
    while(cursor != finMina())
    {
        obtenerMina(lista,mina,cursor);
        renderizarMina(renderer,mina);
        cursor = siguienteMina(lista,cursor);
    }
}
void imprimirMina(MINA &mina)
{
    cout <<"int id_mina: "<< mina.id_mina<<endl;
    cout <<"int posX: "<< mina.posX<<endl;
    cout <<"int posY: "<< mina.posY<<endl;
    cout <<"int tipo: "<< mina.tipo<<endl;
    cout <<"int intervalo_produccion: "<< mina.intervalo_produccion<<endl;
    cout <<"int secuencia_produccion1: "<< mina.secuencia_produccion1<<endl;
    cout <<"int secuencia_produccion2: "<< mina.secuencia_produccion2<<endl;
    cout <<"int secuencia_produccion3: "<< mina.secuencia_produccion3<<endl;
    cout <<"int secuencia_produccion4: "<< mina.secuencia_produccion4<<endl;
    cout <<"int secuencia_produccion5: "<< mina.secuencia_produccion5<<endl;
    cout <<"int materialgenerado: "<< mina.material_generado<<endl;
    cout <<"int flag1: "<< mina.flag_sec1<<endl;
    cout <<"int flag2: "<< mina.flag_sec2<<endl;
    cout <<"int flag3: "<< mina.flag_sec3<<endl;
    cout <<"int flag4: "<< mina.flag_sec4<<endl;
    cout <<"int imgW: "<< mina.imgW<<endl;
    cout <<"int imgH: "<< mina.imgH<<endl;
    std::string imagentp22 = mina.imagen;
    cout <<  "imagen: " << imagentp22 <<endl;
    cout << "******" << endl;
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

void renderizarMina(SDL_Renderer* renderer,MINA &mina)
{
    //imprimirMina(mina);
    SDL_Surface* tmpsurface = IMG_Load(mina.imagen);
    SDL_Texture* casillero_render = SDL_CreateTextureFromSurface(renderer,tmpsurface);
    SDL_FreeSurface(tmpsurface);
    SDL_Rect destR;
    destR.w = 70;
    destR.h = 70;
    destR.x = getMinaPosX(mina);
    destR.y = getMinaPosY(mina);
    SDL_RenderCopy(renderer,casillero_render,NULL,&destR);
}
/*----------------------------------------------------------------------------*/
