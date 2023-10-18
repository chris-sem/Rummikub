#include <SDL.h>
#include <SDL_image.h> 
#include <SDL_ttf.h> 
#include <stdio.h>
#include "fonctions.h" 

void bonjour(){
    printf("Je suis l'ami de tout le monde et l'ami de personne !!!\n");
}

void Erreur_Rencontee(char *message){
    printf("Erreur : %s\n", message);
    SDL_Quit();
}


//la fonction dessiner_rects(), dessine automatiquement plusieurs restangle dans des positions bien definies à l'eran, en partant d'un point de depart de coordonnées ( x_depart, y_depart )
void dessiner_rects(SDL_Rect tabRect[150], SDL_Renderer *renderer, int x_depart, int y_depart, int ecart_x, int ecart_y, int hauteur, int largeur, int nbre_colonne, int taille_tab){

    for(int i=0, x = x_depart,  y = y_depart,  cpt=0; i<taille_tab ; i++ , cpt++){

        if (cpt == nbre_colonne){
            x = x_depart ;
            y = y + hauteur + ecart_y;
            cpt = 0 ;
        }
            
        tabRect[i].x = x ; 
        tabRect[i].y = y ;
        tabRect[i].h = hauteur ;
        tabRect[i].w = largeur ;

        x = x + largeur + ecart_x ;
    }

    // for(int i=0 ; i<taille_tab; i++){

    //     if(SDL_RenderDrawRect(renderer, &tabRect[i]) != 0)
    //         Erreur_Rencontee("Impossible de dessiner le rectangle !");
    // }

}


void preparation_plateau_jeu(SDL_Renderer *renderer, SDL_Rect tabRect1[150], SDL_Rect tabRect2[150], SDL_Rect tabRect3[150], SDL_Rect tabRect4[150], SDL_Rect tabRect5[150], SDL_Rect tabRect6[150], SDL_Rect tabRect7[150], SDL_Rect *notifications, SDL_Texture* tab_textures_sp[10]){
    
    SDL_Rect tete ;
    SDL_Rect contenu ;
    SDL_Rect pied ;

    SDL_Rect marge ;

    tete.x = 0 ;
    tete.y = 0 ;
    tete.h = 225 ;
    tete.w = LARGEUR_F ; 

    contenu.x = 0 ;
    contenu.y = 225 ;
    contenu.h = 485 ; 
    contenu.w = LARGEUR_F ;

    pied.x = 0 ;
    pied.y = 710 ;
    pied.h = 243 ;
    pied.w = LARGEUR_F ;

    marge.x = 608 ;
    marge.y = 235 ;
    marge.h = 50 ;
    marge.w = 10 ;

    notifications->x = 618 ;
    notifications->y = 235 ;
    notifications->h = 50 ;
    notifications->w = 350;

    if(SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE) != 0) 
        Erreur_Rencontee("Erreur depuis SDL_SetRenderDrawColor !\n"); 

    if(SDL_RenderFillRect(renderer, &tete)!= 0)
            Erreur_Rencontee("Impossible de dessiner le rectangle tete !");

    if(SDL_RenderFillRect(renderer, &pied)!= 0)
            Erreur_Rencontee("Impossible de dessiner le rectangle pied !");

    if(SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE) != 0) 
        Erreur_Rencontee("Erreur depuis SDL_SetRenderDrawColor !\n"); 

    SDL_RenderDrawLine(renderer, 40, 64, 750, 64) ;

    SDL_RenderDrawLine(renderer, 842, 64, 1552, 64) ;

    SDL_RenderDrawLine(renderer, 40, 882, 750, 882) ;

    SDL_RenderDrawLine(renderer, 842, 882, 1552, 882) ;

    dessiner_rects(tabRect6, renderer, 265, 20, 572, 830, 40, 240, 2, 4); // les rectangles qui vont prendre les noms des joueurs

    if(SDL_RenderFillRect(renderer, &contenu)!= 0)
            Erreur_Rencontee("Impossible de dessiner le rectangle pied !");
    
    if(SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE) != 0) 
        Erreur_Rencontee("Erreur depuis SDL_SetRenderDrawColor !\n"); 

    if(SDL_RenderFillRect(renderer, notifications) != 0)
        Erreur_Rencontee("Impossible de dessiner notifications");

    if(SDL_RenderFillRect(renderer, &marge) != 0)
        Erreur_Rencontee("Impossible de dessiner marge");
    
    if(SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) != 0)
        Erreur_Rencontee("Erreur depuis SDL_SetRenderDrawColor !\n"); 

    dessiner_rects(tabRect7, renderer, 190, 240, 430, 375, 40, 380, 2, 4);//on dessine ici les rectangle des differentsr bouttons

    dessiner_rects(tabRect2, renderer, 50, 70, 1, 1, 48, 45, 15, 45);//on dessine ici les rectangle du chevalet du joueur 1

    dessiner_rects(tabRect3, renderer, 855, 70, 1, 1, 48, 45, 15, 45);//on dessine ici les rectangle du chevalet du joueur 2

    dessiner_rects(tabRect1, renderer, 10, 292, 1, 1, 70, 51, 30, 150);//on dessine ici les rectangle du plateau 

    dessiner_rects(tabRect4, renderer, 50, 730, 1, 1, 48, 45, 15, 45);//on dessine ici les rectangle du chevalet du joueur 3

    dessiner_rects(tabRect5, renderer, 855, 730, 1, 1, 48, 45, 15, 45);//on dessine ici les rectangle du chevalet du joueur 3

    //affichage des image des bouttons
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[6], &tabRect7[0]);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[7], &tabRect7[1]);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[8], &tabRect7[2]);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[9], &tabRect7[3]);

    //on peut remplir le rectangle de la notification ici


}

int creer_tab_textures(SDL_Renderer *renderer, SDL_Texture* tab_textures[13], char c_pour_carre_OU_t_pour_tuile, char prem_lettre_de_la_couleur){
    
    SDL_Surface *picture = NULL ;
    SDL_Texture *texture = NULL ;

    char s[20];

    for(int i=0 ; i<13 ; i++){

        sprintf(s, "images/%c%c%d.png", c_pour_carre_OU_t_pour_tuile, prem_lettre_de_la_couleur, (i+1));

        picture = IMG_Load(s) ;

        if(picture == NULL){
            printf("Chargement non abouti de l'image : %s", s);
            return -1 ;
        }

        texture = SDL_CreateTextureFromSurface(renderer, picture);
        SDL_FreeSurface(picture);

        if(texture == NULL){
            printf("Creation de texture de : %s, non aboutie", s);
            return -1 ;
        }

        tab_textures[i] = texture ;

    }

    return 0 ;
}

int charger_toutes_les_texture(SDL_Renderer *renderer, SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[21]){

    SDL_Surface *picture = NULL ;
    SDL_Texture *texture = NULL ;

    char* noms_fichiers_sp[] = {"images/c_eff.png","images/r_eff.png","images/cjokn.png","images/cjokr.png","images/jokn.png", "images/jokr.png" , "images/bouton1.png" , "images/bouton2.png", "images/bouton3_2.png", "images/bouton4.png", "images/icone.png", "images/top.png", "images/isty.png", "images/cachet.png", "images/gauche.png", "images/curseur.png", "images/commencer.png", "images/quitter.png", "images/rkb.png", "images/rkb_icone.png", "images/rkb_icone2.png"};

    for(int i=0 ; i<21 ; i++){

        picture = IMG_Load(noms_fichiers_sp[i]);

        if(picture == NULL){
            printf("Chargement non abouti de l'image depuis charger_toutes_les_texture, position %d", i) ;
            return -1 ;
        }

        texture = SDL_CreateTextureFromSurface(renderer, picture);
        SDL_FreeSurface(picture);

        if(texture == NULL){
            printf("Creation de texture non aboutie depuis charger_toutes_les_texture");
            return -1 ;
        }

        tab_textures_sp[i] = texture ;
    }

    if (creer_tab_textures(renderer, tab_textures_tuiles_noires, 't', 'n') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_tuiles_jaunes, 't', 'j') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_tuiles_rouges, 't', 'r') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_tuiles_vertes, 't', 'v') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_carres_jaunes, 'c', 'j') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_carres_noires, 'c', 'n') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_carres_rouges, 'c', 'r') != 0){
        return -1 ;
    }
    if (creer_tab_textures(renderer, tab_textures_carres_vertes, 'c', 'v') != 0){
        return -1 ;
    }

    return 0 ;
}

void mettre_une_texture_dans_un_rect(SDL_Renderer *renderer, SDL_Texture* texture, SDL_Rect* rect){
    SDL_QueryTexture(texture, NULL, NULL, &(rect->w), &(rect->h));
    SDL_RenderCopy(renderer, texture, NULL, rect);
}

