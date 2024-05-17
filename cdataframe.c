//
// Created by 33782 on 26/04/2024.
//
#include "cdataframe.h"

MAILLON* creer_maillon(COLUMN* colonne){
    MAILLON* new = (MAILLON*)malloc(sizeof (MAILLON));
    new->colonne=colonne;
    new->succ=NULL;
    return new;
}

int liste_vide(LISTE L){
    if (L==NULL){
        return 1;
    }
    return 0;
}

void print_cdataframe(LISTE L){
    LISTE temp = L;
    print_col(temp->colonne);
    temp=temp->succ;
    while (temp!=NULL){
        print_col(temp->colonne);
        temp=temp->succ;
    }
}

void afficher_CData_Frame(){

}