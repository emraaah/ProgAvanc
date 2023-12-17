#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include "menu.h"
#include "vaisseau.h"
#include "fonctions_SDL.h"
#include "constants.h"
#include "fonctions_fichiers.h"

// Initialisation du jeu
void jeu(SDL_Window *window, SDL_Renderer *renderer);