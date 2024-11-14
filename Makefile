NAME		=	main.a

SRCS		=	./src/main.c \
				./src/operations/swap.c \
				./src/operations/push.c \
				./tests/test1.c \
				#./src/operations/rotate.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT_DIR	=	./libft
LIBFT_NAME	=	libft.a

DLL_DIR		=	./dll
DLL_LIB		=	./dll/dll.a

TEST_NAME	=	a.out

all:		$(LIBFT_DIR)/$(LIBFT_NAME) $(DLL_LIB) $(NAME)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(DLL_LIB) -o $(TEST_NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
			make -C $(LIBFT_DIR)

$(DLL_LIB):
			make -C $(DLL_DIR)

$(NAME):	$(OBJS)	
			ar rc $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			make -C $(DLL_DIR) clean
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(TEST_NAME)
			make -C $(DLL_DIR) fclean
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
