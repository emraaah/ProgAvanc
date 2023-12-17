#include "menu.h"
#include "fonctions_SDL.h"

// Initialisation des boutons
Button jouerButton = {{233, 250, 0, 0}, NULL};
Button quitterButton = {{233, 350, 0, 0}, NULL};
SDL_Texture* fond = NULL;

// Fonction pour charger les textures du menu
int loadMenu() {

    //Charger les differents image pour le bouton & le fond
    jouerButton.texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("ressources/jouer.bmp"));
    quitterButton.texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("ressources/quitter.bmp"));
    fond = charger_image("ressources/fond.bmp", renderer);

    if (jouerButton.texture == NULL || quitterButton.texture == NULL || fond == NULL) {
        printf("Erreur d’initialisation des images du menu %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

// Fonction pour libérer les textures du menu
void closeMenu() {
    SDL_DestroyTexture(jouerButton.texture);
    SDL_DestroyTexture(quitterButton.texture);
    SDL_DestroyTexture(fond);
}

// Fonction pour afficher le menu
void renderMenu() {
    SDL_RenderClear(renderer);

    // Afficher l'image de fond
    SDL_RenderCopy(renderer, fond, NULL, NULL);

    SDL_QueryTexture(jouerButton.texture, NULL, NULL, &jouerButton.rect.w, &jouerButton.rect.h);
    SDL_QueryTexture(quitterButton.texture, NULL, NULL, &quitterButton.rect.w, &quitterButton.rect.h);

    SDL_RenderCopy(renderer, jouerButton.texture, NULL, &jouerButton.rect);
    SDL_RenderCopy(renderer, quitterButton.texture, NULL, &quitterButton.rect);

    SDL_RenderPresent(renderer);
}
