#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column.h"

COLUMN *create_column(const char *title){
    COLUMN *new_column = (COLUMN*)malloc(sizeof(COLUMN));

    new_column->titre = strdup(title);
    new_column->taille_physique = 0;
    new_column->taille_logique = 0;
    new_column->type_data = NULL;
    new_column->data = NULL;

    return new_column;
}

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

void delete_column(COLUMN *col){
    free(col->titre);
    free(col->data);
    free(col);
}

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

int occurrences(const COLUMN *column, int value){
    int count = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] == value) {
            count++;
        }
    }
    return count;
}

int get_value(const COLUMN *column, int position){
    if (position >= 0 && position < column->taille_logique){
        return column->data[position];
    }else{
        fprintf(stderr, "Position inccorect\n");
        exit(1);
    }}

int bigger_value(const COLUMN *column, int value){
    int count = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] > value) {
            count++;
        }}
    return count;
}
int lesser_value(const COLUMN *column, int value){
    int count = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] < value){
            count++;
        }
    }
    return count;
}

int egaliter_value(const COLUMN *column, int value){
    int count = 0;
    for (int i = 0; i < column->taille_logique; i++){
        if (column->data[i] == value) {
            count++;
        }
    }
    return count;
}