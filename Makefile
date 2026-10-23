CC = gcc
CFLAGS = -Wall -Wextra -std=c99

cifra_cesar: cifra_cesar.c
	$(CC) $(CFLAGS) -o cifra_cesar cifra_cesar.c

clean:
	rm -f cifra_cesar
