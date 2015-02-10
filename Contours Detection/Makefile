CC=gcc
CFLAGS = -O
PRG=palette
OBJ=main.o bmp.o calcul.o
SRC=$(OBJ:.o=.c)

LFLAGS= -lm -L/usr/lib
LIBS= -lX11 -lglut -lGL -lGLU

all: $(PRG)

%.o : %.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $<

palette: $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) -o palette$(LIBS) $(OBJ)

clean:
	@rm -f *.o
	@rm -f gmon.out	
	@rm -f core
	@rm -f *~
	@rm -f glutcode 
