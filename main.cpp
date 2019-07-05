#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include <cstring>
#include "juego.h"
#include "moneda.h"
#include "casillero.h"
#include "tren.h"
#include "mina.h"
#include "estacion.h"
#include "mapa.h"
#include "bandido.h"
#include "comanda.h"

using namespace std;
/* PARAMETROS
S: Segundos que dura un intervalo.
 P: cantidad máxima que puede pedir un bandido.
 A: posiciones para definir el área de Ataque de un bandido.
 posXE: posición x de la estación.
 posYE: posición y de la estación.
 IM: intervalo máximo para generación de monedas.
 VM: intervalos máximos de vida de una moneda.
 IB: máxima cantidad de intervalos para la aparición de bandidos.
 VB: tiempo máximo de vida de un bandido.
 IP: intervalos entre producciones de las minas.
/**/
void evaluarEventosTeclado(JUEGO &juego,TREN &tren,VAGON &vagon,ListaVagon &listavagon,SDL_Event &event,const unsigned char *keys);
void evaluarCambioDireccion(JUEGO &juego,TREN &tren);
void evaluarSalidadePista(JUEGO &juego,TREN &tren);
void agregarMonedaListaMapa(Lista &listaMapa,ListaMoneda &listamonedas);
void agregarBandidoListaMapa(Lista &listaMapa,ListaBandido &listabandidos);
void agregarMinaListaMapa(Lista &listaMapa,ListaMina &listaminas);
void agregarTrenListaMapa(Lista &listaMapa,TREN &tren);
void agregarVagonesListaMapa(Lista &listaMapa,ListaVagon &lista);
void agregarEstacionListaMapa(Lista &listaMapa,ESTACION &estacion);
void recorrerListaMapa(SDL_Renderer* renderer,Lista &listaMapa,int intervalo,JUEGO &juego,TREN &tren,MONEDA &moneda,ListaMoneda &listamonedas,ListaVagon &listavagones,ListaMina &listaminas,ListaBandido &listabandidos);
void compararComandaVagones(COMANDA &comanda, ListaVagon &lista, JUEGO &juego);
void colisionTrenMoneda(TREN &tren,MONEDA &moneda,Dato &datomoneda,ListaMoneda &listamonedas);
void colisionTrenEstacion(TREN &tren,ListaVagon &listavagones);
void colisionTrenMina(ListaMina &listaminas,ListaVagon &listavagones,Dato &datomina);
void colisionTrenVagonBandido(TREN &tren,Dato &datobandido,ListaBandido &listabandidos,ListaVagon &listavagones,JUEGO &juego);

