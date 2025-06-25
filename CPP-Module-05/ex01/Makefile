# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:51:48 by marcsilv          #+#    #+#              #
#    Updated: 2025/06/23 12:53:37 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	  =			Maggots

CC		  =			c++

CFLAGS	  =			-Wall -Werror -Wextra -std=c++98

SRC_DIR	  =			src/
OBJ_DIR	  =			obj/
INC_DIR	  =			inc/

SRC_FILES =			Bureucrat.cpp GradeTooHighException.cpp main.cpp GradeTooLowException.cpp Form.cpp 
OBJ_FILES =			$(SRC_FILES:.cpp=.o)

SRC		  =			$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		  =			$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
