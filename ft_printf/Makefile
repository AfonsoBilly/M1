
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf. c \
       ft_print_char.c \
       ft_print_str.c \
       ft_print_ptr.c \
       ft_print_nbr.c \
       ft_print_unsigned.c \
       ft_print_hex.c

OBJS = $(SRCS:. c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

. PHONY: all clean fclean re