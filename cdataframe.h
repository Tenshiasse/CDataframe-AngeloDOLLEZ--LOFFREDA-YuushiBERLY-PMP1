#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct maillon
{
    COLUMN *colonne;
    struct maillon *succ;
};
/*-Définition du type maillon*/
typedef struct maillon MAILLON;
/*-Définition du type liste-*/
typedef MAILLON* LISTE;

MAILLON* creer_maillon(COLUMN*);
int liste_vide(LISTE);
void ajouter_colonne_cdataframe(LISTE*, COLUMN*);
void supprimer_colonne(LISTE L,const char* nom);
void print_cdataframe(LISTE);
void print_ligne_cdataframe(LISTE,int);
void print_colonne_cdataframe(LISTE L,int);

void search_value(LISTE L,int value);
void afficher_titre(LISTE L);
void print_value_ligne(LISTE L);
int print_value_colonne(LISTE);
int egaliter_cellule_val(LISTE L,int value);
int bigger_cellule_val(LISTE L, int value);
int lesser_cellule_val(LISTE L,int value);
void changer_nom_colonne(LISTE ,const char*,char*);
void ajouter_ligne(LISTE);
void supprimer_ligne(LISTE,int);
#endif