int main(int argc,char *argv[])
{

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        //iniciaciones
        SDL_Window *window;
        SDL_Renderer *renderer;

        JUEGO juego;
        initJuego(juego);
        setJuegoAnchoVentana(juego,800);
        setJuegoAltoVentana(juego,600);
        setJuegoColumnas(juego,20);
        setJuegoFilas(juego,15);

        window = SDL_CreateWindow(
        "Clash of UnLa",
        SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
        getJuegoAnchoVentana(juego),getJuegoAltoVentana(juego),SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        SDL_Event event;
        const unsigned char *keys;
        keys = SDL_GetKeyboardState(NULL);
        IMG_Init(IMG_INIT_PNG);
        SDL_RenderClear(renderer);

        CASILLERO casillero;
        initCasilleros(renderer,casillero,juego); //renderizamos el fondo

        COMANDA comanda;
        MONEDA moneda;
        ListaMoneda listamonedas;
        crearListaMoneda(listamonedas);
        Lista listaMapa;
        crearLista(listaMapa);
        Dato dato;
        TREN tren;
        MINA mina;
        ListaMina listaminas;
        crearListaMina(listaminas);
        ESTACION estacion;
        ListaVagon listavagones;
        VAGON vagon;
        crearListaVagon(listavagones);
        BANDIDO bandido;
        ListaBandido listabandidos;
        crearListaBandido(listabandidos);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        //SETEO DE PARAMETROS
        std::ifstream file("parametros.txt");
        std::string line;
        while (std::getline(file, line))
        {
            std::string key = line.substr(0,line.find(":"));
            std::string value = line.substr((line.find(":")+1));
            value = value.substr(0,value.find(";"));
            //cout << key << " el valor del parametro: " << value<<endl;
            //seteo intervalo del juego
            if (key == "S"){
                setJuegoIntervalo(juego, atoi(value.c_str()));
            }
            //seteo intevalo generacio nmoneda
            if (key == "IM"){
                setJuegoIntervaloMoneda(juego, atoi(value.c_str()));
            }
            //seteo intevalo generacio nmoneda
            if (key == "VM"){
                setintervaloDesaparicionMoneda(juego, atoi(value.c_str()));
            }
            //seteo pos X de la estacion
            if (key == "posXE"){
                setEstacionPosX(estacion, atoi(value.c_str()));
            }
            //seteo pos Y de la estacion
            if (key == "posYE"){
                setEstacionPosY(estacion, atoi(value.c_str()));
            }
            if (key == "posYE"){
                setEstacionPosY(estacion, atoi(value.c_str()));
            }
        }
//SETEO DE MINAS
        std::ifstream file2("mina.txt");
        std::string line2;
        while (std::getline(file2, line2))
        {
            std::string key = line2.substr(0,line2.find(":"));
            std::string value = line2.substr((line2.find(":")+1));
            //cout << key << " el valor del parametro: " << value<<endl;
            //seteo intervalo del juego
            if (key == "oro"){
                crearMina(mina);
                mina.id_mina = atoi(value.c_str());
                setMinaTipo(mina,mina.id_mina);
            }
            if (key == "oroposX")
            {
                setMinaPosX(mina,atoi(value.c_str()));
            }
            if (key == "oroposY")
            {
                setMinaPosY(mina,atoi(value.c_str()));
            }
            if (key == "oroIP"){
                setMinaIntervaloProduccion(mina, atoi(value.c_str()));
            }
            if (key == "oroSEC1"){
                setMinaSecuenciaProduccion1(mina, atoi(value.c_str()));
            }
            if (key == "oroSEC2"){
                setMinaSecuenciaProduccion2(mina, atoi(value.c_str()));
            }
            if (key == "oroSEC3"){
                setMinaSecuenciaProduccion3(mina, atoi(value.c_str()));
            }
            if (key == "oroSEC4"){
                setMinaSecuenciaProduccion4(mina, atoi(value.c_str()));
            }
            if (key == "oroSEC5"){
                setMinaSecuenciaProduccion5(mina, atoi(value.c_str()));
            }
            if (key == "orofin")
            {
                insertarMina(listaminas,mina);
            }
            if (key == "plata"){
                crearMina(mina);
                mina.id_mina = atoi(value.c_str());
                setMinaTipo(mina,mina.id_mina);
            }
            if (key == "plataposX")
            {
                setMinaPosX(mina,atoi(value.c_str()));
            }
            if (key == "plataposY")
            {
                setMinaPosY(mina,atoi(value.c_str()));
            }
            if (key == "plataIP"){
                setMinaIntervaloProduccion(mina, atoi(value.c_str()));
            }
            if (key == "plataSEC1"){
                setMinaSecuenciaProduccion1(mina, atoi(value.c_str()));
            }
            if (key == "plataSEC2"){
                setMinaSecuenciaProduccion2(mina, atoi(value.c_str()));
            }
            if (key == "plataSEC3"){
                setMinaSecuenciaProduccion3(mina, atoi(value.c_str()));
            }
            if (key == "plataSEC4"){
                setMinaSecuenciaProduccion4(mina, atoi(value.c_str()));
            }
            if (key == "plataSEC5"){
                setMinaSecuenciaProduccion5(mina, atoi(value.c_str()));
            }
            if (key == "platafin")
            {
                insertarMina(listaminas,mina);
            }
            if (key == "bronce"){
                crearMina(mina);
                mina.id_mina = atoi(value.c_str());
                setMinaTipo(mina,mina.id_mina);
            }
            if (key == "bronceposX")
            {
                setMinaPosX(mina,atoi(value.c_str()));
            }
            if (key == "bronceposY")
            {
                setMinaPosY(mina,atoi(value.c_str()));
            }
            if (key == "bronceIP"){
                setMinaIntervaloProduccion(mina, atoi(value.c_str()));
            }
            if (key == "bronceSEC1"){
                setMinaSecuenciaProduccion1(mina, atoi(value.c_str()));
            }
            if (key == "bronceSEC2"){
                setMinaSecuenciaProduccion2(mina, atoi(value.c_str()));
            }
            if (key == "bronceSEC3"){
                setMinaSecuenciaProduccion3(mina, atoi(value.c_str()));
            }
            if (key == "bronceSEC4"){
                setMinaSecuenciaProduccion4(mina, atoi(value.c_str()));
            }
            if (key == "bronceSEC5"){
                setMinaSecuenciaProduccion5(mina, atoi(value.c_str()));
            }
            if (key == "broncefin")
            {
                insertarMina(listaminas,mina);
            }
            if (key == "platino"){
                crearMina(mina);
                mina.id_mina = atoi(value.c_str());
                setMinaTipo(mina,mina.id_mina);
            }
            if (key == "platinoposX")
            {
                setMinaPosX(mina,atoi(value.c_str()));
            }
            if (key == "platinoposY")
            {
                setMinaPosY(mina,atoi(value.c_str()));
            }
            if (key == "platinoIP"){
                setMinaIntervaloProduccion(mina, atoi(value.c_str()));
            }
            if (key == "platinoSEC1"){
                setMinaSecuenciaProduccion1(mina, atoi(value.c_str()));
            }
            if (key == "platinoSEC2"){
                setMinaSecuenciaProduccion2(mina, atoi(value.c_str()));
            }
            if (key == "platinoSEC3"){
                setMinaSecuenciaProduccion3(mina, atoi(value.c_str()));
            }
            if (key == "platinoSEC4"){
                setMinaSecuenciaProduccion4(mina, atoi(value.c_str()));
            }
            if (key == "platinoSEC5"){
                setMinaSecuenciaProduccion5(mina, atoi(value.c_str()));
            }
            if (key == "platinofin")
            {
                insertarMina(listaminas,mina);
            }
            if (key == "roca"){
                crearMina(mina);
                mina.id_mina = atoi(value.c_str());
                setMinaTipo(mina,mina.id_mina);
            }
            if (key == "rocaposX")
            {
                setMinaPosX(mina,atoi(value.c_str()));
            }
            if (key == "rocaposY")
            {
                setMinaPosY(mina,atoi(value.c_str()));
            }
            if (key == "rocaIP"){
                setMinaIntervaloProduccion(mina, atoi(value.c_str()));
            }
            if (key == "rocaSEC1"){
                setMinaSecuenciaProduccion1(mina, atoi(value.c_str()));
            }
            if (key == "rocaSEC2"){
                setMinaSecuenciaProduccion2(mina, atoi(value.c_str()));
            }
            if (key == "rocaSEC3"){
                setMinaSecuenciaProduccion3(mina, atoi(value.c_str()));
            }
            if (key == "rocaSEC4"){
                setMinaSecuenciaProduccion4(mina, atoi(value.c_str()));
            }
            if (key == "rocaSEC5"){
                setMinaSecuenciaProduccion5(mina, atoi(value.c_str()));
            }
            if (key == "rocafin")
            {
                insertarMina(listaminas,mina);
            }
            if (key == "carbon"){
                crearMina(mina);
                mina.id_mina = atoi(value.c_str());
                setMinaTipo(mina,mina.id_mina);
            }
            if (key == "carbonposX")
            {
                setMinaPosX(mina,atoi(value.c_str()));
            }
            if (key == "carbonposY")
            {
                setMinaPosY(mina,atoi(value.c_str()));
            }
            if (key == "carbonIP"){
                setMinaIntervaloProduccion(mina, atoi(value.c_str()));
            }
            if (key == "carbonSEC1"){
                setMinaSecuenciaProduccion1(mina, atoi(value.c_str()));
            }
            if (key == "carbonSEC2"){
                setMinaSecuenciaProduccion2(mina, atoi(value.c_str()));
            }
            if (key == "carbonSEC3"){
                setMinaSecuenciaProduccion3(mina, atoi(value.c_str()));
            }
            if (key == "carbonSEC4"){
                setMinaSecuenciaProduccion4(mina, atoi(value.c_str()));
            }
            if (key == "carbonSEC5"){
                setMinaSecuenciaProduccion5(mina, atoi(value.c_str()));
            }
            if (key == "carbonfin")
            {
                insertarMina(listaminas,mina);
            }
        }
        //SETEO COMANDA
        std::ifstream file3("comanda.txt");
        std::string line3;
        while (std::getline(file3, line3))
        {
            std::string key = line3.substr(0,line3.find(":"));
            std::string value = line3.substr((line3.find(":")+1));
            value = value.substr(0,value.find(";"));
            //cout << key << " el valor del parametro: " << value<<endl;
            //seteo intervalo del juego
            if (key == "oro"){
                setComandaOro(comanda, atoi(value.c_str()));
            }
            //seteo intevalo generacio nmoneda
            if (key == "plata"){
                setComandaPlata(comanda, atoi(value.c_str()));
            }
            //seteo intevalo generacio nmoneda
            if (key == "bronce"){
                setComandaBronce(comanda, atoi(value.c_str()));
            }
            //seteo pos X de la estacion
            if (key == "platino"){
                setComandaPlatino(comanda, atoi(value.c_str()));
            }
            //seteo pos Y de la estacion
            if (key == "roca"){
                setComandaRoca(comanda, atoi(value.c_str()));
            }
            if (key == "carbon"){
                setComandaCarbon(comanda, atoi(value.c_str()));
            }
        }
        //recorrerListaMina(renderer,listaminas);
    //GAME LOOP
    int counter = 1;

    //generamos las minas al inicio, luego no cambian de posicion

    while(getJuegoGameisnotOver(juego))
    {
        evaluarEventosTeclado(juego,tren,vagon,listavagones,event,keys);
        if (getJuegoNoEstaPausado(juego)){
             //cout << counter << endl;
            evaluarCambioDireccion(juego,tren);

            if((counter % getJuegoIntervaloMoneda(juego)) == 0)
            {
                generarMoneda(listamonedas,moneda,counter,getintervaloDesaparicionMoneda(juego));
                generarBandido(listabandidos, bandido, counter, getintervaloDesaparicionMoneda(juego));
            }

            //disminuimos la velocidad de render por intervalo
            if (counter % getJuegoIntervalo(juego) == 0){
                SDL_RenderClear(renderer);
                initCasilleros(renderer,casillero,juego);
                generacionMina(listaminas,counter);
                recorrerListaMina(renderer,listaminas);
                initTren(renderer,tren,listavagones);

                initEstacion(renderer,estacion);
                evaluarMonedas(listamonedas,counter);
                recorrerListaMonedas(renderer,listamonedas);
                evaluarBandidos(listabandidos,counter);
                recorrerListaBandidos(renderer,listabandidos);
                //borramos los nodos listaMapa
                vaciarListaMapa(listaMapa);
                crearLista(listaMapa);
                //insertarmos todas las posiciones en listaMapa
                agregarTrenListaMapa(listaMapa,tren);
                agregarEstacionListaMapa(listaMapa,estacion);
                agregarVagonesListaMapa(listaMapa,listavagones);
                agregarMonedaListaMapa(listaMapa,listamonedas);
                agregarBandidoListaMapa(listaMapa,listabandidos);
                agregarMinaListaMapa(listaMapa,listaminas);
                //evaluamos colisiones
                recorrerListaMapa(renderer,listaMapa,counter,juego,tren,moneda,listamonedas,listavagones,listaminas,listabandidos);
                compararComandaVagones(comanda,listavagones,juego);

                SDL_RenderPresent(renderer);
                SDL_Delay(50);
            }
            evaluarSalidadePista(juego,tren);
            counter++;
        }//IF PAUSA
    }//while del juego

    cout<<"Destruimos renderer"<<endl;
    SDL_DestroyRenderer(renderer);
    cout<<"Destruimos window"<<endl;
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    }
    return 0;
}

