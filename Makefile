NAME = ft_ls

LIB = libft/libft.a

SRCS =  ft_content_while.c ft_delete.c ft_no_arguments.c ft_changer.c ft_argument_counterfunc.c array_counter.c ft_count.c ft_filepath.c ft_opendir.c ls_flags.c ft_reverse.c main.c ft_sort.c ft_space.c ft_filechecker.c ft_timesort.c
OBJ =  ft_content_while.o ft_delete.o ft_no_arguments.o ft_changer.o ft_argument_counterfunc.o array_counter.o ft_count.o ft_filepath.o ft_opendir.o ls_flags.o ft_reverse.o main.o ft_sort.o ft_space.o ft_filechecker.o ft_timesort.o
all: $(NAME)

$(NAME):
	make -C libft clean
	@gcc -Wall -Wextra -Werror $(SRCS) $(LIB) -o $(NAME)

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean:
	make -C libft clean
	/bin/rm -f $(NAME)

re: fclean all

