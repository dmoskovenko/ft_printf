NAME = ft_printf.a

BIN = ft_printf

FLAGS = -Wall -Wextra -Werror -g

SRCS = ft_printf.c conversions.c

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

HDR = ft_printf.h

LIBFT = libft

DIR_O = obj

$(NAME): $(OBJS)
	make -C $(LIBFT)
	@echo
	cp libft/libft.a ./$(NAME)
	@echo
	ar rc $(NAME) $(OBJS)
	@echo
	ranlib $(NAME)

$(DIR_O)/%.o: %.c $(HDR)
	@mkdir -p obj
	gcc $(FLAGS) -I $(HDR) -o $@ -c $<
	@echo

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
	@echo
	@rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	@echo
	rm -f $(NAME)
	@echo
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean