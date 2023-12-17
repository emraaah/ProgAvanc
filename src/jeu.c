#include "jeu.h"

void jeu(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_Event evenements;//Événements liés à la fenêtre
    bool terminer = false;
    //char ** terrain = lire_fichier("map/plateau.txt");//Initialiser le plateau

    //Initialiser le fond du jeu 
    SDL_Texture* fond = charger_image("ressources/jeu_fond.bmp", renderer);

    //Allouer le veseau
    vaisseau_t *vaisseau = malloc(sizeof(vaisseau_t));
    init_vaisseau(renderer, vaisseau);

    while (!terminer){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, fond, NULL, NULL);

        //Placer le vaisseau
        SDL_RenderCopy(renderer, vaisseau->sprite, &vaisseau->vaisseau_pavage[0], &vaisseau->SrcR_sprite);

        //Evenements qui permet de deplacer le vaisseau vers la gauche ou vers la droite
        SDL_PollEvent(&evenements);
        switch(evenements.type){
            case SDL_QUIT:
                terminer = true; break;
            case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;  
                        break;
                    case SDLK_RIGHT:
                        vaisseau->SrcR_sprite.x+=WIDTH/22;
                        SDL_Delay(200);
                        break;
                    case SDLK_LEFT:
                        vaisseau->SrcR_sprite.x-=WIDTH/22;
                        SDL_Delay(200);
                        break;     
                }

            //Collision
            if(vaisseau->SrcR_sprite.x <= 0){
                vaisseau->SrcR_sprite.x = 0;
            }else if(vaisseau->SrcR_sprite.x >= 669 - 5){
                vaisseau->SrcR_sprite.x = 669 - 5;
            }
        }

        SDL_RenderPresent(renderer);
    }



    SDL_DestroyTexture(fond);
    SDL_DestroyRenderer(renderer);

    free(vaisseau);
    

    // Quitter SDL
    SDL_DestroyWindow(window);

}