void evaluarEventosTeclado(JUEGO &juego,TREN &tren,VAGON &vagon,ListaVagon &listavagones, SDL_Event &event,const unsigned char *keys){
    if(SDL_PollEvent(&event)){//indica que hay eventos pendientes
        switch(event.type){
            case SDL_QUIT:
                setJuegoGameisnotOver(juego, false);
            break;
            case SDL_KEYDOWN:
                if(keys[SDL_SCANCODE_ESCAPE]){
                    setJuegoGameisnotOver(juego, false);
                }
                if(keys[SDL_SCANCODE_LEFT]){
                    setJuegoDireccionSiguiente(juego,3);
                }
                if(keys[SDL_SCANCODE_RIGHT]){
                    setJuegoDireccionSiguiente(juego,1);
                }
                if(keys[SDL_SCANCODE_UP]){
                    setJuegoDireccionSiguiente(juego,0);
                }
                if(keys[SDL_SCANCODE_DOWN]){
                    setJuegoDireccionSiguiente(juego,2);
                }
                if(keys[SDL_SCANCODE_SPACE]){
                        if (getJuegoNoEstaPausado(juego) == true){
                            setJuegonoEstaPausado(juego,false);
                        } else {
                            setJuegonoEstaPausado(juego,true);
                     }
                }
                if(keys[SDL_SCANCODE_RETURN]){
                    crearVagon(vagon);
                    if (longitudVagon(listavagones)==0)
                    {
                        vagon.id_vagon = 0;
                    } else {
                        VAGON vagonUltimo;
                        PtrNodoListaVagon cursorVagon = ultimoVagon(listavagones);
                        obtenerVagon(listavagones,vagonUltimo,cursorVagon);
                        vagon.id_vagon = vagonUltimo.id_vagon + 1;
                    }

                    insertarVagon(listavagones,vagon);
                }

                break;
        }
    }
}

