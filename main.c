#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"
int main() {
    int suge=0;
    do {
        printf("Voulez-vous sois:\n1 : Utilise une colonne deja initialise en dur?\n2 : Inserer vous meme les valeurs?\n");
        scanf("%d",&suge);
    }while(suge < 1 ||  suge > 2);


    if(suge==1) {
        COLUMN *colone = create_column("column one");
        int val1 = 34;
        if(insert_value(colone, val1))
            printf("Value added successfully to column one\n");
        else
            printf("Error adding value to column one\n");
        int val2 = 59;
        int val3 = 515;
        int val4 = 97;
        int val5 = 5;
        insert_value(colone, val2);
        insert_value(colone, val3);
        insert_value(colone, val4);
        insert_value(colone, val5);
        print_col(colone);

        COLUMN *coltwo = create_column("column two");
        int val9 = 5;
        if (insert_value(coltwo, val9))
            printf("Value added successfully to column two\n");
        else
            printf("Error adding value to column two\n");
        int val8 = 7;
        int val6 = 54;
        int val7 = 2;
        insert_value(coltwo, val8);
        insert_value(coltwo, val6);
        insert_value(coltwo, val7);

        print_col(colone);
        LISTE L = NULL;
        L = creer_maillon(colone);
        print_cdataframe(L);
        ajouter_queue_liste(&L, coltwo);
        print_ligne_cdataframe(L, 3);
        print_colonne_cdataframe(L, 1);

        int haha=ligne_value(colone);
        printf("colonne one = ligne de %d\n",haha);

        print_value_ligne(L);
        print_titre_colonne(colone);

        search_value(L,54);
        afficher_titre(L);
        int nbcol=print_value_colonne(L);
        printf("il y a %d colonne\n",nbcol);

        int valeg= egaliter_cellule_val(L,54);
        printf("il y a %d valeurs egale a 54\n",valeg);
        int valbig= bigger_cellule_val(L,54);
        printf("il y a %d valeurs plus grandes que 54\n",valbig);
        int valess= lesser_cellule_val(L,54);
        printf("il y a %d valeurs plus petites que 54\n",valess);


        int valsuge;
        valsuge = 0;
        int sugemenu = 0;
        printf("\nChoisissez ce que vous voulez:\n1 : chercher l'occurence \n2 : afficher la position d'une valeur \n3 : afficher le nombre de valeur superieur a une valeur donnee \n4 : afficher le nombre de valeur inferieur a une valeur donnee \n5 : le nombre de valeur egale a un chiffre donnee\n6 : si vou voulez rajouter une valeur dans la colonne \n8 : si vous avez fini\n");
        while (sugemenu != 8) {
            valsuge = 0;
            scanf("%d", &sugemenu);
            if (sugemenu == 1) {
                printf("inserer un nombre dont on va chercher l'occurence");
                scanf("%d", &valsuge);
                printf("\nnombre d'occurences de %d: %d\n", valsuge, occurrences(colone, valsuge));
            }
            if (sugemenu == 2) {
                printf("inserer un nombre dont on veut afficher la position");
                scanf("%d", &valsuge);
                printf("\nposition %d = %d\n", valsuge, get_value(colone, valsuge));
            }
            if (sugemenu == 3) {
                printf("inserer un nombre dont on veut afficher le nombre de valeur superieur");
                scanf("%d", &valsuge);
                printf("\nil y a %d valeurs plus grandes que %d \n", bigger_value(colone, valsuge), valsuge);
            }
            if (sugemenu == 4) {
                printf("inserer un nombre dont on veut afficher le nombre de valeur inferieur");
                scanf("%d", &valsuge);
                printf("\nil y a %d valeurs plus petites que %d \n", lesser_value(colone, valsuge), valsuge);
            }
            if (sugemenu == 5) {
                printf("inserer un nombre dont on veut afficher le nombre de valeur egale");
                scanf("%d", &valsuge);
                printf("\nil y a %d valeur egale a %d \n", egaliter_value(colone, valsuge), valsuge);
            }
            if (sugemenu == 6) {
                printf("inserer la valeur que vous voulez rajouter dans la colonne");
                scanf("%d", &valsuge);
                insert_value(colone, valsuge);
            }
            if (sugemenu == 8) {
                printf("Au revoir et bonne journee! :) ");
            }
        }
        delete_column(colone);
    }
    if(suge==2){
        char naco;
        printf("\nDonner un nom a votre colonne:\n");
        scanf("%s",&naco);
        COLUMN *colthree = create_column(&naco);
        int val = 0;
        printf("\nInserer la premiere valeur de la colonne:\n");
        scanf("%d",&val);
        if(insert_value(colthree, val))
            printf("Value added successfully to %s \n",naco);
        else
            printf("Error adding value to %s \n",naco);

        int valtest;
        int sugemenu = 0;
        printf("\nChoisissez ce que vous voulez:\n1 : chercher l'occurence \n2 : afficher la position d'une valeur \n3 : afficher le nombre de valeur superieur a une valeur donnee \n4 : afficher le nombre de valeur inferieur a une valeur donnee \n5 : le nombre de valeur egale a un chiffre donnee\n6 : si vous voulez rajouter une valeur dans la colonne \n8 : si vous avez fini\n");
        while(sugemenu != 8){
            valtest=0;
            scanf("%d" ,&sugemenu);
            if(sugemenu == 1){
                printf("inserer un nombre dont on va chercher l'occurence");
                scanf("%d" ,&valtest);
                printf("\nnombre d'occurences de %d: %d\n", valtest, occurrences(colthree, valtest));
            }
            if(sugemenu == 2){
                printf("inserer un nombre dont on veut afficher la position");
                scanf("%d" ,&valtest);
                printf("\nposition %d = %d\n", valtest, get_value(colthree, valtest));
            }
            if(sugemenu == 3){
                printf("inserer un nombre dont on veut afficher le nombre de valeur superieur");
                scanf("%d" ,&valtest);
                printf("\nil y a %d valeurs plus grandes que %d \n", bigger_value(colthree, valtest), valtest);
            }
            if(sugemenu == 4){
                printf("inserer un nombre dont on veut afficher le nombre de valeur inferieur");
                scanf("%d" ,&valtest);
                printf("\nil y a %d valeurs plus petites que %d \n", lesser_value(colthree, valtest), valtest);
            }
            if(sugemenu == 5){
                printf("inserer un nombre dont on veut afficher le nombre de valeur egale");
                scanf("%d" ,&valtest);
                printf("\nil y a %d valeur egale a %d \n", egaliter_value(colthree, valtest), valtest);
            }
            if(sugemenu == 6){
                printf("inserer la valeur que vous voulez rajouter dans la colonne");
                scanf("%d" ,&valtest);
                insert_value(colthree, valtest);
            }
            if(sugemenu == 8){
                printf("Au revoir et bonne journee! :) ");
            }
        }
        delete_column(colthree);
    }




    return 0;
}