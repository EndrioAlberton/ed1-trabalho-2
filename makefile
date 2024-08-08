# Variáveis

PROJ_NAME=contatos

DIST_PATH=dist

SRC_PATH=src

BINARY_PATH=$(DIST_PATH)/$(PROJ_NAME)

C_SOURCE=$(wildcard $(SRC_PATH)/*.c)

H_SOURCE=$(wildcard $(SRC_PATH)/*.h)

OBJ=$(subst $(SRC_PATH), $(DIST_PATH), $(C_SOURCE:.c=.o))

CC=gcc

CC_FLAGS=-c        \
         -ansi     \
         -pedantic

# Roda o programa
run: all
	$(BINARY_PATH)

# Compila tudo
all: $(BINARY_PATH)

# Faz o link dos objects e gera o binary
$(BINARY_PATH): $(OBJ)
	$(CC) -o $@ $^

# Compila todos os outros objects
$(DIST_PATH)/%.o: $(SRC_PATH)/%.c $(SRC_PATH)/%.h
	$(CC) -o $@ $< $(CC_FLAGS)

# Compila o object do arquivo main
$(DIST_PATH)/main.o: $(SRC_PATH)/main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

# Limpa a dist
clean:
	rm -rf $(DIST_PATH)/*.o $(DIST_PATH)/*~ $(BINARY_PATH)