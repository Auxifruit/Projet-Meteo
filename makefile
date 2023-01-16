CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
BUILD_DIR=build
OBJ2=$(addprefix $(BUILD_DIR)/, $(OBJ))

all: $(BUILD_DIR)/hello

$(BUILD_DIR)/%.o : %.c $(BUILD_DIR)
	$(CC) -c $< -o $@

$(BUILD_DIR)/hello: $(OBJ2)
	$(CC) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/

clean:
	rm -f $(BUILD_DIR)/*.o
