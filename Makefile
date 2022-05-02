NAME	= a.out

CC		= gcc
CFLAG	= 

SRC		= $(wildcard *.c)

all:
	$(CC) $(CFLAG) $(SRC) -lreadline -L. -lft -o $(NAME)