# компилятор
CC=gcc

# флаги
CFLAGS=-c -Wall -Werror
TFLAGS=-I thirdparty -I src

# путь до объектных файлов
OBJDIR=builder/

# путь до исходников
SRCDIR=src/
# путь до тестов
TSTDIR=test/

# общие файлы
FILES=functions.c
#повторяющиеся
SLF=main.c
#тест файл
TESTF=test.c 

# объектные файлы приложения
OBJ=$(patsubst %.c, $(OBJDIR)$(SRCDIR)%.o, $(FILES) $(SLF))

#объектные файлы тестов
TESTOBJ=$(patsubst %.c, $(OBJDIR)$(TSTDIR)%.o, $(FILES) $(TESTF) $(SLF))

# выходной файл
EXECUTABLE=bin/hangman
TESTEXECUTABLE=bin/tests

.PHONY: clean

all: $(EXECUTABLE) $(TESTEXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^

$(OBJDIR)$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^

$(TESTEXECUTABLE): $(TESTOBJ)
	$(CC) -o $@ $^
	
$(OBJDIR)$(TSTDIR)%.o: $(TSTDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^ $(TFLAGS)


$(OBJDIR)$(TSTDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJ) $(TESTOBJ) $(EXECUTABLE) $(TESTEXECUTABLE)



