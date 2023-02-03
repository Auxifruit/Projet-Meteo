# Variable pour la compilation

CC=gcc

# Variable pour le nom des dossiers

SRC=src
OBJ=obj

# Recherche des fichiers .c .h

SRCS=$(wildcard $(SRC)/*.c)
HEADS=$(wildcard $(SRC)/*.h)

# Substitution des .c en .o

OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

# Debut du make

all:exec

exec: $(OBJS)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< -o $@

