#include <SDL/SDL.h>
#include <iostream>

#include "eventos.h"
#include "sdl.h"


void ProcesaEventos(SDL_Surface *pantalla)
{
	SDL_Event evento;

	bool fin = false;
	
	while (!fin) {
		while (SDL_PollEvent(&evento)) {
			switch (evento.type) {
				case SDL_MOUSEMOTION: {
						int x, y;
						unsigned char r,g,b;

						x = evento.motion.x;
						y = evento.motion.y;

						if (SDL_MUSTLOCK(pantalla)) {
							if (SDL_LockSurface(pantalla) < 0) {
								std::cerr << "Error bloqueando la pantalla" << std::endl;
								std::cerr << SDL_GetError() << std::endl;
								SDL_Quit();
								exit(-1);
							}
						}
						GetPixel(pantalla, x, y, r, g, b);

						std::cout << "(" << x << ", " << y << ") = RGB(" <<
							static_cast<int>(r) << ", " << 
							static_cast<int>(g) << ", " << 
							static_cast<int>(b) << ")" << std::endl;
						if (SDL_MUSTLOCK(pantalla)) {
							SDL_UnlockSurface(pantalla);
						}
					}
					break;

				case SDL_KEYDOWN:
					if (evento.key.keysym.sym == SDLK_ESCAPE) {
						std::cout << "ESC detectado. Saliendo..." << std::endl;
						fin = true;
					}
					break;
				case SDL_QUIT:
					std::cout << "Ventana cerrada. Hasta la vista!" << std::endl;
					fin = true;
					break;
			}
		}
	}
}

