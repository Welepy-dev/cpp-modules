# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 22:02:21 by welepy            #+#    #+#              #
#    Updated: 2025/04/09 22:03:47 by welepy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	harl

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

#directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

SRC_FILES	=	Harl.cpp main.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#compile the executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

#clean rule
clean:
	rm -rf $(OBJ_DIR); \

#fclean rule
fclean: clean
	rm -f $(NAME); \

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re
