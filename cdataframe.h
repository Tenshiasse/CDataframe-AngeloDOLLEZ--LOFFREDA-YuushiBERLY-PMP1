#ifndef CDATAFRAME_H
#define CDATAFRAME_H

typedef struct {
    char **columns;
    int num_columns;
    int num_rows;
    int **data;
} CDataframe;

CDataframe create_dataframe(int num_columns);
void fill_dataframe(CDataframe *df);
void fill_dataframe_hardcoded(CDataframe *df);
void print_dataframe(const CDataframe *df);
void display_partial_rows(const CDataframe *df, int limit);
void display_partial_columns(const CDataframe *df, int limit);
void add_row(CDataframe *df, int *values);
void delete_row(CDataframe *df, int row_index);
void add_column(CDataframe *df, const char *column_name);
void delete_column(CDataframe *df, int column_index);
void rename_column(CDataframe *df, int column_index, const char *new_name);
int search_value(const CDataframe *df, int value);
int get_value(const CDataframe *df, int row_index, int column_index);
void set_value(CDataframe *df, int row_index, int column_index, int value);
void display_column_names(const CDataframe *df);
int num_rows(const CDataframe *df);
int num_columns(const CDataframe *df);
int count_cells_equal(const CDataframe *df, int value);
int count_cells_greater(const CDataframe *df, int value);
int count_cells_lesser(const CDataframe *df, int value);

#endif