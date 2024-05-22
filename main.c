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

    //permet de tester en utilisant un CDataframe rempli en dur
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
        printf("\nInitialisation da la premiere colonne :");
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

        // test pour la parti CDataframe en dure
        LISTE L = NULL;
        L = creer_maillon(colone);
        ajouter_colonne_cdataframe(&L, coltwo);
        printf("\nAffichage du CDataFrame : ");

        print_cdataframe(L);
        printf("\nmaintenant, quelque fonction:\n");
        printf("\nOn affiche le CDataFrame jusqu'a la 3eme ligne :\n");
        print_ligne_cdataframe(L, 3);
        printf("\nOn affiche le CDataFrame jusqu'a la premiere colonne :");
        print_colonne_cdataframe(L, 1);
        printf("\nOn affiche le nombre de ligne dans chaque colonne :\n");
        print_value_ligne(L);
        printf("\nOn affiche le nom d'une colonne :\n");
        print_titre_colonne(colone);
        printf("\nOn recherche une valeur dans le CDataFrame :\n");
        search_value(L,54);
        printf("\nOn affiche le nom de toutes les colonnes :\n");
        afficher_titre(L);
        int nbcol=print_value_colonne(L);
        printf("\nIl y a %d colonne dans le CDataFrame\n",nbcol);
        int valeg= egaliter_cellule_val(L,54);
        printf("\nIl y a %d valeurs egale a 54 dans le CDataFrame\n",valeg);
        int valbig= bigger_cellule_val(L,54);
        printf("\nIl y a %d valeurs plus grandes que 54 dans le CDataFrame\n",valbig);
        int valess= lesser_cellule_val(L,54);
        printf("\nIl y a %d valeurs plus petites que 54 dans le CDataFrame\n",valess);
        printf("\nOn change le nom de la premiere colonne :\n");
        changer_nom_colonne(L,"column one","column ONE");
        printf("\nOn ajoute une ligne au CDataFrame :\n");
        ajouter_ligne(L);
        print_cdataframe(L);
        printf("\nOn supprime la deuxieme ligne du CDataFrame :\n");
        supprimer_ligne(L,2);
        print_cdataframe(L);
        printf("\nOn supprime la deuxieme colonne du CDataFrame:\n");
        supprimer_colonne(&L,"column two");
        print_cdataframe(L);

        //test pour la parti colonne
        printf("\nMaintenant les fonction pour les colonnes\n");
        int valsuge;
        valsuge = 0;
        int sugemenu = 0;
        printf("\nChoisissez ce que vous voulez:\n1 : chercher l'occurence \n2 : afficher la position d'une valeur \n3 : afficher le nombre de valeur superieur a une valeur donnee \n4 : afficher le nombre de valeur inferieur a une valeur donnee \n5 : le nombre de valeur egale a un chiffre donnee\n6 : si vou voulez rajouter une valeur dans la colonne \n7 : si vous voulez afficher la colonne\n8 : si vous avez fini\n");
        while (sugemenu != 8) {
            valsuge = 0;
            scanf("%d", &sugemenu);
            if (sugemenu == 1) {
                printf("Inserer un nombre dont on va chercher l'occurence");
                scanf("%d", &valsuge);
                printf("\nNombre d'occurences de %d: %d\n", valsuge, occurrences(colone, valsuge));
            }
            if (sugemenu == 2) {
                printf("Inserer un nombre dont on veut afficher la position");
                scanf("%d", &valsuge);
                printf("\nposition %d = %d\n", valsuge, get_value(colone, valsuge));
            }
            if (sugemenu == 3) {
                printf("Inserer un nombre dont on veut afficher le nombre de valeur superieur");
                scanf("%d", &valsuge);
                printf("\nIl y a %d valeurs plus grandes que %d \n", bigger_value(colone, valsuge), valsuge);
            }
            if (sugemenu == 4) {
                printf("Inserer un nombre dont on veut afficher le nombre de valeur inferieur");
                scanf("%d", &valsuge);
                printf("\nIl y a %d valeurs plus petites que %d \n", lesser_value(colone, valsuge), valsuge);
            }
            if (sugemenu == 5) {
                printf("Inserer un nombre dont on veut afficher le nombre de valeur egale");
                scanf("%d", &valsuge);
                printf("\nIl y a %d valeur egale a %d \n", egaliter_value(colone, valsuge), valsuge);
            }
            if (sugemenu == 6) {
                printf("Inserer la valeur que vous voulez rajouter dans la colonne");
                scanf("%d", &valsuge);
                insert_value(colone, valsuge);
            }
            if (sugemenu == 7){
                print_col(colone);
            }
            if (sugemenu == 8) {
                printf("Au revoir et bonne journee! :) ");
            }
        }
        delete_column(colone);
    }


    // permet de tester en utilisant une colonne fait par l'utilisateur
    if(suge==2){
        char naco;
        printf("\nDonner un nom a votre colonne:\n");
        scanf("%s",&naco);
        COLUMN *colthree = create_column(&naco);
        int val = 0;
        printf("\nInserer la premiere valeur de la colonne:\n");
        scanf("%d",&val);
        if(insert_value(colthree, val))
            printf("Value added successfully to %s \n",&naco);
        else
            printf("Error adding value to %s \n",&naco);

        int valtest;
        int sugemenu = 0;
        printf("\nChoisissez ce que vous voulez:\n1 : chercher l'occurence \n2 : afficher la position d'une valeur \n3 : afficher le nombre de valeur superieur a une valeur donnee \n4 : afficher le nombre de valeur inferieur a une valeur donnee \n5 : le nombre de valeur egale a un chiffre donnee\n6 : si vous voulez rajouter une valeur dans la colonne \n8 : si vous avez fini\n");
        while(sugemenu != 8){
            valtest=0;
            scanf("%d" ,&sugemenu);
            if(sugemenu == 1){
                printf("Inserer un nombre dont on va chercher l'occurence");
                scanf("%d" ,&valtest);
                printf("\nNombre d'occurences de %d: %d\n", valtest, occurrences(colthree, valtest));
            }
            if(sugemenu == 2){
                printf("Inserer un nombre dont on veut afficher la position");
                scanf("%d" ,&valtest);
                printf("\nPosition %d = %d\n", valtest, get_value(colthree, valtest));
            }
            if(sugemenu == 3){
                printf("Inserer un nombre dont on veut afficher le nombre de valeur superieur");
                scanf("%d" ,&valtest);
                printf("\nIl y a %d valeurs plus grandes que %d \n", bigger_value(colthree, valtest), valtest);
            }
            if(sugemenu == 4){
                printf("Inserer un nombre dont on veut afficher le nombre de valeur inferieur");
                scanf("%d" ,&valtest);
                printf("\nIl y a %d valeurs plus petites que %d \n", lesser_value(colthree, valtest), valtest);
            }
            if(sugemenu == 5){
                printf("Inserer un nombre dont on veut afficher le nombre de valeur egale");
                scanf("%d" ,&valtest);
                printf("\nIl y a %d valeur egale a %d \n", egaliter_value(colthree, valtest), valtest);
            }
            if(sugemenu == 6){
                printf("Inserer la valeur que vous voulez rajouter dans la colonne");
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