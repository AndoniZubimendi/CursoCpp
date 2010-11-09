#include "sdl.h"

#include <SDL/SDL_image.h>

#include <iostream>

void PutPixel(SDL_Surface *pantalla, int x, int y,
	unsigned char r, unsigned char g, unsigned char b)
{
	int bpp = pantalla->format->BytesPerPixel;

	Uint8 *p = (Uint8 *)pantalla->pixels + y*pantalla->pitch + x*bpp;

	Uint32 color = SDL_MapRGB(pantalla->format, r, g, b);

	switch (bpp) {
		case 1:
			*p = color;
			break;
		case 2:
			*(Uint16*)p = color;
			break;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (color>>16) & 0xff;
				p[1] = (color>>8) & 0xff;
				p[2] = color & 0xff;
			} else {
				p[0] = color & 0xff;
				p[1] = (color>>8) & 0xff;
				p[2] = (color>>16) & 0xff;
			}
			break;
		case 4:
			*(Uint32 *) p = color;
			break;
	}
}

void GetPixel(SDL_Surface *pantalla, int x, int y,
		unsigned char &r, unsigned char &g, unsigned char &b)
{
	int bpp = pantalla->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)pantalla->pixels + y*pantalla->pitch + x*bpp;
	Uint32 color = 0;

	switch(bpp) {
		case 1:
			color = *p;
			break;
		case 2:
			color = *(Uint16 *)p;
			break;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				color = p[0] << 16 | p[1] << 8 | p[2];
			} else {
				color = p[2] << 16 | p[1] << 8 | p[0];
			}
			break;
		case 4:
			color = *(Uint32*) p;
			break;
	}

	SDL_GetRGB(color, pantalla->format, &r, &g, &b);

}

SDL_Surface *iniciarVideo(int ancho, int largo, int bpp)
{
	SDL_Surface *video = SDL_SetVideoMode(ancho, largo, bpp, SDL_SWSURFACE | SDL_ANYFORMAT);

	if (video == NULL) {
		std::cerr << "Error al crear ventana" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
	}
	return video;
}

int DrawImage(SDL_Surface *pantalla, const char *archivo_imagen, int x_pos, int y_pos)
{
   SDL_Surface *imagen = IMG_Load ( archivo_imagen );
   if ( !imagen ) {
      std::cerr << "IMG_Load: " << IMG_GetError () << std::endl;
      return 1;
   }

   // Draws the image on the screen:
   SDL_Rect rcDest = { x_pos, y_pos, 0, 0 };
   SDL_BlitSurface ( imagen, NULL, pantalla, &rcDest );

   SDL_UpdateRect(pantalla, x_pos, y_pos, imagen->w, imagen->h);
   
   SDL_FreeSurface ( imagen );
   return 0;
}

