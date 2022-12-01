#ifndef SUDOKU_STRUCT_H
#define SUDOKU_STRUCT_H



#include <stdlib.h>
#include <stdio.h>




typedef struct {
    int **matrice;
    int size;
} SudokuGrid;

typedef struct {
    int numberLig;
    int numberCol;
} Coordonnee;


#endif //SUDOKU_STRUCT_H
