#include <time.h>
#include <stdlib.h>

#include "dibujar.h"

#include "sdl.h"

void Dibujar(SDL_Surface *pantalla)
{
	for (int f=0; f < 256; f++) {
		PutPixel(pantalla, 256-f, f, 255,255, 0);
	}

	srand(time(0));
	for (int f=0; f < 256; f++)
		for (int c = 256; c < 512; c++)
			PutPixel(pantalla, c, f, rand() % 256, rand() % 256, rand() % 256);

	for (int f=256; f < 512; f++)
		for (int c = 0; c < 256; c++) {
		PutPixel(pantalla, c, f, 255, f-256, c);
	}

	for (int f=256; f < 512; f++)
		for (int c = 256; c < 512; c++)
			PutPixel(pantalla, c, f, f - 256, c - 256, 255);
}


