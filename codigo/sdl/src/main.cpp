#include <iostream>

#include <SDL/SDL.h>

#include "sdl.h"
#include "dibujar.h"
#include "eventos.h"

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO)< 0) {
		std::cerr << "Error al inicializar la librería SDL" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
	}

	SDL_Surface *pantalla = iniciarVideo(800, 600, 16);

	SDL_WM_SetCaption("TestSDL", 0);

	if (SDL_MUSTLOCK(pantalla)) {
		if (SDL_LockSurface(pantalla) < 0) {
			std::cerr << "Error bloqueando la pantalla" << std::endl;
			std::cerr << SDL_GetError() << std::endl;
			SDL_Quit();
			exit(-1);
		}
	}

	Dibujar(pantalla);

	if (SDL_MUSTLOCK(pantalla)) {
		SDL_UnlockSurface(pantalla);
	}

	DrawImage(pantalla, "icon.png", 400, 400);	
	SDL_UpdateRect(pantalla, 0, 0, 0, 0); // Toda la pantalla. Sino posX, posY, ancho, alto

	ProcesaEventos(pantalla);

	SDL_Quit();
	return 0;
}