void evaluarCambioDireccion(JUEGO &juego,TREN &tren){
    int dprevia = getJuegoDireccionPrevia(juego);
    int dsiguiente = getJuegoDireccionSiguiente(juego);
    if (dprevia == 0 && dsiguiente == 1)
    {
        setTrenTipoDireccion(tren,1);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }
    if (dprevia == 0 && dsiguiente == 3)
    {
        setTrenTipoDireccion(tren,0);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }

    if (dprevia == 1 && dsiguiente == 0)
    {
        setTrenTipoDireccion(tren,0);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }
    if (dprevia == 1 && dsiguiente == 2)
    {
        setTrenTipoDireccion(tren,1);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }

    if (dprevia == 2 && dsiguiente == 3)
    {
        setTrenTipoDireccion(tren,0);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }
    if (dprevia == 2 && dsiguiente == 1)
    {
        setTrenTipoDireccion(tren,1);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }

    if (dprevia == 3 && dsiguiente == 0)
    {
        setTrenTipoDireccion(tren,0);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }
    if (dprevia == 3 && dsiguiente == 2)
    {
        setTrenTipoDireccion(tren,1);
        setTrenDireccion(tren,dsiguiente);
        setJuegoDireccionPrevia(juego,dsiguiente);
    }

}
void evaluarSalidadePista(JUEGO &juego,TREN &tren){
    int anchoVentana = getJuegoAnchoVentana(juego);
    int altoVentana = getJuegoAltoVentana(juego);
    int trenPosX = getTrenPosX(tren);
    int trenPosY = getTrenPosY(tren);

    if (trenPosX > anchoVentana || trenPosX < 0){
        setJuegoGameisnotOver(juego,false);
    }
    if (trenPosY > altoVentana || trenPosY < 0){
        setJuegoGameisnotOver(juego,false);
    }
}

