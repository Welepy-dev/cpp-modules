# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 13:51:17 by welepy            #+#    #+#              #
#    Updated: 2025/04/18 15:14:05 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	  =			HI_THIS_IS_BRAIN

CC		  =			c++

CFLAGS	  =			-Wall -Wextra -Werror -std=c++98

SRC_DIR	  =			src/
OBJ_DIR	  =			obj/

SRC_FILES =			main.cpp
OBJ_FILES =			$(SRC_FILES:.cpp=.o)

SRC		  =			$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		  =			$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
