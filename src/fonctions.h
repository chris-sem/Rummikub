#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#include <string.h>

#define LARGEUR_F 1580 
#define HAUTEUR_F 953 
#define TITRE "Mon appli"

typedef struct {
    int valeur ;
    char couleur ;
} TUILE ;

typedef struct {
    TUILE tab_tuile [106] ;
    int pos_prochain ; //prochaine tuile à prendre
} POCHE_TUILES ;

typedef struct {
    char pseudo[15] ;
    int score ;
} JOUEUR ;

typedef struct{
    TUILE tab_tuiles_j1[5][30] ;
    TUILE tab_tuiles_j2[5][30] ;
    TUILE tab_tuiles_j3[5][30] ;
    TUILE tab_tuiles_j4[5][30] ;
    TUILE tab_tuiles_plateau[5][30] ;
} ETAT ;

void bonjour();

void Erreur_Rencontee(char *message);

void dessiner_rects(SDL_Rect tabRect[150], SDL_Renderer *renderer, int x_depart, int y_depart, int ecart_x, int ecart_y, int hauteur, int largeur, int nbre_colonne, int taille_tab);

void preparation_plateau_jeu(SDL_Renderer *renderer, SDL_Rect tabRect1[150], SDL_Rect tabRect2[150], SDL_Rect tabRect3[150], SDL_Rect tabRect4[150], SDL_Rect tabRect5[150], SDL_Rect tabRect6[150], SDL_Rect tabRect7[150], SDL_Rect *notifications, SDL_Texture* tab_textures_sp[10]);

int creer_tab_textures(SDL_Renderer *renderer, SDL_Texture* tab_textures[13], char c_pour_carre_OU_t_pour_tuile, char prem_lettre_de_la_couleur);

int charger_toutes_les_texture(SDL_Renderer *renderer, SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[21]);

void mettre_une_texture_dans_un_rect(SDL_Renderer *renderer, SDL_Texture* texture, SDL_Rect* rect);

void dessiner_dans_un_rectagle(SDL_Renderer *renderer, int num_a_afficher, char prem_lettre_couleur, int num_du_rectangle, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150], SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[10]);

int trouver_numero_rectangle_aux(int x, int y, int x_pointe, int y_pointe, int largeur, int hateur, int colonne);

int trouver_numero_rectangle(int x_pointe, int y_pointe, int tour);

void surbrillance_rectangle(SDL_Renderer *renderer, int num_rectangle, int num_rectangle_a_eviter, SDL_Rect tabBtns[4], SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150]);

void surbrillance_rectangle_selectionne(SDL_Renderer *renderer, int num_rectangle, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150]);

void ecrire_dans_rectangle(SDL_Renderer *renderer, TTF_Font *font, char mot[30], SDL_Rect *cadre, SDL_Color couleur_font);

void initialisation_tableau_tuile(TUILE tabTuiles[5][30], int ligne, int colonne);

void initialisation_tableaux_tuiles_du_jeu(TUILE tab_tuiles_j1[5][30], TUILE tab_tuiles_j2[5][30], TUILE tab_tuiles_j3[5][30], TUILE tab_tuiles_j4[5][30], TUILE tab_tuiles_plateau[5][30]);

void tabTuiles_vers_graphique(SDL_Renderer *renderer, TUILE tabTuiles[5][30], int ligne, int colonne, int indice, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150], SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[10]);

int nombre_de_zero_a_(int n);

void creer_tab_106_tuiles(TUILE t1[106]);

void generation_poche_tuiles(TUILE tab[106]);

int jouer(SDL_Renderer *renderer, JOUEUR tab_joueurs[4], TTF_Font *font_nom_joueurs, TTF_Font *font_notif_normale, TTF_Font *font_notif_erreur, SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[21] );

void distribution_initiale_tuiles_aux_joueurs(POCHE_TUILES *poche, TUILE tab_tuiles_j1[5][30], TUILE tab_tuiles_j2[5][30], TUILE tab_tuiles_j3[5][30], TUILE tab_tuiles_j4[5][30] );

