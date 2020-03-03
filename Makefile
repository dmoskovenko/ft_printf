NAME = libftprintf.a

BIN = ft_printf

FLAGS = -Wall -Wextra -Werror -g

SRCS = ft_printf.c conversions.c type_char.c type_int.c type_oct.c type_float.c modifiers.c utility.c

HDR = ft_printf.h

LIBFT = libft

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

DIR_O = obj

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: %.c $(HDR)
	@mkdir -p obj
	gcc $(FLAGS) -I $(HDR) -o $@ -c $<

all: $(NAME)

norme:
	norminette ./libft/
	@echo
	norminette ./$(HDR)/
	@echo
	norminette ./$(SRCS)/

clean:
	rm -f $(OBJS)
	@rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	#make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean