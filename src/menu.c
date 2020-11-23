#include "functions.h"
#include "menu.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FALSE 0
#define TRUE 1
#define MAX_LENGTH 101

void print_menu()
{
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

void menu(void)
{
    int counter = 0;
    int numOfWords = 0;
    numOfWords = ScanNumOfWords(numOfWords);

    char wordList[numOfWords][MAX_LENGTH];
    printf("\n");

    while (counter < numOfWords) {
        printf("_____________________________\n");
        printf("|                           |\n");
        printf("|     What is word %d?      |\n", (counter + 1));
        printf("|                           |\n");
        printf("|***************************|\n");
        printf("|                           |\n");
        printf("| Max length is 100 letters |\n");
        printf("| Lowercase ONLY            |\n");
        printf("|                           |\n");
        printf("-----------------------------\n");

        char inputString[MAX_LENGTH];
        while (1) {
            scanf("%s", inputString);
            if (strlen(inputString) < MAX_LENGTH) {
                break;
            } else {
                printf("You input too much letters, try again.\n");
            }
        }
        if (checkLowercase(inputString) == TRUE) {
            //КОПИРОВАНИЕ СТРОКИ В МАССИВ
            int counter2;
            for (counter2 = 0; counter2 < MAX_LENGTH; counter2++) {
                wordList[counter][counter2] = inputString[counter2];
            }
            counter++;
            printf("\n");
        } else {
            printf("Invalid input. Try again.\n\n");
            continue;
        }
    }
    int replay = TRUE;

    while (replay == TRUE) {
        //ВЫБОР СЛОВА ИЗ ЛИСТА
        srand(time(NULL));
        int wordNum = (int)(rand() % numOfWords);
        char* word = &wordList[wordNum][0];
        int length = (int)strlen(word);
        int workStatus = FALSE;
        int attempt = 0;

        int workArray[length];

        for (int counter = 0; counter < length; counter++) {
            workArray[counter] = 0;
        }

        int checkArray[length];

        for (int counter = 0; counter < length; counter++) {
            checkArray[counter] = 0;
        }

        printf("  __ _   ___ \n");
        printf(" / _` | | _ | \n");
        printf("| (_| | |(_)| \n");
        printf(" |__, | |___| \n");
        printf(" |___/ \n");

        while ((workStatus == FALSE) && (attempt < 7)) {
            char letter[100];
            InputLetters(letter, length);
            attempt = LetterCheck(length, word, letter, attempt, checkArray);

            printf("Number of mistakes: %d\n", attempt);
            hangman(attempt);

            ChecktoWork(length, checkArray, workArray);

            workStatus = SolvedLetterCheck(length, workStatus, workArray);

            //ВЫВОД СЛОВА
            for (int counter = 0; counter < length; counter++) {
                if (workArray[counter] == 0) {
                    printf("_");
                } else if (workArray[counter] == 1) {
                    printf("%c", word[counter]);
                }
            }
            printf("\n\n");
        }

        if (attempt == 7) {
            printf("Correct word was: %s\n", word);
            printf("YOU LOSE!\n\n");
        } else {
            printf("YOU WIN!\n\n");
        }
        //ПОЛЬЗОВАТЕЛЬ МОЖЕТ ВЫБРАТЬ ИГРАТЬ ЕЩЕ РАЗ ИЛИ ВЫЙТИ
        int decided = FALSE;
        char decision[MAX_LENGTH];
        while (decided == FALSE) {
            printf("Do you want to play again? (y/n)\n");
            scanf("%s", &decision[0]);
            replayGame(decision, &decided, &replay);
        }
    }
}

