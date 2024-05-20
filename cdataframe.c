//
// Created by 33782 on 26/04/2024.
//
#include "cdataframe.h"
// permet de crée un maillon
MAILLON* creer_maillon(COLUMN* colonne){
    MAILLON* new = (MAILLON*)malloc(sizeof (MAILLON));
    new->colonne=colonne;
    new->succ=NULL;
    return new;
}
// permet de vérifier si une liste est vide ou non
int liste_vide(LISTE L){
    if (L==NULL){
        return 1;
    }
    return 0;
}
// permet le remplissage du CDataframe à partir d'un saisies de l'utilisateurs
void ajouter_colonne_cdataframe(LISTE* L, COLUMN* colonne){
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
//permet de supprimer une colonne
void supprimer_colonne(LISTE *L, const char* nom){
    LISTE temp = *L;
    LISTE prec = NULL;

    while(temp != NULL){
        if(strcmp(temp->colonne->titre, nom) == 0){
            if(prec == NULL){
                *L = temp->succ;
                delete_column(temp->colonne);
                free(temp);
                printf("La colonne a bien ete supprimee.");
                return;
            }
            else{
                prec->succ = temp->succ;
                delete_column(temp->colonne);
                free(temp);
                printf("La colonne a bien ete supprimee.");
                return;
            }
        }
        prec = temp;
        temp = temp->succ;
    }
    printf("Erreur, veuillez reessayer.");
}
// permet  d'afficher tout le CDataframe
void print_cdataframe(LISTE L){
    LISTE temp = L;
    print_col(temp->colonne);
    temp=temp->succ;
    while (temp!=NULL){
        print_col(temp->colonne);
        temp=temp->succ;
    }
}
// permet d'afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur
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
// permet d'afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur
void print_colonne_cdataframe(LISTE L,int val){
    LISTE temp = L;
    print_col(temp->colonne);
    temp=temp->succ;
    for(int i=0;i<val-1;i++){
        print_col(temp->colonne);
        temp=temp->succ;
    }
}
// permet de vérifier l’existence d’une valeur dans le CDataframe
void search_value(LISTE L,int value){
    LISTE temp = L;
    int faux = 0;
    while(temp != NULL){
        for (int i = 0; i < temp->colonne->taille_logique; i++){
            if (temp->colonne->data[i] == value) {
                printf("La valeur existe.\n");
                faux++;
                return;
            }
        }
        temp = temp->succ;
    }
    if(faux==0){
        printf("La valeur n'existe pas.\n");
    }
}
// permet d'afficher le titre des colonnes
void afficher_titre(LISTE L){
    LISTE temp = L;
    int j=1;
    while(temp != NULL){
        printf("colonne[%d] = %s \n",j,((temp->colonne)->titre));
        j++;
        temp=temp->succ;
    }
}
// permet d'afficher le nombre de lignes
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

// permet d'afficher le nombre de colonnes
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
// permet d'avoir le nombre de cellules contenant une valeur egale a x
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
// permet d'avoir le nombre de cellules contenant une valeur superieur a x
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
// permet d'avoir le nombre de cellules contenant une valeur inferieur a x
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
//permet de changer le nom d'une colonne
void changer_nom_colonne(LISTE L,const char *nom,char *nouv_nom){
    LISTE temp = L;
    while(temp!=NULL){
        if(strcmp(nom, temp->colonne->titre) == 0){
            (temp->colonne)->titre = nouv_nom;
            printf("Le nom a bien ete change.\n");
            return;
        }
        temp=temp->succ;
    }
    printf("Erreur veuillez reessayer.\n");
}
//permet d'ajouter une ligne au CDataframe
void ajouter_ligne(LISTE L){
    LISTE temp=L;
    int valeur;
    int j=1;
    while(temp!=NULL) {
        for(int i=0;i<1;i++) {
            printf("Ajouter une valeur dans la colonne %d:", j);
            scanf("%d",&valeur);
            insert_value(temp->colonne,valeur);
            j++;
        }
        temp=temp->succ;
    }
}
//permet de supprimer une ligne
void supprimer_ligne(LISTE L,int ligne){
    LISTE temp = L;
    while(temp!=NULL){
        for(int i=0;i<ligne_value(temp->colonne);i++){
            if(i >= ligne-1) {
                ((temp->colonne)->data[i])=((temp->colonne)->data[i+1]);
            }
        }
        temp=temp->succ;
    }
}