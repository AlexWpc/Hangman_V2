# компилятор
CC=gcc

# флаги
CFLAGS=-c -Wall -Werror

# путь до объектных файлов
OBJDIR=obj/

# путь до исходников
SRCDIR=src/

# общие файлы
FILES=main.c functions.c

# объектные файлы приложения
OBJ=$(patsubst %.c, $(OBJDIR)$(SRCDIR)%.o, $(FILES))

# выходной файл
EXECUTABLE=bin/main

.PHONY: clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^

$(OBJDIR)$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^

format:
    clang-format -i ./src/*.h
    clang-format -i ./src/*.c
    clang-format -i ./test/*c

clean:
	$(RM) $(OBJ) $(EXECUTABLE)
