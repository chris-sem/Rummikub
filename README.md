# Rummikub
Jeu Rummikub avec interface graphique, réalisé en C et la bibliothèque SDL2

En programmation C, la SDL pour **Simple DirectMedia Layer**, est une bibliothèque logicielle multiplateforme destinée à faciliter le développement de jeux vidéo et d'applications multimédia

# Comment ca marche...
### Windows

Le projet a deja été compilé sous windows, vous pouvez directement le lancer (via le terminal bien sur), en vous placant dans le dossier Rummikub, et taper la commande suivante :
bin\prog.exe

Si vous voulez compiler vous meme le projet, tapez la commande suivante (toujours en se placant dans le dossier Rummikub) :

**gcc src/*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf**

et :

**bin\prog.exe** (CA NE MARCHE PAS AUTREMENT, il faut bien faire : bin\prog.exe)

pour l'executer...

### Linux

Sous LINUX (**IL faut penser à installer les dependances avant !!!**), pour compiler, on se place dans le dossier Rummikub et on tape la commande de compilation suivante :

**gcc -g src/*.c  -o  ../ludo $(pkg-config --cflags --libs sdl2 ) -lSDL2_image -lSDL2_ttf -o prog**

Tapez en suite :

**./prog**

pour l'executer...
