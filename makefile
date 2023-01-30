CC=gcc

SRC=src
OBJ=obj

SRCS=$(wildcard $(SRC)/*.c)
HEADS=$(wildcard $(SRC)/*.h)
OBJS=$(SRCS:.c=.o)

BIN_DIR=bin
BIN=$(BIN_DIR)/test

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/*.c
	$(CC) -c $< -o $@