void agregarMonedaListaMapa(Lista &listaMapa,ListaMoneda &listamonedas)
{
    Dato dato;
    crearDato(dato);
    PtrNodoListaMoneda ptrCursor = primeroMoneda(listamonedas);
    MONEDA moneda;
    while ( ptrCursor != finMoneda() ) {
        obtenerMoneda(listamonedas,moneda,ptrCursor);
        dato.posX = getMonedaPosX(moneda);
        dato.posY = getMonedaPosY(moneda);
        dato.id_mapa = getMonedaId(moneda);
        dato.tipo_elemento = 2;
        insertarDato(listaMapa,dato);
        ptrCursor = siguienteMoneda(listamonedas, ptrCursor);
    }
}

void agregarBandidoListaMapa(Lista &listaMapa,ListaBandido &listabandidos)
{
    Dato dato;
    crearDato(dato);
    PtrNodoListaBandido ptrCursor = primeroBandido(listabandidos);
    BANDIDO bandido;
    while ( ptrCursor != finBandido() ) {
        obtenerBANDIDO(listabandidos,bandido,ptrCursor);
        dato.posX = getBandidoPosX(bandido);
        dato.posY = getBandidoPosY(bandido);
        dato.id_mapa = getBandidoIdBandido(bandido);
        dato.tipo_elemento = 6;
        insertarDato(listaMapa,dato);
        ptrCursor = siguienteBandido(listabandidos, ptrCursor);
    }
}

