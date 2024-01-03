NAME 		= 	libftprintf.a
SRC 		= 	ft_printf.c string.c number.c		 
OBJS 		= 	$(SRC:.c=.o)
CC 		= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror
includes	= 	ft_printf.h

all:	$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $^ -I. -o $@

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
	
clean:
		rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all test fclean re all
