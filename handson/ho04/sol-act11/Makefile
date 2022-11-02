CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
POKEMON=main.c pokemon.c
POKEDEX=pokedex.c 
OBJECTS_POKEMON=$(POKEMON:.c=.o)
OBJECTS_POKEDEX=$(POKEDEX:.c=.o)
POKEMON_EXECUTABLE=pokemon
POKEDEX_EXECUTABLE=pokedex

all: $(POKEMON) $(POKEDEX) $(POKEMON_EXECUTABLE) $(POKEDEX_EXECUTABLE)
	
$(POKEMON_EXECUTABLE): $(OBJECTS_POKEMON)
	$(CC) $(OBJECTS_POKEMON) -o $@

$(POKEDEX_EXECUTABLE): $(OBJECTS_POKEDEX)
	$(CC) $(OBJECTS_POKEDEX) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

execute: $(POKEMON_EXECUTABLE)
	 ./$(POKEMON_EXECUTABLE)

clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(POKEMON_EXECUTABLE) $(POKEDEX_EXECUTABLE)