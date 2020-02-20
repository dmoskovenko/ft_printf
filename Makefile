NAME = ft_printf.a
BIN = ft_printf
FLAGS = -Wall -Wextra -Werror -g
SRCS = ft_printf.c conversions.c
OBJS = $(SRC:.c=.o)
HDR = ft_printf.h
LIBFT = libft

$(NAME): $(OBJS)
	make -C $(LIBFT)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	gcc $(FLAGS) main.c -I $(HEADER) -o $(BIN)

# test:
#	@make all main.c
all: $(NAME)

norme:
	norminette ./libft/
	@echo
	norminette ./$(HDR)/
	@echo
	norminette ./$(SRCS)/
	@echo

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean 

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: fclean re norme all clean