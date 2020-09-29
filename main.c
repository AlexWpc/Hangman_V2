#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 50
void menu(void);

void hangman(int attempt);

int checkLowercase(char *inputString);

int main(int argc, char *argv[]) {
  menu();
  hangman();

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

    printf("  __ _  ___ \n");
    printf(" / _` |/ _ \\n");
    printf("| (_| | (_) |\n");
    printf(" \__, |\___/");
    printf(" |___/ ");

    return 0;
  }

  void menu(void) {
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
        return FALSE;
      } else {
        counter++;
      }
    }
    return TRUE;
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
