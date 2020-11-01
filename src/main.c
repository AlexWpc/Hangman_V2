#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 50

int main(int argc, char *argv[]) {
  menu();

  //СОЗДАЕМ МАССИВ ДЛЯ СЛОВАРНОГО ЛИСТА
  printf("How many words? \n");
  int numOfWords = 0;
  scanf("%d", &numOfWords);
  char wordList[numOfWords][MAX_LENGTH];
  printf("\n");

  //ПОЛЬЗОВАТЕЛЬ ЗАПОЛНЯЕТ МАССИВ СЛОВАМИ
  int counter = 0;
  while (counter < numOfWords) {
    printf("_____________________________\n");
    printf("|                           |\n");
    printf("|     What is word %d?       |\n", (counter + 1));
    printf("|                           |\n");
    printf("|***************************|\n");
    printf("|                           |\n");
    printf("| Max length is 50 letters  |\n");
    printf("| Lowercase ONLY            |\n");
    printf("|                           |\n");
    printf("-----------------------------\n");
    char inputString[MAX_LENGTH];
    scanf("%s", inputString);

    //ПРОВЕРКА СТРОКИ НА НИЖНИЙ РЕГИСТР
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
    char *word = &wordList[wordNum][0];

    int workStatus = FALSE;
    int attempt = 0;

    //*workArray СОДЕРЖИТ ЧИСЛО ДЛЯ КАЖДОЙ БУКВЫ
    // 0 = БУКВА НЕ УГАДАНА ПОЛЬЗОВАТЕЛЕМ
    // 1 = БУКВА УГАДАНА ПОЛЬЗОВАТЕЛЕМ

    int workArray[(int)strlen(word)];

    for (counter = 0; counter < strlen(word); counter++) {
      workArray[counter] = 0;
    }

    //*checkArray СОДЕРЖИТ ЧИСЛО ДЛЯ КАЖДОЙ БУКВЫ
    // 0 = БУКВА ЩЕ НЕ УГАДАНА ПОЛЬЗОВАТЕЛЕМ
    // 1 = ТЕКУЩАЯ БУКВА УГАДАННАЯ ПОЛЬЗОВАТЕЛЕМ

    int checkArray[(int)strlen(word)];

    for (counter = 0; counter < strlen(word); counter++) {
      checkArray[counter] = 0;
    }

    printf("  __ _   ___ \n");
    printf(" / _` | | _ | \n");
    printf("| (_| | |(_)| \n");
    printf(" |__, | |___| \n");
    printf(" |___/ \n");

    while ((workStatus == FALSE) && (attempt < 7)) {
      printf("=========================================\n");
      printf("The word contains %d letters.\n", (int)strlen(word));
      printf("Enter a letter: ");

      char letter[MAX_LENGTH];
      scanf(" %s", &letter[0]);
      printf("You entered: %c\n", letter[0]);

      int unsolvedLetters = 0;
      //ПРОВЕРКА БУКВЫ В СЛОВЕ
      for (counter = 0; counter < strlen(word); counter++) {
        if (word[counter] == letter[0]) {
          checkArray[counter] = 1;
        } else {
          checkArray[counter] = 0;
          unsolvedLetters++;
        }
      }
      if (unsolvedLetters == strlen(word)) {
        attempt++;
      }
      printf("Number of mistakes: %d\n", attempt);
      hangman(attempt);

      counter = 0;
      while (counter < strlen(word)) {
        if ((checkArray[counter] == 0) && (workArray[counter] == 0)) {
          workArray[counter] = 0;
        } else {
          workArray[counter] = 1;
        }
        counter++;
      }

      for (counter = 0; counter < strlen(word); counter++) {
        checkArray[counter] = 0;
      }

      //ПРОВЕРКА НАЙДЕННЫХ БУКВ
      int solvedLetters = 0;
      for (counter = 0; counter < strlen(word); counter++) {
        if (workArray[counter] == 1) {
          solvedLetters++;
        }
      }

      if (solvedLetters == strlen(word)) {
        workStatus = TRUE;
      }

      //ВЫВОД СЛОВА
      for (counter = 0; counter < strlen(word); counter++) {
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
      if (decision[0] == 'y') {
        decided = TRUE;
        replay = TRUE;
        printf("\n\n");
      } else if (decision[0] == 'n') {
        decided = TRUE;
        replay = FALSE;
        printf("\n");
      } else {
        printf("Invalid input. Try again.\n\n");
      }
    }
  }

  return EXIT_SUCCESS;
}
