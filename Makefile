
NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs

# Fiche
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)




# Alvo principal
all: $(NAME)


$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compila objetos do ft_printf
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@



# Limpa os .o 
clean:
	rm -f $(OBJ)

# Limpa tudo
fclean: clean
	rm -f $(NAME)


# Recompila tudo
re: fclean all

.PHONY: all clean fclean re