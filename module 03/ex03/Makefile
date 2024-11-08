# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 21:30:40 by anamieta          #+#    #+#              #
#    Updated: 2024/11/08 17:15:24 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

CC = c++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = ${SRC:%.cpp=%.o}

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re