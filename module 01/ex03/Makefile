# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 17:14:52 by anamieta          #+#    #+#              #
#    Updated: 2024/10/25 17:15:37 by anamieta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unnecessary_violence

CC = c++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++17

SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
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