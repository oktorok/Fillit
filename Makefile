# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 03:08:21 by mrodrigu          #+#    #+#              #
#    Updated: 2017/12/05 11:25:03 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re $(LIB_PATH) 

NAME = fillit

FLAGS = -Wall -Wextra -Werror

LIB_NAME = libft.a

LIB_DIR = libft/

LIB_PATH = $(LIB_DIR)$(LIB_NAME)

OBJ_DIR_NAME = objects

OBJ_DIR = $(OBJ_DIR_NAME)/

#OBJ_DIR = ./

HEADER_DIR = libft/

SRC = main.c \
	  ft_filler.c \
	  ft_reader.c \
	  ft_decoder.c \
	  ft_check.c \
	  ft_fill.c \
	  ft_memset_fillit.c \
	  ft_erase.c \
	  ft_dealer.c

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))

all : $(NAME)

$(NAME): $(OBJ) $(LIB_PATH)
	@gcc -o $(NAME) $(OBJ) -L$(LIB_DIR) -lft -I$(HEADER_DIR)
	
$(LIB_PATH):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

$(OBJ_DIR)%.o : %.c
	@gcc $(FLAGS) -I $(HEADER_DIR) -c $<
	@mkdir -p $(OBJ_DIR_NAME)
	@mv -f $(@F) $(OBJ_DIR)

clean : 
	@rm -f $(OBJ)
	@rm -rvf $(OBJ_DIR_NAME)
	@$(MAKE) -C $(LIB_DIR) clean --no-print-directory

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory

re: fclean
	@make
