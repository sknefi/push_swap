NAME		=	push_swap
CHECKER		=	checker

SRCS		=	./src/push_swap.c \
				./src/operations/operation_utils.c \
				./src/operations/swap.c \
				./src/operations/push.c \
				./src/operations/rotate.c \
				./src/utils.c \
				./src/algorithm.c \
				./src/algorithm_components.c \
				./src/algorithm_utils.c \
				./src/fast_sorts/fast_sort.c \
				./src/fast_sorts/fast_sort_utils.c \
				./src/error_checker_ps.c \
				./src/free_memory.c \
				./src/create_stacks.c \

CHECKER_SRCS	=	./src/checker.c \
					./src/checker_utils.c \
					./src/operations/operation_utils.c \
					./src/operations/swap.c \
					./src/operations/push.c \
					./src/operations/rotate.c \
					./src/utils.c \
					./src/algorithm.c \
					./src/algorithm_components.c \
					./src/algorithm_utils.c \
					./src/fast_sorts/fast_sort.c \
					./src/fast_sorts/fast_sort_utils.c \
					./src/error_checker_ps.c \
					./src/free_memory.c \
					./src/create_stacks.c \

OBJS		=	$(SRCS:.c=.o)
CHECKER_OBJS=	$(CHECKER_SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT_DIR	=	./libft
LIBFT_NAME	=	libft.a

DLL_DIR		=	./dll
DLL_LIB		=	./dll/dll.a

all:		$(LIBFT_DIR)/$(LIBFT_NAME) $(DLL_LIB) $(NAME) $(CHECKER)

$(LIBFT_DIR)/$(LIBFT_NAME):
			make -C $(LIBFT_DIR)

$(DLL_LIB):
			make -C $(DLL_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS)     $(OBJS)   $(DLL_LIB) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

$(CHECKER):	$(CHECKER_OBJS)
			$(CC) $(CFLAGS) $(CHECKER_OBJS) $(DLL_LIB) $(LIBFT_DIR)/$(LIBFT_NAME)  -o $(CHECKER)

clean:
			$(RM) $(OBJS) $(CHECKER_OBJS)
			make -C $(DLL_DIR) clean
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(CHECKER)
			make -C $(DLL_DIR) fclean
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
