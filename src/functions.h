#ifndef functions_H
#define functions_H

#define FALSE 0
#define TRUE 1
#define MAX_LENGTH 101

int checkLowercase(char* inputString);

void hangman(int attempt);

void replayGame(char decision[], int* decided, int* replay);

int ScanNumOfWords(int numOfWords);

int CreateArray(int i, char* wordList, int j);

int InputLetters(char letter[], int length);

int LetterCheck(
  int length, char word[], char letter[], int attempt, int checkArray[]);

void ChecktoWork(int length, int checkArray[], int workArray[]);

int SolvedLetterCheck(int length, int workStatus, int workArray[]);

#endif
