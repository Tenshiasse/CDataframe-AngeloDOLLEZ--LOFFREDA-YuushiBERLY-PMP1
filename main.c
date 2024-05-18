#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"
int main() {
    COLUMN *mycol = create_column("My column");
    int val = 8;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    int val1 = 3;
    int val2 = 8;
    int val3 = 32;
    insert_value(mycol, val1);
    insert_value(mycol, val2);
    insert_value(mycol, val3);

    COLUMN *mycol2 = create_column("My column");
    int val4 = 5;
    if (insert_value(mycol2, val4))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    int val5 = 7;
    int val6 = 54;
    int val7 = 2;
    insert_value(mycol2, val5);
    insert_value(mycol2, val6);
    insert_value(mycol2, val7);

    print_col(mycol);
    printf("\noccurences de 5: %d",occurrences(mycol,5));
    printf("\nposition 1 = %d",get_value(mycol,1));
    printf("\nIl y a %d valeurs superieurs a 5",bigger_value(mycol,5));
    printf("\nIl y a %d valeurs inferieur a 10 ", lesser_value(mycol,10));
    printf("\nIl y %d valeurs egales a 6",egaliter_value(mycol,6));
    LISTE L = NULL;
    L=creer_maillon(mycol);
    print_cdataframe(L);
    ajouter_queue_liste(&L,mycol2);
    print_ligne_cdataframe(L,3);
    print_colonne_cdataframe(L,1);
    delete_column(mycol);



    return 0;
}