# Variable pour la compilation

CC=gcc

# Variable pour le nom des dossiers

SRC=src
OBJ=obj

# Recherche des fichiers .c .h

SRCS=$(wildcard $(SRC)/*.c)
HEADS=$(wildcard $(SRC)/*.h)

# Substitution des .c en .o

OBJS=$(SRCS:.c=.o)

# Dossier pour l'executable

#EXEC_DIR=exec
#EXEC=$(EXEC_DIR)/test

# Debut du make

all:test

test: $(OBJS)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/*.c
	$(CC) -c $< -o $@
