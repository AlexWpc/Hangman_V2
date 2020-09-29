#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 50
void menu(void);

void hangman(void);

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
    //ЕСЛИ СИМВОЛ НЕ НИЖНЕГО РЕГИСТРП ВЕРНУТЬ 0
    if (!('a' <= inputString[counter] && inputString[counter] <= 'z')) {
      return FALSE;
    } else {
      counter++;
    }
  }
  return TRUE;
}
void hangman(void) {
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
