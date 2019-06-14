#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include "juego.h"
#include "moneda.h"
#include "casillero.h"
#include "tren.h"

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
        initMoneda(renderer,moneda);
        TREN tren;
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
            if (key == "S"){
                setJuegoIntervalo(juego, atoi(value.c_str()));
            }
            if (key == "IM"){
                setJuegoIntervaloMoneda(juego, atoi(value.c_str()));
            }
        }

        //GAME LOOP
        int counter = 1;
        while(getJuegoGameisnotOver(juego))
        {
             //cout << counter << endl;
            evaluarEventosTeclado(juego,event,keys);
            evaluarCambioDireccion(juego,tren);

            if((counter % getJuegoIntervaloMoneda(juego)) == 0)
            {
                generarMoneda(moneda);
                //cout << getMonedaPosX(moneda) << endl;
                //cout << getMonedaPosY(moneda) << endl;
            }

            //disminuimos la velocidad de render por intervalo
            if (counter % getJuegoIntervalo(juego) == 0){
                SDL_RenderClear(renderer);
                initCasilleros(renderer,casillero);
                initTren(renderer,tren);
                SDL_RenderPresent(renderer);
                SDL_Delay(30);
            }
            counter++;
            /*if (counter == 500)
            {
                break;
            }*/
        }//while del juego

        /*cout<<"Destruimos renderer"<<endl;
        SDL_DestroyRenderer(renderer);
        cout<<"Destruimos window"<<endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();*/
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
                    cout<<"izq"<<endl;
                }
                if(keys[SDL_SCANCODE_RIGHT]){
                    setJuegoDireccionSiguiente(juego,1);
                    cout<<"der"<<endl;
                }
                if(keys[SDL_SCANCODE_UP]){
                    setJuegoDireccionSiguiente(juego,0);
                    cout<<"arr"<<endl;
                }
                if(keys[SDL_SCANCODE_DOWN]){
                    setJuegoDireccionSiguiente(juego,2);
                    cout<<"abj"<<endl;
                }
                if(keys[SDL_SCANCODE_SPACE]){
                    //
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
