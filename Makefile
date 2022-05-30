NAME = push_swap

OBJS = main.o ops.o dist.o exe_ops.o others.o exe_moves.o init.o minsort.o sorted.o

HEAD = push_swap.h

SUBDIRS = libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:		$(SUBDIRS) $(NAME)

$(SUBDIRS):
			make -C $(SUBDIRS)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -Llibft -lft -o $(NAME)

$(OBJS):	%.o:%.c $(HEAD)
			$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
			rm -f $(OBJS)
			make clean -C $(SUBDIRS)

fclean:
			rm -f $(OBJS) $(NAME)
			make fclean -C $(SUBDIRS)

re:			fclean all

.PHONY: all clean fclean re $(SUBDIRS)
