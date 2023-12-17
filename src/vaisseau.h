#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "fonctions_fichiers.h"
#include "fonctions_SDL.h"
#include "constants.h"

//Structure pour representer le vaisseau
struct vaisseau_s{
	int x;
	int y;
	SDL_Texture* sprite;
	SDL_Rect vaisseau_pavage[16];
	SDL_Rect SrcR_sprite;

};
typedef struct vaisseau_s vaisseau_t;

//Initialisation du vaisseau
void init_vaisseau(SDL_Renderer* ecran, vaisseau_t *vaisseau);

#endif // VAISSEAU_H