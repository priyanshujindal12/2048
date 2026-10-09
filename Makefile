
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude

TARGET = 2048

SRC = src/main.c \
      src/board.c \
      src/display.c \
      src/game.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
