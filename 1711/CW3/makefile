#Joseph Mulray
#Makefile CW1 1711
CC = cc
VIEWER = more
OUTFILE = out

.PHONY: run view clean

run: cw3.c
	$(CC) -o $(OUTFILE) cw3.c
	./$(OUTFILE)

view: cw3.c
	$(VIEWER) cw3.c

clean:
	- rm $(OUTFILE)

