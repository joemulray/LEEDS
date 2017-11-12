#Joseph Mulray
#Makefile CW1 1711
CC = cc
VIEWER = more
OUTFILE = out

.PHONY: run view clean

run: cw2.c
	$(CC) -o $(OUTFILE) cw2.c
	./$(OUTFILE)

view: cw2.c
	$(VIEWER) cw2.c

clean:
	- rm $(OUTFILE)

