EXEC     = $(shell basename $$(pwd))
CC       = gcc

CFLAGS   = -O3 -Wall -Wextra -Wpedantic -Wstrict-aliasing
LDFLAGS  = 

SRC      = $(wildcard *.c)
OBJ      = $(SRC:.c=.o)

all: $(EXEC)

${EXEC}: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean run

clean:
	@rm -rf *.o $(EXEC)

run: 
	./$(EXEC)


			