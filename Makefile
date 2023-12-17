CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf
INCLUDES = -I./SDL2_ttf
EXEC = main
SRC = src/main.c src/jeu.c src/fonctions_SDL.c src/menu.c src/vaisseau.c src/fonctions_fichiers.c
OBJ = $(SRC:.c=.o)
   
all: $(EXEC)
main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)