//sachant que le Jocker c'est le num *** 14 ***
void dessiner_dans_un_rectagle(SDL_Renderer *renderer, int num_a_afficher, char prem_lettre_couleur, int num_du_rectangle, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150], SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[10]){
    
    if((num_du_rectangle >= 1) && (num_du_rectangle <= 45)){
        if(num_a_afficher == 0){
            mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[0], &tabRect_J1[num_du_rectangle-1]);
        }
        else if(num_a_afficher <= 13){
            switch ( prem_lettre_couleur){
                case 'j':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_jaunes[num_a_afficher-1], &tabRect_J1[num_du_rectangle-1]);
                    break;

                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_noires[num_a_afficher-1], &tabRect_J1[num_du_rectangle-1]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_rouges[num_a_afficher-1], &tabRect_J1[num_du_rectangle-1]);
                    break;
                case 'v':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_vertes[num_a_afficher-1], &tabRect_J1[num_du_rectangle-1]);
                    break;
            
                default:
                    break;
            }
        }else{
            switch ( prem_lettre_couleur){
                
                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[2], &tabRect_J1[num_du_rectangle-1]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[3], &tabRect_J1[num_du_rectangle-1]);
                    break;
            
                default:
                    break;
            }
        }
        
    }

    else if ((num_du_rectangle >= 46) && (num_du_rectangle <= 90)){
        if(num_a_afficher == 0){
            mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[0], &tabRect_J2[num_du_rectangle-46]);
        }
        else if(num_a_afficher <= 13){
            switch ( prem_lettre_couleur){
                case 'j':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_jaunes[num_a_afficher-1], &tabRect_J2[num_du_rectangle-46]);
                    break;

                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_noires[num_a_afficher-1], &tabRect_J2[num_du_rectangle-46]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_rouges[num_a_afficher-1], &tabRect_J2[num_du_rectangle-46]);
                    break;
                case 'v':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_vertes[num_a_afficher-1], &tabRect_J2[num_du_rectangle-46]);
                    break;
            
                default:
                    break;
            }
        }else{
            switch ( prem_lettre_couleur){
                
                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[2], &tabRect_J2[num_du_rectangle-46]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[3], &tabRect_J2[num_du_rectangle-46]);
                    break;
            
                default:
                    break;
            }
        }
        
    }
    else if ((num_du_rectangle >= 91) && (num_du_rectangle <= 240)){
        if(num_a_afficher == 0){
            mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[1], &tabRect_central[num_du_rectangle-91]);
        }
        else if(num_a_afficher <= 13){
            switch ( prem_lettre_couleur){
                case 'j':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_tuiles_jaunes[num_a_afficher-1], &tabRect_central[num_du_rectangle-91]);
                    break;

                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_tuiles_noires[num_a_afficher-1], &tabRect_central[num_du_rectangle-91]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_tuiles_rouges[num_a_afficher-1], &tabRect_central[num_du_rectangle-91]);
                    break;
                case 'v':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_tuiles_vertes[num_a_afficher-1], &tabRect_central[num_du_rectangle-91]);
                    break;
            
                default:
                    break;
            }
        }else{
            switch ( prem_lettre_couleur){
                
                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[4], &tabRect_central[num_du_rectangle-91]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[5], &tabRect_central[num_du_rectangle-91]);
                    break;
            
                default:
                    break;
            }
        }
       
    }
    else if ((num_du_rectangle >= 241) && (num_du_rectangle <= 285)){
        if(num_a_afficher == 0){
            mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[0], &tabRect_J3[num_du_rectangle-241]);
        }
        else if(num_a_afficher <= 13){
            switch ( prem_lettre_couleur){
                case 'j':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_jaunes[num_a_afficher-1], &tabRect_J3[num_du_rectangle-241]);
                    break;

                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_noires[num_a_afficher-1], &tabRect_J3[num_du_rectangle-241]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_rouges[num_a_afficher-1], &tabRect_J3[num_du_rectangle-241]);
                    break;
                case 'v':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_vertes[num_a_afficher-1], &tabRect_J3[num_du_rectangle-241]);
                    break;
            
                default:
                    break;
            }
        }else{
            switch ( prem_lettre_couleur){
                
                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[2], &tabRect_J3[num_du_rectangle-241]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[3], &tabRect_J3[num_du_rectangle-241]);
                    break;
            
                default:
                    break;
            }
        }
        
    }
    else if ((num_du_rectangle >= 286) && (num_du_rectangle <= 330)){
        if(num_a_afficher == 0){
            mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[0], &tabRect_J4[num_du_rectangle-286]);
        }
        else if(num_a_afficher <= 13){
            switch ( prem_lettre_couleur){
                case 'j':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_jaunes[num_a_afficher-1], &tabRect_J4[num_du_rectangle-286]);
                    break;

                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_noires[num_a_afficher-1], &tabRect_J4[num_du_rectangle-286]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_rouges[num_a_afficher-1], &tabRect_J4[num_du_rectangle-286]);
                    break;
                case 'v':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_carres_vertes[num_a_afficher-1], &tabRect_J4[num_du_rectangle-286]);
                    break;
            
                default:
                    break;
            }
        }else{
            switch ( prem_lettre_couleur){
                
                case 'n':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[2], &tabRect_J4[num_du_rectangle-286]);
                    break;

                case 'r':
                    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[3], &tabRect_J4[num_du_rectangle-286]);
                    break;
            
                default:
                    break;
            }
        }
        
    }else{
        //on fait rien du tout pour l'instant
    }
    
}


int trouver_numero_rectangle_aux(int x, int y, int x_pointe, int y_pointe, int largeur, int hateur, int colonne){

    return ( ( ( ( (y_pointe - y) + (hateur+1) ) / (hateur+1) )  -1 ) * colonne ) + ( ( (x_pointe - x) + (largeur+1) ) / (largeur+1) ) ;
   
}

int trouver_numero_rectangle(int x_pointe, int y_pointe, int tour){

    int joueur1 = 0 ;
    int joueur2 = 0 ;
    int joueur3 = 0 ;
    int joueur4 = 0 ;
    int joueur5 = 0 ;

    if(tour == 1){
        joueur1 = 1 ;
    }else if(tour == 2){
        joueur2 = 1 ;
    }else if(tour == 3){
        joueur3 = 1 ;
    }else if(tour == 4){
        joueur4 = 1 ;
    }else{
        joueur5 = 1;
    }

    if( (y_pointe > 70) && (y_pointe < 217) ){

        if( (x_pointe > 50) && (x_pointe < 740) && (joueur1 || joueur5)){
            return trouver_numero_rectangle_aux(51, 71, x_pointe, y_pointe, 45, 48, 15)  ;
        }

        else if( (x_pointe > 855 ) && (x_pointe < 1545 ) && (joueur2 || joueur5) ){
            return  trouver_numero_rectangle_aux(856, 71, x_pointe, y_pointe, 45, 48, 15) + 45;
        }

        else{
            return 0 ;
        }

    }

    else if( (y_pointe > 240) && (y_pointe < 280) ){

        if( (x_pointe > 190) && (x_pointe < 570) ){
            return 331 ;
        }

        else if( (x_pointe > 1000 ) && (x_pointe < 1380 ) ){
            return  332;
        }

        else{
            return 0 ;
        }
    }

    else if( (y_pointe > 292) && (y_pointe < 647) ){
        return trouver_numero_rectangle_aux(11, 293, x_pointe, y_pointe, 51, 70, 30) + 90 ;
    }

    else if( (y_pointe > 655) && (y_pointe < 695) ){

        if( (x_pointe > 190) && (x_pointe < 570)){
            return 333 ;
        }

        else if( (x_pointe > 1000 ) && (x_pointe < 1380 )){
            return  334;
        }

        else{
            return 0 ;
        }
    }

    else if( (y_pointe > 730) && (y_pointe < 877) ){

        if( (x_pointe > 50) && (x_pointe < 740) && (joueur3 || joueur5) ){
            return trouver_numero_rectangle_aux(51, 731, x_pointe, y_pointe, 45, 48, 15) + 240 ;
        }

        else if( (x_pointe > 855 ) && (x_pointe < 1545 ) && (joueur4 || joueur5)){
            return  trouver_numero_rectangle_aux(856, 731, x_pointe, y_pointe, 45, 48, 15) + 285;
        }

        else{
            return 0 ;
        }

    }

    else{
        return 0 ;
    }
}


void surbrillance_rectangle(SDL_Renderer *renderer, int num_rectangle, int num_rectangle_a_eviter, SDL_Rect tabBtns[4], SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150]){
    
    for(int i=1 ; i <= 334 ; i++){

        if( i != num_rectangle_a_eviter){

            if((i >= 1) && (i<=45)){
                if( i== num_rectangle ){

                    SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) ;//jaune
                    SDL_RenderDrawRect(renderer, &tabRect_J1[i-1]);

                }else{

                    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &tabRect_J1[i-1]);

                }
            }else if((i >= 46) && (i<=90)){
                if( i== num_rectangle ){

                    SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) ;//jaune
                    SDL_RenderDrawRect(renderer, &tabRect_J2[i-46]);

                }else{

                    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &tabRect_J2[i-46]);

                }
            }else if( (i >= 91) && (i<=240)){
                if( i== num_rectangle ){

                    SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) ;//jaune
                    SDL_RenderDrawRect(renderer, &tabRect_central[i-91]);

                }else{

                    SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE);//contenu
                    SDL_RenderDrawRect(renderer, &tabRect_central[i-91]);

                }
            }else if( (i >= 241) && (i<=285)){
                if( i== num_rectangle ){

                    SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) ;//jaune
                    SDL_RenderDrawRect(renderer, &tabRect_J3[i-241]);

                }else{

                    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &tabRect_J3[i-241]);

                }
            }else if( (i >= 286) && (i<=330)){
                if( i== num_rectangle ){

                    SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) ;//jaune
                    SDL_RenderDrawRect(renderer, &tabRect_J4[i-286]);

                }else{

                    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &tabRect_J4[i-286]);

                }
            }else if( (i >= 331) && (i<=334)){
                if( i== num_rectangle ){

                    SDL_SetRenderDrawColor(renderer, 255,175,94, SDL_ALPHA_OPAQUE) ;//jaune
                    SDL_RenderDrawRect(renderer, &tabBtns[i-331]);

                }else{

                    SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE);//contenu
                    SDL_RenderDrawRect(renderer, &tabBtns[i-331]);

                }
            }
            else{}
        }
    }
}

void surbrillance_rectangle_selectionne(SDL_Renderer *renderer, int num_rectangle, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150]){
    
    if((num_rectangle >= 1) && (num_rectangle<=45)){
        SDL_SetRenderDrawColor(renderer, 235,51,36, SDL_ALPHA_OPAQUE) ;//rouge
        SDL_RenderDrawRect(renderer, &tabRect_J1[num_rectangle-1]);

    }else if((num_rectangle >= 46) && (num_rectangle<=90)){

        SDL_SetRenderDrawColor(renderer, 235,51,36, SDL_ALPHA_OPAQUE) ;//rouge
        SDL_RenderDrawRect(renderer, &tabRect_J2[num_rectangle-46]);

    }else if( (num_rectangle >= 91) && (num_rectangle<=240)){

        SDL_SetRenderDrawColor(renderer, 235,51,36, SDL_ALPHA_OPAQUE) ;//rouge
        SDL_RenderDrawRect(renderer, &tabRect_central[num_rectangle-91]);
            
    }else if( (num_rectangle >= 241) && (num_rectangle<=285)){
        SDL_SetRenderDrawColor(renderer, 235,51,36, SDL_ALPHA_OPAQUE) ;//rouge
        SDL_RenderDrawRect(renderer, &tabRect_J3[num_rectangle-241]);
                
    }else if( (num_rectangle >= 286) && (num_rectangle<=330)){
        SDL_SetRenderDrawColor(renderer, 235,51,36, SDL_ALPHA_OPAQUE) ;//rouge
        SDL_RenderDrawRect(renderer, &tabRect_J4[num_rectangle-286]);
    }
    else{}

}

void ecrire_dans_rectangle(SDL_Renderer *renderer, TTF_Font *font, char mot[30], SDL_Rect *cadre, SDL_Color couleur_font){

    SDL_Surface *texte ;
    SDL_Texture *texture_texte ;

    texte = TTF_RenderText_Solid( font, mot, couleur_font);
    texture_texte = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_FreeSurface(texte);

    //SDL_RenderDrawRect(renderer, cadre);
    mettre_une_texture_dans_un_rect(renderer, texture_texte, cadre);

}

void initialisation_tableau_tuile(TUILE tabTuiles[5][30], int ligne, int colonne){
    for(int i=0 ; i<ligne ; i++){
       for(int j=0 ; j<colonne ; j++){
            tabTuiles[i][j].valeur = 0 ;
            tabTuiles[i][j].couleur = 'z' ;
        }
    }
}

void initialisation_tableaux_tuiles_du_jeu(TUILE tab_tuiles_j1[5][30], TUILE tab_tuiles_j2[5][30], TUILE tab_tuiles_j3[5][30], TUILE tab_tuiles_j4[5][30], TUILE tab_tuiles_plateau[5][30]){
    initialisation_tableau_tuile(tab_tuiles_j1, 3, 15);
    initialisation_tableau_tuile(tab_tuiles_j2, 3, 15);
    initialisation_tableau_tuile(tab_tuiles_j3, 3, 15);
    initialisation_tableau_tuile(tab_tuiles_j4, 3, 15);
    initialisation_tableau_tuile(tab_tuiles_plateau, 5, 30);
}

void tabTuiles_vers_graphique(SDL_Renderer *renderer, TUILE tabTuiles[5][30], int ligne, int colonne, int indice, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150], SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[10]){
    int debut = 0 ;

    switch (indice){
        case 1 :
            debut = 1;
            break;
        case 2 :
            debut = 46;
            break;
        case 3 :
            debut = 91;
            break;
        case 4 :
            debut = 241;
            break;
        case 5 :
            debut = 286;
            break;
        default:
            break;

    }

    for(int i=0 ; i<ligne ; i++){
       for(int j=0 ; j<colonne ; j++){
            
            dessiner_dans_un_rectagle(renderer, tabTuiles[i][j].valeur, tabTuiles[i][j].couleur, debut, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);
            debut ++ ;

        }
    }
}

