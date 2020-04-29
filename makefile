CC      = gcc
CFLAGS  = -Wall -O2 -fomit-frame-pointer
# CFLAGS        = -Wall
LD      = gcc
LIBS    =-lncurses
LDFLAGS = -s

testfabs:       wdl.o
	$(LD) $(LDFLAGS) -o	wdl	wdl.o   

testfabs.o:     testfabs.c
	$(CC) $(CFLAGS) -c	 wdl.c

clean:
	$(RM) wdl wdl.o core  *~
