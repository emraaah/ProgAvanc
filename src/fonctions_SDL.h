#ifndef fonctions_SDL
#define fonctions_SDL

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "menu.h"


//Elle charge une image et retourner la surface de texture associée.
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer);

//Elle charge l'image avec la transparence
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) ;

//Elle charge le texte
SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,
                           TTF_Font *font, SDL_Color color) ;

#endif