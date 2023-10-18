#include <SDL.h>
#include <SDL_image.h> 
#include <SDL_ttf.h> 
#include <stdio.h>
#include <stdlib.h>  

#include "fonctions.h"

int main(int argc, char *argv[])
{
    
    SDL_Window *window = NULL ;
    SDL_Renderer *renderer = NULL ;    

    SDL_Rect tabRect_J1[45];
    SDL_Rect tabRect_J2[45];
    SDL_Rect tabRect_J3[45];
    SDL_Rect tabRect_J4[45];

    SDL_Rect tabRect_central[150];
    
    SDL_Rect tabBtns[4];
    SDL_Rect tabNoms[4];

    SDL_Rect notifications ;

    TTF_Font *font = NULL ;
    

    if(TTF_Init() == -1){
        Erreur_Rencontee("Erreur d'initialisation de la lib ttf\n");
    }

    font = TTF_OpenFont( "fonts/Gotu.ttf", 28 ); 

    if(font == NULL){
        Erreur_Rencontee("Erreur FONT") ;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0)//initialisation de la SDL
        Erreur_Rencontee("Erreur d'initialisation\n");

    window = SDL_CreateWindow(TITRE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_F, HAUTEUR_F, SDL_WINDOW_SHOWN );

    if (window == NULL)//Verification de la création de la fenêtre
        Erreur_Rencontee("Echec de creation de la fenetre\n");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == NULL){
        SDL_DestroyWindow(window);
        Erreur_Rencontee("Echec de creation du rendu");
    }


    //Fonction pour charger toutes les textures

    if (charger_toutes_les_texture(renderer) != 0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Erreur_Rencontee("on a pa pu creer le tableau des textures !");
    }

    if(SDL_SetRenderDrawColor(renderer, 32,178,170, SDL_ALPHA_OPAQUE) != 0)
        Erreur_Rencontee("Erreur depuis SDL_SetRenderDrawColor !\n"); 


    preparation_plateau_jeu(renderer, tabRect_central, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabNoms, tabBtns, &notifications, tab_textures_sp) ;



    dessiner_dans_un_rectagle(renderer, 10, 'v', 231, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 14, 'r', 286, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 1, 'r', 100, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 2, 'v', 101, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 3, 'n', 102, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 4, 'j', 103, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 14, 'n', 108, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 14, 'r', 330, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
    dessiner_dans_un_rectagle(renderer, 14, 'n', 1, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);


    
    SDL_RenderPresent(renderer);//Pour presenter ou afficher notre rendu dans notre fenetre

    SDL_bool prog_en_cours = SDL_TRUE ;
    int num_rect_clique = 0 ;

    while(prog_en_cours){

        SDL_Event evenement ;

        while (SDL_PollEvent(&evenement)){
            
            switch (evenement.type){

                case SDL_MOUSEMOTION:
                    surbrillance_rectangle(renderer, trouver_numero_rectangle( evenement.motion.x, evenement.motion.y, 0), num_rect_clique , tabBtns, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
                    SDL_RenderPresent(renderer);
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    num_rect_clique = trouver_numero_rectangle( evenement.button.x, evenement.button.y, 0) ;
                    surbrillance_rectangle_selectionne(renderer, num_rect_clique , tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
                    printf("Vous avez clique le rectangle : %d\n", num_rect_clique );
                    SDL_RenderPresent(renderer);
                    break;

                case SDL_QUIT:
                    prog_en_cours = SDL_FALSE ;
                    break;
            
                default:
                    break;
            }


        }
        
    }





    SDL_DestroyRenderer(renderer);//Cela doit se faire avant la destruction e la fentre ; 
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0 ;
}


//gcc src/*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

