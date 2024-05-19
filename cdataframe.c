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

void search_value(LISTE L,int value){
    LISTE temp = L;
    int faux = 0;
    while(temp != NULL){
        for (int i = 0; i < temp->colonne->taille_logique; i++){
            if (temp->colonne->data[i] == value) {
                printf("La valeur existe.\n");
                faux++;
            }
        }
        temp = temp->succ;
    }
    if(faux==0){
        printf("La valeur n'existe pas.\n");
    }
}

void afficher_titre(LISTE L){
    LISTE temp = L;
    int j=1;
    while(temp != NULL){
        printf("colonne[%d] = %s \n",j,((temp->colonne)->titre));
        j++;
        temp=temp->succ;
    }
}

void print_value_ligne(LISTE L){
    LISTE temp = L;
    int nblig=0;
    int j=1;
    while(temp != NULL){
        nblig = ligne_value(temp->colonne);
        printf("colonne[%d]=%d lignes\n",j,nblig);
        j++;
        temp=temp->succ;
    }
}


int print_value_colonne(LISTE L){
    LISTE temp = L;
    int nbcol = 1;
    temp = temp->succ;
    while (temp != NULL){
        nbcol++;
        temp = temp->succ;
    }
    return nbcol;
}

int egaliter_cellule_val(LISTE L,int value){
    LISTE temp = L;
    int eg=0;
    int egce=0;
    while(temp != NULL){
        eg = 0;
        eg = egaliter_value(temp->colonne, value);
        egce = egce + eg;
        temp = temp->succ;
    }

    return egce;
}

int bigger_cellule_val(LISTE L, int value){
    LISTE temp = L;
    int big=0;
    int bigce=0;
    while(temp != NULL){
        big = 0;
        big = bigger_value(temp->colonne, value);
        bigce = bigce + big;
        temp = temp->succ;
    }
    return bigce;
}

int lesser_cellule_val(LISTE L,int value){
    LISTE temp = L;
    int less=0;
    int lesce=0;
    while(temp != NULL){
        less = 0;
        less = lesser_value(temp->colonne, value);
        lesce = lesce + less;
        temp = temp->succ;
    }
    return lesce;
}
