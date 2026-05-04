# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 13:19:36 by marcsilv          #+#    #+#              #
#    Updated: 2026/05/04 13:19:37 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= inc/

SRC_FILES	= main.cpp BitcoinExchange.cpp
HEADERS		= BitcoinExchange.hpp

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
INC			= $(addprefix $(INC_DIR), $(HEADERS))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