void agregarMinaListaMapa(Lista &listaMapa,ListaMina &listaminas){
    Dato dato;
    crearDato(dato);
    MINA mina;
    PtrNodoListaMina cursor = primeroMina(listaminas);
    while(cursor != finMina())
    {
        obtenerMina(listaminas,mina,cursor);
        dato.posX = getMinaPosX(mina);
        dato.posY = getMinaPosY(mina);
        dato.id_mapa = getMinaIdMina(mina);
        dato.tipo_elemento = 4;
        insertarDato(listaMapa,dato);
        cursor = siguienteMina(listaminas,cursor);
    }
}

void agregarTrenListaMapa(Lista &listaMapa,TREN &tren){
    Dato dato;
    crearDato(dato);
    dato.posX = getTrenPosX(tren);
    dato.posY = getTrenPosY(tren);
    dato.id_mapa = 0;
    dato.tipo_elemento = 1;
    insertarDato(listaMapa,dato);
}

void agregarVagonesListaMapa(Lista &listaMapa,ListaVagon &lista)
{
    Dato dato;
    crearDato(dato);
    VAGON vagon;
    PtrNodoListaVagon cursorVagon = primeroVagon(lista);
    while (cursorVagon != finVagon()) {
        obtenerVagon(lista,vagon,cursorVagon);
        dato.posX = getVagonPosX(vagon);
        dato.posY = getVagonPosY(vagon);
        dato.id_mapa = getVagonId(vagon);
        dato.tipo_elemento = 5;
        insertarDato(listaMapa,dato);
        cursorVagon = siguienteVagon(lista, cursorVagon);
    }
}

void agregarEstacionListaMapa(Lista &listaMapa,ESTACION &estacion)
{
    Dato dato;
    crearDato(dato);
    dato.posX = getEstacionPosX(estacion);
    dato.posY = getEstacionPosY(estacion);
    dato.id_mapa = 0;
    dato.tipo_elemento = 3;
    insertarDato(listaMapa,dato);
}

void recorrerListaMapa(SDL_Renderer* renderer,Lista &listaMapa,int intervalo,JUEGO &juego,TREN &tren,MONEDA &moneda,ListaMoneda &listamonedas,ListaVagon &listavagones,ListaMina &listaminas,ListaBandido &listabandidos)
{
    PtrNodoListaMapa cursor,cursorAuxiliar;
    cursor = primero(listaMapa);
    Dato datotren,datoAuxiliar;

    while (cursor != finMapa()) {
        obtenerDato(listaMapa, datotren, cursor);
            if (datotren.tipo_elemento == 1)
            {
                //evaluo el tren contra el resto
                cursorAuxiliar = primero(listaMapa);
                 while (cursorAuxiliar != finMapa()) {
                     obtenerDato(listaMapa, datoAuxiliar, cursorAuxiliar);
                    if (datoAuxiliar.posX == datotren.posX && datoAuxiliar.posY == datotren.posY)
                    {
                        if (datoAuxiliar.tipo_elemento == 2){
                         colisionTrenMoneda(tren,moneda,datoAuxiliar,listamonedas);
                         //setJuegonoEstaPausado(juego,false);
                        }
                        if (datoAuxiliar.tipo_elemento == 3){
                         colisionTrenEstacion(tren,listavagones);
                         //setJuegonoEstaPausado(juego,false);
                        }
                        if (datoAuxiliar.tipo_elemento == 4){
                         colisionTrenMina(listaminas,listavagones,datoAuxiliar);
                         //setJuegonoEstaPausado(juego,false);
                        }
                        if (datoAuxiliar.tipo_elemento == 6){
                         colisionTrenVagonBandido(tren,datoAuxiliar,listabandidos,listavagones,juego);
                         //setJuegonoEstaPausado(juego,false);
                        }
                    }
                    cursorAuxiliar = siguiente(listaMapa, cursorAuxiliar);
                 }

            }//fin colisiones tren
            //colisiones vagon
            if(datotren.tipo_elemento == 5)
            {
                cursorAuxiliar = primero(listaMapa);
                 while (cursorAuxiliar != finMapa()) {
                     obtenerDato(listaMapa, datoAuxiliar, cursorAuxiliar);
                    if (datoAuxiliar.posX == datotren.posX && datoAuxiliar.posY == datotren.posY)
                    {
                        if (datoAuxiliar.tipo_elemento == 6){
                         colisionTrenVagonBandido(tren,datoAuxiliar,listabandidos,listavagones,juego);
                         //setJuegonoEstaPausado(juego,false);
                        }
                    }
                    cursorAuxiliar = siguiente(listaMapa, cursorAuxiliar);
                 }
            }

        //imprimirMapa(dato);
        cursor = siguiente(listaMapa, cursor);
    }
}

