# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: hmichel <hmichel@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/10 19:59:22 by cgarrot      #+#   ##    ##    #+#        #
#    Updated: 2020/02/06 13:57:51 by seanseau    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
OPTI = -O3 -march=native -flto -ffast-math -ffreestanding -fno-builtin
INC = /includes/ft_printf.h
HEADER = include

#------------------------------------FILE--------------------------------------#

FILES = src/check_caract\
		src/check_digit_param\
		src/check_digit_param2\
		src/check_digit\
		src/check_hexa\
		src/check_hexa_param\
		src/check_hexa_param2\
		src/check_octa\
		src/check_octa_param\
		src/check_pointer\
		src/check_percent\
		src/check_str\
		src/conversion\
		src/ft_printf\
		src/init\
		src/parse\
		src/utils1\
		src/utils2\
		src/utils3\
		src/utils4\
		src/utils_octa_hexa\
		src/check_float\
		src/check_float_param\
		src/check_float_param2\
		src/ft_intcpy\
		src/ft_rev_intcpy\

#----------------------------------SOURCE--------------------------------------#

SRC = $(addsuffix .c , $(FILES))

#----------------------------------OBJECT--------------------------------------#

OBJ = $(addsuffix .o , $(FILES))

#-----------------------------------RULE---------------------------------------#

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

object/%.o: src/%.c $(HEADER)
	@$(CC) $(FLAGS) $(OPTI) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