int nombre_de_zero_a_(int n){ //fonction qui retourne un nombre de [0 à n]
    return (rand()%(n+1)) ;
}

void creer_tab_106_tuiles(TUILE t1[106]){

    char couleur[] = "nvjr" ; //premières lettre de chaque couleur de notre jeu

    int n = 0 ; //les nombres qu'on va ecrire dans le tab : 11111111 - 22222222 - 33333333 ...
    int cpt = 0 ;

    for(int i=0 ; i<106 ; i++){

        t1[i].valeur =  n+1;
        t1[i].couleur = couleur[cpt/2];

        cpt ++ ;

        if(cpt == 8){
            n++ ;
            cpt = 0;
        }
    }
    t1[104].couleur = 'n';
    t1[105].couleur = 'r';
}

void generation_poche_tuiles(TUILE tab[106]){

    TUILE t1[106];
    int pos = 0 ;
    int indice_aleatoire ;

    creer_tab_106_tuiles(t1); //on cree d'abord un tableau de 106 tuiles, et on essaie après de les dispatcher de manière aleatoire dans notre poche de tuiles

    for(int v=0 ; v<90 ; ){

        indice_aleatoire = nombre_de_zero_a_(105);

        if(t1[indice_aleatoire].valeur != 0){
            tab[pos] = t1[indice_aleatoire] ;
            pos ++ ;
            v++ ;
            t1[indice_aleatoire].valeur = 0 ;
        }
    }

    while(pos<106){

        for(int j=0 ; j<106 ; j++){

            if(t1[j].valeur != 0){
                tab[pos] = t1[j];
                pos ++ ;
            }

        }
    }

    //affichage de contenu de la poche de tuile
    
    // for(int j=0, c=0 ; j<106 ; j++){

    //     printf("t[%d] = { %d, %c}\n" ,j, tab[j].valeur, tab[j].couleur);

    //     c++ ;

    //     if(c==8){
    //         printf("\n");
    //         c = 0 ;
    //     }
        
    // }

}

void transcription_etat_jeu_vers_graphique(SDL_Renderer *renderer, ETAT* etat_du_jeu, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150], SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[10]){

    
    tabTuiles_vers_graphique(renderer, etat_du_jeu->tab_tuiles_j1, 3, 15, 1, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

    tabTuiles_vers_graphique(renderer, etat_du_jeu->tab_tuiles_j2, 3, 15, 2, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

    tabTuiles_vers_graphique(renderer, etat_du_jeu->tab_tuiles_j3, 3, 15, 4, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

    tabTuiles_vers_graphique(renderer, etat_du_jeu->tab_tuiles_j4, 3, 15, 5, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

    tabTuiles_vers_graphique(renderer, etat_du_jeu->tab_tuiles_plateau, 5, 30, 3, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);
    
}

TUILE distribuer_tuile(POCHE_TUILES *poche){
    TUILE tuile ;
    tuile.valeur = 0 ;
    tuile.couleur ='z';

    if((poche->pos_prochain) != 106){
        tuile = (poche->tab_tuile)[poche->pos_prochain] ;
        poche->pos_prochain = (poche->pos_prochain) + 1;
    }else{
        printf("Il y a plus de tuiles dans la poche");
    }
    
    return tuile ;
}

void distribution_initiale_tuiles_aux_joueurs(POCHE_TUILES *poche, TUILE tab_tuiles_j1[5][30], TUILE tab_tuiles_j2[5][30], TUILE tab_tuiles_j3[5][30], TUILE tab_tuiles_j4[5][30] ){

    int cpt = 0 ;

    for(int i=0 ; i<3 && cpt<14; i++){
        for(int j=0 ; j<15 && cpt<14 ; j++){

            tab_tuiles_j1[i][j] = distribuer_tuile(poche);
            tab_tuiles_j2[i][j] = distribuer_tuile(poche);
            tab_tuiles_j3[i][j] = distribuer_tuile(poche);
            tab_tuiles_j4[i][j] = distribuer_tuile(poche);

            cpt ++ ;

        }
    }
}

void piocher_tuile(int tour, POCHE_TUILES *poche, ETAT *etat_du_jeu){
    
    int ok=0 ;

    if(tour == 1){
        if(etat_du_jeu->tab_tuiles_j1[2][14].valeur == 0){
            etat_du_jeu->tab_tuiles_j1[2][14] = distribuer_tuile(poche);
        }else{
            for(int i=0 ; (i<3) && (ok==0) ; i++){
                for(int j=0 ; (j<15) && (ok==0)  ; j++){
                    if(etat_du_jeu->tab_tuiles_j1[i][j].valeur == 0){
                        etat_du_jeu->tab_tuiles_j1[i][j] = distribuer_tuile(poche);
                        ok = 1 ;
                    }
                }
            }

            if(ok == 0){
                TUILE t = etat_du_jeu->tab_tuiles_j1[2][14] ;
                etat_du_jeu->tab_tuiles_j1[2][14] = distribuer_tuile(poche);
                poche->tab_tuile[(poche->pos_prochain) - 1] = t ;
                poche->pos_prochain = poche->pos_prochain - 1 ;
            }
        }
    }

    else if(tour == 2){
        if(etat_du_jeu->tab_tuiles_j2[2][14].valeur == 0){
            etat_du_jeu->tab_tuiles_j2[2][14] = distribuer_tuile(poche);
        }else{
            for(int i=0 ; (i<3) && (ok==0) ; i++){
                for(int j=0 ; (j<15) && (ok==0)  ; j++){
                    if(etat_du_jeu->tab_tuiles_j2[i][j].valeur == 0){
                        etat_du_jeu->tab_tuiles_j2[i][j] = distribuer_tuile(poche);
                        ok = 1 ;
                    }
                }
            }

            if(ok == 0){
                TUILE t = etat_du_jeu->tab_tuiles_j2[2][14] ;
                etat_du_jeu->tab_tuiles_j2[2][14] = distribuer_tuile(poche);
                poche->tab_tuile[(poche->pos_prochain) - 1] = t ;
                poche->pos_prochain = poche->pos_prochain - 1 ;
            }
        }
    }

    else if(tour == 3){
        if(etat_du_jeu->tab_tuiles_j3[2][14].valeur == 0){
            etat_du_jeu->tab_tuiles_j3[2][14] = distribuer_tuile(poche);
        }else{
            for(int i=0 ; (i<3) && (ok==0) ; i++){
                for(int j=0 ; (j<15) && (ok==0)  ; j++){
                    if(etat_du_jeu->tab_tuiles_j3[i][j].valeur == 0){
                        etat_du_jeu->tab_tuiles_j3[i][j] = distribuer_tuile(poche);
                        ok = 1 ;
                    }
                }
            }

            if(ok == 0){
                TUILE t = etat_du_jeu->tab_tuiles_j3[2][14] ;
                etat_du_jeu->tab_tuiles_j3[2][14] = distribuer_tuile(poche);
                poche->tab_tuile[(poche->pos_prochain) - 1] = t ;
                poche->pos_prochain = poche->pos_prochain - 1 ;
            }
        }
    }

    else if(tour == 4){
        if(etat_du_jeu->tab_tuiles_j4[2][14].valeur == 0){
            etat_du_jeu->tab_tuiles_j4[2][14] = distribuer_tuile(poche);
        }else{
            for(int i=0 ; (i<3) && (ok==0) ; i++){
                for(int j=0 ; (j<15) && (ok==0)  ; j++){
                    if(etat_du_jeu->tab_tuiles_j4[i][j].valeur == 0){
                        etat_du_jeu->tab_tuiles_j4[i][j] = distribuer_tuile(poche);
                        ok = 1 ;
                    }
                }
            }

            if(ok == 0){
                TUILE t = etat_du_jeu->tab_tuiles_j4[2][14] ;
                etat_du_jeu->tab_tuiles_j4[2][14] = distribuer_tuile(poche);
                poche->tab_tuile[(poche->pos_prochain) - 1] = t ;
                poche->pos_prochain = poche->pos_prochain - 1 ;
            }
        }
    }

    else{}
}

void incrementer_tour(int *tour){

    *tour = (*tour + 1) ;
    if(*tour == 5){
        *tour = 1 ;
    }

}

void num_vers_coordonnees(int num, int nbre_colonne, int *x, int *y){

    int reste = num%nbre_colonne ;
    int quotient = num/nbre_colonne ;

    if(reste == 0){
        quotient = quotient-1 ;
        reste = nbre_colonne ;
    }

    *x = quotient ;
    *y = reste - 1 ;

}

void deplacer_tuile ( TUILE tab_tuiles_j1[5][30], TUILE tab_tuiles_j2[5][30], TUILE tab_tuiles_j3[5][30], TUILE tab_tuiles_j4[5][30], TUILE tab_tuiles_plateau[5][30], int num_rect_depart, int num_rect_final){
    
    int i_depart, j_depart, i_arrive, j_arrive ;
    
    if(((num_rect_depart != 0) && (num_rect_final != 0))){

        if((num_rect_depart>=1) && (num_rect_depart<=45)){

            if((num_rect_final>=1) && (num_rect_final<=45)){

                num_vers_coordonnees(num_rect_depart, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final, 15, &i_arrive, &j_arrive);

                if(tab_tuiles_j1[i_arrive][j_arrive].valeur == 0){

                    tab_tuiles_j1[i_arrive][j_arrive] =  tab_tuiles_j1[i_depart][j_depart] ;
                    tab_tuiles_j1[i_depart][j_depart].valeur = 0 ;

                }

            }
            else if((num_rect_final>=91) && (num_rect_final<=240)){

                num_vers_coordonnees(num_rect_depart, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-90, 30, &i_arrive, &j_arrive);

                if(tab_tuiles_plateau[i_arrive][j_arrive].valeur == 0){

                    tab_tuiles_plateau[i_arrive][j_arrive] =  tab_tuiles_j1[i_depart][j_depart] ;
                    tab_tuiles_j1[i_depart][j_depart].valeur = 0 ;

                }

            }
        }

        else if((num_rect_depart>=46) && (num_rect_depart<=90)){

            if((num_rect_final>=46) && (num_rect_final<=90)){

                num_vers_coordonnees(num_rect_depart-45, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-45, 15, &i_arrive, &j_arrive);

                if(tab_tuiles_j2[i_arrive][j_arrive].valeur == 0){
                    tab_tuiles_j2[i_arrive][j_arrive] =  tab_tuiles_j2[i_depart][j_depart] ;
                    tab_tuiles_j2[i_depart][j_depart].valeur = 0 ;
                }
                

            }
            else if((num_rect_final>=91) && (num_rect_final<=240)){

                num_vers_coordonnees(num_rect_depart-45, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-90, 30, &i_arrive, &j_arrive);

                if(tab_tuiles_plateau[i_arrive][j_arrive].valeur == 0){
                    tab_tuiles_plateau[i_arrive][j_arrive] =  tab_tuiles_j2[i_depart][j_depart] ;
                    tab_tuiles_j2[i_depart][j_depart].valeur = 0 ;
                }
                

            }
        }

        else if((num_rect_depart>=91) && (num_rect_depart<=240)){

            if((num_rect_final>=91) && (num_rect_final<=240)){

                num_vers_coordonnees(num_rect_depart-90, 30, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-90, 30, &i_arrive, &j_arrive);

                if(tab_tuiles_plateau[i_arrive][j_arrive].valeur == 0){
                    tab_tuiles_plateau[i_arrive][j_arrive] =  tab_tuiles_plateau[i_depart][j_depart] ;
                    tab_tuiles_plateau[i_depart][j_depart].valeur = 0 ;
                }

            }

        }

        else if((num_rect_depart>=241) && (num_rect_depart<=285)){

            if((num_rect_final>=241) && (num_rect_final<=285)){

                num_vers_coordonnees(num_rect_depart-240, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-240, 15, &i_arrive, &j_arrive);

                if(tab_tuiles_j3[i_arrive][j_arrive].valeur == 0){

                    tab_tuiles_j3[i_arrive][j_arrive] =  tab_tuiles_j3[i_depart][j_depart] ;
                    tab_tuiles_j3[i_depart][j_depart].valeur = 0 ;
                }

            }
            else if((num_rect_final>=91) && (num_rect_final<=240)){

                num_vers_coordonnees(num_rect_depart-240, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-90, 30, &i_arrive, &j_arrive);

                if(tab_tuiles_plateau[i_arrive][j_arrive].valeur == 0){
                    tab_tuiles_plateau[i_arrive][j_arrive] =  tab_tuiles_j3[i_depart][j_depart] ;
                    tab_tuiles_j3[i_depart][j_depart].valeur = 0 ;
                }

            }
        }

        else if((num_rect_depart>=286) && (num_rect_depart<=330)){

            if((num_rect_final>=286) && (num_rect_final<=330)){

                num_vers_coordonnees(num_rect_depart-285, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-285, 15, &i_arrive, &j_arrive);

                if(tab_tuiles_j4[i_arrive][j_arrive].valeur == 0){

                    tab_tuiles_j4[i_arrive][j_arrive] =  tab_tuiles_j4[i_depart][j_depart] ;
                    tab_tuiles_j4[i_depart][j_depart].valeur = 0 ;
                }

            }
            else if((num_rect_final>=91) && (num_rect_final<=240)){

                num_vers_coordonnees(num_rect_depart-285, 15, &i_depart, &j_depart);
                num_vers_coordonnees(num_rect_final-90, 30, &i_arrive, &j_arrive);

                if( tab_tuiles_plateau[i_arrive][j_arrive].valeur == 0){

                    tab_tuiles_plateau[i_arrive][j_arrive] =  tab_tuiles_j4[i_depart][j_depart] ;
                    tab_tuiles_j4[i_depart][j_depart].valeur = 0 ;
                }

            }
        }

        else{}
    }
    
    
}

int nombre_tuiles_non_vide(TUILE tab[5][30], int ligne, int colonne){

    int cpt = 0 ;

    for(int i=0 ; i<ligne ; i++){
        for(int j=0 ; j<colonne ; j++){
            if(tab[i][j].valeur != 0){
                cpt ++ ;
            }
        }
    }

    return cpt ;

}

int comparaison_etats(ETAT* etat1, ETAT* etat2) {

    if(nombre_tuiles_non_vide(etat1->tab_tuiles_j1, 3, 15) != nombre_tuiles_non_vide(etat2->tab_tuiles_j1, 3, 15) ){
        return 0 ;
    }

    else if(nombre_tuiles_non_vide(etat1->tab_tuiles_j2, 3, 15) != nombre_tuiles_non_vide(etat2->tab_tuiles_j2, 3, 15)){
        return 0 ;
    }

    else if(nombre_tuiles_non_vide(etat1->tab_tuiles_j3, 3, 15) != nombre_tuiles_non_vide(etat2->tab_tuiles_j3, 3, 15)){
        return 0 ;
    }

    else if(nombre_tuiles_non_vide(etat1->tab_tuiles_j4, 3, 15) != nombre_tuiles_non_vide(etat2->tab_tuiles_j4, 3, 15)){
        return 0 ;
    }

    else if(nombre_tuiles_non_vide(etat1->tab_tuiles_plateau, 5, 30) != nombre_tuiles_non_vide(etat2->tab_tuiles_plateau, 5, 30)){
        return 0 ;
    }

    return 1;
}


void copier_etat(ETAT *etat1, ETAT *etat2) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 30; j++) {
            etat2->tab_tuiles_j1[i][j] = etat1->tab_tuiles_j1[i][j];
            etat2->tab_tuiles_j2[i][j] = etat1->tab_tuiles_j2[i][j];
            etat2->tab_tuiles_j3[i][j] = etat1->tab_tuiles_j3[i][j];
            etat2->tab_tuiles_j4[i][j] = etat1->tab_tuiles_j4[i][j];
            etat2->tab_tuiles_plateau[i][j] = etat1->tab_tuiles_plateau[i][j];
        }
    }
}


int tchecker_fin_du_jeu(ETAT *etat_du_jeu){

    //return 1 ;

    int gagnant_1 = 1;
    int gagnant_2 = 2;
    int gagnant_3 = 3;
    int gagnant_4 = 4;

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<15 ; j++){
            if(etat_du_jeu->tab_tuiles_j1[i][j].valeur != 0){
                gagnant_1 = 0 ;
            } 

            if(etat_du_jeu->tab_tuiles_j2[i][j].valeur != 0){
                gagnant_2 = 0 ;
            }

            if(etat_du_jeu->tab_tuiles_j3[i][j].valeur != 0){
                gagnant_3 = 0 ;
            }

            if(etat_du_jeu->tab_tuiles_j4[i][j].valeur != 0){
                gagnant_4 = 0 ;
            } 
        }
    }

    if(gagnant_1 != 0){
        return 1 ;
    }
    else if(gagnant_2 != 0){
        return 2 ;
    }
    else if(gagnant_3 != 0){
        return 3;
    }
    else if(gagnant_4 != 0){
        return 4 ;
    }
    else{
        return 0 ;
    }


}

