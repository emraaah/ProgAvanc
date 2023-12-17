#include "fonctions_SDL.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer){
	return SDL_CreateTextureFromSurface(renderer,SDL_LoadBMP(nomfichier)) ;
}
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b){
    SDL_Surface* surface = SDL_LoadBMP(nomfichier);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b) ) ;
    return SDL_CreateTextureFromSurface(renderer,surface);

}

SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,
                           TTF_Font *font, SDL_Color color){
    SDL_Surface *t= TTF_RenderText_Solid(font, message, color) ;
    return  SDL_CreateTextureFromSurface(renderer,t);
}