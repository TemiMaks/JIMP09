# Zmienne
CC = gcc
CFLAGS = -Wall --pedantic
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/gauss

# Znajduje wszystkie pliki źródłowe .c w katalogu src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Debug zmiennych
$(info SRC = $(SRC))
$(info OBJ = $(OBJ))

# Domyślny cel
all: $(TARGET)

# Kompilacja programu końcowego
$(TARGET): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Kompilacja plików obiektowych
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Uruchomienie programu z argumentami
run: all
	$(TARGET) dane/A dane/b

# Czystość
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean run