TUILE distribuer_tuile(POCHE_TUILES *poche);

void transcription_etat_jeu_vers_graphique(SDL_Renderer *renderer, ETAT* etat_du_jeu, SDL_Rect tabRect_J1[45], SDL_Rect tabRect_J2[45], SDL_Rect tabRect_J3[45], SDL_Rect tabRect_J4[45], SDL_Rect tabRect_central[150], SDL_Texture* tab_textures_tuiles_noires[13], SDL_Texture* tab_textures_tuiles_vertes[13], SDL_Texture* tab_textures_tuiles_jaunes[13], SDL_Texture* tab_textures_tuiles_rouges[13], SDL_Texture* tab_textures_carres_noires[13], SDL_Texture* tab_textures_carres_vertes[13], SDL_Texture* tab_textures_carres_jaunes[13], SDL_Texture* tab_textures_carres_rouges[13], SDL_Texture* tab_textures_sp[10]);

void piocher_tuile(int tour, POCHE_TUILES *poche, ETAT *etat_du_jeu);

void incrementer_tour(int *tour);

void num_vers_coordonnees(int num, int nbre_colonne, int *x, int *y);

void deplacer_tuile ( TUILE tab_tuiles_j1[5][30], TUILE tab_tuiles_j2[5][30], TUILE tab_tuiles_j3[5][30], TUILE tab_tuiles_j4[5][30], TUILE tab_tuiles_plateau[5][30], int num_rect_depart, int num_rect_final);

int tchecker_fin_du_jeu(ETAT *etat_du_jeu);

void calculer_les_score(ETAT *etat_du_jeu, JOUEUR tab_joueurs[4], int *indice_gagnant);

void affichage_score( SDL_Renderer *renderer, ETAT *etat_du_jeu, JOUEUR tab_joueurs[4], int num_gagnant, TTF_Font *font_notif_normale, TTF_Font *font_notif_normale_2, SDL_Texture* tab_textures_sp[20] );

int avant_jeu(SDL_Renderer *renderer, JOUEUR tab_joueurs[4], TTF_Font *font1, TTF_Font *font2, SDL_Texture* tab_textures_sp[21]);

void supprimer_dernier_caractere(char *chaine);

void supprimer_derniere_caractere_chaines(char * chaine1, char *chaine2, char *chaine3, char *chaine4, int *position);

void modifier_chaines(char car, char * chaine1, char *chaine2, char *chaine3, char *chaine4, int *position);

void deplacer_curseur(int* cuseur, int indice, SDL_Rect* rect_cur);

JOUEUR *creer_joueur (char *pseudo, int score);

void chargement(JOUEUR *tabJoueurs, int nombre_max);

void enregistrement(JOUEUR *tabJoueurs, int nombre_max);

int comparaison_etats(ETAT* etat1, ETAT* etat2);

int nombre_tuiles_non_vide(TUILE tab[5][30], int ligne, int colonne);

void decallage(TUILE plateau[5][30], int ligne, int colonne, int num_rect_arret);

///////////////// validation //////////////////

int somme_tuiles_plateau(TUILE plateau[5][30]) ;

int somme_magique(TUILE tab[150]);

int tcheck_joker(TUILE tab[150], int debut, int fin);

int sens_bloc(TUILE tab[150], int debut, int fin);

int indice_prem_valeur_different_de_joker(TUILE tab[150], int debut, int fin);

int somme_normale(TUILE tab[150], int debut, int fin);

int somme_avec_joker_sens_un(TUILE tab[150], int debut, int fin);

int somme_avec_joker_sens_deux(TUILE tab[150], int debut, int fin);

int fin_de_bloc(TUILE tab[150], int debut);

int validation_bloc_sens_un(TUILE tab[150], int debut, int fin);

int validation_bloc_sens_deux(TUILE tab[150], int debut, int fin);

int validation_simple(TUILE plateau[5][30]);

int validation_NOONMAN(TUILE plateau[5][30], int *t1, int *t2, int *t3, int *t4, int *somme_prec, int tour);

//////////////////////////////////////////////

#endif