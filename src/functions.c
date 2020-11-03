#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

void replayGame(char decision[], int *decided, int *replay){
    if (decision[0] == 'y') {
        *decided = TRUE;
        *replay = TRUE;
        printf("\n\n");
      } else if (decision[0] == 'n') {
        *decided = TRUE;
        *replay = FALSE;
        printf("\n");
      } else {
        *decided = FALSE;
        *replay = FALSE;
        printf("Invalid input. Try again.\n\n");
      }
}

void menu() {
    printf(" _                                             \n");
    printf("| |                                            \n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                    __/ |                      \n");
    printf("                   |___/  \n");
    printf("\n");
    printf("By Alexey Chernikov and Andrey Gondaruk (IS_942)\n");
    printf("\n");
}

int checkLowercase(char *inputString) {
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

void hangman(int attempt) {
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