void decallage(TUILE plateau[5][30], int ligne, int colonne, int num_rect_arret){

    for(int i=29 ; i>= num_rect_arret ; i--){
        if((plateau[ligne][i].valeur == 0) && (plateau[ligne][i-1].valeur == 0) && (plateau[ligne][i-2].valeur != 0)){
            i = i-2 ;
            while(plateau[ligne][i].valeur != 0){
                plateau[ligne][i+1] = plateau[ligne][i] ;
                i-- ;
            }
        }
    }

}

void calculer_les_score(ETAT *etat_du_jeu, JOUEUR tab_joueurs[4], int *indice_gagnant){

    int s1 = 0 ;
    int s2 = 0 ;
    int s3 = 0 ;
    int s4 = 0 ;

    int min = 0 ;

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<15 ; j++){

            if( etat_du_jeu->tab_tuiles_j1[i][j].valeur == 14){
                s1 = s1 + 30 ;
            }
            else{
                s1 = s1 + etat_du_jeu->tab_tuiles_j1[i][j].valeur ;
            }

            if( etat_du_jeu->tab_tuiles_j2[i][j].valeur == 14){
                s2 = s2 + 30 ;
            }
            else{
                s2 = s2 + etat_du_jeu->tab_tuiles_j2[i][j].valeur ;
            }

            if( etat_du_jeu->tab_tuiles_j3[i][j].valeur == 14){
                s3 = s3 + 30 ;
            }
            else{
                s3 = s3 + etat_du_jeu->tab_tuiles_j3[i][j].valeur ;
            }

            if( etat_du_jeu->tab_tuiles_j4[i][j].valeur == 14){
                s4 = s4 + 30 ;
            }
            else{
                s4 = s4 + etat_du_jeu->tab_tuiles_j4[i][j].valeur ;
            }

            // s1 = s1 + etat_du_jeu->tab_tuiles_j1[i][j].valeur ;
            // s2 = s2 + etat_du_jeu->tab_tuiles_j2[i][j].valeur ;
            // s3 = s3 + etat_du_jeu->tab_tuiles_j3[i][j].valeur ;
            // s4 = s4 + etat_du_jeu->tab_tuiles_j4[i][j].valeur ;
            
        }
    }

    printf("\nS1 : %d\nS2 : %d\nS3 : %d\nS4 : %d\n", s1, s2, s3, s4) ;

    if(*indice_gagnant < 5){

        if(s1 == 0){
            s1 = s1 + s2 + s3 + s4 ;

            tab_joueurs[0].score = s1 ;
            tab_joueurs[1].score = (-s2) ;
            tab_joueurs[2].score = (-s3) ;
            tab_joueurs[3].score = (-s4) ;

            *indice_gagnant = 1 ;
        }

        else if(s2 == 0){
            s2 = s1 + s2 + s3 + s4 ;

            tab_joueurs[0].score = (-s1) ;
            tab_joueurs[1].score = s2 ;
            tab_joueurs[2].score = (-s3) ;
            tab_joueurs[3].score = (-s4) ;

            *indice_gagnant = 2 ;

        }

        else if(s3 == 0){
            s3 = s1 + s2 + s3 + s4 ;

            tab_joueurs[0].score = (-s1) ;
            tab_joueurs[1].score = (-s2);
            tab_joueurs[2].score = s3 ;
            tab_joueurs[3].score = (-s4) ;

            *indice_gagnant = 3 ;

        }

        else if(s4 == 0){
            s4 = s1 + s2 + s3 + s4 ;

            tab_joueurs[0].score = (-s1) ;
            tab_joueurs[1].score = (-s2);
            tab_joueurs[2].score = (-s3) ;
            tab_joueurs[3].score = s4 ;

            *indice_gagnant = 4 ;

        }

        else{}
    }

    else{

        min = s1 ;
        *indice_gagnant = 1 ;

        if(min > s2){
            min = s2 ;
            *indice_gagnant = 2;
        }
        
        if(min > s3){
            min = s3 ;
            *indice_gagnant = 3 ;
        }
        
        if(min > s4){
            min = s4 ;
            *indice_gagnant = 4 ;
        }

        if(*indice_gagnant == 1){

            tab_joueurs[0].score = (s2 + s3 + s4) ;
            tab_joueurs[1].score = (-s2);
            tab_joueurs[2].score = (-s3) ;
            tab_joueurs[3].score = (-s4) ;

        }

        else if(*indice_gagnant == 2){

            tab_joueurs[0].score = (-s1) ;
            tab_joueurs[1].score = (s1 + s3 + s4);
            tab_joueurs[2].score = (-s3) ;
            tab_joueurs[3].score = (-s4) ;

        }

        else if(*indice_gagnant == 3){

            tab_joueurs[0].score = (-s1) ;
            tab_joueurs[1].score = (-s2);
            tab_joueurs[2].score = (s1 + s2 + s4) ;
            tab_joueurs[3].score = (-s4) ;

        }

        else if(*indice_gagnant == 4){

            tab_joueurs[0].score = (-s1) ;
            tab_joueurs[1].score = (-s2);
            tab_joueurs[2].score = (-s3) ;
            tab_joueurs[3].score = (s1 + s2 + s3) ;

        }

        else{}
    }

}


