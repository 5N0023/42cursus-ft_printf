SRCS =	ft_printf.c		\
		ft_printmem.c	\
		hexaform.c		\
		utils.c 		\
		utils2.c		\


NAME = libftprintf.a 

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c ft_printf.h
	cc $(CC_FLAGS) -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all