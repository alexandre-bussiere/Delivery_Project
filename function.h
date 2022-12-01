#ifndef SUDOKU_FUNCTION_H
#define SUDOKU_FUNCTION_H

#include <stdbool.h>
#include "gameMatrix.h"
#include "struct.h"

int securityInputInt(int borneMin, int borneMax); // verif

void printMatrice(SudokuGrid); // verif
void printMatriceWithMask(SudokuGrid , SudokuGrid ); // verif

SudokuGrid createSudoku(int); // verif

void fillMatrix(int **, int); // verif
void fillMaskRandom(int **, int, int); // verif
void fillMaskManual(int **, int, int); // verif

SudokuGrid createdUserSudokuGrid (SudokuGrid , SudokuGrid ); // verif
SudokuGrid createGameSudokuGrid (int); // verif
SudokuGrid createMaskSudokuGrid (int, int, int); // verif

Coordonnee askAndCheckUserCoordonnee(int); // verif
void playAMove(SudokuGrid , Coordonnee); // verif

bool isMatriceFull(SudokuGrid ); // verif
bool is_move_valide(int x, int y,int val,SudokuGrid grille);

SudokuGrid play_sudoku(SudokuGrid);
void Color(int couleurDuTexte, int couleurDeFond);
#endif //SUDOKU_FUNCTION_H
