NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g

SOURCES = 	ft_printf.c \
			conversions.c \
			type_char.c \
			type_str.c \
			type_ptr.c \
			type_ptr2.c \
			type_int.c \
			type_int2.c \
			type_u.c \
			type_oct.c \
			type_oct2.c \
			type_hex.c \
			type_hex2.c \
			type_float.c \
			modifiers.c \
			utility.c \
			utility_2.c \
			type_nonprint.c

HEADER = includes

LIBFT = libft

DIR_S = srcs

DIR_O = obj

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

all: $(NAME)

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(SRCS)/

clean:
	rm -f $(OBJS)
	@rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean