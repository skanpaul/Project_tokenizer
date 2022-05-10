NAME	= a.out

CC		= gcc
CFLAG	= -Wall -Wextra -Werror

SRC		= $(wildcard *.c)

all:
	$(CC) $(CFLAG) $(SRC) -lreadline -L. -lft -o $(NAME)