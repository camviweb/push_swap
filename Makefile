CFLAGS	=-Wall -Wextra -Werror
CC		=cc $(CFLAGS)
NAME	=push_swap
SRC 	=main.c
OBJD	=obj
OBJ		=$(SRC:%.c=$(OBJD)/%.o)
LIBFTD	=libft
LIBFT	=$(LIBFTD)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L$(LIBFTD) -lft -o $@

$(OBJD)/%.o: %.c | $(OBJD)
	$(CC) -o $@ -c $<

$(OBJD):
	mkdir -p $(OBJD)

$(LIBFT):
	make -C $(LIBFTD)

clean: 
	rm -rf $(OBJD)
	make -C $(LIBFTD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re: fclean all

.PHONY: all clean fclean re
