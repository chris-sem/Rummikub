#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 

#include "fonctions.h"

int main(int argc, char *argv[])
{
    //******************************  LES DECLARATIONS  ****************************

    int j; 
    int a;

    SDL_bool prog_en_cours = SDL_TRUE ;

    SDL_Window *window = NULL ;
    SDL_Renderer *renderer = NULL ;   

    TTF_Font *font_nom_joueurs = NULL ;
    TTF_Font *font_notif_normale = NULL ;
    TTF_Font *font_notif_erreur = NULL ;

    SDL_Surface *icone = NULL ;

    SDL_Texture* tab_textures_tuiles_noires[13];
    SDL_Texture* tab_textures_tuiles_vertes[13];
    SDL_Texture* tab_textures_tuiles_jaunes[13];
    SDL_Texture* tab_textures_tuiles_rouges[13];

    SDL_Texture* tab_textures_carres_noires[13];
    SDL_Texture* tab_textures_carres_vertes[13];
    SDL_Texture* tab_textures_carres_jaunes[13];
    SDL_Texture* tab_textures_carres_rouges[13];

    SDL_Texture* tab_textures_sp[21];

    JOUEUR joueurs[4] ;

    strcpy(joueurs[0].pseudo, "");
    joueurs[0].score = 0 ;

    strcpy(joueurs[1].pseudo, "");
    joueurs[1].score = 0 ;

    strcpy(joueurs[2].pseudo, "");
    joueurs[2].score = 0 ;

    strcpy(joueurs[3].pseudo, "");
    joueurs[3].score = 0 ;
    
    //*******************************************************************************



    //*******************  INITIALISATION GENERALE DU PROJET  ***********************

    if(TTF_Init() == -1){
        Erreur_Rencontee("Erreur d'initialisation de la lib ttf\n");
    }

    font_nom_joueurs = TTF_OpenFont( "fonts/Gotu.ttf", 28 ); 
    font_notif_erreur = TTF_OpenFont( "fonts/Gotu.ttf", 28 ); 
    font_notif_normale = TTF_OpenFont( "fonts/Gotu.ttf", 18 ); 

    if(font_nom_joueurs == NULL || font_notif_erreur == NULL || font_notif_normale == NULL){
        printf("Erreur FONTS\n") ;
        goto Quit;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0){//initialisation de la SDL
        printf("Erreur d'initialisation\n");
        goto Quit ;
    }

    window = SDL_CreateWindow(TITRE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_F, HAUTEUR_F, SDL_WINDOW_SHOWN );

    if (window == NULL){//Verification de la création de la fenêtre
        printf("Echec de creation de la fenetre\n");
        goto Quit ;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if(renderer == NULL){
        SDL_DestroyWindow(window);
        printf("Echec de creation du rendu");
        goto Quit ;
    }

    //Fonction pour charger toutes les textures
    if (charger_toutes_les_texture(renderer, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp) != 0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        printf("on a pa pu creer le tableau des textures !");
        goto Quit ;
    }
    
    icone = IMG_Load("images/icone.png");

    if(icone != NULL){
        SDL_SetWindowIcon(window, icone);
    }
    else{
        goto Quit ;
    }
        

    //***************************************************************************************



    while(prog_en_cours){

        //avant_jeu retourne 0, si l'utilisateur clique sur le bouton commencer
        //retourne 1, s'il clique sur le bouton quitter

        a = avant_jeu(renderer, joueurs, font_nom_joueurs, font_notif_normale, tab_textures_sp);

        if(a == 0){

            //jouer retourne 1 quand l'utilisateur clique sur la croix en haut à droite de l'ecran, 
            //et retourne 0 si l'utilisateur clique sur le bouton fin de partie (double clique)

            j = jouer(renderer, joueurs, font_nom_joueurs, font_notif_normale, font_notif_erreur, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp) ;
            
            if( j == 1){ 
                prog_en_cours = SDL_FALSE ;  
            }

        }
        else{
            prog_en_cours = SDL_FALSE ;
        }
        
    }


    Quit:
        if(NULL != renderer)
            SDL_DestroyRenderer(renderer);
        if(NULL != window)
            SDL_DestroyWindow(window);
        SDL_Quit();

        //printf("fin");
    
    return 0 ; 
}


//windows //gcc src/*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

//Linux //gcc mon_fichier.c $(sdl2-config --cflags --libs) -o prog

