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

void ajouter_queue_liste(LISTE* L, COLUMN* colonne){
    MAILLON* new = creer_maillon(colonne);
    if (liste_vide(*L)==1){
        *L=new;
    }
    else{
        LISTE temp = *L;
        while (temp->succ!=NULL){
            temp=temp->succ;
        }
        temp->succ=new;
    }
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

void print_ligne_cdataframe(LISTE L,int val) {
    LISTE temp = L;
    for (int i=0;i<val;i++){
        temp = L;
        printf("[%d]",i+1);
        while (temp!= NULL){
            if (((temp->colonne)->data) == NULL) {
                printf("NULL");
            }
            else{
                printf("-%d ",((temp->colonne)->data[i]));
            }
            temp=temp->succ;
        }
        printf("\n");
    }
}

void print_colonne_cdataframe(LISTE L,int val){
    LISTE temp = L;
    print_col(temp->colonne);
    temp=temp->succ;
    for(int i=0;i<val-1;i++){
        print_col(temp->colonne);
        temp=temp->succ;
    }
}