void affichage_score( SDL_Renderer *renderer, ETAT *etat_du_jeu, JOUEUR tab_joueurs[4], int num_gagnant, TTF_Font *font_notif_normale, TTF_Font *font_notif_normale_2, SDL_Texture* tab_textures_sp[20] ){ 

    SDL_Rect tableau_score ;
    SDL_Rect bordure_interne ;

    SDL_Rect r0 ;
    SDL_Rect r1 ;
    SDL_Rect r2 ;
    SDL_Rect r3 ;
    SDL_Rect r4 ;
    SDL_Rect r5 ;
    SDL_Rect r6 ;

    SDL_Color couleur_font = { 113, 108, 180 }; //bleu

    char m0[50] ; //Notre gagnant est NOONMANCH 
    char m1[50] ;
    char m2[50] ;
    char m3[50] ;
    char m4[50] ;

    int vrai_numero_du_gagnant = num_gagnant ;//au cas ou on a arreter le jeu qd y'a plus de tuiles dans la poche

    calculer_les_score(etat_du_jeu, tab_joueurs, &vrai_numero_du_gagnant);
    enregistrement(tab_joueurs, 4);

    //printf("Score 1 : %d\nScore 2 : %d\nScore 3 : %d\nScore 4 : %d\n\nLe gagnant est donc le joueur : %d", tab_joueurs[0].score, tab_joueurs[1].score, tab_joueurs[2].score, tab_joueurs[3].score, vrai_numero_du_gagnant);

    tableau_score.x = 350 ;
    tableau_score.y = 310 ;
    tableau_score.h = 315 ;
    tableau_score.w = 850 ;

    bordure_interne.x = 353 ;
    bordure_interne.y = 313 ;
    bordure_interne.h = 309 ;
    bordure_interne.w = 844 ;

    r0.x = 390;
    r0.y = 330;
    r0.h = 50 ;
    r0.w = 700 ;

    r1.x = 410;
    r1.y = 382;
    r1.h = 50 ;
    r1.w = 600 ;

    r2.x = 410;
    r2.y = 434;
    r2.h = 50 ;
    r2.w = 600 ;

    r3.x = 410;
    r3.y = 486;
    r3.h = 50 ;
    r3.w = 600 ;

    r4.x = 410;
    r4.y = 538;
    r4.h = 50 ;
    r4.w = 600 ;

    r5.x = 750;
    r5.y = 588;
    r5.h = 50 ;
    r5.w = 450 ;

    r6.x = 1060;
    r6.y = 325;
    r6.h = 130 ;
    r6.w = 130 ;

    strcpy(m0, "Notre gagnant est ");
    strcat(m0, tab_joueurs[vrai_numero_du_gagnant-1].pseudo);

    sprintf(m1,"%s : %d", tab_joueurs[0].pseudo, tab_joueurs[0].score);
    sprintf(m2,"%s : %d", tab_joueurs[1].pseudo, tab_joueurs[1].score);
    sprintf(m3,"%s : %d", tab_joueurs[2].pseudo, tab_joueurs[2].score);
    sprintf(m4,"%s : %d", tab_joueurs[3].pseudo, tab_joueurs[3].score);

    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE) ;
    SDL_RenderFillRect(renderer, &tableau_score);

    SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawRect(renderer, &bordure_interne) ;

    ecrire_dans_rectangle(renderer, font_notif_normale, m0, &r0, couleur_font);
    ecrire_dans_rectangle(renderer, font_notif_normale, m1, &r1, couleur_font);
    ecrire_dans_rectangle(renderer, font_notif_normale, m2, &r2, couleur_font);
    ecrire_dans_rectangle(renderer, font_notif_normale, m3, &r3, couleur_font);
    ecrire_dans_rectangle(renderer, font_notif_normale, m4, &r4, couleur_font);
    ecrire_dans_rectangle(renderer, font_notif_normale_2, "Cliquez sur le boutton OKI, pour continuer...", &r5, couleur_font);

    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[13], &r6);

}

//////////////////////////////////// VALIDATION YOUSSEF ///////////////

// int validation_mini(TUILE tab[30],int tour)
  
// {

// for (int j=0;j<29;j++)
//             {
//                 if (tab[j].valeur!=0)
//                {
//                 if(tab[j+1].valeur!=0)
//                   {if ((tab[j+1].valeur==tab[j].valeur+1) && (tab[j+1].couleur==tab[j].couleur))
//                         continue;
//                    else if ((tab[j+1].valeur==tab[j].valeur) || (tab[j].valeur==14)|| (tab[j].valeur==14))
//                         continue;
//                    else
//                        return tab[j].valeur;
//                   }
//                 else if (tab[j-3].valeur!=0)
//                     continue;
//                 else
//                     return tour;
//                 }
//              else
//                 continue;
//             }
//       return 0 ;
//  }
//  int validation_aux(TUILE tab[5][30],int tour)
//  {
//     for (int i=0;i<5;i++)
//         {if (validation_mini(tab[i],tour)==0)
//             continue;
//         else
//             printf("%d\n",i);
//         return tour;}
//  return 0;
//  }

//  int validation(TUILE tab[5][30],int tour ,int *appel)
//  { *appel+=1;
//     int res=validation_aux(tab,tour);
//     if (*appel<=2 )
//     {if (res==tour)
//         return res;
//      else
//         {int s=0;
//         for (int i=0;i<5;i++)
//         {for (int j=0;j<30;j++)
//                 s+=tab[i][j].valeur;
//         }
//         if (s>=30)
//             return 0;
//         else
//             return tour;
//         }
//      }
//      else
//         return res;
//  }




int validation_mini(TUILE tab[30],int tour)
  {

for (int j=0;j<29;j++)
            {
                if (tab[j].valeur!=0)
               {
                if(tab[j+1].valeur!=0)
                  {if ((tab[j+1].valeur==tab[j].valeur+1) && (tab[j+1].couleur==tab[j].couleur))
                        continue;
                   else if ((tab[j+1].valeur==tab[j].valeur) || ((tab[j].valeur==14)&&((tab[j+1].valeur==tab[j-1].valeur)||((tab[j+1].valeur==tab[j-1].valeur+2)&&((tab[j+1].couleur==tab[j-1].couleur)))))|| (tab[j+1].valeur==14))
                        continue;
                   else
                       return tour;
                  }
                else if (tab[j-2].valeur!=0)
                    continue;
                else
                    return tour;
                }
             else
                continue;
            }
      return 0 ;
 }
 int validation_aux(TUILE tab[5][30],int tour)
 {
    for (int i=0;i<5;i++)
        {if (validation_mini(tab[i],tour)==0)
            continue;
        else
            printf("%d\n",i);
        return tour;}
 return 0;
 }

 int validation(TUILE tab[5][30],int tour ,int *appel)
 {
    int res=validation_aux(tab,tour);
    if (*appel<=4 )
    {if (res==tour)
        return res;
     else
        {int s=0;
        for (int i=0;i<5;i++)
        {for (int j=0;j<30;j++)
                s+=tab[i][j].valeur;
        }
        if (s>=30)
           { *appel+=1;
            return 0;}
        else
            return tour;
        }
     }
     else
        return res;
 }



////////////////////////////////////////////////////////////////////////

//int validation_noonmanch(TUILE plateau[3][30], int tour, int *t1, int *t2, int *t3, int *t4, int *somme)//si la validation des block est vraie on calcule la somme
//un tableau vide est valide










////////////////////////////////////////////////////////  VALIDATION NOONMAN CH  ////////////////////////////////////////////////

int somme_tuiles_plateau(TUILE plateau[5][30]){

    TUILE t[150] ;
    int k = 0 ;

    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<30 ; j++){
            t[k] = plateau[i][j];
            k++ ;
        }
    }

    return somme_magique(t) ;

    // int s= 0 ;

    // for(int i=0 ; i<5 ; i++){
    //     for(int j=0 ; j<30 ; j++){
    //         s = s +  plateau[i][j].valeur;
    //     }
    // }

    // return s ;

}

int somme_magique(TUILE tab[150]){

    int s = 0 ;

    int debut_bloc = 0 ;
    int fin_bloc = 0 ;

    for(int i=0; i<150 ; i++){

        if(tab[i].valeur != 0){

            debut_bloc = i ;
            fin_bloc = fin_de_bloc(tab, debut_bloc) ;

            if(tcheck_joker(tab, debut_bloc, fin_bloc) == 1){

                if(sens_bloc(tab, debut_bloc, fin_bloc) == 1){
                    s = s + somme_avec_joker_sens_un(tab, debut_bloc, fin_bloc);
                }
                else{
                    s = s + somme_avec_joker_sens_deux(tab, debut_bloc, fin_bloc);
                }
            }
            else{
                s = s + somme_normale(tab, debut_bloc, fin_bloc);
            }

            i = fin_bloc ;
        }
    }

    return s ;

}

int tcheck_joker(TUILE tab[150], int debut, int fin){

    for(int i=debut ; i<= fin ; i++){

        if(tab[i].valeur == 14 ){
            return 1 ;
        }
    }

    return 0 ;
}

int sens_bloc(TUILE tab[150], int debut, int fin){

    int v1 = 0 ;
    int v2 = 0 ;

    for(int i=debut ; i<= fin ; i++){

        if(tab[i].valeur != 14 ){
            if(v1 == 0){
                v1 = tab[i].valeur ;
            }

            else if( v2== 0){
                v2 = tab[i].valeur ;
            }

            else{}
        }
    }

    if(v2 == 0){
        return 2 ;
    }

    else if( v1 == v2 ){
        return 2 ;
    }

    else{
        return 1 ;
    }
}

int indice_prem_valeur_different_de_joker(TUILE tab[150], int debut, int fin){

    for(int i=debut ; i<= fin ; i++){

        if(tab[i].valeur != 14 ){
            return i ;
        }

    }

    return 0 ;
}

int somme_normale(TUILE tab[150], int debut, int fin){

    int s = 0 ;

    for(int i=debut ; i<= fin ; i++){

        s = s + tab[i].valeur ;

    }

    return s ;
}

int somme_avec_joker_sens_un(TUILE tab[150], int debut, int fin){

    int indice = indice_prem_valeur_different_de_joker(tab, debut, fin) ;
    int s = tab[indice].valeur - (indice - debut);

    for(int i=debut+1 ; i<= fin ; i++){

        s = s + tab[i].valeur ;

    }

    return s ;
}

int somme_avec_joker_sens_deux(TUILE tab[150], int debut, int fin){

    int indice = indice_prem_valeur_different_de_joker(tab, debut, fin) ;

    return (tab[indice].valeur) * (fin - debut + 1) ;
}

int fin_de_bloc(TUILE tab[150], int debut){

    int fin = debut ;

    for(int i= debut ; i<150 ; i++){

        if((i+1) < 150){

            if(tab[i+1].valeur != 0 ){
                fin ++ ;
            }
            else{
                return fin ;
            }
        }
        else{
            return fin ;
        }

    }

    return fin ;
}

int validation_bloc_sens_un(TUILE tab[150], int debut, int fin){

    int v = 0 ;
    char c ;

    for(int i=debut ; i<= fin ; i++){

        if(tab[i].valeur != 14){

            if(v == 0){
                v = tab[i].valeur ;
                c = tab[i].couleur ;
            }
            else{

                if( tab[i].valeur != v){
                    return 0 ;
                }

                else{
                    if(tab[i].couleur != c){
                        return 0 ;
                    }
                }
            }
        }

        if(v != 0){
            v ++ ;
        }
    }

    return 1 ;
}

