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
void evaluarEventosTeclado(JUEGO &juego,SDL_Event &event,const unsigned char *keys);
void evaluarCambioDireccion(JUEGO &juego,TREN &tren);
void evaluarSalidadePista(JUEGO &juego,TREN &tren);
PtrNodoLista agregarMonedaListaMapa(Lista &listaMapa,Dato &dato,MONEDA &moneda);
PtrNodoLista agregarMinaListaMapa(Lista &listaMapa,Dato &dato,MINA &mina);
PtrNodoLista agregarTrenListaMapa(Lista &listaMapa,Dato &dato,TREN &tren);

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
        initCasilleros(renderer,casillero); //renderizamos el fondo

        MONEDA moneda;
        initMoneda(moneda);
        Lista listaMapa;
        crearLista(listaMapa);
        Dato dato;
        TREN tren;
        MINA mina;
        ESTACION estacion;
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
            cout << key << " el valor del parametro: " << value<<endl;
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

    //GAME LOOP
    int counter = 1;

    //generamos las minas al inicio, luego no cambian de posicion
    //agregarMinaListaMapa(listaMapa,dato,mina);

    while(getJuegoGameisnotOver(juego))
    {
        evaluarEventosTeclado(juego,event,keys);
        if (getJuegoNoEstaPausado(juego)){
             //cout << counter << endl;
            evaluarCambioDireccion(juego,tren);

            if((counter % getJuegoIntervaloMoneda(juego)) == 0)
            {
                generarMoneda(moneda,counter,getintervaloDesaparicionMoneda(juego));
                agregarMonedaListaMapa(listaMapa,dato,moneda);
            }

            //disminuimos la velocidad de render por intervalo
            if (counter % getJuegoIntervalo(juego) == 0){
                SDL_RenderClear(renderer);
                initCasilleros(renderer,casillero);
                initTren(renderer,tren);
                agregarTrenListaMapa(listaMapa,dato,tren);
                initMinas(renderer,mina);
                initEstacion(renderer,estacion);
                recorrerListaMapa(renderer,listaMapa,counter);
                renderizarListaMapa(renderer,listaMapa);
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

void evaluarEventosTeclado(JUEGO &juego,SDL_Event &event,const unsigned char *keys){
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

PtrNodoLista agregarMonedaListaMapa(Lista &listaMapa,Dato &dato,MONEDA &moneda){
    dato.posX = getMonedaPosX(moneda);
    dato.posY = getMonedaPosY(moneda);
    dato.imgW = getMonedaImgW(moneda);
    dato.imgH = getMonedaImgH(moneda);
    dato.id_mapa = 1;
    dato.intervalo_desaparicion = getMonedaIntervaloDesaparicion(moneda);
    dato.tipo_elemento = 2;
    strcpy(dato.imagen,getMonedaImagen(moneda));
    adicionarPrincipio(listaMapa, dato);
}

PtrNodoLista agregarMinaListaMapa(Lista &listaMapa,Dato &dato,MINA &mina){
    int i;
    for (i=0;i<6; i++){
        crearMina(mina);
        dato.posX = getMinaPosX(mina);
        dato.posY = getMinaPosY(mina);
        dato.imgW = getMinaImgH(mina);
        dato.imgH = getMinaImgH(mina);
        dato.intervalo_desaparicion = 0;
        dato.id_mapa = 800+i;
        dato.tipo_elemento = 4;
        strcpy(dato.imagen,getMinaImg(mina));
        adicionarPrincipio(listaMapa, dato);
    }
}

PtrNodoLista agregarTrenListaMapa(Lista &listaMapa,Dato &dato,TREN &tren){
    dato.posX = getTrenPosX(tren);
    dato.posY = getTrenPosY(tren);
    dato.imgW = getTrenImgH(tren);
    dato.imgH = getTrenImgH(tren);
    dato.intervalo_desaparicion = 0;
    dato.id_mapa = 100;
    dato.tipo_elemento = 1;
    strcpy(dato.imagen,getTrenImagen(tren));
    adicionarPrincipio(listaMapa, dato);
}
