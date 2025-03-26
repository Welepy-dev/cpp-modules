# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 08:07:52 by welepy            #+#    #+#              #
#    Updated: 2025/03/26 09:43:50 by welepy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	  =			megaphone

CC		  =			c++

CFLAGS	  =			-Wall -Werror -Wextra -std=c++98

SRC_DIR	  =			src/
OBJ_DIR	  =			obj/
INC_DIR	  =			include/

SRC_FILES =			megaphone.cpp
OBJ_FILES =			$(SRC_FILES:.cpp=.o)

SRC		  =			$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		  =			$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(OBJ)
	 @$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re
