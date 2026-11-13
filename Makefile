CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
all : test_liste
test_liste : liste.c test_liste.c
$(CC) $(CFLAGS) liste.c test_liste.c -o test_liste
clean :
rm -f test_liste