int validation_bloc_sens_deux(TUILE tab[150], int debut, int fin){

    int v = 0 ;

    for(int i=debut ; i<= fin ; i++){

        if(tab[i].valeur != 14){

            if(v == 0){
                v = tab[i].valeur ;
            }
            else{

                if( tab[i].valeur != v){
                    return 0 ;
                }
            }
        }

    }

    return 1 ;
    
}

int validation_simple(TUILE plateau[5][30]){

    TUILE tab[150] ;
    int k = 0 ;

    int debut_bloc = 0 ;
    int fin_bloc = 0 ;
    int taille = 0 ;

    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<30 ; j++){
            tab[k] = plateau[i][j];
            k++ ;
        }
    }

    for(int i=0; i<150 ; i++){

        if(tab[i].valeur != 0){

            debut_bloc = i ;
            fin_bloc = fin_de_bloc(tab, debut_bloc) ;

            taille = fin_bloc - debut_bloc + 1 ;

            if(taille < 3){
                return 0 ;
            }

            else{

                if((validation_bloc_sens_un(tab, debut_bloc, fin_bloc) == 0 ) && (validation_bloc_sens_deux(tab, debut_bloc, fin_bloc)==0)){
                    return 0 ;
                }

            }

            i = fin_bloc ;
        }
    }

    return 1 ;
}

int validation_NOONMAN(TUILE plateau[5][30], int *t1, int *t2, int *t3, int *t4, int *somme_prec, int tour){

    int s = 0 ;
    if(validation_simple(plateau) == 1){
        if(*t1 == tour){
            s = somme_tuiles_plateau(plateau) ;
            printf("\nLa somme est : %d\n", s - (*somme_prec));

            if((s - (*somme_prec)) >= 30){
                *t1 = 0 ;
                *somme_prec = s ;
                return 1 ;
            }
            else{
                return 0 ;
            }
        }
        else if(*t2 == tour){
            s = somme_tuiles_plateau(plateau) ;
            printf("\nLa somme est : %d\n", s - (*somme_prec));

            if((s - (*somme_prec)) >= 30){
                *t2 = 0 ;
                *somme_prec = s ;
                return 1 ;
            }
            else{
                return 0 ;
            }
        }
        else if(*t3 == tour){
            s = somme_tuiles_plateau(plateau) ;
            printf("\nLa somme est : %d\n", s - (*somme_prec));

            if((s - (*somme_prec)) >= 30){
                *t3 = 0 ;
                *somme_prec = s ;
                return 1 ;
            }
            else{
                return 0 ;
            }
        }
        else if(*t4 == tour){
            s = somme_tuiles_plateau(plateau) ;
            printf("\nLa somme est : %d\n", s - (*somme_prec));

            if((s - (*somme_prec)) >= 30){
                *t4 = 0 ;
                *somme_prec = s ;
                return 1 ;
            }
            else{
                return 0 ;
            }
        }
        else{
            return 1 ;
        }

    }
    else{
        return 0 ;
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int jouer(SDL_Renderer *renderer, JOUEUR tab_joueurs[4], TTF_Font *font_nom_joueurs, TTF_Font *font_notif_normale, TTF_Font *font_notif_erreur, SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[21] ){
    
    SDL_Rect tabRect_J1[45];
    SDL_Rect tabRect_J2[45];
    SDL_Rect tabRect_J3[45];
    SDL_Rect tabRect_J4[45];
    SDL_Rect tabRect_central[150];
    
    SDL_Rect tabBtns[4];
    SDL_Rect tabNoms[4];

    SDL_Rect notifications ;
    char message_notification[19] ;// 19 carac maxx

    //***** NOONMAN *****
    int t1 = 1 ;
    int t2 = 2 ;
    int t3 = 3 ;
    int t4 = 4 ;

    int somme_prec = 0 ;
    //*******************

    int appel = 3 ;
    int num_gagnant = 0; //qd le numero du gagnant = 0, c'est que, on a pas encore de gagnant !
    int tour = 1 ;
    int num_rect_clique = 0 ;
    int num_rect_clique_prec = 0 ;

    SDL_bool prog_en_cours = SDL_TRUE ;
    SDL_Event evenement ;

    ETAT *etat_du_jeu = (ETAT*) malloc(sizeof(ETAT)); 
    ETAT *etat_du_jeu_precedent = (ETAT*) malloc(sizeof(ETAT)); 
    
    POCHE_TUILES *poche = (POCHE_TUILES*) malloc(sizeof(POCHE_TUILES)); //sera considéré comme notre poche de tuiles, où les joueurs iront piocher les tuiles. Il distribuera donc des tuiles de manière aleatoire...

    initialisation_tableaux_tuiles_du_jeu( etat_du_jeu->tab_tuiles_j1, etat_du_jeu->tab_tuiles_j2, etat_du_jeu->tab_tuiles_j3, etat_du_jeu->tab_tuiles_j4, etat_du_jeu->tab_tuiles_plateau);
    preparation_plateau_jeu(renderer, tabRect_central, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabNoms, tabBtns, &notifications, tab_textures_sp) ;

    srand(time(NULL)); //initialisation de la fonction rand() avec le temps, pour la generation des nombres aleatoires

    poche->pos_prochain = 0 ;
    generation_poche_tuiles(poche->tab_tuile);

    distribution_initiale_tuiles_aux_joueurs(poche, etat_du_jeu->tab_tuiles_j1, etat_du_jeu->tab_tuiles_j2, etat_du_jeu->tab_tuiles_j3, etat_du_jeu->tab_tuiles_j4);
    copier_etat(etat_du_jeu, etat_du_jeu_precedent);

    SDL_Color couleur_font = { 113, 108, 180 }; //bleu
    SDL_Color couleur_font_1 = { 240, 134, 80 }; //orange
    SDL_Color couleur_font_2 = { 237, 28, 36 }; //rouge


    ecrire_dans_rectangle(renderer, font_nom_joueurs, tab_joueurs[0].pseudo, &tabNoms[0], couleur_font);
    ecrire_dans_rectangle(renderer, font_nom_joueurs, tab_joueurs[1].pseudo, &tabNoms[1], couleur_font);
    ecrire_dans_rectangle(renderer, font_nom_joueurs, tab_joueurs[2].pseudo, &tabNoms[2], couleur_font);
    ecrire_dans_rectangle(renderer, font_nom_joueurs, tab_joueurs[3].pseudo, &tabNoms[3], couleur_font);

    strcpy(message_notification, " Tour de ");
    strcat(message_notification, tab_joueurs[0].pseudo);

    ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_1);

    transcription_etat_jeu_vers_graphique(renderer, etat_du_jeu, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);
    
    SDL_RenderPresent(renderer);

    // for(int i=0 , c=0 ; i<5 && c<106; i++){
    //    for(int j=0 ; j<30 && c<106 ; j++){
    //         tab_tuiles_plateau[i][j] = poche[c] ;
    //         c++ ;
    //     }
    // }

    // tabTuiles_vers_graphique(renderer, tab_tuiles_plateau, 5, 30, 3, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

    while(prog_en_cours){

        while (SDL_PollEvent(&evenement)){
            
            switch (evenement.type){

                case SDL_MOUSEMOTION:

                    if(num_gagnant == 0){

                        surbrillance_rectangle(renderer, trouver_numero_rectangle( evenement.motion.x, evenement.motion.y, tour), num_rect_clique , tabBtns, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
                        SDL_RenderPresent(renderer);
                    }

                    break;

                case SDL_MOUSEBUTTONDOWN:

                    num_rect_clique = trouver_numero_rectangle( evenement.button.x, evenement.button.y, tour) ;

                    if(num_gagnant == 0){

                        surbrillance_rectangle_selectionne(renderer, num_rect_clique , tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
                        printf("Vous avez clique le rectangle : %d\n", num_rect_clique );

                    }
                    

                    if(evenement.button.button == SDL_BUTTON_LEFT){

                        if(num_gagnant != 0){
                            if(num_rect_clique == 334){
                                

                                free(etat_du_jeu);
                                free(etat_du_jeu_precedent);
                                free(poche);
                                return 0 ;
                            }
                        }

                        else if(num_rect_clique == 331){

                            if(poche->pos_prochain != 106){

                                piocher_tuile(tour, poche, etat_du_jeu_precedent);
                                copier_etat(etat_du_jeu_precedent, etat_du_jeu);

                                incrementer_tour(&tour) ;

                                SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                SDL_RenderFillRect(renderer, &notifications);

                                strcpy(message_notification, " Tour de ");
                                strcat(message_notification, tab_joueurs[tour-1].pseudo);
                                ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_1);

                                num_rect_clique_prec = 0;
                                num_rect_clique = 0;

                                transcription_etat_jeu_vers_graphique(renderer, etat_du_jeu, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);
                                
                            }

                            else{
                                num_gagnant = 5 ;

                                SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                SDL_RenderFillRect(renderer, &notifications);

                                strcpy(message_notification, "Plus de TUILES !!");
                                ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_1);

                                affichage_score(renderer, etat_du_jeu, tab_joueurs, num_gagnant, font_nom_joueurs, font_notif_normale, tab_textures_sp);

                                SDL_RenderPresent(renderer);
                            }
                        }

                        else if(num_rect_clique == 332){
                            
                            //je refais
                            printf("\nVous avez cliquez sur je refaiskkkk !");

                            if(comparaison_etats(etat_du_jeu, etat_du_jeu_precedent) == 1){

                                SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                SDL_RenderFillRect(renderer, &notifications);

                                strcpy(message_notification, "Jouez ou piochez !");
                                ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_2);

                            }
                            
                            else {

                                copier_etat(etat_du_jeu_precedent, etat_du_jeu);
                                transcription_etat_jeu_vers_graphique(renderer, etat_du_jeu, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

                            }
                            
                            

                            //copier et1 das et2
                            // copier_etat(etat_du_jeu_precedent, etat_du_jeu);

                            // transcription_etat_jeu_vers_graphique(renderer, etat_du_jeu, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

                        }

                        else if(num_rect_clique == 333){

                            if(evenement.button.clicks >= 2){
                                return 0 ;
                            }

                        }

                        else if(num_rect_clique == 334){
                            
                            //On verifie aussi si le joueur a jouer si non il doit forcement piocher !!!

                            if(comparaison_etats(etat_du_jeu, etat_du_jeu_precedent) == 1){

                                SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                SDL_RenderFillRect(renderer, &notifications);

                                strcpy(message_notification, "Jouez ou piochez !");
                                ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_2);
                            }
                            //if( validation(etat_du_jeu->tab_tuiles_plateau, tour , &appel) == 0){ // qd la validation vaut 1 
                            else if( validation_NOONMAN(etat_du_jeu->tab_tuiles_plateau, &t1, &t2, &t3, &t4, &somme_prec, tour) == 1 ){

                                num_gagnant = tchecker_fin_du_jeu(etat_du_jeu);

                                if(num_gagnant == 0){

                                    incrementer_tour(&tour) ;

                                    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                    SDL_RenderFillRect(renderer, &notifications);

                                    strcpy(message_notification, " Tour de ");
                                    strcat(message_notification, tab_joueurs[tour-1].pseudo);
                                    ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_1);

                                    //on coupie aussi l'etat du jeu dans etat precedent

                                    copier_etat(etat_du_jeu, etat_du_jeu_precedent);

                                    num_rect_clique_prec = 0;
                                    num_rect_clique = 0;

                                }else{
                                    printf("Notre gagant est le JOUEUR %d", num_gagnant);

                                    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                    SDL_RenderFillRect(renderer, &notifications);

                                    strcpy(message_notification, "On a un GAGNANT !!");
                                    ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_1);

                                    affichage_score(renderer, etat_du_jeu, tab_joueurs, num_gagnant, font_nom_joueurs, font_notif_normale, tab_textures_sp);

                                    //afficher les score pour verifier

                                    SDL_RenderPresent(renderer);
                                }

                            }else{

                                SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE);
                                SDL_RenderFillRect(renderer, &notifications);

                                strcpy(message_notification, " Stop faux jeu !!");
                                ecrire_dans_rectangle(renderer, font_nom_joueurs, message_notification, &notifications, couleur_font_2);

                            }
                        }else{

                            surbrillance_rectangle_selectionne(renderer, num_rect_clique , tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);

                            if(num_rect_clique_prec == 0){
                                num_rect_clique_prec = num_rect_clique ;
                            }
                            else{

                                deplacer_tuile (etat_du_jeu->tab_tuiles_j1, etat_du_jeu->tab_tuiles_j2, etat_du_jeu->tab_tuiles_j3, etat_du_jeu->tab_tuiles_j4, etat_du_jeu->tab_tuiles_plateau, num_rect_clique_prec,  num_rect_clique);
                                //tabTuiles_vers_graphique(renderer, etat_du_jeu->tab_tuiles_j1, 3, 15, 1, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);
    
                                transcription_etat_jeu_vers_graphique(renderer, etat_du_jeu, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);
                                //surbrillance_rectangle_selectionne(renderer, num_rect_clique , tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central);
                                num_rect_clique_prec = 0;
                                num_rect_clique = 0;
                            }
                        }
                        
                    }
                    else if(evenement.button.button == SDL_BUTTON_RIGHT){
                        
                        if(num_gagnant != 0){

                            if(num_rect_clique == 334){


                                free(etat_du_jeu);
                                free(etat_du_jeu_precedent);
                                free(poche);
                                return 0 ;
                            }

                        }

                        else if( (num_rect_clique>=91) && (num_rect_clique<=240) ){

                            int i = 0 ;
                            int j = 0 ;

                            num_vers_coordonnees(num_rect_clique-90, 30, &i, &j);

                            decallage(etat_du_jeu->tab_tuiles_plateau, i, j, num_rect_clique);

                            transcription_etat_jeu_vers_graphique(renderer, etat_du_jeu, tabRect_J1, tabRect_J2, tabRect_J3, tabRect_J4, tabRect_central, tab_textures_tuiles_noires, tab_textures_tuiles_vertes, tab_textures_tuiles_jaunes, tab_textures_tuiles_rouges, tab_textures_carres_noires, tab_textures_carres_vertes, tab_textures_carres_jaunes, tab_textures_carres_rouges, tab_textures_sp);

                        }

                        else{}
                        
                    }
                    else{}

                    SDL_RenderPresent(renderer);
                    break;

                case SDL_QUIT:
                    return 1 ;
                    break;
            
                default:
                    break;
            }

        }
    }

    return 0 ;
    
}


