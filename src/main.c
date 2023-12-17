#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "menu.h"
#include "jeu.h"
#include "fonctions_SDL.h"
#include "constants.h"
#include "fonctions_fichiers.h"
#include "vaisseau.h"

SDL_Window *window = NULL; //Déclaration de la fenêtre
SDL_Renderer *renderer = NULL; //Rendu de l'écran

// Fonction pour initialiser SDL
int initSDL() {
    //Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur d’initialisation de la SDL: %s\n", SDL_GetError());
        return 0;
    }

    //Créer la fenêtre
    window = SDL_CreateWindow("Space War", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur de la creation d’une fenetre: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur de la creation du menu: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (!initSDL()) {
        printf("L'initialisation SDL a échoué.\n");
        return 1;
    }

    if (!loadMenu()) {
        printf("L'initialisation du menu a échoué.\n");
        return 1;
    }
    
    int quit = 0;
    SDL_Event e;

    //Boucle principale
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Vérifier si le clic est sur le bouton "Jouer"
                if (x >= jouerButton.rect.x && x <= jouerButton.rect.x + jouerButton.rect.w &&
                    y >= jouerButton.rect.y && y <= jouerButton.rect.y + jouerButton.rect.h) {
                    printf("Bouton Jouer cliqué!\n");
                    jeu(window, renderer);
                }
                // Vérifier si le clic est sur le bouton "Quitter"
                else if (x >= quitterButton.rect.x && x <= quitterButton.rect.x + quitterButton.rect.w &&
                         y >= quitterButton.rect.y && y <= quitterButton.rect.y + quitterButton.rect.h) {
                    printf("Bouton Quitter cliqué!\n");
                    quit = 1;
                }
            }
        }
        // Afficher le menu
        renderMenu();
    }

    // Libérer les ressources et quitter SDL
    closeMenu();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}