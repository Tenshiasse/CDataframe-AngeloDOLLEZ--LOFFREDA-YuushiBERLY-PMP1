#ifndef COLUMN_H
#define COLUMN_H

typedef struct {
    char *titre;
    int taille_physique;
    int taille_logique;
    char *type_data;
    int *data;
} COLUMN;

COLUMN *create_column(const char *title);
int insert_value(COLUMN *column, int value);
void delete_column(COLUMN *col);
void print_col(const COLUMN *column);
int occurrences(const COLUMN *column, int value);
int get_value(const COLUMN *column, int position);
int bigger_value(const COLUMN *column, int value);
int lesser_value(const COLUMN *column, int value);
int egaliter_value(const COLUMN *column, int value);

#endif