//********************************************** LES FONCTIONS DE L'AVANT JEU *********************************************************

JOUEUR *creer_joueur (char *pseudo, int score){
    JOUEUR *joueur = NULL;
    joueur = (JOUEUR *) malloc(sizeof(JOUEUR));
    strcpy(joueur->pseudo, pseudo);
    joueur->score = score;
    return joueur;
}

void chargement(JOUEUR *tabJoueurs, int nombre_max){
    FILE *fichier = NULL;
    JOUEUR *joueur = NULL;
    JOUEUR listeJoueurs [150] = {0};
    char pseudo[9];
    int score = 0, i=0;
    fichier = fopen("fichier/scores.txt", "r+");
    if(fichier == NULL){
        printf("\n Erreur de lecture du fichier...");
    }else{
        while(fscanf(fichier, "%s %d", pseudo, &score) != EOF && i < 150){
            joueur = NULL;
            joueur = creer_joueur(pseudo, score);
            listeJoueurs[i] = *joueur;
            i += 1;
        }
        fclose(fichier);
    }
    JOUEUR temp;
    for (int j = 1; j <= i; j++) {
        for (int k = 0; k < i-1 ; k++) {
            if(listeJoueurs[k].score < listeJoueurs[k+1].score){
                temp = listeJoueurs[k];
                listeJoueurs[k] = listeJoueurs[k+1];
                listeJoueurs[k+1] = temp;
            }
        }
    }
    for (int j = 0; j < nombre_max; j++) {
        tabJoueurs[j] = listeJoueurs[j];
    }
}

void enregistrement(JOUEUR *tabJoueurs, int nombre_max){
    FILE *fichier = NULL, *fichier_temp = NULL;
    char pseudo[9];
    JOUEUR tabJoueursCpy[4] = {0};
    int score = 0, i=0;
    fichier = fopen("fichier/scores.txt", "r");
    fichier_temp = fopen("fichier/scores_tmp.txt", "a");
    int k=0;
    if(fichier == NULL){
        printf("\n Erreur de lecture du fichier...");
    }else{
        while(fscanf(fichier, "%s %d", pseudo, &score) != EOF ){
            for (int j = 0; j < nombre_max; j++) {
                if(strcmp(pseudo, tabJoueurs[j].pseudo) == 0){
                    score += tabJoueurs[j].score;
                    tabJoueursCpy[k] = tabJoueurs[j];
                    k++;
                    break;
                }
            }
            fprintf(fichier_temp, "%s %d\n", pseudo, score);
            i += 1;
        }
        printf(" k : %d\n", k);
        for (int j = 0; j < nombre_max; j++) {
            int l = 0, trouve = 0;
            do{
                if(strcmp(tabJoueurs[j].pseudo, tabJoueursCpy[l].pseudo) == 0){
                    trouve = 1;
                }
                l++;
            }while(l<k && trouve == 0);
            printf(" trouve : %d\n", trouve);
            if(trouve == 0){
                fprintf(fichier_temp, "%s %d\n", tabJoueurs[j].pseudo, tabJoueurs[j].score);
            }
        }
        fclose(fichier);
        fclose(fichier_temp);
        remove("fichier/scores.txt");
        rename("fichier/scores_tmp.txt", "fichier/scores.txt");
    }
}


void supprimer_dernier_caractere(char *chaine){
     chaine[strlen(chaine)-1] = '\0';
}

void supprimer_derniere_caractere_chaines(char * chaine1, char *chaine2, char *chaine3, char *chaine4, int *position){
    switch(*position){
        case 1:
            if(strlen(chaine1)>0){
                supprimer_dernier_caractere(chaine1);
            }
            break;
        case 2:
            if(strlen(chaine1)>0){
                supprimer_dernier_caractere(chaine2);
            }
            break;
        case 3:
            if(strlen(chaine1)>0){
                supprimer_dernier_caractere(chaine3);
            }
            break;
        case 4:
            if(strlen(chaine1)>0){
                supprimer_dernier_caractere(chaine4);
            }
            break;
        default:
            break;
    }
}

void modifier_chaines(char car, char * chaine1, char *chaine2, char *chaine3, char *chaine4, int *position){
    switch(*position){
        case 1:
            if(strlen(chaine1)<9){
                strcat(chaine1, &car);
            }
            break;
        case 2:
            if(strlen(chaine2)<9){
                strcat(chaine2, &car);
            }
            break;
        case 3:
            if(strlen(chaine3)<9){
                strcat(chaine3, &car);
            }
            break;
        case 4:
            if(strlen(chaine4)<9){
                strcat(chaine4, &car);
            }
            break;
        default:
            break;
    }
}





void deplacer_curseur(int* cuseur, int indice, SDL_Rect* rect_cur){

    if(indice == (-1)){

        if(*cuseur > 1){
            *cuseur = *cuseur - 1 ;
            rect_cur->y = rect_cur->y - 51 ;
        }

    }

    else if( indice == 1){

        if(*cuseur < 4){
            *cuseur = *cuseur + 1 ;
            rect_cur->y = rect_cur->y + 51 ;
        }

    }

    else{}
}



