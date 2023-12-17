#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "fonctions_SDL.h"

extern SDL_Renderer *renderer;  // Déclaration du renderer

// Structure pour représenter un bouton
typedef struct {
    SDL_Rect rect;
    SDL_Texture *texture;
} Button;

// Déclaration des boutons
extern Button jouerButton;
extern Button quitterButton;
extern SDL_Texture* fond;

// Fonction pour charger les textures du menu
int loadMenu();
// Fonction pour libérer les textures du menu
void closeMenu();
// Fonction pour afficher le menu
void renderMenu();

#endif // MENU_H