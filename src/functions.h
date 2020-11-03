#ifndef functions_H
#define functions_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();

int checkLowercase(char *inputString);

void hangman(int attempt);

void replayGame(char decision[], int *decided, int *replay);

#endif
