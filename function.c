#include "function.h"

int securityInputInt(int borneMin, int borneMax) {
    int userValue;
    do {
        printf("Rentrez un entier entre %d et %d : ", borneMin, borneMax);
        scanf("%d", &userValue);
    } while ((userValue < borneMin) || (userValue > borneMax));
    return userValue;
}

Coordonnee askAndCheckUserCoordonnee(int size) {
    Coordonnee numberCase;
    int indexLig, indexCol;
    indexCol = securityInputInt(1, size);
    indexLig = securityInputInt(1, size);
    numberCase.numberLig = indexLig - 1;
    numberCase.numberCol = indexCol - 1;
    return numberCase;
}


void playAMove(SudokuGrid sudokuGrid, Coordonnee playMove) {
    int size = sudokuGrid.size, indexCol, indexLig;
    indexCol = playMove.numberCol;
    indexLig = playMove.numberLig;

    int **grid = sudokuGrid.matrice;
    grid[indexLig][indexCol] = securityInputInt(1, 9);
    sudokuGrid.matrice = grid;
}

bool isMatriceFull(SudokuGrid SudokuGrid) {
    int **grid = SudokuGrid.matrice, size = SudokuGrid.size;
    int i, j, counter = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j] != -1) {
                counter++;
            }
        }
    }
    if (counter == size * size) {
        return true;
    }
    return false;
}
