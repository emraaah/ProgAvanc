#include "vaisseau.h"

void init_vaisseau(SDL_Renderer* renderer, vaisseau_t *vaisseau){

    //Transparence pour le vaisseai
	Uint8 ra=0, ga=0, ba=0;
    vaisseau->sprite = charger_image_transparente("ressources/vaisseaux.bmp",renderer,ra,ga,ba);
    int w, h, x =0, y=0;
    SDL_QueryTexture(vaisseau->sprite, NULL, NULL, &w, &h);

    //Boucle qui parcours le fichier pour l'image
    for(int i=0; i<16; i++){
        if(i >4){
            x=0;
            y=h;   
        }
        vaisseau->vaisseau_pavage[i].x = x;
        vaisseau->vaisseau_pavage[i].y = y;
        vaisseau->vaisseau_pavage[i].w = w/4; // Largeur du sprite
        vaisseau->vaisseau_pavage[i].h = h/5; // Hauteur du sprite
        x+=w/4;
    }
    vaisseau->SrcR_sprite.x = 350;
    vaisseau->SrcR_sprite.y = 550;
    vaisseau->SrcR_sprite.w = WIDTH/20;
    vaisseau->SrcR_sprite.h = HEIGHT/10;
}