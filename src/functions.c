#include "functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
#define MAX_LENGTH 101

void replayGame(char decision[], int* decided, int* replay)
{
    if (decision[0] == 'y') {
        *decided = 1;
        *replay = 1;
        printf("\n\n");
    } else if (decision[0] == 'n') {
        *decided = 1;
        *replay = 0;
        printf("\n");
    } else {
        *decided = 0;
        *replay = 0;
        printf("Invalid input. Try again.\n\n");
    }
}

int checkLowercase(char* inputString)
{
    int counter = 0;
    while (counter < strlen(inputString)) {
        //ЕСЛИ СИМВОЛ НЕ НИЖНЕГО РЕГИСТРA ВЕРНУТЬ 0
        if (!('a' <= inputString[counter] && inputString[counter] <= 'z')) {
            return 0;
        } else {
            counter++;
        }
    }

    return 1;
}

void hangman(int attempt)
{
    if (attempt == 0) {
        printf(" _________\n");
        printf("|         \n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 1) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 2) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 3) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 4) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 5) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\\\n");
        printf("|         |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 6) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\\\n");
        printf("|         |\n");
        printf("|        / \n");
        printf("|       / \n");
        printf("|\n");
        printf("|_______\n");
    } else if (attempt == 7) {
        printf(" _________\n");
        printf("|         |\n");
        printf("|         |\n");
        printf("|        ---\n");
        printf("|       :^ ^:\n");
        printf("|        ---\n");
        printf("|         |\n");
        printf("|        /|\\\n");
        printf("|         |\n");
        printf("|        / \\\n");
        printf("|       /   \\\n");
        printf("|\n");
        printf("|_______\n\n");
    }
}

int ScanNumOfWords(int numOfWords)
{
    char numbs[MAX_LENGTH];
    printf("How many words? \n");

    while (1) {
        scanf("%s", numbs);
        if (isdigit(numbs[0])) {
            numOfWords = atoi(numbs);
            break;
        } else {
            printf("Incorrect input. Try again\n");
        }
    }
    return numOfWords;
}

int InputLetters(char letter[], int length)
{
    int check = 0;
    printf("=========================================\n");
    printf("The word contains %d letters.\n", length);
    printf("Enter a letter: ");

    while (1) {
        scanf("%s", &letter[0]);
        if ((int)strlen(letter) < 100) {
            printf("You entered: %c\n", letter[0]);
            break;
            check = 1;
        } else {
            printf("You entered too much letters, try again.\n");
            check = 1;
        }
    }
    return check;
}

int LetterCheck(
        int length, char word[], char letter[], int attempt, int checkArray[])
{
    int unsolvedLetters = 0;
    //ПРОВЕРКА БУКВЫ В СЛОВЕ
    for (int counter = 0; counter < length; counter++) {
        if (word[counter] == letter[0]) {
            checkArray[counter] = 1;
        } else {
            checkArray[counter] = 0;
            unsolvedLetters++;
        }
    }
    if (unsolvedLetters == length) {
        attempt++;
    }
    return attempt;
}

void ChecktoWork(int length, int checkArray[], int workArray[])
{
    int counter = 0;
    while (counter < length) {
        if ((checkArray[counter] == 0) && (workArray[counter] == 0)) {
            workArray[counter] = 0;
        } else {
            workArray[counter] = 1;
        }
        counter++;
    }

    for (counter = 0; counter < length; counter++) {
        checkArray[counter] = 0;
    }
}

int SolvedLetterCheck(int length, int workStatus, int workArray[])
{
    //ПРОВЕРКА НАЙДЕННЫХ БУКВ
    int solvedLetters = 0;
    for (int counter = 0; counter < length; counter++) {
        if (workArray[counter] == 1) {
            solvedLetters++;
        }
    }

    if (solvedLetters == length) {
        workStatus = TRUE;
    }
    return workStatus;
}
