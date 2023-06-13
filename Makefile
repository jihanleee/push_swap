NAME = push_swap

NAME_BONUS = checker

SRC_DIR = ./srcs/
SRC_CHECKER_DIR = ./srcs_checker/

INCLUDE = ./includes

SRCS = double_rotate.c  ft_printf.c  list1.c  list2.c  print_formats.c\
push.c  rotate.c  sort1.c  sort2.c  swap.c  utils.c
SRCS_CHECKER = double_rotate.c  ft_printf.c  list1.c  list2.c  print_formats.c\
push.c  rotate.c  sort1.c  sort2.c  swap.c  utils.c get_next_line.c get_next_line_utils.c

MAIN = main.c
MAIN_O = main.o

MAIN_CHECKER = main_checker.c
MAIN_CHECKER_O = main_checker.o

SRC_FILES = $(addprefix $(SRC_DIR), $(SRCS))
SRC_CHECKER_FILES = $(addprefix $(SRC_CHECKER_DIR), $(SRCS_CHECKER))
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_CHECKER_FILES = $(SRC_CHECKER_FILES:.c=.o)

CC = gcc

CFLAGS = -Wextra -Werror -Wall -I $(INCLUDE)

all : $(NAME)

bonus : $(NAME_BONUS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILES) $(MAIN_O)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(MAIN_O)

$(NAME_BONUS) : $(OBJ_CHECKER_FILES) $(MAIN_CHECKER_O)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_CHECKER_FILES) $(MAIN_CHECKER_O)

clean :
	rm -f *.o */*.o

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : clean fclean all re