int avant_jeu(SDL_Renderer *renderer, JOUEUR tab_joueurs[4], TTF_Font *font1, TTF_Font *font2, SDL_Texture* tab_textures_sp[21]){

    JOUEUR top_joueurs[5];

    SDL_Rect arriere_plan ;
    SDL_Rect arriere_plan2 ;
    SDL_Rect rummikub ;
    SDL_Rect rkb_icone ;
    SDL_Rect rkb_icone2 ;
    SDL_Rect info ;
    SDL_Rect info2 ;
    SDL_Rect top ;
    SDL_Rect cadre ;
    SDL_Rect isty ;
    SDL_Rect noms_realisateurs ;
    
    SDL_Rect r1 ;
    SDL_Rect r2 ;
    SDL_Rect r3 ;
    SDL_Rect r4 ;

    SDL_Rect p1 ;
    SDL_Rect p2 ;
    SDL_Rect p3 ;
    SDL_Rect p4 ;

    SDL_Rect rect_record1 ;
    SDL_Rect rect_record2 ;
    SDL_Rect rect_record3 ;
    SDL_Rect rect_record4 ;
    SDL_Rect rect_record5 ;

    SDL_Rect btn_commencer ;
    SDL_Rect btn_quitter ;

    SDL_Rect image_gauche ;

    SDL_Rect rect_cur ;

    SDL_bool avant_jeu_en_cours = SDL_TRUE ;
    SDL_Event evenement ;
    int position_curseur = 1;

    SDL_Color bleu = { 113, 108, 180 }; //bleu
    SDL_Color orange = { 240, 134, 80 }; //orange

    char pseudo1[15];
    char pseudo2[15];
    char pseudo3[15];
    char pseudo4[15];

    char record1[15] ;
    char record2[15] ;
    char record3[15] ;
    char record4[15] ;
    char record5[15] ;

    strcpy(pseudo1, "");
    strcpy(pseudo2, "");
    strcpy(pseudo3, "");
    strcpy(pseudo4, "");

    strcpy(record1, "");
    strcpy(record2, "");
    strcpy(record3, "");
    strcpy(record4, "");
    strcpy(record5, "");

    strcpy(top_joueurs[0].pseudo, "");
    strcpy(top_joueurs[1].pseudo, "");
    strcpy(top_joueurs[2].pseudo, "");
    strcpy(top_joueurs[3].pseudo, "");
    strcpy(top_joueurs[4].pseudo, "");

    arriere_plan.x = 0 ;
    arriere_plan.y = 0 ;
    arriere_plan.h = HAUTEUR_F;
    arriere_plan.w = LARGEUR_F ;

    arriere_plan2.x = 400 ;
    arriere_plan2.y = 355 ;
    arriere_plan2.h = 240 ;
    arriere_plan2.w = 500 ;

    cadre.x = 380 ;
    cadre.y = 270 ;
    cadre.h = 80 ;
    cadre.w = 1140 ;

    info.x = 410 ;
    info.y = 280 ;
    info.h = 50 ;
    info.w = 600 ;

    info2.x = 410 ;
    info2.y = 310 ;
    info2.h = 50 ;
    info2.w = 600 ;

    isty.x = 1230 ;
    isty.y = 882 ;
    isty.h = 50 ;
    isty.w = 188 ;

    noms_realisateurs.x = 120 ;
    noms_realisateurs.y = 893 ;
    noms_realisateurs.h = 30;
    noms_realisateurs.w = 900 ;

    top.x = 990 ;
    top.y = 380 ;
    top.h = 50 ;
    top.w = 526 ;

    rect_record1.x = 1050 ;
    rect_record1.y = 445 ;
    rect_record1.h = 40 ;
    rect_record1.w = 500 ;

    rect_record2.x = 1050 ;
    rect_record2.y = 485 ;
    rect_record2.h = 40 ;
    rect_record2.w = 500 ;

    rect_record3.x = 1050 ;
    rect_record3.y = 525 ;
    rect_record3.h = 40 ;
    rect_record3.w = 500 ;

    rect_record4.x = 1050 ;
    rect_record4.y = 565 ;
    rect_record4.h = 40 ;
    rect_record4.w = 500 ;

    rect_record5.x = 1050 ;
    rect_record5.y = 605 ;
    rect_record5.h = 40 ;
    rect_record5.w = 500 ;


    r1.x = 570;
    r1.y = 375;
    r1.h = 50 ;
    r1.w = 300 ;

    p1.x = 410;
    p1.y = 382;
    p1.h = 50 ;
    p1.w = 99 ;

    r2.x = 570;
    r2.y = 427;
    r2.h = 50 ;
    r2.w = 300 ;

    p2.x = 410;
    p2.y = 434;
    p2.h = 50 ;
    p2.w = 99 ;

    r3.x = 570;
    r3.y = 479;
    r3.h = 50 ;
    r3.w = 300 ;

    p3.x = 410;
    p3.y = 486;
    p3.h = 50 ;
    p3.w = 99 ;

    r4.x = 570;
    r4.y = 531;
    r4.h = 50 ;
    r4.w = 300 ;

    p4.x = 410;
    p4.y = 538;
    p4.h = 50 ;
    p4.w = 99 ;

    btn_commencer.x = 410 ;
    btn_commencer.y = 620 ;
    btn_commencer.h = 50 ;
    btn_commencer.w = 455 ;

    btn_quitter.x = 410 ;
    btn_quitter.y = 685 ;
    btn_quitter.h = 50 ;
    btn_quitter.w = 455 ;

    image_gauche.x = 50 ;
    image_gauche.y = 80 ;
    image_gauche.h = 800 ;
    image_gauche.w = 300 ;

    rummikub.x = 400 ;
    rummikub.y = 80 ;
    rummikub.h = 174 ;
    rummikub.w = 691;

    rkb_icone.x = 1130 ;
    rkb_icone.y = 80 ;
    rkb_icone.h = 174 ;
    rkb_icone.w = 174 ;

    rkb_icone2.x = 1315 ;
    rkb_icone2.y = 88 ;
    rkb_icone2.h = 120;
    rkb_icone2.w = 120 ;

    rect_cur.x = 800 ;
    rect_cur.y = 368 ;
    rect_cur.h = 54 ;
    rect_cur.w = 54 ;


    // SDL_RenderFillRect(renderer, &tableau_score);
    //SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE);

    SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE) ;
    SDL_RenderFillRect(renderer, &arriere_plan);

    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[14], &image_gauche);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[15], &rect_cur);

    SDL_SetRenderDrawColor(renderer, 240, 134, 80, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawRect(renderer, &cadre);
    //SDL_RenderDrawRect(renderer, &isty);
    //SDL_RenderDrawRect(renderer, &top);

    SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE);

    ecrire_dans_rectangle(renderer, font2, "Utiliser les fleches * HAUT et BAS * , pour deplacer le curseur, et remplir tous les pseudos !", &info, bleu) ;
    ecrire_dans_rectangle(renderer, font2, "Tous les champs doivent etre remplis ! Ecrivez IA pour faire joueur l'Intelligence Artificielle !", &info2, bleu) ;
    ecrire_dans_rectangle(renderer, font2, "| Realise par : SEM Christopher - YAO Hippolyte - MOUMOU Youssef - PAVET Mathis - LATILA Francklin - KOUOKAM Steve", &noms_realisateurs, bleu) ;

    ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 1 : ", &p1, orange) ;
    ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 2 : ", &p2, orange) ;
    ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 3 : ", &p3, orange) ;
    ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 4 : ", &p4, orange) ;

    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[16], &btn_commencer);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[17], &btn_quitter);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[18], &rummikub);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[19], &rkb_icone);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[20], &rkb_icone2);
    mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[12], &isty);

    SDL_RenderDrawLine(renderer, 960, 370, 960, 790) ;

    SDL_RenderDrawRect(renderer, &rect_cur);

    chargement(top_joueurs, 5);//on creer ici une liste de meilleurs joueurs. S'ils existent, alors on les affichera dans un ordre croissant suivant le score de chacun

    if(strlen(top_joueurs[0].pseudo) != 0){

        mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[11], &top);
        sprintf(record1, "%s : %d", top_joueurs[0].pseudo, top_joueurs[0].score);
        ecrire_dans_rectangle(renderer, font1, record1, &rect_record1, bleu) ;

    }

    if(strlen(top_joueurs[1].pseudo) != 0){

        sprintf(record2, "%s : %d", top_joueurs[1].pseudo, top_joueurs[1].score);
        ecrire_dans_rectangle(renderer, font1, record2, &rect_record2, bleu) ;

    }

    if(strlen(top_joueurs[2].pseudo) != 0){

        sprintf(record3, "%s : %d", top_joueurs[2].pseudo, top_joueurs[2].score);
        ecrire_dans_rectangle(renderer, font1, record3, &rect_record3, bleu) ;

    }

    if(strlen(top_joueurs[3].pseudo) != 0){

        sprintf(record4, "%s : %d", top_joueurs[3].pseudo, top_joueurs[3].score);
        ecrire_dans_rectangle(renderer, font1, record4, &rect_record4, bleu) ;

    }

    if(strlen(top_joueurs[4].pseudo) != 0){

        sprintf(record5, "%s : %d", top_joueurs[4].pseudo, top_joueurs[4].score);
        ecrire_dans_rectangle(renderer, font1, record5, &rect_record5, bleu) ;

    }


    while(avant_jeu_en_cours){

        while (SDL_PollEvent(&evenement)){
            
            switch (evenement.type){

                case SDL_MOUSEBUTTONDOWN:
                    
                    if(evenement.button.x >=410 && evenement.button.x <= 865){

                        if(evenement.button.y >=620 && evenement.button.y <= 670){
                            //printf("Vous avez clique sur le btn COMMENCER !\n");

                            //on retourne 0 que si tous les pseudos sont entrés par l'utilisateur
                            strcpy(tab_joueurs[0].pseudo, pseudo1);
                            strcpy(tab_joueurs[1].pseudo, pseudo2);
                            strcpy(tab_joueurs[2].pseudo, pseudo3);
                            strcpy(tab_joueurs[3].pseudo, pseudo4);

                            if( (strlen(tab_joueurs[0].pseudo) != 0) && (strlen(tab_joueurs[1].pseudo) != 0) && (strlen(tab_joueurs[2].pseudo) != 0) && (strlen(tab_joueurs[3].pseudo) != 0)){
                                return 0 ;
                            }

                        }
                        
                        else if(evenement.button.y >=685 && evenement.button.y <= 735){
                            //printf("Vous avez clique sur le btn QUITTER !\n");
                            return 1 ;
                        }

                        else{}
                    }

                    break;

                case SDL_KEYDOWN: 

                    if(evenement.key.keysym.sym == SDLK_a){
                        //printf("A");
                        modifier_chaines('A', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_b){
                        //printf("B");
                        modifier_chaines('B', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_c){
                        //printf("C");
                        modifier_chaines('C', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_d){
                        //printf("D");
                        modifier_chaines('D', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_e){
                        //printf("E");
                        modifier_chaines('E', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_f){
                        //printf("F");
                        modifier_chaines('F', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_g){
                        //printf("G");
                        modifier_chaines('G', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_h){
                        //printf("H");
                        modifier_chaines('H', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_i){
                        //printf("I");
                        modifier_chaines('I', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_j){
                        //printf("J");
                        modifier_chaines('J', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_k){
                        //printf("K");
                        modifier_chaines('K', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_l){
                        //printf("L");
                        modifier_chaines('L', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_m){
                        //printf("M");
                        modifier_chaines('M', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_n){
                        //printf("N");
                        modifier_chaines('N', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_o){
                        //printf("O");
                        modifier_chaines('O', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_p){
                        //printf("P");
                        modifier_chaines('P', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_q){
                        //printf("Q");
                        modifier_chaines('Q', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_r){
                        //printf("R");
                        modifier_chaines('R', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_s){
                        //printf("S");
                        modifier_chaines('S', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_t){
                        //printf("T");
                        modifier_chaines('T', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_u){
                        //printf("U");
                        modifier_chaines('U', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_v){
                        //printf("V");
                        modifier_chaines('V', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_w){
                        //printf("W");
                        modifier_chaines('w', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_x){
                        //printf("X");
                        modifier_chaines('X', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_y){
                        //printf("Y");
                        modifier_chaines('Y', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_z){
                        //printf("Z");
                        modifier_chaines('Z', pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur) ;
                    }

                    else if(evenement.key.keysym.sym == SDLK_BACKSPACE){
                        //printf("<-");
                        supprimer_derniere_caractere_chaines(pseudo1, pseudo2, pseudo3, pseudo4, &position_curseur);
                    }

                    else if(evenement.key.keysym.sym == SDLK_UP){
                        //printf("fleche haut");
                        deplacer_curseur(&position_curseur, -1, &rect_cur);
                    }

                    else if(evenement.key.keysym.sym == SDLK_DOWN){
                        //printf("fleche bas");
                        deplacer_curseur(&position_curseur, 1, &rect_cur);
                    }

                    else{}

                    break;

                case SDL_QUIT:
                    return 1 ;
                    break;

                default :
                    break;

            }

            //On dessine maintenant nos chaines a l'ecran 

            SDL_SetRenderDrawColor(renderer, 255, 255, 253, SDL_ALPHA_OPAQUE) ;
            SDL_RenderFillRect(renderer, &arriere_plan2);

            ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 1 : ", &p1, orange) ;
            ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 2 : ", &p2, orange) ;
            ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 3 : ", &p3, orange) ;
            ecrire_dans_rectangle(renderer, font2, "Pseudo Joueur 4 : ", &p4, orange) ;

            ecrire_dans_rectangle(renderer, font1, pseudo1, &r1, bleu) ;
            ecrire_dans_rectangle(renderer, font1, pseudo2, &r2, bleu) ;
            ecrire_dans_rectangle(renderer, font1, pseudo3, &r3, bleu) ;
            ecrire_dans_rectangle(renderer, font1, pseudo4, &r4, bleu) ;

            mettre_une_texture_dans_un_rect(renderer, tab_textures_sp[15], &rect_cur);

            SDL_SetRenderDrawColor(renderer, 118,198,204, SDL_ALPHA_OPAQUE);

            SDL_RenderDrawLine(renderer, 570, 416, 778, 416) ;
            SDL_RenderDrawLine(renderer, 570, 469, 778, 469) ;
            SDL_RenderDrawLine(renderer, 570, 520, 778, 520) ;
            SDL_RenderDrawLine(renderer, 570, 572, 778, 572) ;

            SDL_RenderPresent(renderer);
        }

    }
















    return 0 ;
}