void compararComandaVagones(COMANDA &comanda, ListaVagon &lista, JUEGO &juego)
{
    int tipo, cantidad, flag;
    VAGON vagon;
    PtrNodoListaVagon cursorVagon = primeroVagon(lista);
    while (cursorVagon != finVagon()) {
        obtenerVagon(lista,vagon,cursorVagon);
        tipo = getVagonTipoCarga(vagon);
        cantidad = getVagonCarga(vagon);
        if(tipo == 1)
        {
            if(cantidad >= comanda.oro)
            {
                flag++;
            }
        }
        if(tipo == 2)
        {
            if(cantidad >= comanda.plata)
            {
                flag++;
            }
        }
        if(tipo == 3)
        {
            if(cantidad >= comanda.bronce)
            {
            flag++;
            }
        }
        if(tipo == 4)
        {
            if(cantidad >= comanda.platino)
            {
                flag++;
            }
        }
        if(tipo == 5)
        {
            if(cantidad >= comanda.roca)
            {
                flag++;
            }
        }
        if(tipo == 6)
        {
            if(cantidad >= comanda.carbon)
            {
                flag++;
            }
        }
        if(flag == 6)
        {
            cout <<"****ENHORABUENA HAS GANADO EL JUEGO****"<<endl;
            setJuegoGameisnotOver(juego,false);
        }
        cursorVagon = siguienteVagon(lista, cursorVagon);
    }
}

void colisionTrenMoneda(TREN &tren,MONEDA &moneda, Dato &datomoneda,ListaMoneda &listamonedas)
{
    setTrenMonedas(tren,(getTrenMonedas(tren)+1));
    imprimirTren(tren);
    //chequeo por las dudas que sea moneda
    if (datomoneda.tipo_elemento == 2)
    {
        eliminarMonedaPorId(listamonedas,getMapaId(datomoneda));
    }
}

void colisionTrenEstacion(TREN &tren,ListaVagon &listavagones)
{
    int monedas = getTrenMonedas(tren);
    if (monedas > 0)
    {
        VAGON vagon;
        crearVagon(vagon);
        /**
            TIPOS DE VAGON POR CANTIDAD DE MONEDAS
            1m = carbon TIPO 6
            2m = roca TIPO 5
            4m = bronce TIPO 3
            6m = platino TIPO 4
            8m = plata TIPO 2
            +10m = oro TIPO 1
        */
        if (monedas == 1)
        {
            vagon.tipo_carga = 6;
        }
        if (monedas == 2)
        {
            vagon.tipo_carga = 5;
        }
        if (monedas == 4)
        {
            vagon.tipo_carga = 3;
        }
        if (monedas == 6)
        {
            vagon.tipo_carga = 4;
        }
        if (monedas == 8)
        {
            vagon.tipo_carga = 2;
        }
        if (monedas >= 10)
        {
            vagon.tipo_carga = 1;
        }

        if (longitudVagon(listavagones)==0)
        {
            vagon.id_vagon = 0;
        } else {
            VAGON vagonUltimo;
            PtrNodoListaVagon cursorVagon = ultimoVagon(listavagones);
            obtenerVagon(listavagones,vagonUltimo,cursorVagon);
            vagon.id_vagon = vagonUltimo.id_vagon + 1;
        }
        insertarVagon(listavagones,vagon);
        setTrenMonedas(tren,0);
    } else {
        cout <<"DEBE CONSEGUIR MONEDAS PARA OBTENER VAGONES"<<endl;
    }
}

