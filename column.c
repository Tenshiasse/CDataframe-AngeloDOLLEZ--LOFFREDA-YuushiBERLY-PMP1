#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"
// permet de crée une colonne
COLUMN *create_column(const char *title){
    COLUMN *new_column = (COLUMN*)malloc(sizeof(COLUMN));

    new_column->titre = strdup(title);
    new_column->taille_physique = 0;
    new_column->taille_logique = 0;
    new_column->type_data = NULL;
    new_column->data = NULL;

    return new_column;
}
// permet d'insérer une valeur dans une colonne
int insert_value(COLUMN *column, int value){
    if (column == NULL){
        printf("Column is NULL\n");
        return 0;
    }
    if (column->data == NULL){
        column->data = (int*)malloc(sizeof(int));
    }else{
        column->data = (int*)realloc(column->data, (column->taille_logique + 1) * sizeof(int));
    }
    if (column->data == NULL) {
        printf("Allocation memory error\n");
        exit(1);
    }

    column->data[column->taille_logique] = value;
    column->taille_logique++;

    return 1;
}
// permet de libérer l’espace allouée par une colonne
void delete_column(COLUMN *col){
    free(col->titre);
    free(col->data);
    free(col);
}
// permet d'afficher une colonne
void print_col(const COLUMN *column){
    if (column == NULL){
        printf("Auncune valeur dans la colonne\n");
        return;
    }

    for (int i = 0; i < column->taille_logique; i++){
        printf("\n[%d] %d ",i,column->data[i]);
    }
    printf("\n");
}
// permet de retourner le nombre de d’occurrences d’une valeur x
int occurrences(const COLUMN *column, int nb){
    int occva = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] == nb) {
            occva++;
        }
    }
    return occva;
}
// permet de retourner la valeur présente à la position x
int get_value(const COLUMN *column, int position){
    if (position >= 0 && position < column->taille_logique){
        return column->data[position];
    }else{
        printf("Position inccorect\n");
        exit(1);
    }}
// permet de retourner le nombre de valeurs qui sont supérieures à x
int bigger_value(const COLUMN *column, int value){
    int bigva = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] > value) {
            bigva++;
        }}
    return bigva;
}
//permet de retourner le nombre de valeurs qui sont inférieur à x
int lesser_value(const COLUMN *column, int value){
    int lesva = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] < value){
            lesva++;
        }
    }
    return lesva;
}
// permet de retourner le nombre de valeurs qui sont égales à x
int egaliter_value(const COLUMN *column, int value){
    int egva = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] == value) {
            egva++;
        }
    }
    return egva;
}
// permet de donner le nombre de valeur d'une colonne
int ligne_value(const COLUMN *column){
    int nblig= 0;
    for (int i = 0; i < column->taille_logique; i++){
        nblig++;

    }
    return nblig;
}
// permet de d'afficher le titre d'une colonne
void print_titre_colonne(COLUMN *colonne){
    printf("Titre de la colonne : %s\n", colonne->titre);
}