#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <fstream>
#include "juego.h"
#include "moneda.h"
#include "casillero.h"

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

        IMG_Init(IMG_INIT_PNG);
        SDL_RenderClear(renderer);
        CASILLERO casillero;
        initCasilleros(renderer,casillero); //renderizamos el fondo

        MONEDA moneda;
        initMoneda(renderer,moneda);

        SDL_RenderPresent(renderer);
        SDL_Delay(500);
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
            if((counter % getJuegoIntervaloMoneda(juego)) == 0)
            {
                generarMoneda(moneda);
                cout << getMonedaPosX(moneda) << endl;
                cout << getMonedaPosY(moneda) << endl;
            }

            cout<<"jugando"<<endl;
            //SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(30);
            counter++;
            if (counter == 100)
            {
                break;
            }
        }
    }
    return 0;
}