void colisionTrenMina(ListaMina &listaminas,ListaVagon &listavagones,Dato &datomina)
{
    int posX;
    int posY;
    int tipo;
    int intervalo_produccion;
    int secuencia_produccion1;
    int secuencia_produccion2;
    int secuencia_produccion3;
    int secuencia_produccion4;
    int secuencia_produccion5;
    int flag_sec1;
    int flag_sec2;
    int flag_sec3;
    int flag_sec4;
    int id_vagon2;
    int posX2;
    int posY2;
    int direccion2;
    int posX_anterior2;
    int posY_anterior2;
    int tipo_direccion2;
    int imgW2;
    int imgH2;
    int carga2;
    int tipo_carga2;
    int id_mina = getMapaId(datomina);
    int tipo_vagon,material_generado;
    MINA mina;
    //buscamos el tipo de la mina colisionada
    PtrNodoListaMina cursor = primeroMina(listaminas);
    while(cursor != finMina())
    {
        obtenerMina(listaminas,mina,cursor);
        if (id_mina == mina.id_mina)
        {
            tipo_vagon = getMinaTipo(mina);
            material_generado = getMinaMaterialGenerado(mina);
        }
        cursor = siguienteMina(listaminas,cursor);
    }
    if (material_generado > 0)
    {
    //ahora buscamos si hay vagones de este tipo
    //en caso de haber, le pasamos el material generado al vagon y seteamos la mina en cero
    PtrNodoListaVagon cursor = primeroVagon(listavagones);
    VAGON vagon;
            while (cursor != finVagon()) {
            obtenerVagon(listavagones, vagon, cursor);
            if (vagon.tipo_carga == tipo_vagon)
            {
                cout <<"Esta Vagon Va a Cargar Material"<<endl;
                imprimirMina(mina);
                getVagonCarga(vagon);
                material_generado = getMinaMaterialGenerado(mina);
                cout<<vagon.carga<<""<<endl;
                int totalcarga = vagon.carga + material_generado;
                cout<<totalcarga<<""<<endl;
                setVagonCarga(vagon,totalcarga);
                setMinaMaterialGenerado(mina,0);
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
                eliminarMina(listaminas, mina);
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
                insertarMina(listaminas,mina);
                id_vagon2 = getVagonId(vagon);
                posX2= getVagonPosX(vagon);
                posX_anterior2= getVagonPosXAnterior(vagon);
                posY2= getVagonPosY(vagon);
                posY_anterior2= getVagonPosYAnterior(vagon);
                imgW2= getVagonImgW(vagon);
                imgH2= getVagonImgH(vagon);
                carga2= getVagonCarga(vagon);
                tipo_carga2= getVagonTipoCarga(vagon);
                direccion2= getVagonDireccion(vagon);
                tipo_direccion2= getVagonTipoDireccion(vagon);
                eliminarVagon(listavagones, vagon);
                crearVagon(vagon);
                setVagonId(vagon, id_vagon2);
                setVagonPosX(vagon, posX2);
                setVagonPosXAnterior(vagon, posX_anterior2);
                setVagonPosY(vagon, posY2);
                setVagonPosYAnterior(vagon, posY_anterior2);
                setVagonImgW(vagon, imgW2);
                setVagonImgH(vagon, imgH2);
                setVagonCarga(vagon, carga2);
                vagon.tipo_carga=tipo_carga2;
                setVagonDireccion(vagon, direccion2);
                setVagonTipoDireccion(vagon, tipo_direccion2);
                insertarVagon(listavagones, vagon);
                imprimirVagon(vagon);
                cout <<"Fin Colision TREN - MINA"<<endl;
                break;
            }
            cursor = siguienteVagon(listavagones, cursor);
        }
    }

}

void colisionTrenVagonBandido(TREN &tren,Dato &datobandido,ListaBandido &listabandidos,ListaVagon &listavagones,JUEGO &juego)
{
    int id_bandido = datobandido.id_mapa;
    //recorro la lista de bandidos para borrarlo
    PtrNodoListaBandido ptrCursor = primeroBandido(listabandidos);
    BANDIDO bandido;
    while ( ptrCursor != finBandido() ) {
        obtenerBANDIDO(listabandidos,bandido,ptrCursor);
        if (id_bandido == bandido.id_bandido)
        {
            eliminarBANDIDO(listabandidos,bandido);
        }
        ptrCursor = siguienteBandido( listabandidos, ptrCursor);
    }
    //ahora me fijo si el tren tiene vagones
    int cantidad_vagones = longitudVagon(listavagones);
    if (cantidad_vagones == 0)
    {
        cout <<"****HAS PERDIDO POR CULPA DEL BANDIDO****"<<endl;
        setJuegoGameisnotOver(juego,false);
    } else {
      PtrNodoListaVagon ptrNodo = ultimoVagon(listavagones);
        if (ptrNodo != finVagon())
        {
            eliminarNodoVagon(listavagones,ptrNodo);
        }
    }
}
