#include "function.h"

void printMatrice(SudokuGrid matrice) {
    int i, j, size;
    int **truc;
    truc = matrice.matrice;
    size = matrice.size;
    printf("\t");
    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
    }
    printf("\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < size; j++) {
            if (truc[i][j] != -1) {
                printf("%d\t", truc[i][j]);
            } else{
                printf(" \t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printMatriceWithMask(SudokuGrid matrice, SudokuGrid mask) {
    int i, j, size;
    size = matrice.size;

    int **masque, **mat;
    mat = matrice.matrice;
    masque = mask.matrice;

    printf("\t");
    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < size; j++) {
            if (masque[i][j] == 1) {
                printf("%d\t", mat[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

