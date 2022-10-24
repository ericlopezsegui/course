CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
POKEMON=main.c pokemon.c
RANDOM=random.c 
OBJECTS_POKEMON=$(POKEMON:.c=.o)
OBJECTS_RANDOM=$(RANDOM:.c=.o)
POKEMON_EXECUTABLE=pokemon
RANDOM_EXECUTABLE=random

all: $(POKEMON) $(RANDOM) $(POKEMON_EXECUTABLE) $(RANDOM_EXECUTABLE)
	
$(POKEMON_EXECUTABLE): $(OBJECTS_POKEMON)
	$(CC) $(OBJECTS_POKEMON) -o $@

$(RANDOM_EXECUTABLE): $(OBJECTS_RANDOM)
	$(CC) $(OBJECTS_RANDOM) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

execute: $(POKEMON_EXECUTABLE)
	 ./$(POKEMON_EXECUTABLE)

clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(POKEMON_EXECUTABLE) $(RANDOM_EXECUTABLE)