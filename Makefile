##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	malloc.c		\
		calloc.c		\
		realloc.c		\
		reallocarray.c	\
		free.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-shared -o

CC		= 	gcc

LD		=	-c -fpic

NAME 	=	libmy_malloc.so

all:	$(NAME)

$(NAME):
	@$(CC) $(LD) $(SRC)
	@$(CC) $(LDFLAGS) $(NAME) $(OBJ)
clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
