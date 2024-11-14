NAME		=	dll.a

SRCS		=	dll_append.c dll_clear.c dll_create.c dll_init.c \
				dll_iteri.c dll_prepend.c dll_printer.c
OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT_DIR	=	../libft
LIBFT_NAME	=	libft.a

TEST_NAME	=	dll_test.out

all:		$(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
			# $(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(TEST_NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
			# make -C $(LIBFT_DIR)

$(NAME):	$(OBJS)	
			ar rc $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			# make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(TEST_NAME)
			# make -C $(LIBFT_DIR) fclean

re:			fclean all
			# make -C $(LIBFT_DIR) re

.phony:		all clean fclean re
			# make -C $(LIBFT_DIR) all clean fclean re