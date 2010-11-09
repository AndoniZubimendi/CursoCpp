#ifndef __SDL_H__
#define __SDL_H__

#include <SDL/SDL.h>

SDL_Surface *iniciarVideo(int ancho, int largo, int bpp);

void PutPixel(SDL_Surface *pantalla, int x, int y,
	unsigned char r, unsigned char g, unsigned char b);

void GetPixel(SDL_Surface *pantalla, int x, int y,
		unsigned char &r, unsigned char &g, unsigned char &b);

int DrawImage(SDL_Surface *pantalla, const char *imagen, int x_ps, int y_pos);
#endif
