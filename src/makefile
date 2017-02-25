# Makefile
CC = g++
CFLAGS = -Wall
EXEC_NAME = Hex
OBJ_FILES = gameController.o hexBoard.o

# D�finition des cibles particuli�res
.PHONY: clean

# D�sactivation des r�gles implicites
.SUFFIXES:

# Cr�ation de l'ex�cutable
all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

gameController.o: gameController.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

hexBoard.o: hexBoard.cpp hexBoard.h
	$(CC) $(CFLAGS) -o $@ -c $<

# Suppression des fichiers temporaires
clean:
	rm $(EXEC_NAME) $(OBJ_FILES)