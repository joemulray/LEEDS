CC = gcc
VIEWER = less
OUTFILE = out
FILES = 1.c 2.c 3.c 4.c 5.c 6.c \
	7.c 8.c 9.c 10.c 11.c 12.c

.PHONY: run view clean

run: 1 2 3 4 5 6 7 8 9 10 11 12

1: 1.c
	$(CC) 1.c -o $(OUTFILE)
	./$(OUTFILE)

2: 2.c
	$(CC) 2.c -o $(OUTFILE)
	./$(OUTFILE)

3: 3.c
	$(CC) 3.c -o $(OUTFILE)
	./$(OUTFILE)

4: 4.c
	$(CC) 4.c -o $(OUTFILE)
	./$(OUTFILE)

5: 5.c
	$(CC) 5.c -o $(OUTFILE)
	./$(OUTFILE)

6: 6.c
	$(CC) 6.c -o $(OUTFILE)
	./$(OUTFILE)

7: 7.c
	$(CC) 7.c -o $(OUTFILE)
	./$(OUTFILE)

8: 8.c
	$(CC) 8.c -o $(OUTFILE)
	./$(OUTFILE)

9: 9.c
	$(CC) 9.c -o $(OUTFILE)
	./$(OUTFILE)

10: 10.c
	$(CC) 10.c -o $(OUTFILE)
	./$(OUTFILE)
11: 11.c
	$(CC) 11.c -o $(OUTFILE)
	./$(OUTFILE)

12: 12.c
	$(CC) 12.c -o $(OUTFILE)
	./$(OUTFILE)

view: $(FILES)
	$(VIEWER) $(FILES)

clean:
	rm $(OUTFILE)
