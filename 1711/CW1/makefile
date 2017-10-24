#Joseph Mulray
#Makefile CW1 1711
CC = cc
VIEWER = more
OUTFILE = out

.PHONY: run view clean

run: cw1.c
	$(CC) -o $(OUTFILE) cw1.c
	./$(OUTFILE)

view: cw1.c
	$(VIEWER) cw1.c

clean:
	- rm $(OUTFILE)

