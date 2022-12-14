#include <ntdef.h>
#include <windows.h>
#include "function.h"

int securityInputInt(int borneMin, int borneMax) {
    int userValue;
    do {
        printf("Rentrez un entier entre %d et %d : ", borneMin, borneMax);
        scanf("%d", &userValue);
    } while ((userValue < borneMin) || (userValue > borneMax));
    return userValue;
}

void printMatrice(SudokuGrid matrice) {
    Color(15, 0);
    int i, j, size;
    int **truc;
    truc = matrice.matrice;
    size = matrice.size;
    printf("\t");
    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);
        if(i%3==2){
            printf("\t");
        }
    }
    printf("\n");
    printf("\t------------------------------------------------------------------------------------------\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", i + 1);

        for (j = 0; j < size; j++) {
            if (truc[i][j] != -1) {
                printf("%d\t", truc[i][j]);

            } else{
                Color(9, 0);
                printf("-\t");
                Color(15, 0);
            }
            if(j%3==2){
                printf("|\t");
            }
        }
        printf("\n");
        if(i%3==2){
            printf("\t------------------------------------------------------------------------------------------\n");
        }
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


SudokuGrid createSudoku(int size) {
    int i;
    SudokuGrid matrice;
    matrice.matrice = (int **) malloc(sizeof(int *) * size);
    for (i = 0; i < size; i++) {
        matrice.matrice[i] = malloc(sizeof(int) * size);
    }
    matrice.size = size;
    return matrice;
}


void fillMatrix(int **mat, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mat[i][j] = -1;
        }
    }
}

void fillMaskRandom(int **mat, int size, int numberOfCellShow) {
    int i, j, indexLig, indexCol;
    for (i = 0; i < numberOfCellShow; i++) {
        do {
            indexLig = rand() % size;
            indexCol = rand() % size;
        } while (mat[indexLig][indexCol] == 1);
        mat[indexLig][indexCol] = 1;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (mat[i][j] != 1) {
                mat[i][j] = 0;
            }
        }
    }
}

void fillMaskManual(int **mat, int size, int numberOfCellShow) {
    int i, j;
    Coordonnee coordonneeOfCell;
    for (i = 0; i < numberOfCellShow; i++) {
        do {
            printf("Saisir une coordonnee que vous souhaitez voir apparaitre: \n");
            coordonneeOfCell = askAndCheckUserCoordonnee(size);
        } while (mat[coordonneeOfCell.numberLig][coordonneeOfCell.numberCol] == 1);
        mat[coordonneeOfCell.numberLig][coordonneeOfCell.numberCol] = 1;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (mat[i][j] != 1) {
                mat[i][j] = 0;
            }
        }
    }
}

SudokuGrid createdUserSudokuGrid(SudokuGrid solutionMatrix, SudokuGrid maskMatrix) {
    SudokuGrid userTakusuGrid;
    int **mask;
    mask = maskMatrix.matrice;
    userTakusuGrid = createSudoku(solutionMatrix.size);
    int i, j;
    for (i = 0; i < solutionMatrix.size; i++) {
        for (j = 0; j < solutionMatrix.size; j++) {
            if (mask[i][j] == 1) {
                (userTakusuGrid.matrice[i][j]) = (solutionMatrix.matrice[i][j]);
            } else {
                (userTakusuGrid.matrice[i][j]) = -1;
            }
        }
    }
    return userTakusuGrid;
}

SudokuGrid createGameSudokuGrid(int size) {
    SudokuGrid gameGrid;
    gameGrid = createSudoku(size);
    int **grid;
    grid = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
    }
    createGrid9(grid);
    gameGrid.matrice = grid;
    return gameGrid;
}

SudokuGrid createMaskSudokuGrid(int size, int numberOfCellShow, int randOrManual) {
    SudokuGrid mask = createSudoku(size);
    if (randOrManual == 1) {
        fillMaskRandom(mask.matrice, size, numberOfCellShow);
    } else if (randOrManual == 2) {
        fillMaskManual(mask.matrice, size, numberOfCellShow);
    }
    return mask;
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

SudokuGrid play_sudoku(SudokuGrid grille){
    while (isMatriceFull(grille)==0){
        int x=securityInputInt(1,9)-1;
        int y=securityInputInt(1,9)-1;
        int val=securityInputInt(1,9);
        printf("\n");
        if (is_move_valide(x, y,val,grille)==1){
            grille.matrice[x][y]=val;
            printMatrice(grille);
        }
        printf("GG");
    }
    return grille;
}

bool is_move_valide(int x, int y,int val,SudokuGrid grille){
    SudokuGrid gridres;
    gridres = createGameSudokuGrid(9);
    if (gridres.matrice[x][y]!=val){
        return false;
    }
    if (gridres.matrice[x][y]==val){
        return true;
    }
    else{
        printf("The move is strange");
        exit(-1);
    }
}
void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}