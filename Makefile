# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 16:29:05 by vmartins          #+#    #+#              #
#    Updated: 2017/06/27 14:38:09 by vmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nqme
NAME = ft_ls

#Flag
FLAGS = -Wall -Wextra -Werror

#SRCS
SRCS =  main.c \
		srcs/ft_ls.c \
		srcs/ft_error.c \
		srcs/ft_ls_divide.c \
		srcs/ft_size.c \
		srcs/ft_quicksort.c \
		srcs/ft_sort_ls.c \
		srcs/ft_options.c \
		srcs/ft_more_options.c

#INCLUDES
INCLUDES = includes/ft_ls.h


# COLORS
C_NO = "\033[00m"
C_OK = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# # DBG MESSAGE
SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
OK = $(C_OK)OK$(C_NO)

# #Objects
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling" [$(NAME)] "..."
	@make -C libft/
	@gcc -I includes libft/libft.a -o $(NAME) $(SRCS)
	@clear
	@echo "Compiling" [$(NAME)] $(SUCCESS)

%.o: %.c
	@gcc -I includes -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJ) $(OBJ_MAIN)
	@make clean -C libft/
	@echo "Cleaning" [$(NAME)] "..." $(OK)

fclean: clean
	@rm -f $(NAME) $(LIB)
	@make fclean -C libft/
	@echo "Delete" [$(NAME)] $(OK)

re: fclean all

.PHONY: all clean fclean re
