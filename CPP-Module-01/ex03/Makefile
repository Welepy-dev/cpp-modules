# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 17:37:34 by marcsilv          #+#    #+#              #
#    Updated: 2025/04/07 15:52:17 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	  =			violence

CC		  =			c++

CFLAGS	  =			-Wall -Werror -Wextra -std=c++98

SRC_DIR	  =			src/
OBJ_DIR	  =			obj/
INC_DIR	  =			include/

SRC_FILES =			main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ_FILES =			$(SRC_FILES:.cpp=.o)

SRC		  =			$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		  =			$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(OBJ)
	 @$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean: rm -rf $(OBJ_DIR);

#fclean rule
fclean: clean 
	rm -f $(NAME);

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re
