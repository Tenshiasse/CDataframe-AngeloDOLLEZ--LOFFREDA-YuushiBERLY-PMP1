//
// Created by 33782 on 26/04/2024.
//

#ifndef PROJET_TP_CV2_COLUMN_H
#define PROJET_TP_CV2_COLUMN_H

typedef struct{
    char* titre_colonne;
    int taille_physique = 0;
    int taille_logique = 0;
    int* valeur_tableau = NULL;
}COLONNE;

COLONNE * create_column(char* title);

#endif //PROJET_TP_CV2_COLUMN_H
